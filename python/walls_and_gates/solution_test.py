import unittest
from solution import Solution

class SolutionTest(unittest.TestCase):
    def test_walls_and_gates_returns_correct(self):
        input = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
        output = [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
        Solution().walls_and_gates(input)

        self.assertTrue(input == output)

if __name__ == "__main__":
    unittest.main()
