#include <bits/stdc++.h>
using namespace std;

int t, n;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        char num[10 + 5] = {0}, num1[10 + 5] = {0}, num2[10 + 5] = {0};
        scanf("%d", &n);
        itoa(n, num, 10);
        int len1 = 0, len2 = 0;
        for (int i = 0; num[i]; i++)
            if (i & 1)
                num1[len1++] = num[i];
            else
                num2[len2++] = num[i];
        int a = atoi(num1);
        int b = atoi(num2);
        printf("%d\n", (a + 1) * (b + 1) - 2);
    }
    return 0;
}