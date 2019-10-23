T = int(input())
for i in range(T):
    N = int(input())
    L = list(map(int, raw_input().split()))
    L2 = [0] * N
    res = 0
    n = N - 1
    while n != 0:
        if L2[n] == 1:
            n = n - 1
            continue
        req = 0
        a = L[n]
        for i in range(n - 1, -1, -1):
            if L[i] % L[n] == 0:
                L2[i] = 1
                req = req + 1

        res = max(req, res)
        n = n - 1

    print res