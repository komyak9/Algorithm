#include <iostream>
#include <vector>

using namespace std;

int calculate(int count, int N, const vector<vector<bool>>& city_distances, int index, vector<int>& visit_status)
{
	visit_status[index]++;

	for (int i = 0; i < N; i++)
	{
		if (visit_status[i])
			continue;

		if (city_distances[index][i])
		{
			count = calculate(count, N, city_distances, i, visit_status);
		}
	}

	return ++count;
}

int calculate_reverse(int count, int N, const vector<vector<bool>>& city_distances, int index, vector<int>& visit_status)
{
	visit_status[index]++;

	for (int i = 0; i < N; i++)
	{
		if (visit_status[i])
			continue;

		if (city_distances[i][index])
		{
			count = calculate_reverse(count, N, city_distances, i, visit_status);
		}
	}

	return ++count;
}

int calculate_average(int a, int b)
{
	return (a + b) / 2;
}

int main()
{
	vector<vector<bool>> search_distances;
	vector<int> visit_status;

	int N;
	cin >> N;

	int size = N;
	vector<vector<int>> city_distances(size);

	int value;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> value;
			city_distances[i].push_back(value);
		}
	}

	unsigned int lower = 0, upper = 1000000000;
	int count, count_reverse;
	bool check;
	while (lower != upper)
	{
		visit_status.clear();
		visit_status.resize(N, 0);

		search_distances.clear();
		search_distances.resize(N);

		count = 0, count_reverse = 0;
		int average = calculate_average(upper, lower);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				check = city_distances[i][j] <= average;
				search_distances[i].push_back(check);
			}
		}

		count = calculate(count, N, search_distances, 0, visit_status);

		visit_status.clear();
		visit_status.resize(N, 0);

		count_reverse = calculate_reverse(count_reverse, N, search_distances, 0, visit_status);

		if (count == N && count == count_reverse)
		{
			upper = average;
		}
		else
		{
			lower = ++average;
		}
	}

	cout << lower;

	return 0;
}
