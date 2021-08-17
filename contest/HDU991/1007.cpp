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

const int MAXN = 2e7 + 10;

int q, num;
char s[3];

bool hasdel[MAXN];
int belong[MAXN];
list<int> L, R;
int llen, rlen;

int main()
{
    cin >> q;
    while (q--)
    {
        cin >> s;
        if (s[0] == 'L')
        {
            L.emplace_front(++num);
            belong[num] = 1;
            ++llen;
        }
        else if (s[0] == 'R')
        {
            R.emplace_back(++num);
            belong[num] = 0;
            ++rlen;
        }
        else if (s[0] == 'G')
        {
            int x;
            cin >> x;
            hasdel[x] = true;
            if (belong[x])
                --llen;
            else
                --rlen;
        }
        else if (s[0] == 'Q')
        {
            while (hasdel[R.front()])
                R.pop_front();
            cout << R.front() << endl;
        }
        if (llen + 1 < rlen)
        {
            while (hasdel[R.front()])
                R.pop_front();
            L.emplace_back(R.front());
            belong[R.front()] = 1;
            R.pop_front();
            ++llen, --rlen;
        }
        else if (llen > rlen)
        {
            while (hasdel[L.back()])
                L.pop_back();
            R.emplace_front(L.back());
            belong[L.back()] = 0;
            L.pop_back();
            --llen, ++rlen;
        }
    }
    return 0;
}