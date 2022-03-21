import pygame

pygame.font.init()

class score:
    P1 = 00
    P2 = 00
    zero = pygame.image.load("assets/Images/0.png")
    one = pygame.image.load("assets/Images/1.png")
    two = pygame.image.load("assets/Images/2.png")
    three = pygame.image.load("assets/Images/3.png")
    four = pygame.image.load("assets/Images/4.png")
    five = pygame.image.load("assets/Images/5.png")
    num = [zero,one,two,three,four,five]
    font = pygame.font.Font("assets/Fonts/ALBAS___.TTF", 60)

    def init(screen):
        screen.blit(score.font.render ('x', True, (255,255,255)), (437,40))
        screen.blit(score.num[score.P1],(330,40))
        screen.blit(score.num[score.P2], (502,40))
