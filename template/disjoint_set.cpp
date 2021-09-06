#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

/** Disjoint Set Begin **/
namespace DSet
{
    int fa[MAXN];

    void makeSet(int size)
    {
        for (int i = 0; i < size; i++)
            fa[i] = i;
    }

    int find(int x) { return (x == fa[x]) ? x : fa[x] = find(fa[x]); }

    void unionSet(int x, int y) { fa[find(x)] = find(y); }
}
/** Disjoint Set End **/

int main()
{
    DSet::makeSet(200);

    int n;
    scanf("%d", &n);
    int u, v;
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &u, &v), DSet::unionSet(u, v);

    printf("%d\n", DSet::find(5));

    return 0;
}