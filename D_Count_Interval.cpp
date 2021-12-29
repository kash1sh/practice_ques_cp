
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
ll findSubarraySum(vll &a, ll n, ll k)
{
    // STL map to store number of subarrays
    // starting from index zero having
    // particular value of sum.
    // unordered_map<int, int> prevSum;

    // int res = 0;

    // // Sum of elements so far.
    // int currsum = 0;

    // for (int i = 0; i < n; i++)
    // {

    //     // Add current element to sum so far.
    //     currsum += a[i];

    //     // If currsum is equal to desired sum,
    //     // then a new subarray is found. So
    //     // increase count of subarrays.
    //     if (currsum == sum)
    //         res++;

    //     // currsum exceeds given sum by currsum
    //     //  - sum. Find number of subarrays having
    //     // this sum and exclude those subarrays
    //     // from currsum by increasing count by
    //     // same amount.
    //     if (prevSum.find(currsum - sum) != prevSum.end())
    //         res += (prevSum[currsum - sum]);

    //     // Add currsum value to count of
    //     // different values of sum.
    //     prevSum[currsum]++;
    // }

    // return res;
    // ll r = 0, s = 0;
    // unordered_map<ll, ll> m;
    // m[0]++;
    // for (ll i = 0; i < a.size(); i++)
    // {
    //     s += a[i];
    //     if (m[s - k])
    //         r += m[s - k];
    //     m[s]++;
    // }
    // return r;
    // ll cum = 0;      // cumulated sum
    // map<ll, ll> rec; // prefix sum recorder
    // ll cnt = 0;      // number of found subarray
    // rec[0]++;        // to take into account those subarrays that begin with index 0
    // for (ll i = 0; i < a.size(); i++)
    // {
    //     cum += a[i];
    //     cnt += rec[cum - k];
    //     rec[cum]++;
    // }
    // return cnt;
    unordered_map<ll, ll> map;

    map[0] = 1;
    ll sum = 0;
    ll count = 0;
    for (ll i = 0; i < a.size(); i++)
    {
        sum += a[i];

        if (map.find(sum - k) != map.end())
        {
            count += map[sum - k];
        }
        map[sum]++;
    }

    return count;
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
    // ll cnt = 0;
    // for (ll i = 0; i < n; i++)
    // {
    //     if (a[i] == k)
    //     {
    //         cnt++;
    //         debug(i);
    //     }
    // }
    // if (n == 1)
    // {
    //     if (a[0] == k)
    //     {
    //         cout << 1 << endl;
    //         rr;
    //     }
    //     cout << 0 << endl;
    //     rr;
    // }
    // if (n == 2)
    // {
    //     if (a[0] + a[1] == k)
    //     {
    //         if (a[0] == k)
    //         {
    //             cout << 2 << endl;
    //             rr;
    //         }
    //         if (a[1] == k)
    //         {
    //             cout << 2 << endl;
    //             rr;
    //         }
    //         cout << 1 << endl;
    //         rr;
    //     }
    //     if (a[0] == k)
    //     {
    //         cout << 1 << endl;
    //         rr;
    //     }
    //     if (a[1] == k)
    //     {
    //         cout << 1 << endl;
    //         rr;
    //     }
    //     cout << 0 << endl;
    //     rr;
    // }
    ll ans = findSubarraySum(a, n, k);
    cout << ans << endl;
    rr;
}
int main()
{
    io();
    // solve();
    ll t = 1;
    // ll t;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

    // cout<<fixed<<setprecision(10)<<ans<<endl;

    // cout<<printf("%.8lf", hi)<<endl;
    return 0;
}