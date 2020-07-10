#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
 
using namespace std;


class Kid{
	private:
	string name;
	int age;
	public:
	Kid(string name, int age){
		this->name = name;
		this->age = age;
	}
	
	string getname(){
		return this->name;
	}
	
	int getage(){
		return this->age;
	}
	
	void tostring(){
		cout << getname() + ":" << getage() << " ";
	}
	
};

class Trampoline{ 
	public:
	vector<Kid> kidsWaiting;
	vector<Kid> kidsPlaying;
	
	void arrive(Kid * crianca){
		kidsWaiting.push_back(*crianca);
	}
	
	void show(){
	    for(size_t i = kidsWaiting.size()-1 ; i < -1; i--)
	        kidsWaiting[i].tostring();
	        cout << "-> [ ";
	    for(size_t i = kidsPlaying.size()-1 ; i < -1; i--)
	        kidsPlaying[i].tostring();
	        cout << "]" << endl;
	}
	
	void in(){
		if(!kidsWaiting.empty()){
			kidsPlaying.push_back(kidsWaiting[0]);
	    	int size;
			kidsWaiting.erase(kidsWaiting.begin()+0);
		}
	};
	
	void out(){
			if(!kidsPlaying.empty()){
			kidsWaiting.push_back(kidsPlaying[0]);
			kidsPlaying.erase(kidsPlaying.begin()+0);
		}
	}
	
};


int main(){
	Trampoline * trampoline = new Trampoline;
	Kid * kid ;
	
	string name;
	int age;
	
    string line;
    string cmd; 
    
	while(true){
		getline(cin, line);
    	stringstream ss(line);
	    ss >> cmd;
		
		if(cmd == "chegar"){
			ss >> name;
			ss >> age;
			kid = new Kid(name,age);
			trampoline->arrive(kid);			
		}
		
		else if(cmd == "show"){
			trampoline->show();
		}
		
		else if(cmd == "in"){
			trampoline->in();
		}		
	
		else if(cmd == "out"){
			trampoline->out();
		}
				
		else if (cmd == "exit")
			return 0;
		
	}
	
	return 0;
};





/*
- name: String
- age: int
--
+ toString()
+ getName(): String
+ getAge(): int
--
Kid(name, age)

class Trampoline:
- kidsWaiting: Kid[]
- kidsPlaying: Kid[]
--
+ toString(): String
+ arrive(kid: Kid)
+ show(): void
+ in(): void
+ out(): void


                
        }else if(cmd == "rmi"){
        	int ind,size;
        	ss >> ind;
        	size = vet.size();
        	if(ind >= 0 && ind <= size-1){
				vet.erase(vet.begin()+ind);	
			}
*/

