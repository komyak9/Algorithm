#include <iostream>

using namespace std;

bool triple_equality(int a, int b, int c)
{
    if (a == b && b == c && a == c)
    {
        return true;
    }
    return false;
}

int max_sequence_length(const int* const array, const int size)
{
    if (size <= 2)
    {
        return size;
    }

    int leftover = 2;
    int max = leftover;
    int current_count = leftover;

    for (int i = leftover; i < size; i++)
    {
        if (!triple_equality(array[i - 2], array[i - 1], array[i]))
        {
            if (++current_count > max)
            {
                max = current_count;
            }
        }
        else
        {
            current_count = leftover;
        }
    }

    return max;
}

int find_min_index(const int* const array, const int size, const int max_length)
{
    int min_index = 1;
    int leftover = 2;
    int current_count = leftover;

    for (int i = leftover; i < size; i++)
    {
        if (triple_equality(array[i - 2], array[i - 1], array[i]))
        {
            current_count = leftover;
        }
        else
        {
            if (++current_count == max_length)
            {
                min_index = (i + 1) - max_length + 1;
                break;
            }
        }
    }

    return min_index;
}

int array_size_read()
{
    int length = 0;
    cin >> length;
    return length;
}

void array_fill(int* array, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
}

int main()
{
    int size = array_size_read();

    if (size <= 0)
    {
        return 0;
    }

    int* array = new int[size];

    array_fill(array, size);

    int max_length = max_sequence_length(array, size);

    int min_index = find_min_index(array, size, max_length);

    int max_index = min_index + max_length - 1;
    cout << min_index << " " << max_index << endl;

    delete[] array;

    return 0;
}