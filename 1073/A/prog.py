import sys


def main(inp, out):
    n = int(inp.readline())
    string = inp.readline()[:-1]
    for i in range(n - 1):
        if string[i] != string[i + 1]:
            print("YES", file=out)
            print(string[i: i + 2], file=out)
            sys.exit()
    print("NO", file=out)


if __name__ == '__main__':
    if sys.platform == 'win32':
        main(sys.stdin, sys.stdout)
    else:
        with open("input.txt", 'r') as inp, open("output.txt", 'w') as out:
            main(inp, out)
