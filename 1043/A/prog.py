import sys


def main(inp, out):
    n = int(inp.readline())
    a = list(map(int, inp.readline().split()))
    s = sum(a)
    answer = max(2 * s // n + 1, max(a))
    print(answer, file=out)


if __name__ == '__main__':
    if sys.platform == 'win32':
        main(sys.stdin, sys.stdout)
    else:
        with open("input.txt", 'r') as inp, open("output.txt", 'w') as out:
            main(inp, out)
