#include <vector>
#include <string>
#include <iostream>
#include <opencv2/opencv.hpp> 



int main(int argc, char** argv) 
{ 
    // было решено оставить так, потому что библиотеки требовательны к версиям компилятора и ОС
    std::string path = "/home/mfclabber/itmo-cv-labs"; 

    cv::Mat T, T1, T2, T3, image, image_shift, image_reflect, 
            image_scale, image_resize, image_rotate, image_rotate_point,
            image_rotate_point_func, image_Affine, image_bevel, image_clone, 
            image_piece_r, image_projective, image_polynomial;
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


    // Task 6
    // double phi = 25 * M_PI / 180;
    // T = (cv::Mat_<double>(2, 3) << 
    //     cos(phi), -sin(phi), 0, 
    //     sin(phi), cos(phi), 0); 

    // cv::warpAffine(image, image_rotate, T, cv::Size(image.cols, image.rows)); 

    // cv::imwrite(path + "/lab2/outputs/image_rotate.png", image_rotate);

    // cv::imshow("Shift image", image_rotate); 
    // cv::waitKey(0); 


    // Task 7
    // double phi = 25 * M_PI / 180;

    // T1 = (cv::Mat_<double>(3, 3) << 
    //     1, 0, -(image.cols-1) / 2.0, 
    //     0, 1, -(image.rows-1) / 2.0,
    //     0, 0, 1); 

    // T2 = (cv::Mat_<double>(3, 3) << 
    //     cos(phi), -sin(phi), 0, 
    //     sin(phi), cos(phi), 0,
    //     0, 0, 1);  

    // T3 = (cv::Mat_<double>(3, 3) << 
    //     1, 0, (image.cols-1) / 2.0, 
    //     0, 1, (image.rows-1) / 2.0,
    //     0, 0, 1);   
    
    // T = cv::Mat(T3 * T2 * T1, cv::Rect(0, 0, 3, 2));

    // cv::warpAffine(image, image_rotate_point, T, cv::Size(image.cols, image.rows)); 

    // cv::imwrite(path + "/lab2/outputs/image_rotate_point.png", image_rotate_point);

    // cv::imshow("Shift image", image_rotate_point); 
    // cv::waitKey(0); 


    // Task 8
    // double phi = 25;
    // T = cv::getRotationMatrix2D(cv::Point2d(((image.cols-1) / 2.0), (image.rows-1) / 2.0), -phi, 1);
    // cv::warpAffine(image, image_rotate_point_func, T, cv::Size(image.cols, image.rows)); 

    // cv::imwrite(path + "/lab2/outputs/image_rotate_point_func.png", image_rotate_point_func);

    // cv::imshow("Shift image", image_rotate_point_func); 
    // cv::waitKey(0); 


    //Task 9
    // std::vector<cv::Point2f> pts_src = {{50, 300}, 
    //                                     {150, 200}, 
    //                                     {50, 50}};
    // std::vector<cv::Point2f> pts_dst = {{50, 310}, 
    //                                     {160, 200}, 
    //                                     {50, 60}};

    // T = cv::getAffineTransform(pts_src, pts_dst);

    // cv::warpAffine(image, image_Affine, T, cv::Size(image.cols, image.rows)); 

    // cv::imwrite(path + "/lab2/outputs/image_Affine.png", image_Affine);

    // cv::imshow("Shift image", image_Affine); 
    // cv::waitKey(0); 



    //Task 10
    // double s = 0.2;
    // T = (cv::Mat_<double>(2, 3) << 
    //                         1, s, 0, 
    //                         0, 1, 0); 

    // cv::warpAffine(image, image_bevel, T, cv::Size(image.cols, image.rows)); 

    // cv::imwrite(path + "/lab2/outputs/image_bevel.png", image_bevel);

    // cv::imshow("Shift image", image_bevel); 
    // cv::waitKey(0); 


    // Task 11
    // double stretch = 2;
    // T = (cv::Mat_<double>(2, 3) << 
    //                         stretch, 0, 0, 
    //                         0, 1, 0); 

    // image_clone = image.clone();
    // image_piece_r = image_clone(cv::Rect(image.cols / 2, 0, image.cols / 2, image.rows));

    // cv::warpAffine(image_piece_r, image_piece_r, T, cv::Size(image_piece_r.cols, image.rows)); 

    // cv::imwrite(path + "/lab2/outputs/image_piece_r.png", image_clone);

    // cv::imshow("Shift image", image_clone); 
    // cv::waitKey(0); 


    // Task 12
    // T = (cv::Mat_<double>(3, 3) << 
    //             0.7, 0.3, 0.00045, 
    //             0.2, 0.5, 0.0005,
    //             0, 0, 1); 

    // cv::warpPerspective(image, image_projective, T, cv::Size(image.cols, image.rows)); 

    // cv::imwrite(path + "/lab2/outputs/image_projective.png", image_projective);

    // cv::imshow("Shift image", image_projective); 
    // cv::waitKey(0); 


    // Task 13
    //  std::vector<cv::Point2f> pts_src = {{50, 300}, 
    //                                     {150, 200}, 
    //                                     {50, 50},
    //                                     {10, 10}};
    // std::vector<cv::Point2f> pts_dst = {{50, 300}, 
    //                                     {150, 199}, 
    //                                     {49, 50},
    //                                     {10, 10}};

    // T = cv::getPerspectiveTransform(pts_src, pts_dst);

    // cv::warpPerspective(image, image_projective, T, cv::Size(image.cols, image.rows)); 

    // cv::imwrite(path + "/lab2/outputs/image_projective_func.png", image_projective);

    // cv::imshow("Shift image", image_projective); 
    // cv::waitKey(0); 


    // Task 14
    // const double coeff[2][6] = {{0, 1, 0, 0.00001, 0.0001, 0},
    //                                      {0, 0, 1, 0, 0.0002, 0}};

    // if(image.depth() == CV_8U)
    //     image.convertTo(image_polynomial, CV_32F, 1.0 / 255);
    // else
    //     image_polynomial = image;

    // std::vector<cv::Mat> image_BGR;
    // cv::split(image_polynomial, image_BGR);
    // cv::Mat i_pol;
    // for(int k = 0; k < image_BGR.size(); k++){

    //     i_pol = cv::Mat::zeros(image_BGR[k].rows, 
    //                            image_BGR[k].cols, 
    //                            image_BGR[k].type());

    //     for(int x = 0; x < image_BGR[k].cols; ++x){
    //         for(int y = 0; y < image_BGR[k].rows; ++y){

    //             int x_new = static_cast<int>(round(coeff[0][0] + 
    //                 x * coeff[0][1] + y * coeff[0][2] + 
    //                 x * x * coeff[0][3] + y * x * coeff[0][4] + 
    //                 y * y * coeff[0][5]));

    //             int y_new = static_cast<int>(round(coeff[1][0] + 
    //                 x * coeff[1][1] + y * coeff[1][2] + 
    //                 x * x * coeff[1][3] + y * x * coeff[1][4] + 
    //                 y * y * coeff[1][5]));

    //             if(x_new >= 0 && x_new < image_BGR[k].cols
    //                && y_new >= 0 && y_new < image_BGR[k].rows)
    //                 i_pol.at<float>(y_new, x_new) = image_BGR[k].at<float>(y, x);
    //         }
    //     }
    //     image_BGR[k] = i_pol;
    // }
    // cv::merge(image_BGR, i_pol);

    // if(image.depth() == CV_8U)
    //     image_polynomial.convertTo(image_polynomial, CV_8UC3, 255);

    // cv::imwrite(path + "/lab2/outputs/image_polynomial.png", image_polynomial);
    // cv::imshow("B", image_polynomial);
    // cv::waitKey(0); 


    
}

