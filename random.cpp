
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define rr return
#define Endl endl
#define ff first
#define ss second
#define all(X) (X).begin(), (X).end()
// clock_t startTime = clock();
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
double PI = 4 * atan(1)
                    ll mod = 1e9 + 7,
       mxn = 3e5 + 5;
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
vll fact(2e5 + 5, 1);
ll binPow(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    ll ret = binPow(a, b / 2);
    if (b % 2 == 0)
        return (ret * ret) % mod;
    return ((ret * ret) % mod * a) % mod;
}
ll inv(ll a)
{
    return (binPow(a, mod - 2) % mod + mod) % mod;
}
ll binom(ll a, ll b)
{
    // before t
    //  for (int i = 1;i<=2e5;i++)fact[i] = (i * fact[i - 1])%mod;
    if (b < 0 or a < 0)
        return 0;
    return (((fact[a] * inv(fact[b])) % mod * inv(fact[a - b])) % mod + mod) % mod;
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

void solve()
{
// ll n;
// cin >> n;
// vector<ll> a(n);
// map<ll, ll> m;
// for (ll i = 0; i < n; i++)
// {
//     cin >> a[i];
//     m[a[i]]++;
// }
// sort(a.begin(), a.end());
// ll sum = 0;
// // for(auto i : m)
// for (ll i = n - 1; i >= 1; i--)
// {
//     // ll val=a[i];
//     ll cnt = m[a[i]];
//     ll diff = a[i] - a[i - 1];
//     cout << cnt << endl;
//     sum += (diff * cnt);
//     m[a[i - 1]] += cnt;
//     debug(m[a[i - 1]]);
// }
// cout << sum << endl;
#include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        //write your code here
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        int mxa = 0;
        // bool f=true;
        int val = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a')
            {
                // if(cnt==0){
                if (i - 1 >= 0)
                {
                    if (s[i - 1] != 'h')
                    {
                        mxa = max(mxa, cnt);
                        cnt = 1;
                        continue;
                    }
                }
                cnt++;
                // val=1;
                // }
                // else{
                // cnt++;
                // }
            }
            else if (s[i] == 'h')
            {
                if (i - 1 >= 0)
                {
                    if (s[i - 1] != 'a')
                    {
                        mxa = max(mxa, cnt);
                        cnt = 1;
                        continue;
                    }
                }
                // if(cnt==0){
                cnt++;
                // val=2;
                // }
                // else{
                // cnt++;
                // }
            }
            else
            {
                mxa = max(mxa, cnt);
                cnt = 0;
            }
        }
        cout << max(mxa, cnt) << endl;
        // return;
        return 0;
    }
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
    // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;
    // cout<<setprecision(10)
    return 0;
}