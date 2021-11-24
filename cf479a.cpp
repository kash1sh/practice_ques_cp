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
ll help(ll x, ll y, ll z)
{
	ll a1 = x + y + z;
	ll a2 = x + (y * z);
	ll a3 = x * (y + z);
	ll a4 = x * y * z;
	ll a5 = (x * y) + z;
	ll a6 = (x + y) * z;
	return max(a1, max(a2, max(a3, max(a4, max(a5, a6)))));
}
int main()
{
	io();
	ll x, y, z;
	cin >> x >> y >> z;

	cout << help(x, y, z) << endl;
	return 0;
}