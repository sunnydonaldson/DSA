import unittest
from quicksort import quicksort

class QuicksortTest(unittest.TestCase):
    def test_quicksort_empty_list_returns_empty_list(self):
        self.assertTrue(quicksort([], 0, -1) == [])

    def test_quicksort_returns_sorted(self):
        unsorted = [9, 8, 7, 6, 5, 4]
        print(f'nums: {unsorted}')
        self.assertTrue(sorted(unsorted) == quicksort(unsorted, 0, len(unsorted) -1))

if __name__ == "__main__":
    unittest.main()
    
