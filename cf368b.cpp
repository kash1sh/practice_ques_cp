#include<bits/stdc++.h>
#define ll 				long long
#define pb 				push_back
#define loop(i,n) 		for(ll i=0;i<n;i++)
#define loop1(i,n) 		for(ll i=1;i<=n;i++)

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

int main()
{
	io();

	ll n, m;
	cin >> n >> m;

	ll arr[n];
	loop(i, n)
	cin >> arr[i];

	// map<ll,ll>m;
	// ll count[n];
	set<ll>s;
	ll res[n];
	for (ll i = n - 1; i >= 0; i--)
	{
		s.insert(arr[i]);
		res[i] = s.size();
	}
	// loop(i,n)
	// {/
	// map[arr[i]]++;
	// count[i]++;
	// }

	loop(i, m)
	{
		ll val;
		cin >> val;

		cout << res[val - 1] << endl;
	}
	return 0;
}