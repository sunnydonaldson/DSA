from typing import (
    List,
    Tuple,
)

class Solution:
    """
    @param rooms: m x n 2D grid
    @return: nothing
    """
    def walls_and_gates(self, rooms: List[List[int]]):
        # write your code here
        Solution.bfs(rooms, (0, 0))

    @classmethod
    def bfs(cls, rooms: List[List[int]], point: Tuple[int, int]) -> int:
        row, col = point
        val = rooms[row][col]
        if val == 0:
            return 1
        elif val == -1:
            return

        for neighbour in Solution.get_neighbours(rooms, point):
            if rooms[neigbour[0]][neighbour[1]] !=
            distance_to_gate = Solution.bfs(rooms, neighbour)
            if distance_to_gate is not None:
                rooms[row][col] = min(rooms[row][col], distance_to_gate)
        return rooms[row][col] + 1
    
    @classmethod
    def get_neighbours(cls, rooms: List[List[int]], point: Tuple[int, int]) -> List[Tuple[int, int]]:
        row, col = point
        num_rows, num_cols = len(rooms), len(rooms[0])
        neighbours = []
        if row + 1 < num_rows:
            neighbours.append((row + 1, col))
        if row - 1 >= 0:
            neighbours.append((row - 1, col))
        if col + 1 < num_cols:
            neighbours.append((row, col + 1))
        if col -1 >= 0:
            neighbours.append((row, col - 1))
        
        return neighbours
