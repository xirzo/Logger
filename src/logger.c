#include <stdarg.h>
#include <stdio.h>
#include "../include/logger.h"

void logger_set_output_file(FILE *file) {
  g_Logger_output = file;
}

void logger_log(LOGGER_LEVEL level, const char *file, int line, const char *format, ...) {
  FILE *output = g_Logger_output ? g_Logger_output : stderr;

  const char *level_prefix;

  switch (level) {
    case LOGGER_ERROR: {
      level_prefix = "ERROR";
      break;
    }
    case LOGGER_WARNING: {
      level_prefix = "WARNING";
      break;
    }
    case LOGGER_INFO: {
      level_prefix = "INFO";
      break;
    }
  }

  fprintf(output, "[%s] %s:%d: ", level_prefix, file, line);
  va_list args;
  va_start(args, format);
  vfprintf(output, format, args);
  va_end(args);
  fprintf(output, "\n");
  fflush(output);
}
