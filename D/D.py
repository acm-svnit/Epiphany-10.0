t = int(input())
MOD = int(1000000007)


def doIt(s: str, d: str) -> int:
    n = len(s)

    dp = [[0, 0, 0, 0] for i in range(n)]

    dp[0][0] = 1
    dp[0][1] = 0
    dp[0][2] = ord(s[0]) - ord('0') - 1
    dp[0][3] = 1

    for i in range(1, n):
        dp[i][0] = 1
        if i % 2 == 0:
            dp[i][3] = dp[i - 1][3] * 1
            dp[i][1] = (dp[i - 1][1] * 9) % MOD
            dp[i][2] = (
                dp[i - 1][2] * 10
                + dp[i - 1][0] * 9
                + dp[i - 1][3] * (ord(s[i]) - ord("0"))
            ) % MOD
        else:
            dp[i][3] = (dp[i - 1][3] * (1 if (s[i] != d) else 0)) % MOD
            dp[i][2] = (
                dp[i - 1][2] * 9
                + dp[i - 1][3] * (ord(s[i]) - ord("0"))
                - (1 if d < s[i] else 0) * dp[i - 1][3]
                + MOD
            ) % MOD
            dp[i][1] = (dp[i - 1][1] * 10 + dp[i - 1][0] * 9) % MOD

    ans = (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2] + dp[n - 1][3] - 1 + MOD) % MOD
    return ans


for _ in range(t):
    [l, r, d] = input().split(" ")
    l_minus = ""
    for i in range(len(l) - 1, -1, -1):
        if l[i] == "0":
            l_minus = "9" + l_minus
        else:
            l_minus = chr(ord(l[i]) - 1) + l_minus
            for j in range(i - 1, -1, -1):
                l_minus = l[j] + l_minus
            break
    l = l_minus
    if len(l) > 1 and l[0] == "0":
        l = l[1:]
    ansR = doIt(r, d)
    ansL = doIt(l, d)
    ans = (ansR - ansL + MOD) % MOD

    print(ans)
