package graphs;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.stream.Stream;

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

    final Stream<Edge<T>> getNeighbourEdges(T vertex) {
        return graph.get(vertex)
            .getNeighbours().keySet().stream()
            .map(n -> new Edge<>(vertex, n));
    }

    public final Integer numConnectedComponents() {
        Set<T> vertices = this.graph.keySet();
        BfsConfig.Builder<T> config = new BfsConfig.Builder<T>(sample(vertices), vertices);
        Set<T> undiscovered = config.states.undiscovered;

        int count = 0;
        while (!undiscovered.isEmpty()) {
            Bfs(config.setKey(sample(undiscovered)).build());
            count++;
        }
        return count;
    }

    private final BfsResult<T> Bfs(BfsConfig<T> config) {
        Deque<T> queue = new ArrayDeque<>(List.of(config.key()));
        Map<T, T> parents = new HashMap<>();
    
        while (!queue.isEmpty()) {
          T current = queue.pop();
          config.preProcess().accept(current);

          this.getNeighbourEdges(current)
            .peek(n -> config.edgeProcess().accept(n))
            .map(n -> n.to)
            .filter(n -> config.states().get(n).equals(VertexState.UNDISCOVERED))
            .forEach(n -> {
              config.states().update(n);
              parents.put(n, current);
              queue.add(n);
            });
            config.postProcess().accept(current);
            config.states().update(current);
        }

        return new BfsResult<>(config.states(), parents);
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