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
	ll arr[n];

	map<ll, ll>m;
	for (ll i = 0; i < n; i++)
	{
		cin >> arr[i];
		m[arr[i]]++;
	}

	ll mini = INT_MAX, maxa = INT_MIN;
	ll minI = 0, maxI = 0;

	loop(i, n)
	{
		if (arr[i] > maxa)
		{
			maxa = arr[i];
			maxI = i;
		}
		if (arr[i] < mini)
		{
			mini = arr[i];
			minI = i;
		}
	}

	ll a1 = maxa - mini;
	ll a2 = 0;
	if (m[maxa] == n)
		a2 = (n * (n - 1)) >> 1;
	else
		a2 = m[maxa] * m[mini];

	cout << a1 << " " << a2 << endl;
	return 0;

}