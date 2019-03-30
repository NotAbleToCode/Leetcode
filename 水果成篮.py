# 在一排树中，第 i 棵树产生 tree[i] 型的水果。
# 你可以从你选择的任何树开始，然后重复执行以下步骤：

# 把这棵树上的水果放进你的篮子里。如果你做不到，就停下来。
# 移动到当前树右侧的下一棵树。如果右边没有树，就停下来。
# 请注意，在选择一颗树后，你没有任何选择：你必须执行步骤 1，然后执行步骤 2，然后返回步骤 1，然后执行步骤 2，依此类推，直至停止。

# 你有两个篮子，每个篮子可以携带任何数量的水果，但你希望每个篮子只携带一种类型的水果。
# 用这个程序你能收集的水果总量是多少？

# 一个字符串中，允许一个字符不同的最长的子串的长度。

def totalFruit(tree):
    if len(tree) == 0:
        return 0
    cur_value = tree[0]
    last_diff_index = 0
    counter = 0
    pre_max = 0
    my_max = 0
    fru_type = []
    while counter != len(tree):
        if len(fru_type) < 2:
            if not (tree[counter] in fru_type):
                fru_type.append(tree[counter])
                last_diff_index = counter
                cur_value = tree[counter]
            counter += 1
            my_max += 1
        else:
            if tree[counter] in fru_type:
                print(cur_value)
                if tree[counter] != cur_value:
                    last_diff_index = counter
                    cur_value = tree[counter]
                counter += 1
                my_max += 1
            else:
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