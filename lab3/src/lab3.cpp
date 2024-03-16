#include <vector>
#include <string>
#include <random>
#include <iostream>
#include <opencv2/opencv.hpp>



std::vector<float> unique(const cv::Mat &I, bool sort = false)
{
    cv::Mat image = I;

    if (image.depth() != CV_32F)
    {
        std::cerr << "transformation to CV_32F";
        return std::vector<float>();
    }

    std::vector<float> out;
    int rows = image.rows;
    int cols = image.cols * image.channels();

    if (image.isContinuous())
    {
        cols *= rows;
        rows = 1;
    }

    for (int y = 0; y < rows; ++y)
    {
        const float *row_ptr = image.ptr<float>(y);
        for (int x = 0; x < cols; ++x)
        {
            float value = row_ptr[x];
            if (std::find(out.begin(), out.end(), value) == out.end())
                out.push_back(value);
        }
    }

    if (sort)
        std::sort(out.begin(), out.end());
    return out;
}


uchar adaptiveProcess(const cv::Mat &im, int row, int col, int kernelSize, int maxSize)
    {
        std::vector <uchar> pixels;
        for(int a = -kernelSize / 2; a <= kernelSize / 2; a++){
            for(int b = -kernelSize / 2; b <= kernelSize / 2; b++){
                pixels.push_back(im.at<uchar>(row + a, col + b));
            }
        }
        std::sort(pixels.begin(), pixels.end());
        auto min = pixels[0];
        auto max = pixels[kernelSize * kernelSize - 1];
        auto med = pixels[kernelSize * kernelSize / 2];
        auto zxy = im.at<uchar>(row, col);
        if(med > min && med < max){
            if(zxy > min && zxy < max){
                return zxy;
            }else{
                return med;
            }
        }
        else{
            kernelSize += 2;
            if(kernelSize <= maxSize)
                return adaptiveProcess(im, row, col, kernelSize, maxSize);
            else
                return med;
        }
    }

cv::Mat amf_work(cv::Mat src){
    cv::Mat dst;
    int minSize = 3;
    int maxSize = 7; 
    copyMakeBorder(src, dst, maxSize / 2, maxSize / 2, maxSize / 2, maxSize / 2, cv::BORDER_REFLECT);
    int rows = dst.rows;
    int cols = dst.cols;
    for(int j = maxSize / 2; j < rows - maxSize / 2; j++){
        for(int i = maxSize / 2; i < cols * dst.channels() - maxSize / 2; i++){
            dst.at<uchar>(j, i) = adaptiveProcess(dst, j, i, minSize, maxSize);
        }
    }
    return dst;
}


