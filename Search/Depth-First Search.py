#             A
#        ↙       ↘   ↘
#    B           C      D
#    ↓   ↘      ↙  ↘
#    E       F        G
#   ↙  ↘      ↘
# H       I       J
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
close = []
visited = set()  # Set to keep track of visited nodes.
flag = 0


def dfs(visited, graph, node, end):

    if node == end:
        print("Tập close = ")
        print(close)
        exit()
    if node not in visited:
        # print (node)
        close.append(node)  # Add Output
        visited.add(node)
        for neighbour in graph[node]:
            dfs(visited, graph, neighbour, end)


dfs(visited, graph, 'A', 'G')
# output =  ['A', 'B', 'E', 'H', 'I', 'F', 'J', 'C']