#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> e;
    DSU(int N) { e = vector<int>(N, -1); }

    // get representive component (uses path compression)
    int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

    bool same_set(int a, int b) { return get(a) == get(b); }

    int size(int x) { return -e[get(x)]; }

    bool unite(int x, int y)
    { // union by size
        x = get(x), y = get(y);
        if (x == y)
            return false;
        if (e[x] > e[y])
            swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

int main()
{
    int node_num, query_num;
    cin >> node_num >> query_num;
    DSU dsu(node_num);

    for (int i = 0; i < query_num; i++)
    {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 0)
        {
            dsu.unite(u, v);
        }
        else
        {
            cout << dsu.same_set(u, v) << endl;
        }
    }
}