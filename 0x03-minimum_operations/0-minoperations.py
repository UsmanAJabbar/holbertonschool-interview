#!/usr/bin/python3
"Min Operations"

def minOperations(n):
    """
    ---------------------
    METHOD: minOperations
    ---------------------
    Description:
        This method returns the min number
        of copy/paste operations required
        to make a certain number of
        characters.
    Args:
        n: number of characters to generate
    """
    if n <= 1:
        return 0

    for i in range(2, n):                         # n = 45   | n = 15
        if n % i == 0:                            # i = 3    | i = 3
            return minOperations(int(n / i)) + i  # (15) + 3 | (5) + 3

    return n  # Hits this return if prime
