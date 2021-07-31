#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int N, pi[MAXN];
char str[MAXN];

void prework()
{
    int i = 0, j = -1;
    pi[0] = -1;
    while (i < N)
    {
        if (j == -1 || str[i] == str[j])
            pi[++i] = ++j;
        else
            j = pi[j];
    }
}

int main()
{
    int cases = 0;
    while (1)
    {
        scanf("%d", &N);
        if (N == 0)
            break;
        scanf("%s", str);
        printf("Test case #%d\n", ++cases);
        prework();
        for (int i = 1; i <= N; i++)
        {
            if (pi[i] > 0 && i % (i - pi[i]) == 0)
                printf("%d %d\n", i, i / (i - pi[i]));
        }
        memset(pi, 0, sizeof(pi));
        printf("\n");
    }
    return 0;
}