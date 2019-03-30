
test = 'bcabc'
#test = 'cbacdcbc'

def removeDuplicateLetters(s):
    table = [[] for i in range(26)]
    result = [None]*len(s)
    for i,w in enumerate(s):
        table[ord(w)-ord('a')].append(i)
    print(table)
    for i 

removeDuplicateLetters(test)