from sys import maxsize
from itertools import permutations

V = 4

def travellingSalesmanProblem(graph, s):
    #lưu trữ tất cả các đỉnh ngoài đỉnh nguồn
    vertex = []
    for i in range(V):
        if i != s:
            #nếu như i khác đỉnh gốc thì lưu i vào vertex
            vertex.append(i)
    # chi phí thấp nhất
    min_path = maxsize
    next_permutation = permutations(vertex)
    for i in next_permutation:
        #chi phí hiện tại
        current_pathweight = 0
        # khởi tạo vị trí hiện tại bằng vị trí xuất phát
        k = s
        for j in i:
           
            current_pathweight += graph[k][j]
            k = j
        current_pathweight += graph[k][s]
        #cập nhật chi phí
        min_path = min(min_path, current_pathweight)

    return min_path


if _name_ == "_main_":
    graph = [[0, 20, 35, 10],
             [20, 0, 90, 50],
             [35, 90, 0, 12],
             [10, 50, 12, 0]]
    s = 0
    print(travellingSalesmanProblem(graph, s))
