t = int(input())

for _ in range(t):
    n = int(input())
    a = [int(a) for a in input().split(" ")]

    b = [0 for i in range(n)]
    x = [0 for i in range(n)]
    if n > 3:
        for i in range(1, n):
            b[i] = a[i - 1] - a[i]

        for i in range(1, n - 1):
            x[i] = b[i - 1]
            if i >= 3:
                x[i] = x[i] + x[i - 3]
        offset = 0

        if n % 3 == 0:
            offset = 999999999999999
        elif n % 3 == 1:
            i = n - 3
            offset = a[i + 2] - a[i + 1] - x[i]
        else:
            i = n - 4
            offset = a[i + 2] - a[i + 1] - x[i]

        for i in range(1, n - 1, 3):
            x[i] = x[i] + offset
    out = [0 for i in range(n)]

    for i in range(n):
        out[i] = (
            (x[i - 1] if i > 0 else 0) + x[i] + a[i] + (x[i + 1] if i < n - 1 else 0)
        )

    ans = True

    for i in range(1, n):
        if x[i] < 0 or out[i] != out[i - 1]:
            ans = False

    if ans:
        print("Yes")
    else:
        print("No")
