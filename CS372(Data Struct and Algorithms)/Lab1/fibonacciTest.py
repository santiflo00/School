"""
FILE: fibonacciTest.py
Written by: Santiago Flores
8/31/20
Purpose: Test the two functions to see if they run correctly. Take user input 
to find a fibonacci number using the given input n. Finds the runtime of each 
function

"""

from fibonacci import fib1
from fibonacci import fib2
import time

#test function 1 exponential algorithm
def testFib1():
	a = [0,1,1,2,3,5,8,13,21,34,55]
	for i in range(0,10):
		if (a[i] != fib1(i)):
			print('Error in function fib1 ')
			return
	print('fib1 passed test from 0 to 10')

#test for function 2 polynomial algorithm
def testFib2():
	a = [0,1,1,2,3,5,8,13,21,34,55]
	for i in range(0,10):
		if (a[i] != fib2(i)):
			print('Error in function fib2 at index {i}')
			return
	print('fib2 passed test from 0 to 10')

#test that the functions are working properly
testFib1()
testFib2()

#each functions gives the requested fibonacci number and records the time it takes
n = int(input('Enter an integer for n: '))

start_time = time.time()
answer = fib1(n)
end_time = time.time() - start_time
print("fib1 answer: {} with time: {} seconds ---".format(answer, end_time))

start_time = time.time()
answer = fib2(n)
end_time = time.time() - start_time
print("fib2 answer: {} with time: {} seconds ---".format(answer, end_time))


