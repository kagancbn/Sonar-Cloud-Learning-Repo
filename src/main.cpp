#include <iostream>
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

    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    int width = grayImage.cols;
    int height = grayImage.rows;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            grayImage.at<uchar>(i, j) = grayImage.at<uchar>(i, j);
        }
    }

    // Saving the grayscale image
    cv::imwrite("grayscale_image.jpg", grayImage);

    std::cout << "Image converted to grayscale and saved." << std::endl;
    return 0;
}
