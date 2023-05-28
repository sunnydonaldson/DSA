class Solution():
    """
    A researcher has index h if they've published:
    at least h papers with h or more citations, with the other n - h papers having less than h
    """
    def h_index(citations):
        citations = sorted(citations, reverse=True)
        for i, el in enumerate(citations):
            if i + 1 >= el:
                return el
    
    citations = [7, 6, 5, 3, 1]
                [1, 2, 3, 4, 5]
    print(h_index(citations))
    
