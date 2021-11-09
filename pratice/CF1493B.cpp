#include <bits/stdc++.h>
using namespace std;

int T, h, m;

bool reflect(string &s)
{
    reverse(s.begin(), s.end());
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        switch (*it)
        {
        case ':':
        case '1':
        case '8':
        case '0':
            break;
        case '2':
            *it = '5';
            break;
        case '5':
            *it = '2';
            break;
        default:
            return false;
        }
    }
    return true;
}

string create(int val)
{
    int hour = (val / m) % h;
    int minutes = val % m;
    string ret;
    if (hour < 10)
        ret.push_back('0');
    ret.append(to_string(hour));
    ret.push_back(':');
    if (minutes < 10)
        ret.push_back('0');
    ret.append(to_string(minutes));
    return ret;
}

pair<int, int> getval(string time)
{
    string hour, minutes;
    bool flag = true;
    for (auto c : time)
    {
        if (c == ':')
        {
            flag = false;
            continue;
        }
        if (flag)
            hour.push_back(c);
        else
            minutes.push_back(c);
    }
    int hour_val = atoi(hour.c_str());
    int minutes_val = atoi(minutes.c_str());
    return pair<int, int>(hour_val, minutes_val);
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> h >> m;
        int mx = h * m - 1;
        string s;
        cin >> s;
        auto cur = getval(s);
        for (int i = cur.first * m + cur.second; i <= mx; i++)
        {
            string d = create(i);
            if (!reflect(d))
                continue;
            auto v = getval(d);
            if (!(v.first < h && v.second < m))
                continue;
            cout << create(i) << endl;
            goto end;
        }
        cout << "00:00" << endl;
    end:;
    }
    return 0;
}