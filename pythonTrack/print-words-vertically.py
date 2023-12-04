class Solution:
    def printVertically(self, s: str) -> List[str]:
        i = 0
        added = True
        vert = []
        words = s.split()

        while added:
            added = False
            cur = ""

            for word in words:
                if i < len(word):
                    cur += word[i]
                    added = True
                else:
                    cur += " "
                print(word, len(word), cur)
            
            i += 1
            if added:
                vert.append(cur.rstrip())

        return vert
        