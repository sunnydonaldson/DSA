package graphs;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Edge<Integer>> edges = List.of(
                new Edge<Integer>(1, 2),
                new Edge<Integer>(2, 3),
                new Edge<Integer>(2, 4),
                new Edge<Integer>(3, 4),
                new Edge<Integer>(4, 1)
        );

        Graph<Integer> graph = Graph.fromEdges(false, edges);
        System.out.println(graph);
    }
}
