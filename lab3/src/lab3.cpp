#include <vector>
#include <string>
#include <random>
#include <iostream>
#include <opencv2/opencv.hpp> 



std::vector<float> unique(const cv::Mat& I, bool sort = false){
    cv::Mat image = I;

    if(image.depth() != CV_32F){
        std::cerr << "transformation to CV_32F";
        return std::vector<float>();
    }

    std::vector<float> out;
    int rows = image.rows;
    int cols = image.cols * image.channels();
    
    if(image.isContinuous()){
        cols *= rows;
        rows = 1;
    }

    for(int y = 0; y < rows; ++y){
        const float* row_ptr = image.ptr<float>(y);
        for(int x = 0; x < cols; ++x){
            float value = row_ptr[x];
            if(std::find(out.begin(), out.end(), value) == out.end())
                out.push_back(value);
        }
    }

    if(sort)
        std::sort(out.begin(), out.end());
    return out;
}



int main(int argc, char** argv) 
{ 
    // было решено оставить так, потому что библиотеки требовательны к версиям компилятора и ОС
    std::string path = "/home/mfclabber/itmo-cv-labs"; 

    cv::Mat image, image_out;
    image = cv::imread(path + "/lab3/source/image.png", 1); 



    // IMPULSE NOISE

    // double d = 0.0005;
    // double s_vs_p = 0.1;
    // std::vector<cv::Mat> image_out_BGR;

    // cv::split(image, image_out_BGR);

    // for(int i = 0; i < image_out_BGR.size(); ++i){
    //     cv::Mat vals(image_out_BGR[i].size(), CV_32F);
    //     cv::randn(vals, cv::Scalar(0), cv::Scalar(1));

    //     if(image_out_BGR[i].depth() == CV_8U)
    //         image_out_BGR[i].setTo(cv::Scalar(255), vals < d * s_vs_p);
    //     else
    //         image_out_BGR[i].setTo(cv::Scalar(1), vals < d * s_vs_p);
        
    //     image_out_BGR[i].setTo(cv::Scalar(0), (vals >= d * s_vs_p) & (vals < d));
    // }

    // cv::merge(image_out_BGR, image_out);

    // cv::imwrite(path + "/lab3/outputs/image_impulse_noise.png", image_out);
    // cv::imshow("Image", image_out); 
    // cv::waitKey(0); 



    //  MULTIPLICAIVE NOISE

    // double var = 0.05;
    // std::vector<cv::Mat> image_out_BGR;

    // cv::split(image, image_out_BGR);

    // for(int i = 0; i < image_out_BGR.size(); ++i){

    //     cv::Mat gauss(image_out_BGR[i].size(), CV_32F);
    //     cv::randn(gauss, cv::Scalar(0), cv::Scalar(cv::sqrt(var)));

    //     if( image_out_BGR[i].depth() == CV_8U){
    //         cv::Mat image_out_BGR_f;

    //         // Конвертация в вещественное представление для сохранения точности
    //         image_out_BGR[i].convertTo(image_out_BGR_f, CV_32F);

    //         image_out_BGR_f += image_out_BGR_f.mul(gauss);
    //         image_out_BGR_f.convertTo(image_out_BGR[i], image_out_BGR[i].type());
    //     } else
    //         image_out_BGR[i] += image_out_BGR[i].mul(gauss);
    // }

    // cv::merge(image_out_BGR, image_out);

    // cv::imwrite(path + "/lab3/outputs/image_mltp_noise.png", image_out);
    // cv::imshow("Image", image_out); 
    // cv::waitKey(0);



    // GAUSS NOISE

    // double mean = 0;
    // double var = 0.05;
    // std::vector<cv::Mat> image_out_BGR;

    // cv::split(image, image_out_BGR);

    // for(int i = 0; i < image_out_BGR.size(); ++i){

    //     cv::Mat gauss(image_out_BGR[i].size(), CV_32F);
    //     cv::randn(gauss, cv::Scalar(mean), cv::Scalar(cv::sqrt(var)));

    //     if( image_out_BGR[i].depth() == CV_8U){
    //         cv::Mat image_out_BGR_f;

    //         // Конвертация в вещественное представление для сохранения точности
    //         image_out_BGR[i].convertTo(image_out_BGR_f, CV_32F);

    //         image_out_BGR_f += gauss * 255;
    //         image_out_BGR_f.convertTo(image_out_BGR[i], image_out_BGR[i].type());
    //     } else
    //         image_out_BGR[i] += gauss;
    // }

    // cv::merge(image_out_BGR, image_out);

    // cv::imwrite(path + "/lab3/outputs/image_gauss_noise.png", image_out);
    // cv::imshow("Image", image_out); 
    // cv::waitKey(0);



    // QUANTIZATION NOISE

    // if(image.depth() == CV_8U)
    //     image.convertTo(image_out, CV_32F, 1.0 / 255);
    // else
    //     image_out = image.clone();

    // size_t vals = unique(image_out).size();
    // vals = static_cast<size_t>(cv::pow(2, ceil(log2(vals))));

    // int rows = image_out.rows;
    // int cols = image_out.cols * image_out.channels();

    // if(image_out.isContinuous()){
    //     cols *= rows;
    //     rows = 1;
    // }

    // using param_t = std::poisson_distribution<int>::param_type;
    // std::default_random_engine engine;
    // std::poisson_distribution<> poisson;

    // for(int i = 0; i < rows; ++i){
    //     float* ptr = image_out.ptr<float>(i);
    //     for(int j = 0; j < cols; ++j)
    //         ptr[j] = float(poisson(engine, param_t({ptr[j] * vals}))) / vals;
    // }

    // if(image.depth() == CV_8U)
    //     image_out.convertTo(image_out, CV_8U, 255);

    // cv::imwrite(path + "/lab3/outputs/image_quant_noise.png", image_out);
    // cv::imshow("Image", image_out); 
    // cv::waitKey(0);



    // GAUSSIAN FILTER
    // image = cv::imread(path + "/lab3/outputs/image_quant_noise.png", 1); 
    // cv::GaussianBlur(image, image_out, cv::Size(5, 5), 0);

    // cv::imwrite(path + "/lab3/outputs/image_quant_filter.png", image_out);
    // cv::imshow("Image", image_out); 
    // cv::waitKey(0);



    // COUNTERGARMONIC AVERAGE FILTER
    image = cv::imread(path + "/lab3/outputs/image_quant_filter.png", 1); 

    std::pair<int, int> kernel = std::make_pair(2, 2);
    const int Q = 5;

    image_out = image.clone();

    int radius_c = (kernel.first - 1) / 2; // columns offset
    int radius_r = (kernel.second - 1) / 2; // rows offset
    float res = 0;

    for(int c = 0; c < 3; ++c){
        for (int i = radius_r; i < image.rows - kernel.second - 1; i++) {
            for (int j = radius_c; j < image.cols - kernel.first - 1; j++) {
                res = 0;
                for(int m = 0; m < kernel.first; ++m){
                    for(int n = 0; n < kernel.second; ++n){
                        res += (pow(image.at<cv::Vec3f>(i + m, j + n)[c], Q + 1)) 
                                / (pow(image.at<cv::Vec3f>(i + m, j + n)[c], Q));
                    }
                }
                image_out.at<cv::Vec3f>(i, j)[c] = res;
            }
        }
    }
    
    cv::imshow("Image", image_out); 
    cv::waitKey(0);
}