#include <bits/stdc++.h>
using namespace std;

/** FFT Begin **/
namespace FFT
{
    const double PI = acos(-1.0);
    typedef struct Complex
    {
        double x, y;
        Complex(double _x = 0.0, double _y = 0.0)
        {
            x = _x;
            y = _y;
        }
        Complex operator-(const Complex &b) const
        {
            return Complex(x - b.x, y - b.y);
        }
        Complex operator+(const Complex &b) const
        {
            return Complex(x + b.x, y + b.y);
        }
        Complex operator*(const Complex &b) const
        {
            return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
        }
    } cp;

    void change(Complex y[], int len)
    {
        int i, j, k;
        for (int i = 1, j = len / 2; i < len - 1; i++)
        {
            if (i < j)
                swap(y[i], y[j]);
            k = len / 2;
            while (j >= k)
            {
                j = j - k;
                k = k / 2;
            }
            if (j < k)
                j += k;
        }
    }

    void fft(Complex y[], int len, int on)
    {
        change(y, len);
        for (int h = 2; h <= len; h <<= 1)
        {
            Complex wn(cos(2 * PI / h), sin(on * 2 * PI / h));
            for (int j = 0; j < len; j += h)
            {
                Complex w(1, 0);
                for (int k = j; k < j + h / 2; k++)
                {
                    Complex u = y[k];
                    Complex t = w * y[k + h / 2];
                    y[k] = u + t;
                    y[k + h / 2] = u - t;
                    w = w * wn;
                }
            }
        }
        if (on == -1)
        {
            for (int i = 0; i < len; i++)
            {
                y[i].x /= len;
            }
        }
    }
}
/** FFT End **/

int main()
{
    // 高精度乘法

    char A[200], B[200];
    scanf("%s%s", A, B);
    int len1, len2;
    len1 = strlen(A);
    len2 = strlen(B);

    FFT::cp a[400], b[400];
    for (int i = 0; i < len1; i++)
        a[i] = FFT::cp(A[len1 - 1 - i] - '0', 0); // cp(实部, 虚部)
    for (int i = 0; i < len2; i++)
        b[i] = FFT::cp(B[len2 - 1 - i] - '0', 0);

    // 不足的使用(0, 0)补齐
    int len = 1;
    while (len <= len1 + len2)
        len <<= 1;
    for (int i = len1; i < len; i++)
        a[i] = FFT::cp(0, 0);
    for (int i = len2; i < len; i++)
        b[i] = FFT::cp(0, 0);

    // 系数表达式 -> 点值表达式
    FFT::fft(a, len, 1);
    FFT::fft(b, len, 1);

    // 点值表达式可直接相乘计算卷积
    for (int i = 0; i < len; i++)
        a[i] = a[i] * b[i];

    // 点值表达式 -> 系数表达式
    FFT::fft(a, len, -1);

    int ans[400] = {0};
    for (int i = 0; i < len; i++)
        ans[i] = (int)(a[i].x + 0.5);
    for (int i = 0; i < len; i++)
    {
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
    len = len1 + len2;
    while (!ans[len] && len > 0)
        --len;
    for (; len >= 0; len--)
        printf("%d", ans[len]);
    printf("\n");

    return 0;
}