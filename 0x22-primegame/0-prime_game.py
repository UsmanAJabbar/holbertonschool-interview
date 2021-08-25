#!/usr/bin/python3
"""Prime Numbers"""

cache = {}


def set_generator(number):
    """Generates a set from {1...num}"""
    return {
        num for num in range(1, number + 1)
    }


def play_game(playset, playset_max_num):
    """Plays a game eliminating all of the prime numbers"""
    # Find the smallest prime number and assumes the initial user chooses the prime number
    playcount = 0
    for num in playset:
        if num != 1 and is_prime(num):
            playcount += 1

    return (playcount % 2 == 0)


def is_prime(number):
    """Returns whether a given number is a prime"""
    if number in cache:
        return cache[number]

    for num in range(2, number):
        if number % num == 0:
            cache[number] = False
            return cache[number]

    cache[number] = True
    return cache[number]


def remove_multiples(prime_number, number_set, number_set_max_num):
    """Removes all of the multiples of num from number_set"""
    i = 1
    while prime_number * i <= number_set_max_num:
        number_set.remove(prime_number * i)
        i += 1


def isWinner(x, nums):
    """Some game"""

    win_count = {
        'True': 0,
        'False': 0
    }

    if (x <= 0 or len(nums) <= 0):
        return None

    for num in nums:
        playset = set_generator(num)
        win = play_game(playset, num)
        win_count[str(win)] += 1

    # print(win_count)

    return (
        'Ben'
        if win_count['True'] > win_count['False']
        else
        'Maria'
    )
