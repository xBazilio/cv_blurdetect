/**
 * Detect if an image is blurry
 */

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>

using namespace cv;

int main(int argc, char *argv[])
{
    Mat image, finalImage;

    image = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    if (image.empty()) {
        std::cout << "img read fail" << std::endl;
        return 1;
    }

    Laplacian(image, finalImage, CV_8U);

    int rows = finalImage.rows;
    int cols = finalImage.cols;
    char *pixels = reinterpret_cast<char *>(finalImage.data);
    int maxLap = -16777216; //just too small number
    for (int i = 0; i < (rows*cols); i++) {
        if (pixels[i] > maxLap)
            maxLap = pixels[i];
    }

    //You can fine tune maxLap by seeing its value
    //in my case 20 is optimal
    //std::cout << argv[1] << " " << maxLap << "\n";

    if (maxLap < 20) {
        //blurry
        return 0;
    } else {
        //sharp
        return 1;
    }
}
