#include <iostream>

struct Student {
    int broj_indeksa, godina_studija;
    std::string ime, prezime, telefon, adresa;
    Student() = default;
    Student(int broj_indeksa, int godina_studija, std::string adresa,
        std::string telefon, std::string ime, std::string prezime)
        : broj_indeksa(broj_indeksa), godina_studija(godina_studija),
        adresa(adresa), telefon(telefon), ime(ime), prezime(prezime) {}
};

