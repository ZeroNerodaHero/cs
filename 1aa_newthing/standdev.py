def ex(n):
	if(n <= 1): return 1
	return ex(n-1) * n

def com(n,k):
	return ex(n)/(ex(k) * ex(n-k))

n = input("Enter number of shits:")
p = input("Enter pecent the shit:")
print(com(4,2))
for i in range(0,n+1):
	print n,"C",i

	j = com(n,i) * (p**i) * ((1-p)**(n-i))
	print(j)
