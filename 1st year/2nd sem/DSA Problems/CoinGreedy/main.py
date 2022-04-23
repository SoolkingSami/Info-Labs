s = int(input('Enter the sum: '))
n = int(input('Enter the range of coin values: '))
e = int(input('Enter the base coin value: '))


# find the first power that fits the sum
def get_next_pow(start, curr_sum):
    for i in range(start, -1, -1):
        if e ** i <= curr_sum:
            return i


coin_nr = 0
curr_pow = get_next_pow(n, s)
print()
# greedy main
while s != 0:
    # exhaust the current suitable coin value
    curr_val = e ** curr_pow
    curr_fits = s // curr_val
    # update the sum
    s -= curr_val * curr_fits
    coin_nr += curr_fits
    print(f'{curr_fits} coins of value {curr_val} ({e}^{curr_pow}) has been added')
    # get the next suitable value
    curr_pow = get_next_pow(curr_pow, s)

print(f'Final number of coins: {coin_nr}')
