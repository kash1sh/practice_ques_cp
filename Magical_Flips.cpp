#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll TC;
    cin >> TC;
    while (TC--)
    {
        ll n;
        cin >> n;
        //State : -1 undecided, 0 normal, 1 flipped
        vector<ll> A(n), B(n), state(n, -1);
        for (auto &x : A)
            cin >> x;
        for (auto &x : B)
            cin >> x;

        for (ll bit = 1 << 29; bit > 0; bit >>= 1)
        {
            bool poss = true;
            for (ll i = 0; i < n; i++)
            {
                if (state[i] == 0 and !(A[i] & bit))
                    poss = false;
                else if (state[i] == 1 and !(B[i] & bit))
                    poss = false;
                else if (!(A[i] & bit) and !(B[i] & bit))
                    poss = false;
            }
            if (!poss)
                continue;
            for (ll i = 0; i < n; i++)
            {
                if (state[i] != -1)
                    continue;
                // if (A[i] & bit)
                // state[i] = 0;
                // else if (B[i] & bit)
                // state[i] = 1;
                if (!(A[i] & bit))
                    state[i] = 1;
                else if (!(B[i] & bit))
                    state[i] = 0;
            }
        }
        ll ans = (1 << 30) - 1, flips = 0;
        for (ll i = 0; i < n; i++)
        {
            if (state[i] == 1)
            {
                flips++;
                ans &= B[i];
            }
            else
                ans &= A[i];
        }
        cout << ans << ' ' << flips << '\n';
    }

    return 0;
}