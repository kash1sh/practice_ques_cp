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

int main()
{
	io();

	ll n;
	cin >> n;
	map<ll, ll>m;
	// ll arr[4] = {0};
	loop(i, n)
	{
		ll x;
		cin >> x;
		m[x]++;
		// arr[x]++;
	}

	// loop(i, 5)
	// cout << arr[i] << " ";
	// for (auto itr : m)
	// cout << itr.first << " " << itr.second << endl;

	ll count = 0;

	while (m[1] > 0 && m[3] > 0)
	{
		count++;
		m[1]--;
		m[3]--;
	}
	while (m[2] > 1)
	{
		count++;
		m[2] = m[2] - 2;
	}
	while (m[4] > 0)
	{
		count++;
		m[4]--;
	}

	if (m[2] == 1)
	{
		if (m[1] == 1)
		{
			m[1] = m[1] - 1;
			m[2]--;
			count++;
		}

		else if (m[1] >= 2)
		{
			m[1] = m[1] - 2;
			m[2]--;
			count++;
		}

		else if (m[1] == 0)
		{
			m[2]--;
			count++;
		}

	}


	while (m[3] > 0)
	{
		m[3]--;
		count++;
	}
	count +=	ceil(m[1] / 4.0);
	// while (m[1] > 0)
	// {

	// 	count += m[1] / 4;
	// 	m[1] -=  4 * (m[1] / 4.0);
	// 	if (m[1] % 4 == 0)
	// 		count += m[1];
	// }

	cout << count << endl;
	return 0;
}