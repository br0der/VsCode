import time


game = []
playerTurn = True

def sumXor():
    s = 0
    for elem in game:
        s^=elem
    return s

def isOver():
    for elem in game:
        if elem!=0:
            return False
    return True

def printBoard():
    for i in range(len(game)):
        for j in range(game[i]):
            print("X", end=' ')
        print()

def whereToEat():
    s = sumXor()
    if s==0: # losing
        for i in range(len(game)):
            if game[i]!=0:
                return [i, 1]
    s_copy = s
    msb = 1
    while s_copy!=1:
        msb<<=1
        s_copy>>=1
    for i in range(len(game)):
        if game[i]&msb:
            return [i, game[i]-(game[i]^s)]
    return IndexError

print("Give each row's # of elements, each separated by a space")

game = list(map(int, input().split()))

while not isOver():
    print()
    idx = float("INF")
    amt = float("INF")
    if playerTurn:
        print("Player turn!")
        printBoard()
        # print(idx>0)
        while (idx<0) or (idx>=len(game)) or (idx!=float("INF") and game[idx]==0):
            if idx!=float("INF"):
                print("Out of bounds!\n")
            idx = int(input("What row would you like to take from?\n"))
        while amt<=0 or amt>len(game):
            if amt!=float("INF"):
                print("Invalid amount!\n")
            amt = int(input("How many would you like to take from this row?\n"))

    else:
        print("Computer turn!")
        printBoard()
        print("Thinking...")
        # print(whereToEat())
        idx, amt = whereToEat()
        print("Computer chose to take " + str(amt) + " from index " + str(idx) + "!")
        time.sleep(2)
    game[idx]-=amt
    playerTurn = not playerTurn

print("Game over!")
if playerTurn:
    print("You lose...")
else:
    print("You win!!")