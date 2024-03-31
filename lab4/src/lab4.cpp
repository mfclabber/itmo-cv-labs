#include <vector>
#include <string>
#include <iostream>
#include <opencv2/opencv.hpp> 


int main(int argc, char** argv) 
{ 
    // было решено оставить так, потому что библиотеки требовательны к версиям компилятора и ОС
    std::string path = "/home/mfclabber/itmo-cv-labs/lab4"; 

    cv::Mat image, image_new;
    image = cv::imread(path + "/source/yandex_delivery_robot.png", 0);image = cv::imread(path + "/source/yandex_delivery_robot.png", 0);



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



    // Segmentation Veber
    
    // image = cv::imread(path + "/source/face.png", 0);
    // image_new = image.clone();

    // for(int i = 0; i < image_new.rows; ++i){
    //     for(int j = 0; j < image_new.cols; ++j){
    //         if(image_new.at<uchar>(i, j) <= 88)
    //             image_new.at<uchar>(i, j) = 20 - 12 * image_new.at<uchar>(i, j) / 88;   
            
    //         else if(image_new.at<uchar>(i, j) <= 138)
    //             image_new.at<uchar>(i, j) = 0.002 * cv::pow(image_new.at<uchar>(i, j) - 88, 2); 
            
    //         else if(image_new.at<uchar>(i, j) <= 255)
    //             image_new.at<uchar>(i, j) = 7 * (image_new.at<uchar>(i, j) - 138) / 117; 
    //     }
    // }

    // cv::imwrite(path + "/outputs/image_veber_segmentation.png", image_new);
    // cv::imshow("image", image_new);
    // cv::waitKey();



    // Segmentation CIE Lab

    image = cv::imread(path + "/source/road.png", 1);

    cv::Mat image_CIE_Lab, ab;
    cv::cvtColor(image, image_CIE_Lab, cv::COLOR_BGR2Lab);

    std::vector<cv::Mat> image_Lab_canals;
    cv::split(image_CIE_Lab, image_Lab_canals);

    cv::merge(&(image_Lab_canals[1]), 2, ab);
    ab = ab.reshape(0, 1);
    ab.convertTo(ab, CV_32F);

    int k = 3;
    cv::Mat labels;
    cv::kmeans(ab, k, labels, cv::TermCriteria(cv::TermCriteria::EPS +
                                cv::TermCriteria::COUNT, 10, 1.0), 10, 
                                cv::KMEANS_RANDOM_CENTERS);

    labels = labels.reshape(0, image_Lab_canals[0].rows);

    std::vector<cv::Mat> segmentedFrames;
    for(int i = 0; i < k; ++i){
        cv::Mat image_tmp = cv::Mat::zeros(image.rows, image.cols, image.type());
        image.copyTo(image_tmp, labels == i);
        segmentedFrames.push_back(image_tmp);
    }

    cv::imwrite(path + "/outputs/image_CIELab_segmentation.png", segmentedFrames[2]);
    
    cv::threshold(segmentedFrames[2], segmentedFrames[2], 90, 115, cv::THRESH_BINARY);
    cv::imwrite(path + "/outputs/image_road_segmentation.png", segmentedFrames[2]);
    
    cv::imshow("image", segmentedFrames[2]);
    cv::waitKey();
}