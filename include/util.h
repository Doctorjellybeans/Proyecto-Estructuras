#ifndef UTIL_H
#define UTIL_H

void success(const char* fmt, ...);
void error(const char* fmt, ...);
void sleep(unsigned int ms);

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