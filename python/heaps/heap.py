class Min_heap():
    def __init__(self, arr=[]):
        self._heap = list(arr)

        # Constructs the _heap in O(n) time.
        # Based on the knowledge that the last half of the array consists of,
        # already valid _heaps
        for i in range((len(self._heap) -1) // 2, -1, -1):
            self._bubble_down(i)
        
    def _bubble_down(self, i):
        min_idx = i
        first_child = self._get_first_child(i)

        if first_child < len(self._heap):
            if self._heap[min_idx] > self._heap[first_child]:
                min_idx = first_child

        second_child = first_child + 1
        if second_child < len(self._heap):
            if self._heap[min_idx] > self._heap[second_child]:
                min_idx = second_child

        if min_idx != i:
            self._heap[min_idx], self._heap[i] = self._heap[i], self._heap[min_idx]
            self._bubble_down(min_idx)



    def _get_first_child(self, i):
        return 2 * i + 1
    
    def peek(self):
        if len(self._heap) <= 0:
            raise Exception('heap empty')
        return self._heap[0]
    
    def pop(self):
        result = self.peek()
        self._heap[0] = self._heap[-1]
        del self._heap[-1]
        self._bubble_down(0)
        return result
        




arr = [9, 5, 3, 7, 2, 1]
heap = Min_heap(arr)
print(heap._heap)
print(heap.pop())
print(heap._heap)