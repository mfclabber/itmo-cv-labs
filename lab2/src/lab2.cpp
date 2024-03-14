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
    image = cv::imread(path + "/lab2/source/image.png", 1); 


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


    // Task 15
    // cv::Mat u = cv::Mat::zeros(image.rows, image.cols, CV_32F);
    // cv::Mat v = cv::Mat::zeros(image.rows, image.cols, CV_32F);

    // for(int x = 0; x < image.cols; ++x){
    //     for(int y = 0; y < image.rows; ++y){
    //         u.at<float>(y, x) = float(x + 20 * sin(2 * M_PI * y / 90));
    //         v.at<float>(y, x) = float(y);
    //     }
    // }
    // cv::Mat image_sinusoid;
    // cv::remap(image, image_sinusoid, u, v, cv::INTER_LINEAR);

    // cv::imwrite(path + "/lab2/outputs/image_sinusoid.png", image_sinusoid);
    // cv::imshow("B", image_sinusoid);
    // cv::waitKey(0);


    // Task 16
    // cv::Mat x_i, y_i;
    // std::vector<float> t_x, t_y;

    // for(int i = 0; i < image.cols; ++i)
    //     t_x.push_back(float(i));
    
    // for(int i = 0; i < image.rows; ++i)
    //     t_y.push_back(float(i));
    
    // cv::repeat(cv::Mat(t_x).reshape(1, 1), image.rows, 1, x_i);
    // cv::repeat(cv::Mat(t_y).reshape(1, 1).t(), 1, image.cols, y_i);

    // double x_mid = x_i.cols / 2.0;
    // double y_mid = x_i.rows / 2.0;

    // x_i -= x_mid;
    // x_i /= x_mid;
    // y_i -= y_mid;
    // y_i /= y_mid;

    // cv::Mat r, theta;
    // cv::cartToPolar(x_i, y_i, r, theta);

    // double F3 = 0.1, F5 = 0.1;
    // cv::Mat r3, r5;

    // pow(r, 3, r3); pow(r, 5, r5);
    // r += r3 * F3; r += r5 * F5;

    // cv::Mat u, v;
    // cv::polarToCart(r, theta, u, v);
    // u *= x_mid;
    // u += x_mid;
    // v *= y_mid;
    // v *= y_mid;

    // cv::Mat image_barrel;
    // cv::remap(image, image_barrel, u, v, cv::INTER_LINEAR);

    // cv::imwrite(path + "/lab2/outputs/image_barrel.png", image_barrel);
    // cv::imshow("B", image_barrel);
    // cv::waitKey(0);


    // Tasl 17
    // cv::Mat x_i, y_i;
    // std::vector<float> t_x, t_y;

    // for(int i = 0; i < image.cols; ++i)
    //     t_x.push_back(float(i));
    
    // for(int i = 0; i < image.rows; ++i)
    //     t_y.push_back(float(i));
    
    // cv::repeat(cv::Mat(t_x).reshape(1, 1), image.rows, 1, x_i);
    // cv::repeat(cv::Mat(t_y).reshape(1, 1).t(), 1, image.cols, y_i);

    // double x_mid = x_i.cols / 2.0;
    // double y_mid = x_i.rows / 2.0;

    // x_i -= x_mid;
    // x_i /= x_mid;
    // y_i -= y_mid;
    // y_i /= y_mid;

    // cv::Mat r, theta;
    // cv::cartToPolar(x_i, y_i, r, theta);

    // double F3 = -0.3;
    // cv::Mat r3, r5;

    // pow(r, 3, r3); pow(r, 5, r5);
    // r += r + r3 * F3;

    // cv::Mat u, v;
    // cv::polarToCart(r, theta, u, v);
    // u *= x_mid;
    // u += x_mid;
    // v *= y_mid;
    // v *= y_mid;

    // cv::Mat image_barrel;
    // cv::remap(image, image_barrel, u, v, cv::INTER_LINEAR);

    // cv::imwrite(path + "/lab2/outputs/image_pincushion.png", image_barrel);
    // cv::imshow("B", image_barrel);
    // cv::waitKey(0);


    // Task 18
    // cv::Mat topPart = cv::imread(path + "/lab2/1.jpg");
    // cv::Mat botPart = cv::imread(path + "/lab2/2.jpg");

    // int templ_size = 10;
    // cv::Mat templ = topPart(cv::Rect(0,topPart.rows - templ_size - 1, 
    //                                         topPart.cols, templ_size));

    // cv::Mat res;
    // cv::matchTemplate(botPart, templ, res, cv::TM_CCOEFF);

    // double min_val, max_val;
    // cv::Point2i min_loc, max_loc;
    // cv::minMaxLoc(res, &min_val, & max_val, &min_loc, &max_loc);

    // cv::Mat image_res = cv::Mat::zeros(topPart.rows + botPart.rows - 
    //                     max_loc.y - templ_size, topPart.cols, topPart.type());

    // topPart.copyTo(image_res(cv::Rect(0, 0, topPart.cols, topPart.rows)));

    // botPart(cv::Rect(0, max_loc.y + templ_size, botPart.cols,
    //                  botPart.rows - max_loc.y - templ_size)).
    //                  copyTo(image_res(cv::Rect(0, topPart.rows, botPart.cols, botPart.rows - max_loc.y - templ_size)));

    // cv::imwrite(path + "/lab2/outputs/image_glues.png", image_res);
    // cv::imshow("B", image_res);
    // cv::waitKey(0);


    // Task 19
    cv::Mat topPart = cv::imread(path + "/lab2/source/top.png");
    cv::Mat botPart = cv::imread(path + "/lab2/source/bttm.png");
    image = cv::imread(path + "/lab2/source/image_cut.png");
    
    cv::Ptr<cv::Stitcher> stitcher = cv::Stitcher::create(cv::Stitcher::SCANS);
    
    std::vector<cv::Mat> imgs;
    imgs.push_back(botPart);
    imgs.push_back(topPart);

    cv::Mat image_stitch;
    cv::Stitcher::Status status = stitcher->stitch(imgs, image_stitch);

    cv::resize(image_stitch, image_stitch, cv::Size(image.cols, image.rows));

    cv::imwrite(path + "/lab2/outputs/image_stitch.png", image_stitch);
    cv::imshow("B", image_stitch);
    cv::waitKey(0);
}

