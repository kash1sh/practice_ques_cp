#include<bits/stdc++.h>
using namespace std;

static bool help(pair<int,int>&a,pair<int,int>&b)
{
    return a.second<b.second;
}
int maxMeetings(int start[], int end[], int n) {
    
     vector<pair<int,int>>v;
    
    for(int i=0;i<n;i++)
    {
        int a=start[i];
        int b=end[i];
        // cin>>a>>b ;
        v.push_back({a,b});
    }
    
    sort(v.begin(),v.end(),help);
    
     int count=1;
    int mini=v[0].second;
    cout<<"Activities Possible"<<endl;
    cout<<v[0].first<<" "<<v[0].second<<endl;
    for(int i=0;i<n-1;i++)
    {
        if(mini<v[i+1].first)
        {
             cout<<v[i+1].first<<" "<<v[i+1].second<<endl;
            mini=v[i+1].second;
            count++;
        }
    }
    // cout<<count<<endl;
    return count;
    }
    
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
    int n;
    cin>>n;
    
    int start[n];
    int end[n];
    
    for(int i=0;i<n;i++)
    cin>>start[i];
    for(int i=0;i<n;i++)
    cin>>end[i];
    
    int ans=maxMeetings(start,end,n);
    cout<<"Count : "<<ans<<endl;
}