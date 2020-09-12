"""
This problem was asked by Google.

Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.
"""

import random
import time
from collections import deque

def generate_random_array(size):
	arr = []
	for _ in range(size):
		arr.append(random.randint(0,1000))
	return arr

def get_sliding_max_list(array,k): # O(n)
	if k == len(array):
		maxim = max(array)
		print(maxim)
		return
	dq = []
	for index, num in enumerate(array):
		if dq and dq[0] < index + 1 - k:
			dq.pop(0)
		while dq and array[dq[-1]] < num:
			dq.pop()
		dq.append(index)

		if index <= k - 1:
			maxim = array[dq[0]]
			#print(maxim)

def get_sliding_max_stl(a, k): # O(n)

	if not a:
		return None
	if len(a) <= k:
		return max(a)

	dq = deque()

	for i in range(k):
		while dq and a[dq[-1]] < a[i]:
			dq.pop()
		dq.append(i)
	maxim = a[dq[0]]
	#print(maxim)

	for i in range(k, len(a)):
		while dq and dq[0] <= i - k:
			dq.popleft()

		while dq and a[dq[-1]] < a[i]:
			dq.pop()
		dq.append(i)
		maxim = a[dq[0]]
		#print(maxim)

def get_max_list(array,k): # O(nk)
	if(k >= len(array)):
		maxim = max(array)
		return
		#print(maxim)
	index = 0
	while(index+k <= len(array)):
		maxim = max(array[index:index+k])
		#print(maxim)
		index+=1


if __name__ == "__main__":
	random.seed(923)
	sizes = [10,100,1000,10000,100000,1000000]
	window = 6
	for size in sizes:
		array = generate_random_array(size)
		start = time.time()
		get_max_list(array,window)
		print("{:.3f}".format((time.time() - start)*10**5))

		start = time.time()
		get_sliding_max_stl(array,window)
		print("{:.3f}".format((time.time() - start)*10**5))


		start = time.time()
		get_sliding_max_list(array,window)
		print("{:.3f}".format((time.time() - start)*10**5))
		print()		