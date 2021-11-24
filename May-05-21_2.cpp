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
ll count_digits(ll n)
{

	string num = to_string(n);
	return num.size();
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

		ll num = count_digits(n);
		// cout << "Dig " << num << endl;
		ll count = 0;
		ll multiple = 0;
		for (ll i = 0; i < num; i++)
		{
			// ll multiple = multiple * 10 + 1;
			multiple = multiple * 10 + 1;
			// cout << "MUL " << multiple << endl;
			for (ll j = 1; j <= 9; j++)
			{
				if (n >= multiple * j)
					count++;
				// cout << multiple*j << endl;
			}
		}
		cout << count << endl;
	}
}