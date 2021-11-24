
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

bool help(ll n)
{
    if (n % 2021 == 0)
        return true;
    return false;
}
bool solve(ll n)
{
    //  bool flag = true;
    for (ll i = 0; i <= 1000; i++)
    {
        ll firs = 2020 * i;
        ll seco = n - firs;
        if (seco < 0)
        {
            return false;
        }
        if (help(seco))
        {
            return true;
            // flag=false;
        }
    }
    return false;
}
int main()
{
    io();
    ll t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        //    solve(n);
        if (solve(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}