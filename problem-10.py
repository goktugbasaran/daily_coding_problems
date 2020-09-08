"""
This problem was asked by Apple.

Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.


The problem seems simple at first, but the actual objective is not to be able to run a single function with sleep
but it is to have a queue of functions that come in different millisecond offsets.
I implemented 2 classes to represent a Job(function), which has a delay and the function to be executed as a data member.
a JobList, to keep the jobs in a ascended queue. When a new job arrives, it is "inserted" to its correct place. O(n)
And a thread module that checks the last element of the queue, which is the most urgent function. 
"""

from __future__ import division
import time
import threading
from random import randint
import heapq

def current_milli_time(): return int(round(time.time() * 1000))

class Job:
    def __init__(self, fun, args, delay):
        self.fun = fun
        self.args = args
        self.delay = delay
        self.start = delay + current_milli_time()

    # For heap push operation, it was necessary to override < operator for comparisons.
    def __lt__(self, other):
        return self.start < other.start


class JobList:
    def __init__(self):
        self.jobs = []

    # O(N) since it is a sorted list. Worst case is the added element having the minimum delay.
    def add(self, job):
        for i in range(0, len(self.jobs)):
            if(job.start > jobs[i].start):
                self.jobs.insert(i, job)
                return
        self.jobs.append(job)

    def pop(self):
        return self.jobs.pop()

    def __len__(self):
        return len(self.jobs)

    def __getitem__(self, index):
        return self.jobs[index]


def updateListVer(name):
    while(True):
        global jobs
        if(len(jobs) != 0):
            if(jobs[-1].start <= current_milli_time()):
                job = jobs.pop() # O(1) since it is the last element of the list.
                job.fun(job.args)


def updateHeapVer(name):
    while(True):
        global jobs
        if(len(jobs) != 0):
            if(jobs[0].start <= current_milli_time()):
                job = heapq.heappop(jobs)  # Heappop O(log(N))
                job.fun(job.args)


def listVersion():
    global jobs
    jobs = JobList()
    x = threading.Thread(target=updateListVer, args=(1,))
    x.start()

    # generate 1000 functions with 1 to 15 seconds delay.
    for i in range(0, 1000):
        delay = randint(1000, 15000)
        # List insert : O(N)
        jobs.add(Job(print, "Job {}\t{}".format(i, delay), delay))


def heapVersion():
    global jobs
    jobs = []
    heapq.heapify(jobs)
    x = threading.Thread(target=updateHeapVer, args=(1,))
    x.start()

    for i in range(0, 1000):
        delay = randint(1000, 15000)
        heapq.heappush(
            jobs, Job(print, "Job ID:{}\tDelay:{}".format(i, delay), delay))  # Heap push : O(log(N))


if __name__ == "__main__":
    heapVersion()
