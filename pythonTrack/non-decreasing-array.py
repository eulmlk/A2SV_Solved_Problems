class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        n = len(nums)
        removed = False
        curMax = nums[0]

        for i in range(1, n):
            diff = nums[i] - curMax
            # print(curMax, nums[i])
            if diff < 0:
                # print(nums[i], i)
                if removed:
                    return False
                
                removed = True
                if i == 1:
                    curMax = min(nums[0], nums[1])
                elif i - 2 >= 0 and nums[i] >= nums[i - 2]:
                    curMax = nums[i]
                else:
                    curMax = nums[i - 1]
            
            curMax = max(curMax, nums[i])
        
        return True

                


                    


        # 1  2  7  4  5
        #  +1 +5 -3^
