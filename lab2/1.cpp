#include <experimental/filesystem>
#include <string>


int main() {
    std::string path = std::experimental::filesystem::current_path();
}