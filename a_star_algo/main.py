#!/bin/python3
import pygame
from queue import PriorityQueue


# GAME PROPS
WIDTH = 900
ROWS = 50
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
        self.neighbors = []
        if self.row < self.total_rows - 1 and grid[self.row + 1][self.col].is_wall() == False:
            self.neighbors.append(grid[self.row + 1][self.col])

        if self.row > 0 and grid[self.row - 1][self.col].is_wall() == False:
            self.neighbors.append(grid[self.row - 1][self.col])

        if self.col < self.total_rows - 1 and grid[self.row][self.col + 1].is_wall() == False:
            self.neighbors.append(grid[self.row][self.col + 1])

        if self.col > 0 and grid[self.row][self.col - 1].is_wall() == False:
            self.neighbors.append(grid[self.row][self.col - 1])

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

def build_path(came_from, current, draw, win):
    while current in came_from:
        current = came_from[current]
        current.make_path()
        draw(win, [current])

# def a_star_algorithm(draw, grid, start, end):
def a_star_algorithm(draw, win, grid, start, end):
    count = 0
    open_set = PriorityQueue()
    open_set.put((0, count, start))
    came_from = {}
    g_score = {spot: float("inf") for row in grid for spot in row}
    g_score[start] = 0
    f_score = {spot: float("inf") for row in grid for spot in row}
    f_score[start] = h(start.get_pos(), end.get_pos())

    open_set_hash = {start}

    while not open_set.empty():
        changed_sopts = []
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
        
        current = open_set.get()[2]
        open_set_hash.remove(current)

        if current == end: # PATH IS FOUND
            build_path(came_from, end, draw, win)
            return True

        for neighbor in current.neighbors:
            tmp_g_score = g_score[current] + 1

            if tmp_g_score < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tmp_g_score
                f_score[neighbor] = tmp_g_score + h(neighbor.get_pos(), end.get_pos())
                if neighbor not in open_set_hash:
                    count += 1
                    open_set.put((f_score[neighbor], count, neighbor))
                    open_set_hash.add(neighbor)
                    neighbor.make_open()
                    changed_sopts.append(neighbor)
        if current != start:
            current.make_closed()
            changed_sopts.append(current)
        draw(win, changed_sopts)

    return False

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
                if row < 0 or row >= ROWS or col < 0 or col >= ROWS:
                    continue
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
                if row < 0 or row >= ROWS or col < 0 or col >= ROWS:
                    continue
                spot = grid[row][col]
                spot.reset()
                changed_spots.append(spot)
                if spot == start:
                    start = None
                elif spot == end:
                    end = None

            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE and not started:
                    for row in grid:
                        for spot in row:
                            spot.update_neighbors(grid)
                    # a_star_algorithm(lambda: draw(win, grid, ROWS, WIDTH), grid, start, end)
                    a_star_algorithm(update_spots, win, grid, start, end)

        update_spots(win, changed_spots)
    pygame.quit()

main(WIN, WIDTH)
