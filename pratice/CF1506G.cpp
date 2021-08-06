#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int t;

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        string s, ans;
        cin >> s;
        int len = s.size(), vis[26] = {0}, f[26] = {0};
        for (int i = 0; i < len; i++)
            ++f[s[i] - 'a'];
        for (int i = 0; i < len; i++)
        {
            --f[s[i] - 'a'];
            if (vis[s[i] - 'a'])
                continue;
            while (!ans.empty())
            {
                if (f[ans.back() - 'a'] == 0 || ans.back() > s[i])
                    break;
                vis[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            vis[s[i] - 'a'] = 1;
        }
        cout << ans << endl;
    }
    return 0;
}