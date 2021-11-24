#include<bits/stdc++.h>
using namespace std;
int maximizeTheCuts(int n, int x, int y, int z)
{
	int a[3];
	a[0] = x, a[1] = y, a[2] = z;
	int dp[4][n + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 0; i <= 3; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0) {
				dp[i][j] = INT_MIN ;
			}
			else if (j == 0) {
				dp[i][j] = 0;
			}
		}
	}

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i - 1] <= j) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - a[i - 1]] + 1);
			} else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[3][n] < 0 ? 0 : dp[3][n];
}
int main()
{
	int n;
	cin >> n;
	int x, y, z;
	cin >> x, y, z;
	cout << maximizeTheCuts(n, x, y, z);
}