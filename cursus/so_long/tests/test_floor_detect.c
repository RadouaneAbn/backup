#include <stdio.h>

#define WALL '1'
#define FLOOR '0'

// Directions: {row_offset, col_offset}
int directions[4][2] = {
    {-1,  0}, // top
    { 1,  0}, // bottom
    { 0, -1}, // left
    { 0,  1}, // right
};

// char **arr = {
//     "no walls",
//     "top wall",
//     "bottom wall",
//     "left wall",
//     "right wall",
//     "top left walls",
//     "top right walls",
//     "bottom left walls",
//     "bottom right walls",
//     "top left right walls",
//     "bottom left right walls",
//     "left top bottom walls",
//     "right top bottom walls",
//     "left right walls",
//     "top bottom walls",
//     "full walls walls"
// };


// Function to check if a cell is a wall (handling bounds)
int is_wall(char map[10][10], int rows, int cols, int r, int c) {
    return (r >= 0 && r < rows && c >= 0 && c < cols && map[r][c] == WALL);
}

// Function to classify a floor tile based on surrounding walls
void classify_floors(char map[10][10], int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (map[r][c] == FLOOR) {  // Only process floor tiles
                int mask = 0;

                for (int i = 0; i < 4; i++) {
                    int nr = r + directions[i][0];
                    int nc = c + directions[i][1];
                    if (is_wall(map, rows, cols, nr, nc)) {
                        mask |= (1 << i);  // Use bitmask for wall positions
                        // 111
                        // 100
                        // 111
                        // 00000000
                        // 00000001 << 0
                    }   // 00000001
                        // 00000000 << 1
                        // 00000001
                        // 00000100 << 2
                        // 00000101
                        // 00001000 << 3
                        // 00001101
                }

                // Print or store classification (bitmask)
                // printf("Floor at (%d, %d) mask: %d\n", r, c, mask);
                if (mask == 5)
                    printf("Floor at (%d, %d) top left\n", r, c);
                else if (mask == 1)
                    printf("Floor at (%d, %d) top\n", r, c);
                else if (mask == 9)
                    printf("Floor at (%d, %d) top right\n", r, c);
                else if (mask == 6)
                    printf("Floor at (%d, %d) bottom left\n", r, c);
                else if (mask == 2)
                    printf("Floor at (%d, %d) bottom\n", r, c);
                else if (mask == 10)
                    printf("Floor at (%d, %d) bottom right\n", r, c);
                else if (mask == 4)
                    printf("Floor at (%d, %d) left\n", r, c);
                else if (mask == 0)
                    printf("Floor at (%d, %d) None\n", r, c);
                else if (mask == 8)
                    printf("Floor at (%d, %d) right\n", r, c);
                else if (mask == 12)
                    printf("Floor at (%d, %d) left right\n", r, c);
                else if (mask == 13)
                    printf("Floor at (%d, %d) top left right\n", r, c);
                else if (mask == 15)
                    printf("Floor at (%d, %d) full\n", r, c);
                else if (mask == 7)
                    printf("Floor at (%d, %d) left top bottom\n", r, c);
                else if (mask == 11)
                    printf("Floor at (%d, %d) right top bottom\n", r, c);
                else if (mask == 14)
                    printf("Floor at (%d, %d) bottom left right\n", r, c);
                else if (mask == 3)
                    printf("Floor at (%d, %d) top bottom\n", r, c);
                else
                    printf("Floor at (%d, %d) mask: %d\n", r, c, mask);
            }
        }
    }
}

int main() {
    char map[10][10] = {
    //    0    1    2    3    4    5    6    7    8    9
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}, // 0
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, // 1
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'}, // 2
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}, // 3
        {'1', '0', '1', '0', '0', '0', '0', '0', '0', '1'}, // 4
        {'1', '0', '0', '0', '0', '1', '1', '1', '1', '1'}, // 5
        {'1', '0', '1', '0', '0', '0', '1', '1', '1', '1'}, // 6
        {'1', '1', '1', '1', '1', '1', '1', '0', '1', '1'}, // 7
        {'1', '0', '1', '0', '0', '0', '1', '1', '1', '1'}, // 8
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}  // 9
    };
    classify_floors(map, 10, 10);
}