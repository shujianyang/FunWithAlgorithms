class Solution:
	def wordPattern(self, pattern, str):
		"""
		:type patter: str
		:type str: str
		:rtype: bool
		"""
		words = str.split(' ')
		if len(pattern) != len(words) :
			return False
		match = {}
		i = 0
		while i < len(pattern):
			key = pattern[i]
			if not key in match:
				match[key] = words[i]
			elif match[key] != words[i]:
				return False
			i += 1
		if len(match) != len(set(match.values())):
			return False
		return True

slt = Solution()
print(slt.wordPattern('abab', 'dog dog dog dog'))
