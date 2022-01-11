#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int t, n;
char s[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%s", &n, s);
        int len = strlen(s);
        string ans1, ans2;
        ans1.push_back(s[0]);
        ans2.push_back(s[0]);
        for (int i = 1; i < len; i++)
        {
            if (s[i] > s[i - 1])
                break;
            if (i == 1 && s[i] == s[i - 1])
                break;
            ans1.push_back(s[i]);
            ans2.push_back(s[i]);
        }
        reverse(ans2.begin(), ans2.end());
        string ans = ans1 + ans2;
        printf(ans.c_str());
        printf("\n");
    }
    return 0;
}