
// #include <bits/stdc++.h>
// #define ll long long
// #define pb push_back
// #define vll vector<ll>
// #define vpll vector<pair<ll, ll>>
// #define fo(i, k, n) for (ll i = k; i < n; i++)
// #define fo1(i, k, n) for (ll i = k; i <= n; i++)
// #define rr return
// #define Endl endl
// #define ff first
// #define ss second
// // #define all(X) (X).begin(), (X).end()
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
//     // #ifndef ONLINE_JUDGE
//     // freopen("input.txt", "r", stdin);
//     // freopen("error.txt","w",stderr);
//     // freopen("output.txt", "w", stdout);
//     // #endif
// }
// double PI = 4 * atan(1);
// ll mod = 1e9 + 7, mxn = 3e5 + 5;
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
// bool check_sorted(vll a)
// {
//     ll n = a.size();
//     for (ll i = 1; i < n; i++)
//     {
//         if (a[i] >= a[i - 1])
//             continue;
//         return false;
//     }
//     return true;
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
// bool valid_coordinate(ll x, ll y, ll n, ll m)
// {
//     if (x < 0 || y < 0)
//         return false;

//     else if (x >= n || y >= m)
//         return false;

//     else
//         return true;
// }

// int sod(int n)
// {
//     int sum = 0;
//     while (n)
//     {
//         sum += (n % 10);
//         n /= 10;
//     }
//     return sum;
// }

// bool isPowerOfTwo(ll n)
// {
//     return n && (!(n & (n - 1)));
// }
// // Find Min/Max
// // * Greedy/Brute Force
// // * DP
// // * BS
// void computeLPSArray(string pat, int M,
//                      int lps[])
// {

//     // Length of the previous longest
//     // prefix suffix
//     int len = 0;
//     int i = 1;
//     lps[0] = 0; // lps[0] is always 0

//     // The loop calculates lps[i] for
//     // i = 1 to M-1
//     while (i < M)
//     {
//         if (pat[i] == pat[len])
//         {
//             len++;
//             lps[i] = len;
//             i++;
//         }
//         else // (pat[i] != pat[len])
//         {

//             // This is tricky. Consider the example.
//             // AAACAAAA and i = 7. The idea is similar
//             // to search step.
//             if (len != 0)
//             {
//                 len = lps[len - 1];

//                 // Also, note that we do not
//                 // increment i here
//             }
//             else // if (len == 0)
//             {
//                 lps[i] = len;
//                 i++;
//             }
//         }
//     }
// }

// int KMPSearch(string pat, string txt)
// {
//     int M = pat.length();
//     int N = txt.length();

//     // Create lps[] that will hold the longest
//     // prefix suffix values for pattern
//     int lps[M];
//     int j = 0; // index for pat[]

//     // Preprocess the pattern (calculate lps[]
//     // array)
//     computeLPSArray(pat, M, lps);

//     int i = 0; // index for txt[]
//     int res = 0;
//     int next_i = 0;

//     while (i < N)
//     {
//         if (pat[j] == txt[i])
//         {
//             j++;
//             i++;
//         }
//         if (j == M)
//         {

//             // When we find pattern first time,
//             // we iterate again to check if there
//             // exists more pattern
//             j = lps[j - 1];
//             res++;
//         }

//         // Mismatch after j matches
//         else if (i < N && pat[j] != txt[i])
//         {

//             // Do not match lps[0..lps[j-1]]
//             // characters, they will match anyway
//             if (j != 0)
//                 j = lps[j - 1];
//             else
//                 i = i + 1;
//         }
//     }
//     return res;
// }
// vll v;
// void KMP(string pat, string txt)
// {
//     // int M = strlen(pat);
//     int M = pat.size();
//     int N = pat.size();
//     // int N = strlen(txt);

//     // create lps[] that will hold the longest prefix suffix
//     // values for pattern
//     int lps[M];

//     // Preprocess the pattern (calculate lps[] array)
//     computeLPSArray(pat, M, lps);

//     int i = 0; // index for txt[]
//     int j = 0; // index for pat[]
//     while (i < N)
//     {
//         if (pat[j] == txt[i])
//         {
//             j++;
//             i++;
//         }

//         if (j == M)
//         {
//             // printf("Found pattern at index %d ", i - j);
//             v.pb(i - j);
//             j = lps[j - 1];
//         }

