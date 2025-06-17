# Logger

## Build

```
mkdir build && cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr/local
cmake --build .
cmake --install .
```

## Install

In your **CMakeLists.txt** add

```
find_package(logger REQUIRED)
target_link_libraries(your_target PRIVATE logger::logger)
```

## Use

```
#include <logger.h>

int main() {
    FILE *output = fopen("log.txt", "w");
    logger_set_output_file(output);

    LOG_INFO("Using installed logger!");

    fclose(output);
    return 0;
}
```
