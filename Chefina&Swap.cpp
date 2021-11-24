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

int main()
{
	io();
	ll t;
	cin >> t;

	while (t--)
	{
		ll n;
		cin >> n;

		ll sum = (n * (n + 1)) / 2;

		if (sum % 2)
		{
			cout << 0 << endl;
		}
		else
		{
			ll x = pow(1 + 4 * sum, 0.5);
			x -= 1;
			x /= 2;
			ll ans = n - x;
			ll left = (x * (x + 1)) / 2;
			ll right = sum - left;

			if (left == right)
			{
				ll RElem = n - x;
				ll LSum = (x * (x - 1)) / 2;
				ll RSum = (RElem * (RElem - 1)) / 2;

				ans += LSum + RSum;
			}

			cout << ans << endl;
		}
	}
	return 0;
}