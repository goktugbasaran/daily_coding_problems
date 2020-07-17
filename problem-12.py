"""
This problem was asked by Amazon.

There exists a staircase with N steps,
and you can climb up either 1 or 2 steps at a time. 
Given N, write a function that returns the number 
of unique ways you can climb the staircase. The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2

What if, instead of being able to climb 1 or 2 steps
at a time, you could climb any number from a set of positive 
integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
"""

def static_vars(**kwargs):
    def decorate(func):
        for k in kwargs:
            setattr(func, k, kwargs[k])
        return func
    return decorate

@static_vars(count=0)
def calculate(steps,patterns,level=0,reset=0,verbose=False):
	if(reset == 1):
		calculate.count = 0
	for pattern in patterns:
		new_step = steps-pattern
		if(new_step < 0):
			break
		if(new_step == 0):
			calculate.count += 1
		if(verbose):
			print("{}At step {}, took {} steps, new step = {}".format("\t"*level,steps, pattern,new_step))	
		calculate(new_step,patterns,level+1)
	return ("{} ways to climb {} steps with {} step-lengths.\n".format(calculate.count,steps,patterns))

steps = [4,5]
patterns = [[1],[1,2],[1,3,5]]
for step in steps:
	for pattern in patterns:
		print(calculate(step,pattern,reset=1,verbose=False)) # Verbose false will print the search in a tree-like manner