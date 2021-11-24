#include<bits/stdc++.h>
#define ll 				long long
#define pb 				push_back
#define loop(i,n) 		for(ll i=0;i<n;i++)
#define loop1(i,n) 		for(ll i=1;i<=n;i++)
#define mod 			1000000007

#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)

using namespace std;

void io()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}
vector<int> sieveOfEratosthenes(int N)
{
	bool primes[N + 1];
	memset(primes, true, sizeof(primes));
	vector<int> arr;

	for (int i = 2; i * i <= N; i++)
		if (primes[i] == true)
		{	for (int j = i * i; j <= N; j += i)
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
	if (n < 2020)
		return false;
	ll nn = n;

	// for (ll i = 0; i < 500; i++)
	// {
	// 	for (ll j = 0; j < 500; j++)
	// 	{
	// 		// cout << 2020 * i + 2021 * j << endl;
	// 		ll check = 2020 * i + 2021 * j;
	// 		if (n == check)
	// 			return true;
	// 	}

	// }
	// return false;

	// ll rem = n/2021;



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
		if (help(n))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}