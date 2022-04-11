n = int(input('Enter the number of elements: '))

perm = [i for i in range(1, n + 1)]
odd_values = [i for i in range(1, n + 1, 2)]
used = dict(zip(odd_values, [False] * len(odd_values)))


def gen_fixed_perm(step=0):
    if step > n:
        print(perm)
    else:
        for i in odd_values:
            if not used[i]:
                used[i] = True
                perm[step] = i
                gen_fixed_perm(step + 2)
                used[i] = False


gen_fixed_perm()
