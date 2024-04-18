#include <iostream>
#include <vector>


// class Solution {
// public:
//     static bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
//         int mid = 0, l = 0, r = matrix.size() - 1;

//         while(l <= r){
//             mid = (l + r) / 2;
//             if(matrix[mid][0] > target)
//                 r = mid - 1;
//             else if(matrix[mid][matrix[0].size()-1] < target)
//                 l = mid + 1;
//             else 
//                 break;
//         }
//         std::cout << "mid = " << mid << "\n";
//         l = 0; r = matrix[0].size() - 1;
//         int m;
//         while(l < r){
//             m = (l + r) / 2;
//             if(matrix[mid][m] > target)
//                 r = m - 1;
//             else if(matrix[mid][m] < target)
//                 l = m + 1;
//             else
//                 return true;
//         }

//         return false;
//     }
// };

class Base{
public:
    virtual void show() {std::cout << "Base\n";}
};

class Derived: public Base{
public:
    virtual void show() {std::cout << "Derived\n";}
};


int main(){

    Base* b = new Derived();
    b->show();
    delete b;
    
    // std::vector<std::vector<int>> matrix = {{1,3,5,7}, {10,11,16,20}, {23,30,34,60}};
    // std::cout << Solution::searchMatrix(matrix, 3);
}