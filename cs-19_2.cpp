#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 256;
int mod = 1e9 + 7;
int countSub(string str)
{
    // Create an array to store index
    // of last
    vector<int> last(MAX_CHAR, -1);

    // Length of input string
    int n = str.length();

    // dp[i] is going to store count of distinct
    // subsequences of length i.
    int dp[n + 1];

    // Empty substring has only one subsequence
    dp[0] = 1;

    // Traverse through all lengths from 1 to n.
    for (int i = 1; i <= n; i++)
    {
        // Number of subsequences with substring
        // str[0..i-1]
        dp[i] = (2 * dp[i - 1]) % mod;

        // If current character has appeared
        // before, then remove all subsequences
        // ending with previous occurrence.
        if (last[str[i - 1]] != -1)
            dp[i] = (dp[i] - dp[last[str[i - 1]]]) % mod;

        // Mark occurrence of current character
        last[str[i - 1]] = (i - 1);
    }

    return dp[n] % mod;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<char> a(n);
        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        int num = countSub(s) % mod;
        cout << num - 1 << endl;
    }
    return 0;
}