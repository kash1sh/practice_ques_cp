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
#define mod 1000000007

int main()
{
	io();
	ll n;
	cin >> n;
	// n++;
	ll count = n + 1;
	ll sum = 0;
	loop(i, n)
	{
		ll x;
		cin >> x;
		sum += x;
		if (sum > count)
		{
			sum = sum % count;
		}
	}
	// cout << sum << endl;
	ll ans = 0;
	// ll semi=0;
	for (int i = 1; i <= 5; i++)
	{
		ll semi = (sum + i) % count;
		// cout << sum << endl;
		if (semi != 1)
			ans++;
	}

	cout << ans << endl;

	return 0;
}