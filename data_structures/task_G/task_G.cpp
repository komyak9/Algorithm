#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Letter
{
    char symbol;
    int weight;
};

int main()
{
    const int SIZE = 26;
    vector<Letter> letters;

    string line;
    cin >> line;

    int coefficient;
    for (int i = 0; i < SIZE; i++)
    {
        cin >> coefficient;
        Letter letter;
        letter.symbol = (char)(i + 97);
        letter.weight = coefficient;
        letters.push_back(letter);
    }
    coefficient = 0;

    sort(letters.begin(), letters.end(), [](Letter a, Letter b) {
        return a.weight > b.weight;
    });

    for (auto i : letters)
    {
        if (count(line.begin(), line.end(), i.symbol) < 2)
            continue;
        else
        {
            swap(line[coefficient], line[line.find(i.symbol)]);

            coefficient++;
            swap(line[line.size() - coefficient], line[line.substr(coefficient).find(i.symbol) + coefficient]);
        }
    }

    cout << line << endl;

    return 0;
}