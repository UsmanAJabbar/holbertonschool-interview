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
    coins.sort(reverse=True)

    total_from_coins = 0
    number_of_coins = 0

    for coin in coins:
        while total_from_coins + coin <= total:
            total_from_coins += coin
            number_of_coins += 1
            print(total_from_coins)

    return -1 if total_from_coins != total else number_of_coins
