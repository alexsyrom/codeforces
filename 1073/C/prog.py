import sys


def check(n, x, y):
    if abs(x) + abs(y) > n:
        return False
    if (abs(x) + abs(y)) % 2 != n % 2:
        return False
    return True


def main(inp, out):
    n = int(inp.readline())
    ops = inp.readline()[:-1]
    x, y = list(map(int, inp.readline().split()))
    if not check(n, x, y):
        print(-1, file=out)
        return
    X = [0 for i in range(n + 1)]
    Y = [0 for i in range(n + 1)]
    for index, op in enumerate(ops):
        X[index + 1] = X[index]
        Y[index + 1] = Y[index]
        if op == 'L':
            X[index + 1] -= 1
        elif op == 'R':
            X[index + 1] += 1
        elif op == 'U':
            Y[index + 1] += 1
        elif op == 'D':
            Y[index + 1] -= 1
    if X[-1] == x and Y[-1] == y:
        print(0, file=out)
        return
    left = 0
    right = n
    while left + 1 < right:
        segment_len = (left + right) / 2
        possible = False
        for begin in range(n - segment_len + 1):
            new_x = 0
            new_y = 0
            if check(segment_len, new_x, new_y):
                possible = True
                break
        if possible:
            right = segment_len
        else:
            left = segment_len
    print(right, file=out)


if __name__ == '__main__':
    if sys.platform == 'win32':
        main(sys.stdin, sys.stdout)
    else:
        with open("input.txt", 'r') as inp, open("output.txt", 'w') as out:
            main(inp, out)
