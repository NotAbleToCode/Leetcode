
test = [3,2,3,1,2,4,5,5,6]
k = 4
def findKthLargest(nums, k):
    nums.sort(reverse=True)
    return nums[k-1]


print(findKthLargest(test, k))



