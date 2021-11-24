// include<bits / stdc++.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int flag = 0, f = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 1)
                flag++;
            else
                f++;
        }
        int ans = min(flag, n / 2) + min(f, (n + 1) / 2);
        cout << ans << endl;
    }

    return 0;
}