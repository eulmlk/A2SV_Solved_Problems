class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        possible = []
        row1 = ['q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p']
        row2 = ['a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l']
        row3 = ['z', 'x', 'c', 'v', 'b', 'n', 'm']

        def isSingleRow(word):
            if word[0] in row1:
                chosenRow = row1
            elif word[0] in row2:
                chosenRow = row2
            elif word[0] in row3:
                chosenRow = row3

            for ch in word:
                if ch not in chosenRow:
                    return False
                
            return True

        for word in words:
            wordList = list(set([ch.lower() for ch in word]))
            
            if isSingleRow(wordList):
                possible.append(word)
        
        return possible