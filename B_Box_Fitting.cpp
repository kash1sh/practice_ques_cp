
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

bool sortbysecdesc(const pair<int, int> &a,
                   const pair<int, int> &b)
{
    return a.second > b.second;
}
vll a;
ll n, W;
bool check(ll val)
{
    // for(ll i=0;i<val;i++){

    // }
    ll space = W;
    ll i = 0;
    while (val)
    {
        space -= a[i];
        if (space <= 0)
        {
            val--;
            space = W;
        }
        else
        {
            i++;
        }
    }
    if (i >= n && val >= 0)
    {
        return true;
    }
    return false;
}
void solve()
{

    cin >> n >> W;

    fo(i, 0, n)
    {
        ll x;
        cin >> x;
        a.pb(x);
    }
    sort(a.begin(), a.end(), greater<>());
    // multiset<ll> s;
    // for (ll i = 0; i < n; i++)
    // {
    //     cin >> a[i];
    //     s.insert(a[i]);
    //     // m[a[i]]++;
    // }
    // ll rem = W, level = 1;
    // while (!s.empty())
    // {
    //     if (*s.begin() > rem)
    //     {
    //         rem = W;
    //         level++;
    //     }
    //     auto it = s.upper_bound(rem);
    //     if (it != s.begin())
    //     {
    //         it--;
    //         debug(*it);
    //         rem -= *it;
    //         debug(rem);
    //         // level++;
    //         s.erase(it);
    //     }
    // }
    // cout << level << endl;
    // return;
    ll h = 1000000, l = 0;
    ll ans = INT_MAX;
    while (l < h)
    {
        ll mid = (h + l) / 2;

        if (check(mid))
        {
            ans = min(ans, mid);
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << Endl;
    rr;
    // ll maxa = -1;
    // vector<pair<ll, ll>> v(n);
    // ll j = 0;
    // for (auto i : m)
    // {
    //     // if (i.ss > maxa)
    //     // maxa = i.ss;
    //     v[j].first = i.ff;
    //     v[j++].ss = i.ss;
    // }
    // // cout << maxa << endl;

    // sort(v.begin(), v.end(), sortbysecdesc);
    // ll k = 0;
    // while (W > 0 && k < n)
    // {
    //     W -= v[k].ff;
    //     v[k].ss--;
    //     if (k + 1 < n && v[k].ss < v[k + 1].ss)
    //         k++;
    // }
    // for (auto i : v)
    // {
    //     if (maxa < i.ss)
    //         maxa = i.ss;
    // }
    // cout << maxa + 1 << endl;
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