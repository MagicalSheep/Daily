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
        scanf("%d", &n);
        scanf("%s", s + 1);
        int ans = 0x3f3f3f3f;
        for (int i = 'a'; i <= 'z'; i++)
        {
            bool isok = true;
            int l = 1, r = n, tmpans = 0;
            while (l < r)
            {
                if (s[l] == s[r])
                {
                    ++l, --r;
                    continue;
                }
                if (s[l] != i && s[r] != i)
                {
                    isok = false;
                    break;
                }
                ++tmpans;
                if (s[l] == i)
                    ++l;
                else
                    --r;
            }
            if (isok)
                ans = min(ans, tmpans);
        }
        if (ans == 0x3f3f3f3f)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}