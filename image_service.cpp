#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <filesystem>

namespace fs = std::filesystem;

// Function to retrieve the ith image path
std::string getImagePath(int i, const std::vector<std::string>& imageSet) {
    // If i is greater than or equal to the number of images, apply modulo
    if (i >= imageSet.size()) {
        i %= imageSet.size();
    }

    // Return the path of the ith image
    return imageSet[i];
}

// Function to read the list of image paths from a file
std::vector<std::string> readImagePaths(const std::string& filePath) {
    std::vector<std::string> paths;
    std::ifstream file(filePath);

    if (file.is_open()) {
        std::string path;
        while (std::getline(file, path)) {
            paths.push_back(path);
        }
        file.close();
    } else {
        std::cerr << "Error opening file: " << filePath << std::endl;
    }

    return paths;
}

int main() {
    // Print current working directory
    std::cout << "Current working directory: " << fs::current_path() << std::endl;

    // Assuming image paths are stored in a vector
    std::vector<std::string> imageSet = readImagePaths("C:\\361#1\\image_list.txt");

    // Read the input non-negative integer i from image-service.txt
    std::ifstream inputFile("image-service.txt");
    int i;
    if (inputFile >> i) {
        // Get the image path based on the input i
        std::string imagePath = getImagePath(i, imageSet);

        // Write the image path to image-service.txt
        std::ofstream outputFile("image-service.txt");
        outputFile << imagePath;
        outputFile.close();
    } else {
        std::cerr << "Error reading input from image-service.txt\n";
    }

    return 0;
}
