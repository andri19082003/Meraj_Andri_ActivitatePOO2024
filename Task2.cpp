#include <iostream>
#include <cstring>
using namespace std;


class Telefon {
public:
   
    string marca;
    string model;
    int capacitateBaterie; 
    int* cameraResolution; 
    static int nrTelefoaneCreate;
    const int nrSenzori;

    Telefon() : marca("Apple"), model("Iphone13"), capacitateBaterie(100), nrSenzori(5) {
        cameraResolution = new int(0);
        nrTelefoaneCreate++;
    }

    Telefon(string marca, string model) : marca(marca), model(model), capacitateBaterie(4000), nrSenzori(5) {
        cameraResolution = new int(12);
        nrTelefoaneCreate++;
    }

    Telefon(string marca, string model, int baterie, int rezolutieCamera) : marca(marca), model(model), capacitateBaterie(baterie), nrSenzori(5) {
        cameraResolution = new int(rezolutieCamera);
        nrTelefoaneCreate++;
    }

    ~Telefon() {
        delete cameraResolution;
    }

    static void afiseazaNrTelefoane() {
        cout << "Numarul de telefoane create: " << nrTelefoaneCreate << endl;
    }
};


int Telefon::nrTelefoaneCreate = 0;


class Televizor {
public:
   
    string marca;
    int diagonala; 
    bool smart;    
    int* rezolutie; 
    static int nrTelevizoareCreate;
    const int nrPorturiHDMI;

    Televizor() : marca("LG"), diagonala(42), smart(false), nrPorturiHDMI(2) {
        rezolutie = new int(0);
        nrTelevizoareCreate++;
    }

    Televizor(string marca, int diagonala) : marca(marca), diagonala(diagonala), smart(true), nrPorturiHDMI(2) {
        rezolutie = new int(1080);
        nrTelevizoareCreate++;
    }

    Televizor(string marca, int diagonala, bool smart, int rezolutieEcran) : marca(marca), diagonala(diagonala), smart(smart), nrPorturiHDMI(2) {
        rezolutie = new int(rezolutieEcran);
        nrTelevizoareCreate++;
    }

    ~Televizor() {
        delete rezolutie;
    }

   
    static void afiseazaNrTelevizoare() {
        cout << "Numarul de televizoare create: " << nrTelevizoareCreate << endl;
    }
};

int Televizor::nrTelevizoareCreate = 0;


class Laptop {
public:
    
    string marca;
    string model;
    int capacitateRam;   
    int* capacitateStocare; 
    static int nrLaptopuriCreate;  
    const int nrPorturiUSB;

   
    Laptop() : marca("HP"), model("HP1550"), capacitateRam(4), nrPorturiUSB(3) {
        capacitateStocare = new int(0);
        nrLaptopuriCreate++;
    }

    Laptop(string marca, string model) : marca(marca), model(model), capacitateRam(8), nrPorturiUSB(3) {
        capacitateStocare = new int(256);
        nrLaptopuriCreate++;
    }

    Laptop(string marca, string model, int ram, int stocare) : marca(marca), model(model), capacitateRam(ram), nrPorturiUSB(3) {
        capacitateStocare = new int(stocare);
        nrLaptopuriCreate++;
    }

  
    ~Laptop() {
        delete capacitateStocare;
    }


    static void afiseazaNrLaptopuri() {
        cout << "Numarul de laptopuri create: " << nrLaptopuriCreate << endl;
    }
};


int Laptop::nrLaptopuriCreate = 0;


int main() {
   
    Telefon t1;
    Telefon t2("Apple", "iPhone 14");
    Telefon t3("Samsung", "Galaxy S22", 5000, 108);
    cout << "Telefon 1: " << t1.marca << ", " << t1.model << ", Baterie: " << t1.capacitateBaterie << "mAh, Rezolutie camera: " << *t1.cameraResolution << "MP" << endl;
    cout << "Telefon 2: " << t2.marca << ", " << t2.model << ", Baterie: " << t2.capacitateBaterie << "mAh, Rezolutie camera: " << *t2.cameraResolution << "MP" << endl;
    cout << "Telefon 3: " << t3.marca << ", " << t3.model << ", Baterie: " << t3.capacitateBaterie << "mAh, Rezolutie camera: " << *t3.cameraResolution << "MP" << endl;
    Telefon::afiseazaNrTelefoane();

    
    Televizor tv1;
    Televizor tv2("LG", 55);
    Televizor tv3("Samsung", 65, true, 2160);
    cout << "Televizor 1: " << tv1.marca << ", Diagonala: " << tv1.diagonala << "\", Smart: " << tv1.smart << ", Rezolutie: " << *tv1.rezolutie << "p" << endl;
    cout << "Televizor 2: " << tv2.marca << ", Diagonala: " << tv2.diagonala << "\", Smart: " << tv2.smart << ", Rezolutie: " << *tv2.rezolutie << "p" << endl;
    cout << "Televizor 3: " << tv3.marca << ", Diagonala: " << tv3.diagonala << "\", Smart: " << tv3.smart << ", Rezolutie: " << *tv3.rezolutie << "p" << endl;
    Televizor::afiseazaNrTelevizoare();

  
    Laptop l1;
    Laptop l2("Dell", "XPS 13");
    Laptop l3("Apple", "MacBook Pro", 16, 512);
    cout << "Laptop 1: " << l1.marca << ", " << l1.model << ", RAM: " << l1.capacitateRam << "GB, Stocare: " << *l1.capacitateStocare << "GB" << endl;
    cout << "Laptop 2: " << l2.marca << ", " << l2.model << ", RAM: " << l2.capacitateRam << "GB, Stocare: " << *l2.capacitateStocare << "GB" << endl;
    cout << "Laptop 3: " << l3.marca << ", " << l3.model << ", RAM: " << l3.capacitateRam << "GB, Stocare: " << *l3.capacitateStocare << "GB" << endl;
    Laptop::afiseazaNrLaptopuri();

    return 0;
}
