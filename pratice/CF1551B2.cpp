// #include <bits/stdc++.h>
// using namespace std;
// const int MAXN = 2e5 + 10;

// int t, a[MAXN], vis[MAXN], sign[MAXN], colornum[MAXN];

// int ans[MAXN];

// void init()
// {
//     memset(a, 0, sizeof(a));
//     memset(vis, 0, sizeof(vis));
//     memset(sign, 0, sizeof(sign));
//     memset(colornum, 0, sizeof(colornum));
//     memset(ans, 0, sizeof(ans));
// }

// int main()
// {
//     int aa[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9};
//     sort(aa, aa + 13);
//     for (int i = 0; i < 13; i++)
//         printf("%d ", aa[i]);
//     return 0;
//     scanf("%d", &t);
//     while (t--)
//     {
//         init();
//         int n, k;
//         scanf("%d%d", &n, &k);
//         int cnt = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             scanf("%d", &a[i]);
//             if (sign[a[i]] >= k)
//                 continue;
//             if (sign[a[i]] > 0)
//                 ans[i] = sign[a[i]] + 1;
//             ++cnt, ++sign[a[i]];
//         }
//         int nums = cnt / k;

//         for (int i = 1; i <= n; i++)
//         {
//             if (ans[i])
//             {
//                 colornum[ans[i]]++;
//                 vis[a[i]]++;
//                 continue;
//             }
//             if (vis[a[i]] >= k)
//             {
//                 ans[i] = 0;
//             }
//             else
//             {
//                 int dst_color = vis[a[i]] + 1;
//             begin:
//                 if (colornum[dst_color] >= nums)
//                 {
//                     dst_color++;
//                     goto begin;
//                 }
//                 if (dst_color > k)
//                 {
//                     ans[i] = 0;
//                 }
//                 else
//                 {
//                     ans[i] = dst_color;
//                     colornum[dst_color]++;
//                     vis[a[i]]++;
//                 }
//             }
//         }

//         for (int i = 1; i <= n; i++)
//             printf("%d ", ans[i]);
//         printf("\n");
//     }
//     return 0;
// }

#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<pair<int, int>> a(n);
        vector<int> c(n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[i].first), a[i].second = i;
        sort(a.begin(), a.end());
        int t = 0;
        for (int i = 0; i < n; ++i)
        {
            if (i < k || a[i].first != a[i - k].first)
                c[a[i].second] = ++t;
        }
        t -= t % k;
        for (int i = 0; i < n; ++i)
        {
            if (c[i] > t)
                c[i] = 0;
            if (c[i])
                c[i] = (c[i] - 1) % k + 1;
            printf("%d ", c[i]);
        }
        puts("");
    }
}

/*
#include<cstdio>
using namespace std;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		if(n%2==1){
			k=n*m/2-k;
			n^=m;
			m^=n;
			n^=m;
		}
		if(k%2==0&&k<=m/2*n)puts("YES");
		else puts("NO");
	}
}
*/