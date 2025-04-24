def countUniqueXORTriplets(nums):
    seen = set()
    n = len(nums)
    for i in range(n):
        xor_sum = 0
        for j in range(i, n):
            xor_sum ^= nums[j]
            seen.add(xor_sum)
    return len(seen)
