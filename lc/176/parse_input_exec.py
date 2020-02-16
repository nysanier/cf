
import re

# 会换行（\n）替换为空格（ ）
# 把这个逗号（，）替换为分号（；）
def __pre_replace(text):
    # print('ori text: %s' % text)
    text = text.replace('\n', ' ')
    p = r', \w+ = '
    rg = re.findall(p, text)
    for a in rg:
        b = ';' + a[1:]
        text = text.replace(a, b)
    # print('new text: %s' % text)
    return text

def exec_input(__s):
    __s = __pre_replace(__s)
    # print('__s = "%s"' % __s)
    exec(__s)
    __d = locals()
    __d.pop('__s')  # 再次调用locals()，这个结构又会被重新赋值！！
    # print('d = %s' % __d)
    # for __k, __v in __d.items():
    #     print('type(%s): %s' % (__k, type(__v)))
    return __d

if __name__ == "__main__":
    s = 'events = [[1,2],[1,2],[3,3],[1,5],[1,5]]'  # ok
    s = 'events = [[1,2],[1,2],[3,3],[1,5],[1,5]], k = 3'  # , -> ;
    # s = 's = "bab", t = "aba", r = 123'  # , -> ;
    # # '\n' -> ' '
    # s = '''mat = 
    # [[1,1,0,0,0],
    #  [1,1,1,1,0],
    #  [1,0,0,0,0],
    #  [1,1,0,0,0],
    #  [1,1,1,1,1]],
    # k = 3
    # '''
    r = exec_input(s)
    print(r)
