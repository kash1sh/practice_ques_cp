#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<double> comp;
struct Item
{
    int value;
    int weight;
};
static bool help(Item a1, Item a2)
{
    double v1 = (double)((double)a1.value / (double)a1.weight);
    double v2 = (double)((double)a2.value / (double)a2.weight);

    return v2 < v1;
}

double helper(Item arr[], int n, int W)
{
    sort(arr, arr + n, help);

    double cost = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i].weight <= W)
        {
            W -= arr[i].weight;
            comp.push_back(1);
            cost += arr[i].value;
        }

        else
        {
            int remW = W;
            comp.push_back((double)remW / arr[i].weight);
            cost += arr[i].value * ((double)remW / arr[i].weight);
            break;
        }
    }
    return cost;
}
int main()
{
    int n, W;
    cin >> n >> W;

    Item arr[n];

    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " value : " << endl;
        cin >> arr[i].value;

        cout << i + 1 << " weight : " << endl;
        cin >> arr[i].weight;
    }

    double ans = helper(arr, n, W);
    int i = 0;
    for (; i < comp.size() - 1; i++)
    {
        cout << i + 1 << " is Fully Selected  with ratio as " << comp[i] << endl;
    }
    if (i == comp.size() - 1)
        cout << i + 1 << " is Partial with ratio as " << comp[i] << endl;
    cout << "Total Value : " << ans << endl;
}