#include<bits/stdc++.h>
#define ll 				long long
#define pb 				push_back
#define loop(i,n) 		for(ll i=0;i<n;i++)
#define loop1(i,n) 		for(ll i=1;i<=n;i++)
#define fir				first
#define sec				second

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
	ll t;
	cin >> t;

	while (t--)
	{
		ll n;
		cin >> n;

		ll arr[n];
		map<ll, ll>m;
		for (ll i = 0; i < n; i++)
		{
			cin >> arr[i];

			m[arr[i]]++;
		}
		ll countA = 0, countB = 0;
		for (auto itr : m)
		{
			if (itr.sec == 1)
			{
				countA++;
			}
			else {
				countB = itr.sec;
			}

		}

		cout << min(countB, countA) << endl;
	}
}