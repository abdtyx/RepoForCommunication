file(GLOB source ./*.c ./*.cpp)

add_library(oo_src STATIC ${source})
target_include_directories(oo_src PUBLIC ./)