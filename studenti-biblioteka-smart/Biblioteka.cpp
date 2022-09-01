#include <iostream>
#include <memory>
#include "Biblioteka.h"


Biblioteka::Biblioteka(const Biblioteka& b) {
	if (&b != this) {
		for (auto a : b.studenti) {
			std::shared_ptr<Student> s = std::make_shared<Student>(
				a.second->broj_indeksa, a.second->godina_studija, a.second->adresa,
				a.second->telefon, a.second->ime, a.second->prezime);
			studenti[a.first] = s;
		}
		for (auto a : b.knjige) {
			std::shared_ptr<Knjiga> k = std::make_shared<Knjiga>(
				a.second->DajNaslov(), a.second->DajAutora(), a.second->DajZanr(),
				a.second->DajGodinuIzdavanja());
			k->ZaduziKnjigu(*a.second->DajPokKodKogaJe());
			knjige[a.first] = k;
		}
	}
}

Biblioteka::Biblioteka(Biblioteka&& b) {
	std::swap(studenti, b.studenti);
	std::swap(knjige, b.knjige);
}
Biblioteka& Biblioteka::operator=(const Biblioteka& b) {
	if (&b != this) {
		for (auto a : b.studenti) {
			std::shared_ptr<Student> s = std::make_shared<Student>(
				a.second->broj_indeksa, a.second->godina_studija, a.second->adresa,
				a.second->telefon, a.second->ime, a.second->prezime);
			studenti[a.first] = s;
		}
		for (auto a : b.knjige) {
			std::shared_ptr<Knjiga> k = std::make_shared<Knjiga>(
				a.second->DajNaslov(), a.second->DajAutora(), a.second->DajZanr(),
				a.second->DajGodinuIzdavanja());
			k->ZaduziKnjigu(*a.second->DajPokKodKogaJe());
			knjige[a.first] = k;
		}
	}
	return *this;
}

Biblioteka& Biblioteka::operator=(Biblioteka&& b) {
	std::swap(studenti, b.studenti);
	std::swap(knjige, b.knjige);
	return *this;
}

void Biblioteka::RegistrirajNovogStudenta(int br_indeksa, std::string ime,
	std::string prezime,
	int godina_studija,
	std::string adresa,
	std::string br_telefona) {
	if (!studenti.empty() && studenti.find(br_indeksa) != studenti.end()) {
		throw std::logic_error("Vec postoji student s tim brojem indeksa");
	}
	std::shared_ptr<Student> s = std::make_shared<Student>(
		br_indeksa, godina_studija, adresa, br_telefona, ime, prezime);
	studenti[br_indeksa] = s;
}

void Biblioteka::RegistrirajNovuKnjigu(int br_evidencije, std::string naslov,
	std::string ime_pisca, std::string zanr,
	int god_izdavanja) {
	if (!knjige.empty() && knjige.find(br_evidencije) != knjige.end()) {
		throw std::logic_error("Knjiga s tim evidencijskim brojem vec postoji");
	}
	std::shared_ptr<Knjiga> k =
		std::make_shared<Knjiga>(naslov, ime_pisca, zanr, god_izdavanja);
	knjige[br_evidencije] = k;
}

Student& Biblioteka::NadjiStudenta(int br_indeksa) {
	if (studenti.find(br_indeksa) == studenti.end()) {
		throw std::logic_error("Student nije nadjen");
	}
	return *studenti[br_indeksa];
}

Knjiga& Biblioteka::NadjiKnjigu(int br_evidencije) {
	if (knjige.find(br_evidencije) == knjige.end()) {
		throw std::logic_error("Knjiga nije nadjena");
	}
	return *knjige[br_evidencije];
}

void Biblioteka::IzlistajStudente() const {
	for (auto a : studenti) {
		std::cout << "Broj indeksa: " << a.first
			<< "\nIme i prezime: " << a.second->ime << " "
			<< a.second->prezime
			<< "\nGodina studija: " << a.second->godina_studija
			<< "\nAdresa: " << a.second->adresa
			<< "\nBroj telefona: " << a.second->telefon << std::endl << std::endl;
	}
}

void Biblioteka::IzlistajKnjige() const {
	for (auto a : knjige) {
		std::cout << "Evidencijski broj: " << a.first
			<< "\nNaslov: " << a.second->DajNaslov()
			<< "\nPisac: " << a.second->DajAutora()
			<< "\nZanr: " << a.second->DajZanr()
			<< "\nGodina izdavanja: " << a.second->DajGodinuIzdavanja();
		if (a.second->DaLiJeZaduzena()) {
			std::cout << "\nZaduzena kod studenta: " << a.second->DajKodKogaJe().ime
				<< " " << a.second->DajKodKogaJe().prezime << " ("
				<< a.second->DajKodKogaJe().broj_indeksa << ")" << std::endl;
		}
		else {
			std::cout << std::endl;
		}
	}
}

void Biblioteka::ZaduziKnjigu(int br_evidencije, int br_indeksa) {
	if (knjige.find(br_evidencije) == knjige.end()) {
		throw std::logic_error("Knjiga nije nadjena");
	}
	else if (studenti.find(br_indeksa) == studenti.end()) {
		throw std::logic_error("Student nije nadjen");
	}
	else if (knjige.find(br_evidencije)->second->DaLiJeZaduzena()) {
		throw std::logic_error("Knjiga vec zaduzena");
	}
	else {
		knjige.find(br_evidencije)
			->second->ZaduziKnjigu(*studenti.find(br_indeksa)->second);
	}
}

void Biblioteka::RazduziKnjigu(int br_evidencije) {
	if (knjige.find(br_evidencije) == knjige.end()) {
		throw std::logic_error("Knjiga nije nadjena");
	}
	else if (!knjige.find(br_evidencije)->second->DaLiJeZaduzena()) {
		throw std::logic_error("Knjiga nije zaduzena");
	}
	else {
		knjige.find(br_evidencije)->second->RazduziKnjigu();
	}
}

void Biblioteka::PrikaziZaduzenja(int br_indeksa) const {
	if (studenti.find(br_indeksa) == studenti.end()) {
		throw std::logic_error("Student nije nadjen");
	}
	int br = 0;
	for (auto a : knjige) {
		if (a.second->DajPokKodKogaJe() == nullptr) {
			continue;
		}
		if (a.second->DajKodKogaJe().broj_indeksa == br_indeksa) {
			std::cout << "Evidencijski broj: " << a.first
				<< "\nNaslov: " << a.second->DajNaslov()
				<< "\nPisac: " << a.second->DajAutora()
				<< "\nZanr: " << a.second->DajZanr()
				<< "\nGodina izdavanja: " << a.second->DajGodinuIzdavanja()
				<< std::endl;
			br++;
		}
	}
	if (br == 0) {
		std::cout << "Nema zaduzenja za tog studenta!";
	}
}