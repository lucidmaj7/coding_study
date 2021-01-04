stack = []
stack.append(5)
stack.append(2)
stack.append(1)
stack.append(4)
stack.pop()
stack.append(9)
stack.append(10)
stack.pop()

print(stack) # 최하단 원소 부터 출력
print(stack[::-1]) # 최상단 원소부터 출력