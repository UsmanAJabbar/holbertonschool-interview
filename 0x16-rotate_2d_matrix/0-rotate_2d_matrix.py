#!/usr/bin/python3
""" 2D Matrix Rotate """


def rotate_2d_matrix(matrix):
    """Rotate 2D Matrix"""
    size = len(matrix)

    for column in range(size):
        matrix[column] = [ matrix[row][column]
                           for row in range(size - 1, -1, -1) ]
