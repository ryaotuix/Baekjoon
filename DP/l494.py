
# global variables
nums = [1,1,1,1,1]
length = len(nums)
target = 3

cache = dict()
print(type(cache))

def getCnt(ind, currSum):
    # base case
    if (ind == length):
        return 1 if currSum == target else 0

    # if this was found in cache memoization
    if (ind, currSum) in cache:
        return cache[(ind, currSum)]

    cache[(ind, currSum)] = getCnt(ind + 1, currSum + nums[ind]) + getCnt(ind + 1, currSum - nums[ind])
    return cache[(ind, currSum)]


x = getCnt(0,0)
print(x)