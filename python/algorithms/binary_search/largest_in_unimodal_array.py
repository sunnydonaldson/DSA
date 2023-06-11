"""
Runs in O(logn) time, with O(1) space.
"""
def find_largest_in_unimodal_array(arr):
    if not arr:
        return None

    l, r = 0, len(arr) - 1

    while l < r:
        mid = (l + r) // 2
        if arr[mid] < arr[mid + 1]:
            l = mid + 1
        else:
            r = mid
    return arr[l]

