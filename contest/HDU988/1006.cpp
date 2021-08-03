#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 10;

int T, n, A[MAXN];
ll tot;

void buildtree(int L, int R)
{
    if (L > R)
        return;
    ++tot;
    if (L == R)
        return;
    if (R - L + 1 == 1)
    {
        int mid = (L + R) / 2;
        buildtree(L, L);
        buildtree(R, R);
    }
    else
    {
        int B = L + ceil((R - L + 1) / 3) - 1;
        int C = (B + R) / 2;
        buildtree(L, B);
        buildtree(B + 1, C);
        buildtree(C + 1, R);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        tot = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &A[i]);
        buildtree(1, n);
        printf("%d\n", tot);
    }
    return 0;
}