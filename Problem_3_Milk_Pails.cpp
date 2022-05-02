#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORE(i, a, b) for (int i = (a); i <= (b); i++)
#define F0R(i, a) for (int i = 0; i < (a); i++)
#define trav(a, x) for (auto &a : x)

int X, Y, K, M;

const int MX = 101;
const int INF = 1e9 + 7;

int dist[MX][MX];

void setIn(string s) { freopen(s.c_str(), "r", stdin); }
void setOut(string s) { freopen(s.c_str(), "w", stdout); }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    setIn("pails.in");
    setOut("pails.out");

    cin >> X >> Y >> K >> M;

    F0R(i, MX)
    F0R(j, MX) dist[i][j] = INF;

    queue<pair<int, int>> bfs;
    bfs.push({0, 0});
    dist[0][0] = 0;

    while (!bfs.empty())
    {
        pair<int, int> top = bfs.front();
        bfs.pop();
        int ndist = dist[top.first][top.second] + 1;

        int pourX = min(top.first, Y - top.second);
        int pourY = min(top.second, X - top.first);

        int nx[] = {top.first, 0, X, top.first, top.first - pourX, top.first + pourY}; // all possible pours
        int ny[] = {0, top.second, top.second, Y, top.second + pourX, top.second - pourY};

        F0R(i, 6)
        {
            if (ndist > K || dist[nx[i]][ny[i]] != INF)
                continue;
            dist[nx[i]][ny[i]] = ndist;
            bfs.push({nx[i], ny[i]});
        }
    }

    int ret = INF;

    F0R(i, MX)
    {
        F0R(j, MX)
        {
            if (dist[i][j] <= K)
                ret = min(ret, abs(i + j - M));
        }
    }

    cout << ret << endl;
}