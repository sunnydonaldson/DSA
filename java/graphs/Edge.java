package graphs;

public class Edge<T> {
    public final T from;
    public final T to;
    Integer weight;

    public Edge(T from, T to, Integer weight) {
        this.from = from;
        this.to = to;
        this.weight = weight;
    }

    public Edge(T from, T to) {
        this(from, to, 0);
    }

    public final Edge<T> reversed() {
       return new Edge<T>(this.to, this.from, this.weight);
    }
}
