#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
//#include<bits/stdc++.h>
#include <unordered_set>
using namespace std;

/*
int main()
{
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int k;
        cin >> n >> k;

        string input;
        cin >> input;

        char start = input[0];
        char stop = 'p';

        if (k % 2 == 0)
        {
            stop = start;
        }
        else
        {
            if (start == '1')
                stop = '0';
            else
                stop = '1';
        }

        int lastindex = -1;

        for (int i = input.size() - 1; i >= 0; i--)
        {
            if (input[i] == stop)
            {
                lastindex = i;
                break;
            }
        }

        int zeroes = 0;
        int ones = 0;
        int flag = 0;

        if (lastindex != -1)
        {
            for (int i = 0; i <= lastindex; i++)
            {
                if (input[i] == '1')
                    ones++;
                else
                    zeroes++;
            }

            if (k % 2 == 0)
            {

                if (start == '1')
                {
                    if (!(ones >= ((k / 2) + 1) && zeroes >= (k / 2)))
                    {
                        flag = 1;
                        cout << -1 <<endl;
                    }
                      
                }
                else 
                {

                    if (!(zeroes >= ((k / 2) + 1) && ones >= (k / 2)))
                    {
                        flag = 1;
                        cout << -1 << endl;
                    }
                }

            }
            else
            {

                if (!(ones >= ((k + 1) / 2) && zeroes >= ((k + 1) / 2)))
                {
                    flag = 1;
                    cout << -1 << endl;
                }
            }
            
        }
        else
        {
            flag = 1;
            cout << -1 << endl;
        }

        if (flag == 0)
        {
            cout << lastindex + 1 << endl;
        }
     
    }

    return 0;
}*/

long gcd(long a, long b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

long findGCD(vector<long> arr, long n)
{
    long result = arr[0];
    for (long i = 1; i < n; i++)
    {
        result = gcd(arr[i], result);

        if (result == 1)
        {
            return 1;
        }
    }
    return result;
}

/*
void solution(vector<lli>& arr, lli n) {
    int even = 0;
    vector<int> evens;
    int bridge = ceil((float)n / 2.0);
    for (auto i : arr) {
        if (i % 2 == 0) {
            even++;
            evens.push_back(i);
        }
    }

    if (even < bridge) {
        println("NO");
        return;
    }

    sort(evens.begin(), evens.end());

    while (true) {
        if (evens.size() < bridge) {
            println("NO");
            return;
        }

        if (gcdArray(evens, bridge) == 2) {
            println("YES");
            return;
        }

        evens.erase(evens.begin());

    }

}*/

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        long n;
        cin >> n;

        vector<long> input;

        for (long i = 0; i < n; i++)
        {
            long temp;
            cin >> temp;

            // if(temp%2==0)
            input.push_back(temp);
        }

        long even = 0;
        vector<long> evens;
        long bridge = ceil((float)n / 2.0);
        for (auto i : input)
        {
            if (i % 2 == 0)
            {
                even++;
                evens.push_back(i);
            }
        }

        if (even < bridge)
        {
            cout << "NO" << endl;
            //return;
        }

        else
        {
            sort(evens.begin(), evens.end());

            while (true)
            {
                if (evens.size() < bridge)
                {
                    cout << "NO" << endl;
                    //return;
                    break;
                }

                if (findGCD(evens, bridge) == 2)
                {
                    cout << "YES" << endl;
                    //return;
                    break;
                }

                evens.erase(--evens.end());
            }
        }
    }

    return 0;
}