import pygame
from Ball import *
from Player import *
from ScoreBoard import *

pygame.init()
logo = pygame.image.load("assets/Images/Ball.png")
pygame.display.set_icon(logo)
pygame.display.set_caption("WallBall")
background = pygame.image.load("assets/Images/Background.jpg")
screen = pygame.display.set_mode((920,540))
font = pygame.font.Font("assets/Fonts/monof55.ttf", 35)

def main():
    running = True

    while running:
        speed = 15
        pygame.time.delay(speed)
        screen.blit(background,(0,0))
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
            if score.P1 > 4 or score.P2 > 4:
                running = False

        score.init(screen)
        P1.init(screen)
        P2.init(screen)
        ball.init(screen)
        keys=pygame.key.get_pressed()
        P1.move(keys)
        P2.move(keys)
        ball.move(keys)
        if ball.spacebar:
            screen.blit(font.render ('Press SPACE to play', True, (255,255,255)), (270,450))

        if ball.x > 865:
            ball.x,ball.y,P1.y,P2.y,ball.velx,ball.vely = 415,240,175,175,-5,-5
            score.P1 += 1
            print('Goal')

        if ball.x < -35:
            score.P2 += 1
            ball.x,ball.y,P1.y,P2.y, ball.velx, ball.vely = 415,240,175,175,5,5
            print('Goal')

        pygame.display.update()

    pygame.QUIT()

main()
