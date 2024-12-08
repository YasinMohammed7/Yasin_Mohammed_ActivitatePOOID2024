#include <iostream>

using namespace std;

// Initialele numelui: Mohammed Mustafa (M)

class Manager {
private:
	static int nrManageri;
	const int id;
	char* companie;
	int salariu;
	string nume;

public:
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

	Manager(const Manager& man):id(++nrManageri) {
		this->nume = man.nume;
		this->salariu = man.salariu;
		if (this->companie != nullptr)
		{
			this->companie = new char[strlen(man.companie) + 1];
			strcpy_s(this->companie, strlen(man.companie) + 1, man.companie);
		} else {
			this->companie = nullptr;
		}
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

	int getSalariu() {
		return salariu;
	}

	string getCompanie() {
		return companie;
	}

	static int getNrManageri() {
		return nrManageri;
	}

	void setCompanie(const char* companie) {
		this->companie = new char[strlen(companie) + 1];
		strcpy_s(this->companie, strlen(companie) + 1, companie);
	}
};

int Manager::nrManageri = 0;

class Motor {
private:
	static int nrMotoare;
	const int id;
	string marca;
	int nrComponente;
	int* preturi;
public:
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

	Motor(const Motor& m):id(++nrMotoare) {
		this->marca = m.marca;
		this->nrComponente = m.nrComponente;
		this->preturi = new int[m.nrComponente];
		for (int i = 0; i < m.nrComponente; i++)
		{
			this->preturi[i] = m.preturi[i];
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

	int getNrComponente() {
		return nrComponente;
	}

	int* getPreturi() {
		return preturi;
	}

	static int getNrMotoare() {
		return nrMotoare;
	}

	void setPreturi(const int* preturi, int nrComponente) {
		if (nrComponente > 0) {
			this->nrComponente = nrComponente;
			if (this->preturi != nullptr) {
				delete[]this->preturi;
			}
			this->preturi = new int[nrComponente];
			for (int i = 0; i < nrComponente; i++)
			{
				this->preturi[i] = preturi[i];
			}
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
	man2.setCompanie("BCR");
	cout << "Nr. total manageri: " << Manager::getNrManageri() << endl;
	cout << "Salariul " << man2.getSalariu() << " este asigurat de compania " << man2.getCompanie() << endl << endl;

	cout << "Clasa motor" << endl;
	Motor m1;
	m1.afisare();
	int* preturi = new int[3] {4, 5, 6};

	Motor m2(3, "mertan", preturi);
	m2.afisare();
	m2.setPreturi(new int[6] {2, 5, 4, 8, 6, 3}, 6);
	cout << "Nr. total motociclete: " << Motor::getNrMotoare() << endl;
	cout << "Preturile pentru cele " << m2.getNrComponente() << " componente sunt: ";
	 for (int i = 0; i < m2.getNrComponente(); i++) {
			cout << m2.getPreturi()[i]<<", ";
	}
	

	delete[] preturi;
}