
// // #include <bits/stdc++.h>
// // #define ll long long
// // #define pb push_back
// // #define vll vector<ll>
// // #define vpll vector<pair<ll, ll>>
// // #define fo(i, k, n) for (ll i = k; i < n; i++)
// // #define fo1(i, k, n) for (ll i = k; i <= n; i++)
// // #define ff first
// // #define ss second

// // #define setbits(x) __builtin_popcountll(x)
// // #define zrobits(x) __builtin_ctzll(x)

// // using namespace std;

// // void io()
// // {
// //     ios::sync_with_stdio(false);
// //     cin.tie(0);
// //     // #ifndef ONLINE_JUDGE
// //     // freopen("input.txt", "r", stdin);
// //     // freopen("output.txt", "w", stdout);
// //     // #endif
// // }
// // ll mod = 1e9 + 7, mxn = 3e5 + 5;

// // ll add(ll a, ll b, ll mod)
// // {
// //     a %= mod;
// //     b %= mod;
// //     a += b;
// //     if (a >= mod)
// //         a -= mod;
// //     if (a < 0)
// //     {
// //         a += mod;
// //         a %= mod;
// //     }
// //     return a;
// // }

// // ll mul(ll a, ll b, ll mod)
// // {
// //     a %= mod;
// //     b %= mod;
// //     a *= b;
// //     a += mod;
// //     return a % mod;
// // }
// // // ll modInverse(ll a, ll m){
// // //     ll x, y;
// // //     ll g = gcdExtended(a, m, &x, &y);
// // //         ll res = (x%m + m) % m;
// // //         return res;
// // // }
// // // ll binary_Search(vector<ll>&arr,ll key){
// // //     ll l=0,r=arr.size()-1;
// // //     ll ans;
// // //     while(l<=r){
// // //         ll mid=(l+r)/2;
// // //         ll value=arr[mid];
// // //         if(value>key){
// // //             r=mid-1;
// // //         }else if(value==key){
// // //             return mid;
// // //         }else{
// // //             l=mid+1;
// // //         }
// // //     }
// // //     return -1;
// // // int L = 1;
// // // int R = n;
// // // int res = 0;

// // // while (L <= R)
// // // {
// // //     int mid = (L + R) / 2;

// // //     if (isValid(mid))
// // //         L = mid + 1, res = max(res, mid);
// // //     else
// // //         R = mid - 1;
// // // }

// // // return res;
// // // }
// // ll po(ll a, ll b, ll mod)
// // {
// //     if (b == 0)
// //         return 1;
// //     if (b % 2 == 0)
// //         return po(mul(a, a, mod), b / 2, mod);
// //     return mul(a, po(mul(a, a, mod), (b - 1) / 2, mod), mod);
// // }

// // long long power(long long X, long long N)
// // {
// //     if (N == 0)
// //         return 1;
// //     if (N % 2 == 0)
// //         return power(X * X, N / 2);
// //     return X * power(X, N - 1);
// // }

// // int fact[200003];
// // int inv[200003];

// // // void fact0()
// // // {
// // //     int i,j;
// // //     fact[0]=1;
// // //     for(i=1;i<=200000;i++)
// // //     {
// // //         fact[i]=i*fact[i-1]%mod;
// // //     }
// // //     inv[0]=1;
// // //     inv[1]=1;
// // //     int p=mod;
// // //     for (i=2; i<=200000; i++)
// // //         inv[i] = (p - (p/i) * inv[p%i] % p) % p;

// // //     for(i=2;i<=200000;i++)
// // //     {
// // //         inv[i]*=inv[i-1];
// // //         inv[i]%=mod;
// // //     }
// // // }
// // int Comb(int a, int b)
// // {
// //     // cout<<a<<" "<<b<<endl;
// //     int an = fact[a];
// //     //cout<<an<<endl;
// //     an *= inv[b];
// //     an %= mod;
// //     an *= inv[a - b];
// //     an %= mod;
// //     return an;
// // }

// // vector<int> sieveOfEratosthenes(int N)
// // {
// //     bool primes[N + 1];
// //     memset(primes, true, sizeof(primes));
// //     vector<int> arr;

// //     for (int i = 2; i * i <= N; i++)
// //         if (primes[i] == true)
// //         {
// //             for (int j = i * i; j <= N; j += i)
// //                 primes[j] = false;
// //         }

// //     for (int i = 2; i <= N; i++)
// //         if (primes[i])
// //             arr.emplace_back(i);

// //     return arr;
// // }
// // #define mod 1000000007

// // void solve()
// // {
// //     ll n;
// //     cin >> n;
// //     ll sum;
// //     cin >> sum;

// //     vll a(n);

// //     for (ll i = 0; i < n; i++)
// //         cin >> a[i];

// //     ll dp[sum + 1];
// //     dp[0] = 1;
// //     for (ll i = 1; i <= sum; i++)
// //     {
// //         dp[i] = 0;
// //         for (auto j : a)
// //         {
// //             if (i >= j)
// //                 dp[i] = (dp[i] + dp[i - j]) % mod;
// //         }
// //     }
// //     cout << dp[sum] << endl;
// // }
// // int main()
// // {
// //     io();
// //     solve();

