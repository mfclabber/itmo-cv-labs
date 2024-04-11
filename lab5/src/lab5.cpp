#include <vector>
#include <string>
#include <iostream>
#include <opencv2/opencv.hpp> 



struct func{
    func(std::vector<cv::Vec4i>& lines, cv::Mat& image): lines{lines}, image{image} {};
    std::vector<cv::Vec4i> lines;
    cv::Mat image;
    static bool comp(cv::Vec4i& , cv::Vec4i&);
    static uint lenght_line(cv::Vec4i&);
};


func canny_hough_tranform(cv::Mat& image){

    cv::Mat image_new, image_out = image.clone();
    cv::Canny(image, image_new, 50, 200);
    std::vector<cv::Vec4i> linesP;

    HoughLinesP(image_new, linesP, 1, CV_PI / 150, 80, 40, 4);

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


func ordinary_hough_tranform(cv::Mat& image){

    cv::Mat image_new, image_out = image.clone();
    cv::cvtColor(image, image_new, cv::COLOR_BGR2GRAY);

    cv::threshold(image_new, image_new, 50, 255, cv::THRESH_BINARY);

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

bool func::comp(cv::Vec4i& l1, cv::Vec4i& l2){
    return (std::sqrt(std::pow(abs(l1[2] - l1[0]), 2) + std::pow(abs(l1[3] - l1[1]), 2)) < 
            std::sqrt(std::pow(abs(l2[2] - l2[0]), 2) + std::pow(abs(l2[3] - l2[1]), 2)));
}

uint func::lenght_line(cv::Vec4i& l){
    return std::sqrt(std::pow(abs(l[2] - l[0]), 2) + 
                     std::pow(abs(l[3] - l[1]), 2));
}

int main(int argc, char** argv) 
{ 
    std::string path = "/home/mfclabber/itmo-cv-labs/lab5"; 



    // HOUGH TRANSFORM FOR LINES
    // IMAGE 1

    // GRAYSCALE

    // cv::Mat image;
    // image = cv::imread(path + "/source/test.png", 1);

    // func output = ordinary_hough_tranform(image);

    // std::cout << "MAX LENGTH = " << func::lenght_line(*std::max_element(output.lines.begin(), output.lines.end(), func::comp)) <<
    //              "\nMIN LENGTH = " << func::lenght_line(*std::min_element(output.lines.begin(), output.lines.end(), func::comp)) <<
    //              "\nNUMBER OF LINES = " << output.lines.size();


    // cv::imwrite(path + "/outputs/image1_ordinary.png", output.image);
    // cv::imshow("image", output.image);
    // cv::waitKey();

    // MAX LENGTH = 1279
    // MIN LENGTH = 50
    // NUMBER OF LINES = 2946

    // CANNY

    // cv::Mat image;
    // image = cv::imread(path + "/source/test.png", 1);

    // func output = canny_hough_tranform(image);

    // std::cout << "MAX LENGTH = " << func::lenght_line(*std::max_element(output.lines.begin(), output.lines.end(), func::comp)) <<
    //              "\nMIN LENGTH = " << func::lenght_line(*std::min_element(output.lines.begin(), output.lines.end(), func::comp)) <<
    //              "\nNUMBER OF LINES = " << output.lines.size();


    // cv::imwrite(path + "/outputs/image1_canny.png", output.image);
    // cv::imshow("image", output.image);
    // cv::waitKey();

    // MAX LENGTH = 329
    // MIN LENGTH = 40
    // NUMBER OF LINES = 314



    // IMAGE 2

    // GRAYSCALE

    // cv::Mat image;
    // image = cv::imread(path + "/source/2.png", 1);

    // func output = ordinary_hough_tranform(image);

    // std::cout << "MAX LENGTH = " << func::lenght_line(*std::max_element(output.lines.begin(), output.lines.end(), func::comp)) <<
    //              "\nMIN LENGTH = " << func::lenght_line(*std::min_element(output.lines.begin(), output.lines.end(), func::comp)) <<
    //              "\nNUMBER OF LINES = " << output.lines.size();


    // cv::imwrite(path + "/outputs/image2_ordinary.png", output.image);
    // cv::imshow("image", output.image);
    // cv::waitKey();

    // MAX LENGTH = 1290
    // MIN LENGTH = 50
    // NUMBER OF LINES = 984

    // CANNY

    // cv::Mat image;
    // image = cv::imread(path + "/source/2.png", 1);

    // func output = canny_hough_tranform(image);

    // std::cout << "MAX LENGTH = " << func::lenght_line(*std::max_element(output.lines.begin(), output.lines.end(), func::comp)) <<
    //              "\nMIN LENGTH = " << func::lenght_line(*std::min_element(output.lines.begin(), output.lines.end(), func::comp)) <<
    //              "\nNUMBER OF LINES = " << output.lines.size();


    // cv::imwrite(path + "/outputs/image2_canny.png", output.image);
    // cv::imshow("image", output.image);
    // cv::waitKey();

    // MAX LENGTH = 539
    // MIN LENGTH = 50
    // NUMBER OF LINES = 44



    // IMAGE 3

    // GRAYSCALE

    // cv::Mat image;
    // image = cv::imread(path + "/source/4.png", 1);

    // func output = ordinary_hough_tranform(image);

    // std::cout << "MAX LENGTH = " << func::lenght_line(*std::max_element(output.lines.begin(), output.lines.end(), func::comp)) <<
    //              "\nMIN LENGTH = " << func::lenght_line(*std::min_element(output.lines.begin(), output.lines.end(), func::comp)) <<
    //              "\nNUMBER OF LINES = " << output.lines.size();


    // cv::imwrite(path + "/outputs/image3_ordinary.png", output.image);
    // cv::imshow("image", output.image);
    // cv::waitKey();

    // MAX LENGTH = 735
    // MIN LENGTH = 53
    // NUMBER OF LINES = 738

    // CANNY

    // cv::Mat image;
    // image = cv::imread(path + "/source/4.png", 1);

    // func output = canny_hough_tranform(image);

    // std::cout << "MAX LENGTH = " << func::lenght_line(*std::max_element(output.lines.begin(), output.lines.end(), func::comp)) <<
    //              "\nMIN LENGTH = " << func::lenght_line(*std::min_element(output.lines.begin(), output.lines.end(), func::comp)) <<
    //              "\nNUMBER OF LINES = " << output.lines.size();


    // cv::imwrite(path + "/outputs/image3_canny.png", output.image);
    // cv::imshow("image", output.image);
    // cv::waitKey();

    // MAX LENGTH = 469
    // MIN LENGTH = 52
    // NUMBER OF LINES = 52




    // HOUGH TRANSFORM FOR LINES

    // IMAGE 1

    // cv::Mat image, gray;
    // image = cv::imread(path + "/source/6.png", 1);

    // GRAYSCALE

    // cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    // cv::medianBlur(gray, gray, 5);

    // std::vector<cv::Vec3f> circles;

    // cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1,
    // gray.rows/16, // change this value to detect circles with different distances to each other
    // 100, 30, 50, 55 // change the last two parameters
    // // (min_radius & max_radius) to detect larger circles
    // );
    // for( size_t i = 0; i < circles.size(); i++ )
    // {
    //     cv::Vec3i c = circles[i];
    //     cv::Point center = cv::Point(c[0], c[1]);
    //     // circle center
    //     cv::circle(image, center, 1, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    //     // circle outline
    //     int radius = c[2];
    //     cv::circle(image, center, radius, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    // }
    // cv::imwrite(path + "/outputs/image6_ordinary_r50.png", image);
    // cv::imshow("detected circles", image);
    // cv::waitKey();


    // cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1,
    // gray.rows/16, // change this value to detect circles with different distances to each other
    // 100, 30, 50, 65 // change the last two parameters
    // // (min_radius & max_radius) to detect larger circles
    // );
    // for( size_t i = 0; i < circles.size(); i++ )
    // {
    //     cv::Vec3i c = circles[i];
    //     cv::Point center = cv::Point(c[0], c[1]);
    //     // circle center
    //     cv::circle(image, center, 1, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    //     // circle outline
    //     int radius = c[2];
    //     cv::circle(image, center, radius, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    // }
    // cv::imwrite(path + "/outputs/image6_ordinary_r5065.png", image);
    // cv::imshow("detected circles", image);
    // cv::waitKey();


    // CANNY

    // cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    // cv::Canny(gray, gray, 50, 200);

    // std::vector<cv::Vec3f> circles;

    // cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1,
    // gray.rows/16, // change this value to detect circles with different distances to each other
    // 100, 30, 50, 55 // change the last two parameters
    // // (min_radius & max_radius) to detect larger circles
    // );
    // for( size_t i = 0; i < circles.size(); i++ )
    // {
    //     cv::Vec3i c = circles[i];
    //     cv::Point center = cv::Point(c[0], c[1]);
    //     // circle center
    //     cv::circle(image, center, 1, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    //     // circle outline
    //     int radius = c[2];
    //     cv::circle(image, center, radius, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    // }
    // cv::imwrite(path + "/outputs/image6_canny_r50.png", image);
    // cv::imshow("detected circles", image);
    // cv::waitKey();


    // cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1,
    // gray.rows/16, // change this value to detect circles with different distances to each other
    // 100, 30, 50, 65 // change the last two parameters
    // // (min_radius & max_radius) to detect larger circles
    // );
    // for( size_t i = 0; i < circles.size(); i++ )
    // {
    //     cv::Vec3i c = circles[i];
    //     cv::Point center = cv::Point(c[0], c[1]);
    //     // circle center
    //     cv::circle(image, center, 1, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    //     // circle outline
    //     int radius = c[2];
    //     cv::circle(image, center, radius, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    // }
    // cv::imwrite(path + "/outputs/image6_canny_r5065.png", image);
    // cv::imshow("detected circles", image);
    // cv::waitKey();



    // IMAGE 2

    cv::Mat image, gray;
    image = cv::imread(path + "/source/7.png", 1);

    // // GRAYSCALE

    // cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    // cv::medianBlur(gray, gray, 5);

    // std::vector<cv::Vec3f> circles;

    // cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1,
    // gray.rows/16, // change this value to detect circles with different distances to each other
    // 100, 30, 20, 25 // change the last two parameters
    // // (min_radius & max_radius) to detect larger circles
    // );
    // for( size_t i = 0; i < circles.size(); i++ )
    // {
    //     cv::Vec3i c = circles[i];
    //     cv::Point center = cv::Point(c[0], c[1]);
    //     // circle center
    //     cv::circle(image, center, 1, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    //     // circle outline
    //     int radius = c[2];
    //     cv::circle(image, center, radius, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    // }
    // cv::imwrite(path + "/outputs/image7_ordinary_r25.png", image);
    // cv::imshow("detected circles", image);
    // cv::waitKey();


    // cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1,
    // gray.rows/16, // change this value to detect circles with different distances to each other
    // 100, 30, 20, 30 // change the last two parameters
    // // (min_radius & max_radius) to detect larger circles
    // );
    // for( size_t i = 0; i < circles.size(); i++ )
    // {
    //     cv::Vec3i c = circles[i];
    //     cv::Point center = cv::Point(c[0], c[1]);
    //     // circle center
    //     cv::circle(image, center, 1, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    //     // circle outline
    //     int radius = c[2];
    //     cv::circle(image, center, radius, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    // }
    // cv::imwrite(path + "/outputs/image7_ordinary_r2030.png", image);
    // cv::imshow("detected circles", image);
    // cv::waitKey();


    // CANNY

    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::Canny(gray, gray, 50, 200);

    std::vector<cv::Vec3f> circles;

    // cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1,
    // gray.rows/16, // change this value to detect circles with different distances to each other
    // 100, 30, 20, 35 // change the last two parameters
    // // (min_radius & max_radius) to detect larger circles
    // );
    // for( size_t i = 0; i < circles.size(); i++ )
    // {
    //     cv::Vec3i c = circles[i];
    //     cv::Point center = cv::Point(c[0], c[1]);
    //     // circle center
    //     cv::circle(image, center, 1, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    //     // circle outline
    //     int radius = c[2];
    //     cv::circle(image, center, radius, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    // }
    // cv::imwrite(path + "/outputs/image7_canny_r35.png", image);
    // cv::imshow("detected circles", image);
    // cv::waitKey();


    cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1,
    gray.rows/16, // change this value to detect circles with different distances to each other
    100, 30, 18, 35 // change the last two parameters
    // (min_radius & max_radius) to detect larger circles
    );
    for( size_t i = 0; i < circles.size(); i++ )
    {
        cv::Vec3i c = circles[i];
        cv::Point center = cv::Point(c[0], c[1]);
        // circle center
        cv::circle(image, center, 1, cv::Scalar(255,0,0), 3, cv::LINE_AA);
        // circle outline
        int radius = c[2];
        cv::circle(image, center, radius, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    }
    cv::imwrite(path + "/outputs/image7_canny_r3045.png", image);
    cv::imshow("detected circles", image);
    cv::waitKey();


    // IMAGE 3

    // cv::Mat image, gray;
    // image = cv::imread(path + "/source/8.png", 1);

    // // GRAYSCALE

    // cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    // cv::medianBlur(gray, gray, 5);

    // std::vector<cv::Vec3f> circles;

    // cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1,
    // gray.rows/16, // change this value to detect circles with different distances to each other
    // 100, 30, 95, 100 // change the last two parameters
    // // (min_radius & max_radius) to detect larger circles
    // );
    // for( size_t i = 0; i < circles.size(); i++ )
    // {
    //     cv::Vec3i c = circles[i];
    //     cv::Point center = cv::Point(c[0], c[1]);
    //     // circle center
    //     cv::circle(image, center, 1, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    //     // circle outline
    //     int radius = c[2];
    //     cv::circle(image, center, radius, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    // }
    // cv::imwrite(path + "/outputs/image8_ordinary_r100.png", image);
    // cv::imshow("detected circles", image);
    // cv::waitKey();


    // cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1,
    // gray.rows/16, // change this value to detect circles with different distances to each other
    // 100, 30, 80, 100 // change the last two parameters
    // // (min_radius & max_radius) to detect larger circles
    // );
    // for( size_t i = 0; i < circles.size(); i++ )
    // {
    //     cv::Vec3i c = circles[i];
    //     cv::Point center = cv::Point(c[0], c[1]);
    //     // circle center
    //     cv::circle(image, center, 1, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    //     // circle outline
    //     int radius = c[2];
    //     cv::circle(image, center, radius, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    // }
    // cv::imwrite(path + "/outputs/image8_ordinary_r80100.png", image);
    // cv::imshow("detected circles", image);
    // cv::waitKey();


    // CANNY

    // cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    // cv::Canny(gray, gray, 50, 200);

    // std::vector<cv::Vec3f> circles;

    // cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1,
    // gray.rows/16, // change this value to detect circles with different distances to each other
    // 100, 30, 95, 105 // change the last two parameters
    // // (min_radius & max_radius) to detect larger circles
    // );
    // for( size_t i = 0; i < circles.size(); i++ )
    // {
    //     cv::Vec3i c = circles[i];
    //     cv::Point center = cv::Point(c[0], c[1]);
    //     // circle center
    //     cv::circle(image, center, 1, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    //     // circle outline
    //     int radius = c[2];
    //     cv::circle(image, center, radius, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    // }
    // cv::imwrite(path + "/outputs/image8_canny_r100.png", image);
    // cv::imshow("detected circles", image);
    // cv::waitKey();


    // cv::HoughCircles(gray, circles, cv::HOUGH_GRADIENT, 1,
    // gray.rows/ 3, // change this value to detect circles with different distances to each other
    // 100, 30, 80, 120 // change the last two parameters
    // // (min_radius & max_radius) to detect larger circles
    // );
    // for( size_t i = 0; i < circles.size(); i++ )
    // {
    //     cv::Vec3i c = circles[i];
    //     cv::Point center = cv::Point(c[0], c[1]);
    //     // circle center
    //     cv::circle(image, center, 1, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    //     // circle outline
    //     int radius = c[2];
    //     cv::circle(image, center, radius, cv::Scalar(255,0,0), 3, cv::LINE_AA);
    // }
    // cv::imwrite(path + "/outputs/image8_canny_r80110.png", image);
    // cv::imshow("detected circles", image);
    // cv::waitKey();
}