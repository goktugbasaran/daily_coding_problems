"""
This problem was asked by Amazon.

Given an integer k and a string s, 
find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, 
the longest substring with k distinct characters is "bcb".
"""

substrset = set()

def distincCheck(s):
	return len("".join(set(s)))


def longestSubstr(s,k):

	if(s in substrset):
		return s,0
	else:
		substrset.add(s)
	currentDistincCount = distincCheck(s)
	if(k > len(s) or k > currentDistincCount):
		return s,0
		
	if(k==currentDistincCount):
		return s,len(s)

	leftStr = s[1:]
	rightStr = s[:-1]
	if(leftStr != rightStr):
		left,leftc = longestSubstr(leftStr,k)
		right,rightc = longestSubstr(rightStr,k)
	if(leftc>rightc):
		return left,leftc
	else:
		return right,rightc

if __name__ == "__main__":
	s = "abcba"
	k = 2
	print(longestSubstr(s,k))
	