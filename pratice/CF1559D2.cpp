#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
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

const int MAXN = 1e5 + 5;

int n, m1, m2, cnt1, cnt2;
int fa1[MAXN], fa2[MAXN];

int Find1(int x)
{
    if (x != fa1[x])
        fa1[x] = Find1(fa1[x]);
    return fa1[x];
}

void unionSet1(int x, int y)
{
    x = Find1(x);
    y = Find1(y);
    fa1[x] = y;
}

int Find2(int x)
{
    if (x != fa2[x])
        fa2[x] = Find2(fa2[x]);
    return fa2[x];
}

void unionSet2(int x, int y)
{
    x = Find2(x);
    y = Find2(y);
    fa2[x] = y;
}

int main()
{
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= n; i++)
        fa1[i] = i, fa2[i] = i, cnt1 = n, cnt2 = n;
    for (int i = 1; i <= m1; i++)
    {
        int u, v;
        cin >> u >> v;
        unionSet1(u, v);
    }
    for (int i = 1; i <= m2; i++)
    {
        int u, v;
        cin >> u >> v;
        unionSet2(u, v);
    }
    vector<pair<int, int>> ans;
    vector<int> v1, v2;
    for (int i = 2; i <= n; i++)
    {
        if (Find1(1) != Find1(i) && Find2(1) != Find2(i))
        {
            unionSet1(1, i);
            unionSet2(1, i);
            ans.emplace_back(pair<int, int>(1, i));
        }
        if (Find1(i) != Find1(1))
            v1.emplace_back(i);
        if (Find2(i) != Find2(1))
            v2.emplace_back(i);
    }
    while (v1.size() && v2.size())
    {
        if (Find1(v1.back()) == Find1(1))
        {
            v1.pop_back();
            continue;
        }
        if (Find2(v2.back()) == Find2(1))
        {
            v2.pop_back();
            continue;
        }
        ans.emplace_back(pair<int, int>(v1.back(), v2.back()));
        unionSet1(v1.back(), v2.back());
        unionSet2(v1.back(), v2.back());
    }
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x.first << " " << x.second << endl;
    return 0;
}