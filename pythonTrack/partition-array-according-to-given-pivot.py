class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        smaller = []
        larger = []
        equal = []

        for num in nums:
            if num > pivot:
                larger.append(num)
            elif num < pivot:
                smaller.append(num)
            else:
                equal.append(num)
        
        return smaller + equal + larger