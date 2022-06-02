#include <iostream>
#include <string>
#include <list>
#include <stack>
#include <vector>

using namespace std;

struct Letter
{
    char value;
    int index;
};

int main()
{
    string line;
    getline(cin, line);
    unsigned int size = line.length();

    int little_i = 0, big_i = 0;
    vector<int> indexes(size / 2);
    vector<Letter> letters;

    for (int i = 0; i < size; i++)
    {
        Letter letter;
        if (isupper(line[i]))
        {
            letter.index = big_i++;
        }
        else
        {
            letter.index = little_i++;
        }
        letter.value = line[i];
        letters.push_back(letter);
    }

    stack<Letter> let;
    for (int i = 0; i < size; i++)
    {
        if (let.empty())
        {
            let.push(letters[i]);
            continue;
        }

        if (isupper(letters[i].value) != isupper(let.top().value) && tolower(letters[i].value) == tolower(let.top().value))
        {
            if (isupper(letters[i].value))
            {
                indexes[letters[i].index] = let.top().index;
            }
            else if (isupper(let.top().value))
            {
                indexes[let.top().index] = letters[i].index;
            }
            let.pop();
            letters[i] = { 0 };
            continue;
        }
        let.push(letters[i]);
    }

    if (let.empty())
    {
        cout << "Possible" << endl;
        for (int i : indexes)
        {
            cout << i + 1 << " ";
        }
    }
    else
    {
        cout << "Impossible" << endl;
    }

    return 0;
}