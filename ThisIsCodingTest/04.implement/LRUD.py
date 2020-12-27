n =  input()

arr = list(map(str,input().split()))

x = 1
y = 1

for i in range(len(arr)):
    move_x = 0
    move_y = 0
    if arr[i] == 'L':
        move_x = -1
    elif arr[i] == 'R':
        move_x = 1
    elif arr[i] == 'U':
        move_y = -1
    elif arr[i] == 'D':
        move_y = 1
    
    if move_x + x <= int(n) and move_x + x >= 1:
        x += move_x
    
    if move_y + y <= int(n) and move_y + y >= 1:
        y += move_y

print("{} {}".format(x,y))
