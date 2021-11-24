#include <bits/stdc++.h>
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int treeNode)
{
    if (start == end)
    {
        tree[treeNode] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeNode);
    buildTree(arr, tree, mid + 1, end, 2 * treeNode + 1);

    tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}
void updateTree(int *arr, int *tree, int start, int end, int treeNode, int idx, int val)
{
    if (start == end)
    {
        arr[idx] = val;
        tree[treeNode] = val;
        return;
    }

    int mid = (start + end) / 2;

    if (idx > mid)
    {
        updateTree(arr, tree, mid + 1, end, 2 * treeNode + 1, idx, val);
    }
    else
    {
        updateTree(arr, tree, start, mid, 2 * treeNode, idx, val);
    }

    tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}
int query(int *tree, int treeNode, int start, int end, int l, int r)
{
    if (end < l)
        return 0;
    if (start > r)
        return 0;

    if (start >= l && end <= r)
    {
        return tree[treeNode];
    }

    int mid = (start + end) / 2;

    int ans1 = query(tree, 2 * treeNode, start, mid, l, r);
    int ans2 = query(tree, 2 * treeNode + 1, mid + 1, end, l, r);
    return ans1 + ans2;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *tree = new int[10];

    buildTree(arr, tree, 0, 4, 1);
    updateTree(arr, tree, 0, 4, 1, 2, 10);
    for (int i = 1; i < 10; i++)
    {
        cout << tree[i] << endl;
    }
    cout << endl;
    cout << query(tree, 1, 0, 4, 2, 4) << endl;
    cout << endl;
}
