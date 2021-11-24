
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define fir first
#define sec second

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
int mod = 1e9 + 7, mxn = 3e5 + 5;

int add(int a, int b, int mod)
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

int mul(int a, int b, int mod)
{
    a %= mod;
    b %= mod;
    a *= b;
    a += mod;
    return a % mod;
}
int po(int a, int b, int mod)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return po(mul(a, a, mod), b / 2, mod);
    return mul(a, po(mul(a, a, mod), (b - 1) / 2, mod), mod);
}

int fact[200003];
int inv[200003];

void fact0()
{
    int i, j;
    fact[0] = 1;
    for (i = 1; i <= 200000; i++)
    {
        fact[i] = i * fact[i - 1] % mod;
    }
    inv[0] = 1;
    inv[1] = 1;
    int p = mod;
    for (i = 2; i <= 200000; i++)
        inv[i] = (p - (p / i) * inv[p % i] % p) % p;

    for (i = 2; i <= 200000; i++)
    {
        inv[i] *= inv[i - 1];
        inv[i] %= mod;
    }
}
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

vector<ll> ans;
// map<ll, ll> m;
// void all()
// {
//     for (ll i = 1; i <= 1e6; i++)
//     {
//         ll num = i;
//         bool visited[10] = {false};

// while (num)
// {

//     if (visited[num % 10])
//         break;

//     visited[num % 10] = true;

//     num = num / 10;
// }
// if (num == 0)
//     m[i]++;
//         // ans.pb(i);
//     }

//     // for (ll i = 1; i <= 1e7; i++)
//     // {

//     //     // Convert the no. to
//     //     // string
//     //     string s = to_string(i);

//     //     // Convert string to set using stl
//     //     set<ll> uniDigits(s.begin(), s.end());

//     //     // Output if condition satisfies
//     //     if (s.size() == uniDigits.size())
//     //     {
//     //         ans.pb(i);
//     //     }
//     // }
// }
// ll getSum(ll n)
// {
//     ll sum;

//     /* Single line that calculates sum */
//     for (sum = 0; n > 0; sum += n % 10, n /= 10)
//         ;

//     return sum;
// }
// ll help(ll n)
// {

//     // ll as[51] = {-1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 19, 29, 39, 49, 59, 69, 79, 89, 189, 289, 389, 489, 589, 689, 789, 1789};
//     // if (n <= 25)
//     // return as[n];
//     for (ll i = 1; i <= 1e6; i++)
//     {
//         // if (find(ans.begin(), ans.end(), i) != ans.end())
//         if (m[i] != 0)
//         {
//             ll sum = getSum(i);
//             if (sum == n)
//                 return i;
//         }
//     }

//     return -1;
// }
int main()
{
    io();
    ll t;
    // all();
    cin >> t;
    while (t--)
    {
        ll n;
        ans.clear();
        cin >> n;
        if (n > 45)
            cout << -1 << endl;
        else
        {
            for (int i = 9; i > 0; i--)
            {
                if (n >= i)
                {
                    ans.pb(i);
                    n -= i;
                }
            }
            sort(ans.begin(), ans.end());

            fo(i, 0, ans.size())
                    cout
                << ans[i];
            cout << endl;
        }
        // cout << help(n) << endl;
    }
    return 0;
}