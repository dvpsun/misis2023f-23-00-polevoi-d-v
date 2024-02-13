
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


int main() {
  cv::Mat1b m(200, 200, 127);
  cv::imwrite("opencv_sample001.png", m);
  cv::imshow("example", m);
  cv::waitKey(0);
}