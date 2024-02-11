add_library(stackarr stackarr.cpp stackarr.hpp)
target_link_libraries(stackarr complex)
set_property(TARGET stackarr PROPERTY CXX_STANDARD 20)
target_include_directories(stackarr PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS stackarr)