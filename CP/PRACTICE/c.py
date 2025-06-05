def max_coins(N, A, B, C, D):
    max_value = 0
    for num_0 in range(N + 1):
        num_1 = N - num_0
        
        # Case 1: 0s followed by 1s → maximize '01'
        coins1 = (num_0 * (num_0 + 1) // 2) * A + \
                 (num_1 * (num_1 + 1) // 2) * B + \
                 (num_0 * num_1) * C

        # Case 2: 1s followed by 0s → maximize '10'
        coins2 = (num_0 * (num_0 + 1) // 2) * A + \
                 (num_1 * (num_1 + 1) // 2) * B + \
                 (num_0 * num_1) * D

        max_value = max(max_value, coins1, coins2)
    
    return max_value

T = int(input())
for _ in range(T):
    N, A, B, C, D = map(int, input().split())
    print(max_coins(N, A, B, C, D))
