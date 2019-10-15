import pygame

pygame.init()

gameWidth = 400
gameHeight = 400

white = (255,255,255)
black = (0,0,0)
grey = (187, 197, 201)
backColor = (62, 117, 103)

position = [25,150,275]
iterators = [0,1,2]

gameOver = False

num = [[1,2,3],[-1,5,6],[7,8,4]]

currX = 0
currY = 1

outerRect = pygame.Rect(10,10,380,380)

gameScreen = pygame.display.set_mode((gameWidth, gameHeight))
pygame.display.set_caption("8-Puzzle")


def drawBoard():
    gameScreen.fill(backColor)
    pygame.draw.rect(gameScreen, white, outerRect)

    font = pygame.font.Font(None,45)

    for y in iterators:
        # print("Y: ",y)
        for x in iterators:
            # print("    X: ",x)
            if y == currY and x == currX:
                pygame.draw.rect(gameScreen, black, pygame.Rect(position[x], position[y],100,100))
            else:
                pygame.draw.rect(gameScreen, grey, pygame.Rect(position[x], position[y],100,100))
            s = str(num[y][x])
            if num[y][x] == -1:
                continue
            text = font.render(s,1,black)
            textPos = text.get_rect()
            textPos.centerx = position[x] + 50
            textPos.centery = position[y] + 50
            gameScreen.blit(text, textPos)
            

def shiftLeft():
    global currX
    if currX == 0:
        return
    else:
        num[currY][currX] = num[currY][currX-1]
        currX -= 1
        num[currY][currX] = -1


def shiftRight():
    global currX
    if currX == 2:
        return
    else:
        num[currY][currX] = num[currY][currX+1]
        currX += 1
        num[currY][currX] = -1

def shiftDown():
    global currY
    if currY == 2:
        return
    else:
        num[currY][currX] = num[currY+1][currX]
        currY += 1
        num[currY][currX] = -1

def shiftUp():
    global currY
    if currY == 0:
        return
    else:
        num[currY][currX] = num[currY-1][currX]
        currY -= 1
        num[currY][currX] = -1


while not gameOver:
    drawBoard()
    pygame.display.update()
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            gameOver = True
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_LEFT:
                shiftLeft()
            elif event.key == pygame.K_RIGHT:
                shiftRight()
            elif event.key == pygame.K_UP:
                shiftUp()
            elif event.key == pygame.K_DOWN:
                shiftDown()