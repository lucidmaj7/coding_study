
n = int(input())
cnt = 0
time = ""
for h in range(n+1):
   for m in range(60):
      for s in range(60):
          if str(str(h)+str(m)+str(s)).find("3") != -1:
              cnt += 1

print(cnt)
    