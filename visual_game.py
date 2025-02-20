import pygame
import sys
from rock_paper_scissors import game_backup

pygame.init()
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Rock, paper, scissorst")

white = (255, 255, 255)
red = (255, 0, 0)

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit
            sys.exit()

    
    screen.fill(white)

    pygame.draw.rect(screen, red, (350, 250, 100, 100))

    pygame.display.flip()

    pygame.time.Clock().tick(60)
        