//         // mismatch after j matches
//         else if (i < N && pat[j] != txt[i])
//         {
//             // Do not match lps[0..lps[j-1]] characters,
//             // they will match anyway
//             if (j != 0)
//                 j = lps[j - 1];
//             else
//                 i = i + 1;
//         }
//     }
// }

// // Fills lps[] for given patttern pat[0..M-1]

// void solve()
// {
//     // int ans = KMPSearch(pat, txt);
//     ll n, q;
//     cin >> n >> q;
//     string s;
//     cin >> s;
//     string pat = "abc";
//     // char pat[] = "abc";
//     // debug(n);
//     KMP(pat, s);
//     sort(v.begin(), v.end());
//     while (q--)
//     {
//         ll x;
//         char a;
//         cin >> x >> a;
//         s[x - 1] = a;
//         ll ind = upper_bound(v.begin(), v.end(), x) - v.begin();

//         if (ind == 0)
//         {
//             cout << 0 << endl;
//             continue;
//         }
//         ind--;
//         if (v[ind] >= x && v[ind] + 3 <= x)
//         {
//             cout << v.size() - 1 << endl;
//             // rr;
//         }
//         cout << KMPSearch(pat, s) << endl;
//     }
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
#define rr return
#define ff first
#define ss second
#define Auto auto
#define llmin LONG_MIN
#define llmax LONG_MAX
#define Yes cout << "Yes\n"
#define No cout << "No\n"
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define yes cout << "yes\n"
#define no cout << "no\n"

#define show(A)           \
    for (auto i : A)      \
        cout << i << " "; \
    cout << '\n';
#define endl "\n"
#define Endl endl
clock_t startTime = clock();
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " " << x << endl;
#else
#define debug(x)
#endif
using namespace std;

typedef vector<vector<long long>> vvll;

