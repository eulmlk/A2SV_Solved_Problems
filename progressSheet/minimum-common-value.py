class Solution:
    def getCommon(self, nums1: List[int], nums2: List[int]) -> int:
        first, second = 0, 0
        n, m = len(nums1), len(nums2)

        while first < n and second < m:
            if nums1[first] == nums2[second]:
                return nums1[first]
            elif nums1[first] < nums2[second]:
                first += 1
            else:
                second += 1
        
        return -1