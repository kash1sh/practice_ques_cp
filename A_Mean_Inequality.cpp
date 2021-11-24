
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
// int L = 1;
// int R = n;
// int res = 0;

// while (L <= R)
// {
//     int mid = (L + R) / 2;

//     if (isValid(mid))
//         L = mid + 1, res = max(res, mid);
//     else
//         R = mid - 1;
// }

// return res;
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
    ll n;
    cin >> n;
    ll nn = n;
    n = 2 * n;

    vll a(n);
    vll a1(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        a1[i] = a[i];
    }
    sort(a.begin(), a.end());

    sort(a1.begin(), a1.end(), greater<ll>());
    // for (ll i = 0; i < n; i++)
    //     cout << a1[i] << " ";
    vll a2(n, 0);
    // ll j = 0;

    // ll k = n - i;
    ll j = 0, k = 0;
    for (ll i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            a2[i] = a[j++];
        }
        else
        {
            a2[i] = a1[k++];
        }
    }
    // }
    // for (ll i = 1; i < n; i = i + 2)
    // {
    //     ll k = n - j - 1;
    //     // j = j + 1;
    //     a2[i] = a[i];
    //     if (a2[i - 1] == 0)
    //     {
    //         a2[i - 1] = a[k];
    //         j++;
    //     }
    //     k = n - j - 1;
    //     if (a2[i + 1] == 0)
    //     {
    //         a2[i + 1] = a[k--];
    //         j++;
    //     }
    // }
    // for (ll i = 1; i < nn; i = i + 2)
    // {
    //     a2[i] = a[i];
    //     if (i == 1)
    //     {
    //         a2[i - 1] = a[nn + j];
    //         j++;
    //     }

    //     // j++;
    //     if (i != nn - 1)
    //         a2[i + 1] = a[nn + j];
    //     j++;
    // }
    // ll k = 0;
    // for (ll i = nn; i < n; i = i + 2)
    // {
    //     a2[i] = a[i];

    //     // if (i != nn)
    //     // {
    //     //     a2[i - 1] = a[k++];
    //     // }

    //     a2[i + 1] = a[k++];
    // }

    // cout << endl;
    for (ll i = 0; i < n; i++)
        cout << a2[i] << " ";
    cout << endl;
    // bool flag = false;
    // do
    // {
    //     flag = false;
    //     if (a[0] == (a[1] + a[n - 1]) / 2)
    //     {
    //         flag = true;
    //         // break;
    //     }
    //     for (ll i = 1; i < n - 1; i++)
    //     {
    //         if (a[i] == (a[i - 1] + a[i + 1]) / 2)
    //         {
    //             flag = true;
    //             break;
    //         }
    //     }

    //     if (a[n - 1] == (a[n - 2] + a[0]) / 2)
    //         flag = true;

    //     if (flag == false)
    //     {
    //         for (ll i = 0; i < n; i++)
    //             cout << a[i] << " ";
    //         break;
    //     }
    // } while (next_permutation(a.begin(), a.end()));
    // cout << endl;
    // return;
}
int main()
{
    io();
    // solve();

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    // cout<<setprecision(10)
    return 0;
}