//
// Created by zhangsiyu on 2021-12-13.
//

#ifndef COMPILER_1_COMPILER_LEXER_H
#define COMPILER_1_COMPILER_LEXER_H

#include <string>

bool has_more(const char *cur, const char *end);

void lex(const std::string &buffer);

const char* lex_identifier(const char *cur, const char *end);

const char* lex_dec(const char* cur, const char * end);

const char* lex_hex(const char* cur, const char * end);

const char* lex_oct(const char* cur, const char * end);

const char* lex_operator(const char* cur, const char * end);

const char* lex_comment(const char* cur, const char * end);

const char* lex_comment_2(const char* cur, const char * end);

const char* lex_string(const char* cur, const char * end);

const char* lex_string_escape(const char* cur, const char * end);

const char* lex_string_escape_hex(const char* cur, const char * end);

const char* lex_string_escape_oct(const char* cur, const char * end);

const char* skip_whitespace(const char *cur, const char *end);

const char* lex_newline(const char *cur, const char *end);

#endif //COMPILER_1_COMPILER_LEXER_H
