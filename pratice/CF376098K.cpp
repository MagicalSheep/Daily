#include <bits/stdc++.h>
using namespace std;

struct Info
{
    string xing, ming, mail;
};

map<string, Info> names1, mails1, names2, mails2;
vector<string> ans1, ans2;

void input(int ch)
{
    string line;
    while (true)
    {
        getline(cin, line);
        if (line.empty())
            break;
        int len = line.size();
        Info info;
        string buf;
        int flag = 0;
        for (int i = 0; i < len; i++)
        {
            if (i == len - 1)
                buf.push_back(line[i]);
            if (line[i] == ' ' || i == len - 1)
            {
                if (flag == 0)
                    info.ming = buf;
                else if (flag == 1)
                    info.xing = buf;
                else
                    info.mail = buf;
                buf.clear();
                ++flag;
                continue;
            }
            buf.push_back(line[i]);
        }
        string m, n, tmp = info.xing + " " + info.ming;
        for (auto c : info.mail)
            m.push_back(tolower(c));
        for (auto c : tmp)
            n.push_back(tolower(c));
        if (ch == 0)
        {
            mails1[m] = info;
            names1[n] = info;
        }
        else
        {
            mails2[m] = info;
            names2[n] = info;
        }
    }
}

void solve()
{
    for (auto x : names1)
    {
        string m;
        for (auto c : x.second.mail)
            m.push_back(tolower(c));
        if ((names2.find(x.first) == names2.end()) &&
            (mails2.find(m) == mails2.end()))
            ans1.emplace_back(m);
    }
    for (auto x : names2)
    {
        string m;
        for (auto c : x.second.mail)
            m.push_back(tolower(c));
        if ((names1.find(x.first) == names1.end()) &&
            (mails1.find(m) == mails1.end()))
            ans2.emplace_back(m);
    }
    sort(ans1.begin(), ans1.end());
    sort(ans2.begin(), ans2.end());
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input(0);
    input(1);
    solve();
    if (ans1.empty() && ans2.empty())
    {
        cout << "No mismatches." << endl;
        return 0;
    }
    for (auto x : ans1)
        cout << "I " << mails1[x].mail << " " << mails1[x].xing << " " << mails1[x].ming << endl;
    for (auto x : ans2)
        cout << "O " << mails2[x].mail << " " << mails2[x].xing << " " << mails2[x].ming << endl;
    return 0;
}