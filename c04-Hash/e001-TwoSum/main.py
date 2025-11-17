from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash = dict()
        for i, num in enumerate(nums):
            if hash.get(target - num) is not None and hash[target - num] != i:
                return [hash[target - num], i] 
            hash[num] = i
        return None