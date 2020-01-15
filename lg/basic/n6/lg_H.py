def dump(locals, *vals):
    for val in vals:
        for key in locals:
            if locals[key] == val:
                print('{}={}; '.format(key,val), end='')
                break
    print()  # 最后换行

# def dump(locals, *vals):
#     pass
n = int(input())
A,B = input().split()  # 过完
# print(A, B)
l = []
# l.append([A,B])
for i in range(n):
    a,b = input().split()
    l.append([int(a),int(b)])
l.sort(key=lambda x: x[0]*x[1])
# for i in l:
#     print(i)

ans = 0
P = int(A)
for i in range(n):
    v = P // l[i][1]  # 右手
    dump(locals(), ans, v)
    if v > ans:
        ans = v
    P *= l[i][0]  # 左手

print(ans)
