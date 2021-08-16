#include <bits/stdc++.h>
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

const int MAXN = 2e5 + 10;

struct element
{
    int a, b, c, ans, cnt;
} E[MAXN], E2[MAXN];

bool cmp1(element &a, element &b)
{
    if (a.a == b.a)
    {
        if (a.b == b.b)
            return a.c < b.c;
        else
            return a.b < b.b;
    }
    else
    {
        return a.a < b.a;
    }
}

bool cmp2(element &a, element &b)
{
    if (a.b == b.b)
        return a.c < b.c;
    else
        return a.b < b.b;
}

int n, k, nn, top;
int tr[MAXN], ans[MAXN];

inline void add(int x, int v)
{
    for (; x <= k; x += lowbit(x))
        tr[x] += v;
}

inline int getsum(int x)
{
    int ret = 0;
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
    sort(E2 + l, E2 + mid + 1, cmp2);
    sort(E2 + mid + 1, E2 + r + 1, cmp2);
    int j = l;
    for (int i = mid + 1; i <= r; i++)
    {
        while (E2[j].b <= E2[i].b && j <= mid)
            add(E2[j].c, E2[j].cnt), j++;
        E2[i].ans += getsum(E2[i].c);
    }
    for (int i = l; i < j; i++)
        add(E2[i].c, -E2[i].cnt);
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> E[i].a >> E[i].b >> E[i].c;
    sort(E + 1, E + 1 + n, cmp1);
    for (int i = 1; i <= n; i++)
    {
        ++top;
        if (E[i].a != E[i + 1].a || E[i].b != E[i + 1].b || E[i].c != E[i + 1].c)
            ++nn, E2[nn] = E[i], E2[nn].cnt = top, top = 0;
    }
    solve(1, nn);
    for (int i = 1; i <= nn; i++)
        ans[E2[i].ans + E2[i].cnt - 1] += E2[i].cnt;
    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
    return 0;
}