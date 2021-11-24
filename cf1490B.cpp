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

ll help(ll arr[100000], ll n, ll c0, ll c1, ll c2)
{
	if (c1 == c2 && c2 == c0)
		return 0;
	ll count = 0;
	ll b = n / 3;
	for (int i = 0; i < 2; i++)
	{
		if (c0 > b)
		{
			count += c0 - b;
			c1 += c0 - b;
			c0 = b;
		}
		if (c1 > b)
		{
			count += c1 - b;
			c2 += c1 - b;
			c1 = b;
		}
		if (c2 > b)
		{
			count += c2 - b;
			c0 += c2 - b;
			c2 = b;
		}
	}
	return count;
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

		ll arr[100000];
		ll c0 = 0, c1 = 0, c2 = 0;
		for (ll i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (arr[i] % 3 == 0)
				c0++;
			else if (arr[i] % 3 == 1)
				c1++;
			else
				c2++;
		}
		cout << help(arr, n, c0, c1, c2) << endl;


	}
	return 0;
}