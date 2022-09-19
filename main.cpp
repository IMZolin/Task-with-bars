#include <iostream>
#include <vector>
const int k = 3;
const int size = 4;
void exampleSizes(std::vector<double>& arr);
void exampleRelationships(std::vector<int> arr);
void doublePrint(double arr[k]);
void intPrint(int arr[k]);
template <typename T>
void Print(std::vector<T> vec);
template <typename T>
void Fill(std::vector<T>& vec);
template <>
void Fill(std::vector<double>& vec);
template <>
void Fill(std::vector<int>& vec);
void Solution(int count, double size_ost, double* variants);
std::vector<double> sizes;//{0.6,1.5,2.5}
std::vector<int> rels;//relationships {2:1:3}
int main() {

    double variants[size];
    Fill(sizes);
    Fill(rels);
    Print(sizes);
    Print(rels);
    Solution(0, k, variants);
    return 0;
}

template <>
void Fill(std::vector<double>& vec)
{
    vec.push_back(0.6);
    vec.push_back(1.5);
    vec.push_back(2.5);
    vec.push_back(0);
}
template <>
void Fill(std::vector<int>& vec)
{
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(3);
}
template <typename T>
void Print(std::vector<T> vec)
{
    for(auto item: vec)
    {
        std::cout<<item<<" ";
    }
    std::cout<<std::endl;
}

void Solution(int count, double size_ost, double* variants)
{
    if(count == size - 1) {
        variants[count] = size_ost;
        for(int i = 0; i < size; ++i) {
            std::cout << variants[i] << " ";
        }
        std::cout << std::endl;
    } else {
        int dim_m = int(size_ost / sizes[count]);
        for(int i = dim_m; i >= 0 ; --i) {
            size_ost -= sizes[count]*i;
            variants[count] = i;
            Solution(count+1, size_ost, variants);
            size_ost += sizes[count]*i;
        }
    }

}
