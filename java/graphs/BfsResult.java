package graphs;

import java.util.Map;

public record BfsResult<T>(BfsStates<T> states, Map<T, T> parents) {}
