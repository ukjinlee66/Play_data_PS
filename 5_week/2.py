def solution(participant, completion):
    answer = ''
    new_dic = {}
    for i in participant:
        if i in new_dic:
            new_dic[i] +=1
        else:
            new_dic[i] = 1
    for j in completion:
        if j in new_dic:
            new_dic[j] -=1
    for key, val in new_dic.items():
        if val == 1:
            answer = key
            break
    return answer
