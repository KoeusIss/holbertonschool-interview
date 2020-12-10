#!/usr/bin/python3
"""Lockbox module"""


def canUnlockAll(boxes):
    """Determines if all the boxes can be opened or not

    Args:
        boxes (list[list]): boxes is the list of box that contains keys

    Returns:
        (bool): True if we can open all the boxes, otherwise return False

    """
    opens = [True] + [False] * (len(boxes) - 1)

    def open_box(box):
        """Open all the associate box"""

        if len(box) == 0 or all(
                [opens[k] for k in box] if k in range(0, len(boxes))
        ):
            return
        else:
            for key in box:
                opens[key] = True
                open_box(boxes[key])
    open_box(boxes[0])
    return all(opens)
