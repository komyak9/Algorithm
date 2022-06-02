#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    unsigned int n, k;
    cin >> n >> k;

    unsigned int* input = new unsigned int[n];
    for (unsigned int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    sort(input, input + n);

    unsigned int sum = 0;
    for (int i = n - 1, j = 1; i >= 0; i--, j++)
    {
        if (j % k != 0)
        {
            sum += input[i];
        }
    }

    cout << sum << endl;

    return 0;
}