#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define pob pop_back
#define mp make_pair
#define ff first
#define ss second
#define pi 3.14159265
#define mem(x, y) memset(x, y, sizeof(x))
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(), a.end()
#define endl '\n'
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef map<int, int> mii;
typedef map<string, int> msi;
typedef map<char, int> mci;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> vl;
const ll M = 1e9 + 7;
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)
ll expo(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
    {
        ll ret = expo(a, b / 2);
        ret = (ret * ret) % mod;
        return ret;
    }
    else
    {
        ll ret = expo(a, b / 2);
        ret = (ret * ret) % mod;
        ret = (ret * a) % mod;
        return ret;
    }
}
bool is_prime(ll x)
{
    if (x == 1)
        return false;
    for (ll i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}
int arr[200005], sze[200005];

int main()
{
    fast;
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n], b[n - 1];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n - 1);
        vector<ll> v;
        if (n == 2)
        {
            if (b[0] > a[1])
                cout << b[0] - a[1] << endl;
            else
                cout << b[0] - a[0] << endl;
        }
        else
        {
            if (b[0] - a[0] == b[n - 2] - a[n - 1])
            {
                cout << b[0] - a[0] << endl;
            }
            else
            {
                if (b[0] - a[1] == b[n - 2] - a[n - 1])
                {
                    cout << b[0] - a[1] << endl;
                }
                else
                {
                    cout << b[0] - a[0] << endl;
                }
            }
        }
    }
}