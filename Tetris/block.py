from colors import Colors
from position import Position
import pygame as pg

class Block:
    def __init__(self,id):
        self.id = id
        self.cells = {}
        self.cell_sice = 30
        self.row_offset = 0
        self.column_offset = 0
        self.rotation_state = 0
        self.colors = Colors.get_cell_color()
        
    def get_cell_positions(self):
        tiles = self.cells[self.rotation_state]
        move_tiles = []
        for tile in tiles:
            position = Position(tile.row + self.row_offset, tile.column + self.column_offset)
            move_tiles.append(position)
        return move_tiles
        
    def rotate(self):
        self.rotation_state += 1
        if self.rotation_state == len(self.cells):
            self.rotation_state = 0
            
    def draw(self,screen):
        tiles = self.get_cell_positions()
        for tile in tiles:
            tile_rect = pg.Rect(tile.column*self.cell_sice + 1, tile.row*self.cell_sice + 1,
                                self.cell_sice - 1, self.cell_sice - 1)
            pg.draw.rect(screen,self.colors[self.id],tile_rect)
        
    def undo_rotation(self):
        self.rotation_state -= 1
        if self.rotation_state == 0:
            self.rotation_state = len(self.cells) - 1
            
    def move(self, rows, columns):
        self.row_offset += rows
        self.column_offset += columns
        
        
