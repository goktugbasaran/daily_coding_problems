from random import randint
from time import time
'''
Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

'''


def largestSum(array):

	incP = 0
	excP = 0

	for i in array:
		currentMax = excP if excP > incP else incP
		incP = excP + i
		excP = currentMax
	return max(excP, incP)


if __name__ == "__main__":

	sizes = [10, 100, 1000, 10000, 100000, 1000000]
	for size in sizes:
		arr = []
		for i in range(0, size):
			arr.append(randint(-10000, 10000))
		start = time()
		largestSum(arr)
		print((time()-start))
