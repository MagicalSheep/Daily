#include <bits/stdc++.h>
using namespace std;

int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int P;
        scanf("%d", &P);
        if (P == 5)
        {
            printf("2 4\n");
            continue;
        }
        printf("2 %d\n", (P - 1) / 2);
    }
    return 0;
}