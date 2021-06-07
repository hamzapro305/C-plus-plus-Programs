#include <bits/stdc++.h>
using namespace std;

int Unit(int a)
{
    if (a < 0)
    {
        a *= -1;
    }
    if (!(a < 10))
    {
        string num;
        int b = 0;
        stringstream ss;
        ss << a;
        ss >> num;
        for (int i = 0; i < num.length(); i++)
        {
            cout << num[i] << " ";
            if (i < num.length() - 1)
            {
                cout << "+ ";
            }
            else
            {
                cout << "= ";
            }
            
        }
        
        for (int i = 0; i < num.length(); i++)
        {
            b += num[i];
            b -= 48;
        }
        cout << b << endl;
        return Unit(b);
    }
    else
    {
        return a;
    }
}
int main()
{
    long long int a, b;
    cout << "Enter Any Number: ";
    cin >> a;
    b = Unit(a);
    cout << "The Unit Digit Of this Number is: " << b << endl;
    system("pause");
    return 0;
}