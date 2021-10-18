#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 20 + 5;

int t;
char n[MAXN];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", n + 1);
        int len = strlen(n + 1);
        int ans = 0x3f3f3f3f;
        for (int i = len; i >= 1; i--)
        {
            for (int j = i - 1; j >= 1; j--)
            {
                if (n[i] == '5' && (n[j] == '2' || n[j] == '7'))
                {
                    ans = min(ans, len - j - 1);
                    break;
                }
                if (n[i] == '0' && (n[j] == '0' || n[j] == '5'))
                {
                    ans = min(ans, len - j - 1);
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}