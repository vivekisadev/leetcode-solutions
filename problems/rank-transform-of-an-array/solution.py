class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        rank = {v: i + 1 for i, v in enumerate(sorted(set(arr)))}
        return [rank[v] for v in arr]