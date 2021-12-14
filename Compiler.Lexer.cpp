//
// Created by zhangsiyu on 2021-12-13.
//

#include <iostream>
#include <string>
#include "Compiler.Lexer.h"

bool has_more(const char *cur, const char *end) {
    return cur + 1 < end;
}

void lex(const std::string &buffer) {
    const char *end = buffer.c_str() + buffer.size();
    const char *cur = buffer.c_str();
    bool finish = false;
    while (cur < end && *cur && !finish) {
        switch (*cur) {
            case '\t':
            case '\n':
            case '\f':
            case '\v':
            case ' ':
                cur = skip_whitespace(cur, end);
                break;
            case '\\': // new line
                cur = lex_newline(cur + 1, end);
                break;
            case '@':
            case '#':
            case '$':
            case ';':
            case '=':
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '&':
            case '|':
            case '^':
            case '!':
            case '~':
            case '(':
            case ')':
            case '{':
            case '}':
            case '[':
            case ']':
            case '<':
            case '>':
            case ',':
            case '.':
            case '?':
            case ':':
            case '\'':
            case '"':
            case '`':
                cur = lex_operator(cur, end);
                break;
            case '0': {
                if (has_more(cur, end) && (cur[1] == 'x' || cur[1] == 'X')) {
                    cur = lex_hex(cur, end);
                } else {
                    cur = lex_oct(cur, end);
                }
                break;
            }
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                cur = lex_dec(cur, end);
                break;
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
            case '_':
                cur = lex_identifier(cur, end);
                break;
            default:
                std::cout << "Lex error!" << std::endl;
                finish = true;
                break;
        }
    }
}

const char *lex_identifier(const char *cur, const char *end) {
    std::string result;
    bool finish = false;
    while (cur < end && !finish) {
        switch (*cur) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
            case '_': {
                result += *cur;
                cur++;
                break;
            }
            default: {
                finish = true;
                break;
            }
        }
    }
    std::cout << "identifier: " << result << std::endl;
    return cur;
}

const char *lex_dec(const char *cur, const char *end) {
    bool finish = false;
    std::string result;
    while (cur < end && !finish) {
        switch (*cur) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                result += *cur;
                cur++;
                break;
            default:
                finish = true;
                break;
        }
    }
    std::cout << "decimal: " << result << std::endl;
    return cur;
}

const char *lex_hex(const char *cur, const char *end) {
    cur += 2;
    if (!has_more(cur, end)) {
        std::cout << "Syntax error";
    } else {
        bool finish = false;
        std::string result;
        while (cur < end && !finish) {
            switch (*cur) {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case 'a':
                case 'b':
                case 'c':
                case 'd':
                case 'e':
                case 'f':
                case 'A':
                case 'B':
                case 'C':
                case 'D':
                case 'E':
                case 'F':
                    result += *cur;
                    cur++;
                    break;
                default:
                    finish = true;
                    break;
            }
        }
        std::cout << "0x" << result << std::endl;
    }
    return cur;
}

const char *lex_oct(const char *cur, const char *end) {
    bool finish = false;
    std::string result;
    while (cur < end && !finish) {
        switch (*cur) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
                result += *cur;
                cur++;
                break;
            default:
                finish = true;
                break;
        }
    }
    std::cout << "oct: " << result << std::endl;
    return cur;
}

