
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define Endl endl
#define ff first
#define ss second

#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif
using namespace std;

void io()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("error.txt","w",stderr);
    // freopen("output.txt", "w", stdout);
    // #endif
}

ll mod = 1e9 + 7, mxn = 3e5 + 5;
void deb(vector<ll> v)
{
    for (auto t : v)
        cerr << t << " ";
    cerr << "\n";
}
ll mul(ll a, ll b, ll mod)
{
    a %= mod;
    b %= mod;
    a *= b;
    a += mod;
    return a % mod;
}

bool sortbysecdesc(const pair<int, int> &a,
                   const pair<int, int> &b)
{
    return a.second > b.second;
}
bool check_sorted(vll a)
{
    ll n = a.size();
    for (ll i = 1; i < n; i++)
    {
        if (a[i] >= a[i - 1])
            continue;
        return false;
    }
    return true;
}

ll po(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return po(mul(a, a, mod), b / 2, mod);
    return mul(a, po(mul(a, a, mod), (b - 1) / 2, mod), mod);
}

long long power(long long X, long long N)
{
    if (N == 0)
        return 1;
    if (N % 2 == 0)
        return power(X * X, N / 2);
    return X * power(X, N - 1);
}

vll fac(200003);
ll facto(ll n)
{

    fac[0] = 1;
    fac[1] = 1;
    for (ll i = 2; i <= 200003; i++)
    {
        fac[i] = i * fac[i - 1];
    }
    return fac[n];
}
long combi(ll n, ll k)
{
    long long ans = 1;
    k = k > n - k ? n - k : k;
    ll j = 1;
    for (; j <= k; j++, n--)
    {
        if (n % j == 0)
        {
            ans *= n / j;
        }
        else if (ans % j == 0)
        {
            ans = ans / j * n;
        }
        else
        {
            ans = (ans * n) / j;
        }
    }
    return ans;
}
// CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
vector<int> sieveOfEratosthenes(int N)
{
    bool primes[N + 1];
    memset(primes, true, sizeof(primes));
    vector<int> arr;

    for (int i = 2; i * i <= N; i++)
        if (primes[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
                primes[j] = false;
        }

    for (int i = 2; i <= N; i++)
        if (primes[i])
            arr.emplace_back(i);

    return arr;
}
void prime_fact(ll n, vector<ll> &res)
{
    while (n % 2 == 0)
    {
        res.pb(2);
        n = n / 2;
    }

    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            res.pb(i);
            n = n / i;
        }
    }
    if (n > 2)
    {
        res.pb(n);
    }
}
bool valid_coordinate(ll x, ll y, ll n, ll m)
{
    if (x < 0 || y < 0)
        return false;

    else if (x >= n || y >= m)
        return false;

    else
        return true;
}
int sod(int n)
{
    int sum = 0;
    while (n)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

bool isPowerOfTwo(ll n)
{
    return n && (!(n & (n - 1)));
}
vll v;
void printPrevSmaller(vll a, int n)
{
    // Create an empty stack
    stack<int> S;

    // Traverse all array elements
    for (int i = 0; i < n; i++)
    {
        // Keep removing top element from S while the top
        // element is greater than or equal to arr[i]
        while (!S.empty() && S.top() >= a[i])
            S.pop();

        // If all elements in S were greater than arr[i]
        if (S.empty())
            v.pb(-1);
        // cout << "_, ";
        else //Else print the nearest smaller element
        {
            v.pb(S.top());
        }
        // cout << S.top() << ", ";

        // Push this element
        S.push(a[i]);
    }
}
void farthest_min(vll a, ll n)
{

    ll s[n];
    s[n - 1] = a[n - 1];
    for (ll i = n - 2; i >= 0; i--)
    {
        s[i] = min(s[i + 1], a[i]);
    }

    for (int i = 0; i < n; i++)
    {
        ll low = i + 1, high = n - 1, ans = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (s[mid] < a[i])
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        v.pb(ans);
    }
}
void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    map<ll, ll> m;
    fo(i, 0, n)
    {
        cin >> a[i];
        m[a[i]] = i;
    }

    // printPrevSmaller(a, n);
    farthest_min(a, n);

    // ll i = 0, j = n - 1;
    vll vv;
    deb(v);

    for (ll i = 0; i < n; i++)
    {
        if (v[i] == -1)
        {
            vv.pb(-1);
        }
        else
            vv.pb(v[i] - i - 1);
    }
    // for (ll i = 0; i < n - 1; i++)
    // {
    //     bool f = true;
    //     for (ll j = n - 1; j >= i; j--)
    //     {

    //         if (a[i] > a[j])
    //         {
    //             vv.pb(j - i - 1);
    //             f = false;
    //             break;
    //         }
    //         if (v[j] != -1 && v[j] < a[i] && m[v[j]] > i)
    //         {
    //             // debug(m[v[j]]);
    //             vv.pb(m[v[j]] - i - 1);
    //             f = false;
    //             break;
    //         }
    //     }
    //     if (f == true)
    //     {
    //         vv.pb(-1);
    //     }
    // }
    // while (i < n)
    // {
    //     j = n - 1;
    //     while (a[j] >= a[i] && j > i)
    //     {
    //         j--;
    //     }
    //     v.pb(j - i - 1);
    //     i++;
    // }
    // vv.pb(-1);
    fo(i, 0, n)
    {
        cout << vv[i] << " ";
    }
    cout << endl;
    return;
}
int main()
{
    io();
    // solve();
    // ll t=1;
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    // cout<<setprecision(10)
    return 0;
}