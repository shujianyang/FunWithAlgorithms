import copy

class Solution:
	def subsets(self, nums):
		i = 0
		while i < len(nums): #This removes duplicate elements in the list
			j = i + 1
			while j < len(nums):
				if nums[j] == nums[i]:
					del nums[j]
				else:
					j += 1
			i += 1

		nums.sort(reverse=True) #Sort the list from large to small
		return self.getsub(nums)

	#Get subset recursively
	def getsub(self, nums):
		if len(nums) < 1:
			return [[]] #If the list is empty, return empty subset
		else:
			#Split the set into two parts:
			#The first element and the rest part
			first = nums[0]
			rest = nums[1:] #If size of rest part is 0, creates an empty list.

			#Recursive call
			#Note the return value of rest list is not a list but a list of lists
			resub = self.getsub(rest)

			newset = copy.deepcopy(resub) #Create a deep copy

			#Create the union of first element and rest part subset
			for s in newset:
				s.append(first)
			return(resub + newset)


s = Solution()
ans = s.subsets([6,1,5,2,4,3])
print(ans)
