#include <cstdio>
#include <string.h>
typedef long long ll;
using namespace std;

int N, cases;
ll ans;
int nex[4000000][80], cnt, val[4000000], tail[4000000];
char str[1000 + 10];

ll insert(char *s, int l)
{
    int p = 0;
    ll sum = 0;
    for (int i = 0; i < l; i++)
    {
        int c = s[i] - '0';
        if (!nex[p][c])
            nex[p][c] = ++cnt;
        p = nex[p][c];
        sum += val[p];
        ++val[p];
    }
    sum *= 2;
    sum += tail[p];
    ++tail[p];
    return sum;
}

int main()
{
    while (scanf("%d", &N) != EOF && N)
    {
        ans = N * (N - 1) / 2;
        for (int i = 1; i <= N; i++)
        {
            scanf("%s", str);
            int len = strlen(str);
            ans += insert(str, len);
        }
        printf("Case %d: %lld\n", ++cases, ans);
        ans = cnt = 0;
        memset(nex, 0, sizeof(nex));
        memset(val, 0, sizeof(val));
        memset(tail, 0, sizeof(tail));
    }
    return 0;
}