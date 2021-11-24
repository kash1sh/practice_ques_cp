
// #include <bits/stdc++.h>
// #define ll long long
// #define pb push_back
// #define vll vector<ll>
// #define vpll vector<pair<ll, ll>>
// #define fo(i, k, n) for (ll i = k; i < n; i++)
// #define fo1(i, k, n) for (ll i = k; i <= n; i++)
// #define ff first
// #define ss second

// #define setbits(x) __builtin_popcountll(x)
// #define zrobits(x) __builtin_ctzll(x)
// #ifndef ONLINE_JUDGE
// #define debug(x) cerr << #x << " " << x << endl;
// #else
// #define debug(x)
// #endif
// using namespace std;

// void io()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     // #ifndef ONLINE_JUDGE
//     // freopen("input.txt", "r", stdin);
//     // freopen("error.txt","w",stderr);
//     // freopen("output.txt", "w", stdout);
//     // #endif
// }
// ll mod = 1e9 + 7, mxn = 3e5 + 5;
// ll mul(ll a, ll b, ll mod)
// {
//     a %= mod;
//     b %= mod;
//     a *= b;
//     a += mod;
//     return a % mod;
// }
// // ll binary_Search(vector<ll>&arr,ll key){
// //     ll l=0,r=arr.size()-1;
// //     ll ans;
// //     while(l<=r){
// //         ll mid=(l+r)/2;
// //         ll value=arr[mid];
// //         if(value>key){
// //             r=mid-1;
// //         }else if(value==key){
// //             return mid;
// //         }else{
// //             l=mid+1;
// //         }
// //     }
// //     return -1;
// // int L = 1;
// // int R = n;
// // int res = 0;

// // while (L <= R)
// // {
// //     int mid = (L + R) / 2;

// //     if (isValid(mid))
// //         L = mid + 1, res = max(res, mid);
// //     else
// //         R = mid - 1;
// // }

// // return res;
// // }
// bool sortbysecdesc(const pair<int, int> &a,
//                    const pair<int, int> &b)
// {
//     return a.second > b.second;
// }

// ll po(ll a, ll b, ll mod)
// {
//     if (b == 0)
//         return 1;
//     if (b % 2 == 0)
//         return po(mul(a, a, mod), b / 2, mod);
//     return mul(a, po(mul(a, a, mod), (b - 1) / 2, mod), mod);
// }

// long long power(long long X, long long N)
// {
//     if (N == 0)
//         return 1;
//     if (N % 2 == 0)
//         return power(X * X, N / 2);
//     return X * power(X, N - 1);
// }

// int fact[200003];
// int inv[200003];

// // void fact0()
// // {
// //     int i,j;
// //     fact[0]=1;
// //     for(i=1;i<=200000;i++)
// //     {
// //         fact[i]=i*fact[i-1]%mod;
// //     }
// //     inv[0]=1;
// //     inv[1]=1;
// //     int p=mod;
// //     for (i=2; i<=200000; i++)
// //         inv[i] = (p - (p/i) * inv[p%i] % p) % p;

// //     for(i=2;i<=200000;i++)
// //     {
// //         inv[i]*=inv[i-1];
// //         inv[i]%=mod;
// //     }
// // }
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
// // CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
// vector<int> sieveOfEratosthenes(int N)
// {
//     bool primes[N + 1];
//     memset(primes, true, sizeof(primes));
//     vector<int> arr;

//     for (int i = 2; i * i <= N; i++)
//         if (primes[i] == true)
//         {
//             for (int j = i * i; j <= N; j += i)
//                 primes[j] = false;
//         }

//     for (int i = 2; i <= N; i++)
//         if (primes[i])
//             arr.emplace_back(i);

//     return arr;
// }
// void prime_fact(ll n, vector<ll> &res)
// {
//     while (n % 2 == 0)
//     {
//         res.pb(2);
//         n = n / 2;
//     }

//     for (ll i = 3; i <= sqrt(n); i = i + 2)
//     {
//         while (n % i == 0)
//         {
//             res.pb(i);
//             n = n / i;
//         }
//     }
//     if (n > 2)
//     {
//         res.pb(n);
//     }
// }

// void solve()
// {
//     ll n, w;
//     cin >> n >> w;
//     vll v(n);
//     for (ll i = 0; i < n; i++)
//         cin >> v[i];
//     vector<pair<ll, ll>> a(n);
//     ll mini = 0;
//     if (w % 2)
//         mini = (w / 2) + 1;
//     else
//         mini = w / 2;
//     for (ll i = 0; i < n; i++)
//     {
//         a[i].first = v[i];
//         a[i].ss = i + 1;
//     }
//     // sort(a.begin(), a.e  nd());
//     // reverse(a.begin(), a.end());

