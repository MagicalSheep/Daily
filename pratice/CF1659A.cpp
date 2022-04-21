#include <bits/stdc++.h>
using namespace std;

int t, n, r, b;

inline void print(char c, int cnt)
{
    for (int i = 1; i <= cnt; i++)
        putchar(c);
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &r, &b);
        while (r > 0)
        {
            int cnt = ceil(1.0 * r / (b + 1));
            print('R', cnt);
            if (b > 0)
                putchar('B');
            --b;
            r -= cnt;
        }
        printf("\n");
    }
    return 0;
}