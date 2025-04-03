//
// Created by Raymond Thaing on 2/26/25.
//

#ifndef SNOWMAN_FUNCTIONS_H
#define SNOWMAN_FUNCTIONS_H
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

void runSnowman();
std::string getRandomWord(const std::string &filename);
std::string intializeWord(std::string word);
void printBoard(const std::string &userWord, int snowman,const std::string &letterbank);
void  printSnowman(int snowman);
char getUserInput();
bool isInWord(char letter,const std::string &realWord);
void updateWord( std::string &userWord,const std::string &realWord,char letter);
void updateSnowman(int &snowman);
void updateLetterbank(char letter, std::string &letterbank);
bool gameOver(int snowman,const std::string &userWord,const std::string &realWord);
bool open(std::ifstream &fin,const std::string &filename);
std::vector<std::string> getWord( std::ifstream &fin);
std::string randomWord(const std::vector<std::string> &words);

std::string toUpper( std::string &word);
///first parameter of updateWord isn't a const because we want the ability to change it


#endif //SNOWMAN_FUNCTIONS_H
