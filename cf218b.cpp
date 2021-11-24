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
	ll n, pp;
	cin >> n >> pp;

	ll a1[pp];
	// ll a2[p];

	priority_queue<ll>p;
	priority_queue<ll, vector<ll>, greater<ll>>q;
	for (ll i = 0; i < pp; i++)
	{

		cin >> a1[i];
		// a2[i]=a1[i];
		p.push(a1[i]);
		q.push(a1[i]);
	}

	ll mini = 0, maxa = 0;
	for (ll i = 0; i < n; i++)
	{
		ll front = p.top();
		p.pop();
		mini += front;
		front--;
		// if (front > 0)
		p.push(front);

	}

	for (ll i = 0; i < n; i++)
	{
		ll front = q.top();
		q.pop();
		maxa += front;
		front--;
		if (front > 0)
			q.push(front);
		// q.push(front);
	}
	cout << mini << " " << maxa << endl;
	return 0;
}