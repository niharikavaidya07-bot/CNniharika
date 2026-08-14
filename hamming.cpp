#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data;
    int m, r = 0;

    cout << "Enter data bits: ";
    cin >> data;

    m = data.length();

    while ((1 << r) < (m + r + 1))
        r++;

    int n = m + r;
    int h[100] = {0};

    int j = 0;

    for (int i = 1; i <= n; i++)
    {
        if ((i & (i - 1)) != 0)
        {
            h[i] = data[m - 1 - j] - '0';
            j++;
        }
    }

    cout << "\nData bits = " << m;
    cout << "\nParity bits = " << r;
    cout << "\nTotal bits = " << n;

    cout << "\n\nBits:\n";

    for (int i = n; i >= 1; i--)
    {
        if ((i & (i - 1)) == 0)
            cout << "R" << i << " ";
        else
            cout << h[i] << " ";
    }

    cout << "\n";

    for (int p = 1; p <= n; p = p * 2)
    {
        int sum = 0;

        cout << "\nR" << p << " = ";

        for (int i = 1; i <= n; i++)
        {
            if ((i & p) != 0 && i != p)
            {
                cout << h[i];
                sum += h[i];
            }
        }

        h[p] = sum % 2;

        cout << "\nR" << p << " = " << h[p];
    }

    cout << "\n\nHamming code:\n";

    for (int i = n; i >= 1; i--)
        cout << h[i] << " ";

    cout << "\n\nFinal code = ";

    for (int i = n; i >= 1; i--)
        cout << h[i];

    cout << "\n";

    return 0;
}
