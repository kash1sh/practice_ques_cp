#include <bits/stdc++.h>
#define ll long long
using namespace std;
pair<ll, ll> alice_score(multiset<ll> even, multiset<ll> odd, int alice_even, int bob_even)
{
    ll alice = 0, bob = 0;
    int turn = 0;
    int prev_size = 0, count = 0;
    while (true)
    {
        if (turn % 2 == 0)
        {
            if (alice_even == 1 and int(even.size()) != 0)
            {
                alice += *even.rbegin();
                even.erase(even.find(*even.rbegin()));
                alice_even = 0;
            }
            else if (alice_even == 0 and int(odd.size()) != 0)
            {
                alice_even = 1;
                alice += *odd.rbegin();
                odd.erase(odd.find(*odd.rbegin()));
            }
        }
        else
        {
            if (bob_even == 1 and int(even.size()) != 0)
            {
                bob += *even.rbegin();
                even.erase(even.find(*even.rbegin()));
                bob_even = 0;
            }
            else if (bob_even == 0 and int(odd.size()) != 0)
            {
                bob_even = 1;
                bob += *odd.rbegin();
                odd.erase(odd.find(*odd.rbegin()));
            }
        }
        if (prev_size == int(odd.size()) + int(even.size()))
            count++;
        if (count >= 2)
            break;
        prev_size = int(odd.size()) + int(even.size());
        turn++;
    }
    return {alice, bob};
}
void solve()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<ll> x(n);
        multiset<ll> even, odd;
        for (auto &elem : x)
        {
            cin >> elem;
            if (elem % 2 == 0)
                even.insert(elem);
            else
                odd.insert(elem);
        }
        pair<ll, ll> a, b, c, d;
        a = alice_score(even, odd, 0, 1);
        b = alice_score(even, odd, 1, 0);
        c = alice_score(even, odd, 0, 0);
        d = alice_score(even, odd, 1, 1);
        // a and c
        ll a1, a2;
        if (a.second == c.second)
        {
            a1 = max(a.first, c.first);
        }
        else if (a.second > c.second)
        {
            a1 = a.first;
        }
        else
            a1 = c.first;

        // b and d
        if (b.second == d.second)
        {
            a2 = max(b.first, d.first);
        }
        else if (b.second > d.second)
        {
            a2 = b.first;
        }
        else
            a2 = d.first;
        cout << max(a1, a2) << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    solve();
    return 0;
}