#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 5;
#define INF 0x3f3f3f3f

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

ll t, n, q;

struct town
{
    ll x, y, w;

    bool operator<(const town &b) const
    {
        return w < b.w;
    };

} towns[MAXN];

const int maxlog = 20;
ll f1[MAXN][maxlog + 5], f2[MAXN][maxlog + 5], f3[MAXN][maxlog + 5], f4[MAXN][maxlog + 5], logn[MAXN];

void init()
{
    for (int i = 1; i <= n; i++)
        f1[i][0] = f2[i][0] = towns[i].x, f3[i][0] = f4[i][0] = towns[i].y;
    for (int j = 1; j <= maxlog; j++)
    {
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            f1[i][j] = max(f1[i][j - 1], f1[i + (1 << (j - 1))][j - 1]);
            f2[i][j] = min(f2[i][j - 1], f2[i + (1 << (j - 1))][j - 1]);
            f3[i][j] = max(f3[i][j - 1], f3[i + (1 << (j - 1))][j - 1]);
            f4[i][j] = min(f4[i][j - 1], f4[i + (1 << (j - 1))][j - 1]);
        }
    }
}

ll query1(int l, int r)
{
    ll j = logn[r - l + 1];
    return max(f1[l][j], f1[r - (1 << j) + 1][j]);
}

ll query2(int l, int r)
{
    ll j = logn[r - l + 1];
    return min(f2[l][j], f2[r - (1 << j) + 1][j]);
}

ll query3(int l, int r)
{
    ll j = logn[r - l + 1];
    return max(f3[l][j], f3[r - (1 << j) + 1][j]);
}

ll query4(int l, int r)
{
    ll j = logn[r - l + 1];
    return min(f4[l][j], f4[r - (1 << j) + 1][j]);
}

ll mxd(int l, int r, int x, int y)
{
    ll d1 = abs(x - query1(l, r));
    ll d2 = abs(x - query2(l, r));
    ll d3 = abs(y - query3(l, r));
    ll d4 = abs(y - query4(l, r));
    return max(d1, max(d2, max(d3, d4)));
}

ll solve(int l, int r, int x, int y)
{
    if (l > r)
        return 0;
    int mid = (l + r) >> 1;
    ll d = mxd(mid, r, x, y);
    if (towns[mid].w < d)
        return max(towns[mid].w, solve(mid + 1, r, x, y));
    return max(d, solve(l, mid - 1, x, y));
}

int main()
{
    logn[0] = -1;
    for (int i = 1; i < MAXN; i++)
        logn[i] = logn[i >> 1] + 1;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
            cin >> towns[i].x >> towns[i].y >> towns[i].w;
        sort(towns + 1, towns + 1 + n);
        for (int i = 1; i <= n; i++)
        {
            int t1 = towns[i].x + towns[i].y;
            int t2 = towns[i].x - towns[i].y;
            towns[i].x = t1;
            towns[i].y = t2;
        }
        init();
        while (q--)
        {
            int x, y;
            cin >> x >> y;
            cout << solve(1, n, x + y, x - y) << endl;
        }
    }
    return 0;
}