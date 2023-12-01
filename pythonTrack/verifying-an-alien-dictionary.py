class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        ords = {}
        i = 0
        for ch in order:
            ords[ch] = i
            i += 1

        def compare(word1: str, word2: str) -> bool:
            n = len(word1)
            m = len(word2)
            i = 0

            while i < min(n, m):
                if ords[word1[i]] < ords[word2[i]]:
                    return True
                elif ords[word1[i]] > ords[word2[i]]:
                    return False
                i += 1

            return n <= m

        for i in range(len(words) - 1):
            if not compare(words[i], words[i + 1]):
                return False

        return True
