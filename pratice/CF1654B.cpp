#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int cnt[256] = {0}, ans = 0x3f3f3f3f;
        for (int i = s.size() - 1; i >= 0; i--)
            if (!cnt[s[i]])
                cnt[s[i]] = 1, ans = min(ans, i);
        for (int i = ans; i < s.size(); i++)
            putchar(s[i]);
        cout << endl;
    }
    return 0;
}