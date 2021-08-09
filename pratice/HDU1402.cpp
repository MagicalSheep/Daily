#include <bits/stdc++.h>
using namespace std;

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

const int MAXN = 1e5 + 10;
char A[MAXN], B[MAXN];
cp a[MAXN << 1], b[MAXN << 1];
int ans[MAXN << 1];

int main()
{
    while (scanf("%s%s", A, B) != EOF)
    {
        int len1 = strlen(A);
        int len2 = strlen(B);
        for (int i = 0; i < len1; i++)
            a[i] = cp(A[len1 - 1 - i] - '0', 0);
        for (int i = 0; i < len2; i++)
            b[i] = cp(B[len2 - 1 - i] - '0', 0);
        int len = 1;
        while (len <= len1 + len2)
            len <<= 1;
        for (int i = len1; i < len; i++)
            a[i] = cp(0, 0);
        for (int i = len2; i < len; i++)
            b[i] = cp(0, 0);
        fft(a, len, 1);
        fft(b, len, 1);
        for (int i = 0; i < len; i++)
            a[i] = a[i] * b[i];
        fft(a, len, -1);
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
    }
    return 0;
}