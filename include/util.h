#ifndef UTIL_H
#define UTIL_H

void error(const char* fmt, ...);

// Devuelve el mayor valor
template <typename T>
T max(T a, T b) {
    if ( a > b) {
        return a;
    } else {
        return b;
    }
}

// Devuelve el menor valor
template <typename T>
T min(T a, T b) {
    if ( a > b) {
        return a;
    } else {
        return b;
    }
}


#endif //UTIL_H