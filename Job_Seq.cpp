#include <bits/stdc++.h>
#define ll long long
using namespace std;
class Job
{
public:
    int id;
    int dead;
    int profit;
};
static bool help(Job a1, Job a2)
{
    return a1.profit > a2.profit;
}
vector<int> JobScheduling(Job arr[], int n)
{
    vector<int> v;
    sort(arr, arr + n, help);

    //   vector<int> ans;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].dead > maxi)
        {
            maxi = arr[i].dead;
        }
    }
    int avail[maxi + 1];
    memset(avail, -1, sizeof(avail));
    int count = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (avail[j] == -1)
            {
                avail[j] = i;
                count++;
                res += arr[i].profit;
                //   ans.push_back(arr[i].profit);
                break;
            }
        }
    }
    //   int sum=0;
    //   for(int i=0;i<n;i++)
    //   sum+=ans[i];
    //   sum=accumulate(v.begin(),v.end(),sum);
    v.push_back(count);
    v.push_back(res);
    return v;
}

int main()
{
    // #ifndef ONLINE_JUDGE
    //   freopen("input.txt","r",stdin);
    //   freopen("output.txt","w",stdout);
    // #endif
    int n;
    cin >> n;

    Job arr[n];

    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        arr[i].id = x;
        arr[i].dead = y;
        arr[i].profit = z;
    }
    vector<int> ans = JobScheduling(arr, n);

    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}