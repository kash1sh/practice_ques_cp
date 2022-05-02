
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
// #define Auto auto
// #define llmin LONG_MIN
// #define llmax LONG_MAX
// #define Yes cout << "Yes\n"
// #define No cout << "No\n"
// #define YES cout << "YES\n"
// #define NO cout << "NO\n"
// #define yes cout << "yes\n"
// #define no cout << "no\n"
// #define minus cout << "-1\n"

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
// #define pi 3.141592653589793238
// #ifndef ONLINE_JUDGE
// #define debug(x) cerr << #x << " " << x << endl;
// #else
// #define debug(x)
// #endif
// using namespace std;

// typedef vector<vector<long long>> vvll;

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
// int dx[4] = {-1, 0, 1, 0};
// int dy[4] = {0, 1, 0, -1};
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
// string decToBinary(int n)
// {
//     string s = "";
//     int i = 0;
//     while (n > 0)
//     {
//         s = to_string(n % 2) + s;
//         n = n / 2;
//         i++;
//     }
//     return s;
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
// vector<int> primeFactors(int n)
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

// bool isPrime(ll n)
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
// /*
// vector<ll>adj[100005];
// bool vis[100005];
// ll dist[100005];
// void bfs(ll c)
// {
//   vis[c]=true;
//   dist[c]=0;
//   queue<ll>q;
//   q.push(c);
// while(!q.empty())
// {
//     ll x=q.front();
//     q.pop();

//     for(auto y:adj[x])
//     {
//         if(!vis[y])
//         {
//             vis[y]=true;
//             dist[y]=dist[x]+1;

//             q.push(y);
//         }
//     }

// }
// }
// */
// // Find Min/Max
// // * Greedy/Brute Force
// //* Prefix array of max/min
// // * BS
// // * DP/KNPS
// void rotateRight(vll &a, ll k)
// {
//     k %= a.size();
//     reverse(a.begin(), a.end());
//     reverse(a.begin(), a.begin() + k);
//     reverse(a.begin() + k, a.end());
// }
// void RightRotate(vll &a, int n, int k)
// {

//     // If rotation is greater
//     // than size of array
//     k = k % n;
//     vll v;
//     for (int i = 0; i < n; i++)
//     {
//         if (i < k)
//         {

//             // Printing rightmost
//             // kth elements
//             v.pb(a[n - k + i]);
//             // cout << a[n + i - k] << " ";
//         }
//         else
//         {

//             // Prints array after
//             // 'k' elements
//             cout << (a[i - k]) << " ";
//         }
//     }
//     cout << "\n";
// }
// #define NO_OF_CHARS 256
// void leftRotate(vll &arr, int d, int n)
// {
//     /* To handle if d >= n */
//     d = d % n;
//     int g_c_d = __gcd(d, n);
//     for (int i = 0; i < g_c_d; i++)
//     {
//         /* move i-th values of blocks */
//         int temp = arr[i];
//         int j = i;

//         while (1)
//         {
//             int k = j + d;
//             if (k >= n)
//                 k = k - n;

//             if (k == i)
//                 break;

//             arr[j] = arr[k];
//             j = k;
//         }
//         arr[j] = temp;
//     }
// }
// bool arePermutation(string str1, string str2)
// {
//     // Create 2 count arrays and initialize
//     // all values as 0
//     int count1[NO_OF_CHARS] = {0};
//     int count2[NO_OF_CHARS] = {0};
//     int i;

//     // For each character in input strings,
//     // increment count in the corresponding
//     // count array
//     for (i = 0; str1[i] && str2[i]; i++)
//     {
//         count1[str1[i]]++;
//         count2[str2[i]]++;
//     }

//     // If both strings are of different length.
//     // Removing this condition will make the
//     // program fail for strings like "aaca"
//     // and "aca"
//     if (str1[i] || str2[i])
//         return false;

//     // Compare count arrays
//     for (i = 0; i < NO_OF_CHARS; i++)
//         if (count1[i] != count2[i])
//             return false;

//     return true;
// }

// void solve()
// {
//     ll n;
//     cin >> n;
//     vll a(n);
//     set<ll> s;
//     map<ll, ll> m;
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         m[a[i]]++;
//         s.insert(a[i]);
//     }
//     ll maxa = 0;

//     for (Auto i : m)
//     {
//         if (i.ss > maxa)
//         {
//             maxa = i.ss;
//         }
//     }
//     // debug(maxa);
//     ll val = n / 2;
//     if (maxa > val)
//     {
//         NO;
//         rr;
//     }
//     sort(a.begin(), a.end());
//     vll aa(a);
//     rotateRight(a, maxa);
//     for (ll i = 0; i < n - 1; i++)
//     {
//         for (ll j = i + 1; j < n; j++)
//         {
//             string s1;

//             for (ll k = i; k <= j; k++)
//             {
//                 s1 += to_string(a[k]);
//             }
//             string s2;
//             for (ll k = i; k <= j; k++)
//             {
//                 s2 += to_string(aa[k]);
//             }
//             cout << s1 << " " << s2;
//             if (arePermutation(s1, s2))
//             {
//                 cout << "NO\n";
//                 return;
//             }
//         }
//     }
//     // leftRotate(a, maxa, n);
//     YES;
//     show(aa);
//     show(a);
// }
// int main()
// {
//     io();
//     // solve();
//     ll t = 1;
//     cin >> t;
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
using namespace std;
#define ll long long int
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define llu long long unsigned int
#define ld long double
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll big = 2000000000;
const ll inf = 10000000;
int mx = 1e8;
int mn = -1e8;
ll llmx = 1e15;
ll llmn = -1e15;
const ll mod = 998244353;
// const ll mod=1000000007;
ll limit = 20000001;
const ll N = 200005;
const ld pi = 3.1415926535;
string path;
char dir;
int main()
{
    fast_io;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> ans(n);
        set<ll> s;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            ans[i] = a[i];
            s.insert(a[i]);
        }
        if (s.size() <= 2)
        {
            cout << "NO\n";
            continue;
        }
        map<ll, ll> m;
        for (int i = 0; i < n; i++)
        {
            m[a[i]]++;
        }
        ll maxa = 0;
        for (auto i : m)
        {
            if (i.second > maxa)
            {
                maxa = i.second;
            }
        }
        sort(a.begin(), a.end());
        sort(ans.begin(), ans.end());
        int ch = 0;
        for (int j = 0; j < n; j++)
        {
            rotate(ans.begin(), ans.begin() + maxa, ans.end());
            int fnd = 1;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == ans[i])
                {
                    fnd = 0;
                    break;
                }
            }
            if (fnd == 1)
            {
                ch = 1;
                break;
            }
        }
        if (ch == 0)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
            for (auto x : a)
                cout << x << " ";
            cout << "\n";
            for (auto x : ans)
                cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}