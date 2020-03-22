#include <iostream>
//#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

class Pet{
	private:
	int energyMax, hungryMax, cleanMax;
	
	public:  
	int energy, hungry, clean;
	int  diamonds = 0;
	int age = 0;
	bool alive = true;
	
	/*	Pet(){
			
		}
		
		~Pet(){
			
		}	*/
		
	void setEnergy(int energia){
		this->energyMax = energia;
		this->energy = energia;
	}
	
	void setHungry(int saciedade){
		this->hungryMax = saciedade;
		this->hungry = saciedade;
	}
	
	void setClean(int limpeza){
		this->cleanMax = limpeza;
		this->clean = limpeza;
	}
	
	int getEnergy(){
		int ene;
		ene = this->energyMax;
		return ene;
	}
	int getHungry(){
		int hun;
		hun = this->hungryMax;
		return hun;
	}
	
	int getClean(){
		int cle;
		cle = this->cleanMax;
		return cle;
	}

};
//+ Pet(energyMax, hungryMax, cleanMax)


class Jogo{
	public:
	Pet * pet;
	//Pet * pet {nullptr};
	void iniciar(int energyMaximas=0, int hungryMaximas = 0, int cleanMaximas=0){
			Pet * pet = new Pet;
			pet->setEnergy(energyMaximas);
			pet->setHungry(hungryMaximas);
			pet->setClean(cleanMaximas);
	}
	void play(){
		if(pet->alive){
			pet->energy -= 2;
			pet->hungry -= 1;
			pet->clean -= 3;
			pet->diamonds += 1;
			pet->age += 1;
			}

	}
	void shower(){

			pet->energy -= 3;
			pet->hungry -= 1;
			pet->clean = pet->getClean();
			pet->diamonds += 0;
			pet->age += 2;
		

	}
		
	void sleep(){
		
		if(pet->energy + 5 > pet->getEnergy())
			cout << "PET SEM SONO" << endl;
		else{
			while(pet->energy < pet->getEnergy()){
				pet->energy += 1;
				pet->age += 1;
			}
		}
			
	}
		
	void eat(){
			pet->energy -= 1;
			pet->clean -= 2;
			pet->hungry += 4;
			pet->diamonds += 0;
			pet->age += 1;
			if(pet->hungry > pet->getHungry())
				pet->hungry = pet->getHungry();
			

	}
	void show(){
		cout << "Tomagochi" << endl;
		cout << "Energy : " << pet->energy << "/" << pet->getEnergy() << endl;
		cout << "Hungry : " << pet->hungry << "/" << pet->getHungry() << endl;
		cout << "Clean : " << pet->clean << "/" << pet->getClean() << endl;
		cout << "diamonds : " << pet->diamonds<< endl;
		cout << "age : " << pet->age <<endl;
	}
	
};
	
int main(){
	Jogo * tomagochi = new Jogo;
	int existencia = 0;
    string line;
    string cmd; 
    
	while(true){
		getline(cin, line);
    	stringstream ss(line);
	    ss >> cmd;
	    //getchar();
	    cout << "\n";
	    
	    if(cmd == "iniciar"){
	    	int energyMaxima, hungryMaxima, cleanMaxima;
	    	ss >> energyMaxima >> hungryMaxima >> cleanMaxima;
	    	if(existencia == 0){
		    	tomagochi->iniciar(energyMaxima, hungryMaxima, cleanMaxima);
	    		existencia = 1;
			}
			else{
				cout << "PET JA EXISTENTE";	
			}

	    }
	    else if(cmd == "play"){
	    	if(existencia == 1){
	    		tomagochi->play(); 
			} 
			else{
				"SEM PET";
			}
			
			if(tomagochi->pet->energy <= 0){
				cout << "PET MORREU DE CANSAÇO";
				tomagochi->pet->alive = false;
			}
			else if(tomagochi->pet->hungry <= 0){
				cout << "PET MORREU DE FOME";
				tomagochi->pet->alive = false;
			}
			else if(tomagochi->pet->clean <= 0){
				cout << "PET MORREU DE SUJEIRA";
				tomagochi->pet->alive = false;
			}			
				
		}
	    else if(cmd == "shower"){
	    	if(existencia == 1){
				tomagochi->shower(); 
			}
				
			else{
				"SEM PET";
			}
			
			if(tomagochi->pet->energy <= 0){
				cout << "PET MORREU DE CANSAÇO";
				tomagochi->pet->alive = false;
			}
			else if(tomagochi->pet->hungry <= 0){
				cout << "PET MORREU DE FOME";
				tomagochi->pet->alive = false;
			}
			else if(tomagochi->pet->clean <= 0){
				cout << "PET MORREU DE SUJEIRA";
				tomagochi->pet->alive = false;
			}			
			
		}	
	    else if(cmd == "eat"){
	    	if(existencia == 1){
	    		tomagochi->eat();
			} 
			else{
				"SEM PET";
			}

			if(tomagochi->pet->energy <= 0){
				cout << "PET MORREU DE CANSAÇO";
				tomagochi->pet->alive = false;
			}
			else if(tomagochi->pet->hungry <= 0){
				cout << "PET MORREU DE FOME";
				tomagochi->pet->alive = false;
			}
			else if(tomagochi->pet->clean <= 0){
				cout << "PET MORREU DE SUJEIRA";
				tomagochi->pet->alive = false;
			}
				    
		}    
	    else if(cmd == "sleep"){
	    	if(existencia == 1){
	    		tomagochi->sleep();
			}
				
			else{
				"SEM PET";
			}
			
			
			if(tomagochi->pet->energy <= 0){
				cout << "PET MORREU DE CANSAÇO";
				tomagochi->pet->alive = false;
			}
			else if(tomagochi->pet->hungry <= 0){
				cout << "PET MORREU DE FOME";
				tomagochi->pet->alive = false;
			}
			else if(tomagochi->pet->clean <= 0){
				cout << "PET MORREU DE SUJEIRA";
				tomagochi->pet->alive = false;
			}			
				 
		} 
	    else if(cmd == "show"){
	    	if(existencia == 1){
	    		tomagochi->show();
			}
				
			else{
				"SEM PET";
			}
			
			
				
		}
	    else if(cmd == "exit"){
	    	return 0;
		}
	    	
		
	}
	    
	return 0;
}








	













