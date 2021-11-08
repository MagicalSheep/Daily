#include <bits/stdc++.h>
typedef long double ld;
using namespace std;
const int MAXN = 1e5 + 10;

int N;
ld A[MAXN], B[MAXN], C[MAXN], D[MAXN], sum;

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> A[i] >> B[i];
        C[i] = A[i] / B[i];
        sum += C[i];
        D[i] = D[i - 1] + C[i];
    }
    sum /= 2;
    int ind = lower_bound(D + 1, D + 1 + N, sum) - D - 1;
    ld ans = 0;
    for (int i = 1; i <= ind; i++)
        ans += A[i];
    ans += ((sum - D[ind]) * B[ind + 1]);
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}