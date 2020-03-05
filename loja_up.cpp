#include <iostream>
#include <stdlib.h>
#include <sstream>
using namespace std;

struct Loja{
    int potato = 0;
    int apple = 0;
    int rice = 0;
    int money = 10;

    bool sell_potato(){
        if(this->potato > 0){
            this->potato -= 1;
            this->money += 3;
            cout << "vendido" <<endl;
            return true;
        }
        cout << "sem potato" <<endl;
        return false;
    }

    bool sell_apple(){
        if(this->apple > 0){
            this->apple -= 1;
            this->money += 2;
            cout << "vendido" <<endl;
            return true;
        }
        cout << "sem apple" <<endl;
        return false;
    }

    bool sell_rice(){
        if(this->rice > 0){
            this->rice -= 1;
            this->money += 1;
            cout << "vendido" <<endl;
            return true;
        }
        cout << "sem rice" <<endl;
        return false;
    }
    bool buy_potato(){
        if(this->money > 9){
            this->money -= 10;
            this->potato += 6;
            cout << "potato buy" <<endl;
            return true;
        }
        cout << "money insufuciente" <<endl;
        return false;
    }
    bool buy_apple(){
        if(this->money > 5){
            this->money -= 5;
            this->apple += 5;
            cout << "potato buy" <<endl;
            return true;
        }
        cout << "money insufuciente" <<endl;
        return false;
    }

    bool buy_rice(){
        if(this->money > 3){
            this->money -= 3;
            this->rice += 10;
            cout << "potato buy" <<endl;
            return true;
        }
        cout << "money insufuciente" <<endl;
        return false;
    }

};


int main(){
    Loja * dubom  = new Loja();
    string op , tipo;
    while(1){
        string line; 

        cout << "\n";

        cout<< "potato: " << dubom->potato <<endl;
        cout << "apple: " << dubom->apple <<endl;
        cout << "rice: "  << dubom->rice <<endl;
        cout << "money: " << dubom->money<< "R$" <<endl;

        cout << "\n";

        getline(cin, line);
        stringstream ss(line);


        cout << "\n";

        if(line == "potato"){
            dubom->sell_potato();
        }
        else if(line == "apple"){
            dubom->sell_apple();
        }
        else if(line == "rice"){
            dubom->sell_rice();
        }
        else if(line == "buy_potato"){
            dubom->buy_potato();
        }
        else if(line == "buy_apple"){
            dubom->buy_apple();
        }
        else if(line == "buy_rice"){
            dubom->buy_rice();
        }
        else if(line == "exit"){
        	return 0;
        }
        else{
        	cout << "comando invalido";
        }        
        cout << "\n";

    }
    return 0;
}