
#define GAME_NAME "Aztroz Game"

#define SCREEN_X 800
#define SCREEN_Y 600

#define PLAYER_SIZE 32
#define PLAYER_ROTATION .3f
#define PLAYER_ROTATION_MULT .1

#define METEOR_TRANSFORM_SPEED 0.065
#define METEOR_ROTATION_SPEED 0.005

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

SDL_Window* CreateAztrozWindow(void);
SDL_Renderer* CreateAztrozRenderer(SDL_Window*);

void GameLoop(SDL_Window*, SDL_Renderer*);

void PlayerController(SDL_Event, player_t*);
void MeteorController(meteor_t*, size_t, SDL_Renderer*);

void LoadTextures(SDL_Renderer*);
void UnloadTextures(void);
SDL_Texture* UseTexture(int);

int RandRange(int, int);
