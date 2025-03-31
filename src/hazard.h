#define METEOR_MAX_NUMBER 6
#define METEOR_TRANSFORM_SPEED 5.0f
#define METEOR_ROTATION_SPEED 2.0f

typedef struct {
	int sz;
	double angle;
	float speed;
	SDL_FRect rect;
	SDL_FPoint pivot;
} meteor_t;

void InitHazards(void);
void UpdateMeteors(void);
