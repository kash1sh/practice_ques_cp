
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

void solve()
{
    // ll n;
    // cin >> n;
    // map<ll, ll> m;
    // vll a(n);
    // for (ll i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    //     m[a[i]]++;
    // }
    // ll maxa = *max_element(a.begin(), a.end());
    // priority_queue<int> maxHeap;
    // for (auto &p : m)
    // {
    //     maxHeap.push(p.second);
    // }
    // while (maxHeap.size() > 1)
    // {
    //     int l1 = maxHeap.top();
    //     maxHeap.pop();
    //     int l2 = maxHeap.top();
    //     maxHeap.pop();
    //     l1--;
    //     l2--;
    //     if (l1)
    //         maxHeap.push(l1);
    //     if (l2)
    //         maxHeap.push(l2);
    // }
    // if (maxHeap.empty())
    //     cout << 0 << '\n';
    // else
    //     cout << maxHeap.top() << '\n';
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    int mx = 0;
    for (auto x : mp)
    {
        mx = max(mx, x.second);
    }
    if (mx <= n / 2)
    {
        if (n & 1)
        {
            cout << 1 << endl;
            return;
        }
        cout << "0" << endl;
        return;
    }
    cout << n - ((n - mx) * 2) << endl;
    return;
    // set<ll, greater<ll>> s;
    // for (auto i : m)
    // {
    //     s.insert(i.ss);
    //     // if (i.ff == maxa)
    //     //     continue;
    // }
    // ll cnt = n;
    // ll nn = s.size();
    // while (nn > 1)
    // {
    //     ll maxa = *s.begin();
    //     s.erase(s.begin());

    //     ll fin = *s.begin();
    //     ll m2 = *s.begin();
    //     s.erase(s.begin());
    //     maxa--, m2--;
    //     if (maxa)
    //         s.insert(maxa);
    //     if (m2)
    //         s.insert(m2);

    //     // nn++;
    // }
    // if (s.empty())
    // {
    //     cout << 0 << endl;
    //     return;
    // }
    // cout << *(s.begin()) << endl;
    // return;
}
int main()
{
    io();
    // solve();
    // ll t=1;
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    // cout<<setprecision(10)
    return 0;
}