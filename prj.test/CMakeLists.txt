add_executable(test_complex test_complex.cpp)
target_link_libraries(test_complex complex)

add_executable(test_rational test_rational.cpp)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_rational)

find_package(doctest REQUIRED)
add_executable(test_doctest test_doctest.cpp)
target_link_libraries(test_doctest doctest::doctest)


