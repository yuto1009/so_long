#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define WIDTH  32
#define HEIGHT 6

typedef struct {
    int x, y;
} Point;

bool visited[HEIGHT][WIDTH];

bool dfs(Point current, Point end, char map[HEIGHT][WIDTH]) {
    if (current.x == end.x && current.y == end.y) {
        return true;  // ゴールに到達
    }

    // 4つの移動方向
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int d = 0; d < 4; d++) {
        int nx = current.x + dx[d];
        int ny = current.y + dy[d];

        if (nx < 0 || nx >= WIDTH || ny < 0 || ny >= HEIGHT) continue;
        if (visited[ny][nx]) continue;
        if (map[ny][nx] == '1' || map[ny][nx] == 'C') continue;  // 壁やCを避ける

        visited[ny][nx] = true;

        Point next = {nx, ny};
        if (dfs(next, end, map)) { // 再帰的に次の点を探索
            return true;
        }
    }

    return false;
}

int main() {
    char map[HEIGHT][WIDTH] = {
        "1111111111111111111111111111111111",
        "1E1000000000000C00000C000000000001",
        "1010010100100000101001000000010101",
        "1000010010101010001001000000010101",
        "1P0000000C00C0000000000000000000C1",
        "1111111111111111111111111111111111"
    };

    Point start, end;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (map[y][x] == 'P') {
                start.x = x;
                start.y = y;
            } else if (map[y][x] == 'E') {
                end.x = x;
                end.y = y;
            }
        }
    }

    memset(visited, false, sizeof(visited));
    visited[start.y][start.x] = true;

    if (dfs(start, end, map)) {
        printf("ゴールに到達可能です！\n");
    } else {
        printf("ゴールに到達不可能です。\n");
    }

    return 0;
}