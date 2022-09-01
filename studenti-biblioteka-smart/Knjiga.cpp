#include <iostream>
#include "Knjiga.h"

Student& Knjiga::DajKodKogaJe() const {
	if (korisnik == nullptr) {
		throw std::domain_error("Knjiga nije zaduzena");
	}
	return *korisnik;
}