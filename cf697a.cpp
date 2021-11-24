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

	ll t;
	cin >> t;

	while (t--)
	{
		ll n;
		cin >> n;
		// cout << n << endl;
		ll nn = n;
		bool flag = true;
		while (n % 2 == 0) {
			n /= 2;
		}

		// if (n % 2 == 1)
		// {
		// 	cout << "YES" << endl;
		// }
		if (n == 1)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
		// else
		// {

	}

	// }
	return 0;
}