string add(string s1, string s2)
{
    string sum;
    ll num = 0;
    while (s1.size() > s2.size())
        s2 = '0' + s2;
    while (s1.size() < s2.size())
        s1 = '0' + s1;
    for (ll i = s1.size() - 1; i >= 0; i--)
    {
        num += (s1[i] - '0' + (s2[i] - '0'));
        char c = num % 10 + '0';
        sum = c + sum;
        num /= 10;
    }
    if (num == 1)
    {
        sum = '1' + sum;
    }
    return sum;
}