#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 5;

int t, n;
char ma[2][MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        scanf("%s%s", ma[0], ma[1]);
        bool isok = true;
        for (int i = 0; i < n; i++)
        {
            if (ma[0][i] == '1' && ma[1][i] == '1')
            {
                isok = false;
                break;
            }
        }
        printf((isok) ? "YES\n" : "NO\n");
    }
    return 0;
}