#define PLAYER_SIZE 32
#define PLAYER_ROTATION 1.25f
#define PLAYER_ROTATION_MULT 3.5f

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

void InstantiatePlayer(void);
void UpdatePlayer(SDL_Event);
int PlayerPosX(void);
int PlayerPosY(void);
void PlayerController(SDL_Event);
void PlayerMoveKeyboard(SDL_Event);
void PlayerMoveGamepad(SDL_Event);
