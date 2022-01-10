def solution(n, lost, reserve):
    answer = 0
    students = [0] * n
    for l in lost:
        students[l-1] -= 1
    for r in reserve:
        students[r-1] += 1
    answer = n
    for i in range(n):
        v = students[i]
        if v == -1:
            if i >= 1 and students[i-1] == 1:
                pass
            elif i < n - 1 and students[i+1] == 1:
                students[i+1] = 0
            else:
                answer -= 1
    return answer
