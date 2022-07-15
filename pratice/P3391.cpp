#include <bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff

struct Splay
{
    struct node_t
    {
        int val, siz, flag;
        node_t *son[2], *parent, **rt;

        node_t(const int &val, node_t *parent, node_t **rt) : val(val), parent(parent), son{NULL, NULL}, flag(0), siz(1), rt(rt) {}

        ~node_t()
        {
            if (son[0])
                delete son[0];
            if (son[1])
                delete son[1];
        }

        inline void pushdown()
        {
            if (!flag)
                return;
            if (son[0])
                son[0]->flag ^= 1;
            if (son[1])
                son[1]->flag ^= 1;
            swap(son[0], son[1]);
            flag = 0;
        }

        inline void maintain()
        {
            siz = 1;
            if (son[0])
                siz += son[0]->siz;
            if (son[1])
                siz += son[1]->siz;
        }

        inline int relation()
        {
            return this == parent->son[1];
        }

        void rotate()
        {
            if (!parent)
                return;
            node_t *y = parent, *z = y->parent;
            y->pushdown();
            pushdown();
            if (z)
                z->son[y->relation()] = this;
            int chk = relation();
            y->son[chk] = son[chk ^ 1];
            if (son[chk ^ 1])
                son[chk ^ 1]->parent = y;
            son[chk ^ 1] = y;
            y->parent = this;
            parent = z;
            y->maintain();
            maintain();
        }

        node_t *splay(node_t *target = NULL)
        {
            while (parent != target)
            {
                if (parent->parent == target)
                    rotate();
                else if (relation() == parent->relation())
                    parent->rotate(), rotate();
                else
                    rotate(), rotate();
            }
            return this;
        }
    };

    node_t *rt = NULL;

    void insert(const int &val)
    {
        if (!rt)
        {
            rt = new node_t(val, NULL, NULL), rt->rt = &rt;
            return;
        }
        node_t **ptr = &rt, *parent = NULL;
        while (*ptr)
        {
            parent = *ptr;
            if (val < (*ptr)->val)
                ptr = &(*ptr)->son[0];
            else
                ptr = &(*ptr)->son[1];
        }
        *ptr = new node_t(val, parent, &rt);
        rt = (*ptr)->splay();
    }

    node_t *kth(int k)
    {
        node_t *ptr = rt;
        while (1)
        {
            ptr->pushdown();
            int lsiz = (ptr->son[0]) ? (ptr->son[0]->siz) : 0;
            if (lsiz == k - 1)
                break;
            if (k <= lsiz)
                ptr = ptr->son[0];
            else
            {
                k -= lsiz + 1;
                if (k <= 0)
                    break;
                ptr = ptr->son[1];
            }
        }
        return rt = ptr->splay();
    }

    void reverse(int l, int r)
    {
        node_t *x = kth(l), *y = kth(r + 2);
        rt = x->splay();
        y->splay(rt);
        if (y->son[0])
            y->son[0]->flag ^= 1;
    }
};

Splay tr;

void dfs(Splay::node_t *u)
{
    if (u->flag)
        u->pushdown();
    if (u->son[0])
        dfs(u->son[0]);
    if (u->val != INF && u->val != -INF)
        printf("%d ", u->val);
    if (u->son[1])
        dfs(u->son[1]);
}

int n, m;

int main()
{
    tr.insert(-INF), tr.insert(INF);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        tr.insert(i);
    while (m--)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        tr.reverse(l, r);
    }
    dfs(tr.rt);
    printf("\n");
    return 0;
}