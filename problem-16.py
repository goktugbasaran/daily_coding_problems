"""
This problem was asked by Twitter.

You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to accomplish this, with the following API:

record(order_id): adds the order_id to the log
get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N.
You should be as efficient with time and space as possible.
"""

class NLogger:
	def __init__(self,N):
		self.orders = []
		self.index = 0
		self.size = N

	def record(self,order_id):
		if(len(self.orders) < self.size): # If N is too large, it should not allocate
			self.orders.append(order_id) # too much recourse in the beginning.
		else:
			self.orders[self.index] = order_id
			self.index = (self.index + 1) % self.size

	def getLast(i):
		return self.orders[ (self.index + self.size - i) % self.size]

	def __str__(self):
		return "{}".format(self.orders)


if __name__ == "__main__":
	orders = [0,1,2,3,4,5,6,7,8,9]
	logger = NLogger(3)
	for order in orders:
		logger.record(order)
		print(logger)
