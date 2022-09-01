#include <iostream>
#include "Student.h"

class Knjiga {
    std::string naslov_knjige, ime_pisca, zanr_knjige;
    int god_izdavanja;
    Student* korisnik = nullptr;

public:
    Knjiga(std::string naslov_knjige, std::string ime_pisca,
        std::string zanr_knjige, int god_izdavanja)
        : naslov_knjige(naslov_knjige), ime_pisca(ime_pisca),
        zanr_knjige(zanr_knjige), god_izdavanja(god_izdavanja) {}
    std::string DajNaslov() const { return naslov_knjige; }
    std::string DajAutora() const { return ime_pisca; }
    std::string DajZanr() const { return zanr_knjige; }
    int DajGodinuIzdavanja() const { return god_izdavanja; }
    void ZaduziKnjigu(Student& s) { korisnik = &s; }
    void RazduziKnjigu() { korisnik = nullptr; }
    bool DaLiJeZaduzena() { return korisnik != nullptr; }
    Student& DajKodKogaJe();
    Student* DajPokKodKogaJe() { return korisnik; }
}; 
