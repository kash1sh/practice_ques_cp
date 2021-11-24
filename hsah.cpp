#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second == p2.second)
    {
        return 1000 / p1.first > 1000 / p2.first;
    }
    return p1.second > p2.second;
}
int main()
{
    int max_marky, s, n;
    //min_marky is min marks s is number of students n is the number of questions
    cin >> max_marky >> s >> n;
    vector<int> walhberg;
    int danny;
    map<int, int> mallu;
    for (int i = 0; i < s; i++)
    {
        cin >> danny;
        walhberg.push_back(danny);
    }
    vector<pair<int, int>> haru;
    int qno, m;

    for (int i = 0; i < n; i++)
    {

        cin >> qno >> m;
        mallu[qno] = i + 1;
        haru.push_back(make_pair(qno, m));
    }
    sort(haru.begin(), haru.end(), compare);
    for (int i = 0; i < s; i++)
    {
        vector<int> kar;
        int sum = 0;
        int x = walhberg[i];
        for (int j = 0; j < n; j++)
        {

            if (sum <= (max_marky - x))
            {
                sum = sum + haru[j].first;
                kar.push_back(mallu[haru[j].first]);
            }
        }
        cout << kar.size() << " ";
        sort(kar.begin(), kar.end());
        for (int k = 0; k < kar.size(); k++)
        {
            cout << kar[k] << " ";
        }
        kar.clear();
        cout << endl;
    }
}