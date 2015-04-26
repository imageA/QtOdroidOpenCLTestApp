#ifndef GLOBAL_H
#define GLOBAL_H

#define OPENCL_CL_OFF_H 0
#define OPENCL_CL_ON_H 1

#define QT_EXAMPLE_SQUARE_H 0
#define QT_EXAMPLE_HOG_H 1
#define QT_EXAMPLE_PERFORMANCE_H 0

#define LIBRARY_BlendLinear     0
#define LIBRARY_Sobel           1
#define LIBRARY_GaussianBlur    2
#define LIBRARY_Multiply        3
#define LIBRARY_CvtColor        4

#include <QMainWindow>
#include <opencv2/core/core.hpp>

//QImage Mat2QImage(cv::Mat const& src);
QImage Mat2QImage(const cv::Mat3b &src);

#endif // GLOBAL_H
