
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
ll binary_Search(vector<ll> &arr, ll key)
{
    ll l = 0, r = arr.size() - 1;
    ll ans;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll value = arr[mid];
        if (value > key)
        {
            r = mid - 1;
        }
        else if (value == key)
        {
            return mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
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

void solve()
{
    // ll n;
    // cin >> n;

    // vector<ll> v(n);
    // vector<ll> v1(n);

    // fo(i, 0, n)
    // {
    //     ll x;
    //     cin >> x;

    //     if (x % 2 == 0)
    //     {
    //         v.pb(x);
    //     }
    //     else
    //         v1.pb(x);
    // }

    // ll a = 0, b = 0;
    // sort(v.begin(), v.end(), greater<int>());
    // sort(v1.begin(), v1.end(), greater<int>());
    // deque<ll> q;
    // deque<ll> q1;

    // for (ll i = 0; i < v.size(); i++)
    // {
    //     q.push_back(v[i]);
    // }
    // for (ll i = 0; i < v1.size(); i++)
    // {
    //     q1.push_back(v1[i]);
    // }
    // ll count = 0;
    // while (q.size() != 0 && q1.size() != 0)
    // {
    //     ll ff = q.front();
    //     q.pop_front();
    //     a += ff;
    //     count++;
    //     if (q.size() == 0)
    //         break;
    //     ll ss = q1.front();
    //     b += ss;

    //     q1.pop_front();
    //     count++;
    // }

    // if (count % 2 == 0)
    // {
    //     while (q1.size())
    //     {
    //         ll ff = q1.back();
    //         q1.pop_back();
    //         if (q1.size() == 0)
    //             break;
    //         ll ss = q1.back();
    //         b += ss;

    //         q1.pop_back();
    //     }
    //     while (q.size())
    //     {
    //         ll ff = q.back();
    //         q1.pop_back();
    //         a += ff;
    //         if (q.size() == 0)
    //             break;
    //         ll ss = q.back();
    //         // b += ss;
    //         q.pop_back();
    //     }
    // }
    // else
    // {
    //     while (q1.size())
    //     {
    //         ll ss = q1.back();
    //         b += ss;
    //         q1.pop_back();
    //         if (q1.size() == 0)
    //             break;
    //         ll ff = q1.back();
    //         q1.pop_back();
    //     }
    //     while (q.size())
    //     {
    //         ll ss = q.back();
    //         // b += ss;
    //         q.pop_back();
    //         if (q.size() == 0)
    //             break;
    //         ll ff = q.back();
    //         q1.pop_back();
    //         a += ff;
    //     }
    // }
    // // cout << a << " " << b << endl;
    // if (a > b)
    // {
    //     cout << "Alice" << endl;
    //     return;
    // }
    // else if (a == b)
    // {
    //     cout << "Tie" << endl;
    //     return;
    // }
    // else
    // {
    //     cout << "Bob" << endl;
    //     return;
    // }
    ll n;
    cin >> n;
    //n++;
    ll a[n];

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    reverse(a, a + n);
    /*for(int i =0; i<n; i++){
  cout<<a[i];
}
 
cout<<endl;*/
    ll sum1 = 0;
    ll sum2 = 0;
    ll count = 0;
    for (int i = 0; i < n; i++)
    {

        if (count % 2 == 0)
        {
            if (a[i] % 2 == 0)
            {
                sum1 += a[i];
            }
            //count^=1;
        }
        else
        {
            if (a[i] % 2 == 1)
            {
                sum2 += a[i];
            }
            // count^=1;
        }

        count++;
    }

    if (sum1 > sum2)
    {
        //return 1;
        cout << "Alice" << endl;
        //cout<<t<<endl;
    }
    else if (sum1 == sum2)
    {
        cout << "Tie" << endl;
        //cout<<t<<endl;
    }
    else
        cout << "Bob" << endl;
}
int main()
{
    io();
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    // cout<<setprecision(10)
    return 0;
}