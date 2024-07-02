#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Veiculo {
private:
    string placa;

public:
    Veiculo() {}
    virtual ~Veiculo() {}

    void setPlaca(string placa) { this->placa = placa; }
    string getPlaca() const { return placa; }

    virtual void mostrarInfos() const = 0;  // Método virtual puro
};

class Moto : public Veiculo {
private:
    float Valor;
    int Ano;
    float Estado;

public:
    void setInfos(float Valor, int Ano, float Estado) {
        this->Valor = Valor;
        this->Ano = Ano;
        this->Estado = Estado;
    }

    void mostrarInfos() const override {
        cout << "Moto - Placa: " << getPlaca() << ", Valor: " << Valor << ", Ano: " << Ano << ", Estado: " << Estado << endl;
    }
};

class Carro : public Veiculo {
private:
    float Valor;
    int Ano;
    float Estado;

public:
    void setInfos(float Valor, int Ano, float Estado) {
        this->Valor = Valor;
        this->Ano = Ano;
        this->Estado = Estado;
    }

    void mostrarInfos() const override {
        cout << "Carro - Placa: " << getPlaca() << ", Valor: " << Valor << ", Ano: " << Ano << ", Estado: " << Estado << endl;
    }
};

int main() {
  
    vector<Veiculo*> veiculos;
  
    string placa;
    float valor;
    int ano;
    float estado;
    char tipo;

    while (true) {
      
        cout << "Deseja criar uma Moto (M) ou um Carro (C)? (M/C): ";
        cin >> tipo;

        if (tipo == 'M' || tipo == 'm') {
          
            Moto* moto = new Moto();
          
            cout << "Digite a placa da Moto: ";
            cin >> placa;
            moto->setPlaca(placa);

            cout << "Digite o valor da Moto: ";
            cin >> valor;

            cout << "Digite o ano da Moto: ";
            cin >> ano;

            cout << "Digite o estado da Moto (de 0.0 a 1.0): ";
            cin >> estado;

            moto->setInfos(valor, ano, estado);

            veiculos.push_back(moto);

            cout << "Moto criada com as seguintes informações:" << endl;
            moto->mostrarInfos();
          
        } else if (tipo == 'C' || tipo == 'c') {
          
            Carro* carro = new Carro();
          
            cout << "Digite a placa do Carro: ";
            cin >> placa;
            carro->setPlaca(placa);

            cout << "Digite o valor do Carro: ";
            cin >> valor;

            cout << "Digite o ano do Carro: ";
            cin >> ano;

            cout << "Digite o estado do Carro (de 0.0 a 1.0): ";
            cin >> estado;

            carro->setInfos(valor, ano, estado);

            veiculos.push_back(carro);

            cout << "Carro criado com as seguintes informações:" << endl;
            carro->mostrarInfos();
          
        } else {
          
            cout << "Opção inválida. Saindo do programa." << endl;
            break;
          
        }

        char continuar;
        cout << "Deseja criar outro veículo? (S/N): ";
        cin >> continuar;

        if (continuar != 'S' && continuar != 's') {
            break;
        }
    }

    cout << "\nVeículos criados:\n";
    for (auto veiculo : veiculos) {
        veiculo->mostrarInfos();
        delete veiculo;
    }
  
    veiculos.clear();

    return 0;
}

