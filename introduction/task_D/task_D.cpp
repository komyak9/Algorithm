#include <iostream>

using namespace std;

int main()
{
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
    long long k;
    cin >> a >> b >> c >> d >> k;

    int count = 0;
    for (long long i = 0; i < k; i++)
    {
        count = a * b - c;
        if (count <= 0)
        {
            count = 0;
            break;
        }
        else if (count > d)
        {
            count = d;
            break;
        }
        if (count == a)
            break;

        a = count;

    }

    cout << count;
}