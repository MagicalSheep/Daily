#include <algorithm>
#include <cstdio>
#include <deque>
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

/** Monotonous Queue Begin**/
template <typename T>
class MQ
{
private:
    deque<pair<int, T> > q;
    int index, siz, type;

public:
    const static int DEC = 0;
    const static int INC = 1;

    MQ() { index = 0, siz = -1, type = INC; }
    MQ(int type) { index = 0, siz = -1, this->type = type; }
    MQ(int size, int type) { index = 0, this->siz = size, this->type = type; }

    void push(T val)
    {
        while (!q.empty() && (((type == INC) && q.back().second >= val) || ((type == DEC) && q.back().second <= val)))
            q.pop_back();
        q.push_back(pair<int, T>(++index, val));
        if (siz > 0 && index >= siz && q.front().first < index - siz + 1)
            q.pop_front();
    }

    int size() { return q.size(); }

    bool empty() { return q.empty(); }

    T getans() { return q.front().second; }
};
/** Monotonous Queue End**/

const int MAXN = 2e6;

int N, K, in, mxans[MAXN];

int main()
{
    cin >> N >> K;
    MQ<int> q1(K, MQ<int>::INC), q2(K, MQ<int>::DEC);
    for (int i = 1; i <= N; i++)
    {
        cin >> in;
        q1.push(in), q2.push(in);
        if (i >= K)
        {
            cout << q1.getans() << " ";
            mxans[i] = q2.getans();
        }
    }
    cout << endl;
    for (int i = K; i <= N; i++)
        cout << mxans[i] << " ";
    cout << endl;
    return 0;
}