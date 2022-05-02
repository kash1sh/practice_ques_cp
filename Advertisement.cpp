
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
// * DP/KNPS

void solve()
{
    ll n;
    cin >> n;

    vll a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // deb(a);
    stack<pair<ll, ll>> gl, gr;
    vll v1(n), v2(n);
    // deb(a);
    ll j = 0;
    for (ll i = 0; i < n; i++)
    {
        if (gl.empty())
        {
            // gl.push({-1, i});
            // v1.pb(-1);
            v1[j++] = -1;
            gl.push({a[i], i});
            continue;
        }
        while (gl.size() && gl.top().ff >= a[i])
        {
            gl.pop();
        }
        if (gl.size() == 0)
        {
            // gl.push({-1, i});
            gl.push({a[i], i});
            v1[j++] = -1;
            // v1.pb(-1);
            continue;
        }
        // v1.pb(gl.top().ss);
        v1[j++] = gl.top().ss;
        gl.push({a[i], i});
        // gl.push({i - gl.top().ss, i});
        // gl.p
    }
    j = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (gr.empty())
        {
            gr.push({a[i], i});
            // v2.pb(n);
            v2[j++] = -1;
            continue;
        }
        while (gr.size() && gr.top().ff >= a[i])
        {
            gr.pop();
        }
        if (gr.size() == 0)
        {
            // gr.push({n, i});
            gr.push({a[i], i});
            // v2.pb(-1);
            v2[j++] = n;
            continue;
        }
        // gr.push({i - gr.top().ss, i});
        // v2.pb(gr.top().ss);
        v2[j++] = gr.top().ss;
        gr.push({a[i], i});
    }
    reverse(v2.begin(), v2.end());
    // deb(v1);
    // deb(v2);
    vll res(n);
    for (ll i = 0; i < n; i++)
    {
        res[i] = v2[i] - v1[i] - 1;
    }
    // deb(res);
    ll maxa = LONG_MIN;
    for (ll i = 0; i < n; i++)
    {
        maxa = max(maxa, a[i] * res[i]);
    }
    cout << maxa << endl;
    rr;
    // ll n;
    // cin >> n;

    // vll arr(n);
    // for (ll i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    // // deb(a);
    // vector<long long> left(n), right(n);
    // stack<pair<long long, ll>> s;
    // //nsl

    // for (int i = 0; i < n; i++)
    // {
    //     if (s.empty())
    //     {
    //         left[i] = -1;
    //         s.push({arr[i], i});
    //         continue;
    //     }
    //     // else
    //     // {
    //     while (!s.empty() && s.top().ff >= arr[i])
    //     {
    //         s.pop();
    //     }
    //     if (s.empty())
    //     {
    //         left[i] = -1;
    //         s.push({arr[i], i});
    //         continue;
    //     }
    //     // else
    //     // {
    //     left[i] = s.top().ss;
    //     s.push({arr[i], i});
    //     // }
    //     // }
    // }

    // //empty stack
    // while (!s.empty())
    // {
    //     s.pop();
    // }

    // //nsr
    // int j = 0;
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     if (s.empty())
    //     {
    //         right[j++] = n;
    //         s.push({arr[i], i});
    //         continue;
    //     }
    //     // else
    //     // {
    //     while (!s.empty() && s.top().ff >= arr[i])
    //     {
    //         s.pop();
    //     }
    //     if (s.empty())
    //     {
    //         right[j++] = n;
    //         s.push({arr[i], i});
    //     }
    //     else
    //     {
    //         right[j++] = s.top().ss;
    //         s.push({arr[i], i});
    //     }
    //     // }
    // }

    // reverse(right.begin(), right.end());

    // //calculation of width
    // for (int i = 0; i < n; i++)
    // {
    //     left[i] = right[i] - left[i] - 1;
    // }

    // long long ans = INT_MIN;
    // //calculate getMaxArea
    // for (int i = 0; i < n; i++)
    // {
    //     long x = left[i] * arr[i];
    //     if (x > ans)
    //     {
    //         ans = x;
    //     }
    // }
    // // return ans;
    // cout << ans << endl;
    // rr;
    // stack<pair<ll, ll>> gl, gr;
    // vll v1, v2;
    // // deb(a);
    // for (ll i = 0; i < n; i++)
    // {
    //     if (gl.empty())
    //     {
    //         // gl.push({-1, i});
    //         v1.pb(-1);
    //         gl.push({a[i], i});
    //         continue;
    //     }
    //     while (gl.size() && gl.top().ff >= a[i])
    //     {
    //         gl.pop();
    //     }
    //     if (gl.size() == 0)
    //     {
    //         // gl.push({-1, i});
    //         gl.push({a[i], i});
    //         v1.pb(-1);
    //         continue;
    //     }
    //     v1.pb(gl.top().ss);
    //     gl.push({a[i], i});
    //     // gl.push({i - gl.top().ss, i});
    //     // gl.p
    // }

    // for (ll i = n - 1; i >= 0; i--)
    // {
    //     if (gr.empty())
    //     {
    //         gr.push({a[i], i});
    //         v2.pb(n);
    //         continue;
    //     }
    //     while (gr.size() && gr.top().ff >= a[i])
    //     {
    //         gr.pop();
    //     }
    //     if (gr.size() == 0)
    //     {
    //         // gr.push({n, i});
    //         gr.push({a[i], i});
    //         v2.pb(-1);
    //         continue;
    //     }
    //     // gr.push({i - gr.top().ss, i});
    //     v2.pb(gr.top().ss);
    //     gr.push({a[i], i});
    // }
    // reverse(v2.begin(), v2.end());
    // deb(v1);
    // deb(v2);
    // vll res(n);
    // for (ll i = 0; i < n; i++)
    // {
    //     res[i] = abs(v2[i] - v1[i]) - 1;
    // }
    // deb(res);
    // ll maxa = LONG_MIN;
    // for (ll i = 0; i < n; i++)
    // {
    //     maxa = max(maxa, a[i] * res[i]);
    // }
    // cout << maxa << endl;
    // rr;
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