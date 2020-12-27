MOD = int(1000000007)
MAX = int(200005)

fact = [1 for i in range(MAX)]


def mul(a: int, b: int) -> int:
    return (a % MOD * b % MOD) % MOD


def binpow(a: int, b: int) -> int:
    res = int(1)

    while b > 0:

        if b % 2 == 1:
            res = mul(res, a)

        a = mul(a, a)
        b = int(b / 2)

    return res


def C(n: int, r: int) -> int:

    return mul(fact[n], mul(binpow(fact[r], MOD - 2), binpow(fact[n - r], MOD - 2)))


t = int(input())

for i in range(2, MAX):
    fact[i] = mul(fact[i - 1], i)

for _ in range(t):

    [a, x, y] = [int(a) for a in input().split(" ")]

    ans = mul(a, C(x + y, min(x, y)))

    print(ans)
