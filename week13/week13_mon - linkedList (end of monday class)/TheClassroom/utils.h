// these are useful library functions for input

// steveh - prog71990-f24 - week06

#pragma once
#include <stdbool.h>
#include <stdio.h>

int CountOfLetterInString(char* string, char c);

void CleanNewLineFromString(char* string);

bool StringIsNumeric(char* string);

bool PromptAndGetStringInput(char* prompt, char* response, size_t max);

float PromptAndReturnNumberInput(char* prompt);

bool PromptAndGetNumberInput(char* prompt, float* response);
