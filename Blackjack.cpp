#include "BlackJack.h"
//Random generator
int Random(){
    int x = rand() % 10;
    return x;
}
int CheckPoints(std::vector<int>& currentHand)
{
    int sum_of_ele{};
    for (auto& a : currentHand) sum_of_ele+=a;
    return sum_of_ele;
}
int PullAnother()
{
    return user.cardnumber[Random()];
}
int ComputerAlgorithm(std::vector<int>& currentHand){
    int temp = Random();
    if(CheckPoints(currentHand) + temp <=21) {
        computer.currentCards.push_back(temp); 
        ComputerAlgorithm(computer.currentCards);
    }
    return CheckPoints(computer.currentCards);
}
void initialize()
{
    user.currentCards.push_back(user.cardnumber[Random()]);
    computer.currentCards.push_back(user.cardnumber[Random()]);
}
void render(std::vector<int>& current)
{
    std::cout<<"Your cards:\t";
    for(auto a : current) {std::cout<< a<<"   ";}
}
void Playing(std::vector<int>& currentHand)
{
    std::string answer;
    std::cout<<"Do you want to pull another card:\t"; std::cin>> answer;
    while(answer!="yes" && answer != "Yes" && answer != "No"&& answer != "no")
        std::cout<<"Please select a god damn valid response\n";
    while(answer=="yes"||answer=="Yes")
    {
        user.currentCards.push_back(PullAnother());
        render(user.currentCards);
        user.handscore=CheckPoints(user.currentCards);
        if(CheckPoints(user.currentCards)>21) 
            {
                std::cout<<"\nComputer won!";
                break;
            } 
        std::cout<<"Do you want to pull another card:\t"; std::cin>> answer;
    }
    if(user.handscore > ComputerAlgorithm(computer.currentCards) && user.handscore<=21) std::cout<<"You won";
    else if(computer.handscore == user.handscore && user.handscore<=21) std::cout<<"\nDraw";
}
int main ()
{
    srand(time(NULL));
    for(int i{};i < 2; i++) initialize();
    render(user.currentCards);
    Playing(user.currentCards);
}