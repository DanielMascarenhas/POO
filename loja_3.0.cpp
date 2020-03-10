#include <iostream>
#include <stdlib.h>
#include <sstream>
using namespace std;


struct Cliente{
    int exist = 1;
    int potato = 0;
    int apple = 0;
    int rice = 0;
    Cliente(){
            cout << "cliente ja existente" << endl;

    }
    ~Cliente(){
        cout << "cliente saindo" << endl;
        cout << "potatos compradas: " << this->potato << endl;
        cout << "apples compradas: " << this->apple << endl;
        cout << "rices comprados: " << this->rice << endl;
    }
};


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
    Cliente * um_cara = new Cliente();
    string op , tipo;
    while(1){
        string line; 

        cout << "\n";

        cout<< "potato: " << dubom->potato << endl;
        cout << "apple: " << dubom->apple << endl;
        cout << "rice: "  << dubom->rice << endl;
        cout << "money: " << dubom->money<< "R$" << endl;
        cout << "\n";

        getline(cin, line);
        stringstream ss(line);

        // ss >> op >> nome;

        cout << "\n";

        if(um_cara == nullptr){
            cout << "tem ngm!!";
        }

        if(line == "potato"){
            dubom->sell_potato();
            um_cara->potato += 1;
        }
        else if(line == "apple"){
            dubom->sell_apple();
            um_cara->apple += 1;
        }
        else if(line == "rice"){
            dubom->sell_rice();
            um_cara->apple += 1;
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
        else if(line == "cliente"){
            if(um_cara->exist == 1){
                cout << "cliente ja existente" << endl;
            }
            else{
                Cliente * um_cara = new Cliente();
            }
        }
        else if(line == "saida"){
            if(um_cara->exist == 1)
            delete um_cara;
            else{
                cout << "sem cliente" << endl;
            }
        }
        else{
        	cout << "comando invalido";
        }        
        cout << "\n";

    }
    return 0;
}