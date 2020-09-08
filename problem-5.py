"""
This problem was asked by Jane Street.

cons(a, b) constructs a pair, and car(pair) and cdr(pair) 
returns the first and last element of that pair. 
For example, car(cons(3, 4)) returns 3, and 
cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
Implement car and cdr.
"""

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair

def car(f):
    def first(a, b):
        return a
    return f(first)

def cdr(f):
    def second(a, b):
        return b
    return f(second)

print("1st element of pair: {}\n2nd element of pair: {}".format(car(cons(1,5)),cdr(cons(1,5))))