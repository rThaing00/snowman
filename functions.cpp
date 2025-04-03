//
// Created by Raymond Thaing on 2/26/25.
//

#include "functions.h"

void runSnowman()
{
    srand(time(0));
    ///create variables
    std::string realWord = getRandomWord("5000-baby-girl-names.txt");
    std::string userWord= intializeWord(realWord),letterbank;
    realWord= toUpper(realWord);
    int snowman= 0;
    bool isActive= true;
    /// print User interface or U/I
    printBoard(userWord,snowman,letterbank);
    ///do
    do
    {
        /// get letter from user
        char letter = getUserInput();
        ///check if letter is in the word
        if(isInWord(letter,realWord))
        {
            /// display letter
            updateWord(userWord,realWord,letter);
        }
        else
        {
            updateSnowman(snowman);
            /// add a body part and update letter bank(there should be 6 different parts)
            updateLetterbank(letter,letterbank);
        }
        printBoard(userWord,snowman,letterbank);
        isActive = !gameOver(snowman,userWord,realWord);
        ///check if the lettter is the in the lettter bank(for hw need to make it yourself)
    }
        ///while game is active
    while(isActive);
    printSnowman(snowman);

}
//TODO read random word from a file
std::string getRandomWord(const std::string &filename)
{
    ////create ifstream object
    std::ifstream fin;
    ///if the object attaches to my file
     if(open(fin, filename))
    {
//         get a vector containing all of the words in the file
         std::vector<std::string> words = getWord(fin);
        //the getWords function will read all the words and push them to a vector and return the vector
//       ///return a random word from the file
        return randomWord(words);
//        /// to get a random number use the rand() function and it returns from 0 to int_MAX
//        ///use the modulus to get a range of numbers
        ///ex. int r= rand() % 10 is getting a range from 0 - 9
        ///fstream  info
        ///do if(!fin.fail()) means if the the file didn't fail to open
        /// to print everything in a file you can use  the eof(end of file) thing
    }
}

std::string intializeWord(std::string word)
{
    std::string result;
    for(char letter : word)
    {
        if (letter == ' ')
        {
            result.push_back(letter);
        }
        else

        result.push_back('_');
    }
    std::cout<<"\n\n\n";
    return result;
}

void printBoard(const std::string &userWord, int snowman,const std::string &letterbank)
{
    printSnowman(snowman);
    std::cout << userWord << std::endl;
    std::cout  << "letterbank: " << letterbank <<std::endl;

}
//TODO use int snowman to determine how much to print
void printSnowman(int snowman)
{
    switch (snowman)
    {
        case 1:
            std::cout <<"\n\n O\n";
            break;
        case 2:
            std::cout <<"\n o\n"<<" O\n";
            break;
        case 3:
            std::cout <<"\n o \n"<<" O-\n";;
            break;
        case 4:
            std::cout <<"\n o>\n"<<"-O-\n";;
            break;
        case 5:
            std::cout<< " ^\n"<< " o\n"<< "-O-\n";
            break;
        case 6:
            std::cout<< " ^\n"<< " o>\n"<< "-O-\n";
            break;
        default:
            break;
    }
}
char getUserInput()
{
    char letter;
    std::cin>> letter;
    return toupper(letter);

}
bool isInWord(char letter,const std::string &realWord)
{
    return realWord.find(letter) != std::string::npos;
}
void updateWord(std::string &userWord,const std::string &realWord,char letter)
{
    int start= 0,index;
    do
    {
        index= realWord.find(letter,start);
        if (index != std::string::npos)
        {
            userWord[index] = letter;
            start = index + 1;

        }
    }
    while (index != std::string::npos);
}
void updateSnowman(int &snowman)
{
    snowman++;
}
void updateLetterbank(char letter,std::string &letterbank)
{
    if(letterbank.find(letter)==std::string::npos)
    {
        letterbank.push_back(letter);
    }

}
bool gameOver(int snowman,const std::string &userWord,const std::string &realWord)
{
    if (snowman > 6 && userWord !=realWord)
    {
        std::cout <<"You have ran out of attempts.\n"<<"GAME OVER!!!!\n";
        std::cout<< "real word is "<<realWord;
        return false;
    }
    if(snowman < 6 && userWord == realWord)
    {
        std::cout << "congrats you have won the game!!!\n";
        std::cout<< "real word is " <<realWord;
        return true;
    }

}
bool open( std::ifstream &fin,const std::string &filename)
{
    fin.open(filename);
    return !fin.fail();
}

std::vector<std::string> getWord( std::ifstream &fin)
{
    ///the getWords function
    /// will read all the words and push them to a vector and return the vector
    std::vector<std::string> vect;
    std::string words;
    while(fin>>words)
    {
        vect.push_back(toUpper(words));
    }
return vect;

}
std::string randomWord(const std::vector<std::string> &words)
{
    return words[rand() % words.size()];
}
std::string toUpper( std::string &word)
{
    for(int i=0;i<word.size();i++)
    {
        word[i] = toupper(word[i]);
    }
    return word;
}