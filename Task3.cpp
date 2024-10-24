#include <iostream>
#include <cstring>
using namespace std;


class Telefon;
class Televizor;
class Laptop;


class Telefon {
private:
   
    string marca;
    string model;
    int capacitateBaterie; 
    int* cameraResolution; 
    static int nrTelefoaneCreate;
    const int nrSenzori;

public:

    Telefon() : marca("Apple"), model("Iphone13"), capacitateBaterie(0), nrSenzori(5) {
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

    Telefon(const Telefon& other) : marca(other.marca), model(other.model), capacitateBaterie(other.capacitateBaterie), nrSenzori(other.nrSenzori) {
        cameraResolution = new int(*(other.cameraResolution));
    }


    ~Telefon() {
        delete cameraResolution;
    }


    string getMarca() const { return marca; }
    string getModel() const { return model; }
    int getCapacitateBaterie() const { return capacitateBaterie; }
    int getCameraResolution() const { return *cameraResolution; }


    void setMarca(string marca) { this->marca = marca; }
    void setModel(string model) { this->model = model; }
    void setCapacitateBaterie(int baterie) { this->capacitateBaterie = baterie; }
    void setCameraResolution(int rezolutie) { *cameraResolution = rezolutie; }


    static int getNrTelefoaneCreate() {
        return nrTelefoaneCreate;
    }


    static void afiseazaNrTelefoane() {
        cout << "Numarul de telefoane create: " << nrTelefoaneCreate << endl;
    }

 
    friend void afisareDetaliiTelefon(const Telefon& t);
    friend void actualizareCameraTelefon(Telefon& t, int rezolutieNoua);
};

int Telefon::nrTelefoaneCreate = 0;

void afisareDetaliiTelefon(const Telefon& t) {
    cout << "Telefon marca: " << t.marca << ", Model: " << t.model
        << ", Capacitate baterie: " << t.capacitateBaterie << "mAh"
        << ", Rezolutie camera: " << *t.cameraResolution << " MP" << endl;
}


void actualizareCameraTelefon(Telefon& t, int rezolutieNoua) {
    *t.cameraResolution = rezolutieNoua;
}


class Televizor {
private:
    
    string marca;
    int diagonala; 
    bool smart;    
    int* rezolutie; 
    static int nrTelevizoareCreate;
    const int nrPorturiHDMI;

public:

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


    Televizor(const Televizor& other) : marca(other.marca), diagonala(other.diagonala), smart(other.smart), nrPorturiHDMI(other.nrPorturiHDMI) {
        rezolutie = new int(*(other.rezolutie));
    }


    ~Televizor() {
        delete rezolutie;
    }


    string getMarca() const { return marca; }
    int getDiagonala() const { return diagonala; }
    bool isSmart() const { return smart; }
    int getRezolutie() const { return *rezolutie; }


    void setMarca(string marca) { this->marca = marca; }
    void setDiagonala(int diagonala) { this->diagonala = diagonala; }
    void setSmart(bool smart) { this->smart = smart; }
    void setRezolutie(int rezolutieNoua) { *rezolutie = rezolutieNoua; }

  
    static int getNrTelevizoareCreate() {
        return nrTelevizoareCreate;
    }


    friend void afisareDetaliiTelevizor(const Televizor& tv);
    friend void actualizareRezolutieTelevizor(Televizor& tv, int rezolutieNoua);
};


int Televizor::nrTelevizoareCreate = 0;


void afisareDetaliiTelevizor(const Televizor& tv) {
    cout << "Televizor marca: " << tv.marca << ", Diagonala: " << tv.diagonala
        << "\", Smart: " << (tv.smart ? "Da" : "Nu")
        << ", Rezolutie: " << *tv.rezolutie << "p" << endl;
}


void actualizareRezolutieTelevizor(Televizor& tv, int rezolutieNoua) {
    *tv.rezolutie = rezolutieNoua;
}


class Laptop {
private:

    string marca;
    string model;
    int capacitateRam; 
    int* capacitateStocare; 
    static int nrLaptopuriCreate;
    const int nrPorturiUSB;

public:

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

 
    Laptop(const Laptop& other) : marca(other.marca), model(other.model), capacitateRam(other.capacitateRam), nrPorturiUSB(other.nrPorturiUSB) {
        capacitateStocare = new int(*(other.capacitateStocare));
    }

 
    ~Laptop() {
        delete capacitateStocare;
    }

   
    string getMarca() const { return marca; }
    string getModel() const { return model; }
    int getCapacitateRam() const { return capacitateRam; }
    int getCapacitateStocare() const { return *capacitateStocare; }



    void setMarca(string marca) { this->marca = marca; }
    void setModel(string model) { this->model = model; }
    void setCapacitateRam(int ram) { this->capacitateRam = ram; }
    void setCapacitateStocare(int stocareNoua) { *capacitateStocare = stocareNoua; }

    static int getNrLaptopuriCreate() {
        return nrLaptopuriCreate;
    }

    friend void afisareDetaliiLaptop(const Laptop& l);
    friend void actualizareCapacitateStocare(Laptop& l, int stocareNoua);
};


int Laptop::nrLaptopuriCreate = 0;

void afisareDetaliiLaptop(const Laptop& l) {
    cout << "Laptop marca: " << l.marca << ", Model: " << l.model
        << ", RAM: " << l.capacitateRam << " GB, Stocare: " << *l.capacitateStocare << " GB" << endl;
}


void actualizareCapacitateStocare(Laptop& l, int stocareNoua) {
    *l.capacitateStocare = stocareNoua;
}


int main() {

    Telefon t1;("Huawei", "Huawei11");
    Telefon t2("Apple", "iPhone 14");
    Telefon t3("Samsung", "Galaxy S22", 5000, 108);

    afisareDetaliiTelefon(t1);
    afisareDetaliiTelefon(t2);
    afisareDetaliiTelefon(t3);

    actualizareCameraTelefon(t2, 64);
    afisareDetaliiTelefon(t2);

    Telefon::afiseazaNrTelefoane();

    Televizor tv1;("Finlux", "42");
    Televizor tv2("LG", 55);
    Televizor tv3("Samsung", 65, true, 2160);

    afisareDetaliiTelevizor(tv1);
    afisareDetaliiTelevizor(tv2);
    afisareDetaliiTelevizor(tv3);

    actualizareRezolutieTelevizor(tv3, 4320);
    afisareDetaliiTelevizor(tv3);

    Laptop l1;("HP", "HP1550");
    Laptop l2("Dell", "XPS 13");
    Laptop l3("Apple", "MacBook Pro", 16, 512);

    afisareDetaliiLaptop(l1);
    afisareDetaliiLaptop(l2);
    afisareDetaliiLaptop(l3);

    actualizareCapacitateStocare(l2, 1024);
    afisareDetaliiLaptop(l2);

    return 0;
}

