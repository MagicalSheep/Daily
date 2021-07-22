#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

/** Graph Data Structure Begin **/
int cnt, head[MAXN];

struct edge
{
    int to, next;
} Edge[MAXN << 1];

void addEdge(int u, int v)
{
    Edge[++cnt].to = v;
    Edge[cnt].next = head[u];
    head[u] = cnt;
}
/** Graph Data Structure End **/

int main()
{
    int u = 1, v = 2;
    addEdge(u, v);
    for (int e = head[u]; e; e = Edge[e].next)
    {
        // do sth
    }
    return 0;
}