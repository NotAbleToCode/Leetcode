# 给定一个编码字符串 S。为了找出解码字符串并将其写入磁带，从编码字符串中每次读取一个字符，并采取以下步骤：

# 如果所读的字符是字母，则将该字母写在磁带上。
# 如果所读的字符是数字（例如 d），则整个当前磁带总共会被重复写 d-1 次。
# 现在，对于给定的编码字符串 S 和索引 K，查找并返回解码字符串中的第 K 个字母。

# 我们采用递归的思想
# 一层一层下去逐步减小可能的范围
# 

S = "ha22"
K = 5

def decodeAtIndex(S, K):
    # 记录下标
    my_index = 0
    # counter用于记录实际遍历的个数
    counter = 0
    while counter < K :
        # 遇到数字，由于重复，故counter要倍数增加
        if S[my_index] >= '0' and S[my_index] <= '9':
            counter *= int(S[my_index])
        else:
        # 否则，counter加一即可
            counter += 1
        my_index += 1
    # 如果恰巧counter等于K，有两种情况，一种是正好到字母，counter加一后等于K，此时该字母即是结果
    # 另一种是counter倍数增加后正好等于K，此时遍历到数字，该数字前的第一个字母即是结果
    if counter == K:
        if S[my_index-1] >= '0' and S[my_index-1] <= '9':
            temp = my_index - 1
            while S[temp] >= '0' and S[temp] <= '9':
                temp -= 1
            return S[temp]
        else:
            return S[my_index-1]
    # 否则，结果肯定在counter倍数增加后，counter大于K，此时遍历到的是数字，而结果肯定是数字前的一串字符中的一个字母
    # 而且，通过求余运算，可以得到位置
    # 递归即可
    else:
        return decodeAtIndex(S[:my_index-1], K%(counter//int(S[my_index-1])))

print(decodeAtIndex(S, K))
