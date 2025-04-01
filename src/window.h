#define SCREEN_X 720
#define SCREEN_Y 720

int InitWindow(void);
int InitRenderer(void);
SDL_Window* GetWindow(void);
SDL_Renderer* GetRenderer(void);
int GetWindowX(void);
int GetWindowY(void);
void DestroyWindow(void);
void DestroyRenderer(void);
