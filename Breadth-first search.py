#             A
#        ↙       ↘   ↘
#    B           C      D
#    ↓   ↘      ↙  ↘
#    E       F        G
#   ↙  ↘      ↘
# H       I       J
import collections
graph = {
    'A': ['B', 'C', 'D'],
    'B': ['E', 'F'],
    'C': ['F', 'G'],
    'G': [],
    'D': [],
    'E': ['H', 'I'],
    'F': ['J'],
    'H': [],
    'I': [],
    'J': []
}
# BFS algorithm


def bfs(graph, root, end):

    visited, queue = set(), collections.deque([root])
    visited.add(root)

    while queue:
        
        # Xếp hàng một đỉnh từ hàng đợi
        vertex = queue.popleft()
         # Nếu nó là đỉnh cần tìm thì kết thúc chương trình
        if vertex == end:
            exit(0)
        print(str(vertex) + " ", end="")
       
      
        # Nếu không được truy cập, đánh dấu nó lại và xếp nó vào danh sách

        for neighbour in graph[vertex]:
            if neighbour not in visited:
                visited.add(neighbour)
                queue.append(neighbour)


if __name__ == '__main__':

    print("Tập Close của BFS: ")
    bfs(graph, 'A', 'G')
    #output = [A, B, C, D, E, F]
