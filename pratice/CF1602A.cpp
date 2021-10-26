#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;

int t;
char s[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s);
        int len = strlen(s);
        int mn = 0x3f3f3f3f, pos = 0;
        for (int i = 0; i < len; i++)
            if (mn > (int)s[i])
                pos = i, mn = (int)s[i];
        printf("%c ", (char)mn);
        for (int i = 0; i < len; i++)
        {
            if (i == pos)
                continue;
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}