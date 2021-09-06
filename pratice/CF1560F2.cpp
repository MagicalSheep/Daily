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

int t, k, dignum;
bool vis[10];
char n[15], ans[15];

bool dfs(int ind, int *num, int len, bool isok)
{
    if (ind == dignum)
        return true;

    if (len < k)
    {
        int new_num[k] = {0}, new_num_len = len;
        for (int i = 0; i < len; i++)
            new_num[i] = num[i];
        if (!vis[n[ind] - '0'])
            new_num[new_num_len++] = n[ind] - '0', vis[n[ind] - '0'] = true;
        ans[ind] = n[ind];
        if (dfs(ind + 1, new_num, new_num_len, isok))
            return true;
        if (new_num_len != len)
            vis[n[ind] - '0'] = false;

        for (int i = 0; i < len; i++)
            new_num[i] = num[i];
        if (vis[n[ind] - '0' + 1])
            new_num[len] = 0;
        else
            new_num[len] = n[ind] - '0' + 1;
        ans[ind] = n[ind] + 1;
        return dfs(ind + 1, new_num, len + 1, true);
    }

    sort(num, num + len);
    if (isok)
    {
        ans[ind] = num[0] + '0';
        return dfs(ind + 1, num, len, isok);
    }
    for (int i = 0; i < len; i++)
    {
        if (num[i] >= n[ind] - '0')
        {
            ans[ind] = num[i] + '0';
            if (dfs(ind + 1, num, len, num[i] > n[ind] - '0'))
                return true;
        }
    }
    return false;
}

int main()
{
    cin >> t;
    while (t--)
    {
        memset(vis, 0, sizeof(vis));
        cin >> n >> k;
        dignum = strlen(n);
        ans[dignum] = '\0';
        int num[k] = {0};
        dfs(0, num, 0, false);
        cout << atoll(ans) << endl;
    }
    return 0;
}