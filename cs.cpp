#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> v(20000);
map<string, ll> m;

void read()
{
    fstream fin;

    // Open an existing file
    fin.open("t4_i.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    ll cnt = 0;
    while (fin >> temp)
    {

        row.clear();
        // read row
        getline(fin, line);
        // partition into words
        stringstream s(line);
        if (cnt = 0)
        {
            cnt = 1;
            continue;
        }
        while (getline(s, word, ', '))
        {

            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }
        // cout << row[0] << endl;
        // break;
        ll val = stoi(row[2]);
        string title = row[0];
        m[title] += val;
        v.push_back(val);
    }
    //sorting
    sort(v.begin(), v.end());

    for (ll i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
        // return;
    }
    cout << endl;
    // finding most popular
    string name;
    ll maxa = LONG_MIN;
    for (auto i : m)
    {
        if (i.second > maxa)
        {
            maxa = i.second;
            name = i.first;
        }
    }
    // most popular
    cout << name << endl;
    // rr;
}
int main()
{
    read();
    return 0;
}