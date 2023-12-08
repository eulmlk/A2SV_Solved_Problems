class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        code = []

        NORMAL_STATE = 0
        INSIDE_BLOCK_COMMENT = 1
        INSIDE_LINE_COMMENT = 2

        state = NORMAL_STATE
        updatedLine = ''

        for line in source:
            n = len(line)
            i = 0

            while i < n:
                ch = line[i:i+2]

                if state == NORMAL_STATE:
                    if ch == '/*':
                        state = INSIDE_BLOCK_COMMENT
                        i += 2
                        continue
                    elif ch == '//':
                        state = INSIDE_LINE_COMMENT
                        i += 2
                        continue

                elif state == INSIDE_BLOCK_COMMENT:
                    if ch == '*/':
                        state = NORMAL_STATE
                        i += 2
                        continue
                
                if i < n and state == NORMAL_STATE:
                    updatedLine += line[i]
                
                i += 1
            
            if state == INSIDE_LINE_COMMENT:
                state = NORMAL_STATE
            
            # print(updatedLine)

            if len(updatedLine) != 0 and state != INSIDE_BLOCK_COMMENT:
                code.append(updatedLine)
                updatedLine = ''
            
        if len(updatedLine) != 0:
            code.append(updatedLine)
        
        return code

        """
        struct Node{
            int size;
            int val;
        };
        """