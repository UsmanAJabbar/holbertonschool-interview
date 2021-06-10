#!/usr/bin/python3
""" 2D Matrix Rotate """


def rotate_2d_matrix(matrix):
    """Rotate 2D Matrix"""
    size = len(matrix)

    new_arr = []
    for column in range(size):
        new_arr += [[matrix[row][column]
                     for row in range(size - 1, -1, -1)]]

    for row in range(size):
        matrix[row] = new_arr[row]
