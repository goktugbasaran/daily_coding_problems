"""
Implement an autocomplete system.
 That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string 'de' 
and the set of strings [dog, deer, deal], 
return [deer, deal].
"""

"""
I used trie data structure which is mostly used for reTRIEving, hence the name.
Using the hint, preprocessing the words I get from the internet should be O(W)
"""

import requests
import random
import re
# get 25k words
word_site = "http://svnweb.freebsd.org/csrg/share/dict/words?view=co&content-type=text/plain"
letters = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'] # Other letters may be added for language support

response = requests.get(word_site)
WORDS = response.content.splitlines()
words = sorted(WORDS)
# Preprocess words to contain only alphanumerical characters and lowercase characters
for i,word in enumerate(words):
	words[i] = str(word,"utf-8")
	words[i] = re.sub(r'[^a-zA-Z0-9]','', words[i])
	words[i] = words[i].lower()

class Node:
	def __init__(self):
		self.children = [None]*len(letters)
		self.endChar = False
		
class Trie:
	def __init__(self):
		self.root = self.getNode()

	def getNode(self): # Generate a new node
		return Node()

	def _getIndex(self,char):# Returns the index of the current letter
		return ord(char.lower()) - ord('a') 

	def _getLetter(self,index): # Returns the letter belonging to the index
		if(index<len(letters)):
			return letters[index]		

	def insert(self,key):
		traverse = self.root
		length = len(key)
		for i in range(0,length):
			index = self._getIndex(key[i]) # returns the index of the i'th letter of the key
			if (traverse.children[index] == None):
				traverse.children[index] = self.getNode()
			traverse = traverse.children[index]
		traverse.endChar = True

	def search(self,key):
		traverse = self.root
		length = len(key)
		for i in range(0,length):
			index = self._getIndex(key[i])
			if(traverse.children[index] == None):
				return False
			traverse = traverse.children[index]
		# found the prefix, now need to return all children
		words = self.getChildrenWords(traverse)
		for i in range(len(words)):
			words[i] = key + words[i]
		return words

	def getChildrenWords(self,node): # Recursively find children words
		words = []
		for index,child in enumerate(node.children):
			if(child == None):
				continue
			if(child.endChar == True): 
				words.append(self._getLetter(index))
			else:
				children_words = self.getChildrenWords(child)
				if(children_words != None):
					for children_word in children_words:
						words.append(self._getLetter(index) + children_word)
		return words

trie = Trie()
for word in words:
	trie.insert(word)
import time
pres = ["he","hel", "de","do","derp","te","tes"]
for pre in pres:
	print("For key:{}".format(pre))
	start = time.time()
	trie.search(pre.lower())
	print("It took {} seconds to search in the dictionary".format(time.time()-start))