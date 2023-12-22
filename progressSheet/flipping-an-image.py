class Solution:
    def flipAndInvertImage(self, image: List[List[int]]) -> List[List[int]]:
        for row in image:
            row.reverse()

            for index in range(len(row)):
                row[index] = 0 if row[index] == 1 else 1
        
        return image
        