#include <bits/stdc++.h>
using namespace std;

int t, n;

void solve(string &s)
{
    int i = 0, cnt = 0;
    for (; i + 1 < n;)
    {
        if (s[i] == '(' && s[i + 1] == ')' ||
            s[i] == '(' && s[i + 1] == '(' ||
            s[i] == ')' && s[i + 1] == ')')
        {
            i += 2;
            ++cnt;
            continue;
        }
        if (i == n - 2)
            break;
        for (int j = i + 2; j < n; j++)
        {
            if (s[j] == ')')
            {
                i = j + 1;
                ++cnt;
                goto end;
            }
        }
        break;
    end:;
    }
    cout << cnt << " " << n - i << endl;
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
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}