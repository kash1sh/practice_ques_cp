#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int num = 0, n = s.size(), pow = 1;
    //initializes array with initializer list
    //explained here: https://www.learncpp.com/cpp-tutorial/arrays-part-ii/
    int count[2019] = {1};
    for (int i = n - 1; i >= 0; i--)
    {
        //find the remainder of the current number mod 2019
        num = (num + pow * (s[i] - '0')) % 2019;
        //increment the count of this remainder
        count[num]++;
        pow = pow * 10 % 2019;
    }
    long long ans = 0;
    for (int i = 0; i < 2019; i++)
    {
        //there are nC2 ways to pair the numbers with the same remainder
        ans += (long long)count[i] * (count[i] - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}