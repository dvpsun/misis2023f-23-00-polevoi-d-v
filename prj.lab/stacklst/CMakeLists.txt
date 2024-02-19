add_library(stacklst stacklst.cpp stacklst.hpp)
target_link_libraries(stacklst complex)
set_property(TARGET stacklst PROPERTY CXX_STANDARD 20)
target_include_directories(stacklst PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)