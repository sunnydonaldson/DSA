import unittest
from dijkstra import dijkstra


class DijkstraTest(unittest.TestCase):
    def test_a_to_a_returns_0(self):
        graph = {1:{}}
        self.assertEqual(dijkstra(1, 1, graph), 0)

    def test_acyclic_graph(self):
        graph = {
            1: {
                2: 2,
                3: 4
            },        
            2: {
                3: 1
            },
            3: {}
        }

        self.assertEqual(dijkstra(1, 3, graph), 3)

if __name__ == "__main__":
    unittest.main()
    
