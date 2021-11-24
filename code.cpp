#include<bits/stdc++.h>
#define pb push_back
#define loop(i,n) for(int i=0;i<n;i++)
#define ll long long
using namespace std;
// bool arr[1000001];
// vector<ll> seive()
// {
// 	ll n = 1000001;
// 	for(ll i=0;i<=n;i++)
// 	{
// 		arr[i]=true;
// 	}
// 	arr[0]=false;
// 	arr[1]=false;

// 	for(ll i=0;i*i<=n;i++)
// 	{
// 		if(arr[i]==true)
// 		{
// 			for(ll j=i*i;j<=n;j+=i)
// 			{
// 				arr[j]=false;
// 			}
// 		}
// 	}
// 	vector<ll>ans;

// 	for(ll i=0;i<=n;i++)
// 	{
// 		if(arr[i]==false)
// 			ans.pb(i);
// 	}
// 	return ans;
// }
ll gccd(ll a,ll b)
{
	if(b==0)
		return a;

	return (b,a%b);

}
ll power(long long x, ll y, int p)
{
    ll res = 1;     // Initialize result
 
    x = x % p; // Update x if it is more than or
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	ll n;
	cin>>n;
	// vector<ll>simp=seive();
	// ll maxa=power(5,n,100)%100;
	// cout<<maxa<<endl;
	cout<<25<<endl;
	return 0;
	// cout<<"LAVDA"<<endl;
}
