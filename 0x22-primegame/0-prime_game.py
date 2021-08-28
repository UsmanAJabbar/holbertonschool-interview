#!/usr/bin/python3
"""Prime Numbers"""

cache = {}


def set_generator(number):
    """Generates a set from {1...num}"""
    return {
        num for num in range(1, number + 1)
    }


def play_game(playset):
    """Plays a game eliminating all of the prime numbers"""

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

    playcount = 0
    for num in playset:
        if num != 1 and is_prime(num):
            playcount += 1

    return playcount % 2 == 0


def isWinner(x, nums):
    """Some game"""

    win_count = {
        'True': 0,
        'False': 0
    }

    if not x or not len(nums):
        return None

    for num in nums:
        playset = set_generator(num)
        win_count[
            str(play_game(playset, num))
        ] += 1

    return (
        'Ben'
        if win_count['True'] > win_count['False']
        else
        'Maria'
    )
