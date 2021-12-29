
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define rr return
#define ff first
#define ss second
#define llmin LONG_MIN
#define llmax LONG_MAX
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yes cout << "yes\n"
#define no cout << "no\n"

#define show(A)           \
    for (auto i : A)      \
        cout << i << " "; \
    cout << '\n';
#define endl "\n"
#define Endl endl
clock_t startTime = clock();
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define all(v) v.begin(), v.end()
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
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("error.txt","w",stderr);
    // freopen("output.txt", "w", stdout);
    // #endif
}
double PI = 4 * atan(1);
ll mod = 1e9 + 7, mxn = 3e5 + 5;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
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
// int a = count(all(s),'A');
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
// Find Min/Max
// * Greedy/Brute Force
//* Prefix array of max/min
// * BS
// * DP
ll dp[3000][2];
ll cnt = 0;
bool help(ll a1, ll a2)
{
    bool ans = false;
    if (a1 == 0)
        return false;
    if (dp[a1][a2] != -1)
        return dp[a1][a2];

    if (a1 >= 1)
        ans = ans | (!help(a1 - 1, !a2));
    if (a1 >= 2)
        ans = ans | (!help(a1 - 2, !a2));
    return dp[a1][a2] = ans;
}
void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll sum = 0;
    if (n == 2)
    {
        if (s == "00")
        {
            cout << "JJ" << endl;
            rr;
        }
        if (s == "11")
        {
            cout << "JJ" << endl;
            rr;
        }
        cout << "Uttu" << endl;
        rr;
    }
    for (ll i = 0; i < n; i++)
    {
        if (i == n - 1)
            continue;
        sum += abs(s[i + 1] - s[i]);
    }

    // if (sum == 0)
    // {
    //     if (n % 2 == 0)
    //     {
    //         cout << "Uttu" << endl;
    //         rr;
    //     }
    //     else
    //     {
    //         cout << "JJ" << endl;
    //         rr;
    //     }
    // }
    if (sum == n - 1)
    {
        cout << "Uttu" << endl;
        rr;
    }
    // debug(sum);
    // ll diff = n - 1 - sum;
    // if (diff % 2 == 0)
    // {
    //     cout << "JJ" << endl;
    //     rr;
    // }
    // cout << "Uttu" << endl;
    // rr;
    // bool f = true;
    // for (ll i = 0; i < n - 1; i++)
    // {
    //     // for(ll j=i+1;j<n;j++){
    //     // if(s[])
    //     // }
    //     if (s[i + 1] == s[i])
    //     {
    //         // s[i + 1] = 1 - s[i + 1];
    //         i++;
    //         f = !f;
    //         continue;
    //     }
    // }
    // if (f)
    // {
    //     cout << "Uttu" << endl;
    //     rr;
    // }
    // cout << "JJ" << endl;
    // rr;
    string s1, s2;
    cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        s1 += (i % 2 == 0 ? '1' : '0');
        s2 += (i % 2 == 0 ? '0' : '1');
        // s1+=(i%2==0?'1':'0');
    }
    memset(dp, -1, sizeof(dp));
    ll cnt1 = 0, cnt2 = 0, ans;
    if (s[0] != s1[0])
        cnt1++;
    if (s[0] != s2[0])
        cnt2++;

    for (ll i = 0; i < n - 1; i++)
    {
        if (s[i] != s1[i])
            cnt1++;
        if (s[i] != s2[i])
            cnt2++;
        if (s[i] == s[i + 1])
            cnt++;
    }
    // debug(cnt);
    bool res = help(cnt, 0);
    ans = min(cnt1, cnt2);
    if (res)
    {
        cout << "JJ" << endl;
        rr;
    }
    cout << "Uttu" << endl;
    rr;
    if (ans % 2 == 0)
    {
        cout << "Uttu" << endl;
        rr;
    }
    cout << "JJ" << endl;
    rr;
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

    // cout<<fixed<<setprecision(10)<<ans<<endl;

    // cout<<printf("%.8lf", hi)<<endl;
    return 0;
}