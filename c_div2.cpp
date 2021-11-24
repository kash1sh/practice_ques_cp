void solve_LOL()
{
    string s;
    cin >> s;

    int n = sz(s);

    string s1 = "";
    string s2 = "";

    vector<int> p1, p0;
    F(i, 0, n - 1)
    {
        if (i % 2)
            s1 += '1', s2 += '0';
        else
            s1 += '0', s2 += '1';

        if (s[i] == '1')
        {
            p1.push_back(i);
        }
        if (s[i] == '0')
        {
            p0.push_back(i);
        }
    }

    vector<int> une1, une2;

    F(i, 0, n - 1)
    {
        if (s[i] == '?')
            continue;
        if (s[i] != s1[i])
            une1.push_back(i);
        if (s[i] != s2[i])
            une2.push_back(i);
    }

    dbg(s1, s2);

    int cnt = 0;

    F(i, 0, n - 1)
    {
        int pos1 = lower_bound(all(p1), i) - p1.begin();
        int pos0 = lower_bound(all(p0), i) - p0.begin();

        if (pos1 == sz(p1) && pos0 == sz(p0))
        {
            cnt += ((n - i) * (n - i + 1)) / 2;
            break;
        }
        int par = 1;
        int ind = -1;

        if ((pos0 == sz(p0)) || (pos1 < sz(p1) && p1[pos1] < p0[pos0]))
        {
            ind = p1[pos1];
            if (s1[ind] == '1')
                par = 1;
            else
                par = 2;
        }
        else
        {
            ind = p0[pos0];
            if (s1[ind] == '0')
                par = 1;
            else
                par = 2;
        }

        dbg(i, par, ind, cnt);

        if (par == 1)
        {
            int pos = lower_bound(all(une1), ind) - une1.begin();
            int last = n;
            if (pos != sz(une1))
            {
                last = une1[pos];
            }

            dbg(i, pos, last);

            int len = last - i;
            cnt += len;
        }
        else
        {
            int pos = lower_bound(all(une2), ind) - une2.begin();
            int last = n;
            if (pos != sz(une2))
            {
                last = une2[pos];
            }

            int len = last - i;
            cnt += len;
        }

        dbg(cnt);
    }

    cout << cnt;
    cout << "\n";
}