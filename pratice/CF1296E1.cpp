#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> s;
    string s1, s2;
    int ans[n + 5] = {0};
    for (int i = 0; s[i]; i++)
    {
        if (s[i] >= s1.back())
        {
            s1.push_back(s[i]);
        }
        else if (s[i] >= s2.back())
        {
            s2.push_back(s[i]);
            ans[i] = 1;
        }
        else
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    int len = (int)s.size();
    for (int i = 0; i < len; i++)
        printf("%d", ans[i]);
    printf("\n");
    return 0;
}