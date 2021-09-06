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

int T, cnt[26];
char t[MAXN], s[MAXN], ans[30], ansindex;

bool test(int slen)
{
    string tt, ss;
    for (int i = 0; i < slen; i++)
        ss.push_back(s[i]);
    int i = 0;
    while (ss.size())
    {
        tt.append(ss);
        ss.erase(remove(ss.begin(), ss.end(), ans[i]), ss.end());
        ++i;
    }
    if (strcmp(tt.c_str(), t) == 0)
        return true;
    return false;
}

int main()
{
    cin >> T;
    while (T--)
    {
        memset(cnt, 0, sizeof(cnt));
        ansindex = 0;
        cin >> t;
        int len = strlen(t);
        for (int i = len - 1; i >= 0; i--)
        {
            if (!cnt[t[i] - 'a'])
                ans[ansindex++] = t[i];
            cnt[t[i] - 'a']++;
        }
        ans[ansindex] = '\0';
        reverse(ans, ans + ansindex);
        int sum = 0;
        bool isok = true;
        for (int i = 0; i < ansindex; i++)
        {
            if (cnt[ans[i] - 'a'] % (i + 1) != 0)
            {
                isok = false;
                break;
            }
            sum += cnt[ans[i] - 'a'] / (i + 1);
        }
        if (!isok)
        {
            cout << "-1" << endl;
            continue;
        }
        for (int i = 0; i < sum; i++)
            s[i] = t[i];
        s[sum] = '\0';
        if (test(sum))
            cout << s << " " << ans << endl;
        else
            cout << "-1" << endl;
    }
    return 0;
}