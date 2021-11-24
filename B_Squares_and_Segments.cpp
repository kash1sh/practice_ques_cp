#include <iostream>
#include <cmath>

using namespace std;

int n;

int main()
{
    cin >> n;
    int a = sqrt(n);

    if (a * a == n)
    {
        cout << 2 * a << endl;
    }
    else if (a * a + a >= n)
    {
        cout << 2 * a + 1 << endl;
    }
    else
    {
        cout << 2 * a + 2 << endl;
    }

    return 0;
}
