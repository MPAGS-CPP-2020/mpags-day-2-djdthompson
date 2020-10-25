// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// For std::isalpha and std::isupper
#include <cctype>

#include "transformChar.hpp"
#include "processCmdLine.hpp"



// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};


  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};

  // Process command line arguments - ignore zeroth element, as we know this to
  // be the program name and don't need to worry about it
  if(!processCmdLine(cmdLineArgs,helpRequested,versionRequested,inputFile,outputFile)){
    std::cerr << "Exiting..."<<std::endl;
    return 1;
  }

  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.1.0" << std::endl;
    return 0;
  }

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  // Read in user input from stdin/file
  // Warn that input file option not yet implemented
  

  // Loop over each character from user input
  // (until Return then CTRL-D (EOF) pressed)
  //std::cout<<inputFile<<std::endl;
  if (inputFile.empty()) {
    std::cout << "No input file stated, using stdin"<<std::endl;

    while(std::cin >> inputChar){
      inputText+=transformChar(inputChar);
    }
  }else{
    std::ifstream inpStream{inputFile};
    //std::cout<<inpStream.good()<<std::endl;
    if (!inpStream.good()){
      std::cerr<<"File "<<inputFile<<" could not be opened...does it exist?"<<"...Exiting"<<std::endl;
      return 1;
    }
    while(inpStream >> inputChar){
      inputText+=transformChar(inputChar);
    }
    inpStream.close();
  }


  
  
  

  // Output the transliterated text
  // Warn that output file option not yet implemented
  if (outputFile.empty()) {
    std::cout << "No output file stated, using stdout"<<std::endl;
    std::cout <<std::endl<< inputText << std::endl;
  }else{
    std::ofstream outStream{outputFile,std::ios::app};
    if (!outStream.good()){
      std::cerr<<"File "<<outputFile<<" could not be opened correctly"<<"...Exiting"<<std::endl;
      return 1;
    }
    outStream<<std::endl<<inputText;
    outStream.close();
  }


 

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}