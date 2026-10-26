class Solution:
    def solve(self, output, mapping, ans, digits, i):
        # Base case
        if i >= len(digits):
            if len(output) > 0:
                ans.append(output)
            return

        # Current digit
        digi = digits[i]
        mappedString = mapping[digi]

        # Har character ke liye recursive call
        for ch in mappedString:
            # Include character in output
            output += ch

            # Recursive call
            self.solve(output, mapping, ans, digits, i + 1)

            # Backtracking
            output = output[:-1]

    def letterCombinations(self, digits: str) -> list[str]:
        ans = []

        mapping = {
            '2': "abc",
            '3': "def",
            '4': "ghi",
            '5': "jkl",
            '6': "mno",
            '7': "pqrs",
            '8': "tuv",
            '9': "wxyz"
        }

        output = ""
        i = 0

        self.solve(output, mapping, ans, digits, i)

        return ans