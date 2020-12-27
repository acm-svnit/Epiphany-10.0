class Matrix:
    def __init__(self, n1, m1):
        self.n = n1
        self.m = m1
        self.A = [[0 for i in range(self.m)] for i in range(self.n)]

    def __mul__(self, other):
        p = other.n
        q = other.m
        product = Matrix(self.n, q)

        for i in range(self.n):
            for j in range(q):
                for k in range(self.m):
                    product.A[i][j] = (
                        product.A[i][j] + self.A[i][k] * other.A[k][j]
                    ) % 2
        return product

    def __str__(self):
        print("N:",self.n,"M:",self.m)
        print("A:")
        for i in self.A:
            for j in i:
                print(j,end=" ")
            print('')
        return ''


def isBobWin(n: int, k: int, p: int) -> bool:
    aux = [0 for i in range(n)]
    E = 1 if (p == 2 or p == 3) else 0
    O = 1 if (p == 2 or p == 4) else 0
    for i in range(n):
        if i % 2 == 1:
            aux[i] = E
        else:
            aux[i] = O

    multiplier = Matrix(2 * n, 2 * n)

    for i in range(n):
        for j in range(2 * n):
            if j < n:
                if j == i:
                    multiplier.A[i][j] = 1
                else:
                    multiplier.A[i][j] = 0
            else:
                if j == i + n:
                    multiplier.A[i][j] = 1
                else:
                    multiplier.A[i][j] = 0
    for i in range(n, 2 * n):
        for j in range(n, 2 * n):
            x = i - n
            y = j - n
            dist = j - i if j >= i else n - i + j
            multiplier.A[i][j] = 0 if dist > x else 1

    ans = Matrix(2 * n, 2 * n)

    for i in range(2 * n):
        ans.A[i][i] = 1

    while k > 0:
        if k % 2 == 1:
            ans = ans * multiplier
        multiplier = multiplier * multiplier
        k = int(k / 2)

    in1 = Matrix(1, 2 * n)
    for i in range(n):
        in1.A[0][i] = aux[i]
    for i in range(n, 2 * n):
        in1.A[0][i] = 1
    out = in1 * ans
    H = 0
    T = 0

    for i in range(n, 2 * n):
        if out.A[0][i] == 1:
            H = H + 1
        else:
            T = T + 1

    if H > T:
        return False
    return True


t = int(input())

for _ in range(t):
    [n, k] = [int(a) for a in input().split(" ")]

    check = 0
    ty = -1
    for p in range(1, 5):
        if isBobWin(n, k, p):
            check = 1
            ty = p
            break
    if check:
        print("BOB", ty)
    else:
        print("ALICE")