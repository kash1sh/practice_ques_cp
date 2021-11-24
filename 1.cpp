#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    // cout << "Hello World" << endl;
    string s = "othinger";
    ll val = 1000;
    char ch;
    for (ll i = 0; i < s.size(); i++)
    {
        if ((ll)s[i] < val)
        {
            ch = s[i];
            val = (ll)s[i];
        }
    }
    cout << val << " " << ch << endl;
    // rr;
    return 0;
}