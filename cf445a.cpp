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
char mat[101][101];
#define mod 1000000007
bool flagB = false;
bool flagW = false;
bool flagE = false;
void help(ll i, ll j, ll n, ll m)
{

	if (mat[i][j] == '-')
		return;

	int dXdY[4][2] = {{ -1, 0}, {0, 1}, {1, 0}, {0, -1}};

	if (mat[i][j] == '.')
	{
		for (ll ii = 0; ii < 4; ii++)
		{
			ll x = i + dXdY[ii][0];
			ll y = j + dXdY[ii][1];
			if (x >= 0 && x < n && y >= 0 && y < m)
			{
				if (mat[x][y] == 'B')
					mat[i][j] = 'W';
				else if (mat[x][y] == 'W')
					mat[i][j] = 'B';

			}
			if (mat[i][j] == '.')
				mat[i][j] = 'B';
		}

	}


}
int main()
{
	io();
	ll n, m;
	cin >> n >> m;

	// ll mat[n][m];

	for (ll i = 0; i < n; i++)
	{
		loop(j, m)
		{
			cin >> mat[i][j];
		}
	}

	loop(i, n)
	{
		loop(j, m)
		help(i, j, n, m);
	}

	loop(i, n)
	{
		loop(j, m)
		cout << mat[i][j] << " ";
		cout << endl;
	}
	return 0;
}