import pygame

class P1:
    img = pygame.image.load("assets/Images/P1.png")
    x = -30
    y = 175
    vel = 5

    def init(screen):
        screen.blit(P1.img, (P1.x,P1.y))

    def move(keys):
        if keys[pygame.K_w] and P1.y >= 1:
            P1.y -= P1.vel
        if keys[pygame.K_s] and P1.y <= 353:
            P1.y += P1.vel


class P2:
    img = pygame.image.load("assets/Images/P2.png")
    x = 844
    y = 175
    vel = 5

    def init(screen):
        screen.blit(P2.img, (P2.x,P2.y))

    def move(keys):
        if keys[pygame.K_UP] and P2.y >= 1:
            P2.y -= P2.vel
        if keys[pygame.K_DOWN] and P2.y <= 353:
            P2.y += P2.vel
