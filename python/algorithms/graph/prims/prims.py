from collections import defaultdict
from operator import itemgetter


class Graph:
    def __init__(self, adj_list, is_directed):
        self.graph = adj_list
        self.is_directed = is_directed

    @classmethod
    def from_edge_list(cls, edge_list, is_directed=False):
        adj_list = defaultdict(dict)
        for u, v, w in edge_list:
            adj_list[u][v] = w
            if not is_directed:
                adj_list[v][u] = w

        return cls.from_adj_list(adj_list, is_directed)

    @classmethod
    def from_adj_list(cls, adj_list, is_directed=False):
        return cls(adj_list, is_directed)

    def prims(self):
        """
        Algorithm for finding the min cost spanning tree for a connected graph/component.
        Doesn't work for directed graphs as the algorithm assumes there's a path from any node, to any other node.
        
        1. Find the min cost edge
        2. Create a tree and add the to vertices from the edge above
        3. Create a collection of nearest elements that maps from each vertex in the graph to the nearest vertex in the MST (the two nodes from the edge in step 1)
            The distance for nodes already in the tree should be 0.
        4. While not all the elements in nearest are 0:
            4.1 Add the node with the minimum distance in nearest, to the tree
            4.2 Go through all the elements in nearest, and update them if the new node is closer.
        """
        if self.is_directed:
            raise ValueError("Prim's doesn't work on directed graphs.")

        mst = defaultdict(dict)
        if not self.graph:
            return mst

        u, v, w = None, None, float("inf")
        for vertex, neighbours in self.graph.items():
            curr_v, curr_w = min(neighbours.items(), key=itemgetter(1))
            if curr_w < w:
                u, v, w = vertex, curr_v, curr_w
        mst[u][v] = w
        mst[v][u] = w

        nearness = {}
        for node in self.graph:
            if node == u or node == v:
                continue

            nearness[node] = u
            if v in self.graph[node] and (not u in self.graph[node] or self.graph[node][v] > self.graph[node][u]):
                nearness[node] = v
            

        while nearness:
            nearest, nearest_dist = None, float("inf") 
            for node, neighbour in nearness.items():

                if neighbour in self.graph[node] and self.graph[node][neighbour] < nearest_dist:
                    nearest, nearest_dist = node, self.graph[node][neighbour]

            mst[nearest][nearness[nearest]] = nearest_dist
            mst[nearness[nearest]][nearest] = nearest_dist
            del nearness[nearest]

            for node, neighbour in nearness.items():
                if nearest in self.graph[node] and self.graph[node][nearest] < self.graph[node][neighbour]:
                    nearness[node] = nearest
        return mst








if __name__ == "__main__":
    graph = Graph.from_edge_list(
        [(1, 2, 3), (1, 4, 1), (3, 4, 2),(3, 2, 4)]
    )

    print("original")
    print(graph.graph)
    print(graph.prims())
            

        

        

            
    