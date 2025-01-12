#include <iostream>
#include <string>

using namespace std;

// Clasa Magazin
class Magazin {
private:
    string oras;
    int nrAngajati;
    float* salarii;
    float suprafata;
    const int anDeschidere;
    static int impozitM2;

public:
    // Constructorul implicit
    Magazin() : anDeschidere(2024), nrAngajati(0), salarii(nullptr), suprafata(50) {
        this->oras = "Bucuresti";
    }

    // Constructor cu parametri
    Magazin(string oras, int nrAngajati, float suprafata, int an)
        : anDeschidere(an), oras(oras), nrAngajati(nrAngajati), suprafata(suprafata) {
        this->salarii = new float[nrAngajati];
        for (int i = 0; i < nrAngajati; i++) {
            this->salarii[i] = 2000 + i;
        }
    }

    // Constructor de copiere
    Magazin(const Magazin& m)
        : anDeschidere(m.anDeschidere), oras(m.oras), nrAngajati(m.nrAngajati), suprafata(m.suprafata) {
        this->salarii = new float[m.nrAngajati];
        for (int i = 0; i < m.nrAngajati; i++) {
            this->salarii[i] = m.salarii[i];
        }
    }

    // Destructor
    ~Magazin() {
        if (this->salarii) {
            delete[] this->salarii;
        }
    }

    // Operatorul de atribuire
    Magazin& operator=(const Magazin& m) {
        if (this != &m) {
            this->oras = m.oras;
            this->nrAngajati = m.nrAngajati;
            this->suprafata = m.suprafata;

            if (this->salarii) {
                delete[] this->salarii;
            }
            this->salarii = new float[m.nrAngajati];
            for (int i = 0; i < m.nrAngajati; i++) {
                this->salarii[i] = m.salarii[i];
            }
        }
        return *this;
    }

    // Getters și setters
    int getNrAngajati() const { return this->nrAngajati; }
    float getSuprafata() const { return this->suprafata; }

    void afisare() const {
        cout << "Oras: " << this->oras << endl;
        cout << "Numar angajati: " << this->nrAngajati << endl;
        cout << "Suprafata: " << this->suprafata << endl;
        cout << "An deschidere: " << this->anDeschidere << endl;
        cout << "Impozit pe m2: " << Magazin::impozitM2 << endl;
    }

    static void modificaImpozit(int impozit) {
        if (impozit > 0) {
            Magazin::impozitM2 = impozit;
        }
    }

    static float calculeazaSuprafataTotala(Magazin* vector, int nrMagazine) {
        float suma = 0;
        for (int i = 0; i < nrMagazine; i++) {
            suma += vector[i].suprafata;
        }
        return suma;
    }
};

int Magazin::impozitM2 = 2;

// Clasa Departament
class Departament {
private:
    string nume;
    int nrAngajati;
    Magazin magazin; // Atribut de tip Magazin (relatie has-a)

public:
    // Constructor implicit
    Departament() : nume("Necunoscut"), nrAngajati(0), magazin() {}

    // Constructor cu parametri
    Departament(string nume, int nrAngajati, Magazin magazin)
        : nume(nume), nrAngajati(nrAngajati), magazin(magazin) {}

    // Constructor de copiere
    Departament(const Departament& d)
        : nume(d.nume), nrAngajati(d.nrAngajati), magazin(d.magazin) {}

    // Destructor
    ~Departament() {}

    // Operatorul de atribuire
    Departament& operator=(const Departament& d) {
        if (this != &d) {
            this->nume = d.nume;
            this->nrAngajati = d.nrAngajati;
            this->magazin = d.magazin;
        }
        return *this;
    }

    // Metode de acces (getters și setters)
    string getNume() const { return this->nume; }
    void setNume(string nume) { this->nume = nume; }

    int getNrAngajati() const { return this->nrAngajati; }
    void setNrAngajati(int nrAngajati) { this->nrAngajati = nrAngajati; }

    Magazin getMagazin() const { return this->magazin; }
    void setMagazin(Magazin m) { this->magazin = m; }

    // Afisare detalii departament
    void afisare() const {
        cout << "Nume Departament: " << this->nume << endl;
        cout << "Numar angajati: " << this->nrAngajati << endl;
        cout << "Detalii magazin: " << endl;
        this->magazin.afisare();
    }
};

int main() {
    // Crearea unui obiect Magazin
    Magazin m1("Bucuresti", 10, 300, 2022);

    // Crearea unui obiect Departament
    Departament d1("Vanzari", 5, m1);

    // Crearea unui alt Departament prin copiere
    Departament d2 = d1;

    // Modificarea unui departament
    Departament d3;
    d3 = d1;

    // Afisarea detaliilor
    d1.afisare();
    cout << endl;
    d2.afisare();
    cout << endl;
    d3.afisare();

    return 0;
}
