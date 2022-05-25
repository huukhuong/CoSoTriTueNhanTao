#             A
#        ↙       ↘   ↘
#    B           C      D
#    ↓   ↘      ↙  ↘
#    E       F        G
#   ↙  ↘      ↘
# H       I       J

#   Hàng đợi   vs            Đỉnh u              Hàng đợi for               Các đỉnh v kề u           Hàng đợi sau khi  queue
#                    (lấy từ hàng đợi)       (sau khi lấy u ra)            mà chưa xét                đẩy v vào
#   A                        A                  0                           B,C,D                       B,C,D
#   B,C,D                    B                  C,D                         E,F                         C,D,E,F
#   C,D,E,F                  C                  D,E,F                       F,G                         D,E,F,G
#   D,E,F,G                  D                  E,F,G                       0                           E,F,G
#   E,F,G                    E                  F,G                         H,I                         F,G,H,I
#   F,G,H,I                  F                  G,H,I                       J                           G,H,I,J
#   G,H,I,J                  G                  H,I,J                       0                           H,I,J
#   H,I,J                    H                  I,J                         0                           I,J    
#   I,J                      I                  J                           0                           J
#   J                        J                  0                           0                           0


                                         
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
#khanh

def bfs(graph, root, end):

    visited, queue = set(), collections.deque([root]) #tao 2 hàng đợi;
    visited.add(root)

    while queue:
        
      
        vertex = queue.popleft()     #Lấy phần tử đầu tiên trong hàng đợi
         # Nếu nó là đỉnh cần tìm thì kết thúc chương trình
        if vertex == end:
            exit(0)
        print(str(vertex) + " ", end="")
       
      
      # Lấy tất cả các đỉnh liền kề của đỉnh vertex trong đồ thị. 

        for neighbour in graph[vertex]:
            if neighbour not in visited:        #Nếu một các đỉnh liền kề của vertex đang xét chưa được truy cập, 
                visited.add(neighbour)          #đánh dấu nó đã được truy cập và xếp hàng
                queue.append(neighbour)


if __name__ == '__main__':

    print("Tập Close của BFS: ")
    bfs(graph, 'A', 'G')
    #output = [A, B, C, D, E, F]
