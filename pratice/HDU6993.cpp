#include <bits/stdc++.h>
using namespace std;

int T;

int main()
{
    int cases = 0;
    scanf("%d", &T);
    while (T--)
    {
        char str[500 + 10];
        int ma[500 + 10] = {0};
        for (int i = 1; i <= 30; i++)
        {
            scanf("%s", str);
            for (int j = 0; j < 100; j++)
                if (str[j] == '#')
                    ma[j + 1] = 1;
        }
        printf("Case #%d:\n", ++cases);
        int cnt = 7, ansl[10], ansr[10];
        bool right = false;
        for (int i = 100; i >= 1; i--)
        {
            if (ma[i] == 1 && !right)
                ansr[cnt] = i, right = true;
            if (ma[i] == 0 && right)
                ansl[cnt--] = i + 1, right = false;
            if (right && cnt == 1)
                break;
        }
        for (int i = 1; i <= 100; i++)
        {
            if (ma[i] == 1)
            {
                ansl[cnt] = i;
                break;
            }
        }
        for (int i = 1; i <= 7; i++)
            printf("%d %d\n", ansl[i], ansr[i]);
    }
    return 0;
}