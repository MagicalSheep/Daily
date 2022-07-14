#include <bits/stdc++.h>
using namespace std;

struct Splay
{
    struct node_t
    {
        int val, cnt, siz;
        node_t *son[2], *parent, **rt;

        node_t(const int &val, node_t *parent, node_t **rt) : val(val), parent(parent), son{NULL, NULL}, siz(1), cnt(1), rt(rt) {}

        ~node_t()
        {
            if (son[0])
                delete son[0];
            if (son[1])
                delete son[1];
        }

        inline void maintain()
        {
            siz = 0;
            if (son[0])
                siz += son[0]->siz;
            if (son[1])
                siz += son[1]->siz;
            siz += cnt;
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

        node_t *pre()
        {
            node_t *ptr = this->son[0];
            if (!ptr)
                return NULL;
            while (ptr->son[1])
                ptr = ptr->son[1];
            return ptr;
        }

        node_t *nex()
        {
            node_t *ptr = this->son[1];
            if (!ptr)
                return NULL;
            while (ptr->son[0])
                ptr = ptr->son[0];
            return ptr;
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
            (*ptr)->siz++;
            if (val < (*ptr)->val)
                ptr = &(*ptr)->son[0];
            else if (val > (*ptr)->val)
                ptr = &(*ptr)->son[1];
            else
            {
                (*ptr)->cnt++;
                rt = (*ptr)->splay();
                return;
            }
        }
        *ptr = new node_t(val, parent, &rt);
        rt = (*ptr)->splay();
    }

    node_t *find(const int &val)
    {
        node_t *ptr = rt;
        for (; ptr && val != ptr->val; ptr = ptr->son[(val < ptr->val) ? 0 : 1])
            ;
        if (!ptr)
            return NULL;
        return rt = ptr->splay();
    }

    int rank(const int &val)
    {
        node_t *ptr = find(val);
        if (!ptr)
            return 0;
        return (ptr->son[0]) ? (ptr->son[0]->siz + 1) : 1;
    }

    int kth(int k)
    {
        node_t *ptr = rt;
        while (1)
        {
            int lsiz = (ptr->son[0]) ? (ptr->son[0]->siz) : 0;
            if (lsiz == k - 1)
                break;
            if (k <= lsiz)
                ptr = ptr->son[0];
            else
            {
                k -= lsiz + ptr->cnt;
                if (k <= 0)
                    break;
                ptr = ptr->son[1];
            }
        }
        return (rt = ptr->splay())->val;
    }

    node_t *merge(node_t *l, node_t *r)
    {
        if (!l && !r)
            return NULL;
        if (!l && r)
            return r;
        if (l && !r)
            return l;
        node_t *ptr = l;
        while (ptr->son[1])
            ptr = ptr->son[1];
        ptr->splay();
        ptr->son[1] = r;
        r->parent = ptr;
        ptr->maintain();
        return ptr;
    }

    void erase(const int &val)
    {
        node_t *ptr = find(val);
        if (ptr->cnt > 1)
        {
            ptr->siz--;
            ptr->cnt--;
            return;
        }
        node_t *l = ptr->son[0], *r = ptr->son[1];
        if (l)
            l->parent = NULL, l->rt = &l;
        if (r)
            r->parent = NULL, r->rt = &r;
        rt = merge(l, r);
        ptr->son[0] = ptr->son[1] = NULL;
        delete ptr;
    }

    int pre(const int &val)
    {
        node_t *ptr = find(val);
        if (ptr)
        {
            rt = ptr->pre()->splay();
            return rt->val;
        }
        else
        {
            insert(val);
            rt = rt->pre()->splay();
            int res = rt->val;
            erase(val);
            return res;
        }
    }

    int nex(const int &val)
    {
        node_t *ptr = find(val);
        if (ptr)
        {
            rt = ptr->nex()->splay();
            return rt->val;
        }
        else
        {
            insert(val);
            rt = rt->nex()->splay();
            int res = rt->val;
            erase(val);
            return res;
        }
    }
};

int n;

int main()
{
    Splay tr;
    scanf("%d", &n);
    while (n--)
    {
        int opt, x;
        scanf("%d%d", &opt, &x);
        switch (opt)
        {
        case 1:
            tr.insert(x);
            break;
        case 2:
            tr.erase(x);
            break;
        case 3:
            printf("%d\n", tr.rank(x));
            break;
        case 4:
            printf("%d\n", tr.kth(x));
            break;
        case 5:
            printf("%d\n", tr.pre(x));
            break;
        case 6:
            printf("%d\n", tr.nex(x));
            break;
        default:
            break;
        }
    }
    return 0;
}