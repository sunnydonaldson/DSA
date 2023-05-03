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
    