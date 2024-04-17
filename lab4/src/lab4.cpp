#include <vector>
#include <string>
#include <iostream>
#include <opencv2/opencv.hpp> 


void entropy(cv::Mat &I, cv::Mat &Iout, cv::Mat &el){
    if(I.channels() != 1 || I.type() != CV_8U)
        return;
    
    cv::Mat Icopy;
    cv::copyMakeBorder(I, Icopy, int((el.rows - 1) / 2), int(el.rows / 2),
                        int((el.cols - 1) / 2), int(el.cols / 2), cv::BORDER_REPLICATE);

    Iout = cv::Mat::zeros(I.rows, I.cols, CV_32F);

    double hist[256];
    for(int i = 0; i < 256; ++i)
        hist[i] = 0;

    int count = 0;
    for(int i = 0; i < el.rows; ++i)
        for(int j = 0; j < el.cols; ++j)
            if(el.at<uchar>(i, j))
                count++;
    
    for(int y = 0; y < I.rows; y++)
        for(int x = 0; x < I.cols; x++){
            for(int i = 0; i < el.rows; i++)
                for(int j = 0; j < el.cols; j++)
                    if(el.at<uchar>(i, j))
                        hist[Icopy.at<uchar>(y + i, x + j)] += 1;
            double val = 0;
            for(int i = 0; i < 256; i++)
                if(hist[i] > 0){
                    val -= hist[i] / count * log2(hist[i] / count);
                    hist[i] = 0;
                }    
                Iout.at<float>(y, x) = float(val);
        }
}



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


