import heapq
"""
    time: O(vlogv + vloge), where v is the number of verteces, and e the number of edges
    space: O(v + e)

    You could optimise this using a fibonacci heap, which allows you to decrease the keys (D[v] = ...)
    in O(1) time instead of O(loge).  Resulting in a total O(vlogv + e) solution
"""
def dijkstra(src, dest, graph):
    P = {src: None} # predecessors
    V = set() # visited
    D = {v: float("inf") for v in graph.keys()} # queue
    D[src] = 0
    Q = [(d, v) for v, d in D.items()] # distances
    heapq.heapify(Q)

    while Q:
        d, u = heapq.heappop(Q) # distance, current

        if u in V:
            continue
        V.add(u)

        for v, w in graph[u].items(): # vertex, weight
            if d + w < D[v]:
                D[v] = d + w
                predecessors[v] = w
                heapq.heappush(Q, (D[v], v))

    # It might be more useful to return P and D instead, then you can find the shortest path from src to *any* node
    return D[dest]

        

