
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define ff first
#define ss second

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
ll mat[1001][1001];
int help(int x1, int x2, int y1, int y2)
{
    ll dp[1001][1001];
    memset(dp, 0, sizeof(dp));
    for (int i = x1 - 1; i < x2; i++)
    {
        for (int j = y1 - 1; j < y2; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = mat[i][j];
            else if (i == 0)
                dp[i][j] = dp[i][j - 1] + mat[i][j];
            else if (j == 0)
                dp[i][j] = dp[i - 1][j] + mat[i][j];
            else
                dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1])) + mat[i][j];
            // if (i > 0 && j > 0)
            // {
            //     mat[i][j] += max(mat[i][j - 1], mat[i - 1][j]);
            // }
            // else if (i > 0)
            // {
            //     mat[i][j] += mat[i - 1][j];
            // }
            // else
            //     mat[i][j] += mat[i][j - 1];
        }
    }
    // cout << dp[3][3];
    // cout << mat[x2][y2];
    // cout << mat[x1 - 1][y1 - 1];
    // cout<<mat[0][0]<<" "<<mat[2][2]<<endl
    // cout<<dp[2][2]<<endl;
    ll res = dp[x2 - 1][y2 - 1];
    return res;
}
void solve()
{
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll k = 1;
    for (int j = 0; j < 1000; j++)
    {
        if (j == 0)
            mat[j][0] = 1;
        else
            mat[j][0] = mat[j - 1][0] + k;
        k = k + 1;
    }
    for (int i = 0; i < 1000; i++)
    {
        mat[i][1] = mat[i][0] + i + 1;
        for (int j = 2; j < 1000; j++)
        {
            ll diff = mat[i][j - 1] - mat[i][j - 2];
            mat[i][j] = mat[i][j - 1] + diff + 1;
        }
    }
    // for (int i = 0; i < 10; i++)
    // {
    //     for (int j = 0; j < 10; j++)
    //         cout << mat[i][j] << " ";
    //     cout << endl;
    // }
    // cout << "HH";
    cout << help(x1, x2, y1, y2) << endl;
    return;
}
int main()
{
    io();
    ll t;
    cin >> t;
    while (t--)
    {
        // cout << "h";
        solve();
    }

    // cout<<setprecision(10)
    return 0;
}