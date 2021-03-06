"""
This problem was asked by Google.

The area of a circle is defined as πr^2. 

Estimate π to 3 decimal places using a Monte Carlo method.

Hint: The basic equation of a circle is x2 + y2 = r2.
"""	

from random import randrange,seed,randint
seed(1)

def estimatePi(r,N):
	inside=0
	outside=0
	r = 2500
	for i in range(N):
		x = randint(-r,r)
		y = randint(-r,r)
		if(x*x+y*y<=r*r):
			inside+=1	
	return 4*(inside/N)

R = [1,10,100,1000]
N = [10,100,1000,10000,100000,1000000]problem_number
for n in N:
	for r in R:
		seed(randint(1,7))
		print("R:{}\t{} Samples:\t{:.3f}".format(r,n,estimatePi(r,n)))