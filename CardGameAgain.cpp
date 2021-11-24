#include<bits/stdc++.h>
#define ll 				long long
#define pb 				push_back
#define loop(i,n) 		for(ll i=0;i<n;i++)
#define loop1(i,n) 		for(ll i=1;i<=n;i++)
#define mod 			1000000007

#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)

using namespace std;
void primeFactori(ll k)
{
	for (ll i = 2; i * i <= k; i++)
	{
		cnt = 0;
		while (kk % i == 0)
		{
			kk = kk / i;
			cnt++;
		}
	}
}
void io()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

vector<pair<ll, ll>>kprime;
vector<pair<ll, ll>>copy;
int main()
{
	io();

	ll n, k;
	cin >> n >> k;

	ll arr[n + 1];
	ll kk = 0;

	for (ll i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	kk = k;
	ll cnt = 0;
	for (ll i = 2; i * i <= k; i++)
	{
		cnt = 0;
		while (kk % i == 0)
		{
			kk = kk / i;
			cnt++;
		}

		if (cnt != 0)
			kprime.pb({i, cnt});
		// kprime[i] = cnt;
	}
	if (k > 1)
		kprime.pb({k, 1});

	for (ll i = 0; i < kprime.size(); i++)
	{
		copy.first = kprime.first;
		copy.second = 0;
	}



	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			kk = arr[j];
			for (ll i = 2; i * i <= arr[j]; i++)
			{
				cnt = 0;
				while (kk % i == 0)
				{
					kk = kk / i;
					cnt++;
				}
				if (cnt != 0)
				{
					if (find(copy.first.begin(), copy.first.end(), i) != copy.first.end())
						copy

					}
			}
		}
	}

}

return 0;
}