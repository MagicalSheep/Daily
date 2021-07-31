#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e3 + 10;
#define P1 1000000007
#define P2 1000000009
#define NUMBER 19560929

int T, n, c[MAXN], A[MAXN][MAXN], color[MAXN];
int cnt, head[MAXN];
ll xx1[MAXN], xx2[MAXN];

struct edge
{
    int to, next;
} Edge[MAXN << 1];

void init()
{
    memset(head, 0, sizeof(head));
    cnt = 0;
}

void addEdge(int u, int v)
{
    Edge[++cnt].to = v;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}

void dfs(int p, int st, int u, int &ans)
{
    if (color[c[u]] == 0)
        ++ans;
    ++color[c[u]];
    A[st][u] = ans;
    for (int e = head[u]; e; e = Edge[e].next)
    {
        int vv = Edge[e].to;
        if (vv == p)
            continue;
        dfs(u, st, vv, ans);
    }
    --color[c[u]];
    if (color[c[u]] == 0)
        --ans;
}

long long fpow_mod(long long x, long long n, long long m)
{
    x %= m;
    long long ans = 1;
    while (n)
    {
        if (n & 1)
            ans = ans * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return ans;
}

int f(int i, int P, int type)
{
    int ret = 0;
    for (int j = 1; j <= n; j++)
        ret = (ret + A[i][j] * ((type == 1) ? xx1[j] : xx2[j]) % P) % P;
    return ret;
}

int main()
{
    for (int i = 1; i <= 2000; i++)
    {
        xx1[i] = fpow_mod(NUMBER, i - 1, P1);
        xx2[i] = fpow_mod(NUMBER, i - 1, P2);
    }
    scanf("%d", &T);
    while (T--)
    {
        init();
        scanf("%d", &n);
        for (int i = 2; i <= n; i++)
        {
            int v;
            scanf("%d", &v);
            addEdge(i, v), addEdge(v, i);
        }
        for (int i = 1; i <= n; i++)
            scanf("%d", &c[i]);
        for (int i = 1; i <= n; i++)
        {
            int data = 0;
            dfs(i, i, i, data);
        }
        for (int i = 1; i <= n; i++)
            printf("%d %d\n", f(i, P1, 1), f(i, P2, 2));
    }
    return 0;
}