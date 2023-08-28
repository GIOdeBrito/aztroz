
#define GAME_NAME "Aztroz Game"
#define PLAYER_SIZE 32
#define PLAYER_ROTATION .6f
#define PLAYER_ROTATION_MULT 4.33434f

enum bool { false, true };

typedef struct {
    int width;
    int height;
    double angle;
    SDL_Rect rect;
    SDL_Point pivot;
} player_t;

typedef struct {
    int posx;
    int posy;
    int tamanho;
} projectile_t;
