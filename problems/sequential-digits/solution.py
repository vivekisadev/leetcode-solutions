class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        s = "123456789"
        res = []
        for length in range(1, 10):
            for start in range(0, 10 - length):
                num = int(s[start:start+length])
                if low <= num <= high:
                    res.append(num)
        return sorted(res)