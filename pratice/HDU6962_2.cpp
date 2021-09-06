#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

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

/** Segment Tree Begin **/
template <typename T>
class SegTree
{
private:
    int siz; // tree size
    T *a;    // source data
    struct node
    {
        int l, r;
        // data you want to operate

        /** Example Begin **/
        T sum1, sum2, sum3, sum4, add1, add2, add3, add4;
        /** Example End **/
    } * tree;

    // Merge function
    void pushup(int p)
    {
        /** Example Begin **/
        tree[p].sum1 = tree[p << 1].sum1 + tree[p << 1 | 1].sum1;
        tree[p].sum2 = tree[p << 1].sum2 + tree[p << 1 | 1].sum2;
        tree[p].sum3 = tree[p << 1].sum3 + tree[p << 1 | 1].sum3;
        tree[p].sum4 = tree[p << 1].sum4 + tree[p << 1 | 1].sum4;
        /** Example End **/
    }

    void pushdown(int p)
    {
        /** Example Begin **/
        if (tree[p].add1)
        {
            tree[p << 1].add1 += tree[p].add1;
            tree[p << 1 | 1].add1 += tree[p].add1;
            tree[p << 1].sum1 += tree[p].add1;
            tree[p << 1 | 1].sum1 += tree[p].add1;
            tree[p].add1 = 0;
        }
        if (tree[p].add2)
        {
            tree[p << 1].add2 += tree[p].add2;
            tree[p << 1 | 1].add2 += tree[p].add2;
            tree[p << 1].sum2 += tree[p].add2;
            tree[p << 1 | 1].sum2 += tree[p].add2;
            tree[p].add2 = 0;
        }
        if (tree[p].add3)
        {
            tree[p << 1].add3 += tree[p].add3;
            tree[p << 1 | 1].add3 += tree[p].add3;
            tree[p << 1].sum3 += tree[p].add3;
            tree[p << 1 | 1].sum3 += tree[p].add3;
            tree[p].add3 = 0;
        }
        if (tree[p].add4)
        {
            tree[p << 1].add4 += tree[p].add4;
            tree[p << 1 | 1].add4 += tree[p].add4;
            tree[p << 1].sum4 += tree[p].add4;
            tree[p << 1 | 1].sum4 += tree[p].add4;
            tree[p].add4 = 0;
        }
        /** Example End **/
    }

public:
    SegTree(int max_size) { tree = (node *)calloc(max_size << 2, sizeof(node)); }
    SegTree(int max_size, T *arr) { tree = (node *)calloc(max_size << 2, sizeof(node)), this->a = arr; }

    void build(int p, int s, int t)
    {
        tree[p].l = s, tree[p].r = t;
        /** Example Begin **/
        tree[p].add1 = tree[p].add2 = tree[p].add3 = tree[p].add4 = 0;
        tree[p].sum1 = tree[p].sum2 = tree[p].sum3 = tree[p].sum4 = 0;
        /** Example End **/
        if (s == t)
        {
            // initialization
            return;
        }
        int mid = (s + t) >> 1;
        build(p << 1, s, mid), build(p << 1 | 1, mid + 1, t);
        pushup(p);
    }

    // Section update
    void update(int p, int s, int t, T add1, T add2, T add3, T add4)
    {
        if (tree[p].l >= s && tree[p].r <= t)
        {
            /** Example Begin **/
            tree[p].add1 += add1;
            tree[p].add2 += add2;
            tree[p].add3 += add3;
            tree[p].add4 += add4;
            tree[p].sum1 += add1;
            tree[p].sum2 += add2;
            tree[p].sum3 += add3;
            tree[p].sum4 += add4;
            /** Example End **/
            return;
        }
        pushdown(p);
        int mid = (tree[p].l + tree[p].r) >> 1;
        if (s <= mid)
            update(p << 1, s, t, add1, add2, add3, add4);
        if (t > mid)
            update(p << 1 | 1, s, t, add1, add2, add3, add4);
        pushup(p);
    }

