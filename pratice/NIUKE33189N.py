import math


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    cnt = [0] * 30
    for i in range(n):
        j = 1
        while a[i] != 0:
            if (a[i] & 1) == 1:
                cnt[j] += 1
            a[i] >>= 1
            j += 1
    sum = 0
    for i in range(n):
        a[i] = 0
        for j in range(1, 21, 1):
            if cnt[j] <= 0:
                continue
            a[i] += (1 << (j - 1))
            cnt[j] -= 1
        sum += a[i]
    mu = n * n * n
    zi = 0
    for i in range(n):
        zi += (a[i] * n - sum) * (a[i] * n - sum)
    g = math.gcd(zi, mu)
    zi /= g
    mu /= g
    print('{}/{}'.format(int(zi), int(mu)))


solve()
