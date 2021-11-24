
// #include <bits/stdc++.h>
// #define ll long long
// #define pb push_back
// #define fo(i, k, n) for (ll i = k; i < n; i++)
// #define fo1(i, k, n) for (ll i = k; i <= n; i++)
// #define fir first
// #define sec second

// #define setbits(x) __builtin_popcountll(x)
// #define zrobits(x) __builtin_ctzll(x)

// using namespace std;

// void io()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     // #ifndef ONLINE_JUDGE
//     // freopen("input.txt", "r", stdin);
//     // freopen("output.txt", "w", stdout);
//     // #endif
// }
// ll mod = 1e9 + 7, mxn = 3e5 + 5;

// ll add(ll a, ll b, ll mod)
// {
//     a %= mod;
//     b %= mod;
//     a += b;
//     if (a >= mod)
//         a -= mod;
//     if (a < 0)
//     {
//         a += mod;
//         a %= mod;
//     }
//     return a;
// }

// ll mul(ll a, ll b, ll mod)
// {
//     a %= mod;
//     b %= mod;
//     a *= b;
//     a += mod;
//     return a % mod;
// }
// // ll modInverse(ll a, ll m){
// //     ll x, y;
// //     ll g = gcdExtended(a, m, &x, &y);
// //         ll res = (x%m + m) % m;
// //         return res;
// // }
// ll binary_Search(vector<ll> &arr, ll key)
// {
//     ll l = 0, r = arr.size() - 1;
//     ll ans;
//     while (l <= r)
//     {
//         ll mid = (l + r) / 2;
//         ll value = arr[mid];
//         if (value > key)
//         {
//             r = mid - 1;
//         }
//         else if (value == key)
//         {
//             return mid;
//         }
//         else
//         {
//             l = mid + 1;
//         }
//     }
//     return -1;
// }
// ll po(ll a, ll b, ll mod)
// {
//     if (b == 0)
//         return 1;
//     if (b % 2 == 0)
//         return po(mul(a, a, mod), b / 2, mod);
//     return mul(a, po(mul(a, a, mod), (b - 1) / 2, mod), mod);
// }

// long long power(long long X, long long N)
// {
//     if (N == 0)
//         return 1;
//     if (N % 2 == 0)
//         return power(X * X, N / 2);
//     return X * power(X, N - 1);
// }

// int fact[200003];
// int inv[200003];

// void fact0()
// {
//     int i, j;
//     fact[0] = 1;
//     for (i = 1; i <= 200000; i++)
//     {
//         fact[i] = i * fact[i - 1] % mod;
//     }
//     inv[0] = 1;
//     inv[1] = 1;
//     int p = mod;
//     for (i = 2; i <= 200000; i++)
//         inv[i] = (p - (p / i) * inv[p % i] % p) % p;

//     for (i = 2; i <= 200000; i++)
//     {
//         inv[i] *= inv[i - 1];
//         inv[i] %= mod;
//     }
// }
// int Comb(int a, int b)
// {
//     // cout<<a<<" "<<b<<endl;
//     int an = fact[a];
//     //cout<<an<<endl;
//     an *= inv[b];
//     an %= mod;
//     an *= inv[a - b];
//     an %= mod;
//     return an;
// }

// vector<int> sieveOfEratosthenes(int N)
// {
//     bool primes[N + 1];
//     memset(primes, true, sizeof(primes));
//     vector<int> arr;

//     for (int i = 2; i * i <= N; i++)
//         if (primes[i] == true)
//         {
//             for (int j = i * i; j <= N; j += i)
//                 primes[j] = false;
//         }

//     for (int i = 2; i <= N; i++)
//         if (primes[i])
//             arr.emplace_back(i);

//     return arr;
// }
// #define mod 1000000007
// bool checkPalindrome(string str)
// {
//     // Calculating string length
//     int len = str.length();

//     // Traversing through the string
//     // upto hlaf its length
//     for (int i = 0; i < len / 2; i++)
//     {

//         // Comparing i th character
//         // from starting and len-i
//         // th character from end
//         if (str[i] != str[len - i - 1])
//             return false;
//     }

