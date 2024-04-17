#include <vector>
#include <string>
#include <iostream>
#include <opencv2/opencv.hpp> 



void bwareaopen(const cv::Mat& A, cv::Mat& C, int dim , int conn = 8){
    if (A.channels() != 1 || A.type () != CV_8U)
        return;
    // Find all connected components
    cv::Mat labels, stats, centers;
    int num = cv::connectedComponentsWithStats(A, labels, stats, centers, conn);
    // Clone image
    C = A.clone();
    // Check size of all connected components
    std::vector<int> td ;
    for(int i = 0; i < num; i++)
        if(stats.at<int>(i, cv::CC_STAT_AREA) < dim)
            td.push_back(i);
    // Remove small areas
    if(td.size() > 0)
        if(A.type() == CV_8U)
        {
            for (int i = 0; i < C.rows ; i++)
                for (int j = 0; j < C.cols; j++)
                    for (int k = 0; k < td.size(); k++)
                        if(labels.at<int>(i, j) == td[k])
                        {
                            C.at<uchar>(i, j) = 0;
                            continue;
                        }
        }
    else
    {
        for (int i = 0; i < C.rows; i++)
            for (int j = 0; j < C.cols; j++)
                for (int k = 0; k < td.size(); k++)
                    if (labels.at<int >(i, j) == td[k])
                    {
                        C.at<float>(i, j ) = 0;
                        continue;
                    }
    }
}


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


    // cv::Mat image, new_image, BW2;
    // image = cv::imread(path + "/source/3.png", 0);

    // cv::threshold(image, new_image, 160, 255, cv::THRESH_BINARY_INV);

    // cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));

    // cv::morphologyEx(new_image, BW2, cv::MORPH_ERODE, kernel, cv::Point(-1, -1), 14, cv::BORDER_CONSTANT, cv::Scalar(0));

    // cv::Mat D, S, C;
    // cv::Mat T = cv::Mat::zeros(new_image.rows, new_image.cols, new_image.type());

    // int pix_num = new_image.rows * new_image.cols;

    // while(cv::countNonZero(BW2) < pix_num){
    //     cv::morphologyEx(BW2, D, cv::MORPH_DILATE, kernel, cv::Point(-1, -1), 1, cv::BORDER_CONSTANT, cv::Scalar(0));
    //     cv::morphologyEx(D, C, cv::MORPH_CLOSE, kernel, cv::Point(-1, -1), 1, cv::BORDER_CONSTANT, cv::Scalar(0));
    //     S = C - D;
    //     cv::bitwise_or(S, T, T);
    //     BW2 = D;
    // }

    // cv::morphologyEx(T, T, cv::MORPH_CLOSE, kernel, cv::Point(-1, -1), 1, cv::BORDER_CONSTANT, cv::Scalar(255));
    // cv::bitwise_and(T,  new_image, new_image);
    // std::cout << 'a';
    // cv::imshow("image", new_image);
    // cv::waitKey();



    // TASK 3


    cv::Mat image, image_gray, image_bw;
    image = cv::imread(path + "/source/2.png", 1);

    cv::cvtColor(image, image_gray, cv::COLOR_BGR2GRAY);
    cv::threshold(image_gray, image_bw, 0, 250, cv::THRESH_BINARY + cv::THRESH_OTSU);

    bwareaopen(image_bw, image_bw, 20, 8);
    cv::Mat B = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));

    cv::morphologyEx(image_bw, image_bw, cv::MORPH_CLOSE, B);


    cv::Mat image_fg;
    double image_fg_min, image_fg_max;
    cv::distanceTransform(image_bw, image_fg, cv::DIST_L2, 5);

    cv::minMaxLoc(image_fg, &image_fg_min, &image_fg_max);
    cv::threshold(image_fg, image_fg, 0.7 * image_fg_max, 255, 0);
    image_fg.convertTo(image_fg, CV_8U, 255.0 / image_fg_max);

    cv::imshow("image", image_fg);
    cv::waitKey();
    cv::Mat markers;

    int num = cv::connectedComponents(image_fg, markers);

    cv::Mat image_bg = cv::Mat::zeros(image_bw.rows, image_bw.cols, image_bw.type());

    cv::Mat markers_bg = markers.clone();
    cv::watershed(image, markers_bg);

    image_bg.setTo(cv::Scalar(255), markers_bg == -1);

    cv::Mat image_unk;

    cv::bitwise_not(image_bg, image_unk);
    cv::subtract(image_unk, image_fg, image_unk);

    markers += 1;
    markers.setTo(cv::Scalar(0), image_unk == 255);

    cv::watershed(image, markers);

    cv::Mat markers_jet;
    markers.convertTo(markers_jet, CV_8U, 255.0 / (num + 1));

    cv::applyColorMap(markers_jet, markers_jet, cv::COLORMAP_JET);

    image.setTo(cv::Scalar(255, 0, 0), markers == -1);
    cv::imwrite(path + "/outputs/3_filtr_reverse.png", image_fg);
    cv::imshow("image", image_bg);
    cv::waitKey();
}