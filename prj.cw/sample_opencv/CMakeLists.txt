find_package(OpenCV CONFIG REQUIRED)

add_executable(opencv_001 opencv_001.cpp)
target_link_libraries(opencv_001 PRIVATE opencv_core opencv_imgproc opencv_highgui)