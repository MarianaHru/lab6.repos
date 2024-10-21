cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_TOOLCHAIN_FILE /Users/tarasgrudzinskij/Documents/semestr_1/програмування/vcpkg/scripts/buildsystems/vcpkg.cmake)

set(GTest_DIR /Users/tarasgrudzinskij/Documents/semestr_1/програмування/vcpkg/installed/x64-osx/share/gtest)
find_package(GTest CONFIG REQUIRED)

# Додаємо тести для lab6_1
add_executable(lab6_1_unit_test lab6_1/lab6_1_unit_test.cpp lab6_1/lab6_1.cpp)
target_compile_definitions(lab6_1_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab6_1_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)


# Додаємо тести для lab6_1_rec
add_executable(lab6_1_unit_test_rec lab6_1_rec/lab6_1_unit_test_rec.cpp lab6_1_rec/lab6_1_rec.cpp)
target_compile_definitions(lab6_1_unit_test_rec PRIVATE UNIT_TESTING)
target_link_libraries(lab6_1_unit_test_rec PRIVATE GTest::gtest GTest::gtest_main pthread)


# Додаємо тести для lab6_2
add_executable(lab6_2_unit_test lab6_2/lab6_2_unit_test.cpp lab6_2/lab6_2.cpp)
target_compile_definitions(lab6_2_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab6_2_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)



# # Додаємо тести для lab6_2_rec
# add_executable(lab6_2_unit_test_rec lab6_2_rec/lab6_2_unit_test_rec.cpp lab6_2_rec/lab6_2_rec.cpp)
# target_compile_definitions(lab6_2_unit_test_rec PRIVATE UNIT_TESTING)
# target_link_libraries(lab6_2_unit_test_rec PRIVATE GTest::gtest GTest::gtest_main pthread)


# Додаємо тести для lab6_3
add_executable(lab6_3_unit_test lab6_3/lab6_3_unit_test.cpp lab6_3/lab6_3.cpp)
target_compile_definitions(lab6_3_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab6_3_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)



# Додаємо тести для lab6_3_rec
add_executable(lab6_3_unit_test_rec lab6_3_rec/lab6_3_unit_test_rec.cpp lab6_3_rec/lab6_3_rec.cpp)
target_compile_definitions(lab6_3_unit_test_rec PRIVATE UNIT_TESTING)
target_link_libraries(lab6_3_unit_test_rec PRIVATE GTest::gtest GTest::gtest_main pthread)



# Додаємо тести для lab6_4
add_executable(lab6_4_unit_test lab6_4/lab6_4_unit_test.cpp lab6_4/lab6_4.cpp)
target_compile_definitions(lab6_4_unit_test PRIVATE UNIT_TESTING)
target_link_libraries(lab6_4_unit_test PRIVATE GTest::gtest GTest::gtest_main pthread)



# Додаємо тести для lab6_4_rec
add_executable(lab6_4_unit_test_rec lab6_4_rec/lab6_4_unit_test_rec.cpp lab6_4_rec/lab6_4_rec.cpp)
target_compile_definitions(lab6_4_unit_test_rec PRIVATE UNIT_TESTING)
target_link_libraries(lab6_4_unit_test_rec PRIVATE GTest::gtest GTest::gtest_main pthread)

