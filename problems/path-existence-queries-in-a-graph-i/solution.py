class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        # group[i] = component id of node i
        group = [0] * n
        for i in range(1, n):
            group[i] = group[i - 1] + (1 if nums[i] - nums[i - 1] > maxDiff else 0)
        
        return [group[u] == group[v] for u, v in queries]