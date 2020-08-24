/**
 *  Surface cpp - documenting code
 *
 */

#include "surface.h"
#include "constants.h"
#include "variable.h"

void rotate_surface(int x, int y, int w, int h, SDL_Surface* source, int angle)
{
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    offset.w = w;
    offset.h = h;
    SDL_Texture* texture_source = SDL_CreateTextureFromSurface(renderer, source);
    if (texture_source == NULL) {
        fprintf(stderr, "CreateTextureFromSurface failed: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Point center = { bike->w/2, bike->h/4 };
    SDL_RendererFlip flip = SDL_FLIP_NONE; // the flip of the texture.
    SDL_RenderCopyEx(renderer, texture_source, NULL, &offset, angle, &center, flip);
    SDL_DestroyTexture(texture_source);

    return;
}

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

    /* render the current animation step of our shape */
    //SDL_RenderCopy(Main_Renderer, BlueShapes, &SrcR, &DestR);
    SDL_RenderCopy(dest, texture_source, NULL, &offset);
    SDL_DestroyTexture(texture_source);

    return;
}

