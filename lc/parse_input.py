
# ------- exec input
import re

# 会换行（\n）替换为空格（ ）
# 把这个逗号（，）替换为分号（；）
def __pre_replace(text):
    # print('ori text: %s' % text)
    text = text.replace('\n', ' ')
    p = r',\s+\w+ = '
    rg = re.findall(p, text)
    for a in rg:
        b = ';' + a[1:]
        text = text.replace(a, b)
    # print('new text: %s' % text)
    return text

def exec_input(__s):
    __s = __pre_replace(__s)
    # print('__s: %s' % __s)
    exec(__s)
    __d = locals()
    __d.pop('__s')  # 再次调用locals()，这个结构又会被重新赋值！！
    # print('d: %s' % __d)
    # for __k, __v in __d.items():
    #     print('type(%s): %s' % (__k, type(__v)))
    return __d


def eval_input(__s):
    return eval(__s)


# --------- parse input
def read_input():
    fp = '/Users/nysanier/git/cf/input.txt'
    # 0 读一个值，表示case数
    with open(fp) as f:
        t = int(f.readline())
        lin = []
        lout = []
        fin = ''
        while True:
            # 包含行尾！！ 返回str!! EOF=len(0), 空行=len(1)
            ln = f.readline()
            if not ln:  # 结束了
                break
            if fin:
                # 结束输入
                if ln.startswith('输出：'):
                    fout = ln[3:]
                    lout.append(fout)
                    lin.append(fin)
                    fin = ''
                else:  # 合并多行输入
                    fin += ln
            if ln.startswith('输入：'):
                assert fin == ''
                fin += ln[3:]
    return t, lin, lout

def parse_input():
    t, lin, lout = read_input()
    # print(t)
    # print(lin)
    # print(lout)
    pin = []
    pout = []
    for s in lin:
        pin.append(exec_input(s))
    for s in lout:
        pout.append(eval_input(s))
    # print(t)
    # print(pin)
    # print(pout)
    return t, pin, pout



if __name__ == "__main__":
    # t, lin, lout = read_input()
    t, pin, pout = parse_input()
    import pprint
    pp = pprint.PrettyPrinter(indent=4)
    # pp.pprint(t)
    # pp.pprint(lin)
    # pp.pprint(lout)
    pp.pprint(t)
    pp.pprint(pin)
    pp.pprint(pout)
    # print(t, lin, lout)
    # # 1 read 输入/输出
    # #    输入-输出的所有内容都是‘输入’！

    # # 2 输出就一个值
    # def test_eval():
    #     s = '1234'
    #     # eval() 函数用来执行一个字符串表达式，并返回表达式的值。
    #     #   只能是表达式？
    #     v = eval(s)
    #     print('eval: ', locals())

    # def test_exec():
    #     # s = 'a = 1'
    #     # v = exec(s)
    #     exec('a = 1')
    #     print('exec: ', locals())

    # test_eval()
    # test_exec()
