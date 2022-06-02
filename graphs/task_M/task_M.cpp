#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
	int x;
	int y;
	int index;
	int path;
	bool is_used;

	Point(int index, int x, int y, int path, bool is_used)
	{
		this->index = index;
		this->x = x;
		this->y = y;
		this->path = path;
		this->is_used = is_used;
	}

	Point* x_low = nullptr;
	Point* y_low = nullptr;
	Point* x_high = nullptr;
	Point* y_high = nullptr;
};

bool compute_point(Point* a, Point* b)
{
	if (a->is_used || b->is_used)
		return a->is_used && !b->is_used;
	else
		return a->path > b->path;
}

int parent(int value)
{
	return (value - 1) / 2;
}

int calculate_left(int value)
{
	return 1 + 2 * value;
}

int calculate_right(int value)
{
	return 2 + 2 * value;
}

void sift_down(Point** heap, int n, int right)
{
	int left = right;
	if (calculate_left(right) < n && compute_point(heap[left], heap[calculate_left(right)]))
	{
		left = calculate_left(right);
	}
	if (calculate_right(right) < n && compute_point(heap[left], heap[calculate_right(right)]))
	{
		left = calculate_right(right);
	}
	if (right != left)
	{
		swap(heap[right]->index, heap[left]->index);
		swap(heap[right], heap[left]);
		sift_down(heap, n, left);
	}
}

void sift_up(Point** heap, int i)
{
	while (compute_point(heap[parent(i)], heap[i]))
	{
		swap(heap[i]->index, heap[parent(i)]->index);
		swap(heap[i], heap[parent(i)]);
		i = parent(i);

		if (i <= 0)
			break;
	}
}

int get_time(char cell)
{
	switch (cell)
	{
	case '.':
		return 1;
	case 'W':
		return 2;
	case '#':
		return -1;
	}
}

bool check_start_or_end(int x, int y, int i, int j)
{
	return x == i && y == j;
}

bool check_possibility_first(int x, Point* low_x)
{
	return x > 0 && !low_x->is_used;
}

bool check_possibility_second(int x, int current_x, Point* high_x)
{
	return x < current_x - 1 && !high_x->is_used;
}

bool check_possibility_third(int y, Point* low_y)
{
	return y > 0 && !low_y->is_used;
}

bool check_possibility_forth(int y, int current_y, Point* high_y)
{
	return y < current_y - 1 && !high_y->is_used;
}

bool check(int x, int x1, int y, int y1)
{
	return x != x1 || y != y1;
}

int main()
{
	int x, y, x_start, y_start, x_end, y_end;
	cin >> x >> y >> x_start >> y_start >> x_end >> y_end;

	x_start--;
	y_start--;
	x_end--;
	y_end--;

	int size = 1000000;
	Point** points = new Point * [size];

	vector<vector<char>> map;
	map.resize(x);
	for (int i = 0; i < x; i++)
	{
		map[i].resize(y);

		for (int j = 0; j < y; j++)
		{
			cin >> map[i][j];
		}
	}

	int index = 0;
	Point* point_start = nullptr;
	Point* point_end = nullptr;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			points[index] = new Point(index, i, j, 100000000, false);

			if (get_time(map[i][j]) == -1)
			{
				points[index]->is_used = true;
			}
			if (check_start_or_end(x_start, y_start, i, j))
			{
				point_start = points[index];
			}
			if (check_start_or_end(x_end, y_end, i, j))
			{
				point_end = points[index];
			}

			int new_index;
			if (j >= 1)
			{
				new_index = index - 1;
				points[index]->y_low = points[new_index];
				points[index - 1]->y_high = points[index];
			}
			if (i >= 1)
			{
				new_index = index - y;
				points[index]->x_low = points[index - y];
				points[new_index]->x_high = points[index];
			}
			index++;
		}
	}
	point_start->path = 0;
	sift_up(points, point_start->index);

	for (int i = index / 2 - 1; i >= 0; i--)
	{
		sift_down(points, index, i);
	}

	while (true) {
		Point* min_point = points[0];
		if (min_point->is_used)
		{
			break;
		}
		else
		{

			min_point->is_used = true;
			sift_down(points, index, min_point->index);


			if (check_possibility_first(min_point->x, min_point->x_low))
			{
				min_point->x_low->path = min(min_point->x_low->path, min_point->path + get_time(map[min_point->x - 1][min_point->y]));
				sift_up(points, min_point->x_low->index);
			}
			if (check_possibility_second(min_point->x, x, min_point->x_high))
			{
				min_point->x_high->path = min(min_point->x_high->path, min_point->path + get_time(map[min_point->x + 1][min_point->y]));
				sift_up(points, min_point->x_high->index);
			}
			if (check_possibility_third(min_point->y, min_point->y_low))
			{
				min_point->y_low->path = min(min_point->y_low->path, min_point->path + get_time(map[min_point->x][min_point->y - 1]));
				sift_up(points, min_point->y_low->index);
			}
			if (check_possibility_second(min_point->y, y, min_point->y_high))
			{
				min_point->y_high->path = min(min_point->y_high->path, min_point->path + get_time(map[min_point->x][min_point->y + 1]));
				sift_up(points, min_point->y_high->index);
			}
		}
	}

	int result = point_end->path;

	if (result == 100000000)
	{
		cout << -1;
	}
	else
	{
		vector<char> path;
		Point* point_previous = point_end;
		const char s = 'S', n = 'N', e = 'E', w = 'W';

		while (check(point_previous->x, x_start, point_previous->y, y_start))
		{
			int path1 = point_previous->path - get_time(map[point_previous->x][point_previous->y]);

			if (point_previous->y_high && path1 == point_previous->y_high->path)
			{
				path.push_back(w);
				point_previous = point_previous->y_high;
			}
			else if (point_previous->x_low && path1 == point_previous->x_low->path)
			{
				path.push_back(s);
				point_previous = point_previous->x_low;
			}
			else if (point_previous->x_high && path1 == point_previous->x_high->path)
			{
				path.push_back(n);
				point_previous = point_previous->x_high;
			}
			else if (point_previous->y_low && path1 == point_previous->y_low->path)
			{
				path.push_back(e);
				point_previous = point_previous->y_low;
			}
		}

		cout << result << endl;
		reverse(path.begin(), path.end());
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i];
		}
	}

	return 0;
}