
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define fir first
#define sec second

#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)

using namespace std;

void io()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
}
ll mod = 1e9 + 7, mxn = 3e5 + 5;

ll add(ll a, ll b, ll mod)
{
    a %= mod;
    b %= mod;
    a += b;
    if (a >= mod)
        a -= mod;
    if (a < 0)
    {
        a += mod;
        a %= mod;
    }
    return a;
}

ll mul(ll a, ll b, ll mod)
{
    a %= mod;
    b %= mod;
    a *= b;
    a += mod;
    return a % mod;
}
// ll modInverse(ll a, ll m){
//     ll x, y;
//     ll g = gcdExtended(a, m, &x, &y);
//         ll res = (x%m + m) % m;
//         return res;
// }
ll binary_Search(vector<ll> &arr, ll key)
{
    ll l = 0, r = arr.size() - 1;
    ll ans;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll value = arr[mid];
        if (value > key)
        {
            r = mid - 1;
        }
        else if (value == key)
        {
            return mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}
ll po(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return po(mul(a, a, mod), b / 2, mod);
    return mul(a, po(mul(a, a, mod), (b - 1) / 2, mod), mod);
}

long long power(long long X, long long N)
{
    if (N == 0)
        return 1;
    if (N % 2 == 0)
        return power(X * X, N / 2);
    return X * power(X, N - 1);
}

int fact[200003];
int inv[200003];

void fact0()
{
    int i, j;
    fact[0] = 1;
    for (i = 1; i <= 200000; i++)
    {
        fact[i] = i * fact[i - 1] % mod;
    }
    inv[0] = 1;
    inv[1] = 1;
    int p = mod;
    for (i = 2; i <= 200000; i++)
        inv[i] = (p - (p / i) * inv[p % i] % p) % p;

    for (i = 2; i <= 200000; i++)
    {
        inv[i] *= inv[i - 1];
        inv[i] %= mod;
    }
}
int Comb(int a, int b)
{
    // cout<<a<<" "<<b<<endl;
    int an = fact[a];
    //cout<<an<<endl;
    an *= inv[b];
    an %= mod;
    an *= inv[a - b];
    an %= mod;
    return an;
}

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
#define mod 1000000007

void solve()
{
    ll h, m;
    cin >> h >> m;
    // cout << h << m << endl;
    ll ch, dot, cm;
    string s;
    cin >> s;
    // cout << s << endl;
    bool flag = false;
    ll first = 0, second = 0, third = 0, fouth = 0;
    for (ll i = 0; i < s.size(); i++)
    {
        if (i == 0)
        {
            first = s[i] - '0';
            // cout << first;
        }
        else if (i == 1)
        {
            second = s[i] - '0';
        }
        else if (i == 3)
        {
            third = s[i] - '0';
        }
        else if (i == 4)
        {
            fouth = s[i] - '0';
        }
    }

    // ch = first * 10 + second;
    // cm = third * 10 + fouth;
    // cout << first << " " << second << endl;
    // cout << third << " " << fouth << endl;
    // cout << ch << " " << cm << endl;
    map<int, int> map;
    map[3] = -1;
    map[4] = -1;
    map[6] = -1;
    map[7] = -1;
    map[9] = -1;
    map[0] = 0;
    map[1] = 1;
    map[2] = 5;
    map[5] = 2;
    map[8] = 8;

    ll dch, dcm;
    dcm = 10 * third + fouth;
    dch = 10 * first + second;
    vector<pair<int, int>> v;
    for (ll i = dch; i < h; i++)
    {
        for (ll j = 0; j < m; j++)
        {
            ll one = i / 10;
            ll two = i % 10;
            ll three = j / 10;
            ll four = j % 10;

            if (map[one] == -1 || map[two] == -1 || map[three] == -1 || map[four] == -1)
                continue;
            one = map[one];
            two = map[two];
            three = map[three];
            four = map[four];
            ll ddch = one * 10 + two;
            ll ddcm = three * 10 + four;

            if (i < h && j < m && (i > dch || (dch == i && dcm <= j)))
            {
                // if ())
                // {
                v.pb({i, j});
                break;
                // }
            }
        }
    }

    if (v.size() == 0)
    {
        cout << "00:00" << endl;
        return;
    }

    cout << (v[0].first) / 10 << (v[0].first) % 10 << ":" << (v[0].second) / 10 << (v[0].second) % 10 << endl;

    // if ()
    // cin >> ch >> cm;
    // cout << ch << " m -> " << cm;
}
int main()
{
    io();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    // cout<<setprecision(10)
    return 0;
}