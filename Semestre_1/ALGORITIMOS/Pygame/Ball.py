import pygame
import random
from Player import *

class ball:
    spacebar = True
    a = 0
    img = pygame.image.load("assets/Images/Ball.png")
    x = 415
    y = 240
    velx = 4
    vely = 4
    sort2 = random.randint(1,10)

    def init(screen):
        screen.blit(ball.img,(ball.x,ball.y))

        for i in range(P2.y,P2.y+130):
            if ball.x >= P2.x-5 and ball.y == i:
                ball.velx = -ball.velx +1

        for i in range(P1.y,P1.y+130):
            if ball.x <= P1.x+45 and ball.y == i:
                ball.velx = -ball.velx -1

        if ball.y <= 10 or ball.y >= 450:
            ball.vely = -ball.vely

    def move(keys):
        if keys[pygame.K_SPACE]:
            ball.spacebar = False
            ball.a += 1
        if ball.a >= 1:
            ball.x-=ball.velx
            if ball.sort2 % 2 == 0:
                ball.y+=ball.vely
            else:
                ball.y-=ball.vely
