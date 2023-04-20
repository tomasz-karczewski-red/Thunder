#pragma once

#define syslog(level, format, ...)                      \
    do {                                                \
        fprintf(stdout, format"\n", ##__VA_ARGS__);     \
        fflush(stdout);                                 \
    } while (0)

