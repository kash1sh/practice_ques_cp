
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vint vector<int>
#define vpint vector<pair<int, int>>
#define fo(i, k, n) for (int i = k; i < n; i++)
#define fo1(i, k, n) for (int i = k; i <= n; i++)
#define rr return
#define ff first
#define ss second
#define intmin LONG_MIN
#define intmax LONG_MAX
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
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
void deb(vector<int> v)
{
    for (auto t : v)
        cerr << t << " ";
    cerr << "\n";
}
int mul(int a, int b, int mod)
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
bool check_sorted(vint a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= a[i - 1])
            continue;
        return false;
    }
    return true;
}
vint fact(2e5 + 5, 1);
int binPow(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    int ret = binPow(a, b / 2);
    if (b % 2 == 0)
        return (ret * ret) % mod;
    return ((ret * ret) % mod * a) % mod;
}
int inv(int a)
{
    return (binPow(a, mod - 2) % mod + mod) % mod;
}
int binom(int a, int b)
{
    // before t
    //  for (int i = 1;i<=2e5;i++)fact[i] = (i * fact[i - 1])%mod;
    if (b < 0 or a < 0)
        return 0;
    return (((fact[a] * inv(fact[b])) % mod * inv(fact[a - b])) % mod + mod) % mod;
}
// CONDITION && cout << "YES" || cout << "NO"; cout << '\n';
// int a = count(aint(s),'A');
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
vector<int> factors(int n)
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
bool valid_coordinate(int x, int y, int n, int m)
{
    if (x < 0 || y < 0)
        return false;

    else if (x >= n || y >= m)
        return false;

    else
        return true;
}

int sod(int n)
{
    int sum = 0;
    while (n)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

bool isPowerOfTwo(int n)
{
    return n && (!(n & (n - 1)));
}
// Find Min/Max
// * Greedy/Brute Force
//* Prefix array of max/min
// * BS
// * DP
int count(int n)
{
    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i == n / i)
            {
                cnt++;
                continue;
            }
            cnt += 2;
        }
    }
    return cnt;
}
void solve()
{
    int n;
    cin >> n;
    cout << count(n) << endl;
    rr;
}
const int MAX_N = 1e6;
// max_div[i] contains the largest prime that goes into i
int max_div[MAX_N + 1];
int main()
{
    io();
    // solve();
    // int t=1;
    // int t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    // // cerr << endl <<setprecision(20)<< double( clock() - startTime ) / (double)CLOCKS_PER_SEC<< " seconds." << endl;

    // // cout<<fixed<<setprecision(10)<<ans<<endl;

    // // cout<<printf("%.8lf", hi)<<endl;
    // return 0;
    for (int i = 2; i <= MAX_N; i++)
    {
        if (max_div[i] == 0)
        {
            for (int j = i; j <= MAX_N; j += i)
            {
                max_div[j] = i;
            }
        }
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int div_num = 1;
        while (x != 1)
        {
            /*
			 * get the largest prime that can divide x and see
			 * how many times it goes into x (stored in count)
			 */
            int prime = max_div[x];
            int count = 0;
            while (x % prime == 0)
            {
                count++;
                x /= prime;
            }
            div_num *= count + 1;
        }
        cout << div_num << '\n';
    }
}