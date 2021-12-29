#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    ll summ = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        summ += arr[i];
    }
    sort(arr, arr + n);
    stack<ll> s;
    for (int i = 1; i < n; i++)
    {
        s.push(arr[i] - arr[0]);
    }
    ll ct = 0;
    ll minn = INT_MAX;
    while (!s.empty() && summ > k)
    {
        minn = min(minn, ct + (summ - k + ct) / (ct + 1));
        summ -= s.top();
        s.pop();
        ct++;
    }
    if (summ > k)
    {
        ct += (summ - k + ct) / (ct + 1);
    }
    cout << min(minn, ct) << endl;
}
int main()
{
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
}