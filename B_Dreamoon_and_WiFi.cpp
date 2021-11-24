
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
// ll binary_Search(vector<ll>&arr,ll key){
//     ll l=0,r=arr.size()-1;
//     ll ans;
//     while(l<=r){
//         ll mid=(l+r)/2;
//         ll value=arr[mid];
//         if(value>key){
//             r=mid-1;
//         }else if(value==key){
//             return mid;
//         }else{
//             l=mid+1;
//         }
//     }
//     return -1;
// int L = 1;
// int R = n;
// int res = 0;

// while (L <= R)
// {
//     int mid = (L + R) / 2;

//     if (isValid(mid))
//         L = mid + 1, res = max(res, mid);
//     else
//         R = mid - 1;
// }

// return res;
// }
ll po(ll a, ll b, ll mod)
{
    ll result = 1;
    while (b > 0)
    {
        if (b & 1)
            result = a * result % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return result;
}

long long power(long long X, long long N)
{
    if (N == 0)
        return 1;
    if (N % 2 == 0)
        return power(X * X, N / 2);
    return X * power(X, N - 1);
}

ll fact[200003];
ll inv[200003];

void fact0()
{
    int p = mod;
    fact[0] = 1;
    ll i;
    for (i = 1; i <= 200000; i++)
    {
        fact[i] = i * fact[i - 1] % mod;
    }
    i--;
    inv[i] = po(fact[i], p - 2, p);
    for (i--; i >= 0; i--)
    {
        inv[i] = inv[i + 1] * (i + 1) % p;
    }
}

ll nCr(ll n, ll r)
{
    if (r > n || n < 0 || r < 0)
        return 0;
    return fact[n] * inv[r] % mod * inv[n - r] % mod;
}
// void fact0()
// {
//     int i, j;
//     fact[0] = 1;
//     for (i = 1; i <= 200000; i++)
//     {
//         fact[i] = i * fact[i - 1] % mod;
//     }
//     inv[0] = 1;
//     inv[1] = 1;
//     int p = mod;
//     for (i = 2; i <= 200000; i++)
//         inv[i] = (p - (p / i) * inv[p % i] % p) % p;

//     for (i = 2; i <= 200000; i++)
//     {
//         inv[i] *= inv[i - 1];
//         inv[i] %= mod;
//     }
// }
// int Comb(int a, int b)
// {
//     // cout<<a<<" "<<b<<endl;
//     int an = fact[a];
//     //cout<<an<<endl;
//     an *= inv[b];
//     an %= mod;
//     an *= inv[a - b];
//     an %= mod;
//     return an;
// }

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
int final;
string st, bt;
int ans(int i, int cnt)
{
    if (i == bt.size())
    {
        if (cnt == final)
            return 1;
        return 0;
    }

    if (bt[i] == '?')
        return ans(i + 1, cnt + 1) + ans(i + 1, cnt - 1);

    if (bt[i] == '+')
        return ans(i + 1, cnt + 1);

    return ans(i + 1, cnt - 1);
}
void solve()
{
    // string s1, s2;
    ll c1 = 0, c2 = 0;
    ll cnt1 = 0, cnt2 = 0;
    cin >> st >> bt;
    int p = 0;
    for (int i = 0; i < st.size(); i++)
    {
        if (st[i] == '+')
            final++;
        else
            final--;

        if (bt[i] == '?')
            p++;
    }
    int x = ans(0, 0);
    cout << fixed << setprecision(12) << x / pow(2, p);
}
int main()
{
    io();
    solve();

    // ll t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }

    // cout<<setprecision(10)
    return 0;
}