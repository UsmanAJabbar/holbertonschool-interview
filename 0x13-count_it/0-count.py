#!/usr/bin/python3
"""Counts the occurrence of keywords in a reddit API query"""
from collections import Counter
from requests import get


def count_words(sub, word_list=[], next='', word_sum={}):
    """Counts the number of words"""
    # Converts it to a set on the very first run
    if not word_sum:
        word_list = set([word.lower() for word in word_list])

    api = get(f'https://api.reddit.com/r/{sub}/hot?after={next}',
              headers={'User-Agent': 'Chrome'},
              allow_redirects=False).json()
    posts = api.get('data', {}).get('children')

    if not posts:
        return print_helper(word_sum)

    for post in posts:
        if not post['data']['stickied']:
            title = post['data']['title'].lower().split()
            w_count = Counter(title)

            for keyword in word_list:
                if keyword in word_sum:
                    word_sum[keyword] += w_count.get(keyword, 0)
                else:
                    word_sum[keyword] = w_count.get(keyword, 0)

    next = api.get('data', {}).get('after', 'exit')
    # This executes when there are no more pages or if data doesn't exist
    if next in ['exit', None]:
        return print_helper(word_sum)

    return count_words(sub, word_list, next, word_sum)


def print_helper(word_count):
    """Results should be printed in descending order, by the count"""
    for elements in sorted(word_count.items(),
                           key=lambda x: x[1], reverse=True):
        print(f'{elements[0]}: {elements[1]}')
