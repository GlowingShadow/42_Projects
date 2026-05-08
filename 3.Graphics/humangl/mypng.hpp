#pragma once
#include "stdafx.h"
#include "lpng1634/png.h"
#include <iostream>

//#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define PNG_DEBUG 3

class MyPng
{
public:
	MyPng(std::string filename);
	~MyPng();

};

