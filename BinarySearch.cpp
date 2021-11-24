#include <bits/stdc++.h>
using namespace std;

int bsearch(int L, int R, int arr[], int key)
{
    while (L <= H)
    {
        int mid = L + (H - L) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }

        if (arr[mid] < key)
        {
            L = mid + 1;
        }
        else
            R = mid - 1;
    }
    return -1;
}
int binary_search(vector<int> &a, int query)
{
    int l = 0, hi = a.size() - 1;
    while (l < hi)
    {
        int mid = (l + hi) / 2;
        if (a[mid]) < query)
            {
                l = mid + 1;
            }
        else
        {
            hi = mid;
        }
    }
    // if (a[left] == query)
    // {
    return l;
    // }
    return -1;
    // Alternate
    // int k = 0;
    // for (int b = n / 2; b >= 1; b /= 2)
    // {
    //     while (k + b < n && array[k + b] <= x)
    //         k += b;
    // }
    // if (array[k] == x)
    // {
    //     // x found at index k
    // }
}
int max_binary_search()
{

    int low = 0;

    int high = pairs[m - 1].second;

    while (low < high)
    {

        int mid = low + (high - low) / 2;

        if (pos(mid))
        {

            low = mid + 1;
        }
        else
        {

            high = mid;
        }
    }

    return (low - 1);
}
// find Then, the following code counts the number of elements whose value is x:
auto a = lower_bound(array, array + n, x);
auto b = upper_bound(array, array + n, x);
cout << b - a << "\n";
// Using equal_range, the code becomes shorter:
auto r = equal_range(array, array + n, x);
cout << r.second - r.first << "\n";
int main()
{
    arr = {0, 1, 2, 3, 4, 5, 6};
    int key = 0;
    bsearch(0, 10, arr, key);
}