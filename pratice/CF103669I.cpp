#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;

inline void print(char c, int cnt)
{
    for (int i = 1; i <= cnt; i++)
        putchar(c);
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &a, &b);
    int cnt = n - b;
    for (int i = 1; i <= n; i++)
    {
        print((cnt > 0) ? '1' : '0', m - a);
        print((cnt > 0) ? '0' : '1', a);
        --cnt;
        printf("\n");
    }
    return 0;
}