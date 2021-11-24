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
	ll t;
	cin >> t;

	while (t--)
	{
		ll n;
		cin >> n;

		ll arr[n];

		for (ll i = 0; i < n; i++)
			cin >> arr[i];

		ll s1 = 0, s2 = 0;
		ll up = 0;
		for (ll i = 0; i < n; i++)
		{
			if (arr[i] == 1)
			{
				up++;
				s1++;
			}
			else if (arr[i] == 2)
			{
				s2--;
			}
			else
			{
				if (s2 <= 0)
				{
					s2++;
					up++;
				}
			}
		}

		cout << up << endl;
	}
}