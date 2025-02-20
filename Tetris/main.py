import pygame as pg,sys
from game import Game

pg.init()
magenta = (84,83,144)

screen = pg.display.set_mode((301,600))
pg.display.set_caption("Python Tetris")

clock = pg.time.Clock()

game = Game()

GAME_UPDATE = pg.USEREVENT  
pg.time.set_timer(GAME_UPDATE, 200)

while True:
    for event in pg.event.get():
        if event.type == pg.QUIT:
            pg.quit()
            sys.exit()
        
        if event.type == pg.KEYDOWN:
            if game.game_over == True:
                game.game_over = False
                game.reset()
            if event.key == pg.K_LEFT and game.game_over == False:
                game.move_left()
            if event.key == pg.K_RIGHT and game.game_over == False:
                game.move_right()
            if event.key == pg.K_DOWN and game.game_over == False:
                game.move_down()
            if event.key == pg.K_UP and game.game_over == False:
                game.rotate()
        if event.type == GAME_UPDATE and game.game_over == False:
            game.move_down()
    
    screen.fill(magenta)
    game.draw(screen)
    
    pg.display.update()
    clock.tick(60)