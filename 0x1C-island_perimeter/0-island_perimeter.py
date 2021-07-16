#!/usr/bin/python3
"""Island Perimeter"""


def island_perimeter(grid):
    """Finds a land perimeter

    Arguments:
        grid {list[List]} -- The land

    Returns:
        int -- The perimeter of the land
    """
    perimeter = 0
    for row in grid + list(map(list, zip(*grid))):
        for i, j in zip([0] + row, row + [0]):
            perimeter += int(i != j)
    return perimeter
