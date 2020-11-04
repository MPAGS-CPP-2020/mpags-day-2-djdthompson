#ifndef MPAGSCIPHER_PROCESSCMDLINE_HPP
#define MPAGSCIPHER_PROCESSCMDLINE_HPP //unique identifier

#include <string>
#include <vector>

bool processCmdLine(const std::vector<std::string>& args,bool& helpReq,bool& verReq,int& encryptReq,std::string& inpF, std::string& outF,std::string& ciphKey);

#endif //prevents processcmdline being included twice in a program