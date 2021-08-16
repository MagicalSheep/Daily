#include <bits/stdc++.h>
typedef long long ll;
#define lowbit(x) ((x) & (-x))
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

int n, m, rnk[MAXN];
ll tr[MAXN], ans[MAXN];

struct element
{
    int id, val, t;
    ll ans1, ans2;
} E[MAXN];

bool cmp1(element a, element b) { return a.t < b.t; }
bool cmp2(element a, element b) { return a.val < b.val; }
bool cmp3(element a, element b) { return a.id < b.id; }
bool cmp4(element a, element b) { return a.t > b.t; }

inline void add(int x, int v)
{
    for (; x <= n; x += lowbit(x))
        tr[x] += v;
}

inline ll getsum(int x)
{
    ll ret = 0;
    for (; x; x -= lowbit(x))
        ret += tr[x];
    return ret;
}

void solve(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    solve(l, mid), solve(mid + 1, r);
    sort(E + l, E + mid + 1, cmp2);
    sort(E + mid + 1, E + r + 1, cmp2);
    int j = l;
    for (int i = mid + 1; i <= r; i++)
    {
        while (E[j].val < E[i].val && j <= mid)
            add(E[j].id, 1), j++;
        E[i].ans1 += (getsum(n) - getsum(E[i].id));
    }
    for (int i = l; i < j; i++)
        add(E[i].id, -1);
}

void solve2(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    solve2(l, mid), solve2(mid + 1, r);
    sort(E + l, E + mid + 1, cmp3);
    sort(E + mid + 1, E + r + 1, cmp3);
    int j = l;
    for (int i = mid + 1; i <= r; i++)
    {
        while (E[j].id < E[i].id && j <= mid)
            add(E[j].val, 1), j++;
        E[i].ans2 += (getsum(n) - getsum(E[i].val));
    }
    for (int i = l; i < j; i++)
        add(E[i].val, -1);
}

int main()
{
    // freopen("C:\\Users\\CSUACM29\\Downloads\\P3157_1.in", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> E[i].val, E[i].id = i, rnk[E[i].val] = i;
    for (int i = m; i >= 1; i--)
    {
        int sc;
        cin >> sc;
        E[rnk[sc]].t = i;
    }
    sort(E + 1, E + 1 + n, cmp1);
    solve(1, n);
    sort(E + 1, E + 1 + n, cmp1);
    solve2(1, n);
    sort(E + 1, E + 1 + n, cmp4);
    for (int i = 1; i <= m; i++)
        ans[m - i + 1] = E[i].ans1 + E[i].ans2;
    for (int i = 1; i <= m; i++)
        ans[i] += ans[i - 1];
    for (int i = m; i >= 1; i--)
        cout << ans[i] << endl;
    return 0;
}