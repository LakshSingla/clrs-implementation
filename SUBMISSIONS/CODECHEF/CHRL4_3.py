from math import log
MOD = 10e9 + 7

n = input()
k = input()
a = []

for x in range(n): a.append(input())

cache = []
path = []

for i in range(n):
    if i == 0:
        cache.append(0)
        path.append(0)
        #cache[i] = 0
        #path[i] = 0

    elif i <= k:
        cache.append(log(a[0]))
        path.append(0)
        #cache[i] = log(a[0])
        #path[i] = 0
    
    else:
        min = log(a[i]) + log(a[i-1]) + cache[i-1]
        next_jump = i - 1
        for j in range(i-1, i-1-k, -1):
            dist = log(a[i]) + log(a[j]) + cache[j]
            if min > dist : min = dist
            if min > dist : next_jump = j
            #min       = (min > dist ? dist : min)
            #next_jump = (min > dist ? j    : next_jump)
        path.append(next_jump)
        cache.append(min)
        #path[i] = next_jump
        #cache[i] = min

ans = 1
x = n-1
i = 0
while x != 0 : 
   ans *= a[x] % MOD 
   x = path[x]
ans *= a[0] % MOD
print(ans)
    