//     ll sum = 0, j = 0, k = 0;
//     vll ans(n);
//     // if (a[j].first > w)
//     // {
//     //     cout << -1 << endl;
//     //     return;
//     // }
//     while (sum < mini)
//     {
//         sum += a[j].first;
//         ans[k++] = a[j++].ss;
//     }
//     if (sum > w)
//     {
//         cout << -1 << endl;
//         return;
//     }
//     cout << k << endl;
//     for (ll i = 0; i < k; i++)
//         cout << ans[i] << " ";
//     cout << endl;
//     return;
// }
// int main()
// {
//     io();
//     // solve();
//     // ll t=1;
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }

//     // cout<<setprecision(10)
//     return 0;
// }

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

vll fac(200003);
ll facto(ll n)
{

    fac[0] = 1;
    fac[1] = 1;
    for (ll i = 2; i <= 200003; i++)
    {
        fac[i] = i * fac[i - 1];
    }
    return fac[n];
}
long combi(ll n, ll k)
{
    long long ans = 1;
    k = k > n - k ? n - k : k;
    ll j = 1;
    for (; j <= k; j++, n--)
    {
        if (n % j == 0)
        {
            ans *= n / j;
        }
        else if (ans % j == 0)
        {
            ans = ans / j * n;
        }
        else
        {
            ans = (ans * n) / j;
        }
    }
    return ans;
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

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll half = ceil(k / 2);
    ll full = k;
    vll a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // cout << "S";
    // vll b(a);
    // vector<pair<ll, ll>> b;
    // for (ll i = 0; i < n; i++)
    // {
    // b[i] = {a[i], i};
    // }
    // map<ll, ll> m;
    // for (ll i = 0; i < n; i++)
    // {
    //     m[i] = i;
    // }
    vpll b(n);
    // // vector < pair<ll, ll> b;
    for (ll i = 0; i < n; i++)
    {
        b[i].ff = a[i];
        b[i].ss = i;
        // b[i] = ({a[i], i});
        // b.pb({a[i], i});
    }
    sort(b.begin(), b.end());
    // // sort(a.begin(), a.end());
    if (b[0].ff > full)
    {
        cout << -1 << endl;
        return;
    }
    for (ll i = 0; i < n; i++)
    {
        if (b[i].ff >= half && b[i].ff <= full)
        {
            cout << 1 << endl;
            cout << b[i].ss + 1 << endl;
            return;
        }
    }
    // for (ll i = 0; i < n; i++)
    // {
    //     cerr << b[i].ff << " ";
    //     cerr << endl;
    // }
    // cout << "S";
    ll s = 0, e = n - 1;
    ll sum = 0;
    // ll latest = a[e];
    bool f = true;
    ll cnt = 0;
    vll ans;
    // sum=0;
    for (ll i = n - 1; i >= 0; i--)
    {
        cerr << b[i].ff << endl;
        if (b[i].ff < half)
        {
            sum += b[i].ff;
            ans.pb(b[i].ss + 1);
        }
        debug(sum);
        if (sum >= half)
        {
            cout << ans.size() << endl;
            for (ll j = 0; j < ans.size(); j++)
            {
                cout << ans[j] << " ";
            }
            return;
        }
    }
    cout << -1 << endl;
    return;
    // while (sum < half)
    // {
    //     if (b[e].ff > full || sum + b[e].ff > full)
    //     {
    //         e--;
    //         continue;
    //     }
    //     //     // continue;
    //     //     // if (sum + a[e] > full)
    //     //     // {
    //     //     //     e--;
    //     //     //     continue;
    //     //     // }
    //     //     // continue;
    //     //     // ans.pb(m[a[e]] + 1);
    //     ans.pb(b[e].ss + 1);
    //     debug(b[e].ff);
    //     sum += b[e].ff;
    //     e--;

    //     //     cnt++;
    //     if (e < 0 && sum < half)
    //     {
    //         f = false;
    //     }
    // }

    // if (f == false || ans.size() == 0)
    // {
    //     cout << -1 << endl;
    //     return;
    // }
    // // if (sum > full)
    // // {
    // // }
    // else
    // {
    //     // cout << cnt << endl;
    // cout << ans.size() << endl;
    // for (ll i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    // return;
    //     // return;
    // }
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