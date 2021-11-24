
#include <bits/stdc++.h>
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
clock_t startTime = clock();
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
double PI = 4 * atan(1);
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
map<string, ll> m;
ll x = 0;
void print()
{
    x++;
    cout << "List " << x << ":" << endl;

    for (auto i : m)
    {
        cout << i.ff << " | " << i.ss << endl;
    }
    // cout << endl;
}
void solve()
{
    ll n;
    cin >> n;
    if (n == 0)
    {
        print();
    }
    string ele = "elephant";
    string mon = "monkey";
    string tig = "tiger";
    string bea = "bear";
    string pen = "penguin";
    string lio = "lion";

    for (ll i = 0; i <= n; i++)
    {
        // debug(i);
        string s;
        getline(cin, s);
        // cerr << s << endl;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        // size_t fin =
        size_t found = s.find(ele);
        if (found != string::npos)
        {
            m[ele]++;
        }
        size_t foun = s.find(mon);
        if (foun != string::npos)
        {
            m[mon]++;
        }
        size_t fond = s.find(tig);
        if (fond != string::npos)
        {
            m[tig]++;
        }
        size_t fund = s.find(bea);
        if (fund != string::npos)
        {
            m[bea]++;
        }
        size_t ound = s.find(lio);
        if (ound != string::npos)
        {
            m[lio]++;
        }
        size_t foud = s.find(pen);
        if (foud != string::npos)
        {
            m[pen]++;
        }
    }
    print();
    m.clear();
    ll nn;
    cin >> nn;
    // debug(nn);
    if (nn == 0)
    {
        //     print();
        rr;
    }
    for (ll i = 0; i <= nn; i++)
    {
        string s;
        getline(cin, s);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        // size_t fin =
        size_t found = s.find(ele);
        if (found != string::npos)
        {
            m[ele]++;
        }
        size_t foun = s.find(mon);
        if (foun != string::npos)
        {
            m[mon]++;
        }
        size_t fond = s.find(tig);
        if (fond != string::npos)
        {
            m[tig]++;
        }
        size_t fund = s.find(bea);
        if (fund != string::npos)
        {
            m[bea]++;
        }
        size_t ound = s.find(lio);
        if (ound != string::npos)
        {
            m[lio]++;
        }
        size_t foud = s.find(pen);
        if (foud != string::npos)
        {
            m[pen]++;
        }
    }
    print();
    m.clear();
    ll nnn;
    cin >> nnn;
    if (nnn == 0)
    {
        // print();
        rr;
    }
    for (ll i = 0; i <= nnn; i++)
    {
        string s;
        getline(cin, s);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        // size_t fin =
        size_t found = s.find(ele);
        if (found != string::npos)
        {
            m[ele]++;
        }
        size_t foun = s.find(mon);
        if (foun != string::npos)
        {
            m[mon]++;
        }
        size_t fond = s.find(tig);
        if (fond != string::npos)
        {
            m[tig]++;
        }
        size_t fund = s.find(bea);
        if (fund != string::npos)
        {
            m[bea]++;
        }
        size_t ound = s.find(lio);
        if (ound != string::npos)
        {
            m[lio]++;
        }
        size_t foud = s.find(pen);
        if (foud != string::npos)
        {
            m[pen]++;
        }
    }
    print();
    m.clear();
    ll nnnn;
    cin >> nnnn;
    if (nnnn == 0)
    {
        // print();
        rr;
    }
    for (ll i = 0; i <= nnnn; i++)
    {
        string s;
        getline(cin, s);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        // size_t fin =
        size_t found = s.find(ele);
        if (found != string::npos)
        {
            m[ele]++;
        }
        size_t foun = s.find(mon);
        if (foun != string::npos)
        {
            m[mon]++;
        }
        size_t fond = s.find(tig);
        if (fond != string::npos)
        {
            m[tig]++;
        }
        size_t fund = s.find(bea);
        if (fund != string::npos)
        {
            m[bea]++;
        }
        size_t ound = s.find(lio);
        if (ound != string::npos)
        {
            m[lio]++;
        }
        size_t foud = s.find(pen);
        if (foud != string::npos)
        {
            m[pen]++;
        }
    }
    print();
    m.clear();
    // if(nnnn==0)rr;
    ll na;
    cin >> na;
    if (na == 0)
    {
        // print();
        rr;
    }
    for (ll i = 0; i <= na; i++)
    {
        string s;
        getline(cin, s);
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        // size_t fin =
        size_t found = s.find(ele);
        if (found != string::npos)
        {
            m[ele]++;
        }
        size_t foun = s.find(mon);
        if (foun != string::npos)
        {
            m[mon]++;
        }
        size_t fond = s.find(tig);
        if (fond != string::npos)
        {
            m[tig]++;
        }
        size_t fund = s.find(bea);
        if (fund != string::npos)
        {
            m[bea]++;
        }
        size_t ound = s.find(lio);
        if (ound != string::npos)
        {
            m[lio]++;
        }
        size_t foud = s.find(pen);
        if (foud != string::npos)
        {
            m[pen]++;
        }
    }
    print();
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
    // cout<<setprecision(10)
    return 0;
}