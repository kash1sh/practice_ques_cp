
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define ff first
#define ss second
#define rr return
#define Endl endl

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
    // freopen("error.txt", "w", stderr);
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
    // ll n, m;
    // cin >> n >> m;

    // vll a(n);
    // vll pre(m);

    // for (ll i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    //     a[i]--;
    // }

    // for (ll i = 0; i < m; i++)
    //     cin >> pre[i];

    // // ll dp[100001][100001];
    // sort(a.begin(), a.end(), greater<ll>());

    // ll idx = 0;
    // ll ans = 0;

    // for (ll i = 0; i < n; i++)
    // {
    //     if (a[i] >= idx)
    //     {
    //         ans += pre[idx];
    //         idx++;
    //     }
    //     else
    //         ans += pre[a[i]];
    // }
    // debug(ans);
    // // print(pre);
    // cout << ans << endl;
    // // dp[0][0] = 0;

    // for (ll i = 1; i < n; i++)
    // {
    //     for (ll j = 1; j < m; j++)
    //     {
    //         if (pre[j - 1] <= a[i])
    //         {
    //             dp[i][j] = dp[i - 1][j] + min(pre[a[i] - 1], pre[j - 1]);
    //         }
    //         else
    //             dp[i][j] = dp[i - 1][j] + pre[j - 1];
    //     }
    // }
    ll n, m;
    cin >> n >> m;
    // vpll
    vll a(n), b(m);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    for (ll j = 0; j < m; j++)
    {
        cin >> b[j];
    }
    vpll v(n);
    fo(i, 0, n)
    {
        v.pb({b[a[i]], a[i]});
    }
    sort(v.begin(), v.end(), greater<>());
    ll idx = 0, sum = 0;
    for (ll i = 0; i < n; i++)
    {
        if (b[v[i].ss] > b[idx])
        {
            // debug(b[idx]);
            sum += b[idx];
            // b[idx] = INT_MAX;
            idx++;
        }
        else
        {
            // debug(b[v[i].ss]);
            sum += b[v[i].ss];
        }
    }
    cout << sum << endl;
    rr;
    // vll sec(m, false);
    // ll mid = m / 2;
    // ll j = 0;
    // ll cost = 0;
    // for (ll i = 0; i < n; i++)
    // {
    //     if (a[i] <= mid)
    //     {
    //         cost += b[a[i]];
    //     }
    //     else
    //     {

    //         if (sec[j] == false)
    //         {
    //             sec[j] = true;
    //             cost += b[j++];
    //         }
    //         else
    //         {
    //             while (sec[j] == false)
    //             {
    //                 j++;
    //             }
    //             if (j < n)
    //             {
    //                 cost += b[j++];
    //                 sec[j] = true;
    //             }
    //             else
    //             {
    //                 cost += b[a[i]];
    //             }
    //             // debug(cost);
    //         }
    //     }
    // }
    // cout << cost << endl;
    // return;
}
int main()
{
    io();
    // solve();

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    // cout<<setprecision(10)
    return 0;
}