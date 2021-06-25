#!/usr/bin/python3
"""Some doc"""


def makeChange(coins: list, total: int) -> int:
    """
    ------------------
    METHOD: makeChange
    ------------------
    Given a pile of coins of different values,
    determine the fewest number of coins needed
    to meet a given amount total.
    Args:
        @coins: list of coin options
        @total: total to generate
    """
    if amount == 0:
        return 0

    dp = [amount+1] * (amount+1) 
    dp[0] = 0

    for i in range(len(coins)):
        for j in range(coins[i], amount + 1):  
            dp[j] = min(dp[j], dp[j - coins[i]] + 1)

    return -1 if dp[-1] > amount else dp[-1]