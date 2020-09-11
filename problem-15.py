"""
This problem was asked by Facebook.
Given a stream of elements too large to store in memory, pick a random element
from the stream with uniform probability.

https://stackoverflow.com/questions/23351918/select-an-element-from-a-stream-with-uniform-distributed-probability

"""

import random
from datetime import datetime

def stream_generator(num):
    for x in xrange(num):
        yield x


def pick_random(stream):
	index = 0
	picked_number = None 

	for element in stream:
		index+=1
		if( random.random() <= ( 1.0/index )):
			picked_number = element
	return picked_number



if __name__ == "__main__":
	random.seed(datetime.now())
	sample_size = 10000
	number = pick_random(stream_generator(sample_size))