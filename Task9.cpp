#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Clasa abstracta Vehicul
class Vehicul {
public:
    virtual void afisare() const = 0; 
    virtual float calculeazaPretTotal() const = 0; 
    virtual ~Vehicul() {} 
};

// Clasa abstracta Motor
class Motor {
public:
    virtual string tipMotor() const = 0; 
    virtual ~Motor() {}
};


class MotorElectric : public Motor {
public:
    string tipMotor() const override {
        return "Electric";
    }
};


class MotorDiesel : public Motor {
public:
    string tipMotor() const override {
        return "Diesel";
    }
};


class Masina : public Vehicul {
protected:
    int nrRoti;
    string marca;
    float pret;
    Motor* motor; 

public:
    Masina() : nrRoti(4), marca("Dacia"), pret(5000), motor(new MotorDiesel()) {}

    Masina(int nrRoti, string marca, float pret, Motor* motor) : nrRoti(nrRoti), marca(marca), pret(pret), motor(motor) {}

    virtual ~Masina() {
        delete motor;
    }

    void afisare() const override {
        cout << "Masina: " << marca << ", Nr roti: " << nrRoti << ", Pret: " << pret << ", Motor: " << motor->tipMotor() << endl;
    }

    float calculeazaPretTotal() const override {
        return pret + pret * 0.19f; 
    }
};


class Tir : public Masina {
private:
    float tonaj;

public:
    Tir() : Masina(10, "Volvo", 100000, new MotorDiesel()), tonaj(20) {}

    Tir(int nrRoti, string marca, float pret, Motor* motor, float tonaj) : Masina(nrRoti, marca, pret, motor), tonaj(tonaj) {}

    void afisare() const override {
        cout << "Tir: " << marca << ", Nr roti: " << nrRoti << ", Pret: " << pret << ", Tonaj: " << tonaj << ", Motor: " << motor->tipMotor() << endl;
    }

    float calculeazaPretTotal() const override {
        return pret + pret * 0.19f; 
    }
};

int main() {
    vector<Vehicul*> vehicule;

    vehicule.push_back(new Masina(4, "Dacia", 5000, new MotorElectric()));
    vehicule.push_back(new Masina(4, "Tesla", 70000, new MotorElectric()));
    vehicule.push_back(new Tir(10, "Volvo", 100000, new MotorDiesel(), 25));
    vehicule.push_back(new Tir(12, "Scania", 120000, new MotorDiesel(), 30));

  
    for (size_t i = 0; i < vehicule.size(); i++) {
        vehicule[i]->afisare();
        cout << "Pret total (cu TVA): " << vehicule[i]->calculeazaPretTotal() << "\n";
        cout << "-----------------------------\n";
    }

 
    for (size_t i = 0; i < vehicule.size(); i++) {
        delete vehicule[i];
    }

    return 0;
}
