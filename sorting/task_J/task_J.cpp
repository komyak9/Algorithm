#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> g1, g2;

    int goblin_number;
    char sign;
    int count;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cin >> sign;

        if (sign == '-')
        {
            cout << g1.front() << endl;
            g1.pop_front();
        }
        else
        {
            cin >> goblin_number;
            if (sign == '+')
            {
                g2.push_back(goblin_number);
            }
            else
            {
                g2.push_front(goblin_number);
            }
        }
        if (g2.size() > g1.size())
        {
            g1.push_back(g2.front());
            g2.pop_front();
        }
    }
}