import sys


def main(inp, out):
    string = inp.readline().strip()
    a_first = True
    answer = []
    for char in reversed(string):
        if (char == 'a') == a_first:
            answer.append('1')
            a_first = not a_first
        else:
            answer.append('0')
    print(' '.join(reversed(answer)), file=out)


if __name__ == '__main__':
    if sys.platform == 'win32':
        main(sys.stdin, sys.stdout)
    else:
        with open("input.txt", 'r') as inp, open("output.txt", 'w') as out:
            main(inp, out)
