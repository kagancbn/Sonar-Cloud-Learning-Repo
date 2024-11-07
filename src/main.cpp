#include <iostream>
#include <memory>
#include <opencv2/opencv.hpp>
#include <cstdint>

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

    auto grayImagePtr = std::make_unique<cv::Mat>();
    cv::cvtColor(image, *grayImagePtr, cv::COLOR_BGR2GRAY);

    int32_t width = grayImagePtr->cols;
    int32_t height = grayImagePtr->rows;
    for (int32_t i = 0; i < height; ++i) {
        for (int32_t j = 0; j < width; ++j) {
            grayImagePtr->at<uchar>(i, j) = grayImagePtr->at<uchar>(i, j) * 2;  // Magic number (2)
        }
    }

    // Attempt to save the grayscale image and check if it was successful
    bool isSaved = cv::imwrite("grayscale_image.jpg", *grayImagePtr);
    if (!isSaved) {
        std::cerr << "Error: Failed to save the grayscale image!" << std::endl;
        return -1;
    }

    std::cout << "Image converted to grayscale and saved successfully." << std::endl;

    return 0;
}
