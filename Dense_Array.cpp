#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define fo(i, n) for (ll i = 0; i < n; i++)
#define fo1(i, n) for (ll i = 1; i <= n; i++)
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

int main()
{
	io();
	ll t;
	cin >> t;

	while (t--)
	{
		ll n;
		cin >> n;

		ll arr[n];

		fo(i, n)
		{
			cin >> arr[i];
		}
		ll cnt = 0;
		for (ll i = 1; i < n; i++)
		{
			ll maxa = max(arr[i], arr[i - 1]);
			ll mini = min(arr[i], arr[i - 1]);

			while (maxa > 2 * mini)
			{
				cnt++;
				mini = 2 * mini;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}