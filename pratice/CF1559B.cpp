#include <bits/stdc++.h>
using namespace std;

int t, n;
string ans;

void solve(char l, char r, int len)
{
    char c[2] = {'B', 'R'};
    if (l != 0)
    {
        int a = (l == 'B') ? 1 : 0;
        int b = (l == 'B') ? 0 : 1;
        for (int i = 1; i <= len; i++)
            ans.push_back(c[a]), swap(a, b);
    }
    else if (r != 0)
    {
        int a, b;
        if (r == 'R')
        {
            a = (len % 2) ? 0 : 1;
            b = (len % 2) ? 1 : 0;
        }
        else
        {
            a = (len % 2) ? 1 : 0;
            b = (len % 2) ? 0 : 1;
        }
        for (int i = 1; i <= len; i++)
            ans.push_back(c[a]), swap(a, b);
    }
    else
    {
        int a = 0, b = 1;
        for (int i = 1; i <= len; i++)
            ans.push_back(c[a]), swap(a, b);
    }
}

int main()
{
    cin >> t;
    while (t--)
    {
        char l = 0, r = 0, len = 0, c;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> c;
            if (c != '?')
            {
                if (len != 0)
                {
                    r = c;
                    solve(l, r, len);
                    len = 0;
                }
                ans.push_back(c);
                l = c;
                continue;
            }
            ++len;
        }
        if (c == '?')
            solve(l, r, len);
        cout << ans << endl;
        ans.clear();
    }
    return 0;
}