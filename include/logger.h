#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

typedef enum {
  LOGGER_INFO,
  LOGGER_WARNING,
  LOGGER_ERROR,
} LOGGER_LEVEL;

#define LOG_ERROR(...)   logger_log(LOGGER_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define LOG_WARNING(...) logger_log(LOGGER_WARNING, __FILE__, __LINE__, __VA_ARGS__)
#define LOG_INFO(...)    logger_log(LOGGER_INFO, __FILE__, __LINE__, __VA_ARGS__)

static FILE *g_Logger_output = NULL;

void logger_set_output_file(FILE *file);
void logger_log(LOGGER_LEVEL level, const char *file, int line, const char *format, ...);

#endif  // !LOGGER_H
