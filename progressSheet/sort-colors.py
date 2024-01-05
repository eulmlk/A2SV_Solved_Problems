class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        # --- counting sort ---
        counts = [0] * 3

        for i in nums:
            counts[i] += 1

        ind = 0
        for i in range(3):
            while counts[i]:
                nums[ind] = i
                ind += 1
                counts[i] -= 1
        """

        """ 
        # --- insertion sort --- "
        for i in range(1, len(nums)):
            temp = nums[i]
            j = i - 1
            while j >= 0 and nums[j] > temp:
                nums[j + 1] = nums[j]
                j -= 1
            nums[j + 1] = temp
        """

        """ 
        # --- bubble sort ---
        for i in range(len(nums) - 1, 0, -1):
            for j in range(i):
                if nums[j] > nums[j + 1]:
                    nums[j], nums[j + 1] = nums[j + 1], nums[j]
        """
        
        """ 
        # selection sort
        for i in range(len(nums)):
            minIndex = i
            j = i + 1

            while j < len(nums):
                if nums[j] < nums[minIndex]:
                    minIndex = j
                j += 1
            
            if i != minIndex:
                nums[minIndex], nums[i] = nums[i], nums[minIndex]
        """

        red, white, blue = 0, 0, len(nums) - 1

        while white <= blue:
            if nums[white] == 0:
                nums[red], nums[white] = nums[white], nums[red]
                red += 1
                white += 1
            elif nums[white] == 1:
                white += 1
            else:
                nums[white], nums[blue] = nums[blue], nums[white]
                blue -= 1