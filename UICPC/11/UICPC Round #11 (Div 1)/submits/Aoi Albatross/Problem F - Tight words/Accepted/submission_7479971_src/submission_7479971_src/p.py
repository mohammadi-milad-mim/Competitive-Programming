import sys


for line in sys.stdin:
	k, n = map(int, line.split(' '))
	k = k + 1
	dp = [[0] * (k + 10) for _ in range(n + 10)]

	for i in range(1, k + 1):
		dp[1][i] = 1  

	for i in range(2, n + 1):
		for j in range(1, k + 1):
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1]

	ans = 0
	for i in range(0, k + 1):
		ans = ans + dp[n][i]

	print("%.9f" %(ans / (k ** n) * 100))