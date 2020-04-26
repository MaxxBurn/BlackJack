#include <iostream>
#include <time.h>
#include <vector>
struct cards
{
    const std::vector<int> cardnumber= {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> currentCards;
    int handscore;
}user,computer;

int PullAnother();
int ComputerAlgorithm(std::vector<int>&);
void Initialize();
void render(std::vector<int>&);
void playing(std::vector<int>);