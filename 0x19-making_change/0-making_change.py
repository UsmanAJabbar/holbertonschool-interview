#!/usr/bin/python3
"""Some doc"""


def makeChange(coins: list, total: int) -> int:
    """
    ------------------
    METHOD: makeChange
    ------------------
    Given a pile of coins of different values,
    determine the fewest number of coins needed
    to meet a given total total.
    Args:
        @coins: list of coin options
        @total: total to generate
    """
    if total == 0:
        return 0
    
# There is no way  the result ,i.e. the no. of coins to form the total, can be greater than the actual given total so we initiate our dp table with 'total+1' to compare minimums

    dp = [total+1] * (total+1) 
    dp[0] = 0
    
# we are not interseted in the 'total' less than current coin's value as there is no possible way to include this coin and produce an total less than it.

    for i in range(len(coins)):
        for j in range(coins[i], total + 1):  
            dp[j] = min(dp[j], dp[j - coins[i]] + 1)

    return -1 if dp[-1] > total else dp[-1]