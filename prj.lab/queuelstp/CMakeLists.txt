add_library(queuelstp queuelstp.cpp queuelstp.hpp)
set_property(TARGET queuelstp PROPERTY CXX_STANDARD 20)
target_include_directories(queuelstp PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)