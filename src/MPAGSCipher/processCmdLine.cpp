#include <string>
#include <vector>
#include <iostream>

#include "processCmdLine.hpp"

bool processCmdLine(const std::vector<std::string>& args,bool& helpReq,bool& verReq,std::string& inpF, std::string& outF){
  /*Takes the argument vector of strings and the relevant variables for program operation and proceses user input
    to a useful result for the remainder of the program

    -------
    args: vector string of arguments after(and including) executable
    bool helpReq: will set true if help requested
    bool verReq: ^^^ version requested
    string inpF: string to store input file name
    string outF: ^^^ output file name

    all variables passed by reference 

    -------
    returns true for a successful parse and false if file names/arugments missing or invalid arugments
  */



  // Add a typedef that assigns another name for the given type for clarity
  typedef std::vector<std::string>::size_type size_type;
  const size_type nCmdLineArgs {args.size()};

   // Process command line arguments - ignore zeroth element, as we know this to
  // be the program name and don't need to worry about it
  for (size_type i {1}; i < nCmdLineArgs; ++i) {

    if (args[i] == "-h" || args[i] == "--help") {
      helpReq = true;
    }
    else if (args[i] == "--version") {
      verReq = true;
    }
    else if (args[i] == "-i") {
      // Handle input file option
      // Next element is filename unless -i is the last argument
      if (i == nCmdLineArgs-1) {
        std::cerr << "[error] -i requires a filename argument" << std::endl;
        // exit main with non-zero return to indicate failure
        return false;
      }
      else {
  // Got filename, so assign value and advance past it
        inpF = args[i+1];
        ++i;
      }
    }
    else if (args[i] == "-o") {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      if (i == nCmdLineArgs-1) {
        std::cerr << "[error] -o requires a filename argument" << std::endl;
        // exit main with non-zero return to indicate failure
        return false;
      }
      else {
  // Got filename, so assign value and advance past it
        outF = args[i+1];
        ++i;
      }
    }
    else {
      // Have an unknown flag to output error message and return non-zero
      // exit status to indicate failure
      std::cerr << "[error] unknown argument '" << args[i] << "'\n";
      return false;
    }
  }
  return true; //if all arguments processed correctly return true to tell main program that operation was successful

}