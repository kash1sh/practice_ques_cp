
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
string help(string s)
{
    ll curr = 0, maxa = 0;
    ll find = 0;
    // cout << s << endl;
    if (s.size() <= 1)
        return "00";
    for (ll i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            // debug(i);
            // cout << i << endl;
            if (curr % 2 == 0)
            {
                if (curr > maxa)
                {
                    maxa = curr;
                    find = i;
                    // debug(curr);
                    // break;
                }
            }
            curr = 0;
            continue;
        }
        curr++;
    }
    if (maxa == 0)
    {
        if (curr % 2 == 0)
        {
            return s.substr(s.size() - curr, curr);
        }
        return "00";
    }
    return s.substr(find - maxa, maxa);
    // cout << s.substr(i - maxa, maxa) << endl;
    // rr;
}
vector<string> help(string s, string t)
{
    string res;
    int cnt = 0;
    map<string, int> m, m1;

    istringstream ss(t);

    string word; // for storing each word

    while (ss >> word)
    {
        // print the read word
        // cout << word << "\n";
        m[word]++;
    }

    istringstream s1(s);

    string word1; // for storing each word

    while (s1 >> word1)
    {

        m1[word1]++;
    }
    vector<string> ans;

    for (auto i : m1)
    {
        if (m.find(i.first) == m.end())
        {
            ans.push_back(i.first);
        }
    }
    return ans;
}
void solve()
{
    string s, t;
    // cin >> s;
    // getline(cin, s);
    std::getline(std::cin, s);
    std::getline(std::cin, t);
    // cout << s << endl;
    vector<string> ans = help(s, t);
    for (Auto i : ans)
    {
        cout << i << endl;
    }
    // cout << help(s,t) << endl;
    rr;
    // ll curr = 0, maxa = 0;
    // ll find = 0;
    // for (ll i = 0; i < s.size(); i++)
    // {
    //     if (s[i] == ' ')
    //     {
    //         if (curr % 2 == 0)
    //         {
    //             if (curr > maxa)
    //             {
    //                 maxa = curr;
    //                 find = i;
    //                 break;
    //             }
    //         }
    //         curr = 0;
    //         continue;
    //     }
    //     curr++;
    // }
    // if (maxa == 0)
    // {
    //     if (cnt % 2 == 0)
    //     {
    //         return s.substr(n - cnt, cnt);
    //     }
    //     return "";
    // }
    // cout << s.substr(i - maxa, maxa) << endl;
    // rr;
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