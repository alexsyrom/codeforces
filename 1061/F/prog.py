import sys
import random


def main(inp, out):
    n, k = list(map(int, inp.readline().split()))
    can = set(range(1, n + 1))
    for i in range(55):
        a = random.randint(1, n)
        b = a
        while b == a:
            b = random.randint(1, n)
        dd = set([a, b])
        for i in range(1, n + 1):
            if i == a or i == b:
                continue
            print("? {} {} {}".format(a, i, b))
            out.flush()
            answer = inp.readline().strip()
            if answer == "Yes":
                dd.add(i)
        if len(can) == 1:
            break
    print(can.pop())
    out.flush()


if __name__ == '__main__':
    main(sys.stdin, sys.stdout)
