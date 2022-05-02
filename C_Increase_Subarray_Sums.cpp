
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
#define Auto auto
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

typedef vector<vector<long long>> vvll;

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
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
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
vector<int> primeFactors(int n)
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

bool isPrime(ll n)
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
/*
vector<ll>adj[100005];
bool vis[100005];
ll dist[100005];
void bfs(ll c)
{
  vis[c]=true;
  dist[c]=0;
  queue<ll>q;
  q.push(c);
while(!q.empty())
{
    ll x=q.front();
    q.pop();

    for(auto y:adj[x])
    {
        if(!vis[y])
        {
            vis[y]=true;
            dist[y]=dist[x]+1;

            q.push(y);
        }
    }

}
}
*/
// Find Min/Max
// * Greedy/Brute Force
//* Prefix array of max/min
// * BS
// * DP/KNPS
// while (j < N)
// {

//     while (j < N)
//     {

// { Driver Code Starts
// #include<bits/stdc++.h>
// using namespace std;

//  // } Driver Code Ends
// class Solution{
// public:
// #define ll long long
int maximumSumSubarray(int K, vector<ll> &a, int N)
{
    // code here
    ll i = 0, j = 0;
    ll sum = 0;
    ll ans = LONG_MIN;
    while (j < N)
    {
        sum += a[j];

        if (j - i + 1 < K)
        {
            j++;
            continue;
        }
        ans = max(ans, sum);
        sum -= a[i];
        i++;
        j++;
    }
    return ans;
}

int maxSum(vll &a, int k, ll x)
{
    ll n = a.size();
    // k must be smaller than n
    // if (n < k)
    // {
    //     cout << "Invalid";
    //     return -1;
    // }

    // Compute sum of first window of size k
    int res = 0;
    for (int i = 0; i < k; i++)
        res += a[i];

    // Compute sums of remaining windows by
    // removing first element of previous
    // window and adding last element of
    // current window.
    int curr_sum = res;
    ll lo = 0, hi = k;
    for (int i = k; i < n; i++)
    {
        curr_sum += a[i] - a[i - k];
        // res = max(res, curr_sum);
        if (curr_sum > res)
        {
            res = curr_sum;
            lo = i - k;
            hi = i;
        }
    }
    // for (ll i = lo; i < hi; i++)
    // {
    //     a[i] += x;
    // }

    return res;
}
ll dp[5005];
void help(ll i, vll &a, ll n)
{
    ll sum = 0;
    if (i == n)
        return;
    for (ll p = i; p < n; p++)
    {
        sum += a[p];
        ll curr = dp[p - i + 1];
        dp[p - i + 1] = max(sum, curr);
    }
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vll a(n);
    ll sum = 0;
    bool f = true;
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (a[i] < 0)
        {
            f = false;
        }
    }

    for (ll i = 0; i < 5005; i++)
    {
        dp[i] = LONG_MIN;
    }

    // if (f)
    // {
    //     for (ll i = 0; i <= n; i++)
    //     {
    //         cout << sum + i * k << " ";
    //     }
    //     cout << endl;
    //     rr;
    // }
    ll val;
    // ll mxa = *max_element(a.begin(), a.end());
    // ll val = max(0ll, max(sum, mxa));
    // cout << val << " ";
    for (ll i = 0; i < n; i++)
    {
        help(i, a, n);
    }
    for (ll i = 0; i <= n; i++)
    {
        // ll ans = maxSum(a, i, k);
        ll ans = 0;
        for (ll j = 1; j <= n; j++)
        {
            // ll vl = maximumSumSubarray(j, a, a.size());
            ll vl = dp[j] + k * min(i, j);
            ans = max(ans, vl);
        }

        // if (i == 0)
        // {
        // }
        // else
        // {
        val = (ans);
        cout << val << " ";
        // }
    }
    cout << endl;
    rr;
}
int main()
{
    io();
    // solve();
    ll t = 1;
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