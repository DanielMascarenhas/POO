#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class Espiral{
    public:

    string nome;
    int qtd;
    float preco;
    Espiral(string nome = "", int qtd = 0, float preco = 0){
        this->nome = nome; this->qtd = qtd, this->preco = preco;
    }
    
    std::string tostring(){
        if(nome == "")
            return " [ empty : " + to_string(this->qtd) + " U : " + to_string(this->preco) + " R$]";
        return " [ " + nome + " : " + to_string(this->qtd) + " U : " + to_string(this->preco) + " R$]";
    }
};

class Maquina{

        private:


    float saldo_cliente;
    float lucro;
    int espirais_maximas = 0;

        public:
    std::vector<Espiral> espirais;

    Maquina(int capacidade):
        espirais(capacidade){
        saldo_cliente = 0;
        lucro = 0;
    }
    void inserir_dinheiro(float number){
        saldo_cliente += number;
    }
    float pedir_troco(){
        float saldo_here = saldo_cliente;
        lucro += saldo_cliente;
        saldo_cliente = 0;
        return saldo_here;
    }
    void vender(int ind){
        saldo_cliente -= espirais[ind].preco;
        lucro += espirais[ind].preco;
        espirais[ind].qtd -= 1;
    }
    bool alterar_espiral(int indice, string nome, int qtd, float preco){
        Espiral * comida = new Espiral( nome , qtd , preco); 
        espirais[indice] = *comida;
        return true;
    }
    float get_saldo(){
        return saldo_cliente;
    }
    float get_lucro(){
        return lucro;
    }
    bool espiral_qtd(int indice){
        if(espirais[indice].qtd > 0)
            return true;
        else{
            return false;
        }
    }
    float espiral_preco(int indice){
        return espirais[indice].preco;
    }    
    int get_espirais_maximas(){
        return espirais_maximas;
    }
    void set_espirais_maximas(int number){
        espirais_maximas = number;
    }
    int tamanho(){
        return espirais.size()-1;
    }
    void to_string(){
        for(size_t i = 0  ; i < espirais.size(); i++)
	        cout << i << " :" << espirais[i].tostring() << endl;
    }
    bool registro_nome(int ind){
        if(espirais[ind].nome != "")
            return true;
        return false;
    }
    void deletar(int ind){
        espirais[ind].nome = "";
        espirais[ind].qtd = 0;
        espirais[ind].preco = 0;
    }
};

int main(){
    Maquina * maquina;
    int correcao = 0;
    string line;
    while(true){
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;

        if(cmd == "end")
            break;

        else if(cmd == "iniciar"){
            int espiralis = 0 ,max_espiralis =0;
            ss >> espiralis >> max_espiralis;
            maquina = new Maquina(espiralis);
            maquina->set_espirais_maximas(max_espiralis);
            correcao = 1;
        }

        else if(cmd == "dinheiro"){
            float dinheiro = 0;
            ss >> dinheiro;
            maquina->inserir_dinheiro(dinheiro);
        }

        else if(cmd == "troco"){
            cout << "recebido troco de : " << maquina->pedir_troco() << "R$" << endl;
        }
        else if(cmd == "vender"){
            int indice = 0;
            ss >> indice;
            if(indice > maquina->tamanho() || indice < 0)
                cout << "erro : indice invalido" << endl;
            else if ( !maquina->espiral_qtd(indice))
                cout << "erro : quantidade insufuciente" << endl;
                
            else if(maquina->get_saldo() < maquina->espiral_preco(indice)){
                cout << "saldo insuficiente" << endl;
            }
            else{
                maquina->vender(indice);
                cout << "produto " << indice << " vendido!" << endl;
            }
        }   

        else if(cmd == "inserir"){
            int indice = 0, qtd = 0;
            string nome = "";
            float preco = 0;
            ss >> indice >> nome >> qtd >> preco;

            if(indice > maquina->tamanho() || indice < 0){
                cout << "indice nao existente" << endl;
            }
            else if(maquina->registro_nome(indice)){
                cout << "erro : espiral ocupada" << endl;
            }
            else if(qtd > maquina->get_espirais_maximas()){
                cout << "erro : maximo de espirais excedido" << endl;
            }
            else{
                maquina->alterar_espiral(indice, nome, qtd, preco);
            }
        }
        else if(cmd == "deletar"){
            int indice = 0;
            ss >> indice;
            if(indice > maquina->tamanho() || indice < 0)
                cout << "erro : indice invalido" << endl;
            maquina->deletar(indice);
        }
        
        else{
            cout << "comando invalido" << endl;
        }         
        if(correcao){
            cout << "saldo : " << maquina->get_saldo() << "R$" << endl;
            maquina->to_string();
        }

    }








    /*Maquina maquina(5);
    maquina.alterar_espiral(0,"candy",3,1);
    maquina.inserir_dinheiro(5);
    maquina.vender(0);
    maquina.to_string();
    cout << maquina.get_saldo() << "    " << maquina.get_lucro() << endl;*/



    return 0;
}