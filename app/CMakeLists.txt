cmake_minimum_required(VERSION 3.4.1)
add_library( # Sets the name of the library.
             native-lib
             SHARED
              src/main/cpp/bspatch.c
              src/main/cpp/bsdiff.c
              src/main/cpp/bs.c
              src/main/cpp/bzip2/blocksort.c
              src/main/cpp/bzip2/bzip2.c
              src/main/cpp/bzip2/bzip2recover.c
              src/main/cpp/bzip2/bzlib.c
              src/main/cpp/bzip2/compress.c
              src/main/cpp/bzip2/crctable.c
              src/main/cpp/bzip2/decompress.c
              src/main/cpp/bzip2/huffman.c
              src/main/cpp/bzip2/randtable.c
              )

find_library(
              log-lib
              log )

target_link_libraries(
                       native-lib
                       ${log-lib} )
