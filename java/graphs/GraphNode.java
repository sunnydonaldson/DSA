package graphs;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class GraphNode<T> {
    private final T val;
    private final Map<T, Integer> neighbours = new HashMap<>();

    public GraphNode(T val) {
        this.val = val;
    }

    public void addNeighbour(T neighbour) {
        this.addNeighbour(neighbour, 0);
    }

    public void addNeighbour(T neighbour, Integer weight) {
       this.neighbours.put(neighbour, weight);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.val).append(": {");

        this.neighbours.forEach((k, v) -> {
            sb.append('(')
                    .append(k)
                    .append(", ")
                    .append(v)
                    .append("), ");
        });
        sb.replace(sb.length() - 2, sb.length(), "}\n");
        return sb.toString();
    }
}
