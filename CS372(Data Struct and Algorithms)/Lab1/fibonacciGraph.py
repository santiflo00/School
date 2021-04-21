"""
FILE: fibonacciGraph.py
Written by: Santiago Flores
8/31/20
Purpose: Create a graph of the runtimes of each algorithm

"""
from fibonacci import fib1
from fibonacci import fib2
import matplotlib.pyplot as plt
import numpy as np
import time

plt.xlabel('n')
plt.ylabel('Time')
plt.title('Running time of two fibonacci algorithms')

x = [0,1,5,10,15,20,25,30,35]
#values taken from plugging in x values into fibonacciTest and multiplying by 10^5
expY = [0]
polyY = [0] 
for i in range(0,8):
	start_time = time.time()
	fib1(x[i])
	expY.append(time.time() - start_time)
	start_time = time.time()
	fib2(x[i])
	polyY.append(time.time() - start_time)

plt.plot(x, expY, label = "Exponential(fib1)")
plt.plot(x, polyY, label = "Polynomial(fib2)")

plt.legend()
plt.show()
