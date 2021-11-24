#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << "YES" << endl;
        }
        else
        {
            int count_one = 0, count_zero = 0;
            for (int i = 0; i < n; i++)
            {
                if (b[i] == '1')
                {
                    count_one++;
                }
                else
                {
                    count_zero++;
                }
            }
            if (count_one == n)
            {
                cout << "NO" << endl;
            }
            else if (count_zero == n)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}