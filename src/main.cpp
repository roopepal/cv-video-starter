#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char* argv[])
{    
    std::string file_path(DATA_DIR);
    file_path += argv[1];

    VideoCapture cap(file_path);

    if(!cap.isOpened()) {
        std::cout << "Error opening file " << file_path << std::endl;
        return -1;
    }

    Mat frame, previous;
    cap >> frame;

    // scaling factor
    float resize_by = 0.5;

    while(1) {

        if(frame.empty()) {
            break;
        }

        // grayscale
        cvtColor(frame, frame, COLOR_BGR2GRAY);

        // downsample
        resize(frame, frame, Size(frame.cols * resize_by, frame.rows * resize_by), 0, 0, INTER_LINEAR);

        imshow("Window", frame);

        char c=(char) cv::waitKey(30);
        if(c == 27) {
            break;
        }

        cap >> frame;
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
