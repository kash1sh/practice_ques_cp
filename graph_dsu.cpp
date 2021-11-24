#include <bits/stdc++.h>
using namespace std;

int grid[MAXN][MAXM];     // the grid itself
int n, m;                 // grid dimensions, rows and columns
bool visited[MAXN][MAXM]; // keeps track of which nodes have been visited
int currentSize = 0;      // reset to 0 each time we start a new component

void floodfill(int r, int c, int color)
{
    if (r < 0 || r >= n || c < 0 || c >= m)
        return; // if outside grid
    if (grid[r][c] != color)
        return; // wrong color
    if (visited[r][c])
        return; // already visited this square

    visited[r][c] = true; // mark current square as visited
    currentSize++;        // increment the size for each square we visit
    // recursively call floodfill for neighboring squares
    floodfill(r, c + 1, color);
    floodfill(r, c - 1, color);
    floodfill(r - 1, c, color);
    floodfill(r + 1, c, color);
}

int parent[MAXN]; //stores the root of each set
void initialize(int N)
{
    for (int i = 0; i < N; i++)
    {
        parent[i] = i; //initially, the root of each set is the node itself
    }
}
// find NAIVE IMPLEMENTATION
int find(int x)
{ //finds the root of the set of x
    if (x == parent[x])
    { //if x is the parent of itself, it is the root
        return x;
    }
    else
    {
        return find(parent[x]); //otherwise, recurse to the parent of x
    }
}
// find OPTIMIZED IMPLEMENTATION
int find(int x)
{
    if (x == parent[x])
    {
        return x;
    }
    else
    {
        // we set the direct parent to the root of the set to reduce path length
        return parent[x] = find(parent[x]);
    }
}
void union(int a, int b)
{                    //merges the sets of a and b
    int c = find(a); //find the root of a
    int d = find(b); //find the root of b
    if (c != d)
    {
        parent[d] = c; //merge the sets by setting the parent of d to c
    }
}
int main()
{
    return 0;
}