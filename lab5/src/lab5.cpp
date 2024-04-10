#include <vector>
#include <string>
#include <iostream>
#include <opencv2/opencv.hpp> 

struct func{
    func(std::vector<cv::Vec4i>& lines, cv::Mat& image): lines{lines}, image{image} {};
    std::vector<cv::Vec4i> lines;
    cv::Mat image;
};

func canny_hough_tranform(cv::Mat& image){

    cv::Mat image_new, image_out = image.clone();
    cv::Canny(image, image_new, 50, 200);
    std::vector<cv::Vec4i> linesP;

    HoughLinesP(image_new, linesP, 1, CV_PI / 180, 50, 50, 15);

    for (int i = 0; i < linesP.size(); ++i){
        cv::Vec4i I = linesP[i];
        cv::line(image_out, cv::Point(I[0], I[1]),
                            cv::Point(I[2], I[3]),
                            cv::Scalar(0, 255, 0), 
                                  1, cv::LINE_AA);

        cv::circle(image_out, cv::Point(I[0], I[1]), 1,
                                       (127, 0, 60), 5, 
                                          cv::LINE_AA);

        cv::circle(image_out, cv::Point(I[2], I[3]), 1, 
                                        (0, 0, 255), 5, 
                                          cv::LINE_AA);
    }

    return func(linesP, image_out);
}


int main(int argc, char** argv) 
{ 
    std::string path = "/home/mfclabber/itmo-cv-labs/lab5"; 

    cv::Mat image, image_new;
    image = cv::imread(path + "/source/3.png", 1);
    // cv::Canny(image, image_new, 50, 200);


    // Image 1. Grayscale

    // cv::Mat image_out = image.clone();

    // std::vector<cv::Vec2f> lines;
    // cv::HoughLines(image_new, lines, 1, CV_PI / 180, 150);

    // for( size_t i = 0; i < lines.size(); i++ )
    // {
    //     float rho = lines[i][0], theta = lines[i][1];
    //     cv::Point pt1, pt2;
    //     double a = cos(theta), b = sin(theta);
    //     double x0 = a*rho, y0 = b*rho;
    //     pt1.x = cvRound(x0 + 1000*(-b));
    //     pt1.y = cvRound(y0 + 1000*(a));
    //     pt2.x = cvRound(x0 - 1000*(-b));
    //     pt2.y = cvRound(y0 - 1000*(a));
    //     cv::line(image_out, pt1, pt2, cv::Scalar(0,0,255), 1, cv::LINE_AA);
    // }


    // std::vector<cv::Vec4i> linesP;
    // HoughLinesP(image_new, linesP, 1, CV_PI / 180, 50, 50, 15);

    // for (int i = 0; i < linesP.size(); ++i){
    //     cv::Vec4i I = linesP[i];
    //     cv::line(image_out, cv::Point(I[0], I[1]),
    //                         cv::Point(I[2], I[3]),
    //                         cv::Scalar(0, 255, 0), 
    //                               1, cv::LINE_AA);

    //     cv::circle(image_out, cv::Point(I[0], I[1]), 1,
    //                                    (127, 0, 60), 5, 
    //                                       cv::LINE_AA);

    //     cv::circle(image_out, cv::Point(I[2], I[3]), 1, 
    //                                     (0, 0, 255), 5, 
    //                                       cv::LINE_AA);
    // }

    func output = canny_hough_tranform(image);


    // cv::imwrite(path + "/outputs/image_binarization.png", image_new);
    cv::imshow("image", output.image);
    cv::waitKey();
}