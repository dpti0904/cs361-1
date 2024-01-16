   // prng_service.cpp
   #include <iostream>
   #include <fstream>
   #include <cstdlib>
   #include <ctime>
  
   int main() {
       // Seed the random number generator with the current time
       std::srand(std::time(0));
 
      // Generate a pseudo-random number
      int randomNumber = std::rand();
 
      // Write the pseudo-random number to prng-service.txt
      std::ofstream outFile("prng-service.txt");
      if (outFile.is_open()) {
          outFile << randomNumber;
          outFile.close();
      } else {
          std::cerr << "Unable to open prng-service.txt for writing." << std::endl;
          return 1; // Return an error code
      }
       return 0; // Return success
  }