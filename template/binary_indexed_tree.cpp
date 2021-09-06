#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

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

int main()
{
    int n;
    scanf("%d", &n);
    BIT::size = n;

    BIT::add(4, 2);

    BIT::getsum(5);

    return 0;
}