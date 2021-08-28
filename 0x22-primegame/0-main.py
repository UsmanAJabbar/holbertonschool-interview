#!/usr/bin/python3
"""
Main file for testing
"""


isWinner = __import__('0-prime_game').isWinner

nums = [0] * 100
for i in range(100):
    nums[i] = i * i

print("Winner: {}".format(isWinner(100, nums)))


# ./a.out barfoothefoobarman foo bar wut
#                            wut foo bar

# Basically look for where foo is at and add that starting index where I found foo at in a list
# build the list with the subsequent words and their indexes

# sort the array [7, 10, 13]

# if the array == number of words we had to look for
#     and
# we have a consistent gap between all of the words
#         i.e foo started at index 7 and bar at 10 and wut and 13
#         we will look for 7 and then 10 and then 13 in the array
#         if we couldn't find the consistnt gap, err, we failed
