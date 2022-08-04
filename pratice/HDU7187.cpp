#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 3e6 + 5;

/* --------------- fast io begin--------------- */
namespace Fread
{
    const int SIZE = 1 << 21;
    char buf[SIZE], *S, *T;
    inline char getchar()
    {
        if (S == T)
        {
            T = (S = buf) + fread(buf, 1, SIZE, stdin);
            if (S == T)
                return '\n';
        }
        return *S++;
    }
} // namespace Fread
namespace Fwrite
{
    const int SIZE = 1 << 21;
    char buf[SIZE], *S = buf, *T = buf + SIZE;
    inline void flush()
    {
        fwrite(buf, 1, S - buf, stdout);
        S = buf;
    }
    inline void putchar(char c)
    {
        *S++ = c;
        if (S == T)
            flush();
    }
    struct NTR
    {
        ~NTR() { flush(); }
    } ztr;
} // namespace Fwrite
#ifdef ONLINE_JUDGE
#define getchar Fread ::getchar
#define putchar Fwrite ::putchar
#endif
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

int T, n, k, p, s, t, dep[MAXN], depmx;

struct edge
{
    int u, v, w;
};

struct node
{
    ll dis;
    int u;
    bool operator>(const node &a) const { return dis > a.dis; }
};

vector<edge> g[MAXN];
ll dis[MAXN];
bool vis[MAXN];
priority_queue<node, vector<node>, greater<node>> q;

void dfs(int u, int fa)
{
    for (auto e : g[u])
    {
        int v = e.v;
        if (v == fa)
            continue;
        dep[v] = dep[u] + 1;
        depmx = max(depmx, dep[v]);
        dfs(v, u);
    }
}

void dijkstra(int n, int s)
{
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty())
    {
        int u = q.top().u;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto ed : g[u])
        {
            int v = ed.v;
            ll w = ed.w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}

int main()
{
    for (int i = 0; i < MAXN; i++)
        dis[i] = 1e16;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].emplace_back(edge{u, v, w});
            g[v].emplace_back(edge{v, u, w});
        }
        cin >> k >> p >> s >> t;
        dep[1] = 1, depmx = 1;
        dfs(1, 1);
        for (int i = 1; i <= n; i++)
        {
            g[i].emplace_back(edge{i, n + dep[i], 0});
            g[n + depmx + dep[i]].emplace_back(edge{n + depmx + dep[i], i, 0});
        }
        for (int i = 1; i <= depmx; i++)
        {
            if (i - k >= 1)
            {
                g[n + i].emplace_back(edge{n + i, n + depmx + i - k, p});
                g[n + depmx + i - k].emplace_back(edge{n + depmx + i - k, n + i, p});
            }
            if (i + k <= depmx)
            {
                g[n + i].emplace_back(edge{n + i, n + depmx + i + k, p});
                g[n + depmx + i + k].emplace_back(edge{n + depmx + i + k, n + i, p});
            }
        }
        dijkstra(n + 2 * depmx, s);
        cout << dis[t] << endl;
        for (int i = 1; i <= n + 2 * depmx; i++)
            vis[i] = 0, g[i].clear(), dis[i] = 1e16;
    }
    return 0;
}