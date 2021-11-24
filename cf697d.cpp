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
vector<pair<ll, ll>>v;
bool comp(pair<ll, ll>v1, pair<ll, ll>v2)
{
	return v1.second < v2.second;
}
ll help(ll n, ll m)
{
	ll sum = 0;
	for (ll i = 0; i < n; i++)
		sum += v[i].first;

	if (sum < m)
		return -1;

	sort(v.begin(), v.end(), comp);
	ll arr[n];
	ll k = 0;
	ll idx = INT_MAX;
	for (ll i = 0; i < n; i++)
	{
		if (v[i].second == 1)
			arr[k++] = v[i].first;
		if (v[i].second == 2)
			idx = i;
	}
	sort(arr, arr + k, greater<ll>());
	ll count = 0;
	for (ll i = 0; i < k; i++)
	{
		if (m > 0)
		{
			m -= arr[i];
			count++;
		}
		else
			return count;
	}
	if (idx == INT_MAX)
		return -1;
	ll a2[n - k];
	ll w = 0;
	for (ll i = idx; i < n; i++)
	{
		a2[w++] = v[i].first;
	}
	for (ll i = 0; i < n - k; i++)
	{
		if (m > 0)
		{
			m -= a2[i];
			count++;
		}
		else
			return count;
	}
	return -1;
}
int main()
{
	ll t;
	cin >> t;

	while (t--)
	{
		ll n, m;
		cin >> n >> m;


		// ll sum = 0;
		v.resize(n);
		for (ll i = 0; i < n; i++)
		{
			cin >> v[i].first;
			// sum += v[i].first;

		}
		for (ll i = 0; i < n; i++)
		{
			cin >> v[i].second;
		}


		cout << help(n, m) << endl;

	}
}