#include <iostream>
#include <list>
#include <string>

using namespace std;

bool is_to_insert(string line1, string line2)
{
    if (line1 + line2 >= line2 + line1)
        return true;
    else
        return false;
}



int main()
{
    list<string> sorted;
    string line;

    while (cin >> line)
    {
        if (sorted.empty())
        {
            sorted.push_back(line);
            continue;
        }

        list<string>::iterator it = sorted.begin(), end = sorted.end();
        for (; it != sorted.end(); it++)
        {
            if (is_to_insert(line, *it))
            {
                sorted.insert(it, line);
                break;
            }
        }
        if (it == sorted.end())
        {
            sorted.push_back(line);
        }
    }

    for (string s : sorted)
    {
        cout << s;
    }
    cout << endl;

    return 0;
}