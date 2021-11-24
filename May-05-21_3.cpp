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

vector<vector<bool>>vis(101, vector<bool>(101, false));
int dXdY[4][2] = {{ -1, 0}, {0, 1}, {1, 0}, {0, -1}};
bool safe(vector<vector<int>> &mat, int n, int i, int j)
{
	for (int ii = 0; ii < 4; ii++)
	{
		int x = i + dXdY[ii][0];
		int y = j + dXdY[ii][1];

		if (x >= 0 && x < n && y >= 0 && y < n && !vis[x][y])

		}
}
void help(vector<vector<int>> &mat, int n, int i, int j)
{
	if (i >= n || j >= n)
		return;
	vis[i][j] = true;
	mat[i][j] = count;




}
int main()
{
	io();
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		if (n == 1)
			cout << 1 << endl;
		if (n == 2)
			cout << -1 << endl;

		int mat[n][n];
		memset(mat, 0, sizeof(mat));
		vector<vector<int>>mat(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				help(mat, n, i, j);
			}
		}
		help(mat, n);
	}
}