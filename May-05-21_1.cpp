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

bool help(int n, string s)
{
	unordered_map<char, int>m;
	m[s[0]] = 1;
	for (int i = 1; i < n; i++)
	{
		// m[s[i]]++;
		if (m[s[i]] == 0)
		{
			m[s[i]] = 1;
		}
		else if (m[s[i]] == 1 && s[i - 1] != s[i])
		{
			return false;
		}
	}
	return true;
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
		string s;
		cin >> s;

		if (help(n, s))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}