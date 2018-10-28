import sys


def compute_z(x):
    z = [0 for i in x]
    left = 0
    right = 0
    for i in range(len(x)):
        z[i] = max(0, min(right - i, z[i - left]))
        while i + z[i] < len(x) and x[z[i]] == x[i + z[i]]:
            z[i] += 1
        if i + z[i] > right:
            right = i + z[i]
            left = i
    return z


def main(inp, out):
    n = int(inp.readline())
    a = list(map(int, inp.readline().split()))
    prev = 0
    x = [0 for i in range(n)]
    for i in range(n):
        x[i] = a[i] - prev
        prev = a[i]
    z = compute_z(x)
    answer = []
    for i in range(1, n):
        if z[i] + i == n:
            answer.append(i)
    answer.append(n)
    print(len(answer), file=out)
    print(' '.join(str(el) for el in answer), file=out)


if __name__ == '__main__':
    if sys.platform == 'win32':
        main(sys.stdin, sys.stdout)
    else:
        with open("input.txt", 'r') as inp, open("output.txt", 'w') as out:
            main(inp, out)
