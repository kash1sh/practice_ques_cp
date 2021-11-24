#include <bits/stdc++.h>
using namespace std;
#define ll long long

// vector arr[1000];
vector<ll> sieveOfEratosthenes(ll N)
{
    bool primes[N + 1];
    memset(primes, true, sizeof(primes));
    vector<ll> arr;

    for (ll i = 2; i * i <= N; i++)
        if (primes[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
                primes[j] = false;
        }

    for (ll i = 2; i <= N; i++)
        if (primes[i])
            arr.emplace_back(i);

    return arr;
}

int main()
{
    ll N = 200;
    vector<ll> arr = sieveOfEratosthenes(N);
    for (auto i : arr)
        cout << i << " ";
}