//     // If the above loop doesn't return then it is
//     // palindrome
//     return true;
// }
// void solve()
// {
//     ll a, b;
//     cin >> a >> b;
//     string s;
//     cin >> s;
//     ll len = a + b;
//     if (len == 1)
//     {
//         if (a == 1)
//             cout << 0 << endl;
//         else
//             cout << 1 << endl;
//         return;
//     }
//     ll c3 = 0;
//     for (auto i : s)
//     {
//         if (i == '?')
//             c3++;
//     }
//     if (c3 == 0)
//     {
//         if (checkPalindrome(s))
//             cout << s << endl;
//         cout << -1 << endl;
//         return;
//     }
//     if(c3 == len)
//     {

//     }
//     // for (ll i = 0; i < len / 2; i++)
//     // {
//     //     //  if (s[i] != s[len - i - 1])
//     //     if (s[i] == '1')
//     //     {
//     //         s[len - i - 1] == '1';
//     //         b--;
//     //     }
//     //     else if (s[len - i - 1] == '1')
//     //     {
//     //         s[i] == '1';
//     //         b--;
//     //     }
//     //     else if (s[i] == '0')
//     //     {
//     //         s[len - i - 1] = '0';
//     //         a--;
//     //     }
//     //     else if (s[len - i - 1] == '0')
//     //     {
//     //         s[i] = '0';
//     //         a--;
//     //     }
//     // }
//     bool flag = true;
//     for (ll i = 0; i < len / 2; i++)
//     {
//         if (s[i] == '?')
//         {
//             if (s[len - i - 1] != '?')
//             {
//                 s[i] = s[len - i - 1];
//                 s[i] == '0' ? a-- : b--;
//             }
//             else
//             {
//                 if (a > 2)
//                 {
//                     s[i] = '0';
//                     s[len - i - 1] = '0';
//                 }
//                 else if (b > 2)
//                 {
//                     s[i] = '1';
//                     s[len - i - 1] = '1';
//                 }
//                 else
//                     flag = false;
//             }
//         }
//         else if (s[len - i - 1] == '?')
//         {
//             if (s[i] != '?')
//             {
//                 // s[i] = s[len - i - 1];
//                 s[len - i - 1] = s[i];
//                 s[i] == '0' ? a-- : b--;
//             }
//         }
//     }
//     if (flag)
//         cout << s << endl;
//     else
//         cout << -1 << endl;
// }
// int main()
// {
//     io();
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    int c = 0;
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
            a--;
        if (s[i] == '1')
            b--;
        if (s[i] == '?')
            c++;
    }
    // cout<<"in "<<a<<" "<<b<<"\n";
    if (c == 0)
    {
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - 1 - i])
            {
                cout << -1 << "\n";
                return;
            }
        }
        if (a > 0 || b > 0)
        {
            cout << -1 << "\n";
            return;
        }
        cout << s << "\n";
        return;
    }
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == '?' && s[n - i - 1] != '?')
        {
            if (s[n - i - 1] == '0' && a > 0)
            {
                s[i] = '0';
                a--;
            }
            else if (s[n - i - 1] == '0' && a == 0)
            {
                cout << -1 << "\n";
                return;
            }
            else if (s[n - i - 1] == '1' && b > 0)
            {
                s[i] = '1';
                b--;
            }
            else
            {
                cout << -1 << "\n";
                return;
            }
        }
        else if (s[n - i - 1] == '?' && s[i] != '?')
        {
            if (s[i] == '0' && a > 0)
            {
                s[n - i - 1] = '0';
                a--;
            }
            else if (s[i] == '0' && a == 0)
            {
                cout << -1 << "\n";
                return;
            }
            else if (s[i] == '1' && b > 0)
            {
                s[n - i - 1] = '1';
                b--;
            }
            else
            {
                cout << -1 << "\n";
                return;
            }
        }
    }
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == '?' && s[n - i - 1] == '?')
        {
            if (a >= 2)
                s[i] = '0', s[n - i - 1] = '0', a -= 2;
            else if (b >= 2)
                s[i] = '1', s[n - i - 1] = '1', b -= 2;
            else
            {
                cout << -1 << "\n";
                return;
            }
        }
    }
    if (n % 2 == 1 && s[n / 2] == '?')
    {
        if (a > 0)
            s[n / 2] = '0', a--;
        else if (b > 0)
            s[n / 2] = '1', b--;
        else
        {
            cout << -1 << "\n";
            return;
        }
    }
    if (a > 0 || b > 0)
    {
        cout << -1 << "\n";
        return;
    }
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            cout << -1 << "\n";
            return;
        }
    }
    cout << s << "\n";
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout << setprecision(10);
    //        freopen("timber_input.txt", "r", stdin);
    //        freopen("timber_output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        //    cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
