import unittest
from largest_in_unimodal_array import find_largest_in_unimodal_array

class LargestInUnimodalArrayTest(unittest.TestCase):
    def test_empty_array_returns_none(self):
        result = find_largest_in_unimodal_array([])

        self.assertEqual(result, None)

    def test_single_element_returns_element(self):
        result = find_largest_in_unimodal_array([4])

        self.assertEqual(result, 4)

    def test_largest_in_left_side_returns_largest(self):
        result = find_largest_in_unimodal_array([1, 3, 11, 10, 2, -1, -4, -5])

        self.assertEqual(result, 11)

    def test_arbitrary_case_returns_largest(self):
        result = find_largest_in_unimodal_array([1, 4, 7, 9, 10, 12, 6, 4, 2])

        self.assertEqual(result, 12)

if __name__ == "__main__":
    unittest.main()