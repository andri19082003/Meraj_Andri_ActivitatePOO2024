#include<iostream>
using namespace std;
class Angajat {
protected:
	int marca;
	string nume;
	float salariu;
public:
	Angajat() {
		this->marca = 1200;
		this->nume = "Maria";
		this->salariu = 3029;

	}

	Angajat(int marca, string nume, float salariu) {
		this->marca = marca;
		this->nume = nume;
		this->salariu = salariu;


	}

	float getSalariu() {
		return this->salariu;
	}
	virtual float getVenitIncasat() = 0;
};

class Cercetator :public Angajat {
public:
	Cercetator(int marca, string nume, float salariu) :Angajat(marca, nume, salariu) {

	}
	float getVenitIncasat() {
		return this->salariu;
	}
};

class Manager :public Angajat {
private:
	int nrSubordonati;
	float sporPerAngajat;
public:
	Manager() :Angajat() {
		this->nrSubordonati = 0;
		this->sporPerAngajat = 0;
	}
	Manager(int nrSubordonati, float sporPerAngajat) :Angajat() {
		this->nrSubordonati = nrSubordonati;
		this->sporPerAngajat = sporPerAngajat;
	}
	float getSporConducere() {
		return this->nrSubordonati * this->sporPerAngajat;
	}
	
};

class ManagerDepartament :public Manager {
private:
	string numeDepartament;
	bool deCercetare;
public:
	ManagerDepartament() :Manager() {
		this->numeDepartament = "Departament";
		this->deCercetare = true;

	}
	ManagerDepartament(string numeDepartament,bool deCercetare, int nrSubordonati, float sporPerAngajat):Manager(nrSubordonati, sporPerAngajat) {
		this->numeDepartament = numeDepartament;
		this->deCercetare = deCercetare;

	}

	float getVenitIncasat() {
		float venit = this->salariu;
		venit += this->getSporConducere();
		if (this->deCercetare) {
			venit += (10 / 100) * salariu;
		}

		return venit;
	}
};


class ManagerDeProiect :public Manager {
private:
	string numeProiect;
	int nrZile;
	float sporZi;
public:
	ManagerDeProiect() :Manager() {
		this->numeProiect = "Anonim";
		this->nrZile = 0;
		this->sporZi = 0;
	 }

	ManagerDeProiect(string numeProiect, int nrZile, float spoZi, int nrSubordonati, float sporPerAngajat) :Manager(nrSubordonati,sporPerAngajat) {
		this->numeProiect = numeProiect;
		this->nrZile = nrZile;
		this->sporZi = spoZi;
	}
	float getVenitIncasat() {
		float venit = this->salariu;
		venit += this->getSporConducere();
		venit += (this->nrZile * this->sporZi);

		return venit;
	}
};

void main() {
	//Angajat a;
	//Manager m;

	ManagerDepartament md;
	ManagerDeProiect mp;

	Angajat* pointer;
	pointer = NULL;
	pointer = new ManagerDepartament();
	pointer->getVenitIncasat();

	int nrAngajati = 5;
	Angajat** vector = new Angajat*[nrAngajati];
	vector[0] = new ManagerDepartament();
	vector[1] = new ManagerDeProiect();
	vector[2] = new ManagerDeProiect("todo list",10,30,3,17);
	vector[3] = new ManagerDepartament("ai",true,10,15);
	vector[4] = new Cercetator(3783,"Ion",2100);

	for (int i = 0; i < nrAngajati; i++) {
		cout << (i + 1) << ". " << vector[i]->getVenitIncasat() << endl;
	}

}