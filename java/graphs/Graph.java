package graphs;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Graph<T> {
    final Map<T, GraphNode<T>> graph = new HashMap<>();
    final boolean isDirected;

    public Graph(boolean isDirected) {
        this.isDirected = isDirected;
    }

    public static final <T> Graph<T> fromEdges(boolean isDirected, List<Edge<T>> edges) {
        final Graph<T> graph = new Graph<T>(isDirected);

        edges.forEach(graph::addEdge);

        return graph;
    }

    public final void addEdge(Edge<T> edge) {
       this.insertEdge(edge);

       if (!this.isDirected) {
           this.insertEdge(edge.reversed());
       }
    }

    private final void insertEdge(Edge<T> edge) {
        this.graph.computeIfAbsent(edge.from, u -> new GraphNode<T>(edge.from));
        this.graph.get(edge.from).addNeighbour(edge.to, edge.weight);
    }

    final Set<T> getNeighbours(T key) {
        return graph.get(key)
            .getNeighbours()
            .keySet();
    }

    public final Integer numConnectedComponents() {
        BfsStates<T> states = BfsStates.fromVertices(this.graph.keySet());

        int count = 0;
        while (!states.undiscovered.isEmpty()) {
            Bfs(sample(states.undiscovered), states);
            count++;
        }
        return count;
    }

   public final BfsResult<T> Bfs(T key) {
    return Bfs(key, BfsStates.fromVertices(this.graph.keySet()));
   } 

    private final BfsResult<T> Bfs(T key, BfsStates<T> states) {
        Deque<T> queue = new ArrayDeque<>(List.of(key));
        Map<T, T> parents = new HashMap<>();
    
        while (!queue.isEmpty()) {
          T current = queue.pop();
          // Add option to pre-process vertex here.
          // Add a foreach with optional processing of the edge here.
          this.getNeighbours(current).stream()
            .filter(n -> states.get(n).equals(VertexState.UNDISCOVERED))
            .forEach(n -> {
              states.update(n);
              parents.put(n, current);
              queue.add(n);
            });
          // Optional post-processing here.
          states.update(current);
        }

        return new BfsResult<>(states, parents);
      }
    
    private static final <T> T sample(Set<T> set) {
        return set.stream()
            .findFirst()
            .orElseThrow(() -> new IllegalArgumentException("Can't sample empty set"));
    }

    @Override
    public String toString() {
        return this.graph.values().toString();
    }
}