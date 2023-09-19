Custom printf Project

## Description

This project aims to create a custom `printf` function in the C programming language. The `printf` function is a fundamental part of the C standard library, responsible for formatted output.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Author](#author)
- [Reference](#reference)

## Features

	- [x] Basic `printf` functionality.
	- [ ] Support for format specifiers (e.g., `%d`, `%s`, `%c`, `%f`).
	- [ ] Handling of various data types (integers, strings, characters, floating-point numbers).
	- [ ] Custom format specifiers for special use cases.
	- [ ] Error handling and graceful degradation.

## Getting Started

### Prerequisites

	Before you begin, ensure you have met the following requirements:

	- A C compiler (e.g., GCC, Clang) installed on your system.
	- A code editor of your choice (e.g., Visual Studio Code, Sublime Text).

### Installation

	1. Clone this repository to your local machine:

	      '''sh
	      git clone https://github.com/your-username/printf.git
	2. cd printf
	3. gcc -o printf printf.c


### Usage

	To use the custom printf function in your C programs, include the 'main.h' header and call the '_printf' function with the desired format string and arguments. Here is an example:
		#include "main.h"
		int main()
		{
			char name[] = "Betty Kimba Lee";
			_printf("My name is %s", name);
			return (0);
		}
	
	compile your program with the custom printf function and run your program


### Author

	1. Ugeh Mya
	2. Elyud Tesfay

	A big thank you to Alx for their dedication and mentorship in building and grooming us into great software engineers. Their guidance, expertise, and patience have been invaluable on our journey. We are grateful for the countless hours spent teaching and sharing knowledge. Alx's passion for software development is contagious and has inspired us to reach new heights in our careers. We look forward to continuing to learn and grow under their mentorship, and we're excited about the endless possibilities in the world of software engineering that lie ahead. Thank you, Alx, for being an exceptional mentor and role model.



### Reference

	Printf. (2023, August 23). In Wikipedia. https://en.wikipedia.org/wiki/Printf
      
