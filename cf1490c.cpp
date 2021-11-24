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
map<ll, ll> m;
void big()
{
	ll N = pow(10, 12);
	m.clear();

	for (ll i = 1; i * i * i <= N; i++)
		m[i * i * i] = i;

}
bool check(ll n)
{

	for (auto itr : m)
	{
		ll fir = itr.first;
		ll sec = n - fir;

		// if (find(m.begin(), m.end(), sec) != m.end())
		if (m.find(sec) != m.end())
			return true;
	}
	return false;
}
int main()
{
	io();
	ll t;
	big();
	cin >> t;

	while (t--)
	{
		ll n;
		cin >> n;

		// cout << check(n) << endl;
		if (check(n))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}