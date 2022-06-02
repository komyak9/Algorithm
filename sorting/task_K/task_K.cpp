#include <iostream>

using namespace std;

struct Cell_Memory
{
	Cell_Memory* prev;
	Cell_Memory* next;
	int index;
	int start;
	int length;
	bool is_free;

	Cell_Memory(int ind, int start, int length, bool is_free, Cell_Memory* prev, Cell_Memory* next)
	{
		this->index = ind;
		this->start = start;
		this->length = length;
		this->is_free = is_free;

		this->prev = prev;
		this->next = next;
		if (next)
			next->prev = this;
		if (prev)
			prev->next = this;
	}

	void remove()
	{
		if (prev)
			prev->next = next;
		if (next)
			next->prev = prev;
	}
};

Cell_Memory* requests[100000];
Cell_Memory* available_cells[100000];

void swap(int a, int b) {
	Cell_Memory* t = available_cells[a];
	available_cells[a] = available_cells[b];
	available_cells[b] = t;
	available_cells[a]->index = a;
	available_cells[b]->index = b;
}

bool segment_comp(Cell_Memory* a, Cell_Memory* b)
{
	return a->length < b->length;
}

int left(int i)
{
	return 2 * i + 1;
}

int right(int i)
{
	return 2 * i + 2;
}

int parent(int i)
{
	return (i - 1) / 2;
}


void calc_up(Cell_Memory** heap, int i)
{
	while (i > 0 && segment_comp(heap[parent(i)], heap[i]))
	{
		swap(i, parent(i));
		i = parent(i);
	}
}

void calc_down(Cell_Memory** heap, int n, int i)
{
	int j = i;
	if (left(i) < n && segment_comp(heap[j], heap[left(i)]))
		j = left(i);
	if (right(i) < n && segment_comp(heap[j], heap[right(i)]))
		j = right(i);
	if (i != j) {
		swap(i, j);
		calc_down(heap, n, j);
	}
}

void remove(Cell_Memory** heap, int& n, int i)
{
	swap(i, n - 1);
	n--;
	if (i >= n)
		return;
	calc_up(heap, i);
	calc_down(heap, n, i);
}

void next_prev_taken(Cell_Memory** cell_to_remove, int* free_count)
{
	(*cell_to_remove)->is_free = true;
	(*cell_to_remove)->index = *free_count;
	available_cells[*free_count] = *cell_to_remove;
	calc_up(available_cells, (*free_count)++);
}

void next_taken(Cell_Memory** cell_to_remove)
{
	(*cell_to_remove)->prev->length += (*cell_to_remove)->length;
	calc_up(available_cells, (*cell_to_remove)->prev->index);
	(*cell_to_remove)->remove();
}

void prev_taken(Cell_Memory** cell_to_remove)
{
	(*cell_to_remove)->next->start = (*cell_to_remove)->start;
	(*cell_to_remove)->next->length += (*cell_to_remove)->length;
	calc_up(available_cells, (*cell_to_remove)->next->index);
	(*cell_to_remove)->remove();
}

void not_taken(Cell_Memory** cell_to_remove, int* free_count)
{
	(*cell_to_remove)->prev->length += (*cell_to_remove)->length + (*cell_to_remove)->next->length;
	calc_up(available_cells, (*cell_to_remove)->prev->index);
	(*cell_to_remove)->remove();
	remove(available_cells, *free_count, (*cell_to_remove)->next->index);
	(*cell_to_remove)->next->remove();
}

int main()
{
	int n, m;
	cin >> n >> m;

	int free_count = 0;
	Cell_Memory cell_one = { free_count, 0, n, true, nullptr, nullptr };
	available_cells[free_count++] = &cell_one;

	for (int i = 0; i < m; i++)
	{
		int current;
		cin >> current;

		if (current >= 1)
		{
			Cell_Memory* cell_max = available_cells[0];
			int to_print;
			if (!free_count || cell_max->length < current)
			{
				requests[i] = nullptr;
				to_print = -1;
			}
			else
			{
				requests[i] = new Cell_Memory(-1, cell_max->start, current, false, cell_max->prev, cell_max);
				to_print = requests[i]->start + 1;

				cell_max->length -= current;
				cell_max->start += current;

				if (cell_max->length > 0)
					calc_down(available_cells, free_count, cell_max->index);
				else
				{
					cell_max->remove();
					remove(available_cells, free_count, 0);
				}
			}
			cout << to_print << endl;
		}
		else
		{
			current = -current;
			Cell_Memory* cell_to_remove = requests[current - 1];

			if (cell_to_remove == nullptr)
				continue;

			bool prev_free = cell_to_remove->prev && cell_to_remove->prev->is_free;
			bool next_free = cell_to_remove->next && cell_to_remove->next->is_free;

			if (!next_free && !prev_free)
				next_prev_taken(&cell_to_remove, &free_count);
			else if (!next_free)
				next_taken(&cell_to_remove);
			else if (!prev_free)
				prev_taken(&cell_to_remove);
			else
				not_taken(&cell_to_remove, &free_count);

			requests[i] = nullptr;
		}
	}

	return 0;
}