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

	ll t;
	cin >> t;

	while (t--)
	{
		ll n;
		cin >> n;

		ll arr[51];

		for (ll i = 0; i < n; i++)
			cin >> arr[i];
		ll count = 0;
		for (ll i = 0; i < n - 1; i++)
		{
			float maxa = max(arr[i], arr[i + 1]);
			ll mini = min(arr[i], arr[i + 1]);

			float div = (float)((float)maxa / (float) mini);
			// cout << div << endl;
			if (div > 2)
			{
				while ((float)div > 2)
				{
					// cout << maxa << endl;
					maxa /= 2;
					// cout << maxa << endl;
					count++;

					// div =  (maxa / mini);
					div = (float)(maxa / (float) mini);
					// cout << div << endl;
				}
			}
		}

		cout << count << endl;
	}
	return 0;
}