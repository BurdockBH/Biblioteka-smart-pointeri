#include <iostream>
#include <map>
#include <memory>
#include "Biblioteka.h"
using namespace std;

int main() {

	Biblioteka bib;
	int opcija;
	cout << "Odaberite opciju: \n 1 - Registriraj novog studenta (br indeksa, ime, prezime, godina studija, adresa, telefon)"
		<< "\n 2 - Registriraj novu knjigu (br evidencije, ime knjige, ime pisca, zanr, godina izdavanja)"
		<< "\n 3 - Nadji studenta (broj indeksa)"
		<< "\n 4 - Nadji knjigu (broj evidencije)"
		<< "\n 5 - Izlistaj studente"
		<< "\n 6 - Izlistaj knjiga"
		<< "\n 7 - Zaduzi knjigu (broj evidencije, broj indeksa)"
		<< "\n 8 - Razduzi knjigu (broj evidencije)"
		<< "\n 9 - Prikazi zaduzenja (broj indeksa) \n 0 - Izlaz" << std::endl;
	while (true) {
		cout << "Opcija: ";
		cin >> opcija;
		switch (opcija)
		{
		case 1:
		{
			int br_indeksa, god_studija;
			std::string ime, prezime, adresa, telefon;
			std::cin >> br_indeksa >> ime >> prezime >> god_studija >> adresa >> telefon;
			bib.RegistrirajNovogStudenta(br_indeksa, ime, prezime, god_studija, adresa, telefon);
			std::cout << "Student registrovan!" << std::endl;
			break;
		}
		case 2:
		{
			int br_evidencije, god_izdavanja;
			std::string ime_knjige, ime_pisca, zanr;
			std::cin >> br_evidencije >> ime_knjige >> ime_pisca >> zanr >> god_izdavanja;
			bib.RegistrirajNovuKnjigu(br_evidencije, ime_knjige, ime_pisca, zanr, god_izdavanja);
			std::cout << "Knjiga registrovana!" << std::endl;
			break;
		}
		case 3:
		{
			try {
				int br_indeksa;
				std::cin >> br_indeksa;
				auto student = bib.NadjiStudenta(br_indeksa);
				std::cout << "Ime: " << student.ime << std::endl << "Prezime: " << student.prezime << std::endl << "Broj indeksa: "
					<< student.broj_indeksa << "Adresa: " << student.adresa << std::endl << "Godina studija: "
					<< student.godina_studija << std::endl << "Telefon: " << student.telefon << std::endl;
				break;
			}
			catch (std::logic_error e) {
				std::cout << e.what() << std::endl;
				continue;

			}
		}
		case 4:
		{
			try {
				int br_evidencije;
				std::cin >> br_evidencije;
				auto knjiga = bib.NadjiKnjigu(br_evidencije);
				std::cout << "Knjiga: " << knjiga.DajNaslov() << std::endl;
				break;
			}
			catch (std::logic_error e) {
				std::cout << e.what() << std::endl;
				continue;

			}
		}
		case 5:
		{
			bib.IzlistajStudente();
			break;
		}
		case 6:
		{
			bib.IzlistajKnjige();
			break;
		}
		case 7:
		{
			try {
				int br_evidencije, br_indeksa;
				std::cin >> br_evidencije >> br_indeksa;
				bib.ZaduziKnjigu(br_evidencije, br_indeksa);
				std::cout << "Knjiga " << bib.NadjiKnjigu(br_evidencije).DajNaslov() << " zaduzena kod studenta " << bib.NadjiStudenta(br_indeksa).ime << std::endl;
				break;
			}
			catch (std::logic_error e) {
				std::cout << e.what() << std::endl;
				continue;

			}
		}
		case 8:
		{
			try {
				int br_evidencije;
				std::cin >> br_evidencije;
				std::cout << "Knjiga " << bib.NadjiKnjigu(br_evidencije).DajNaslov() << " razduzena.";
				bib.RazduziKnjigu(br_evidencije);
				break;
			}
			catch (std::logic_error e) {
				std::cout << e.what() << std::endl;
				continue;

			}

		}
		case 9:
		{
			try {
				int br_indeksa;
				std::cin >> br_indeksa;
				bib.PrikaziZaduzenja(br_indeksa);
				break;
			}
			catch (std::logic_error e) {
				std::cout << e.what() << std::endl;
				continue;

			}
		}
		}
		std::cout << std::endl;
		if (opcija == 0) {
			break;
		}
	}
	return 0;
}
