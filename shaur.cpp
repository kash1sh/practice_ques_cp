#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void mergerow(int **arr, int r1, int r2, int m2, int c1, int c2)
{
    int n2 = c2 - m2;
    int n1 = m2 - c1 + 1;
    int row1[n1];
    int row2[n2];

    for (int ri = r1; ri <= r2; ri++)
    {
        for (int ci = c1; ci <= c2; ci++)
        {
            if (ci <= m2)
            {
                row1[ci - c1] = arr[ri][ci];
            }
            if (ci > m2)
            {
                row2[ci - m2 - 1] = arr[ri][ci];
            }
        }
        int i = 0;
        int j = 0;
        int k = c1;

        while (i < n1 && j < n2)
        {
            if (row1[i] <= row2[j])
            {
                arr[ri][k] = row1[i];
                i++;
            }
            else
            {
                arr[ri][k] = row2[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            arr[ri][k] = row1[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[ri][k] = row2[j];
            j++;
            k++;
        }
    }
}
void mergecolumn(int **arr, int r1, int r2, int m1, int c1, int c2)
{
    int n2 = r2 - m1;
    int n1 = m1 - r1 + 1;
    int col1[n1];
    int col2[n2];
    for (int ci = c1; ci <= c2; ci++)
    {
        for (int ri = r1; ri <= r2; ri++)
        {
            if (ri <= m1)
            {
                col1[ri - r1] = arr[ri][ci];
            }
            if (ri > m1)
            {
                col2[ri - m1 - 1] = arr[ri][ci];
            }
        }
        int i = 0;
        int j = 0;
        int k = r1;

        while (i < n1 && j < n2)
        {
            if (col1[i] <= col2[j])
            {
                arr[k][ci] = col1[i];
                i++;
            }
            else
            {
                arr[k][ci] = col2[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            arr[k][ci] = col1[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k][ci] = col2[j];
            j++;
            k++;
        }
    }
}
void mergesort(int **arr, int r1, int r2, int c1, int c2)
{
    int m1 = (r2 + r1) / 2;
    int m2 = (c2 + c1) / 2;
    if (r1 >= r2 && c2 >= c1)
    {
        return;
    }
    mergesort(arr, r1, m1, c1, m2);
    mergesort(arr, r1, m1, m2 + 1, c2);
    mergesort(arr, m1 + 1, r2, c1, m2);
    mergesort(arr, m1 + 1, r2, m2 + 1, c2);
    mergerow(arr, r1, r2, m2, c1, c2);
    mergecolumn(arr, r1, r2, m1, c1, c2);
}
int main()
{
    int r;
    int c;
    cin >> r >> c;
    int c2 = c - 1;
    int r2 = r - 1;
    int **Matrix = new int *[r];
    for (int i = 0; i < r; i++)
    {
        Matrix[i] = new int[c];
        for (int j = 0; j < c; j++)
        {
            cin >> Matrix[i][j];
        }
    }
    mergesort(Matrix, 0, r2, 0, c2);
    for (int a = 0; a < r; a++)
    {
        for (int b = 0; b < c; b++)
        {
            cout << Matrix[a][b] << " ";
        }
        cout << endl;
    }
}

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define vll vector<ll>
#define vpll vector<pair<ll, ll>>
#define fo(i, k, n) for (ll i = k; i < n; i++)
#define fo1(i, k, n) for (ll i = k; i <= n; i++)

#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)

using namespace std;

void io()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif
}

#define mod 1000000007

int mat[1001][1001];

void mer1(int l, int m, int r, int cs, int cend)
{

    for (int ii = cs; ii <= cend; ii++)
    {
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[n1], R[n2];
        for (int i = 0; i < n1; i++)
            L[i] = mat[l + i][ii];
        for (int j = 0; j < n2; j++)
            R[j] = mat[m + 1 + j][ii];

        int i = 0;

        int j = 0;

        int k = l;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                mat[k][ii] = L[i];
                i++;
            }
            else
            {
                mat[k][ii] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            mat[k][ii] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            mat[k][ii] = R[j];
            j++;
            k++;
        }
    }
}
void mer2(int l, int r, int m, int rs, int rend)
{

    for (int ii = rs; ii <= rend; ii++)
    {
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[n1], R[n2];
        for (int i = 0; i < n1; i++)
            L[i] = mat[ii][l + i];
        for (int j = 0; j < n2; j++)
            R[j] = mat[ii][m + 1 + j];

        int i = 0;

        int j = 0;

        int k = l;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                mat[ii][k] = L[i];
                i++;
            }
            else
            {
                mat[ii][k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            mat[ii][k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            mat[ii][k] = R[j];
            j++;
            k++;
        }
    }
}

void helpp(ll rs, ll cs, ll re, ll ce)
{

    if (rs >= re && cs >= ce)
        return;

    ll midX = ceil((re + rs) / 2);
    ll midY = ceil((ce + cs) / 2);
    // cout << "H" << endl;
    helpp(rs, cs, midX, midY);
    helpp(rs, midY + 1, midX, ce);
    helpp(midX + 1, cs, re, midY);
    helpp(midX + 1, midY + 1, re, ce);

    mer2(cs, ce, midY, rs, re);
    mer1(rs, midX, re, cs, ce);
}
void solve()
{
    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
    helpp(0, 0, n - 1, m - 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << mat[i][j] << " ";
        // cout << endl;
    }
    cout << endl;
}
int main()
{
    io();
    solve();

    return 0;
}