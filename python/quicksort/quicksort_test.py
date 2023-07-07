import unittest
from quicksort import quicksort

class QuicksortTest(unittest.TestCase):
    def test_quicksort_empty_list_returns_empty_list(self):
        arr = []

        quicksort(arr, 0, -1)

        self.assertEqual([], arr)

    def test_quicksort_returns_sorted(self):
        unordered = [9, 8, 7, 6, 5, 4]
        ordered = sorted(unordered)
        quicksort(unordered, 0, len(unordered) - 1)

        self.assertEqual(ordered, unordered)

if __name__ == "__main__":
    unittest.main()
    
