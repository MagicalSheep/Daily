#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 5;

int t, k;
char a[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &k);
        scanf("%s", a + 1);
        int cnt[10] = {0}, pos[10] = {0};
        for (int i = 1; i <= k; i++)
        {
            cnt[a[i] - '0']++;
            if (pos[a[i] - '0'] == 0)
                pos[a[i] - '0'] = i;
        }
        if (cnt[1])
            printf("1\n1\n");
        else if (cnt[4])
            printf("1\n4\n");
        else if (cnt[6])
            printf("1\n6\n");
        else if (cnt[8])
            printf("1\n8\n");
        else if (cnt[9])
            printf("1\n9\n");
        else if (cnt[2] >= 2)
            printf("2\n22\n");
        else if (cnt[3] >= 2)
            printf("2\n33\n");
        else if (cnt[5] >= 2)
            printf("2\n55\n");
        else if (cnt[7] >= 2)
            printf("2\n77\n");
        else if (cnt[2] && (a[1] - '0') != 2)
            printf("2\n%d2\n", a[1] - '0');
        else if (cnt[5] && (a[1] - '0') != 5)
            printf("2\n%d5\n", a[1] - '0');
        else if (cnt[2] && cnt[7] && pos[2] < pos[7])
            printf("2\n27\n");
        else
            printf("2\n57\n");
    }
    return 0;
}