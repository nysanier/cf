# 好像比较难实现正确，因为形参不会传到实参上，只是给了对象的地址而已
# def dump(locals, *vals):
    # for val in vals:
    #     for key in locals:
    #         if id(locals[key]) == id(val):
    #             print('{}={}; '.format(key,val), end='')
    #             break
    # print()  # 最后换行

# stderr不作为结果来处理
import sys
def dump(**kw):
    for k in kw:
        print('{}={}; '.format(k,kw[k]), file=sys.stderr, end='')
    print(file=sys.stderr)

n = int(input())
A,B = input().split()  # 过完

l = []
for i in range(n):
    a,b = input().split()
    l.append([int(a),int(b)])
l.sort(key=lambda x: x[0]*x[1])

ans = 0
P = int(A)
for i in range(n):
    v = P // l[i][1]  # 右手
    # dump(locals(), ans, v)
    dump(**{'v':v, 'ans':ans})
    if v > ans:
        ans = v
    P *= l[i][0]  # 左手

print(ans)
