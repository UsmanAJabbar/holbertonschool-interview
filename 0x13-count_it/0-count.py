#!/usr/bin/python3
"""Counts the occurrence of keywords in a reddit API query"""
from requests import get as r_get
from collections import Counter


def count_words(sub, word_list=[], next='', word_sum={}) -> None:
    """Counts the number of words"""
    print(word_sum)

    # Converts it to a set on the very first run
    if not word_sum:   word_list = set([word.lower() for word in word_list])

    # This executes when there are no more pages
    if next == 'None': return print(word_sum)

    api = r_get(f'https://api.reddit.com/r/{sub}/hot?after={next}',
                headers={'User-Agent': 'Chrome'},
                allow_redirects=False).json()
    posts = api.get('data', {}).get('children')

    if not posts: return print(word_sum)

    for post in posts:
        if not post['data']['stickied']:
            title = post['data']['title'].lower().split()
            w_count = Counter(title)

            for keyword in word_list:
                if keyword in word_sum:
                    word_sum[keyword] += w_count.get(keyword, 0)
                else:
                    word_sum[keyword]  = w_count.get(keyword, 0)

    next = api.get('data', {}).get('after', 'None')
    count_words(sub, word_list, next, word_sum)

# def print_helper(word_count: dict) -> None:
#     """Results should be printed in descending order, by the count"""
#     print(word_count)