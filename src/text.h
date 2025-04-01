#define MAX_TEXT_ONSCREEN 8
#define MAX_LOADED_FONTS 8

typedef struct {
	SDL_Texture* texture;
	SDL_Rect rect;
} text_t;

void InitText(void);
void DrawOnScreenText(void);
void ClearOnScreenText(void);
void QueueText(char*,int,int);
void DrawFPS(void);
void DrawPlayerPosition(void);
void DestroyFonts(void);
