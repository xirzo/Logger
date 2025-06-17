#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

typedef enum {
  LOGGER_INFO,
  LOGGER_WARNING,
  LOGGER_ERROR,
} LOG_LEVEL;

#define LOG_ERROR(...)   logger_log(LOG_ERROR, __FILE__, __LINE__, __VA_ARGS__)
#define LOG_WARNING(...) logger_log(LOG_WARNING, __FILE__, __LINE__, __VA_ARGS__)
#define LOG_INFO(...)    logger_log(LOG_INFO, __FILE__, __LINE__, __VA_ARGS__)

static LOG_LEVEL g_Log_level = LOGGER_INFO;
static FILE *g_Log_output = NULL;

void logger_set_level(LOG_LEVEL level);
void logger_set_output_file(FILE *file);
void logger_log(LOG_LEVEL level, const char *file, int line, const char *format, ...);

#endif  // !LOGGER_H
