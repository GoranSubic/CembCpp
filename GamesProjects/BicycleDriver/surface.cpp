#include "surface.h"
#include "constants.h"
#include "variable.h"


void apply_surface(int x, int y, int w, int h, SDL_Surface* source, SDL_Renderer* dest, SDL_Rect* clip)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    offset.w = w;
    offset.h = h;
    //SDL_BlitSurface(source, clip, dest, &offset);
    SDL_Texture* texture_source = SDL_CreateTextureFromSurface(dest, source);
    if (texture_source == NULL) {
        fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
        exit(1);
    }

    //if (x == 0 && y == 0) {
    //    /* render background, whereas NULL for source and destination
    //      rectangles just means "use the default" */
    //      //SDL_RenderCopy(Main_Renderer, Background_Tx, NULL, NULL);
    //    SDL_RenderCopy(dest, texture_source, NULL, NULL);
    //}
    //else {
    //    /* render the current animation step of our shape */
    //    //SDL_RenderCopy(Main_Renderer, BlueShapes, &SrcR, &DestR);
        SDL_RenderCopy(dest, texture_source, NULL, &offset);
    //}
    SDL_DestroyTexture(texture_source);

    return;
}

