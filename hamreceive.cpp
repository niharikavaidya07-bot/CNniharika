#include <iostream>
#include <string>
using namespace std;

int main()
{
    string code;
    cout << "Enter received codeword: ";
    cin >> code;

    int n = code.length();
    int error = 0;
    int r = 1;

    while (r <= n)
    {
        int count = 0;

        cout << "\nR" << r << endl;
        cout << "R" << r;

        for (int i = 1; i <= n; i++)
        {
            if ((i & r) != 0 && i != r)
            {
                if ((i & (i - 1)) == 0)
                    cout << " R" << i;
                else
                    cout << " D" << i;
            }
        }

        cout << "\n";

        for (int i = 1; i <= n; i++)
        {
            if ((i & r) != 0)
            {
                int bit = code[n - i] - '0';
                cout << bit << " ";
                count = count ^ bit;
            }
        }

        cout << "\nSet R" << r << " = " << count << endl;

        if (count == 1)
            error = error + r;

        r = r * 2;
    }

    cout << "\nWord : ";

    r = 1;

    while (r <= n)
    {
        cout << ((error & r) ? 1 : 0);
        r = r * 2;
    }

    cout << "\nDecimal equivalent = " << error << endl;

    if (error == 0)
    {
        cout << "No error exists.\n";
        cout << "Correct codeword is:\n";
        cout << code << endl;
    }
    else if (error <= n)
    {
        cout << "Error exists at " << error << "th position\n";
        cout << "So invert that bit.\n";

        code[n - error] = (code[n - error] == '0') ? '1' : '0';

        cout << "\nCorrect codeword is:\n";

        for (int i = 0; i < n; i++)
            cout << code[i] << " ";

        cout << endl;
    }
    else
    {
        cout << "Error position is greater than codeword length.\n";
        cout << "Multiple errors or invalid codeword.\n";
    }

    return 0;
}