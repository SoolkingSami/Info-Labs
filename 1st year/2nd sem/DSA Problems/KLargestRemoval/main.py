n = int(input('Enter the number: '))
k = int(input('Enter the number of digits to be removed: '))

# at every step store the maximum number obtained by removing
# 1, 2, ..., k digits
for _ in range(0, k):
    dec_pow = 1
    curr = 0

    # while there is no digit left to be extracted
    while n // dec_pow > 0:
        # get the number by removing its (dec_pow / 10)th digit
        temp = (n // (dec_pow * 10)) * dec_pow + n % dec_pow
        dec_pow *= 10

        # and store the current maximum number
        curr = max(curr, temp)

    # update the final result with the largest number obtained
    # by removing one more digit
    n = curr
    # print(f'The largest number yielded after removing {_ + 1} digits is: {n}')

print(f'The largest number yielded after removing {k} digits is: {n}')
