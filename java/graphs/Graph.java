package graphs;

import java.util.*;

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
        Bfs<T> bfs = new Bfs<T>(this);

        int count = 0;
        while (bfs.searchUndiscovered()) {
            count++;
        }
        return count;
    }

    @Override
    public String toString() {
        return this.graph.values().toString();
    }
}