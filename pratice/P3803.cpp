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

const int MAXN = 1e7 + 10;
int n, m;
cp F[MAXN], G[MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++)
    {
        int in;
        scanf("%d", &in);
        F[i] = cp(in, 0);
    }
    for (int i = 0; i <= m; i++)
    {
        int in;
        scanf("%d", &in);
        G[i] = cp(in, 0);
    }
    int len = 1;
    while (len <= n + m + 2)
        len <<= 1;
    for (int i = n + 1; i < len; i++)
        F[i] = cp(0, 0);
    for (int i = m + 1; i < len; i++)
        G[i] = cp(0, 0);
    fft(F, len, 1);
    fft(G, len, 1);
    for (int i = 0; i < len; i++)
        F[i] = F[i] * G[i];
    fft(F, len, -1);
    for (int i = 0; i < n + m + 1; i++)
        printf("%d ", int(F[i].x + 0.5));
    printf("\n");
    return 0;
}