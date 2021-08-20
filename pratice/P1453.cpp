#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/* --------------- fast io begin--------------- */
namespace Fastio
{
    struct Reader
    {
        template <typename T>
        Reader &operator>>(T &x)
        {
            char c = getchar();
            T f = 1;
            while (c < '0' || c > '9')
            {
                if (c == '-')
                    f = -1;
                c = getchar();
            }
            x = 0;
            while (c >= '0' && c <= '9')
            {
                x = x * 10 + (c - '0');
                c = getchar();
            }
            x *= f;
            return *this;
        }
        Reader &operator>>(char &c)
        {
            c = getchar();
            while (c == '\n' || c == ' ')
                c = getchar();
            return *this;
        }
        Reader &operator>>(char *str)
        {
            int len = 0;
            char c = getchar();
            while (c == '\n' || c == ' ')
                c = getchar();
            while (c != '\n' && c != ' ')
            {
                str[len++] = c;
                c = getchar();
            }
            str[len] = '\0';
            return *this;
        }
        Reader() {}
    } cin;
    const char endl = '\n';
    struct Writer
    {
        template <typename T>
        Writer &operator<<(T x)
        {
            if (x == 0)
            {
                putchar('0');
                return *this;
            }
            if (x < 0)
            {
                putchar('-');
                x = -x;
            }
            static int sta[45];
            int top = 0;
            while (x)
            {
                sta[++top] = x % 10;
                x /= 10;
            }
            while (top)
            {
                putchar(sta[top] + '0');
                --top;
            }
            return *this;
        }
        Writer &operator<<(char c)
        {
            putchar(c);
            return *this;
        }
        Writer &operator<<(char *str)
        {
            int cur = 0;
            while (str[cur])
                putchar(str[cur++]);
            return *this;
        }
        Writer &operator<<(const char *str)
        {
            int cur = 0;
            while (str[cur])
                putchar(str[cur++]);
            return *this;
        }
        Writer() {}
    } cout;
} // namespace Fastio
#define cin Fastio ::cin
#define cout Fastio ::cout
#define endl Fastio ::endl
/* --------------- fast io end--------------- */

const int MAXN = 1e5 + 10;

/** Graph Data Structure Begin **/
int cnt, head[MAXN];

struct edge
{
    int to, next;
} Edge[MAXN << 1];

void addEdge(int u, int v)
{
    Edge[++cnt].to = v;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}
/** Graph Data Structure End **/

int n, vis[MAXN], fa[MAXN], root[2], p[MAXN], f[MAXN][2];
double k, ans;

void dp(int pa, int x)
{
    f[x][0] = 0, f[x][1] = p[x];
    for (int e = head[x]; e; e = Edge[e].next)
    {
        int v = Edge[e].to;
        if (v == pa)
            continue;
        dp(x, v);
        f[x][0] += max(f[v][0], f[v][1]);
        f[x][1] += f[v][0];
    }
}

inline int Find(int x)
{
    return (x == fa[x]) ? x : fa[x] = Find(fa[x]);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i], fa[i] = i;
    bool lock = false;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        ++u, ++v;
        if (!lock && Find(u) == Find(v))
        {
            root[0] = u, root[1] = v;
            lock = true;
            continue;
        }
        addEdge(u, v), addEdge(v, u);
        if (!lock)
            fa[Find(u)] = Find(v);
    }
    scanf("%lf", &k);
    dp(root[0], root[0]);
    ans = f[root[0]][0];
    dp(root[1], root[1]);
    ans = max(ans, 1.0 * f[root[1]][0]);
    printf("%.1f\n", ans * k);
    return 0;
}