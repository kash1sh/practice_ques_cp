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
ll ar[1000001];
vector<ll>v[1000001];

void update(ll n)
{
	// if(v[n].size()==0){
	for (ll i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			v[n].push_back(i);
			ar[i]++;

			if (i * i != n)
			{
				v[n].push_back(n / i);
				ar[n / i]++;
			}
		}
	}

	// }
	// else
	// {
	// 	for(ll d : v[n])
	// 		ar[d]++;
	// }

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
		ll num;
		for (ll i = 0; i <= 1000001; i++)
			ar[i] = 0;
		ll ans = 0;
		for (ll i = 0; i < n; i++)
		{
			cin >> num;
			ans = max(ans, ar[num]);
			update(num);
		}
		cout << ans << endl;
	}
	return 0;

}