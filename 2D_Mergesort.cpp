// merge sort for a two-dimensional array.
// In case of odd dimension, the first division contains more number of elements than the second one.

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

int mat[1001][1001];

void mer1(int si, int mid, int ei, int cs, int cend)
{
    // cout << "GG";

    for (int ii = cs; ii <= cend; ii++)
    {
        int output[1000];

        int i = si;
        int p = mid + 1;
        int w = si;
        while (i <= mid && p <= ei)
        {
            if (mat[i][ii] < mat[p][ii])
                output[w++] = mat[i++][ii];
            else
                output[w++] = mat[p++][ii];
        }

        for (; i <= mid; i++)
            output[w++] = mat[i][ii];
        for (; p <= ei; p++)
            output[w++] = mat[p][ii];
        for (int u = si; u <= ei; u++)
        {
            mat[u][ii] = output[u];
        }
    }
}
void mer2(int si, int ei, int mid, int rs, int rend)
{

    for (int ii = rs; ii <= rend; ii++)
    {
        int output[1000];

        int i = si;
        int p = mid + 1;
        int w = si;
        while (i <= mid && p <= ei)
        {
            if (mat[ii][i] < mat[ii][p])
                output[w++] = mat[ii][i++];
            else
                output[w++] = mat[ii][p++];
        }

        for (; i <= mid; i++)
            output[w++] = mat[ii][i];
        for (; p <= ei; p++)
            output[w++] = mat[ii][p];
        for (int u = si; u <= ei; u++)
        {
            mat[ii][u] = output[u];
        }
    }
}

void helpp(ll rs, ll cs, ll re, ll ce)
{

    if (rs >= re && cs >= ce)
        return;

    ll midX = ceil((re + rs) / 2);
    ll midY = ceil((ce + cs) / 2);
    // cout << "H" << endl;
    helpp(rs, cs, midX, midY);
    helpp(rs, midY + 1, midX, ce);
    helpp(midX + 1, cs, re, midY);
    helpp(midX + 1, midY + 1, re, ce);

    mer2(cs, ce, midY, rs, re);
    mer1(rs, midX, re, cs, ce);
}
void solve()
{
    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
    helpp(0, 0, n - 1, m - 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << mat[i][j] << " ";
        // cout << endl;
    }
    cout << endl;
}
int main()
{
    io();
    solve();

    return 0;
}
