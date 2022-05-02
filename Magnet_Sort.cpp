
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
void solve()
{
    ll n;
    cin >> n;
    vll a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    string s;
    cin >> s;

    ll cntN = 0, cntS = 0;
    for (auto i : s)
    {
        if (i == 'N')
            cntN++;
        else
            cntS++;
    }
    if (is_sorted(all(a)))
    {
        cout << 0 << endl;
        rr;
    }
    if (cntN == 0 || cntS == 0)
    {
        cout << -1 << endl;
        rr;
    }
    ll fn = -1, ls = -1;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'N')
        {
            fn = i;
            break;
        }
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'S')
        {
            ls = i;
            break;
        }
    }

    ll ln = -1, fs = -1;

    for (ll i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'N')
        {
            ln = i;
            break;
        }
    }
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == 'S')
        {
            fs = i;
            break;
        }
    }
    ll cnt = 0;
    vll b = a;
    sort(all(a));
    int start = INT_MAX, last = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            start = min(i, start);
            last = max(last, i);
        }
    }

    bool f1 = false, f2 = false;
    for (int i = 0; i < start; i++)
        if (s[i] != s[last])
            f1 = true;
    for (int i = last; i < n; i++)
        if (s[i] != s[start])
            f2 = true;
    if (s[start] != s[last] f1 f2)
        cout << 1;
    else
        cout << 2;
    cout << endl;
    rr;
    // while (1)
    // {
    //     for (ll i = 1; i < n; i++)
    //     {
    //         if (a[i] > a[i - 1])
    //             continue;
    //         if (i >= fn && i <= ls)
    //         {
    //             sort(a.begin() + fn, a.begin() + ls + 1);
    //             cnt++;
    //         }
    //         else if (i >= fs && i <= ln)
    //         {
    //             sort(a.begin() + fs, a.begin() + ln + 1);
    //             cnt++;
    //         }
    //     }
    //     if (is_sorted(all(a)))
    //     {
    //         cout << cnt << endl;
    //         rr;
    //     }
    // }
    // vll b(a);
    // sort(b.begin(), b.end());
    // ll fir = -1, las = a.size();
    // las++;
    // bool f = true;
    // for (ll i = 0; i < n; i++)
    // {
    //     if (a[i] != b[i])
    //     {
    //         fir = i;
    //         f = false;
    //         break;
    //     }
    // }
    // // if (f == true)
    // // {
    // //     cout << 0 << endl;
    // //     rr;
    // // }
    // // if (las > fir)
    // // {
    // for (ll i = 0; i < n; i++)
    // {
    //     if (a[i] != b[i])
    //     {
    //         las = i;
    //         // break;
    //     }
    // }
    // f = false;
    // ll ff = 0;

    // // if (s[las] != s[fir])
    // // {
    // //     cout << 1 << endl;
    // //     rr;
    // // }
    // for (ll kk = 0; kk < fir; kk++)
    // {
    //     if (s[kk] != s[las])
    //     {
    //         f = true;
    //         break;
    //     }
    // }
    // for (ll kk = n - 1; kk > las; kk++)
    // {
    //     if (s[kk] != s[fir])
    //     {
    //         ff = 1;
    //         break;
    //     }
    // }
    // // if (f == false)
    // // {
    // //     cout << 1 << endl;
    // //     rr;
    // // }
    // if ((f || ff) && s[fir] != s[las])
    // {
    //     cout << 1 << endl;
    //     rr;
    // }
    // cout << 2 << Endl;
    // rr;

    // // }
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