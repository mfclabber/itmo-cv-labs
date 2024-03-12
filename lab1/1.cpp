#include <iostream>
#include <opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace cv; 
using namespace std; 

int main()
{
    cout << CV_VERSION;
    // Read the image file as 
    // imread("default.jpg"); 
    Mat image = imread("image.png"); 
  
    // Error Handling 
    // if (image.empty()) { 
    //     cout << "Image File "
    //          << "Not Found" << endl; 
  
    //     // wait for any key press 
    //     std::cin.get(); 
    //     return -1; 
    // } 
  
    // Show Image inside a window with 
    // the name provided 
    imshow("Window Name", image); 
  
    // Wait for any keystroke 
    waitKey(0);
}

// https://onlinetestpad.com/t4lijgwp3obb4
0.5*Integrate[Power[e,-3t] * Power[e,-i2pit*Divide[2,2]],{t,0,2}] 