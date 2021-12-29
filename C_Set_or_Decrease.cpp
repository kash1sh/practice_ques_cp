
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
vector<int> factors(int n)
{
    vector<int> f;
    for (int x = 2; x * x <= n; x++)
    {
        while (n % x == 0)
        {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1)
        f.push_back(n);
    return f;
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

bool prime(ll n)
{
    if (n < 2)
        return false;
    for (ll x = 2; x * x <= n; x++)
    {
        if (n % x == 0)
            return false;
    }
    return true;
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

bool check(ll mid, vll &a, ll k, ll sum)
{
    ll mini = *min_element(a.begin(), a.end());
    ll mini2 = mini;
    // ll sum = 0;
    // debug(sum);
    vll v(a);
    bool f = true;
    // debug(mid);
    // if (mini >= k)
    // {
    //     while (mini >= k - 1)
    //     {
    //     }
    // }
    ll cnt = 0;
    for (ll i = 0; i < v.size(); i++)
    {
        if (v[i] == mini)
            cnt++;
    }
    if (mini * (a.size() - cnt) + mini2 * (cnt - 1) + mini > k)
    {
        while (mini * (a.size() - cnt) + mini2 * (cnt - 1) + mini > k)
        {
            mini--;
            mid--;
        }
    }
    debug(mini);
    ll mini3 = mini--;
    ll midd = mid;
    // for (ll i = 0; i < v.size(); i++)
    // {
    //     if (v[i] == mini2)
    //     {
    //         v[i] = mini;
    //         mid--;
    //     }
    // }
    // mid++;
    vll v2(a);
    ll sum2 = sum;
    // bool f = true;
    for (ll i = 0; i < a.size(); i++)
    {
        if (mid <= 0)
        {
            // f = false;
            // break;
            return false;
        }
        if (v[i] > mini)
        {
            sum -= v[i];
            sum += mini;
            v[i] = v[i] - mini;
            mid--;
            if (sum <= k)
                return true;
        }
        else
        {
            mini--;
            i = -1;
        }
    }
    if (sum <= k)
        return true;
    // mid = midd;

    // for (ll i = 0; i < a.size(); i++)
    // {
    //     if (mid <= 0)
    //     {
    //         // break;
    //         return false;
    //     }
    //     if (v2[i] > mini3)
    //     {
    //         sum2 -= v2[i];
    //         sum2 += mini3;
    //         v2[i] = v2[i] - mini3;
    //         mid--;
    //         if (sum2 <= k)
    //             return true;
    //     }
    //     // else
    //     // {
    //     //     mini3--;
    //     //     i = -1;
    //     // }
    // }
    // return sum2 <= k;
}
void solve()
{
    ll n, k;
    cin >> n >> k;
    vll a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll sum = 0;
    for (auto i : a)
    {
        sum += i;
    }
    sort(a.begin(), a.end(), greater<>());
    if (sum <= k)
    {
        cout << 0 << endl;
        rr;
    }
    if (n == 1)
    {
        cout << a[0] - k << endl;
        rr;
    }
    // ll lo = 0, hi = 1e9;
    // while (lo < hi)
    // {
    //     ll mid = lo + (hi - lo) / 2;

    //     if (check(mid, a, k, sum))
    //     {
    //         hi = mid;
    //     }
    //     else
    //         lo = mid + 1;
    // }
    ll ans = LONG_MAX;
    // sum -= a[0];
    for (ll i = 0; i < n; i++)
    {
        ll val = (k - sum < 0 ? (k - sum - n + 1) / n : ((k - sum) / n));
        ans = min(ans, i + max(a[0] - val, 0ll));
        sum = sum - a[n - i - 1];
    }
    cout << ans / 2 << endl;
    rr;
    // cout << lo << endl;
    // rr;
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