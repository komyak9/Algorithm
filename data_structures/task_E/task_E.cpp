#include <iostream>
#include <list>

using namespace std;

int main() {
    int n, k;
    list<int> stoila;
    cin >> n >> k;

    int number_stoila;
    for (int i = 0; i < n; i++)
    {
        cin >> number_stoila;
        stoila.push_back(number_stoila);
    }

    int good_distance, bad_distance, distance;
    int cow_position, cow_count;

    good_distance = 1;
    bad_distance = stoila.back();
    while (bad_distance - good_distance != 1) {
        distance = (bad_distance + good_distance) / 2;

        cow_position = stoila.front();
        cow_count = 1;
        for (auto pos : stoila)
        {
            if (pos - cow_position < distance)
                continue;
            else
            {
                cow_position = pos;
                cow_count++;
            }
        }

        if (cow_count >= k)
            good_distance = distance;
        else
            bad_distance = distance;
    }
    cout << good_distance << endl;
    return 0;
}