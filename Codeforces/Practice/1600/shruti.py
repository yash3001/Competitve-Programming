t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    mx = max(l)
    i=0
    ans = 0
    while(i < n):
        cnt = 0
        while(i < n and l[i] == mx):
            cnt += 1
            i += 1
        i += 1
        ans = max(ans, cnt)
    print(ans)