void imfillholes(cv::Mat &I, cv::Mat& Iout )
{
    // Check input image data
    if (I.channels() != 1 || I.type() != CV_8U)
        return;
    cv::Mat mask = I.clone();
    // Fill mask from all horizontal borders
    for(int i = 0; i < I.cols; i++)
    {
        if(mask.at<uchar>(0, i) == 0)
            cv::floodFill(mask, cv::Point(i, 0), cv::Scalar(255), NULL,
                          cv::Scalar(10), cv::Scalar(10));
        if(mask.at<uchar>(I.rows - 1, i) == 0)
            cv::floodFill(mask, cv::Point(i, I.rows - 1),
            cv::Scalar(255), NULL,
            cv::Scalar(10), cv::Scalar(10));
    }
    // Fill mask from all vertical borders
    for(int i = 0; i < I.rows; i++)
    {
        if(mask.at<uchar>(i, 0) == 0)
            cv::floodFill(mask, cv::Point(0, i),
            cv::Scalar(255), NULL, cv::Scalar(10),
            cv::Scalar(10));
        if(mask.at<uchar>(i, I.cols - 1) == 0)
            cv::floodFill(mask, cv::Point(I.cols - 1, i ), cv::Scalar(255),
                      NULL, cv::Scalar(10), cv::Scalar(10));
    }
    // Use the mask to create an image
    Iout = I.clone();
    Iout.setTo(cv::Scalar(255), mask == 0);
}




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
    
    image = cv::imread(path + "/source/face.png", 0);
    image_new = image.clone();

    for(int i = 0; i < image_new.rows; ++i){
        for(int j = 0; j < image_new.cols; ++j){
            if(image_new.at<uchar>(i, j) <= 110)
                image_new.at<uchar>(i, j) = 50 - 12 * image_new.at<uchar>(i, j) / 88;   
            
            else if(image_new.at<uchar>(i, j) <= 150)
                image_new.at<uchar>(i, j) = 0.0002 * cv::pow(image_new.at<uchar>(i, j) - 88, 2); 
            
            else if(image_new.at<uchar>(i, j) <= 255)
                image_new.at<uchar>(i, j) = 0.07 * (image_new.at<uchar>(i, j) - 138) / 117; 
        }
    }

    cv::imwrite(path + "/outputs/image_veber_segmentation.png", image_new);
    cv::imshow("image", image_new);
    cv::waitKey();



    // Segmentation CIE Lab

    // image = cv::imread(path + "/source/road.png", 1);

    // cv::Mat image_CIE_Lab, ab;
    // cv::cvtColor(image, image_CIE_Lab, cv::COLOR_BGR2Lab);

    // std::vector<cv::Mat> image_Lab_canals;
    // cv::split(image_CIE_Lab, image_Lab_canals);

    // cv::merge(&(image_Lab_canals[1]), 2, ab);
    // ab = ab.reshape(0, 1);
    // ab.convertTo(ab, CV_32F);

    // int k = 3;
    // cv::Mat labels;
    // cv::kmeans(ab, k, labels, cv::TermCriteria(cv::TermCriteria::EPS +
    //                             cv::TermCriteria::COUNT, 10, 1.0), 10, 
    //                             cv::KMEANS_RANDOM_CENTERS);

    // labels = labels.reshape(0, image_Lab_canals[0].rows);

    // std::vector<cv::Mat> segmentedFrames;
    // for(int i = 0; i < k; ++i){
    //     cv::Mat image_tmp = cv::Mat::zeros(image.rows, image.cols, image.type());
    //     image.copyTo(image_tmp, labels == i);
    //     segmentedFrames.push_back(image_tmp);
    // }

    // cv::imwrite(path + "/outputs/image_CIELab_segmentation.png", segmentedFrames[2]);
    
    // cv::threshold(segmentedFrames[2], segmentedFrames[2], 90, 115, cv::THRESH_BINARY);
    // cv::imwrite(path + "/outputs/image_road_segmentation.png", segmentedFrames[2]);
    
    // cv::imshow("image", segmentedFrames[2]);
    // cv::waitKey();

    // Texture segmentation


    // image = cv::imread(path + "/source/sea.png", 0);

    // cv::Mat E, Eim;
    // cv::Mat el = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(9, 9));
    // entropy(image, E, el);

    // double Emin, Emax;
    // cv::minMaxLoc(E, &Emin, &Emax);
    // Eim = (E - Emin) / (Emax - Emin);
    // Eim.convertTo(Eim, CV_8U, 255);
    // cv::Mat BW1;
    // cv::threshold(Eim, BW1, 0, 255, cv::THRESH_OTSU);

    // cv::imwrite(path + "/outputs/image_entropy_segmentation.png", BW1);
    
    // cv::Mat BWao, closeBWao, Mask1;
    // bwareaopen(BW1, BWao, 50000);
    // cv::imwrite(path + "/outputs/image_bwareoopen_segmentation.png", BWao);

    // cv::Mat nhood = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(9, 9));
    // cv::morphologyEx(BWao, closeBWao, cv::MORPH_CLOSE, nhood);

    // imfillholes(closeBWao, Mask1);
    // cv::imwrite(path + "/outputs/image_imclose_segmentation.png", Mask1);

    // std::vector<std::vector<cv::Point>> contours;
    // cv::findContours(Mask1, contours, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
    // cv::Mat boundary = cv::Mat::zeros(Mask1.rows, Mask1.cols, CV_8UC1);
    
    // cv::drawContours(boundary, contours, -11, 255, 1);
    // cv::imwrite(path + "/outputs/image_countours_segmentation.png", boundary);

    // cv::Mat segmentResults = image.clone();
    // segmentResults.setTo(cv::Scalar(255), boundary != 0);
    // cv::imwrite(path + "/outputs/image_segmentResults_segmentation.png", segmentResults);

    // cv::Mat I2 = image.clone();
    // I2.setTo(0, Mask1 != 0);

    // cv::imwrite(path + "/outputs/I.png",I2);
    // cv::imshow("image", I2);

    // cv::Mat E2, Eim2;

    // entropy(I2, E2, el);;

    // double Emin2, Emax2;
    // cv::minMaxLoc(E2, &Emin2, &Emax2);

    // Eim2 = (E2 - Emin2) /  (Emax2 -  Emin2);
    // Eim2.convertTo(Eim2, CV_8U, 255);
    
    // cv::Mat BW2;

    // cv::threshold(Eim2, BW2, 0, 255, cv::THRESH_OTSU);
    // cv::imwrite(path + "/outputs/image_entropy2_segmentation.png", BW2);

    // cv::Mat BW2ao, closeBW2ao, Mask2;
    // bwareaopen(BW2, BW2ao, 50000);
    // cv::imwrite(path + "/outputs/image_bwareoopen2_segmentation.png", BW2ao);

    // cv::morphologyEx(BW2ao, closeBW2ao, cv::MORPH_CLOSE, nhood);
    // imfillholes(closeBW2ao, Mask2);
    // cv::imwrite(path + "/outputs/image_imclose2_segmentation.png", Mask2);

    // std::vector<std::vector<cv::Point>> contours2;
    // cv::findContours(Mask2, contours2, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);
    // cv::Mat boundary2 = cv::Mat::zeros(Mask2.rows, Mask2.cols, CV_8UC1);
    // cv::drawContours(boundary2, contours2, -1, 255, 1);
    // cv::imwrite(path + "/outputs/image_countours2_segmentation.png", boundary2);

    // cv::Mat segmentResults2 = I2.clone();
    // segmentResults2.setTo(255, boundary2 != 0);
    // cv::imwrite(path + "/outputs/image_segmentResults2_segmentation.png", segmentResults2);

    // I2 = image.clone();
    // I2.setTo(0, Mask2 != 0);

    // cv::imwrite(path + "/outputs/I2.png",I2);
    // cv::imshow("image", I2);

    // cv::waitKey();
}