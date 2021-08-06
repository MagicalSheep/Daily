#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int N, a[MAXN];

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + 1 + N);
    for (int i = 1; i <= N; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}