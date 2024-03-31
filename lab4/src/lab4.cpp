#include <vector>
#include <string>
#include <iostream>
#include <opencv2/opencv.hpp> 


int main(int argc, char** argv) 
{ 
    // было решено оставить так, потому что библиотеки требовательны к версиям компилятора и ОС
    std::string path = "/home/mfclabber/itmo-cv-labs/lab4"; 

    cv::Mat image, image_new;
    image = cv::imread(path + "/source/yandex_delivery_robot.png", 0);



    // Binarization
    // cv::threshold(image, image_new, 127, 255, cv::THRESH_BINARY);

    // cv::imwrite(path + "/outputs/image_binarization.png", image_new);
    // cv::imshow("image", image_new);
    // cv::waitKey();



    // Double threshold binarization
    // cv::threshold(image, image_new, 127, 255, cv::THRESH_TOZERO);
    // cv::threshold(image_new, image_new, 200, 255, cv::THRESH_BINARY);
    
    // cv::imwrite(path + "/outputs/image_double_binarization.png", image_new);
    // cv::imshow("image", image_new);
    // cv::waitKey();



    // Otsu binarization
    // cv::threshold(image, image_new, 0, 255, cv::THRESH_OTSU);
    
    // cv::imwrite(path + "/outputs/image_otsu_binarization.png", image_new);
    // cv::imshow("image", image_new);
    // cv::waitKey();



    // Adaprive binarization
    // cv::adaptiveThreshold(image, image_new, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 11, 2);
    
    // cv::imwrite(path + "/outputs/image_adaptive_binarization.png", image_new);
    // cv::imshow("image", image_new);
    // cv::waitKey();



    // Segmentation
    
}