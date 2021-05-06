#!/usr/bin/python3
"""Count it module"""
import requests


def count_words(subreddit, word_list, after='', counter=None):
    """Count word appearance in subreddit

    Arguments:
        subreddit {string} -- Is the subreddit name
        word_list {list} -- Is the list of word to search for

    Keyword Arguments:
        after {str} -- Next page ID (default: {''})
        counter {dict} -- The counter dictionary (default: {None})

    Returns:
        None -- If nothing goes well
    """
    if counter is None:
        counter = {item: 0 for item in word_list}

    if after is None:
        items = counter.items()
        sorted_items = sorted(items, key=lambda x: x[1])
        for (key, value) in sorted_items:
            if value != 0:
                print(key, ": ", value)
        return None

    params = {'after': after, 'limit': 100}
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    res = requests.get(url, params=params)

    if res.status_code == 200:
        res = res.json()
        after = res["data"]["after"]
        children = [child for child in res["data"]["children"]]
        for child in children:
            title = child["data"]["title"]
            tokens = [token.lower() for token in title.split()]
            for word in word_list:
                counter[word] += tokens.count(word)

        count_words(subreddit, word_list, after, counter)
    else:
        return None
