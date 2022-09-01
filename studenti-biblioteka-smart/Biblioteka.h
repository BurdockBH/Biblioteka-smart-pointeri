#include <iostream>
#include <map>
#include <memory>
#include "Knjiga.h"

class Biblioteka {
    std::map<int, std::shared_ptr<Student>> studenti;
    std::map<int, std::shared_ptr<Knjiga>> knjige;

public:
    Biblioteka() = default;
    Biblioteka(const Biblioteka& b);
    Biblioteka(Biblioteka&& b);
    Biblioteka& operator=(const Biblioteka& b);
    Biblioteka& operator=(Biblioteka&& b);
    void RegistrirajNovogStudenta(int br_indeksa, std::string ime,
        std::string prezime, int godina_studija,
        std::string adresa, std::string br_telefona);
    void RegistrirajNovuKnjigu(int br_evidencije, std::string naslov,
        std::string ime_pisca, std::string zanr,
        int god_izdavanja);
    Student& NadjiStudenta(int br_indeksa);
    Knjiga& NadjiKnjigu(int br_evidencije);
    void IzlistajStudente() const;
    void IzlistajKnjige() const;
    void ZaduziKnjigu(int br_evidencije, int br_indeksa);
    void RazduziKnjigu(int br_evidencije);
    void PrikaziZaduzenja(int br_indeksa);
};