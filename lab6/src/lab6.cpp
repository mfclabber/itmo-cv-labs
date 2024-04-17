#include <vector>
#include <string>
#include <iostream>
#include <opencv2/opencv.hpp> 



int main(int argc, char** argv) 
{ 
    std::string path = "/home/mfclabber/itmo-cv-labs/lab6"; 



    // TASK 1


    // cv::Mat image;
    // image = cv::imread(path + "/source/1.png", 0);

    // cv::Mat labelImage(image.size(), CV_32S);

    // cv::Mat new_image = cv::Mat::zeros(image.rows, image.cols, image.type());

    // int morph_size = 2; 
    // cv::Mat kernel = getStructuringElement(cv::MORPH_RECT, 
    //                                        cv::Size(1 * morph_size + 1, 
    //                                                 1 * morph_size + 1), 
    //                                        cv::Point(morph_size, 
    //                                                  morph_size)); 

    // cv::erode(image, new_image, kernel, cv::Point(-1, -1), 1); //, cv::BORDER_CONSTANT, cv::morphologyDefaultBorderValue());

    // int n_labels = connectedComponents(new_image, labelImage, 4);
    // std::unordered_map<int, int> labels_map;

    // for(int i = 0; i < image.rows-1; ++i){
    //     for(int j = 0; j < image.cols-1; ++j){
    //         ++labels_map[labelImage.at<int>(i, j)];
    //     }
    // }

    // labels_map.erase(0);

    // int k = (*std::max_element(labels_map.begin(), labels_map.end(), [](auto a, auto b){return a.second < b.second;})).first;

    // for(int i = 0; i < image.rows-1; ++i){
    //     for(int j = 0; j < image.cols-1; ++j){
    //         if(labelImage.at<int>(i, j) == k)
    //             new_image.at<uchar>(i, j) = new_image.at<uchar>(i, j);
    //         else
    //             new_image.at<uchar>(i, j) = 0;
    //     }
    // }

    // cv::morphologyEx(new_image, new_image, 
    //                  cv::MORPH_DILATE, kernel, 
    //                  cv::Point(-1, -1), 2); 

    // cv::morphologyEx(new_image, new_image, 
    //                  cv::MORPH_GRADIENT, kernel, 
    //                  cv::Point(-1, -1), 2); 

    // cv::imwrite(path + "/outputs/1_gradient.png", new_image);
    // cv::imshow("image", new_image);
    // cv::waitKey();



    // TASK 2


    
}