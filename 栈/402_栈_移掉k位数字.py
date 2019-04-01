# 和316去除重复字母有类似指出
# 去掉任意k位，使留下来的字符串字典序最小
# 利用单调栈
# 遍历字符串中元素，对每个元素
# 若栈为空，则元素直接入栈
# 若栈不为空，检查栈顶元素，若栈顶元素比该元素大，那么为了减小字典序，必须将栈顶元素删掉，即弹出，知道栈顶元素比该元素小，或者删除次数用完为止
# 若遍历结束后，删除次数还未用完，那么说明栈中的元素是升序排列的，从后删除，把删除次数用完即可。

num = "1432219"
k = 3

def removeKdigits(num, k):
    my_stack = []
    for i in range(len(num)):
        while len(my_stack) != 0 and k > 0 and my_stack[-1] > num[i]:
            my_stack.pop()
            k -= 1
        # 移除次数用完
        if k == 0:
            ans = ''
            for q in my_stack:
                ans += q
            ans = ans + num[i:]
            # 去掉前导零
            a = 0
            while a < len(ans) and ans[a] == '0':
                a += 1
            return ans[a:] if ans[a:] != '' else '0'
        my_stack.append(num[i])
    # 移除次数未用完，但是跳出了for循环，说明此时栈中是严格升序的，从后向前删除即可
    while k > 0 and len(my_stack) != 0:
        my_stack.pop()
        k -= 1
    ans = ''
    for i in my_stack:
        ans += i    
    
    # 去掉前导零
    a = 0
    while a < len(ans) and ans[a] == '0':
        a += 1
    return ans[a:] if ans[a:] != '' else '0'


print(removeKdigits(num, k))