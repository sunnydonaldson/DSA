<<<<<<< HEAD
def main():
    pass

def quicksort(nums, left, right):
    if left >= right:
        return nums

    pivot = partition(nums, left, right)
    quicksort(nums, left, pivot-1)
    quicksort(nums, pivot+ 1, right)

    return nums


def partition(nums, left, right):
    pivot = nums[right]
    print(f'pivot: {pivot}')
    i = left - 1

    for j in range(left, right):
        print(f'nums[j]: {nums[j]}')
        if nums[j] <= pivot:
            i += 1
            nums[i], nums[j] = nums[j], nums[i]
        print(f'j: {j}')
        print(f'i: {i}')
        print(nums)

    nums[i + 1], nums[right] = nums[right], nums[i + 1]
    print(nums)

    return i + 1
    
=======
def quicksort(nums, l, r):

    if r > l:
        pivot = partition(nums, l, r)
        quicksort(nums, l, pivot -1)
        quicksort(nums, pivot + 1, r)

"""
[1, 6, 3, 4, 7, 5]
[1, 6, 3, 4, 7, 5], first_bigger (index) = 1
[1, 3, 6, 4, 7, 5], first_bigger (index) = 1, swap 
[1, 3, 4, 6, 7, 5], first_bigger (index) = 1, swap 
[1, 3, 4, 6, 7, 5], first_bigger (index) = 1, swap 

"""
def partition(nums, l, r):
    pivot = r
    first_bigger = l

    for i in range(l, r):
        if nums[i] < nums[pivot]:
            nums[i], nums[first_bigger] = nums[first_bigger], nums[i]
            first_bigger += 1

    nums[first_bigger], nums[pivot] = nums[pivot], nums[first_bigger]
    pivot = first_bigger
    return pivot
>>>>>>> 36b0d22 (Add quickselect and quicksort.)
