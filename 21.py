# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    @staticmethod
    def mergeTwoLists(l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1==None and l2==None:
            return []
        elif l1==None and l2!=None:
            return l2
        elif l1!=None and l2==None:
            return l1
        else:
            if l1.val <= l2.val:
                l1, l2 = l1, l2  
            else:
                l1, l2 = l2, l1
        begin_l1 = l1
        pre_l1 = l1
        while l1 != None and l2 != None:
            while l1 != None and l1.val <= l2.val:
                pre_l1 = l1
                l1 = l1.next
            if l1 != None:
                pre_l1.next = l2
                pre_l1 = l2
                temp = l2.next
                l2.next = l1
                l2 = temp
            else:
                pre_l1.next = l2

            # temp = begin_l1
            # while temp != None:
            #     print(temp.val, end = ' ')
            #     temp = temp.next
            # print('\n')
        return begin_l1

def generate_list(x):
    begin = ListNode(x[0])
    pre = begin
    for i in x[1:]:
        pre.next = ListNode(i)
        pre = pre.next
    return begin

def main():
    a = [-10,-9,-6,-4,1,9,9]
    b = [-5,-3,0,7,8,8]
    a_begin = generate_list(a)
    b_begin = generate_list(b)
    temp = a_begin
    while temp != None:
        print(temp.val, end = ' ')
        temp = temp.next
    print('\n')
    
    temp = b_begin
    while temp != None:
        print(temp.val, end = ' ')
        temp = temp.next
    print('\n')
    
    temp = Solution.mergeTwoLists(a_begin, b_begin)
    while temp != None:
        print(temp.val, end = ' ')
        temp = temp.next
if __name__ == '__main__':
    main()