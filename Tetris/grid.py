import pygame as pg
from colors import Colors

class Grid(Colors):
    def __init__(self):
        self.num_rows = 20
        self.num_cols = 10
        self.cell_size = 30
        self.grid = [[0 for i in range(self.num_cols)] for i in range(self.num_rows)]
        self.colors = Colors.get_cell_color()
        
    def print_grid(self):
        for row in range(self.num_rows):
            for col in range(self.num_cols):
                print(self.grid[row][col], end = " ")
            print()
        
    def is_inside(self,row,column):
        if row >= 0 and row < self.num_rows and column >= 0 and column < self.num_cols:
            return True
        else:
            return False 
        
    def is_empty(self, row, column):
        if self.grid[row][column] == 0:
            return True
    
    def reset(self):
        for row in range(self.num_rows):
            for column in range(self.num_cols):
                self.grid[row][column] = 0
        
    def is_row_full(self, row):
        for column in range(self.num_cols):
            if self.grid[row][column] == 0:
                return False    
        return True     
    
    def clear_row(self,row):
        for column in range(self.num_cols):
            self.grid[row][column] = 0
            
    def move_row_down(self, row, num_rows):
        for column in range(self.num_cols):
            self.grid[row+num_rows][column] = self.grid[row][column]
            self.grid[row][column] = 0
            
    def clear_full_rows(self):
        completed = 0
        for row in range(self.num_rows-1,0,-1):
            if self.is_row_full(row):
                self.clear_row(row)
                completed += 1
            elif completed > 0:
                self.move_row_down(row,completed)
        return completed
            
      
    def draw(self,screen):
        for row in range(self.num_rows):
            for col in range(self.num_cols):
                cell_value = self.grid[row][col]
                cell_rect = pg.Rect(col*self.cell_size + 1, row*self.cell_size + 1,
                                    self.cell_size - 1, self.cell_size - 1) 
                pg.draw.rect(screen,self.colors[cell_value],cell_rect)