// //     // ll t;
// //     // cin >> t;
// //     // while (t--)
// //     // {
// //     //     solve();
// //     // }

// //     // cout<<setprecision(10)
// //     return 0;
// // }

// #include <bits/stdc++.h>
// #define ll long long
// #define pb push_back
// #define vll vector<ll>
// #define vpll vector<pair<ll, ll>>
// #define fo(i, k, n) for (ll i = k; i < n; i++)
// #define fo1(i, k, n) for (ll i = k; i <= n; i++)
// #define rr return
// #define ff first
// #define ss second
// #define llmin LONG_MIN
// #define llmax LONG_MAX
// #define Yes cout << "Yes\n"
// #define No cout << "No\n"
// #define YES cout << "YES\n"
// #define NO cout << "NO\n"
// #define yes cout << "yes\n"
// #define no cout << "no\n"

// #define show(A)           \
//     for (auto i : A)      \
//         cout << i << " "; \
//     cout << '\n';
// #define endl "\n"
// #define Endl endl
// clock_t startTime = clock();
// #define setbits(x) __builtin_popcountll(x)
// #define zrobits(x) __builtin_ctzll(x)
// #define all(v) v.begin(), v.end()
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
//     cout.tie(0);
//     // #ifndef ONLINE_JUDGE
//     // freopen("input.txt", "r", stdin);
//     // freopen("error.txt","w",stderr);
//     // freopen("output.txt", "w", stdout);
//     // #endif
// }
// double PI = 4 * atan(1);
// ll mod = 1e9 + 7, mxn = 3e5 + 5;
// const int dx[4] = {1, -1, 0, 0};
// const int dy[4] = {0, 0, -1, 1};
// void deb(vector<ll> v)
// {
//     for (auto t : v)
//         cerr << t << " ";
//     cerr << "\n";
// }
// ll mul(ll a, ll b, ll mod)
// {
//     a %= mod;
//     b %= mod;
//     a *= b;
//     a += mod;
//     return a % mod;
// }

// bool sortbysecdesc(const pair<int, int> &a,
//                    const pair<int, int> &b)
// {
//     return a.second > b.second;
// }
// vll fact(2e5 + 5, 1);
// ll binPow(ll a, ll b)
// {
//     if (b == 0)
//         return 1;
//     if (b == 1)
//         return a;
//     ll ret = binPow(a, b / 2);
//     if (b % 2 == 0)
//         return (ret * ret) % mod;
//     return ((ret * ret) % mod * a) % mod;
// }
// ll inv(ll a)
// {
//     return (binPow(a, mod - 2) % mod + mod) % mod;
// }
// ll binom(ll a, ll b)
// {
//     // before t
//     //  for (int i = 1;i<=2e5;i++)fact[i] = (i * fact[i - 1])%mod;
//     if (b < 0 or a < 0)
//         return 0;
//     return (((fact[a] * inv(fact[b])) % mod * inv(fact[a - b])) % mod + mod) % mod;
// }
// // CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
// // int a = count(all(s),'A');
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
// vector<int> factors(int n)
// {
//     vector<int> f;
//     for (int x = 2; x * x <= n; x++)
//     {
//         while (n % x == 0)
//         {
//             f.push_back(x);
//             n /= x;
//         }
//     }
//     if (n > 1)
//         f.push_back(n);
//     return f;
// }
// bool valid_coordinate(ll x, ll y, ll n, ll m)
// {
//     if (x < 0 || y < 0)
//         return false;

//     else if (x >= n || y >= m)
//         return false;

//     else
//         return true;
// }

// bool prime(ll n)
// {
//     if (n < 2)
//         return false;
//     for (ll x = 2; x * x <= n; x++)
//     {
//         if (n % x == 0)
//             return false;
//     }
//     return true;
// }

// bool isPowerOfTwo(ll n)
// {
//     return n && (!(n & (n - 1)));
// }
// // Find Min/Max
// // * Greedy/Brute Force
// //* Prefix array of max/min
// // * BS
// // * DP

// void solve()
// {
//     ll n, sum;
//     cin >> n >> sum;
//     vll a(n);

//     for (ll i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     // sort(a.begin(), a.end());

//     vll dp(sum + 2, 0);
//     dp[0] = 1;

//     for (ll i = 1; i <= sum; i++)
//     {
//         for (ll j = 0; j < n; j++)
//         {
//             if (i - a[j] >= 0)
//             {
//                 dp[i] = (dp[i] + dp[i - a[j]]) % mod;
//             }
//         }
//     }
//     cout << dp[sum] << endl;
//     rr;
// }
// int main()
// {
//     io();
//     // solve();
//     ll t = 1;
//     // ll t;
//     // cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

//     // cout<<fixed<<setprecision(10)<<ans<<endl;

//     // cout<<printf("%.8lf", hi)<<endl;
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

void solve()
{
    ll n;
    cin >> n;
    ll sum;
    cin >> sum;

    vll a(n);

    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll dp[sum + 1];
    dp[0] = 1;
    for (ll i = 1; i <= sum; i++)
    {
        dp[i] = 0;
        for (auto j : a)
        {
            if (i >= j)
                dp[i] = (dp[i] + dp[i - j]) % mod;
        }
    }
    cout << dp[sum] % mod << endl;
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