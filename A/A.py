t = int(input())

for _ in range(t):
    [a, b, c] = [int(a) for a in input().split(" ")]

    if (
        3 * a - b - c >= 0
        and 3 * b - a - c >= 0
        and 3 * c - a - b >= 0
        and (3 * a - b - c) % 4 == 0
        and (3 * b - a - c) % 4 == 0
        and (3 * c - a - b) % 4 == 0
    ):
        print("YES")
    else:
        print("NO")