#pragma once

#ifndef CAESAR_H
#define CAESAR_H

#include <stddef.h>
#include <iostream>

class Caesar {
public:
    Caesar();
    ~Caesar();

    int Encrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& OutSz);
    int Decrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& OutSz);

    void SetShift(int shift);
    void PrintData(const unsigned char* data, unsigned int size);

private:
    unsigned char ShiftChar(unsigned char ch, int shift);
    int mShift;
};

#endif