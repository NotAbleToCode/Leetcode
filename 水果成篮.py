# 在一排树中，第 i 棵树产生 tree[i] 型的水果。
# 你可以从你选择的任何树开始，然后重复执行以下步骤：

# 把这棵树上的水果放进你的篮子里。如果你做不到，就停下来。
# 移动到当前树右侧的下一棵树。如果右边没有树，就停下来。
# 请注意，在选择一颗树后，你没有任何选择：你必须执行步骤 1，然后执行步骤 2，然后返回步骤 1，然后执行步骤 2，依此类推，直至停止。

# 你有两个篮子，每个篮子可以携带任何数量的水果，但你希望每个篮子只携带一种类型的水果。
# 用这个程序你能收集的水果总量是多少？

# 一个字符串中，允许一个字符不同的最长的子串的长度。
# 设计一系列规则，可实现O(n)

def totalFruit(tree):
    if len(tree) == 0:
        return 0
    cur_value = tree[0] # 最后一次变化的元素类型
    last_diff_index = 0 # 元素最后一次变化时的下标
    counter = 0 # 下标
    pre_max = 0
    my_max = 0
    fru_type = [] # 水果的类型
    while counter != len(tree):
        if len(fru_type) < 2: # 类型小于2
            if not (tree[counter] in fru_type): # 新类型，直接加入，last_diff_index，cur_value更新
                fru_type.append(tree[counter])
                last_diff_index = counter
                cur_value = tree[counter]
            counter += 1
            my_max += 1
        else: # 类型等于2
            if tree[counter] in fru_type: # 如果是已有的类型，加入
                print(cur_value)
                if tree[counter] != cur_value: # 如果变化，则更新last_diff_index，cur_value
                    last_diff_index = counter
                    cur_value = tree[counter]
                counter += 1
                my_max += 1
            else: # 否则，最长的只可能以last_diff_index为起点，last_diff_index之前的都会更小
                pre_max = max(pre_max, my_max)
                my_max = (counter-last_diff_index+1)
                #print(my_max)
                fru_type = [tree[last_diff_index], tree[counter]]
                #print(fru_type)
                cur_value = tree[counter]
                last_diff_index = counter
                counter += 1
            #print(pre_max)
    return max(pre_max, my_max)


print(totalFruit([5,0,0,7,0,7,2,7]))