int main(int argc, char **argv)
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

    // image = cv::imread(path + "/lab3/outputs/image_quant_filter.png", 1);

    // std::pair<int, int> kernel = std::make_pair(3, 3);
    // const int Q = -10;

    // image_out = image.clone();
    // std::cout << image.depth();
    
    // int radius_c = (kernel.first - 1) / 2;  // columns offset
    // int radius_r = (kernel.second - 1) / 2; // rows offset
    // float res = 0;

    // for (int c = 0; c < 3; ++c)
    // {
    //     for (int i = radius_r; i < image.rows - kernel.second - 1; i++)
    //     {
    //         for (int j = radius_c; j < image.cols - kernel.first - 1; j++)
    //         {
    //             res = 0;
    //             for (int m = 0; m < kernel.first; ++m)
    //             {
    //                 for (int n = 0; n < kernel.second; ++n)
    //                 {
    //                     res += (pow(image.at<cv::Vec3f>(i + m, j + n)[c], Q + 1)) / (pow(image.at<cv::Vec3f>(i + m, j + n)[c], Q));
    //                 }
    //             }
    //             image_out.at<cv::Vec3f>(i, j)[c] = res;
    //         }
    //     }
    // }
    // cv::imwrite(path + "/lab3/outputs/image_quant_countergarmonic_filter_Q10.png", image_out);
    // cv::imshow("Image", image_out);
    // cv::waitKey(0);

    // MEDIAN FILTER

    // image = cv::imread(path + "/lab3/outputs/image_gauss_noise.png", 1);

    // cv::medianBlur(image, image_out, 3);

    // cv::imwrite(path + "/lab3/outputs/image_gauss_median_filter_k3.png", image_out);
    // cv::imshow("Image", image_out);
    // cv::waitKey(0);



    // RANG FILTER

    // image = cv::imread(path + "/lab3/outputs/image_gauss_noise.png", 1);

    // int k_size[] = {3, 3};

    // cv::Mat kernel= cv::Mat::ones(k_size[0], k_size[1], CV_64F);
    // int rank = 5;

    // cv::Mat image_copy;
    // if(image.depth() == CV_8U)
    //     image.convertTo(image_copy, CV_32F, 1.0 / 255);
    // else
    //     image_copy = image;

    // cv::copyMakeBorder(image_copy, image_copy,
    //                     int((k_size[0] - 1) / 2),
    //                     int(k_size[0] / 2),
    //                     int((k_size[1] - 1) / 2),
    //                     int(k_size[1] / 2), cv::BORDER_REPLICATE);

    // std::vector<cv::Mat> bgr_planes;
    // cv::split(image_copy, bgr_planes);

    // for(int k = 0; k < bgr_planes.size(); k++){
    //     cv::Mat image_tmp = cv::Mat::zeros(image.size(), bgr_planes[k].type());

    //     std::vector<double> c;
    //     c.reserve(k_size[0] * k_size[1]);

    //     for(int i = 0; i , image.rows; i++){
    //         for(int j = 0; j < image.cols; j++){
    //             c.clear();

    //             for(int a = 0; a < k_size[0]; a++)
    //                 for(int b = 0; b < k_size[1]; b++)
    //                     c.push_back(bgr_planes[k].at<float>(i + a, j + b) *kernel.at<double>(a, b));

    //             std::sort(c.begin(), c.end());

    //             image_tmp.at<float>(i, j) = float(c[rank]);
    //         }
    //     }
    //     bgr_planes[k] = image_tmp;
    // }

    // cv::merge(bgr_planes, image_out);

    // if(image.depth() == CV_8U)
    //     image_out.convertTo(image_out, CV_8U, 255);

    // cv::imwrite(path + "/lab3/outputs/image_gauss_weighteed_median_filter_k3.png", image_out);
    // cv::imshow("Image", image_out);
    // cv::waitKey(0);



    // VINIER WEIGHTED FILTER

    // int k_size[] = {5, 5};
    // cv::Mat kernel = cv::Mat::ones(k_size[0], k_size[1], CV_64F);

    // double k_sum = cv::sum(kernel)[0];

    // cv::Mat image_copy;
    // if(image.depth() == CV_8U)
    //     image.convertTo(image_copy, CV_32F, 1.0 / 255);\
    // else    
    //     image_copy = image;
    // cv::copyMakeBorder(image_copy, image_copy,
    //                     int((k_size[0] - 1) / 2),
    //                     int(k_size[0] / 2),
    //                     int((k_size[1] - 1) / 2),
    //                     int(k_size[1] / 2), cv::BORDER_REPLICATE);

    // std::vector<cv::Mat> bgr_planes;
    // cv::split(image_copy, bgr_planes);

    // for(int k = 0; k < bgr_planes.size(); k++){
    //     cv::Mat image_tmp = cv::Mat::zeros(image.size(), bgr_planes[k].type());
    //     double v(0);

    //     for(int i = 0; i < image.rows; i++)
    //         for(int j = 0; j < image.cols; j++){
    //             double m(0), q(0);
    //             for(int a = 0; a < k_size[0]; a++)
    //                 for(int b = 0; b < k_size[1]; b++){
    //                     double t = bgr_planes[k].at<float>(i + a, j + b) * kernel.at<double>(a, b);
    //                     m += t;
    //                     q += t*t;
    //                 }
                
    //             m /= k_sum;
    //             q /= k_sum;
    //             q -= m*m;
    //             v += q;
    //         }
    //     v /= image.cols * image.rows;

    //     for(int i = 0; i < image.rows; i++)
    //         for(int j = 0; j < image.cols; j++){
    //             double m(0), q(0);
    //             for(int a = 0; a < k_size[0]; a++)
    //                 for(int b = 0; b < k_size[1]; b++){
    //                     double t = bgr_planes[k].at<float>(i = a, j + b) * kernel.at<double>(a, b);
    //                     m += t;
    //                     q += t*t;
    //                 }
    //             m /= k_sum;
    //             q /= k_sum;
    //             q -= m*m;

    //             double im = bgr_planes[k].at<float>(i + (k_size[0] - 1) / 2, j + (k_size[1] - 1) / 2);
    //             if(q < v)
    //                 image_tmp.at<float>(i, j) = float(m);
    //             else
    //                 image.at<float>(i, j) = float((im - m) * ( 1 - v / q) + m);
    //         }
    //     bgr_planes[k] = image_tmp;
    // }

    // cv::merge(bgr_planes, image_out);

    // if(image.depth() == CV_8U)
    //     image_out.convertTo(image_out, CV_8U, 255);

    // cv::imwrite(path + "/lab3/outputs/image_vinier_filter_k3.png", image_out);
    // cv::imshow("Image", image_out);
    // cv::waitKey(0);
    


    // ADAPTIVE MEDIAN FILTER

    // cv::Mat src = cv::imread(path + "/lab3/outputs/image_vinier_filter_k3.png");
    // cv::Mat dst = afm_work(src);
    // cv::imshow("origin", src);
    // cv::imshow("result", dst);
    // cv::imwrite("../result.jpg", dst);
    // cv::waitKey(0);



    // ROBERTS OPERATOR

    // image = cv::imread(path + "/lab3/source/SDC_Yandex.png", 1);
    // cv::Mat G_x = (cv::Mat_<double>(2, 2) << -1, 1, 0, 0);
    // cv::Mat G_y = (cv::Mat_<double>(2, 2) << 1, 0, -1, 0);

    // cv::Mat I_x, I_y, I_out;

    // cv::filter2D(image, I_x, -1, G_x);
    // cv::filter2D(image, I_y, -1, G_y);

    // I_x.convertTo(I_x, CV_32F);
    // I_y.convertTo(I_y, CV_32F);

    // cv::magnitude(I_x, I_y, I_out);

    // cv::imwrite(path + "/lab3/outputs/roberts_operator.png", I_out);
    // cv::imshow("Image", I_out);
    // cv::waitKey(0);



    // PREVIT OPERATOR

    // image = cv::imread(path + "/lab3/source/SDC_Yandex.png", 1);
    // cv::Mat G_x = (cv::Mat_<double>(3, 3) << -1, 0, 1, -1, 0, 1, -1, 0, 1);
    // cv::Mat G_y = (cv::Mat_<double>(3, 3) << -1, -1, -1, 0, 0, 0, 1, 1, 1);

    // cv::Mat I_x, I_y, I_out;
    
    // cv::filter2D(image, I_x, -1, G_x);
    // cv::filter2D(image, I_y, -1, G_y);

    // I_x.convertTo(I_x, CV_32F);
    // I_y.convertTo(I_y, CV_32F);

    // cv::magnitude(I_x, I_y, I_out);

    // cv::imwrite(path + "/lab3/outputs/previt_operator.png", I_out);
    // cv::imshow("Image", I_out);
    // cv::waitKey(0);



    // SOBEL OPERATOR

    // image = cv::imread(path + "/lab3/source/SDC_Yandex.png", 1);
    // cv::Mat G_x = (cv::Mat_<double>(3, 3) << -1, 0, 1, -2, 0, 2, -1, 0, 1);
    // cv::Mat G_y = (cv::Mat_<double>(3, 3) << 1, 2, 1, 0, 0, 0, -1, -2, -1);

    // cv::Mat I_x, I_y, I_out;
    
    // cv::filter2D(image, I_x, -1, G_x);
    // cv::filter2D(image, I_y, -1, G_y);

    // I_x.convertTo(I_x, CV_32F);
    // I_y.convertTo(I_y, CV_32F);

    // cv::magnitude(I_x, I_y, I_out);

    // cv::imwrite(path + "/lab3/outputs/sobel_operator.png", I_out);
    // cv::imshow("Image", I_out);
    // cv::waitKey(0);



    // LAPLAS OPERATOR

    // image = cv::imread(path + "/lab3/source/SDC_Yandex.png", 1);
    // cv::Mat G_x = (cv::Mat_<double>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
    // cv::Mat G_y = (cv::Mat_<double>(3, 3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);

    // cv::Mat I_x, I_y, I_out;
    
    // cv::filter2D(image, I_x, -1, G_x);
    // cv::filter2D(image, I_y, -1, G_y);

    // I_x.convertTo(I_x, CV_32F);
    // I_y.convertTo(I_y, CV_32F);

    // cv::magnitude(I_x, I_y, I_out);

    // cv::imwrite(path + "/lab3/outputs/laplas_operator.png", I_out);
    // cv::imshow("Image", I_out);
    // cv::waitKey(0);



    //CANNY OPERATOR

    image = cv::imread(path + "/lab3/source/SDC_Yandex.png", 1);
    cv::Canny(image, image_out, 50, 200);

    cv::imwrite(path + "/lab3/outputs/canny_operator.png", image_out);
    cv::imshow("Image", image_out);
    cv::waitKey(0);
}