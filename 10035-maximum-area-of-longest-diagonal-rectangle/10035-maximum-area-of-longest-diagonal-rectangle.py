class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        res = 0
        di = 0;
        for i in range(0,len(dimensions)):
            l = dimensions[i][0]
            w = dimensions[i][1]
            diag = math.sqrt((l * l) + (w * w))
            if(diag > di):
                res = l * w
                di = diag
            elif(diag == di):
                res = max(res, l * w)
                diag = di
        return res