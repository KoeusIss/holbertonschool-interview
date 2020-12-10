#!/usr/bin/python3
"""Lockbox module"""


def canUnlockAll(boxes):
    """Determines if all the boxes can be opened or not

    Args:
        boxes (list[list]): boxes is the list of box that contains keys

    Returns:
        (bool): True if we can open all the boxes, otherwise return False

    """
    if boxes[0] == [] or not isinstance(boxes, list):
        return False

    opens = [0]
    for idx, box in enumerate(boxes):
        for key in box:
            if key not in opens and key in range(0, len(boxes)) and key != idx:
                opens.append(key)
    return len(opens) == len(boxes)
