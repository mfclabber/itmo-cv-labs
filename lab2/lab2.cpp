
#include <opencv2/opencv.hpp> 
#include <iostream>
#include <string>

int main(int argc, char** argv) 
{ 
    // было решено оставить так, потому что библиотики требовательны к версиям компилятора и ОС
    std::string path = "/home/mfclabber/itmo-cv-labs"; 

    cv::Mat T, image, image_shift, 
            image_reflect, image_scale, image_resize;
    image = cv::imread(path + "/lab2/image.png", 1); 


    // Task 1
    // T = (cv::Mat_<double>(2, 3) << 
    //     1, 0, 150, 
    //     0, 1, 100); 
    // cv::warpAffine(image, image_shift, T, cv::Size(image.cols, image.rows));

    // cv::imwrite(path + "/lab2/outputs/image_shift.png", image_shift);

    // cv::imshow("Shift image", image_shift); 


    // Task 2
    // T = (cv::Mat_<double>(2, 3) << 
    //     1, 0, 0, 
    //     0, -1, image.rows-1); 

    // cv::warpAffine(image, image_reflect, T, cv::Size(image.cols, image.rows));

    // cv::imwrite(path + "/lab2/outputs/image_reflect.png", image_reflect);

    // cv::imshow("Shift image", image_reflect); 
    // cv::waitKey(0); 


    // Task 3
    // cv::flip(image, image_reflect, 1);

    // cv::imwrite(path + "/lab2/outputs/image_flip.png", image_reflect);

    // cv::imshow("Shift image", image_reflect); 
    // cv::waitKey(0); 


    // Task 4
    // T = (cv::Mat_<double>(2, 3) << 
    //     0.5, 0, 0, 
    //     0, 0.5, 0); 

    // cv::warpAffine(image, image_scale, T, cv::Size(int(0.5 * image.cols), int(0.5 * image.rows))); 

    // cv::imwrite(path + "/lab2/outputs/image_scale.png", image_scale);

    // cv::imshow("Shift image", image_scale); 
    // cv::waitKey(0); 


    // Task 5
    // cv::resize(image, image_resize, cv::Size(int(0.5 * image.cols), int(0.5 * image.rows)));
    
    // cv::imwrite(path + "/lab2/outputs/image_resize.png", image_resize);

    // cv::imshow("Shift image", image_resize); 
    // cv::waitKey(0); 
}

