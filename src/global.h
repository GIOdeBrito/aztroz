
#define GAME_NAME "Aztroz Game"
#define PLAYER_SIZE 32
#define PLAYER_ROTATION .4f
#define PLAYER_ROTATION_MULT .33434f

#define LENGTH(x) sizeof(x) / sizeof(x[0])
#define GRATORAD(x) x * 0.01745329251f

typedef enum bool { false, true };

typedef struct {
    int sz;
    double angle;
    // Aceita valores quebrados
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
	SDL_FRect rect;
} meteoros_t;

SDL_Window* CreateAztrozWindow(void);
SDL_Renderer* CreateAztrozRenderer(SDL_Window*);

void control_player(SDL_Event, player_t*);
void LoadTexture(SDL_Renderer*);
void UnloadTextures(void);
SDL_Texture* UseTexture(int);
