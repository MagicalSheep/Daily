#include <bits/stdc++.h>
#define P 20071027
using namespace std;

char str[300000 + 10], word[100 + 10];
int nex[1000000][30], cnt, len, sign[1000000], f[300000 + 10], cases;

void insert(char *s)
{
    int l = strlen(s), p = 0;
    for (int i = 0; i < l; i++)
    {
        int c = s[i] - 'a';
        if (!nex[p][c])
            nex[p][c] = ++cnt;
        p = nex[p][c];
    }
    sign[p] = 1;
}

void solve()
{
    f[len] = 1;
    for (int i = len - 1; i >= 0; i--)
    {
        int l = len - i, p = 0;
        for (int j = i; j < i + l; j++)
        {
            int c = str[j] - 'a';
            if (!nex[p][c])
                break;
            p = nex[p][c];
            if (sign[p])
                f[i] = (f[i] + f[j + 1]) % P;
        }
    }
}

void init()
{
    memset(nex, 0, sizeof(nex));
    memset(sign, 0, sizeof(sign));
    memset(f, 0, sizeof(f));
    cnt = 0;
}

int main()
{
    while (scanf("%s", str) != EOF)
    {
        len = strlen(str);
        int S;
        scanf("%d", &S);
        for (int i = 1; i <= S; i++)
        {
            scanf("%s", word);
            insert(word);
        }
        solve();
        printf("Case %d: %d\n", ++cases, f[0]);
        init();
    }
    return 0;
}