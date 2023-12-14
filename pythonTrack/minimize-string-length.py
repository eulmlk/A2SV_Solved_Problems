class Solution:
    def minimizedStringLength(self, s: str) -> int:
        return len({ch for ch in s})