const char *lex_operator(const char *cur, const char *end) {
    std::string result;
    bool finish = false;
    while (cur < end && !finish) {
        switch (*cur) {
            case '<': // up to 3
            case '>': {
                if (has_more(cur + 1, end) && cur[1] == *cur && cur[2] == '=') { // check <<= >>=
                    result = std::string(cur, 0, 3);
                    cur += 3;
                } else if (has_more(cur, end) && (cur[1] == *cur || cur[1] == '=')) { // check << >> <= >=
                    result = std::string(cur, 0, 2);
                    cur += 2;
                } else { // check > <
                    result = std::string(1, *cur);
                    cur++;
                }
                finish = true;
                break;
            }
            case '@': // up to 1
            case '#':
            case '$':
            case ';':
            case '(':
            case ')':
            case '{':
            case '}':
            case '[':
            case ']':
            case ',':
            case '.':
            case '?':
            case ':':
            case '`': {
                result = *cur;
                cur++;
                finish = true;
                break;
            }
            case '+': // up to 2 with _= __
            case '-':
            case '=':
            case '&':
            case '|': {
                if (has_more(cur, end) && (cur[1] == '=' || cur[1] == *cur)) { // check == += -= &= |= ++ -- && ||
                    result = std::string(cur, 0, 2);
                    cur += 2;
                } else { // check unary
                    result = std::string(1, *cur);
                    cur++;
                }
                finish = true;
                break;
            }
            case '%': // up to 2
            case '*':
            case '^':
            case '!':
            case '~': {
                if (has_more(cur, end) && cur[1] == '=') { // check %= ^= != ~= *=
                    result = std::string(cur, 0, 2);
                    cur += 2;
                } else { // check % * ^ ! ~
                    result = std::string(1, *cur);
                    cur++;
                }
                finish = true;
                break;
            }
            case '/': { // maybe comment, up to 2
                if (has_more(cur, end) && cur[1] == '=') { // check /=
                    result = std::string(cur, 0, 2);
                    cur += 2;
                } else if (has_more(cur, end) && cur[1] == '/') { // check //
                    cur = lex_comment(cur, end);
                } else if (has_more(cur, end) && cur[1] == '*') { // check /*
                    cur = lex_comment_2(cur, end);
                } else { // check /
                    result = std::string(1, *cur);
                    cur++;
                }
                finish = true;
                break;
            }
            case '\'': // char
                break;
            case '"': // string
                cur = lex_string(cur, end);
                break;
            default: // never run here
                finish = true;
                break;
        }
    }
    if (!result.empty())
        std::cout << "operator: " << result << std::endl;
    return cur;
}

const char *lex_comment(const char *cur, const char *end) {
    std::string result;
    bool finish = false;
//    cur += 2;
    while (cur < end && !finish) {
        switch (*cur) {
            case '\n':
            case '\r':
                finish = true;
                cur++;
                break;
            case '\\':
                cur = lex_newline(cur + 1, end);
                break;
            default:
                result += *cur;
                cur++;
                break;
        }
    }
    std::cout << "comment: " << result << std::endl;
    return cur;
}

const char *lex_comment_2(const char *cur, const char *end) {
    std::string result;
    bool finish = false;
//    cur += 2;
    while (cur < end && !finish) {
        switch (*cur) {
            case '*': {
                if (has_more(cur, end) && cur[1] == '/') {
                    result += "*/";
                    cur += 2;
                    finish = true;
                    break;
                }
            }
            default:
                result += *cur;
                cur++;
                break;
        }
    }
    std::cout << "multiline comment: \n" << result << std::endl;
    return cur;
}

const char *lex_string(const char *cur, const char *end) {
    cur += 1;
    bool finish = false;
    std::string result = "\"";
    while (cur < end && !finish) {
        switch (*cur) {
            case '"':
                finish = true;
                cur++;
                break;
            case '\\': { // escape here
                cur = lex_string_escape(cur, end);
                break;
            }
            default:
                cur++;
                break;
        }
    }
    return cur;
}

const char *lex_string_escape(const char *cur, const char *end) {
    std::string result;
    if (has_more(cur, end)) {
        if (cur[1] == '\\') {
            result += "\\";
        } else if (cur[1] == 'n') {
            result += "\n";
        } else if (cur[1] == 'r') {
            result += "\r";
        } else if (cur[1] == 'x') {
            cur = lex_string_escape_hex(cur, end);
        } else if (cur[1] >= '0' && cur[1] <= '7') {
            cur = lex_string_escape_oct(cur, end);
        } else {
            std::cout << "Syntax error!\n";
            cur++;
        }
        cur += 2;
    } else {
        cur++;
        std::cout << "Syntax error!\n";
    }
    return cur;
}

const char *lex_string_escape_hex(const char *cur, const char *end) {

}

const char *lex_string_escape_oct(const char *cur, const char *end) {

}

const char *skip_whitespace(const char *cur, const char *end) {
    bool finish = false;
    while (cur < end) {
        if (finish) {
            break;
        }
        switch (*cur) {
            case '\n':
            case '\r':
            case '\t':
            case ' ':
                cur++;
                break;
            default:
                finish = true;
                break;
        }
    }
    return cur;
}

const char *lex_newline(const char *cur, const char *end) {
    bool finish = false;
    while (cur < end && !finish) {
        switch (*cur) {
            case ' ':
            case '\t':
                cur++;
                break;
            case '\n':
            case '\r':
                cur++;
                finish = true;
                break;
            default:
                finish = true;
                break;
        }
    }
    return cur;
}