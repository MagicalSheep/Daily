#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define P 1000000007

int t, f[100 + 10][2600 + 10];

int main()
{
    for (int i = 1; i <= 26; i++)
        f[1][i] = 1;
    for (int i = 2; i <= 100; i++)
        for (int j = 1; j <= 2600; j++)
            for (int k = 1; k <= min(j, 26); k++)
                f[i][j] = (f[i][j] + f[i - 1][j - k]) % P;
    scanf("%d", &t);
    while (t--)
    {
        char str[100 + 10];
        scanf("%s", str);
        int len = strlen(str);
        int sum = 0;
        for (int i = 0; i < len; i++)
            sum += str[i] - 'a' + 1;
        printf("%d\n", f[len][sum] - 1);
    }
    return 0;
}