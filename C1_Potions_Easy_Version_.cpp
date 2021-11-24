
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

// using namespace std;

// void io()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     // #ifndef ONLINE_JUDGE
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);
//     // #endif
// }
// ll mod = 1e9 + 7, mxn = 3e5 + 5;

// ll add(ll a, ll b, ll mod)
// {
//     a %= mod;
//     b %= mod;
//     a += b;
//     if (a >= mod)
//         a -= mod;
//     if (a < 0)
//     {
//         a += mod;
//         a %= mod;
//     }
//     return a;
// }

// ll mul(ll a, ll b, ll mod)
// {
//     a %= mod;
//     b %= mod;
//     a *= b;
//     a += mod;
//     return a % mod;
// }
// // ll modInverse(ll a, ll m){
// //     ll x, y;
// //     ll g = gcdExtended(a, m, &x, &y);
// //         ll res = (x%m + m) % m;
// //         return res;
// // }
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
// #define mod 1000000007
// vll a;
// ll maxCount = INT_MIN;
// ll help(ll i, ll n, ll count, ll sum)
// {
//     if (i == n)
//     {
//         if (count > maxCount)
//         {
//             maxCount = count;
//             // return sum;
//         }

//         return count;
//     }
//     ll counta = 0;

//     if (a[i] >= 0)
//     {
//         counta = help(i + 1, n, count + 1, sum + a[i]);
//     }
//     else
//     {
//         if (sum + a[i] >= 0)
//         {
//             ll count1 = help(i + 1, n, count + 1, sum + a[i]);
//             counta = count1;

//             count1 = help(i + 1, n, count, sum);

//             counta = max(counta, count1);
//         }
//     }
//     return counta;
// }
// void solve()
// {
//     ll n;
//     cin >> n;

//     // vll a(n);

//     a.clear();
//     a.resize(n);

//     for (ll i = 0; i < n; i++)
//         cin >> a[i];
//     ll count = 0;
//     ll sum = 0;

//     ll ans = help(0, n, count, sum);
//     cout << maxCount << endl;
// }

// // vll a;
// // ll maxCount = INT_MIN;
// // int dp[2001][2001];
// // ll help(ll i, ll n, ll sum)
// // {
// //     if (i == n)
// //     {
// //         return 1;
// //     }
// //     if (dp[i][sum] != -1)
// //         return dp[i][sum];

// //     if (a[i] >= 0)
// //     {
// //         // count++;
// //         // vis[i] = tru;
// //         // pair<ll, ll> s;
// //         // count++;
// //         dp[i][sum] = help(i + 1, n, sum + a[i]);
// //         // counta = help(i + 1, n, count + 1, sum + a[i], vis);
// //         // sum = s.first;
// //         // count = s.ss;
// //     }
// //     else
// //     {
// //         if (sum + a[i] >= 0)
// //         {
// //             // count++;
// //             // vis[i] = true;
// //             // pair<ll, ll> s;

// //             dp[i][sum] = help(i + 1, n, sum + a[i]) + help(i + 1, n, sum);
// //             // count++;
// //             // ll count1 = help(i + 1, n, count + 1, sum + a[i], vis);
// //             // counta = count1;
// //             // // count--;
// //             // count1 = help(i + 1, n, count, sum, vis);

// //             // counta = max(counta, count1);
// //             // count += max(help(), help());
// //             // sum = s.first;
// //             // count = s.ss;
// //         }
// //     }
// //     return dp[i][sum];
// // }
// // void solve()
// // {
// //     ll n;
// //     cin >> n;

// //     // vll a(n);

// //     a.clear();
// //     a.resize(n);

// //     for (ll i = 0; i < n; i++)
// //         cin >> a[i];
// //     ll count = 0;
// //     ll sum = 0;
// //     vector<bool> vis(n, false);
// //     memset(dp, -1, sizeof(dp));
// //     ll ans = help(0, n, sum);
// //     cout << ans << endl;
// // }
// int main()
// {
//     io();
//     solve();

//     // ll t;
//     // cin >> t;
//     // while (t--)
//     // {
//     //     solve();
//     // }

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

    vll a(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    multiset<ll> s;
    ll sum = 0;
    ll cnt = 0;
    for (ll i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            s.insert(-1 * a[i]);
        }
        sum += a[i];
        cnt++;

        while (sum < 0)
        {
            ll front = *s.rbegin();
            sum += front;
            s.erase(s.find(*s.rbegin()));

            cnt--;
        }
    }
    cout << cnt << endl;
    return;
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