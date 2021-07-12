# 动态规划

# 线性DP

## 基本线性DP

> [NOIP2010 乌龟棋](https://www.luogu.com.cn/problem/P1541 "NOIP2010 乌龟棋")

以每一步行动为线性发展的线索，记录从开始到当前步所使用的每种类型卡片的数量。则状态可设置为：`f(m, i, j, k, l)`表示到第m步时，使用了i张1卡片、j张2卡片、k张3卡片、l张4卡片后，所得的最大分数。

注意到在状态转移的过程中，`f(m, i, j, k, l)`只与上一步的状态`f(m-1, i, j, k, l)`有关，故可通过滚动数组将线性发展的线索——步数给省略掉，从而得到状态：`f(i, j, k, l)`

```C++
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 350 + 10;

ll N, M, a[MAXN], b[MAXN], f[45][45][45][45];

int main()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> a[i];
    for (int i = 1; i <= M; i++)
    {
        ll t = 0;
        cin >> t;
        b[t]++;
    }
    f[0][0][0][0] = a[1];
    for (int i = 0; i <= b[1]; i++)
    {
        for (int j = 0; j <= b[2]; j++)
        {
            for (int k = 0; k <= b[3]; k++)
            {
                for (int l = 0; l <= b[4]; l++)
                {
                    ll x = 1 + i + 2 * j + 3 * k + 4 * l;
                    ll tmp = 0;
                    if (i)
                        tmp = max(tmp, f[i - 1][j][k][l]);
                    if (j)
                        tmp = max(tmp, f[i][j - 1][k][l]);
                    if (k)
                        tmp = max(tmp, f[i][j][k - 1][l]);
                    if (l)
                        tmp = max(tmp, f[i][j][k][l - 1]);
                    f[i][j][k][l] = tmp + a[x];
                }
            }
        }
    }
    cout << f[b[1]][b[2]][b[3]][b[4]] << endl;
    return 0;
}
```

## 最长公共子序列

> [P1439 【模板】最长公共子序列](https://www.luogu.com.cn/problem/P1439 "P1439 【模板】最长公共子序列")

对于最长公共子序列，状态可设置为：`f(i, j)`，表示第一个串前i位与第二个串前j位的最长公共子序列长度，则`f(0, 0) = 0`。对于状态转移方程，不难发现`f(i, j)`的值只与`f(i-1, j-1)`、`f(i-1, j)`、`f(i, j-1)`的值有关。其中：

1. 当A1[i] = A2[j]时，可以从这两个串中选择该元素，使公共子序列的长度增加1。即`f(i, j) = f(i-1, j-1) + 1`。
2. 当A1[i] != A2[j]时，无法从串中选择元素来增加公共子序列的长度，则`f(i, j)`的值只能从前一状态继承。即`f(i, j) = max(f(i-1, j), f(i, j-1))`。

该算法的时间复杂度为`O(n^2)`。

对于P1439题，数据量无法使用`O(n^2)`的算法，注意到两串含有的元素相同，可以考虑使用离散化，将LCS问题转换为LIS问题，从而使用`O(nlogn)`的算法解决。

具体步骤如下：

1. 将A1串离散化为单调递增的序列（保存映射关系到临时数组中）
2. 根据离散化后的映射关系，重组A2
3. 求A2的最长上升子序列

这是因为，离散化后的两串仍具有相同长度的最长公共子序列，而由于A1串已是单调递增的序列，因而其公共子序列必单调递增。因此，重组后A2串的最长上升子序列长度即为所求。

```C++
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;

ll n, p1[MAXN], p2[MAXN], m[MAXN];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p1[i];
    for (int i = 0; i < n; i++)
        cin >> p2[i];
    for (int i = 0; i < n; i++)
        m[p1[i]] = i;
    vector<ll> tmp, ans;
    for (int i = 0; i < n; i++)
        tmp.emplace_back(m[p2[i]]);
    ans.emplace_back(tmp[0]);
    for (int i = 1; i < (int)tmp.size(); i++)
    {
        if (ans.back() < tmp[i])
            ans.emplace_back(tmp[i]);
        else
            *lower_bound(ans.begin(), ans.end(), tmp[i]) = tmp[i];
    }
    cout << ans.size() << endl;
    return 0;
}
```

## 最长连续不下降子序列

## 最长不下降子序列

> [NOIP1999 导弹拦截](https://www.luogu.com.cn/problem/P1020 "NOIP1999 导弹拦截")

将该题转换为求最长不上升子序列和最长上升子序列，此处仅分析采用`O(nlogn)`复杂度的算法，但需要注意的是，该复杂度的算法只能得到最长单调子序列的长度，而无法求得其具体的值。

对于求最长单调子序列问题：
1. 首先创建一个临时数组存放子序列（在`O(nlogn)`的算法中，该数组存放的并非结果子序列），并将原序列首元素放入临时数组中。
2. 从头至尾扫描原序列，将扫描处的原序列值与子序列尾值进行比较，符合单调条件则加入到子序列尾部。
3. 若不符合单调条件，则通过二分查找在子序列中找到不会破坏子序列单调性的第一个位置，并将该元素覆盖该位置上的原元素。
   
这是由于，能够使得子序列增长的判断发生在子序列的末尾元素与新元素之间。在不需要求得具体元素值的情况下，我们可以在保证总长度不变的条件下，随意替换除末尾元素外的任意元素。而若要替换末尾元素，则需要保证单调性，即替换后的末尾元素仍然大于（小于）子序列内的任何一个元素，这样才能使得后续的判断变得有效。

在求上升子序列中，如果能够使用更小的新元素来替换子序列的末尾元素，则子序列便有变得更长的可能性（贪心），下降子序列同理。

综合以上两点，我们只需要始终将不满足单调条件的新元素，以不破坏子序列单调性的方式插入子序列（准确的来说是替换原元素），则最终可以得到最长单调子序列的长度。

```C++
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<ll> a;

int main()
{
    ll tmp = 0;
    while (cin >> tmp)
        a.emplace_back(tmp);
    int len = a.size();
    vector<ll> aa1;
    aa1.emplace_back(a[0]);
    for (int i = 1; i < len; i++)
    {
        if (aa1.back() >= a[i])
            aa1.emplace_back(a[i]);
        else
            *upper_bound(aa1.begin(), aa1.end(), a[i], greater<ll>()) = a[i];
    }
    cout << aa1.size() << endl;
    vector<ll> aa2;
    aa2.emplace_back(a[0]);
    for (int i = 1; i < len; i++)
    {
        if(aa2.back() < a[i])
            aa2.emplace_back(a[i]);
        else
            *lower_bound(aa2.begin(), aa2.end(), a[i]) = a[i];
    }
    cout << aa2.size() << endl;
    return 0;
}
```

## 最长回文子序列

## 最长回文子串

# 背包DP

# 区间DP

# 树形DP

# 状压DP

# 数位DP