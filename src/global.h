
#define PROJECT "Aztroz Game"

#define SCREEN_X 800
#define SCREEN_Y 600

#define PLAYER_SIZE 32
#define PLAYER_ROTATION 1.25f
#define PLAYER_ROTATION_MULT 3.5f

#define METEOR_TRANSFORM_SPEED 5.0f
#define METEOR_ROTATION_SPEED 2.0f

#define LENGTH(x) sizeof(x) / sizeof(x[0])
#define GRATORAD(x) x * 0.01745329251f

typedef enum bool { false, true } boolean;

typedef struct {
    int sz;
    double angle;
    SDL_FRect rect;
    SDL_FPoint pivot;
} player_t;

typedef struct {
	int sz;
    SDL_FRect rect;
    SDL_FPoint pivot;
} projectile_t;

typedef struct {
	int sz;
	double angle;
	SDL_FRect rect;
	SDL_FPoint pivot;
} meteor_t;

void GameLoop(SDL_Window*, SDL_Renderer*);
void RenderFPSOnScreen (SDL_Renderer*);

void PlayerController(SDL_Event, player_t*);
void PlayerMoveKeyboard(SDL_Event);
void PlayerMoveGamepad(SDL_Event);
void MeteorController(meteor_t*, size_t, SDL_Renderer*);

int RandRange(int, int);
