class Graph:
    def __init__(self, graph):
        self.graph = graph
        self.unvisited = set(graph.keys())
        self.stack = []
    
    def topological_sort(self):
        while self.unvisited:
            node = self.unvisited.pop()
            self.unvisited.add(node)
            self.dft(node)
        return self.stack
                            
    def dft(self, node):
        for neighbour in self.graph[node]:
            if neighbour in self.unvisited:
                self.dft(neighbour)
      
        self.stack.append(node)
        self.unvisited.remove(node)

if __name__ == "__main__":
    graph = {"A": {"B", "D"}, "B": {"C"}, "C": {"E", "F"}, "D": {"F"}, "E": {}, "F": {}}

    my_graph = Graph(graph)
    print(my_graph.topological_sort())
