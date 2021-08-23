#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

/** Binary Indexed Tree Begin **/
namespace BIT
{
    int tr[MAXN], size;

    void clear() { memset(tr, 0, sizeof(tr)); }

    // note: set size before adding
    void add(int k, int v)
    {
        for (; k <= size; k += ((k) & (-k)))
            tr[k] += v;
    }

    int getsum(int k)
    {
        int ret = 0;
        for (; k; k -= ((k) & (-k)))
            ret += tr[k];
        return ret;
    }
}
/** Binary Indexed Tree End **/

/** CDQ Begin **/
namespace CDQ
{
    struct element
    {
        int a, b, c;
        int cnt;
        int ans;
    } E[MAXN];
    int len;

    bool cmp_a(element x, element y)
    {
        if (x.a == y.a)
        {
            if (x.b == y.b)
                return x.c < y.c;
            else
                return x.b < y.b;
        }
        else
        {
            return x.a < y.a;
        }
    }
    bool cmp_b(element x, element y)
    {
        if (x.b == y.b)
            return x.c < y.c;
        else
            return x.b < y.b;
    }

    // write init function
    // init E[i].a, E[i].b, E[i].c, E[i].cnt
    template <typename T>
    void init(T *arr, int element_len, int bitsize)
    {
        len = element_len;
        BIT::size = bitsize;

        /** Example Begin **/
        for (int i = 1; i <= len; i++)
            E[i].a = arr[i].a, E[i].b = arr[i].b, E[i].c = arr[i].c, E[i].cnt = arr[i].cnt;
        /** Example End **/
    }

    void solve(int l, int r)
    {
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        solve(l, mid), solve(mid + 1, r);
        sort(E + l, E + mid + 1, cmp_b);
        sort(E + mid + 1, E + r + 1, cmp_b);
        int j = l;
        for (int i = mid + 1; i <= r; i++)
        {
            while (E[j].b <= E[i].b && j <= mid)
                BIT::add(E[j].c, E[j].cnt), j++;
            E[i].ans += BIT::getsum(E[i].c);
        }
        for (int i = l; i < j; i++)
            BIT::add(E[i].c, -E[i].cnt);
    }

    // ansindex from 0
    void getans(int *ans)
    {
        sort(E + 1, E + 1 + len, cmp_a);
        solve(1, len);
        for (int i = 1; i <= len; i++)
            ans[E[i].ans + E[i].cnt - 1] += E[i].cnt;
    }
}
/** CDQ End **/

// test variable begin
int n, k, ans[MAXN];

struct element
{
    int a, b, c, cnt;
} E[MAXN], E2[MAXN];

bool cmp(element x, element y)
{
    if (x.a == y.a)
    {
        if (x.b == y.b)
            return x.c < y.c;
        else
            return x.b < y.b;
    }
    else
    {
        return x.a < y.a;
    }
}
// test variable end

int main()
{
    // 三维偏序

    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        cin >> E[i].a >> E[i].b >> E[i].c;
    // prework begin
    sort(E + 1, E + 1 + n, cmp);
    int top = 0, elen = 0;
    for (int i = 1; i <= n; i++)
    {
        ++top;
        if (E[i].a != E[i + 1].a || E[i].b != E[i + 1].b || E[i].c != E[i + 1].c)
            ++elen, E2[elen] = E[i], E2[elen].cnt = top, top = 0;
    }
    // prework end
    CDQ::init(E2, elen, k);
    CDQ::getans(ans);
    for (int i = 0; i < n; i++)
        printf("%d\n", ans[i]);
    return 0;
}