def cal(num):
	ret = 1
	for i in range(num,0, -1):
		ret *= i
	return ret

val = input()
print(cal(int(val)))
