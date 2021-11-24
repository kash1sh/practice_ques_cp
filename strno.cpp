#include<bits/stdc++.h>
#define ll 				long long
#define pb 				push_back
#define loop(i,n) 		for(ll i=0;i<n;i++)
#define loop1(i,n) 		for(ll i=1;i<=n;i++)
#define mod 1000000007

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
ll fact(ll x)
{
	ll count = 0;

	for (ll i = 2; i * i <= x; i++)
	{
		while (x % i == 0)
		{
			// 		// while(x/i){
			count++;
			x = x / i;
			// 		// }

		}
	}
	// if(x>1)
	count++;
	return count;
}
int main()
{
	io();
	ll t;

	cin >> t;

	while (t--)
	{
		ll x, a;
		cin >> x >> a;
// cout<<"Chal kya raha"<<endl;
		ll primes = fact(x);
		// ll primes=3;
		if (primes >= a)
		{
			cout << 1 << endl;
		}
		else
			cout << 0 << endl;
	}
	return 0;
}