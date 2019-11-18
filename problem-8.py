from random import randint
from time import time


"""
A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

Given the root to a binary tree, count the number of unival subtrees.

For example, the following tree has 5 unival subtrees:

   0
  / \
 1   0
	/ \
   1   0
  / \
 1   1



	0       == 1

	0
   / \
  0	  0     == 3

 	 1
	/ \
   1   1    == 2
  /
 1

 """


class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

    def printTree(self):
        if self.left:
            self.left.printTree()
        print(self.val)
        if self.right:
            self.right.printTree()

    def insert(self, val):
        if(self.val):
            if val < self.val:
                if self.left == None:
                    self.left = Node(val)
                else:
                    self.left.insert(val)
            elif(val > self.val):
                if(self.right == None):
                    self.right = Node(val)
                else:
                    self.right.insert(val)
        else:
            self.val = val


'''
O(n^2) solution
'''


def is_uni(root):
    return unival(root, root.val)


def unival(root, val) -> bool:
    if (root == None):
        return True
    if (root.val == val):
        return unival(root.left, val) and unival(root.right, val)
    return False


def count(root):
    if root == None:
        return 0
    leftSubtree = count(root.left)
    rightSubtree = count(root.right)
    if(is_uni(root)):
        return leftSubtree + rightSubtree
    else:
        return 1+leftSubtree+rightSubtree


'''
'''


''' O(n) '''


def traverse(root):
    if(root == None):
        return 0, True
    left, isLeft = traverse(root.left)
    right, isRight = traverse(root.right)
    total = left+right
    if(isLeft and isRight):
        if(root.left != None and root.val != root.left.val):
            return total, False
        if(root.right != None and root.val != root.right.val):
            return total, False
        return total+1, True
    return total, False


if __name__ == "__main__":

    sizes = [1000, 10000, 100000]
    for size in sizes:
        root = Node(randint(0, 10000))
        for i in range(0, size):
            root.insert(randint(0, 10000))
        start = time()
        traverse(root)
        print("O(n)", time()-start)

    for size in sizes:
        root = Node(randint(0, 10000))
        for i in range(0, size):
            root.insert(randint(0, 10000))
        start = time()
        count(root)
        print("O(n^2)", time()-start)
