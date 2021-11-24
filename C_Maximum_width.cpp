
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)
#define ff first
#define ss second
#define rr return
#define Endl endl

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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    // vector<int> position_left(m);
    // int pos = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (pos == m)
    //         break;
    //     if (s[i] == t[pos])
    //     {
    //         position_left[pos] = i;
    //         pos++;
    //     }
    // }
    // vector<int> position_right(m);
    // pos = m - 1;
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     if (pos == -1)
    //         break;
    //     if (s[i] == t[pos])
    //     {
    //         position_right[pos] = i;
    //         pos--;
    //     }
    // }
    // int ans = 0;
    // for (int i = 0; i < m - 1; i++)
    // {
    //     ans = max(ans, position_right[i + 1] - position_left[i]);
    // }
    // cout << ans << endl;
    // map<char, ll> m1;
    // map<char, ll> m2;

    // for (ll i = 0; i < n; i++)
    // {
    //     m1[s[i]] = i;
    // }
    // for (ll i = n - 1; i >= 0; i--)
    // {
    //     m2[s[i]] = i;
    // }
    vll left(m), right(m);
    ll j = 0;
    for (ll i = 0; i < n; i++)
    {
        if (s[i] == t[j])
        {
            left[j] = i;
            j++;
        }
    }
    j = m - 1;
    for (ll i = n - 1; i >= 0; i--)
    {
        if (s[i] == t[j])
        {
            right[j] = i;
            j--;
        }
    }
    ll maxa = INT_MIN;
    for (ll i = 0; i < m - 1; i++)
    {
        maxa = max(maxa, right[i + 1] - left[i]);
    }
    // for (auto i : m1)
    // {
    //     cout << i.ff << " " << i.ss << endl;
    // }
    // for (auto i : m2)
    // {
    //     cout << i.ff << " " << i.ss << endl;
    // }
    // for (auto i : m1)
    // {
    //     ll v1 = i.ss - m2[i.ff];
    //     maxa = max(maxa, v1);
    // }
    // set<char, ll> se;
    // for (ll i = 0; i < m - 1; i++)
    // {
    //     // ll v1 = m1[t[i + 1]] - m1[t[i]];
    //     ll v2 = m1[t[i + 1]] - m2[t[i]];
    //     // ll v3 = m2[t[i + 1]] - m2[t[i]];
    //     // ll v4 = m1[t[i + 1]] - m2[t[i]];
    //     // ll val = max(v1, max(v2, max(v3, v4)));
    //     maxa = max(maxa, v2);
    //     // maxa = max()
    // }
    cout << maxa << endl;
    rr;
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