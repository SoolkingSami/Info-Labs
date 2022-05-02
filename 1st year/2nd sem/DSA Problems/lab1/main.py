game = [[0 for j in range(0, 3)] for i in range(0, 3)]


def game_board(player=0, row=0, column=0, just_display=False):
    global game
    print('   a  b  c ')
    if not just_display:
        game[row][column] = player
        game = game
    for count, row in enumerate(game):
        print(count, row)
    print('\n')


game_board(player=1, row=1, column=0)
game_board(player=2, row=1, column=1)
