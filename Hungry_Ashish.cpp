#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        if (n < a && n < b)
        {
            cout << "NOTHING" << endl;
        }
        else if (n < a && n >= b)
        {
            cout << "BURGER" << endl;
        }
        else if (n >= a)
        {
            cout << "PIZZA" << endl;
        }
    }
    return 0;
}