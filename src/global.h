#define PROJECT "Aztroz Game"

#define LENGTH(x) sizeof(x) / sizeof(x[0])
#define GRATORAD(x) x * 0.01745329251f

typedef enum bool { false, true } boolean;

void GameLoop(void);
int RandRange(int, int);
