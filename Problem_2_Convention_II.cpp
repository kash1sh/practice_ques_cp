
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

// void solve()
// {
//     ll n;
//     cin >> n;

//     vector<pair<ll, ll>, ll> a;
//     multiset<pair<ll, ll>, ll> s;
//     for (ll i = 0; i < n; i++)
//     {
//         cin >> v[i].ff.ff >> v[i].ff.ss;
//         v[i].ss = i + 1;
//         pair<ll, ll> p = {v[i].ff.ff, v[i].ff.ss};
//         s.insert({p, v[i].ss})
//     }
//     vll wt(n, 0);
//     ll time = 0;
//     for (ll i = 0; i < n; i++)
//     {
//         // pai
//         auto it = s.begin();

//         pair<ll, ll> p = *(it.ff);
//         ll sen = *(it.ss);
//         s.erase(s.begin());
//         // ll fin;

//         if (time == 0)
//         {
//             time = p.ff + p.ss;
//         }
//         else
//         {
//             wt[sen] = time - p.ff;
//             time = time + p.ss;
//         }
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
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    int n;
    vector<vector<int>> cows;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int start, duration;
        cin >> start >> duration;
        cows.push_back({i, start, duration});
    }
    // sort by arrival time.
    sort(cows.begin(), cows.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[1] < b[1]; });

    int time = 0, cur = 0, ans = 0;

    // sorted by priority so that the highest seniority starts eating first
    set<vector<int>> waiting;
    // as long as we haven't processed all cows or there are still cows waiting
    while (cur < n)
    {
        // this cow can be processed.
        if (cur < n && cows[cur][1] <= time)
        {
            waiting.insert(cows[cur]);
            cur++;
            // no cow waiting, skip to the next cow.
        }
        else if (waiting.size() == 0)
        {
            // set time to the ending time of the next cow.
            time = cows[cur][1] + cows[cur][2];
            cur++;
        }
        else
        {
            // process the next cow
            vector<int> next = *waiting.begin();
            ans = max(ans, time - next[1]);

            // set the time to when this cow finishes.
            time += next[2];
            waiting.erase(waiting.begin());
        }
    }
    cout << ans << '\n';
}