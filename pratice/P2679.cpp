#include <bits/stdc++.h>
typedef long long ll;
#define P 1000000007
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

const int MAXN = 1e3 + 5;
const int MAXM = 2e2 + 5;

int n, m, k, s, pre = 0, cur = 1;
char A[MAXN], B[MAXM];
ll f[2][MAXM][MAXM][2];

int main()
{
    cin >> n >> m >> k;
    cin >> A + 1 >> B + 1;
    for (int i = 1; i <= n; i++)
    {
        swap(pre, cur);
        f[cur][1][1][0] = s;
        if (A[i] == B[1])
            f[cur][1][1][1] = 1, s++;
        else
            f[cur][1][1][1] = 0;
        for (int j = 2; j <= m; j++)
        {
            for (int kk = 1; kk <= k; kk++)
            {
                if (A[i] == B[j])
                    f[cur][j][kk][1] = ((f[pre][j - 1][kk - 1][1] + f[pre][j - 1][kk][1]) % P + f[pre][j - 1][kk - 1][0] % P) % P;
                else
                    f[cur][j][kk][1] = 0;
                f[cur][j][kk][0] = (f[pre][j][kk][0] + f[pre][j][kk][1]) % P;
            }
        }
    }
    cout << (f[cur][m][k][1] + f[cur][m][k][0]) % P << endl;
    return 0;
}