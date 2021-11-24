// // #include<iostream>
// // #include<vector>
// // #include<cstring>
// // #include<algorithm>
// // #define ll 				long long
// // #define pb 				push_back
// // #define loop(i,n) 		for(ll i=0;i<n;i++)
// // #define loop1(i,n) 		for(ll i=1;i<=n;i++)
// // #define mod 1000000007

// // #define setbits(x)      __builtin_popcountll(x)
// // #define zrobits(x)      __builtin_ctzll(x)

// // using namespace std;

// // void io()
// // {
// // 	ios::sync_with_stdio(false);
// // 	cin.tie(0);
// // #ifndef ONLINE_JUDGE
// // 	freopen("input.txt", "r", stdin);
// // 	freopen("output.txt", "w", stdout);
// // #endif
// // }

// // bool prime[201];
// // vector<ll>v;
// // void sieve()
// // {

// // 	memset(prime, true, sizeof(prime));
// // 	prime[0] = false;
// // 	prime[1] = false;
// // 	for (ll p = 2; p * p <= 200; p++)
// // 	{

// // 		if (prime[p] == true)
// // 		{

// // 			for (ll i = p * p; i <= 200; i += p)
// // 				prime[i] = false;
// // 		}
// // 	}

// // }
// // int main()
// // {
// // 	io();
// // 	ll t;
// // 	cin >> t;

// // 	while (t--)
// // 	{
// // 		ll n;
// // 		cin >> n;

// // 		sieve();

// // 		for (ll i = 2; i < 200; i++)
// // 		{
// // 			if (prime[i] == true)
// // 			{
// // 				for (ll j = i + 1; j < 200; j++)
// // 				{
// // 					if (prime[j] == true)
// // 						v.pb(i * j);
// // 				}
// // 			}
// // 		}

// // 		vector<ll>sum;

// // 		for (ll i = 0; i < v.size(); i++)
// // 		{
// // 			for (ll j = 0; j < v.size(); j++)
// // 			{
// // 				sum.pb(i + j);
// // 			}
// // 		}

// // 		if (find(sum.begin(), sum.end(), n) != sum.end())
// // 		{
// // 			cout << "YES" << endl;
// // 		}
// // 		else
// // 			cout << "NO" << endl;
// // // 		bool flag = false;
// // // 		if (n % 2 == 0)
// // // 		{
// // // 			if (find(v.begin(), v.end(), n / 2) != v.end())
// // // 				cout << "YES" << endl, flag = true;
// // // 		}

// // // 		for (ll i = 0; i < v.size(); i++)
// // // 		{
// // // 			for (ll j = v.size() - 1; j >= 0; j--)
// // // 			{
// // // 				if (v[i] + v[j] == n && flag == false)
// // // 				{
// // // 					flag = true;
// // // 					cout << "YES" << endl;
// // // 					break;
// // // 				}
// // // 				else if (v[i] + v[j] > n)
// // // 				{
// // // 					j--;
// // // 				}
// // // 				else
// // // 					i++;

// // // 			}
// // // 		}

// // // 		if (flag == false)
// // // 			cout << "NO" << endl;

// // 	}
// // 	return 0;


// #include<bits/stdc++.h>
// #define ll 				long long
// #define pb 				push_back
// #define loop(i,n) 		for(ll i=0;i<n;i++)
// #define loop1(i,n) 		for(ll i=1;i<=n;i++)
// #define mod 1000000007

// #define setbits(x)      __builtin_popcountll(x)
// #define zrobits(x)      __builtin_ctzll(x)

// using namespace std;

// void io()
// {
// 	ios::sync_with_stdio(false);
// 	cin.tie(0);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// }

// bool prime[201];
// vector<ll>v;
// vector<ll>pr;
// void sieve()
// {

// 	memset(prime, true, sizeof(prime));
// 	prime[0] = false;
// 	prime[1] = false;
// 	for (ll p = 2; p * p <= 200; p++)
// 	{

// 		if (prime[p] == true)
// 		{

// 			for (ll i = p * p; i <= 200; i += p)
// 				prime[i] = false;
// 		}
// 	}

// }
// int main()
// {
// 	io();
// 	ll t;
// 	cin >> t;
// 	sieve();
// 	while (t--)
// 	{
// 		ll n;
// 		cin >> n;

// 		for (ll i = 2; i < 200; i++)
// 		{
// 			if (prime[i] == true)
// 				pr.pb(i);
// 		}


// 		for (ll i = 0; i < pr.size(); i++)
// 		{
// // // 			if (prime[i] == true)
// // // 			{
// 			for (ll j = i + 1; j < pr.size(); j++)
// 			{
// // 				// 	if (prime[j] == true)
// 				v.pb(pr[i] * pr[j]);
// 			}
// // // 			}
// 		}
// 		// for (ll i = 0; i < pr.size(); i++)
// 		// cout << v[i] << endl;

// 		vector<ll>sum;

// 		for (ll i = 0; i < v.size(); i++)
// 		{
// 			for (ll j = 0; j < v.size(); j++)
// 			{
// 				sum.pb(v[i] + v[j]);
// 			}
// 		}

// 		if (find(sum.begin(), sum.end(), n) != sum.end())
// 		{
// 			cout << "YES" << endl;
// 		}
// 		else
// 			cout << "NO" << endl;
// // 		bool flag = false;
// // 		if (n % 2 == 0)
// // 		{
// // 			if (find(v.begin(), v.end(), n / 2) != v.end())
// // 				cout << "YES" << endl, flag = true;
// // 		}

// // 		for (ll i = 0; i < v.size(); i++)
// // 		{
// // 			for (ll j = v.size() - 1; j >= 0; j--)
// // 			{
// // 				if (v[i] + v[j] == n && flag == false)
// // 				{
// // 					flag = true;
// // 					cout << "YES" << endl;
// // 					break;
// // 				}
// // 				else if (v[i] + v[j] > n)
// // 				{
// // 					j--;
// // 				}
// // 				else
// // 					i++;

// // 			}
// // 		}

// // 		if (flag == false)
// // 			cout << "NO" << endl;

// 	}
// 	return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a[201] = {0};
	for (int i = 2; i <= sqrt(200); i++)
	{
		if (a[i] == 1)
			continue;

		for (int j = i * i; j <= 200; j += i)
			a[j] = 1;

	}

	vector<int> primes;
	for (int i = 2; i <= 200; i++)
	{
		if (a[i] == 0)
			primes.push_back(i);
	}

	int l = primes.size();
	vector<int> semisums;
	for (int i = 0; i < l; i++)
	{
		for (int j = i + 1; j < l; j++)
			semisums.push_back(primes[i]*primes[j]);
	}

	vector<int> allsums;
	for (int i = 0; i < semisums.size(); i++)
	{
		for (int j = 0; j < semisums.size(); j++)
			allsums.push_back(semisums[i] + semisums[j]);
	}

	/*for(auto it : allsums)
	cout<<it<<" ";*/

	//

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		if (find(allsums.begin(), allsums.end(), n) != allsums.end())
			cout << "YES";
		else
			cout << "NO";

		cout << endl;
	}
	return 0;
}