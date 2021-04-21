import matplotlib.pyplot as plt

merge = [0, 0.136, 0.273, 0.456, 0.887]
quick = [0, 0.104, 0.193, 0.364, 0.711]
bubble = [0, 1.128, 4.018, 7.583, 53.692]

inputSize = [0, 512, 1024, 2048, 4096]

plt.plot(inputSize, merge, label = "merge")
plt.plot(inputSize, quick, label = "quick")
plt.plot(inputSize, bubble, label = "bubble")

plt.xlabel('input size')
plt.ylabel('time(ms)')

plt.title('Running times of 3 different sorting algorithms')
plt.legend()

plt.show()
