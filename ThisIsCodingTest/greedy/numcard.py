n, m = map(int, input().split())

#print(n)
#print(m)

max = -1
first = -1
for i in range(n):
    arr = list(map(int,input().split()))
    f = arr[0]
    arr.sort()
    min = arr[0]
    if max < min:
        max = min
        first = f
    
print(first)
    