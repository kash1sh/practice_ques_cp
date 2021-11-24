#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

bool check_prime(ll n)
{
    if (n == 1)
        return false;

    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
ll is_prime[1000001];
void sieve_Eratosthenes()
{
    ll maxa = 1000000;

    for (ll i = 1; i <= maxa; i++)
    {
        is_prime[i] = 1;
    }
    is_prime[0] = is_prime[1] = 0;

    for (ll i = 2; i * i <= maxa; i++)
    {
        if (is_prime[i])
        {
            for (ll j = i * i; j <= maxa; j = j + i)
            {
                is_prime[j] = 0;
            }
        }
    }
}
// vector<pair<ll, ll>> fact[100000];
vector<pair<ll, ll>> fact;
void primeFact(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n = n / i;
            }
            // cnt is the power of this i;
            fact.push_back({i, cnt});
        }
    }
    if (n > 1)
    {
        fact.push_back({n, 1});
    }
}
ll power(ll a, ll k)
{
    ll res = 1;
    while (k)
    {
        if (k % 2)
        {
            res = (res * a) % mod;
            k--;
        }
        else
        {
            a = (a * a) % mod;
            k /= 2;
        }
    }
    return res % mod;
}
vector<ll> sieve(1000001);
void primeFact_sieve()
{
    ll maxa = 1000001;

    for (ll i = 1; i <= maxa; i++)
        sieve[i] = 0;

    for (ll i = 2; i <= maxa; i++)
    {
        if (sieve[i] == 0)
        {
            for (ll j = i; j <= maxa; j = j + i)
            {
                if (sieve[j] == 0)
                    sieve[j] = i;
            }
        }
    }
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}
int main()
{
    // check if number is prime
    // T.C. -> O(sqrt(n))
    // ll n = 21;
    // if (check_prime(n))
    //     cout << "Yes\n";
    // else
    //     cout << "Not Prime\n";

    // sieve of eratosthenes
    // T.C. -> O(log(logn))
    // sieve();

    // prime factorization
    //  T.C. ->
    // if we run loop from 2 to N, checking if every num divides N, hence finding prime factorization, it will cost
    // a lot of time for prime numbers,for composite, we will enter inside if only 10 times, inside where we will do
    // logn work hence => 10*logn which is fine, but for primes, we will check for every num upto N, as no one will
    // be able to divide N, hence => T.c. -> O(n), so we will optimize
    // instead of running loop upto N, we will run it upto sqrt(n), as it can be proved that there exists atleast one
    // divisor <=sqrt(N), where N is composite => T.C. -> O(sqrt(n)) for primes and O(log(n)) for composites.
    // n = 220;
    // primeFact(n);
    // for (ll i = 0; i < fact.size(); i++)
    // {
    //     cout << fact[i].first << " " << fact[i].second << endl;
    // }
    // cout << endl;

    // Binary Exponentiation coded as Modular Exponentiation
    // T.C. => O(log (n))
    ll a = 2, k = 5;
    cout << power(a, k) << endl;

    // primeFact_sieve();
    // n = 282420;
    // cout << n << endl;
    // while (n)
    // {
    //     cout << sieve[n] << " ";
    //     n = n / sieve[n];
    // }

    // Matrix Exponentiation
    // Simple Multiplication Mrthod, look Video

    // Euclid Algo to Calculate GCD of 2 numbers
    //  gcd(a,b) = if(b==0)=>a else gcd(b,a%b);
    // ll a1, b1;
    // gcd(a1, b1);
}
