class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        fileMap = {}

        for pathInfo in paths:
            path, *files = pathInfo.split()

            for file in files:
                i = file.index('(')
                name, content = file[:i], file[i + 1:-1]
                fileMap[content] = fileMap.get(content, []) + [path + '/' + name]
        
        return [files for files in fileMap.values() if len(files) > 1]