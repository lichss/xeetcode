class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) <= 1:
            return len(s)

        left = 0
        righ = 1
        seen = {s[0]:1}
        maxl = 1
        while righ < len(s):
            if(seen.get(s[righ],0) == 0):
                seen[s[righ]] = 1
                righ += 1
                maxl = max(righ - left,maxl)
            else:
                while(s[righ] != s[left]):
                    seen[s[left]] = 0
                    left+= 1
                seen[s[left]] = 0
                left += 1

        return maxl        
        