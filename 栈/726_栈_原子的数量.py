
def multi(num, scale):
    return [i*scale for i in num]

def countOfAtoms(formula):
    # 总的字母数量
    num_total = [0]*26
    my_stack = []
    for i in formula:
        if i != ')':
            my_stack.append(i)
        else:
            while 

