#include <iostream>
#include <limits.h>

using namespace std;

// Function to find minimum swaps
// to group all 1's together
int minSwaps(int arr[], int n)
{

    int numberOfOnes = 0;

    // find total number of all 1's in the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
            numberOfOnes++;
    }

    // length of subarray to check for
    int x = numberOfOnes;

    int count_ones = 0, maxOnes;

    // Find 1's for first subarray of length x
    for (int i = 0; i < x; i++)
    {
        if (arr[i] == 1)
            count_ones++;
    }

    maxOnes = count_ones;

    // using sliding window technique to find
    // max number of ones in subarray of length x
    for (int i = 1; i <= n - x; i++)
    {

        // first remove leading element and check
        // if it is equal to 1 then decrement the
        // value of count_ones by 1
        if (arr[i - 1] == 1)
            count_ones--;

        // Now add trailing element and check
        // if it is equal to 1 Then increment
        // the value of count_ones by 1
        if (arr[i + x - 1] == 1)
            count_ones++;

        if (maxOnes < count_ones)
            maxOnes = count_ones;
    }

    // calculate number of zeros in subarray
    // of length x with maximum number of 1's
    int numberOfZeroes = x - maxOnes;

    return numberOfZeroes;
}

// Driver Code
int main()
{

    int a[] = {0, 0, 1, 0, 1, 1, 0, 0, 1};
    int n = sizeof(a) / sizeof(a[0]);

    cout << minSwaps(a, n);

    return 0;
}