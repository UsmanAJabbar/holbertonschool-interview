#!/usr/bin/python3
"""Some doc"""


def makeChange(coins: list, amount: int) -> int:
    """
    ------------------
    METHOD: makeChange
    ------------------
    Given a pile of coins of different values,
    determine the fewest number of coins needed
    to meet a given amount.
    Args:
        @coins: list of coin options
        @amount: amount to generate
    """
    if amount <= 0:
        return 0

    inf = float('inf')

    # Create a table the size of `amount`
    cache = [inf] * (amount + 1)
    cache[0] = 0

    # Plan, check out how many coins it takes to make the current coin
    # So we're going to loop from 0 to the amount and record how many coins
    # it takes to get to that amount

    # How many coins does it take to make 0? 1
    # How many coins does it take to make 1? 1  # Given that we have the coin
    # and so on and so forth

    # By the end of it, since we recorded how many coins it took at each index
    # we could simply return how many coins it took to make `amount`

    # cache[index] => where cache is the table and [index] represents
    #                                                           the index
    #                                                           and the amount

    for current_amount in range(amount + 1):  # Loop from 0 to amount
        for coin in coins:                    # coins that could gen the amt
            if coin <= current_amount:        # gen amt if coin is <= amount
                cache[current_amount] = min(
                    cache[current_amount], cache[current_amount - coin] + 1)
                # Compare cur_amt with the amount if we have previously seen it
                # eg, current_amount = 25, coin = 5
                # check if the cache[25] smaller number of coins or cache[20]

    return cache[amount] if cache[amount] != inf else -1
