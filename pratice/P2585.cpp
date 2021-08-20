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

const int MAXN = 5e5 + 10;

int ind = 1, f[MAXN][3], g[MAXN][3];

void dp(int x)
{
    f[x][0] = 1, f[x][1] = f[x][2] = 0;
    g[x][0] = 1, g[x][1] = g[x][2] = 0;
    int sonsiz = getchar() - '0', son[2] = {0};
    for (int i = 0; i < sonsiz; i++)
        son[i] = ++ind, dp(ind);
    if (sonsiz == 1)
    {
        f[x][0] += max(f[son[0]][1], f[son[0]][2]);
        f[x][1] += max(f[son[0]][0], f[son[0]][2]);
        f[x][2] += max(f[son[0]][0], f[son[0]][1]);
        g[x][0] += min(g[son[0]][1], g[son[0]][2]);
        g[x][1] += min(g[son[0]][0], g[son[0]][2]);
        g[x][2] += min(g[son[0]][0], g[son[0]][1]);
    }
    else if (sonsiz == 2)
    {
        f[x][0] += max(f[son[0]][1] + f[son[1]][2], f[son[0]][2] + f[son[1]][1]);
        f[x][1] += max(f[son[0]][0] + f[son[1]][2], f[son[0]][2] + f[son[1]][0]);
        f[x][2] += max(f[son[0]][0] + f[son[1]][1], f[son[0]][1] + f[son[1]][0]);
        g[x][0] += min(g[son[0]][1] + g[son[1]][2], g[son[0]][2] + g[son[1]][1]);
        g[x][1] += min(g[son[0]][0] + g[son[1]][2], g[son[0]][2] + g[son[1]][0]);
        g[x][2] += min(g[son[0]][0] + g[son[1]][1], g[son[0]][1] + g[son[1]][0]);
    }
}

int main()
{
    dp(1);
    cout << max(f[1][0], max(f[1][1], f[1][2])) << " "
         << min(g[1][0], min(g[1][1], g[1][2])) << endl;
    return 0;
}