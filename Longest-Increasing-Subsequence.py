# Phương thức để in LIS
def printLIS(arr: list):
    for x in arr:
        print(x, end=" ")
    print()
def constructPrintLIS(arr: list, n: int):

    l = [[] for i in range(n)]

    l[0].append(arr[0])
 

    for i in range(1, n):
 
      
        for j in range(i):
 
           
            if arr[i] > arr[j] and (len(l[i]) < len(l[j]) + 1):
                l[i] = l[j].copy()
 
  
        l[i].append(arr[i])
    maxx = l[0]
 
    for x in l:
        if len(x) > len(maxx):
            maxx = x
 

    printLIS(maxx)
 
def lis(arr):
    n = len(arr)

    lis = [1]*n
 
    for i in range(1, n):
        for j in range(0, i):
            if arr[i] > arr[j] and lis[i] < lis[j] + 1:
                lis[i] = lis[j]+1
 
    maximum = 0
 
    
    for i in range(n):
        maximum = max(maximum, lis[i])
 
    return maximum
 

if __name__ == "__main__":
 
    arr = [2, 8, 11, 3, 5, 9, 10, 4, 17, 6]
    n = len(arr)
    print ("Length of lis is", lis(arr))
    constructPrintLIS(arr, n)
 