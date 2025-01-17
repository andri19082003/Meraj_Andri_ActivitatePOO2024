#include <iostream>

using namespace std;

class Magazin {
private:
	string oras;
	int nrAngajati;
	float* salarii;
	float suprafata;
	const int anDeschidere;
	static int impozitM2;

public:
	Magazin() :anDeschidere(2024), nrAngajati(0) {
		this->oras = "Bucuresti";
		this->suprafata = 50;
		this->salarii = NULL;
	}

	void afisare() {
		cout << "Oras: " << this->oras << endl;
		cout << "Numar angajati: " << this->nrAngajati << endl;
		cout << "Suprafata: " << this->suprafata << endl;
		cout << "An deschidere: " << this->anDeschidere << endl;
		cout << "Impozit pe m2: " << Magazin::impozitM2 << endl;
	}

	Magazin(string oras, int nrAngajati, float suprafata, int an) :anDeschidere(an) {
		this->oras = oras;
		this->nrAngajati = nrAngajati;
		this->suprafata = suprafata;
		this->salarii = new float[nrAngajati];
		for (int i = 0; i < nrAngajati; i++) {
			this->salarii[i] = 2000 + i;
		}
	}

	Magazin(const Magazin& m) :anDeschidere(m.anDeschidere) {
		this->oras = m.oras;
		this->nrAngajati = m.nrAngajati;
		this->suprafata = m.suprafata;
		this->salarii = new float[m.nrAngajati];
		for (int i = 0; i < m.nrAngajati; i++) {
			this->salarii[i] = m.salarii[i];
		}
		this->suprafata = m.suprafata;
	}

	~Magazin() {
		if (this->salarii) {
			delete[]this->salarii;
		}
	}

	int getNrAngajati() {
		return this->nrAngajati;
	}

	void setNrAngajati(int nrAngajati, float* salarii) {
		if (nrAngajati > 0)
		{
			this->nrAngajati = nrAngajati;
			if (this->salarii != NULL) {
				delete[]this->salarii;
			}
			this->salarii = new float[this->nrAngajati];
			for (int i = 0; i < nrAngajati; i++) {
				this->salarii[i] = salarii[i];
			}
		}
	}

	float getSuprafata() {
		return this->suprafata;
	}

	void setSuprafata(float suprafata) {
		if (suprafata > 0) {
			this->suprafata = suprafata;
		}
	}

	float* getSalarii() {
		return this->salarii;
	}

	float getSalariu(int index) {
		if (index >= 0 && index < this->nrAngajati) {
			return this->salarii[index];
		}
	}

	float calculeazaSuprafataMedie() {
		if (this->nrAngajati != 0)
		{
			return this->suprafata / this->nrAngajati;
		}
		else {
			return 0;
		}
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

	bool operator>(Magazin m)
	{
		if (this->suprafata > m.suprafata)
			return this->suprafata == m.suprafata && this->nrAngajati == m.nrAngajati;
	}


	bool operator==(Magazin m)
	{
		return this->suprafata > m.suprafata && this->nrAngajati > m.nrAngajati;
	}


	friend ostream& operator<<(ostream& out, const Magazin& m)
	{
		out << "Oras : " << m.oras << '\n';
		out << "Numar angajati : " << m.nrAngajati << '\n';
		if (m.nrAngajati > 0)
			for (int i = 0; i < m.nrAngajati; i++)
			{
				cout << "Salariul angajatului " << i + 1 << " este " << m.salarii[i] << '\n';
			}
		out << "Suprafata : " << m.suprafata << '\n';
		out << "An deschidere : " << m.anDeschidere << '\n';
		out << "Impozit pe m2  : " << m.impozitM2 << '\n';
		return out;
	}

	friend istream& operator>>(istream& input, Magazin& m);


	explicit operator int()
	{
		return this->nrAngajati;
	}

	operator float()
	{
		float s = 0;
		for (int i = 0; i < this->nrAngajati; i++)
			s += this->salarii[i];
		return s;
	}

	float& operator[](int index) {
		if (index >= 0 && index < this->nrAngajati)
			return this->salarii[index];
		else
		{
			throw "index-ul este in afara limitelor";
		}
		//throw
		//try
		//catch 
	}
};
int Magazin::impozitM2 = 2;

istream& operator>>(istream& input, Magazin& m)
{
	cout << "Introdu orasul : ";
	input >> m.oras;
	cout << "Introdu numarul de angajati : ";
	input >> m.nrAngajati;
	if (m.salarii != NULL)
		delete[]m.salarii;
	if (m.nrAngajati > 0)
		m.salarii = new float[m.nrAngajati];
	for (int i = 0; i < m.nrAngajati; i++)
	{
		cout << " Salariul " << i + 1 << ":";
		input >> m.salarii[i];
	}
	cout << "Introdu suprafata : ";
	input >> m.suprafata;
	return input;

}



int main() {
	Magazin m1, m2;
	/*cout << "Sunt " << m1.getNrAngajati() << " angajati in cadrul magazinului." << endl;
	m1.setNrAngajati(6, new float[6] {2, 5, 4, 8, 6, 3});
	cout << "Sunt " << m1.getNrAngajati() << " angajati in cadrul magazinului." << endl;
	Magazin m2("Bucuresti", 3, 80, 2019);
	cout << endl << m2.getSalarii()[1] << endl;
	cout << m2.getSalariu(1) << endl;

	if (m1 > m2) {
		cout << "m1 este mai mare";

	}
	m2.setNrAngajati(5, new float[5] {2, 5, 4, 8, 6});

	cout << m2.getSalariu(3) << endl;
	Magazin m3 = m2;*/

	cin >> m1;

	//if (m1 > m2) { //m1.operator > (m2)
	//	cout << "m1 este mai mare";
	//}

	//if (m1 > m2) {
	//	cout << "m1 este egal cu m2";
	//}
	//else
	//{
	//	cout << "Sunt diferite.";
	//}

	cout << m1;

	int nrAngajati = (int)m2;

	float salariiTotale = m1;
	cout << '\n' << "Salarii totale : " << salariiTotale;

	try {
		cout << m1[1];
		m2[1] = 200;
		float s = m2[-9];
	}
	catch (const char* exceptie) {
		cout << endl << exceptie << '\n';
	}
	catch (...) {

	}

	return 0;
}