void io()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("error.txt","w",stderr);
    // freopen("output.txt", "w", stdout);
    // #endif
}
double PI = 4 * atan(1);
ll mod = 1e9 + 7, mxn = 3e5 + 5;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
void deb(vector<ll> v)
{
    for (auto t : v)
        cerr << t << " ";
    cerr << "\n";
}
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
vll fact(2e5 + 5, 1);
ll binPow(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    ll ret = binPow(a, b / 2);
    if (b % 2 == 0)
        return (ret * ret) % mod;
    return ((ret * ret) % mod * a) % mod;
}
ll inv(ll a)
{
    return (binPow(a, mod - 2) % mod + mod) % mod;
}
ll binom(ll a, ll b)
{
    // before t
    //  for (int i = 1;i<=2e5;i++)fact[i] = (i * fact[i - 1])%mod;
    if (b < 0 or a < 0)
        return 0;
    return (((fact[a] * inv(fact[b])) % mod * inv(fact[a - b])) % mod + mod) % mod;
}
// CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
// int a = count(all(s),'A');
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
vector<int> primeFactors(int n)
{
    vector<int> f;
    for (int x = 2; x * x <= n; x++)
    {
        while (n % x == 0)
        {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1)
        f.push_back(n);
    return f;
}

bool isPrime(ll n)
{
    if (n < 2)
        return false;
    for (ll x = 2; x * x <= n; x++)
    {
        if (n % x == 0)
            return false;
    }
    return true;
}

bool isPowerOfTwo(ll n)
{
    return n && (!(n & (n - 1)));
}
/*
vector<ll>adj[100005];
bool vis[100005];
ll dist[100005];
void bfs(ll c)
{
  vis[c]=true;
  dist[c]=0;
  queue<ll>q;
  q.push(c);
while(!q.empty())
{
    ll x=q.front();
    q.pop();

    for(auto y:adj[x])
    {
        if(!vis[y])
        {
            vis[y]=true;
            dist[y]=dist[x]+1;

            q.push(y);
        }
    }

}
}
*/
// Find Min/Max
// * Greedy/Brute Force
//* Prefix array of max/min
// * BS
// * DP/KNPS
void solve()
{
    // ll n, q;
    // cin >> n >> q;
    // string s;
    // cin >> s;
    // vector<ll> res;
    // set<ll> ss;
    // for (ll i = 0; i < n; i++)
    // {
    //     if (s[i] == 'a')
    //     {
    //         string s1 = s.substr(i, 3);
    //         // cout << i << endl;
    //         // cout << s1 << endl;
    //         if (s1 == "abc")
    //         {
    //             res.pb(i);
    //             ss.insert(i);
    //         }
    //     }
    // }
    // // deb(res);
    // ll cnt = ss.size();
    // debug(cnt);
    // for (ll i = 0; i < q; i++)
    // {
    //     ll x;
    //     char y;
    //     cin >> x >> y;
    //     // x--;
    //     for (ll i = max(0ll, x - 4ll); i <= min(n - 3, x + 4ll); i++)
    //     {
    //         string s1 = s.substr(i, 3ll);
    //         if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
    //         {
    //             ss.insert(i);
    //         }
    //         else
    //         {
    //             ss.erase(i);
    //         }
    //     }
    //     cout << ss.size() << endl;
    //     continue;
    //     // for (ll i = max(0ll, x - 2ll); i <= x; i++)
    //     // {
    //     //     string s1 = s.substr(i, 3);
    //     //     if (s1 == "abc")
    //     //     {
    //     //         cnt--;
    //     //     }
    //     // }
    //     // s[x] = y;
    //     // // ll val=max(0,x-2)
    //     // for (ll i = max(0ll, x - 2ll); i <= x; i++)
    //     // {
    //     //     string s1 = s.substr(i, 3);
    //     //     if (s1 == "abc")
    //     //     {
    //     //         cnt++;
    //     //     }
    //     // }
    //     // cout << y << endl;
    //     // if(find(all(res),x))
    //     // if (y != 'a')
    //     // {
    //     //     if (ss.find(x - 1) != ss.end())
    //     //     {
    //     //         cnt--;
    //     //         ss.erase(x);
    //     //     }
    //     //     s[x - 1] = y;
    //     //     if (y == 'b')
    //     //     {
    //     //         if (x - 2 < 0)
    //     //         {
    //     //             cout << cnt << endl;
    //     //             continue;
    //     //         }
    //     //         string s1 = s.substr(x - 2, 3);
    //     //         if (s1 == "abc")
    //     //         {
    //     //             res.pb(x - 1);
    //     //             cnt++;
    //     //             ss.insert(x - 1);
    //     //         }
    //     //     }
    //     //     else
    //     //     {
    //     //         if (x - 3 < 0)
    //     //         {
    //     //             cout << cnt << endl;
    //     //             continue;
    //     //         }
    //     //         string s1 = s.substr(x - 3, 3);
    //     //         if (s1 == "abc")
    //     //         {
    //     //             res.pb(x - 1);
    //     //             cnt++;
    //     //             ss.insert(x - 1);
    //     //         }
    //     //     }
    //     // }
    //     // else
    //     // {
    //     //     if (ss.find(x - 1) != ss.end())
    //     //     {
    //     //         cout << cnt << endl;
    //     //         continue;
    //     //         // rr;
    //     //     }
    //     //     if (x - 2 >= 0)
    //     //     {
    //     //         s[x - 1] = y;
    //     //         if (ss.find(x - 2) != ss.end())
    //     //         {
    //     //             cnt--;
    //     //             // cout << cnt << endl;
    //     //             // continue;
    //     //         }
    //     //     }
    //     //     if (x - 3 >= 0)
    //     //     {
    //     //         s[x - 1] = y;
    //     //         if (ss.find(x - 3) != ss.end())
    //     //         {
    //     //             cnt--;
    //     //             // cout << cnt << endl;
    //     //             // continue;
    //     //         }
    //     //     }
    //     //     s[x - 1] = y;
    //     //     string s1 = s.substr(x - 1, 3);
    //     //     if (s1 == "abc")
    //     //     {
    //     //         res.pb(x - 1);
    //     //         cnt++;
    //     //         ss.insert(x - 1);
    //     //     }
    //     // }

    //     // s[x - 1] = y;
    //     // // cout << s << endl;
    //     // cout << ss.size() << endl;
    // }
    // rr;
    set<int> bad;
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s.substr(i, 3) == "abc")
        {
            bad.insert(i);
        }
    }
    while (q--)
    {
        int a;
        char c;
        cin >> a >> c;
        s[a - 1] = c;
        // debug(s);
        for (int i = max(0, a - 3); i <= min(n, a + 1); i++)
        {
            if (s.substr(i, 3) == "abc")
            {
                bad.insert(i);
            }
            else
            {
                bad.erase(i);
            }
        }
        // debug(bad);
        cout << bad.size() << endl;
    }
}

int main()
{
    io();
    // solve();
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

    // cout<<fixed<<setprecision(10)<<ans<<endl;

    // cout<<printf("%.8lf", hi)<<endl;
    return 0;
}