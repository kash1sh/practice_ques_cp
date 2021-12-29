
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
void replaceCharacter(int v[],
                      ll c1, ll c2, ll n)
{
    // Base Case
    // If the string is empty
    if (n == 0)
    {
        return;
    }

    // If the character at starting
    // of the given string is equal
    // to c1, replace it with c2
    if (v[0] == c1)
    {
        v[0] = c2;
    }

    // Getting the answer from recursion
    // for the smaller problem
    return replaceCharacter(v + 1,
                            c1, c2, n);
}
void update(vector<ll> &v, int N, vector<vector<ll>> &Q)
{

    // Creating a hashmap
    map<int, vector<int>> hashmap;
    for (int i = 0; i < N; ++i)
    {
        hashmap[v[i]].push_back(i);
    }

    // Iterating with q in given queries
    for (auto q : Q)
    {
        if (hashmap.count(q[0]))
        {
            if (hashmap.count(q[1]))
                hashmap[q[1]].insert(hashmap[q[1]].end(),
                                     hashmap[q[0]].begin(),
                                     hashmap[q[0]].end());
            else
                hashmap[q[1]] = hashmap[q[0]];
            hashmap.erase(q[0]);
        }
    }

    // Creating map to store key value pairs
    map<int, int> new_map;
    for (auto it = hashmap.begin(); it != hashmap.end();
         ++it)
    {
        for (auto index : it->second)
            new_map[index] = it->first;
    }

    // Updating the main array with final values
    for (auto it = new_map.begin(); it != new_map.end();
         ++it)
        v[it->first] = it->second;
}
Tree<pair<ll, ll>> o;

void solve()
{
    ll q;
    cin >> q;
    vll v;
    // int v[q];
    // multiset<ll> ms;
    // ll k = 0;
    for (ll i = 0; i < q; i++)
    {
        ll x, y, z;
        cin >> x;
        if (x == 1)
        {
            cin >> y;
            //         v[k++] = y;
            //         debug(v[k - 1]);
            v.pb(y);
            //         // ms.pb(y);
        }
        else
        {
            cin >> y >> z;
            // vector<vector<ll>> Q = {{y, z}};
            vector<vector<ll>> Q = {{y, z}};
            update(v, v.size(), Q);
            //         replaceCharacter(v, y, z, q);
            //         for (auto i : v)
            //         {
            //             cout << i << " ";
            //             // rr;
        }
        // }
    }
    for (auto i : v)
    {
        cout << i << " ";
        //     // rr;
    }
    cout << endl;
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