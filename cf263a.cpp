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
	int mat[5][5];
	ll x = 0, y = 0;
	loop(i, 5)
	{
		loop(j, 5)
		{
			cin >> mat[i][j];
			if (mat[i][j] == 1)
			{
				x = i;
				y = j;
			}
		}

	}

	cout << (abs(x - 2) + abs(y - 2)) << endl;

	return 0;

}