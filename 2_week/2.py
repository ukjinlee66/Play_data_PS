import itertools

def sosu(arr):
    for i in range(2, int(9999999**0.5)):
        if arr[i] == True:
            for j in range(i+i,9999999,i):
                arr[j]=False
    return arr
def solution(numbers):
    answer = 0
    arr = [True for i in range(0, 9999999)]
    arr[0]=arr[1]=False
    sosu(arr)
    new_list = list(numbers)
    for i in range (1,len(numbers) + 1):
        new_list2 = list(map(''.join, itertools.permutations(new_list,i)))
        for j in new_list2:
            nn = int(j);
            if arr[nn] == True:
                answer+=1
                arr[nn]=False
    return answer
