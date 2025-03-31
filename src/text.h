#define MAX_TEXT_ONSCREEN 8

typedef struct {
	SDL_Texture* texture;
    SDL_Rect rect;
} text_t;

void InitText(void);
void DrawOnScreenText(void);
void ClearOnScreenText(void);
void QueueText(char*,int,int,TTF_Font*);
void DrawFPS(void);
void DrawPlayerPosition(void);
void DestroyFonts(void);
