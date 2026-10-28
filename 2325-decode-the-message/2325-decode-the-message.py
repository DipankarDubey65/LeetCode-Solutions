class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        mp = {}
        ch = 'a'

        for i in range(len(key)):
            if key[i] != ' ' and key[i] not in mp:
                mp[key[i]] = ch
                ch = chr(ord(ch) + 1)

        ans = ""

        for i in range(len(message)):
            if message[i] != ' ':
                ans += mp[message[i]]
            else:
                ans += ' '

        return ans