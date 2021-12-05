
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        int kt;
        vector<int> v;
        cin >> n >> kt;

        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        if (n == 1)
        {
            cout << "YES" << endl;
        }
        else
        {

            if (v[0] + v[n - 1] > kt)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }

        // return 0;
    }

    return 0;
}