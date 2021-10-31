#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 5;

int t;
char s[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        int a = 0, b = 0;
        for (int i = 2; i <= len; i++)
        {
            if (s[i - 1] == 'a' && s[i] == 'b')
                ++a;
            else if (s[i - 1] == 'b' && s[i] == 'a')
                ++b;
        }
        if (a == b)
        {
            printf("%s\n", s + 1);
            continue;
        }
        s[len] = (s[len] == 'a') ? 'b' : 'a';
        printf("%s\n", s + 1);
    }
    return 0;
}
