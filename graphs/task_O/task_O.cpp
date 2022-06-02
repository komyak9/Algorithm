#include <iostream>
#include <list>
#include <vector>

using namespace std;

vector<unsigned short>* studs;
unsigned short* colors;

unsigned short check_color(unsigned short current_value)
{
    if (current_value == 2)
        return 1;
    else
        return 2;
}

bool calculate(unsigned short index, unsigned short color)
{
    colors[index] = color;
    for (int i = 0; i < studs[index].size(); i++)
    {
        if (colors[studs[index][i]] == colors[index])
            return false;
        else if (!colors[studs[index][i]])
        {
            if (!calculate(studs[index][i], check_color(color)))
                return false;
        }
    }
    return true;
}

int main()
{
    const string pos_answer = "YES", neg_answer = "NO";
    bool result = true;

    unsigned short N, M;
    cin >> N >> M;

    studs = new vector<unsigned short>[N];
    colors = new unsigned short[N] {0};

    unsigned short l1, l2;
    for (short i = 0; i < M; i++)
    {
        cin >> l1 >> l2;
        l1--;
        l2--;
        studs[l1].push_back(l2);
        studs[l2].push_back(l1);
    }

    for (short i = 0; i < N; i++)
    {
        if (!colors[i])
            result = calculate(i, 1);

        if (!result)
            break;
    }

    if (result)
        cout << pos_answer;
    else
        cout << neg_answer;


    delete[] colors;
    delete[] studs;

    return 0;
}