package graphs;

import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.List;

public class Bfs<T> {
  Graph<T> graph;
  BfsStates<T> states;
  Map<T, T> parents = new HashMap<>();

  public Bfs(Graph<T> graph) {
    this.graph = graph;
    this.states = BfsStates.fromGraph(graph); 
  }

  public final boolean searchUndiscovered() {
    if (this.states.undiscovered.isEmpty()) {
      return false;
    }

    T el = this.states.undiscovered.stream()
      .skip(new Random().nextInt(this.states.undiscovered.size()))
      .findFirst()
      .get();
    
    this.search(el);
    return true;
  }

  public final void search(T key) {
    Deque<T> queue = new ArrayDeque<>(List.of(key));

    while (!queue.isEmpty()) {
      T current = queue.pop();
      // Add option to pre-process vertex here.
      // Add a foreach with optional processing of the edge here.
      graph.getNeighbours(current).stream()
        .filter(n -> this.states.get(n).equals(VertexState.UNDISCOVERED))
        .forEach(n -> {
          this.states.update(n);
          this.parents.put(n, current);
          queue.add(n);
        });
      // Optional post-processing here.
      this.states.update(current);
    }
  }
}
