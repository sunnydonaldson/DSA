package graphs;

import java.util.HashSet;
import java.util.Set;

public class BfsStates<T> {
  final Set<T> undiscovered = new HashSet<T>();
  final Set<T> discovered = new HashSet<T>();
  final Set<T> processed = new HashSet<T>();

  private BfsStates(Set<T> vertices) {
    this.undiscovered.addAll(vertices);
  }

  public static final <T> BfsStates<T> fromGraph(Graph<T> graph) {
    return new BfsStates<T>(graph.graph.keySet());
  }

  public final void update(T key) {
    switch (this.get(key)) {
      case UNDISCOVERED:
        this.undiscovered.remove(key);
        this.discovered.add(key);
        break;
      case DISCOVERED:
        this.discovered.remove(key);
        this.processed.add(key);
        break;
      case PROCESSED:
        throw new IllegalStateException("PROCESSED node can't change state.");
    }
  }

  public final VertexState get(T key) {
    if (this.undiscovered.contains(key)) {
      return VertexState.UNDISCOVERED;
    } else if (this.discovered.contains(key)) {
      return VertexState.DISCOVERED;
    } else if (this.processed.contains(key)) {
      return VertexState.PROCESSED;
    } else {
      throw new IllegalArgumentException("State not tracked for vertex: " + key);
    }
  }
}
