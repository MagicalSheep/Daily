#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

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

        /**
         * No splay operation be done in this function.
         */
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

        /**
         * Do splay until parent is target. NULL target means root.
         */
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

        /**
         * No prev exist will return NULL
         */
        node_t *pre()
        {
            node_t *ptr = this->son[0];
            if (!ptr)
                return NULL;
            while (ptr->son[1])
                ptr = ptr->son[1];
            return ptr;
        }

        /**
         * No nexv exist will return NULL
         */
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

    /**
     * Auto splay and update rt when completed.
     */
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

    /**
     * Not exist will return NULL.
     * Auto splay and update rt when completed.
     */
    node_t *find(const int &val)
    {
        node_t *ptr = rt;
        for (; ptr && val != ptr->val; ptr = ptr->son[(val < ptr->val) ? 0 : 1])
            ;
        if (!ptr)
            return NULL;
        return rt = ptr->splay();
    }

    /**
     * Not exist value will return rank 0
     * Auto splay and update rt when completed.
     */
    int rank(const int &val)
    {
        node_t *ptr = find(val);
        if (!ptr)
            return 0;
        return (ptr->son[0]) ? (ptr->son[0]->siz + 1) : 1;
    }

    /**
     * Auto splay and update rt when completed.
     */
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

    /**
     * All nodes in subtree l must be smaller than the r one.
     * @return the new splay tree root pointer
     */
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
            ptr->siz--; // ptr is root, no parent
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

    /**
     * Note: Insert INF into tree before using this function.
     * Return INF when no prev exist.
     * If value appears more than one times in tree, will not return itself.
     * Please use find fuction to do a special judge. 
     */
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

    /**
     * Note: Insert INF into tree before using this function.
     * Return INF when no nexv exist.
     * If value appears more than one times in tree, will not return itself.
     * Please use find fuction to do a special judge. 
     */
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

int n, ans;

int main()
{
    Splay tr;
    tr.insert(INF), tr.insert(-INF);
    scanf("%d%d", &n, &ans);
    tr.insert(ans);
    for (int i = 2; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        if (!tr.find(a))
        {
            int pre = tr.pre(a), nex = tr.nex(a);
            ans += min(abs(pre - a), abs(nex - a));
        }
        tr.insert(a);
    }
    printf("%d\n", ans);
    return 0;
}