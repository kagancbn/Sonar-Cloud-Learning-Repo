#include <iostream>
#include <memory>  // Include for std::unique_ptr
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./image_grayscale <image_path>" << std::endl;
        return -1;
    }

    cv::Mat image = cv::imread(argv[1]);
    if (image.empty()) {
        std::cerr << "Error: Could not open or find the image!" << std::endl;
        return -1;
    }

    // Use auto to deduce the type
    auto grayImagePtr = std::make_unique<cv::Mat>();
    cv::cvtColor(image, *grayImagePtr, cv::COLOR_BGR2GRAY);

    int width = grayImagePtr->cols;
    int height = grayImagePtr->rows;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            grayImagePtr->at<uchar>(i, j) = grayImagePtr->at<uchar>(i, j) * 2; // Magic number (2)
        }
    }

    // Saving the grayscale image
    cv::imwrite("grayscale_image.jpg", *grayImagePtr);

    std::cout << "Image converted to grayscale and saved." << std::endl;

    return 0;
}
