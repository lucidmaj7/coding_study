# Queue

from collections import deque

queue = deque()

queue.append(5) # insert
queue.append(2)
queue.append(3)
queue.append(7)
queue.popleft() # pop
queue.append(1)
queue.popleft()

print(queue)
queue.reverse() # reverse queue
print(queue)