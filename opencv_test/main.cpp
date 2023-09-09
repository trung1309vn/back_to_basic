#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <windows.h>

int main()
{
    // Read image
    // std::string input_file = "../../test/test_img.jpg";
    // cv::Mat img = cv::imread(input_file, cv::IMREAD_UNCHANGED);
    // if (!img.empty())
    // {
    //     cv::imshow("Test Image", img);
    //     cv::waitKey(0);
    // }

    // Video capture
    cv::VideoCapture cap(0, cv::CAP_DSHOW);
    if (!cap.isOpened())
    {
        std::cerr << "Cannot read video. Try moving video file to sample directory." << std::endl;
        cap.release();
        system("pause");
        return -1;
    }

    cv::Mat frame;
    while (cap.read(frame))
    {
        cv::flip(frame, frame, 1);
        cv::imshow("Test Webcam", frame);
        int key = cv::waitKey(34); // About 30fps
        if (key == (int)'q')
            break;
    }

    std::cout << "STOP capturing";
    cv::destroyAllWindows();
    return 0;
}
