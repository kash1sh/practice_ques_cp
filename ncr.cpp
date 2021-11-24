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
int dp[1001][801];
int help(int n, int r)
{
	if (r > n)
		return 0;
	if (dp[n][r] != -1)
		return dp[n][r] % mod;
	if (r == 0 || r == n)
	{
		dp[n][r] = 1;
		return 1;
	}
	// if(r==1 || r==n-1)
	// {
	//     dp[n][r]=n;
	//     return n;
	// }

	dp[n][r] = (help(n - 1, r - 1) % mod + help(n - 1, r) % mod) % mod;
	return dp[n][r] % mod;
}
int nCr(int n, int r) {
	// code here
	memset(dp, -1 , sizeof(dp));
	return help(n, r);
}
int main()
{
	io();
	int n, r;
	cin >> n >> r;
	cout << nCr(n, r) << endl;
}