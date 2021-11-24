
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
bool comp(const pair<int, int> &a,
          const pair<int, int> &b)
{
    return (a.second > b.second);
}
void solve()
{
    ll mini, s, n;
    cin >> mini >> s >> n;

    ll arr[s];

    for (ll i = 0; i < s; i++)
        cin >> arr[i];

    // for (ll i = 0; i < s; i++)
    // cout << arr[i] << " ";
    cout << endl;
    vector<pair<ll, ll>> v(n);
    map<pair<ll, ll>, ll> m;

    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].ff;
        cin >> v[i].ss;
        pair<ll, ll> p = {v[i].ff, v[i].ss};
        m[p] = i + 1;
    }
    sort(v.begin(), v.end(), comp);
    // ll vis[1001] = {0};
    for (ll k = 0; k < 1000; k++)
    {
        for (ll i = 0; i < n - 1; i++)
        {
            // if(vis[v[i].ss]==0)
            // vis[v[i].ss]=
            if (v[i + 1].ss == v[i].ss)
            {
                float ratio1 = (float)((float)v[i].ff / (float)v[i].ss);
                float ratio2 = (float)((float)v[i + 1].ff / (float)v[i + 1].ss);
                // cout << ratio1 << " " << ratio2 << endl;

                if (ratio1 > ratio2)
                {
                    swap(v[i + 1], v[i]);
                }
            }
        }
    }

    // for (ll i = 0; i < n; i++)
    // {
    // cout << v[i].ff << " " << v[i].ss << endl;

    // }

    vll ans(n);
    vector<vector<ll>> res;
    bool flag = false;
    for (ll i = 0; i < s; i++)
    {
        ans.clear();
        ll score = arr[i];
        if (score >= mini)
        {
            // ans.pb(1);
            continue;
        }

        for (ll j = 0; j < n; j++)
        {

            score += v[j].ff;
            // cout << score << " ";
            pair<ll, ll> p = {v[j].ff, v[j].ss};
            ans.pb(m[p]);
            if (score >= mini)
            {
                res.pb(ans);
                break;
            }
        }
    }
    for (auto i : res)
    {
        if (i.size())
        {
            sort(i.begin(), i.end());
            cout << i.size() << " ";
            for (ll j = 0; j < i.size(); j++)
            {
                cout << i[j] << " ";
            }
        }
        else
        {
            cout << 0;
        }
        cout << endl;
    }
    return;
}
int main()
{
    io();
    // ll t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }

    // cout<<setprecision(10)
    return 0;
}