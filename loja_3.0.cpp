#include <iostream>
#include <stdlib.h>
#include <sstream>
using namespace std;


class Cliente{
    public:
    int exist = 1;
    
    int potato = 0;
    int apple = 0;
    int rice = 0;
    Cliente(){
            cout << "cliente entrando" << endl;

    }
    ~Cliente(){
        cout << "cliente saindo" << endl;
        cout << "potatos compradas: " << this->potato << endl;
        cout << "apples compradas: " << this->apple << endl;
        cout << "rices comprados: " << this->rice << endl;
    }
};


class Loja{
    public:
    Cliente * um_cara {nullptr};
    int potato = 0;
    int apple = 0;
    int rice = 0;
    int money = 10;

    int criar_cliente(){
		if(um_cara != nullptr){
        	cout << "cliete ja existente" << endl;
        }
        else{
            this->um_cara = new Cliente();
        }
	    return 0;
    }
    bool deletar_cliente(){
	    if(um_cara != nullptr){
            delete um_cara;
            return true;
		}
        else{
                cout << "sem cliente" << endl;
                return false;
        }
    }

    bool sell_potato(){
		if(um_cara == nullptr){
        	cout << "cliente nao existente" << endl;
			return false;
        }

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
	if(um_cara == nullptr){
        	cout << "cliente nao existente" << endl;
		return false;
        }
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
	if(um_cara == nullptr){
        	cout << "cliente nao existente" << endl;
		return false;
        }
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
    //string op , tipo;
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
        string cmd; 
        cout << "\n";
        ss >> cmd;
        if(cmd == "potato"){
            if(dubom->sell_potato())
                dubom->um_cara->potato += 1;
        }
        else if(cmd == "apple"){
            if(dubom->sell_apple())
                dubom->um_cara->apple += 1;
        }
        else if(cmd == "rice"){
            if(dubom->sell_rice())
                dubom->um_cara->apple += 1;
        }
        else if(cmd == "buy_potato"){
            dubom->buy_potato();
        }
        else if(cmd == "buy_apple"){
            dubom->buy_apple();
        }
        else if(cmd == "buy_rice"){
            dubom->buy_rice();
        }
        else if(cmd == "exit"){
        	return 0;
        }
        else if(cmd == "cliente"){
            
			dubom->criar_cliente();





        }
        else if(cmd == "saida"){

			dubom->deletar_cliente();
        }
        else{
        	cout << "comando invalido";
        }        
        cout << "\n";

        }
    delete dubom;  
    return 0;
}
