#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a;
        cout << min(a, n - a) << endl;
    }
    return 0;
}