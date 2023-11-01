while True:
    try:
        arr = list(map(int, input().split()))
        arr = arr[:-1]

        ans = -pow(10, 500)
        for i in range(len(arr)):
            p = 1
            for j in range(i, len(arr)):
                p *= arr[j]
                ans = max(ans, p)
        print(ans)

    except EOFError:
        break