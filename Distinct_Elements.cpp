
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
// #define modd(x, mod) (x % mod + mod) % mod
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
// ll MOD = 1e9 + 7;
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
// // const int MAX_CHAR = 256;
// // int countSub(string str)
// // {
// //     // Create an array to store index
// //     // of last
// //     vector<ll> last(100005, -1);

// //     // Length of input string
// //     ll n = str.length();

// //     // dp[i] is going to store count of distinct
// //     // subsequences of length i.
// //     ll dp[n + 1];

// //     // Empty substring has only one subsequence
// //     dp[0] = 1;

// //     // Traverse through all lengths from 1 to n.
// //     for (ll i = 1; i <= n; i++)
// //     {
// //         // Number of subsequences with substring
// //         // str[0..i-1]
// //         dp[i] = (2 * modd(dp[i - 1], mod));

// //         // If current character has appeared
// //         // before, then remove all subsequences
// //         // ending with previous occurrence.
// //         if (last[str[i - 1]] != -1)
// //             dp[i] = (modd(dp[i], mod) - modd(dp[last[str[i - 1]]], mod));
// //         //  % mod;

// //         // Mark occurrence of current character
// //         last[str[i - 1]] = (i - 1);
// //     }

// //     return dp[n] % mod;
// // }
// // int di(string S)
// // {
// // const int N = s.length();
// // const int MOD = 1e9 + 7;

// // vector<int> dp(100005 + 1);
// // dp[0] = 1;
// // vector<int> last(100006, -1);

// // for (int i = 0; i < N; i++)
// // {
// //     int x = s[i] - 'a';
// //     dp[i + 1] = dp[i] * 2 % MOD;
// //     if (last[x] >= 0) // if this is the first occurence of ch
// //         dp[i + 1] -= dp[last[x]];
// //     dp[i + 1] %= MOD;
// //     last[x] = i;
// // }
// // dp[N]--;
// // if (dp[N] < 0)
// //     dp[N] += MOD;
// // return dp[N];
// // ll MOD = 1000000007;
// // // int pre = 1; //The number of subsequences till previous-location. Include empty string: ""
// // // int cur = 1;
// // // int last_count[100005]; //The number of subsequences till now. Include empty string: ""
// // // // int[]last_count = new int[26]; //The number of subsequences that end with a character till now. Not include empty string: ""
// // // for (int i = 0; i < S.length(); ++i)
// // // {
// // //     int charIndex = S[i] - 'a';
// // //     cur = pre * 2 % MOD;          //include-current-character  +  not-include-current-character
// // //     cur -= last_count[charIndex]; //Remove duplicated characters: previous subsequences that end with current character.
// // //     cur = cur >= 0 ? cur % MOD : cur + MOD;
// // //     last_count[charIndex] = pre; //The number of subsequences that end with current character.
// // //     pre = cur;
// // // }
// // // --cur; // remove the empty string: ""
// // // return cur;

// // // }
// // int countSub(vll s, int n)
// // {
// //     map<int, int> Map;

// //     // Iterate from 0 to s.length()
// //     for (int i = 0; i < n; i++)
// //     {
// //         Map[s[i]] = -1;
// //     }

// //     int allCount = 0;
// //     int levelCount = 0;

// //     // Iterate from 0 to s.length()
// //     for (int i = 0; i < n; i++)
// //     {
// //         int c = s[i];

// //         // Check if i equal to 0
// //         if (i == 0)
// //         {
// //             allCount = 1;
// //             Map[s[i]] = 1;
// //             levelCount = 1;
// //             continue;
// //         }

// //         // Replace levelCount withe
// //         // allCount + 1
// //         levelCount = allCount + 1;

// //         // If map is less than 0
// //         if (Map[s[i]] == -1)
// //         {
// //             allCount = allCount + levelCount;
// //         }
// //         else
// //         {
// //             allCount = allCount + levelCount - Map[s[i]];
// //         }
// //         Map[s[i]] = levelCount;
// //     }
// //     // for(auto it:Map)cout<<it.first<<" "<<it.second<<endl;
// //     // Return answer
// //     return allCount;
// // }

// void solve()
// {
//     ll n;
//     cin >> n;
//     vector<ll> a(n);
//     unordered_map<ll, ll> m;
//     // string s;
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> a[i];
//         m[a[i]++];
//         // s += (a[i]);
//     }
//     // cout << str;
//     if (n == 1)
//     {
//         cout << 1 << endl;
//         rr;
//     }
//     unordered_map::iterator i;
//     for (i = m.begin(); i != m.end(); i++)
//     {
//         if (i->second == 1)
//             ans = ans * 2;
//         else
//         {
//             ans = ans * (1 + i->second);
//         }
//         ans %= MOD;
//     }
//     cout << ans - 1 << endl;
//     // ll num = countSub(s, n);
//     // cout << num << endl;
//     rr;
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
//     // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

//     // cout<<fixed<<setprecision(10)<<ans<<endl;

//     // cout<<printf("%.8lf", hi)<<endl;
//     return 0;
// }
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double
#define pii pair<int, int>
#define um unordered_map<int, int>
#define mii map<int, int>
#define vi vector<int>
#define vll vector<long long>
#define pq priority_queue<int>
#define si stack<int>
#define hi cout << "hello" << endl
#define MOD 1000000007
// #define fastio()

// ios_base::sync_with_stdio(false);

// cin.tie(NULL);

// cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define precision(a) cout << setprecision(a) << fixed
#define pb push_back
#define amax(a, b) a = max(a, b)
#define amin(a, b) a = min(a, b)
int main()
{
    // fastio();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        ll ans = 1;
        um h;
        rep(i, 0, n)
        {
            cin >> a[i];
            h[a[i]]++;
        }
        um::iterator i;
        for (i = h.begin(); i != h.end(); i++)
        {
            if (i->second == 1)
                ans = ans * 2;
            else
            {
                ans = ans * (1 + i->second);
            }
            ans %= MOD;
        }
        cout << ans - 1 << endl;
    }
    return 0;
}