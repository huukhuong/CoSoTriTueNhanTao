from collections import defaultdict
from queue import PriorityQueue

data = defaultdict(list)
data['A'] = ['B', 'C', 'D', 6] //giá trị cuối cùng của hàm đánh giá tại đỉnh a
data['B'] = ['E', 'F', 3]
data['C'] = ['G', 'H', 4]
data['D'] = ['I', 'J', 5]
data['E'] = [3]
data['F'] = ['K', 'L', 'M', 1]
data['G'] = [6]
data['H'] = ['N', 'O', 2]
data['I'] = [5]
data['J'] = [4]
data['K'] = [2]
data['L'] = [0]
data['M'] = [4]
data['N'] = [0]
data['O'] = [4]


class Node:

    def __init__(self, name, par=None, h=0): //h là hàm đánh giá tại mỗi đỉnh đó 
        self.name = name
        self.par = par
        self.h = h

    def display(self):
        print(self.name, self.h)

    def __lt__(self, other): //so sánh thằng nào nhỏ hơn
        if (other == None):
            return False
        return self.h < other.h

    def __eq__(self, other):
        if other == None:
            return False
        return self.name == other.name


def equal(O, G):
    if O.name == G.name:
        return True
    return False


def CheckInPriority(tmp, c): //kt thuộc priotiry
    if tmp == None:
        return False
    return (tmp in c.queue)


def getPath(O, distance): //truy vết ngược lại tìm tổng trọng số
    print(O.name)
    distance += O.h   //truy vết ngược trạng thái cha của nó rồi cộng dồn cái giá trị tại cái đỉnh cha
    if O.par != None:
        getPath(O.par, distance)
    else:
        print('distance', distance)
        return


def bfs(S=Node('A'), G=Node('N')): // xuất phát từ đỉnh A kết thúc tại đỉnh N
    global name
    Open = PriorityQueue()
    Closed = PriorityQueue()
    S.h = data[S.name][-1] //-1 là truy xuất đến phần tử cuối cùng của cái data 
    Open.put(S)
    while True:
        if Open.empty(): // kiểm tra có rỗng hay k
            print('tim kiem that bai')
            return
        O = Open.get() 
        Closed.put(O) //cho O vào close
        print('Duyet:', O.name, O.h)
        if equal(O, G):
            print('tim kiem thanh cong!')
            distance = 0
            getPath(O, distance)
            return

        // nếu O k bằng g kiểm tra tất cả các con của O
        i = 0
        while i < len(data[O.name]) - 1: //duyệt tới gần cuối
            name = data[O.name][i]
            h = data[name][-1]

            tmp = Node(name=name, h=h)
            tmp.par = O

            ok1 = CheckInPriority(tmp, Open)
            ok2 = CheckInPriority(tmp, Closed)

            if not ok1 and not ok2:
                Open.put(tmp)

            i += 1


bfs(Node('A'), Node('N'))
