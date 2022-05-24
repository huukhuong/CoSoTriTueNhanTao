
from multiprocessing.reduction import steal_handle
from queue import PriorityQueue
import copy
from random import randint
import time


class State:
    def __init__(self, data=None, par=None, g=0, h=0, op=None):
        self.data = data
        self.g = g
        self.h = h
        self.par = par
        self.op = op

    def clone(self):
        sn = copy.deepcopy(self)
        return sn

    def Print(self):
        sz = 3
        for i in range(sz):
            for j in range(sz):
                print(self.data[i * sz + j], end=' ')
            print()
        print()

    def Key(self):
        if self.data == None:
            return None
        res = ''
        for x in self.data:
            res += (str)(x)
        return res

    def __lt__(self, other):
        if other == None:
            return False
        return self.g + self.h < other.g + other.h

    def __eq__(self, other):
        if other == None:
            return False
        return self.Key() == other.Key()

class Operator:
    def __init__(self, i):
        self.i = i

    def Up(self, s):
        if self.checkStateNull(s) == True:
            return None
        x, y = self.findPos(s)
        if x == 2:
            return None
        return self.swap(s, x, y, self.i)

    def Down(self, s):
        if self.checkStateNull(s)  == True:
            return None
        x, y = self.findPos(s)
        if x == 0:
            return None
        return self.swap(s, x, y, self.i)

    def Left(self, s):
        if self.checkStateNull(s) == True:
            return None
        x, y = self.findPos(s)
        if y == 2:
            return None
        return self.swap(s, x, y, self.i)

    def Right(self, s):
        if self.checkStateNull(s) == True:
            return None
        x, y = self.findPos(s)
        if y == 0:
            return None
        return self.swap(s, x, y, self.i)

    # Kiểm tra trạng thái s.data == null
    def checkStateNull(self, s):
        return s.data == None
    # Tìm vị trí x,y của hàng và cột xuất hiện số 0
    def findPos(self, s):
        sz = 3
        for i in range(sz):
            for j in range(sz):
                if s.data[i * sz + j] == 0:
                    return i, j
        return None
   # Hoán đổi vị trí x,y theo hàng cột mong muốn
    def swap(self, s, x, y, i):
        sz = 3
        sn = s.clone()
        x_new = x
        y_new = y
        # xet up down
        if i == 0:
            x_new = x + 1
            y_new = y
        if i == 1:
            x_new = x - 1
            y_new = y
        if i == 2:
            x_new = x
            y_new = y + 1
        if i == 3:
            x_new = x
            y_new = y - 1
        sn.data[x * sz + y] = s.data[x_new * sz + y_new]
        sn.data[x_new * sz + y_new] = 0
        return sn
# di chuyển lên xuống trái phải
    def Move(self, s):
        global noofMoves 

        if self.i == 0:
            noofMoves += 1 
            return self.Up(s)

        if self.i == 1:
            noofMoves += 1 
            return self.Down(s)
        if self.i == 2:
            noofMoves += 1 
            return self.Left(s)
        if self.i == 3:
            noofMoves += 1 
            return self.Right(s)
        return None


def checkInPriority(Open, tmp):
    if tmp == None:
        return False
    return (tmp in Open.queue)


def Equal(O, G):
    if O == None:
        return False
    return O.Key() == G.Key()

# vẽ đường đi
def Path(O):
    if O.par != None:
        Path(O.par)
        if O.op.i == 0:
            print("UP")
        if O.op.i == 1:
            print("DOWN")
        if O.op.i == 2:
            print("LEFT")
        if O.op.i == 3:
            print("RIGHT")
    O.Print()

#kiểm tra sự sai khác của vị trí hiện tại S, so với vị trí đích G
def Hx(S, G):
    sz = 3
    res = 0
    for i in range(sz):
        for j in range(sz):
            if S.data[i * sz + j] != G.data[i * sz+j]:
                res += 1
    return res

noofMoves = 0 

def RUN():
    #tạo hàng đợi
    Open = PriorityQueue()
    Closed = PriorityQueue()
    S.g = 0
    S.h = Hx(S, G)
    Open.put(S)
    
    while True:
        if Open.empty() == True:
            print("Tim kiem that bai")
            return
        O = Open.get()
        Closed.put(O)
        if Equal(O, G) == True:
            print("Tim thay")
            Path(O)
            return
        #sinh ra các trạng thái con
        for i in range(4):
            op = Operator(i)
            child = op.Move(O)
           # noofMoves += 1
            if child == None:
                continue
            ok1 = checkInPriority(Open, child)
            ok2 = checkInPriority(Closed, child)
            if not ok1 and not ok2:
                child.par = O
                child.op = op
                child.g = O.g + 1
                child.h = Hx(child, G)
                Open.put(child)


'''def init(num):
    G = State()
    sz = 3
    G.data = []
    for i in range(sz):
        for j in range(sz):
            G.data.append((i * sz + j + 1) % 9)
    print(G.data)
    S = G.clone()
    for i in range(num):
        op = Operator(randint(0, 3))
        tmp = op.Move(S)
        if tmp != None:
            S = tmp
    print(S.data)
    return S, G
'''



S = State()
S.data = [1, 5, 2,
          4, 0, 3,
          7, 8, 6] # Start
G = State()
G.data = [1, 2, 3,
          4, 5, 6,
          7, 8, 0] # Goal

print("Tập S")
S.Print()
print("Tập G")
G.Print()
print("-----------------------------------------")
RUN()
print("Độ dài =" , noofMoves)

