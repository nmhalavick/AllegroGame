cmake_minimum_required(VERSION 2.8)
file(GLOB sources *.h *.c *.cxx *.cpp *.hxx *.cpp)
file(GLOB main main.cpp)
list(REMOVE_DUPLICATES sources)
#INCLUDE_DIRECTORIES( ~cdshaffer/allegro/include )
#LINK_DIRECTORIES( ~cdshaffer/allegro/lib )
INCLUDE_DIRECTORIES( /usr/local/include )
LINK_DIRECTORIES( /usr/local/lib )
add_executable(main ${sources})

TARGET_LINK_LIBRARIES(main liballegro.dylib liballegro_dialog.dylib liballegro_main.dylib liballegro_image.dylib)

# I don't think this works
SET(GCC_DEBUG_COMPILE_FLAGS "-ggdb")
SET(GCC_DEBUG_LINK_FLAGS    "-ggdb")

add_definitions(${GCC_DEBUG_COMPILE_FLAGS})

#
# Add support for documentation generation via Doxygen
#
ADD_CUSTOM_TARGET(doc COMMAND doxygen Doxyfile)

#
#   BOOST unit test support
#

