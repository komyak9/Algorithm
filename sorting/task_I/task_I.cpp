#include <iostream>
#include <set>
#include <list>
#include <queue>
#include <limits.h>
#include <vector>

using namespace std;

struct Car {
    int priority = 500001;
    int number;

    bool operator <(const Car& car) const {
        return (priority < car.priority);
    }
};

int main() {
    int n, k, p;
    cin >> n >> k >> p;

    vector<int> input_cars(p);
    list<int> priorities[n];
    for (int i = 0; i < p; i++) {
        cin >> input_cars[i];
        priorities[--input_cars[i]].push_back(i);
    }

    priority_queue<Car> cars;
    set<int> contained_cars;

    int count = 0;
    for (int i = 0; i < p; i++) {
        priorities[input_cars[i]].pop_front();

        if (contained_cars.find(input_cars[i]) == contained_cars.end())
        {
            count++;
            if (contained_cars.size() >= k)
            {
                contained_cars.erase(cars.top().number);
                cars.pop();
            }
            contained_cars.insert(input_cars[i]);
        }
        Car car;
        car.number = input_cars[i];
        if (!priorities[input_cars[i]].empty())
            car.priority = priorities[input_cars[i]].front();

        cars.push(car);
    }

    cout << count << endl;

    return 0;
}