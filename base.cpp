#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm> 

using namespace std;

//mostra o vetor
void vet_show(vector<int>& vet){
    cout << "[ ";
    for(size_t i = 0; i < vet.size(); i++)
        cout << vet[i] << " ";
    cout << "]\n";
}

void vet_rshow(vector<int>& vet){
	cout << "[ ";
	for(int i = vet.size() - 1; i > -1 ; i--){
		cout << vet[i] << " ";
	}
	cout << "]\n";
}

//retorna o índice que contém value ou -1 se não existir
int vet_find(vector<int>& vet, int value){
    vector<int>::iterator it = find(vet.begin(),vet.end(),value);
    if(it != vet.end()){
        int index = distance(vet.begin(),it);
        cout << index << " ";
    }
    else{
        cout << -1 << " ";
    }
    return 0;
}
int new_vet_find(vector<int>& vet, int value){
    vector<int>::iterator it = find(vet.begin(),vet.end(),value);
    if(it != vet.end()){
        int index = distance(vet.begin(),it);
		return index;
    }

        return -1;
        
    }
int main(){
    vector<int> vet;
    string line;
    while(true){
        getline(cin, line);
        stringstream ss(line);
        cout << "$" << line << "\n";
        string cmd;
        ss >> cmd; //pegando o primeiro token
        if(line == "end"){
            break;
        }else if(cmd == "add"){
            int value;
            while(ss >> value) //enquanto conseguir retirar valores
                vet.push_back(value);
        }else if(cmd == "show"){
            vet_show(vet);
        }else if(cmd == "rshow"){
            vet_rshow(vet);
        }else if(cmd == "find"){
        	int value;
            cout << "$";
            while(ss >> value) //enquanto conseguir retirar valores
                vet_find(vet,value);

                cout <<"\n";
        }else if(cmd == "rmi"){
        	int ind,size;
        	ss >> ind;
        	size = vet.size();
        	if(ind >= 0 && ind <= size-1){
				vet.erase(vet.begin()+ind);	
			}
        	else{
        		cout << -1<< endl;        		
			}
        }else if(cmd == "ins"){
        	int value,ind,size;
        	ss >> value;
        	ss >> ind;
        	size = vet.size();
        	if(ind >= 0 && ind < size)
        		vet.insert(vet.begin()+ind,value);
        	else if(ind >= size)
        		vet.insert(vet.begin()+size,value);
        }else if(cmd == "rma"){
        	int value,size,boleano;
        	size = vet.size();
        	ss >> value;
        	boleano = new_vet_find(vet,value);
			while(boleano >= 0){
				vet.erase(vet.begin()+boleano);
				boleano = new_vet_find(vet,value);
			}
        }else{
            cout << "Comando invalido\n";
        }
    }
    return 0;
}
