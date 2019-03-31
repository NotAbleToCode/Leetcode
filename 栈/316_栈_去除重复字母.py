# 给定一个仅包含小写字母的字符串，去除字符串中重复的字母，使得每个字母只出现一次。
# 需保证返回结果的字典序最小（要求不能打乱其他字符的相对位置）。


test = "cbacdcbc"
test = "bbcaac"
test = "bcabc"

# 字典序最小，暗含了单调
# 每个字母只出现一次，说明是有限制的单调
# 先统计所有字母出现的次数O(n)
# 采用单调栈的思想：

# 采用如下规则，可以在O(n)的时间复杂度完成：
# 初始化一个栈对象ans，用于存放结果
# 从左到右遍历所有元素
#   如果元素i不在ans内
#       循环：
#       如果栈顶的元素比i大
#           如果栈顶的元素出现的次数大于等于2，那么说明i后还有该元素，为了减小字典序，那么该元素应该在i后，该元素出栈，出现次数减一。
#           如果栈顶的元素出现的次数等于1，那么该栈顶元素不能被删除，只能留在原位置。
#           （栈顶前的元素已经达到最优位置，因为栈顶元素前的元素，一类是比i小的，由于栈顶元素不能改变，如果删除这些元素，那么势必会导致字典序增大
#           一类是比i大的，这样的元素出现的次数是1，否则不能出现在前面。）
#           元素i入栈
#       如果栈顶的元素比i小
#           元素i直接入栈
#   如果元素i在ans内
#       也就是说，元素i已经出现在ans中了，由于ans的性质，continue

def removeDuplicateLetters(s):
    my_stack = []
    counter = [0]*26 # 记录还没遍历过的各个字母出现的频次
    flag = [False]*26 # 记录是否出现在栈中
    for i in s:
        counter[ord(i)-ord('a')] += 1
    for i in s:
        counter[ord(i)-ord('a')] -= 1 # 每次遍历一个字符就将他出现的次数减一
        if flag[ord(i)-ord('a')] == True: # 标记是否被访问过
            continue
        # 如果结果字符串尾端的字符比将要插入字符大，而且后面字符串中还有这个字符，就弹出。
        while len(my_stack) != 0 and my_stack[-1] >= i and counter[ord(my_stack[-1])-ord('a')] >= 1:
            flag[ord(my_stack[-1])-ord('a')] = False
            my_stack.pop()
        my_stack.append(i)
        flag[ord(i)-ord('a')] = True
    ans = ''
    for i in my_stack:
        ans += i
    return ans

print(removeDuplicateLetters(test))