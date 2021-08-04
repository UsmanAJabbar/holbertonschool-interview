#!/usr/bin/python3
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
    if n <= 0:
        return []

    pascal = [[1]]

    while n > 1:
        prev_row = pascal[-1]

        curr_row = [1] + [
            prev_row[j] + prev_row[j + 1]
            for j in range(len(prev_row) - 1)
        ] + [1]

        pascal += [curr_row]
        n -= 1

    return pascal
