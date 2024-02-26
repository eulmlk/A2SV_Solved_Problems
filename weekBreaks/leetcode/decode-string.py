class Solution:
    def decodeString(self, s: str) -> str:
        def decode(s):
            print(''.join(s))
            n = len(s)
            result = []

            i = 0
            while i < n:
                if s[i] in "0123456789":
                    count = 0

                    while i < n and s[i] in "0123456789":
                        count *= 10
                        count += int(s[i])
                        i += 1
                    
                    i += 1

                    sub = []
                    lefts = 1
                    while i < n and lefts > 0:
                        if s[i] == '[':
                            lefts += 1
                        elif s[i] == ']':
                            lefts -= 1
                        
                        if lefts > 0:
                            sub.append(s[i])
                        
                        i += 1
                    
                    result.extend(decode(sub) * count)
                else:
                    result.append(s[i])
                    i += 1

            return result
        
        return ''.join(decode(list(s)))