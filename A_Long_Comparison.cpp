
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
// #define all(X) (X).begin(), (X).end()
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
// * DP
// * BS

void solve()
{
    ll n1, p1, n2, p2;
    cin >> n1 >> p1 >> n2 >> p2;
    string s1 = to_string(n1);
    string s2 = to_string(n2);

    ll l1 = s1.size();
    ll l2 = s2.size();

    ll t1 = l1 + p1;
    ll t2 = l2 + p2;
    // if (p1 == p2)
    // // {
    if (t1 > t2)
    {
        cout << ">" << endl;
        rr;
    }

    else if (t1 < t2)
    {
        cout << "<" << endl;
        rr;
    }
    // }
    // if (n1 != n2 && p1 == p2)
    // {
    //     if (n1 > n2)
    //     {
    //         cout << ">" << Endl;
    //         rr;
    //     }
    //     if (n2 > n1)
    //     {
    //         cout << "<<" << Endl;
    //         rr;
    //     }
    // }
    for (ll i = 0; i < min(l1, l2); i++)
    {
        ll v1 = s1[i] - '0';
        ll v2 = s2[i] - '0';
        if (v1 > v2)
        {
            cout << ">" << endl;
            rr;
        }
        else if (v2 > v1)
        {
            cout << "<" << endl;
            rr;
        }
    }
    // if(l1>l2){

    // }
    // if (p1 > p2)
    // {
    //     for (ll i = 0; i < p1; i++)
    //     {
    //         ll v1 = s1[i] - '0';
    //         ll v2 = s2[i] - '0';
    //         if (v1 > v2)
    //         {
    //             cout << ">" << endl;
    //             rr;
    //         }
    //         else if (v2 > v1)
    //         {
    //             cout << "<" << endl;
    //             rr;
    //         }
    //     }
    //     for (ll i = p1; i < l2; i++)
    //     {
    //         if (s2[i] != '0')
    //         {
    //             cout << "<" << endl;
    //             rr;
    //         }
    //     }
    // }
    if (l1 > l2)
    {
        // for (ll i = 0; i < p2; i++)
        // {
        //     ll v1 = s1[i] - '0';
        //     ll v2 = s2[i] - '0';
        //     if (v1 > v2)
        //     {
        //         cout << ">" << endl;
        //         rr;
        //     }
        //     else if (v2 > v1)
        //     {
        //         cout << "<" << endl;
        //         rr;
        //     }
        // }
        // for (ll i = p2; i < l1; i++)
        // {
        //     if (s1[i] != '0')
        //     {
        //         cout << ">" << endl;
        //         rr;
        //     }
        // }
        for (ll i = min(l1, l2); i < l1; i++)
        {
            if (s1[i] != '0')
            {
                cout << ">" << endl;
                rr;
            }
        }
    }
    else if (l2 > l1)
    {
        for (ll i = min(l1, l2); i < l2; i++)
        {
            if (s2[i] != '0')
            {
                cout << "<" << endl;
                rr;
            }
        }
    }
    cout << "=" << endl;
    rr;
    // for (ll i = 0; i < p1; i++)
    // {
    //     s1.pb('0');
    // }

    // for (ll i = 0; i < p1; i++)
    // {
    //     s2.pb('0');
    // }
    // for (ll i = 0; i < t1; i++)
    // {
    //     // if(s1[])
    //     ll v1 = s1[i] - '0';
    //     ll v2 = s2[i] - '0';

    //     if (v1 > v2)
    //     {
    //         cout << ">" << endl;
    //         rr;
    //     }
    //     else if (v2 > v1)
    //     {
    //         cout << "<" << endl;
    //         rr;
    //     }
    // }
    // cout << "=" << endl;
    // rr;
    // if (p1 > p2)
    // {
    //     cout << "" << endl;
    //     rr;
    // }
    // else if (p2 > p1)
    // {
    //     cout << "<" << endl;
    //     rr;
    // }

    // vll v1, v2;

    // for (ll i = 0; i < s1.size(); i++)
    // {
    //     v1.pb(s1[i] - '0');
    // }

    // for (ll i = 0; i < s2.size(); i++)
    // {
    //     v2.pb(s2[i] - '0');
    // }
    // while (p1--)
    // {
    //     v1.pb(0);
    // }
    // while (p2--)
    // {
    //     v2.pb(0);
    // }

    // ll num1 = 0, num2 = 0;

    // for (ll i = 0; i < v1.size(); i++)
    // {
    //     num1 += (v1[i] * pow(10, v1.size() - i));
    // }

    // for (ll i = 0; i < v2.size(); i++)
    // {
    //     num2 += (v2[i] * pow(10, v2.size() - i));
    // }
    // int i;
    // if (num1 > num2)
    // {
    //     i = 62;
    //     // char i=
    //     char c = (char)i;
    //     cout << c << endl;
    //     rr;
    // }
    // else if (num1 < num2)
    // {
    //     // c = 62;
    //     i = 60;
    //     char c = (char)i;
    //     cout << c << endl;
    //     rr;
    // }
    // i = 61;
    // char c = (char)i;
    // cout << c << endl;
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