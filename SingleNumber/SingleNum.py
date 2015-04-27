def singleNumber(nums):
	x=0
	for n in nums:
		x ^= n
	return x

print(singleNumber([46,61,23,8,23,3,15,61,15,8,46]))
