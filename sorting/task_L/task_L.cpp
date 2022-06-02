#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> numbers(n);
    deque<int> part;
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
        if (i < k)
        {
            part.push_back(numbers[i]);
            while (part.size() >= 2 && (part[part.size() - 1] < part[part.size() - 2]))
            {
                part.erase(part.end() - 2);
            }
        }
    }
    cout << part.front() << ' ';

    for (int i = k; i < n; i++)
    {
        if (part.size() > k || part.front() == numbers[i - k])
        {
            part.pop_front();
        }
        part.push_back(numbers[i]);

        while (part.size() >= 2 && (part[part.size() - 1] < part[part.size() - 2]))
        {
            part.erase(part.end() - 2);
        }
        cout << part.front() << ' ';
    }
    cout << endl;

    return 0;
}