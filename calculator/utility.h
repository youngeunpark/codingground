/**
    @file utility.h
    @date 2018/06/10
    @author Youngeun Park
    @brief
    Utility macros
*/

#ifndef __UTILITY_H__
#define __UTILITY_H__

/// Check if given c is numeric number
#define isNum(c) ((c >= '0') && (c <= '9'))

/// Check if given c is newline or NULL
#define isTerminator(c) ((c == '\n') || (c == 0))

/// Check if given c is white character
#define isWhitespace(c) ((c == ' ') || (c == '\t'))

/// Translate character c into integer value
#define toNumeric(c) (c - '0')

#endif

