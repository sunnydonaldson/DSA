
def quickselect(nums, l, r, k) -> int:
    if l == r:
        return nums[l]

    pivot = partition(nums, l, r)

    if pivot == k:
        return nums[k]
    elif pivot > k:
        r = pivot - 1
    else:
        l = pivot + 1
    return quickselect(nums, l, r, k)

def partition(nums, l, r):
    pivot = r
    first_higher = l

    for i in range(l, r):
        if nums[i] < nums[pivot]:
            nums[first_higher], nums[i] = nums[i], nums[first_higher]
            first_higher += 1
    nums[first_higher], nums[pivot] = nums[pivot], nums[first_higher]
    return first_higher

nums = [1, 6, 3, 4, 7, 5]
print(quickselect(nums, 0, len(nums) -1, 1))