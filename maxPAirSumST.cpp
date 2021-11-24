#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int maximum;
    int smaximum;
};
void buildTree(int *arr, node *tree, int treeIndex, int start, int end)
{

    if (start == end)
    {
        tree[treeIndex].maximum = arr[start];
        tree[treeIndex].smaximum = INT_MIN;
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, 2 * treeIndex, start, mid);
    buildTree(arr, tree, 2 * treeIndex + 1, mid + 1, end);

    node left = tree[2 * treeIndex];
    node right = tree[2 * treeIndex + 1];
    tree[treeIndex].maximum = max(left.maximum, right.maximum);
    tree[treeIndex].smaximum = min(max(right.maximum, left.smaximum), max(left.maximum, right.smaximum));
    return;
}
void updateTree(int *arr, node *tree, int start, int end, int treeNode, int idx, int val)
{
    if (start == end)
    {
        arr[idx] = val;
        tree[treeNode].maximum = val;
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

    tree[treeNode].maximum = max(tree[2 * treeNode].maximum, tree[2 * treeNode + 1].maximum);
    tree[treeNode].smaximum = max(tree[2 * treeNode].smaximum, tree[2 * treeNode + 1].smaximum);
}
node query(node *tree, int treeNode, int start, int end, int l, int r)
{
    if (end < l)
        return {};
    if (start > r)
        return {};

    if (start >= l && end <= r)
    {
        return tree[treeNode];
    }

    int mid = (start + end) / 2;

    node ans1 = query(tree, 2 * treeNode, start, mid, l, r);
    node ans2 = query(tree, 2 * treeNode + 1, mid + 1, end, l, r);

    node k;
    k.maximum = (ans1.maximum, ans2.maximum);
    k.smaximum = (ans1.smaximum, ans2.smaximum);
    return k;
    // return ans1  ans2;
}
int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    node *tree = new node[3 * n];
    buildTree(arr, tree, 1, 0, n - 1);

    for (int i = 0; i < 3 * n; i++)
    {
        cout << tree[i].maximum << " " << tree[i].smaximum << endl;
    }
    cout << endl;
    node k = query(tree, 1, 0, n - 1, 1, 4);
    cout << k.maximum << "  HH" << endl;
    updateTree(arr, tree, 0, 4, 1, 2, 10);
    for (int i = 0; i < 3 * n; i++)
    {
        cout << tree[i].maximum << " " << tree[i].smaximum << endl;
    }
}