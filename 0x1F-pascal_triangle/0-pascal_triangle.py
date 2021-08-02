#!/usr/bin/env python3
"""Pascal's Triangle"""

def pascal_triangle(n):
    """
    -----------------------
    METHOD: PASCAL TRIANGLE
    -----------------------
    Description:
        Returns a pascal representation
        a triangle with n rows.
    """
    pascal = []
    if n <= 0:
        return pascal

    if not len(pascal):
        pascal += [[1]]

    while n > 1:
        curr_row = [1]                        # List that holds the current generated row
        prev_row = pascal[-1]
        for j in range(len(prev_row) - 1):    # Loop through the prev list (-1 to avoid index error)
            curr_row += [
                prev_row[j] + prev_row[j + 1]
            ]
        curr_row += [1]
        pascal += [curr_row]
        n -= 1

    return pascal
