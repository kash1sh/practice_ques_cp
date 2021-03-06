
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

bool primes[10000002];
vector<ll> arr(10000002);
void sieveOfEratosthenes(ll N)
{

    memset(primes, true, sizeof(primes));

    for (ll i = 2; i * i <= N; i++)
        if (primes[i] == true)
        {
            for (ll j = i * i; j <= N; j += i)
                primes[j] = false;
        }

    arr[1] = 0;
    for (ll i = 2; i <= N; i++)
    {
        arr[i] = arr[i - 1];
        if (primes[i])
            arr[i]++;
    }

    // return arr;
}
#define mod 1000000007

void solve()
{
    ll t;
    // vector<ll> arr(10000002);
    sieveOfEratosthenes(1e7 + 2);
    cin >> t;
    while (t--)
    {
        // solve();
        ll n;
        cin >> n;
        // map<ll, ll> m;
        // m.clear();
        // vll vis(n, false);
        // vector<bool> vis(n, false);
        // vis[2] = true;
        ll cnt = 1;
        // for (ll i = 2; i <= n; i = i + 2)
        // {
        //     if (i % 2 == 0)
        //     {
        //         // vis[i]
        //         // m[1]++;
        //         vis[i] = true;
        //     }
        // }

        // for (ll i = 3; i <= n; i = i + 2)
        // {
        //     if (vis[i] == true)
        //         continue;
        //     if (i * 2 < n)
        //     {
        //         primes[i] = false;
        //     }
        //     else if (primes[i])
        //         cnt++;
        // }
        // cout << cnt << endl;
        cout << arr[n] - arr[n / 2] << endl;
        return;
    }
}
int main()
{
    io();
    solve();

    // cout<<setprecision(10)
    return 0;
}