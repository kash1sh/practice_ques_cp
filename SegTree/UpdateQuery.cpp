#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int t[4 * N];

// tl,tr -> node range
// id -> updating point
// val -> new value
// point in array
void update(int v, int tl, int tr, int id, int val)
{
    if (tl == id && tr == id)
    {
        t[v] = val;
        return;
    }

    if (id > tr || id < tl)
    {
        return;
    }

    int tm = (tr + tl) / 2;
    update(2 * v, tl, tm, id, val);
    update(2 * v + 1, tm + 1, tr, id, val);
    t[v] = t[2 * v] + t[2 * v + 1];
}
// l,r is the query range
int query(int v, int tl, int tr, int l, int r)
{
    // 0 Overlap
    if (tl > r || tr < l)
        return 0;

    // full Overlap
    if (l <= tl && r >= tr)
    {
        return t[v];
    }
    // partial Overlap

    int tm = (tl + tr) / 2;
    int ans = 0;
    ans += query(2 * v, tl, tm, l, r);
    ans += query(2 * v + 1, tm + 1, tr, l, r);
    return ans;
}
int main()
{
    update(1, 0, N - 1, 2, 5);
    update(1, 0, N - 1, 3, 6);
    cout << query(1, 0, N - 1, 2, 3);
}