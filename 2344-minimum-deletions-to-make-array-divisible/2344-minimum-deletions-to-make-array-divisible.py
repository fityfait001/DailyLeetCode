class Solution:
    def minOperations(self, nums: List[int], numsDivide: List[int]) -> int:
        res=reduce(math.gcd,numsDivide)
        nums.sort()
        dele=0
        for i in nums:
            if(res%i==0):
                return dele
            else:
                dele+=1
        if(dele==len(nums)):
            return -1 

        