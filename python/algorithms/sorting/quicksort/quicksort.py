
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

if __name__ == "__main__":
    arr = [3,2,3,1,2,4,5,5,6]
    print(arr)
    quicksort(arr, 0, len(arr) -1)
    print(arr)
