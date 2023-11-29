class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if "" in strs:
            return ""
    
        i = -1
        common = True
        while common:
            i += 1
            for s in strs:
                if i >= len(s) or s[i] != strs[0][i]:
                    common = False
                    break
        
        return strs[0][0:i]
