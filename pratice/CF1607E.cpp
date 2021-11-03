#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int t, n, m;
char s[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        int ansr = 1, ansc = 1;
        int curr = 1, curc = 1;
        int mxd = 1, mxr = 1;
        for (int i = 1; i <= len; i++)
        {
            if (s[i] == 'L')
            {
                if (curc == 1)
                {
                    if (mxr == m)
                        break;
                    ansc++;
                    curc++;
                    mxr++;
                }
                curc--;
            }
            else if (s[i] == 'R')
            {
                if (curc == m)
                    break;
                curc++;
                mxr = max(mxr, curc);
            }
            else if (s[i] == 'U')
            {
                if (curr == 1)
                {
                    if (mxd == n)
                        break;
                    ansr++;
                    curr++;
                    mxd++;
                }
                curr--;
            }
            else
            {
                if (curr == n)
                    break;
                curr++;
                mxd = max(mxd, curr);
            }
        }
        printf("%d %d\n", ansr, ansc);
    }
    return 0;
}