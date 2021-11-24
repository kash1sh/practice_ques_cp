
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

#ifndef ONLINE_JUDGE
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
}
int mod = 1e9 + 7, mxn = 3e5 + 5;

int add(int a, int b, int mod)
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

int mul(int a, int b, int mod)
{
    a %= mod;
    b %= mod;
    a *= b;
    a += mod;
    return a % mod;
}
int po(int a, int b, int mod)
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

ll solve(ll n, ll k, string s)
{
    // if (n == 1 || n == 2 || n == 0)
    // return n;
    ll cnt = 0;
    ll ans = 0;
    ll first = 0, last = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            if (cnt == 0)
            {
                ans++;
                first = i;
            }
            // first = i;
            // s[i] = 'x';
            cnt++;
        }
    }
    // string s2 = reverse(s.begin(), s.end());
    for (ll i = n - 1; i >= 0; i--)
    {
        if (s[i] == '*')
        {
            last = i;
            ans++;
            break;
        }
    }
    // ll ans = 2;
    if (cnt == 1 || cnt == 2 || cnt == 0)
        return cnt;
    s[first] = 'x';
    s[last] = 'x';
    char c = '*';
    // return 3;
    bool flag = false;

    for (ll i = 0; i < n; i++)
    {
        if (s[i] == '.')
            continue;
        // flag = false;
        if (s[i] == 'x')
        {
            flag = false;
            for (ll j = i + 1; j <= i + k; j++)
            {
                if (j < n && s[j] == 'x')
                {
                    flag = true;
                    break;
                }
                else if (j >= n)
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag == false)
        {
            for (ll j = i + k; j > i; j--)
            {
                if (j < n && s[j] == '*')
                {
                    s[j] = 'x';
                    ans++;
                    break;
                }
            }
        }
    }
    return ans;
}
int main()
{
    io();
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        cout << solve(n, k, s) << endl;
    }
    return 0;
}