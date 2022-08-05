#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 2e5 + 5;

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

ll t, n, m, ed[MAXN], mn, cnt[MAXN];
pair<ll, ll> a[MAXN];
unordered_map<ll, set<ll>> mp;
unordered_map<ll, ll> upd[MAXN];

void buy(int pid, int id)
{
    if (a[pid].first >= ed[id])
        ed[id] = a[pid].first + a[pid].second;
    else
        ed[id] += a[pid].second;
}

void update(int pid)
{
    while (mp[mn].empty())
        ++mn;
    auto &vec = upd[pid];
    for (auto v : vec)
    {
        mp[cnt[v.first]].erase(v.first);
        cnt[v.first] -= v.second;
        mp[cnt[v.first]].insert(v.first);
        if (cnt[v.first] < mn)
            mn = cnt[v.first];
    }
    vec.clear();
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i].first >> a[i].second;
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= m; i++)
            mp[0].insert(i), cnt[i] = 0, ed[i] = 0, mn = 0;
        for (int i = 1; i <= n; i++)
        {
            update(i);
            auto &p = mp[mn];
            auto store = *(p.begin());
            buy(i, store);
            int id = lower_bound(a + 1, a + 1 + n, pair<ll, ll>(ed[store], 0)) - a;
            if (id <= n)
                upd[id][store] += 1;
            mp[cnt[store]].erase(store);
            cnt[store]++;
            mp[cnt[store]].insert(store);
        }
        ll ans = 0;
        for (int i = 1; i <= m; i++)
            ans = max(ans, ed[i]);
        cout << ans << endl;
        for (auto &v : mp)
            v.second.clear();
    }
    return 0;
}