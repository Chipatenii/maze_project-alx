#ifndef PLAYER_H
#define PLAYER_H

#define ROTATE_SPEED 0.1
#define MOVE_SPEED 0.1

typedef struct {
    float x, y;
    float angle;
} Player;

typedef struct {
    Player player;
    int running;
    char **map;
} Game;

void rotatePlayer(Player *player, float angle);
void movePlayer(Player *player, char **map, float speed);
void strafePlayer(Player *player, char **map, float speed);

#endif // PLAYER_H