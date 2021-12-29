#include <bits/stdc++.h>
using namespace std;

int n, cnt[1000001];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0, num; i < n; i++)
    {
        cin >> num;
        for (int p = 1; p * p <= num; p++)
        {
            if (num % p == 0)
            {
                cnt[p]++;
                if (p * p != num)
                    cnt[num / p]++;
            }
        }
    }
    for (int i = 1000000; i >= 1; i--)
    {
        if (cnt[i] >= 2)
        {
            cout << i << "\n";
            break;
        }
    }
}