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
    if n == 1:
        return n

    for i in range(2, n):           # n = 45
        if n % i == 0:                  # i = 3
            return minOperations(int(n / i)) + i
    return n
