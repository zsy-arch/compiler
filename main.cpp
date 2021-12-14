#include <iostream>
#include <string>
#include <fstream>
#include "Compiler.Lexer.h"

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        std::cout << "no file input." << std::endl;
        return 0;
    }
    std::string file_path(argv[1]);
    std::ifstream file_istream(file_path);
    file_istream.seekg(0, std::ios::end);
    size_t end = file_istream.tellg();
    std::string buffer(end, '\0');
    file_istream.seekg(0);
    file_istream.read(&buffer[0], end);
    lex(buffer);
    return 0;
}
