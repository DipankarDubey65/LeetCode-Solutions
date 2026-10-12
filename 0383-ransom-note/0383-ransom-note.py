class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        n = len(ransomNote)
        m = len(magazine)

        need = {}
        have = {}

        for i in range(n):
            need[ransomNote[i]] = need.get(ransomNote[i], 0) + 1

        for i in range(m):
            have[magazine[i]] = have.get(magazine[i], 0) + 1

        for i in need:
            if need[i] > have.get(i, 0):
                return False

        return True