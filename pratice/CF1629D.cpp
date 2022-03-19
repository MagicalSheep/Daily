#include <bits/stdc++.h>
using namespace std;

int t, n;

bool solve(vector<string> &dict)
{
    set<string> se;
    for (auto s : dict)
    {
        string st = s;
        reverse(st.begin(), st.end());
        if (st == s || se.find(st) != se.end())
            return true;
        if (s.length() == 2)
        {
            string st = s;
            reverse(st.begin(), st.end());
            for (int i = 'a'; i <= 'z'; i++)
            {
                st.push_back(i);
                if (se.find(st) != se.end())
                    return true;
                st.pop_back();
            }
        }
        else if (s.length() == 3)
        {
            string s2 = s.substr(1, 2);
            string rs2 = s2;
            reverse(rs2.begin(), rs2.end());
            if (se.find(rs2) != se.end())
                return true;
        }
        se.insert(s);
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<string> dict(n);
        for (int i = 0; i < n; i++)
            cin >> dict[i];
        cout << ((solve(dict)) ? "YES" : "NO") << endl;
    }
    return 0;
}