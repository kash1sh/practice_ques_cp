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

int main()
{
	io();

	ll t;
	cin >> t;

	while (t--)
	{
		ll ch, ri;
		cin >> ch >> ri;

		double ccd = ((double)ch / 9);
		ll cd = ceil(ccd);

		// cout << "Chef Dig " << cd << endl;
		double rrd = ((double)ri / 9);
		// cout << "RRD " << rrd << endl;
		ll rd = ceil(rrd) ;
		// cout << "Rick Dig " << rd << endl;
		// if (ch <= 9)
		// {
		// 	cd = 1;
		// }
		// if (ri <= 9)
		// {
		// 	rd = 1;
		// }
		if (rd <= cd)
			cout << 1 << " " << rd << endl;
		else
			cout << 0 << " " << cd << endl;
	}
	return 0;
}