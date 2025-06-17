#include "logger.h"
#include <stdarg.h>

void logger_set_level(LOG_LEVEL level) {
  g_Log_level = level;
}

void logger_set_output_file(FILE *file) {
  g_Log_output = file;
}

void logger_log(LOG_LEVEL level, const char *file, int line, const char *format, ...) {
  if (level > g_Log_level) {
    return;
  }
  FILE *output = g_Log_level ? g_Log_output : stderr;

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
