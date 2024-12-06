#include <iostream>

using namespace std;

// Initialele numelui: Mohammed Mustafa (M)

class Manager {
public:
	static int nrManageri;
	const int id;
	char* companie;
	int salariu;
	string nume;

	Manager():id(++nrManageri) {
		this->companie = nullptr;
		this->salariu = 0;
		this->nume = "N/A";
	}

	Manager(string nume, int salariu, const char* companie):id(++nrManageri) {
		this->nume = nume;
		this->salariu = salariu;
		this->companie = new char[strlen(companie) + 1];
		strcpy_s(this->companie, strlen(companie) + 1, companie);
	}

	~Manager() {
		if (this->companie != nullptr)
		{
			delete[] this->companie;
		}
	}

	void afisare() {
		cout << "Managerul " << this->nume
			<< " are salariul " << this->salariu
			<< " si lucreaza la compania " << (this->companie != nullptr ? this->companie : "N/A") << endl;
		
	}
};

int Manager::nrManageri = 0;

class Motor {
public:
	static int nrMotoare;
	const int id;
	string marca;
	int nrComponente;
	int* preturi;

	Motor():id(++nrMotoare) {
		this->marca = "N/A";
		this->nrComponente = 0;
		this->preturi = nullptr;
	}

	Motor(int nrComponente, string marca, const int* preturi) :id(++nrMotoare) {
		this->marca = marca;
		this->nrComponente = nrComponente;
		this->preturi = new int[nrComponente];
		for (int i = 0; i < nrComponente; i++)
		{
			this->preturi[i] = preturi[i];
		}
	}

	~Motor() {
		if (this->preturi != nullptr)
		{
			delete[] this->preturi;
		}
	}

	void afisare() {
		cout << "Motorul cu marca " << this->marca
			<< " are " << this->nrComponente << " componente"
			<< " cu preturile urmatoare: " <<endl;
		for (int i = 0; i < this->nrComponente; i++)
		{
			cout << (i + 1) << ". " << this->preturi[i] << endl;
		}
	}

};

int Motor::nrMotoare = 0;

int main() {
	cout << "Clasa manager" <<endl;
	Manager man1;
	man1.afisare();
	Manager man2("Alex", 4000, "unicredit");
	man2.afisare();

	cout << "Clasa motor" << endl;
	Motor m1;
	m1.afisare();
	int* preturi = new int[3] {4, 5, 6};

	Motor m2(3, "mertan", preturi);
	m2.afisare();

	delete[] preturi;
}