#include <bits/stdc++.h>
using namespace std;
#define int long long // a.k.a. TLE creator
#define all(x) x.begin(), x.end()

template <class A, class B>
istream &operator>>(istream &o, pair<A, B> &x)
{
    return o >> x.first >> x.second;
}
template <class A, class B>
ostream &operator<<(ostream &o, pair<A, B> &x) { return o << x.first << ' ' << x.second << ' '; }

const int INF = 1e18, MOD = 998244353, N = 1e9 + 1, M = 100, K = 400;

void setIO()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
}

signed main()
{
    setIO();
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int &i : a)
        cin >> i;
    sort(a, a + n);
    int ans = 0;
    set<int> s;
    for (int i = n - 1; ~i; --i)
    {
        auto it = s.upper_bound(a[i]);
        if (it != s.end() && *it <= a[i] + k)
        {
        }
        else
            ans++;
        s.insert(a[i]);
    }
    cout << ans;
}
