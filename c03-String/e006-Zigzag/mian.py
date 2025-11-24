class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if(numRows == 1):
            return s
        rows = [''] * numRows
        currow = 0;
        down = False

        for c in s:
            rows[currow] += c;
            if(currow == 0 or currow == numRows - 1):
                down = not down
            currow += 1 if down else -1
        
        return ''.join(rows)