import sys


def main(inp, out):
    n = int(inp.readline())
    a = list(map(int, inp.readline().split()))
    b = list(map(int, inp.readline().split()))
    was = set()
    index = 0
    for number in b:
        result = 0
        if number not in was:
            while a[index] != number:
                result += 1
                was.add(a[index])
                index += 1
            result += 1
            was.add(a[index])
            index += 1
        print(result, end=' ', file=out)


if __name__ == '__main__':
    if sys.platform == 'win32':
        main(sys.stdin, sys.stdout)
    else:
        with open("input.txt", 'r') as inp, open("output.txt", 'w') as out:
            main(inp, out)
