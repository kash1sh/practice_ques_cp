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

	ll a1[n];
	ll a2[n - 1];
	ll a3[n - 2];
	// map<ll, ll>m;
	ll sum1 = 0, sum2 = 0, sum3 = 0;
	loop(i, n)
	{
		cin >> a1[i];
		// m[a1[i]]++;
		sum1 += a1[i];
	}
	loop(i, n - 1)
	{
		cin >> a2[i];
		// m[a2[i]]++;
		sum2 += a2[i];
	}
	loop(i, n - 2)
	{
		cin >> a3[i];
		// m[a3[i]]++;
		sum3 += a3[i];
	}


	cout << sum1 - sum2 << endl << sum2 - sum3 << endl;
	return 0;
}