#!/bin/bash

#******* A makefile to compile all the .c files in the directory****


#***** compiler options with 89 standards*****
options=gcc -Wall -Werror -Wextra -pedantic -std=gnu89

.PHONY: printf

#****Compile each file on its own*****
printf:
	$(options) *.c -o printf

.PHONY: clean

#***** Remove all the object files ****
clean:
	rm *.o printf


