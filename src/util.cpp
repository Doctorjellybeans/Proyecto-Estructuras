#include <stdio.h>
#include <stdarg.h>

#include <SDL2/SDL.h>

// - Quiero std::print()
// + Pero si tenemos std::print() en casa
// std::print() en casa:
void success(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    printf("\x1b[38;2;40;150;35m");
    vfprintf(stdout, fmt, args);
    printf("\x1b[0m\n");

    va_end(args);
}

void error(const char* fmt, ...) {
    va_list args;

    va_start(args, fmt);

    printf("\x1b[48;2;50;50;50m\x1b[38;2;235;10;21m Error: \x1b[0m\x1b[0m\x1b[48;2;40;40;40m\x1b[38;2;185;25;21m ");
    vfprintf(stdout, fmt, args);
    printf(" \x1b[0m\x1b[0m\n");

    va_end(args);
}

void sleep(unsigned int ms) {
    SDL_Delay(ms);
}