from matrix import mul

if __name__ == '__main__':
    x = [[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12]]
    y = [[9, 6], [11, 2], [8, 10]]

    print(mul(x, y))
    # [[55, 40], [139, 94], [223, 148], [307, 202]]