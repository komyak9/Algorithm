#include <iostream>
#include <vector>

using namespace std;

int calculate(int count, vector<int>* money_boxes, int* keys, int iter)
{
    keys[iter] = 1;
    for (int i = 0; i < money_boxes[iter].size(); i++)
    {
        if (!keys[money_boxes[iter][i]])
        {
            count = calculate(count, money_boxes, keys, money_boxes[iter][i]);
        }
        else if (keys[money_boxes[iter][i]] == 1)
        {
            count++;
        }
    }
    keys[iter]++;

    return count;
}

int main()
{
    int n;
    cin >> n;

    int* visits = new int[n] {0};
    vector<int>* money_boxes = new vector<int>[n];

    int key_number;
    for (int i = 0; i < n; i++) {
        cin >> key_number;
        key_number--;
        money_boxes[key_number].push_back(i);
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visits[i])
        {
            count = calculate(count, money_boxes, visits, i);
        }
    }
    cout << count;

    delete[] money_boxes;
    delete[] visits;

    return 0;
}
