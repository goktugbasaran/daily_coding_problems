from __future__ import division
import time
import threading
from random import randint


def current_milli_time(): return int(round(time.time() * 1000))

"""
This problem was asked by Apple.

Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.


The problem seems simple at first, but the actual objective is not to be able to run a single function with sleep
but it is to have a queue of functions that come in different millisecond offsets.
I implemented 2 classes to represent a Job(function), which has a delay and the function to be executed as a data member.
a JobList, to keep the jobs in a ascended queue. When a new job arrives, it is "inserted" to its correct place. O(n)
And a thread module that checks the last element of the queue, which is the most urgent function. 
Python 3
"""


class Job:
    def __init__(self, fun, args, delay):
        self.fun = fun
        self.args = args
        self.delay = delay
        self.start = delay + current_milli_time()


class JobList:
    def __init__(self):
        self.jobs = []

    def add(self, job):
        for i in range(0, len(self.jobs)):
            if(job.start > jobs[i].start):
                self.jobs.insert(i, job)
                return
        self.jobs.append(job)

    def pop(self):
        return self.jobs.pop(len(self.jobs)-1)

    def __len__(self):
        return len(self.jobs)

    def __getitem__(self, index):
        return self.jobs[index]


def update(name):
    while(True):
        global jobs
        if(len(jobs) != 0):
            if(jobs[len(jobs) - 1].start <= current_milli_time()):
                job = jobs.pop()
                job.fun(job.args)


if __name__ == "__main__":
    global jobs
    jobs = JobList()
    x = threading.Thread(target=update, args=(1,))
    x.start()

    # generate 1000 functions with 1 to 15 seconds delay.
    for i in range(0, 1000):
        delay = randint(1000, 15000)
        jobs.add(Job(print, "Job {}\t{}".format(i, delay), delay))
