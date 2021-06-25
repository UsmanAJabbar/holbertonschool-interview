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
    inf = float('inf')

    # Create a table the size of `amount`
    cache = [inf] * (amount + 1)
    cache[0] = 0

    # Plan, check out how many coins it takes to make the current coin
    # So we're going to loop from 0 to the amount and record how many coins
    # it takes to get to that amount

    # How many coins does it take to make 0? 1
    # How many coins does it take to make 1? 1  # Given that we have the coin
    # and so on and so forth, this is a linear approach so the cache list doesn't recreate itself

    # By the end of it, since we recorded how many coins it took at each index
    # we could simply return how many coins it took to make `amount`

    # cache[index] => where cache is the table and [index] represents
                                                    # the index
                                                    # and the amount

    for current_amount in range(amount + 1): # Loop from 0 to amount
        for coin in coins:                   # Find coins that could feasibly be generate the current_amount
            if coin <= current_amount:       # We can only generate an amount if the coin is smaller than the amount
                cache[current_amount] = min(cache[current_amount], cache[current_amount - coin])
                                             # Compare the current_amount with the amount if we have previously seen it
                                             # eg, current_amount = 25, coin = 5
                                             # check if the cache[25] smaller number of coins or cache[20]
    
    return cache[amount] if cache[amount] != inf else -1