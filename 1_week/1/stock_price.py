def solution(prices):
    answer = [0] * len(prices)
    # prices 크기만큼 빈 리스트를 할당.
    for i in range(0,len(prices)):
        for j in range(i + 1, len(prices)):
            answer[i] += 1
            if prices[i]>prices[j]:
                break;
    return answer
