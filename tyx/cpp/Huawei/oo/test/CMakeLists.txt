file(GLOB source ./*.c ./*.cpp ./*.cc)

add_executable(oo_test ${source})
target_link_libraries(oo_test PRIVATE oo_src gtest_main)