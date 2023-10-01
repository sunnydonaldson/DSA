package graphs;

import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Edge<Integer>> edges = List.of(
                new Edge<Integer>(1, 2),
                new Edge<Integer>(2, 4),
                new Edge<>(3, 2)
        );

        Graph<Integer> graph = Graph.fromEdges(false, edges);
        System.out.println(graph);

        System.out.printf("isBipartite? %b%n", graph.isBipartite());

        graph.addEdge(new Edge<>(3, 4));
        System.out.println(graph);
        System.out.printf("isBipartite? %b%n", graph.isBipartite());

        graph.addEdge(new Edge<>(20, 21));
        graph.addEdge(new Edge<>(30, 21));
        graph.addEdge(new Edge<>(23, 25));

        System.out.println(graph.numConnectedComponents());

    }
}
