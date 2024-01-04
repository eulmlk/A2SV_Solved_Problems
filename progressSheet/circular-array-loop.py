class Solution:
    def circularArrayLoop(self, nums: List[int]) -> bool:
        n = len(nums)

        for i in range(n):
            fast, slow = i, i
            count = n

            while count:
                fast = (fast + nums[fast]) % n
                if nums[fast] * nums[i] < 0:
                    break

                fast = (fast + nums[fast]) % n
                if nums[fast] * nums[i] < 0:
                    break

                slow = (slow + nums[slow]) % n

                next_ = (slow + nums[slow]) % n
                if fast == slow and slow != next_:
                    return True
                count -= 1
        
        return False