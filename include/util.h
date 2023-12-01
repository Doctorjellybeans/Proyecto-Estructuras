#ifndef UTIL_H
#define UTIL_H

// Debug
void success(const char* fmt, ...);
void error(const char* fmt, ...);

// Pausa la applicación N milisegundos
void sleep(unsigned int ms);

// Consigue el tiempo actual
unsigned int getTime();

// Devuelve el mayor valor
template <typename T>
inline T max(T a, T b) {
    if ( a > b)
        return a;
    else
        return b;
}

// Devuelve el menor valor
template <typename T>
inline T min(T a, T b) {
    if ( a > b)
        return a;
    else 
        return b;
}

#endif //UTIL_H