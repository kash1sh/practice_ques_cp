
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
ll mod = 1e9 + 7, mxn = 3e5 + 5;
ll mul(ll a, ll b, ll mod)
{
    a %= mod;
    b %= mod;
    a *= b;
    a += mod;
    return a % mod;
}
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
bool sortbysecdesc(const pair<int, int> &a,
                   const pair<int, int> &b)
{
    return a.second > b.second;
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

// void fact0()
// {
//     int i,j;
//     fact[0]=1;
//     for(i=1;i<=200000;i++)
//     {
//         fact[i]=i*fact[i-1]%mod;
//     }
//     inv[0]=1;
//     inv[1]=1;
//     int p=mod;
//     for (i=2; i<=200000; i++)
//         inv[i] = (p - (p/i) * inv[p%i] % p) % p;

//     for(i=2;i<=200000;i++)
//     {
//         inv[i]*=inv[i-1];
//         inv[i]%=mod;
//     }
// }
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
ll help(ll a, ll b, ll c, ll x)
{
    return a * x * x + b * x + c;
}
void solve()
{
    ll a, b, c, k;
    cin >> a >> b >> c >> k;

    ll val = INT_MAX; // = help(a,b,c,k);

    int l = 0;
    int h = sqrt(k);

    while (h >= l)
    {
        ll mid = (l + h) / 2;
        debug(mid);
        if (k <= help(a, b, c, mid))
        {
            val = min(val, mid);
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << val << endl;
    return;
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

    // cout<<setprecision(10)
    return 0;
}