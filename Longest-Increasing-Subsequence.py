# Phương thức để in LIS
def printLIS(arr: list):
    for x in arr:
        print(x, end=" ")
    print()
 
# Function print Longest Increasing
def constructPrintLIS(arr: list, n: int):
 
    # L[i] - The longest increasing sub-sequence
   
    l = [[] for i in range(n)]
 
    # L[0] is equal to arr[0]
    l[0].append(arr[0])
 
    # start from index 1
    for i in range(1, n):
 
        # do for every j less than i
        for j in range(i):
 
            # L[i] = {Max(L[j])} + arr[i]
            # where j < i and arr[j] < arr[i]
            if arr[i] > arr[j] and (len(l[i]) < len(l[j]) + 1):
                l[i] = l[j].copy()
 
        # L[i] ends with arr[i]
        l[i].append(arr[i])
 
    # L[i] now stores increasing sub-sequence of
    # arr[0..i] that ends with arr[i]
    maxx = l[0]
 
    # LIS will be max of all increasing sub-
    # sequences of arr
    for x in l:
        if len(x) > len(maxx):
            maxx = x
 
    # max will contain LIS
    printLIS(maxx)
 
# Driver Code
if __name__ == "__main__":
 
    arr = [2, 8, 11, 3, 5, 9, 10, 4, 17, 6]
    n = len(arr)
 
    # construct and print LIS of arr
    constructPrintLIS(arr, n)
 
