package graphs;

import java.util.Set;
import java.util.function.Consumer;

public record BfsConfig<T>(T key, Set<T> vertices, BfsStates<T> states, Consumer<T> preProcess, Consumer<Edge<T>> edgeProcess, Consumer<T> postProcess) {
  public static final class Builder<T> {
    Consumer<T> preProcess = T -> {};
    Consumer<Edge<T>> edgeProcess = T -> {};
    Consumer<T> postProcess = T -> {};

    BfsStates<T> states;
    T key;
    Set<T> vertices;

    Builder(T key, Set<T> vertices) {
      this.key = key;
      this.vertices = vertices;
      this.states = BfsStates.fromVertices(vertices);
    }

    public final Builder<T> setKey(T key) {
      this.key = key;
      return this;
    }

    public final Builder<T> setStates(BfsStates<T> states) {
      this.states = states;
      return this;
    }

    public final Builder<T> setPreProcess(Consumer<T> preProcess) {
      this.preProcess = preProcess;
      return this;
    }

    public final Builder<T> setEdgeProcess(Consumer<Edge<T>> edgeProcess) {
      this.edgeProcess = edgeProcess;
      return this;
    }

    public final Builder<T> setPostProcess(Consumer<T> postProcess) {
      this.postProcess = postProcess;
      return this;
    }

    public final BfsConfig<T> build() {
      return new BfsConfig<T>(
        this.key,
        this.vertices,
        this.states,
        this.preProcess,
        this.edgeProcess,
        this.postProcess
      );
    }
  }
  
}
