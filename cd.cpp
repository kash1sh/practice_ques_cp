#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                cout << 1 << " ";
            }
            else
            {
                cout << 2 << " ";
            }
        }
        cout << endl;
        // return 0;
    }
    return 0;
}