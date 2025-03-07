#!/bin/python3
import pygame


# GAME PROPS
WIDTH = 1000
ROWS = 100
GAP = WIDTH // ROWS

WIN = pygame.display.set_mode((WIDTH, WIDTH))
pygame.display.set_caption("A* Path Finding Algorithm")

WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GREEN = (0, 255, 0)
RED = (255, 0, 0)
PURPLE = (128, 0, 128)
ORANGE = (255, 165, 0)
GREY = (128, 128, 128)
BLUE = (0, 255, 0)
YELLOW = (255, 255, 0)
TURQUOISE = (64, 244, 208)

class Spot:
    def __init__(self, row, col, width, total_rows):
        self.row = row
        self.col = col
        self.x = row * width
        self.y = col * width
        self.color = WHITE
        self.neighbors = []
        self.width = width
        self.total_rows = total_rows

    def get_pos(self):
        return self.row, self.col
    
    def is_closed(self):
        return self.color == RED
    
    def is_open(self):
        return self.coloe == GREEN
    
    def is_wall(self):
        return self.color == BLACK
    
    def is_start(self):
        return self.color == ORANGE

    def is_end(self):
        return self.color == TURQUOISE
    
    def reset(self):
        self.color = WHITE

    def make_closed(self):
        self.color = RED

    def make_open(self):
        self.color = GREEN
    
    def make_wall(self):
        self.color = BLACK

    def make_start(self):
        self.color = ORANGE

    def make_end(self):
        self.color = TURQUOISE

    def make_path(self):
        self.color = PURPLE

    def draw(self, win):
        pygame.draw.rect(win, self.color, (self.x, self.y, self.width, self.width))  # Fill color
        # pygame.draw.line(win, GREY, (self.x, self.y), (self.x + self.width, self.y))  # Top border
        # pygame.draw.line(win, GREY, (self.x, self.y), (self.x, self.y + self.width))  # Left border
        # pygame.draw.line(win, GREY, (self.x, self.y + self.width - 1), (self.x + self.width, self.y + self.width - 1))  # Bottom border
        # pygame.draw.line(win, GREY, (self.x + self.width - 1, self.y), (self.x + self.width - 1, self.y + self.width))  
        
    def update_neighbors(self, grid):
        pass

    def __lt__(self, other):
        return False
    
def h(p1, p2):
    x1, y1 = p1
    x2, y2 = p2
    return abs(x1 - x2) + abs(y1 - y2)

def make_grid(rows, width):
    grid = []
    for i in range(rows):
        grid.append([])
        for j in range(rows):
            spot = Spot(i, j, GAP, rows)
            grid[i].append(spot)
    return grid

def draw_grid(win, rows, width):
    for i in range(rows):
        pygame.draw.line(win, GREY, (0, i * GAP), (width, i * GAP))
    for j in range(rows):
        pygame.draw.line(win, GREY, (j * GAP, 0), (j * GAP, width))

def update_spots(win, changed_spots):
    for spot in changed_spots:
        spot.draw(win)
    draw_grid(win, ROWS, WIDTH)
    pygame.display.update()

def draw(win, grid, rows, width):
    win.fill(WHITE)
    for row in grid:
        for spot in row:
            spot.draw(win)

    draw_grid(win, rows, width)
    pygame.display.update()

def get_clicked_pos(pos, row, width):
    y, x = pos
    row = y // GAP
    col = x // GAP
    
    return row, col

def main(win, width):
    grid = make_grid(ROWS, width)

    start = None
    end = None
    
    run = True
    started = False
    draw(win, grid, ROWS, width)
    while run:
        changed_spots = []
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                run = False

            if started:
                continue

            if pygame.mouse.get_pressed()[0]: # LEFT CLICK
                pos = pygame.mouse.get_pos()
                row, col = get_clicked_pos(pos, ROWS, width)
                spot = grid[row][col]
                if not start and spot != end:
                    start = spot
                    start.make_start()
                    changed_spots.append(spot)
                elif not end and spot != start:
                    end = spot
                    end.make_end()
                    changed_spots.append(spot)
                elif spot != end and spot != start:
                    changed_spots.append(spot)
                    spot.make_wall()
                
                    
            elif pygame.mouse.get_pressed()[2]: # RIGHT CLICK
                pos = pygame.mouse.get_pos()
                row, col = get_clicked_pos(pos, ROWS, width)
                spot = grid[row][col]
                spot.reset()
                changed_spots.append(spot)
                if spot == start:
                    start = None
                elif spot == end:
                    end = None

            elif event.type == pygame.K:
                if event.key == pygame.K_SPACE and not started:


        update_spots(win, changed_spots)
    pygame.quit()

main(WIN, WIDTH)
