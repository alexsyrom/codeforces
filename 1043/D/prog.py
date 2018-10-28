import sys


def main(inp, out):
    n, m = list(map(int, inp.readline().split()))
    perms = []
    dicts = []
    for i in range(m):
        perm = list(map(int, inp.readline().split()))
        table = dict()
        for index, char in enumerate(perm):
            table[char] = index
        perms.append(perm)
        dicts.append(table)
    first = 0
    result = 0
    while first < n:
        indices = [dicts[i][perms[0][first]] for i in range(m)]
        diff = 0
        flag = True
        while flag:
            diff += 1
            for index in range(m):
                if indices[index] + diff >= n or perms[index][indices[index] + diff] != perms[0][indices[0] + diff]:
                    flag = False
                    break
        result += diff * (diff + 1) // 2
        first += diff
    print(result, file=out)


if __name__ == '__main__':
    if sys.platform == 'win32':
        main(sys.stdin, sys.stdout)
    else:
        with open("input.txt", 'r') as inp, open("output.txt", 'w') as out:
            main(inp, out)
