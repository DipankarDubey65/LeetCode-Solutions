class Solution:
    def removeDuplicates(self, s: str, k: int) -> str:
        n = len(s)
        st = []

        for i in range(n):
            c = s[i]

            if not st:
                st.append([c, 1])
            else:
                if st[-1][0] != c:
                    st.append([c, 1])
                else:
                    st[-1][1] += 1

                    if st[-1][1] == k:
                        st.pop()

        res = ""

        while st:
            p = st.pop()
            while p[1] > 0:
                res += p[0]
                p[1] -= 1

        res = res[::-1]
        return res