    // Section query
    T query(int p, int x)
    {
        if (tree[p].l == tree[p].r)
        {
            T sum1 = tree[p].sum1 * x * x * x;
            T sum2 = tree[p].sum2 * x * x;
            T sum3 = tree[p].sum3 * x;
            T sum4 = tree[p].sum4;
            return sum1 + sum2 + sum3 + sum4;
        }
        pushdown(p);
        int mid = (tree[p].l + tree[p].r) >> 1;
        T sum = 0;
        if (x <= mid)
            sum = query(p << 1, x);
        else
            sum = query(p << 1 | 1, x);
        return sum;
    }
};
/** Segment Tree End **/

int n, q, o, a, b, x;
SegTree<ll> tr(MAXN);

/** Tree Link Begin **/
int tot, fa[MAXN], dep[MAXN], siz[MAXN], son[MAXN], top[MAXN], dfn[MAXN], rnk[MAXN];

void dfs1(int p)
{
    son[p] = -1;
    siz[p] = 1;
    for (int e = head[p]; e; e = Edge[e].next)
    {
        if (!dep[Edge[e].to])
        {
            dep[Edge[e].to] = dep[p] + 1;
            fa[Edge[e].to] = p;
            dfs1(Edge[e].to);
            siz[p] += siz[Edge[e].to];
            if (son[p] == -1 || siz[Edge[e].to] >= siz[son[p]])
                son[p] = Edge[e].to;
        }
    }
}

void dfs2(int p, int t)
{
    top[p] = t;
    dfn[p] = ++tot;
    rnk[tot] = p;
    if (son[p] == -1)
        return;
    dfs2(son[p], t);
    for (int e = head[p]; e; e = Edge[e].next)
        if (Edge[e].to != son[p] && Edge[e].to != fa[p])
            dfs2(Edge[e].to, Edge[e].to);
}

int LCA(int u, int v)
{
    int fu = top[u], fv = top[v];
    while (fu != fv)
    {
        if (dep[fu] < dep[fv])
            swap(u, v), swap(fu, fv);
        u = fa[fu];
        fu = top[u];
    }
    return dep[u] < dep[v] ? u : v;
}

void modify(int u, int v)
{
    int fu = top[u], fv = top[v], lca = LCA(u, v);
    int l = 1, r = dep[u] + dep[v] - 2 * dep[lca] + 1;
    ll x = 0;
    while (fu != fv)
    {
        if (dep[fu] >= dep[fv])
        {
            x = l + dfn[u];
            tr.update(1, dfn[fu], dfn[u], -1, 3 * x, -3 * x * x, x * x * x);
            l += dep[u] - dep[fu] + 1;
            u = fa[fu], fu = top[u];
        }
        else
        {
            x = dfn[fv] - r + (dep[v] - dep[fv] + 1) - 1;
            tr.update(1, dfn[fv], dfn[v], 1, -3 * x, 3 * x * x, -x * x * x);
            r -= (dep[v] - dep[fv] + 1);
            v = fa[fv], fv = top[v];
        }
    }
    if (dep[u] > dep[v])
    {
        x = l + dfn[u];
        tr.update(1, dfn[v], dfn[u], -1, 3 * x, -3 * x * x, x * x * x);
    }
    else
    {
        x = dfn[fv] - r + (dep[v] - dep[fv] + 1) - 1;
        tr.update(1, dfn[u], dfn[v], 1, -3 * x, 3 * x * x, -x * x * x);
    }
}
/** Tree Link End **/

int main()
{
    cin >> n;
    tr.build(1, 1, n);
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        addEdge(a, b), addEdge(b, a);
    }
    dep[1] = 1;
    dfs1(1), dfs2(1, 1);
    cin >> q;
    while (q--)
    {
        cin >> o;
        if (o == 1)
        {
            cin >> a >> b;
            modify(a, b);
        }
        else
        {
            cin >> x;
            cout << tr.query(1, dfn[x]) << endl;
        }
    }
    return 0;
}