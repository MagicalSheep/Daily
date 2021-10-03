#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 10;

int t;
char s[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s);
        int a = 0, b = 0, c = 0;
        for (int i = 0; s[i]; i++)
        {
            if (s[i] == 'A')
                ++a;
            else if (s[i] == 'B')
                ++b;
            else
                ++c;
        }
        if (b == a + c)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}