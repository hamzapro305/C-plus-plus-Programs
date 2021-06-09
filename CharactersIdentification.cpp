#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()

{
    string str, str1;
    int u = 0, l = 0, s = 0, n = 0, sc = 0;
    cout << "Enter a string: ";

    // Technique to get whole line in one string
    cin >> str;
    getline(cin, str1);
    str += str1;

    for (int i = 0; i < str.length(); i++)
    {
        if (isupper(str[i]))
        {
            u++;
        }
        else if (islower(str[i]))
        {
            l++;
        }
        else if (isdigit(str[i]))
        {
            n++;
        }
        else if (str[i] == 32)
        {
            s++;
        }
        else if ((str[i] >= 33 && str[i] <= 47) || (str[i] >= 58 && str[i] <= 64) || (str[i] >= 91 && str[i] <= 96) || (str[i] >= 123 && str[i] <= 255))
        {
            sc++;
        }
    }
    cout << "Upper case letters: " << u << endl
         << "Lower case Letters: " << l << endl
         << "Spaces: " << s << endl
         << "Numbers: " << n << endl
         << "Special Characters: " << sc << endl;
    system("pause");

    return 0;
}