"""
FILE: fibonacci.py
Written by: Santiago Flores
8/31/20
Purpose: Find the fibonacci numbers using two different algorithms
one that has an exponetial runtime and one that has a polynomial runtime

"""

#fibonacci sequence using exponential algorithm
def fib1(n):
	if (n == 0):
		return 0
	if (n == 1):
		return 1
	return fib1(n-1) + fib1(n-2)

#fibonacci sequence using polynomial algorithm
def fib2(n):
	if (n == 0):
		return 0
	if (n == 1):
		return 1
	f = [0,1]
	i = 2
	for i in range(2,n+1):
		f.append(f[i-1] + f[i-2])
	return f[n]


