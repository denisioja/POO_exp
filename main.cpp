 #include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//amu no

class Copaci {
private:
    std::string specie;
    int numar;
public:
    Copaci() = default;

    Copaci(const std::string &specie_, int numar_);

    Copaci(const Copaci &copaci);

    Copaci& operator=(const Copaci &copaci) {
        specie = copaci.specie;
        numar = copaci.numar;
        return *this;
    };

//    int getNumar() const {
//        return numar;
//    }

    void afiscop(){
        std::cout << specie << " " << numar << "\n";
    }

    friend Copaci sumaC(const std::vector<Copaci> &copaci) {
        int suma=0;
        for(int i = 0; i < copaci.size(); i++)
            suma = suma + copaci[i].numar;
        Copaci total("Totalitatea copacilor", suma);
        return total;
    }

    ~Copaci() = default;

    friend std::ostream & operator <<(std::ostream &out, Copaci &copaci);
};

Copaci::Copaci(const std::string &specie_, int numar_) {
    this->specie = specie_;
    this->numar = numar_;
}

Copaci::Copaci(const Copaci &copaci) {
    this->specie = copaci.specie;
    this->numar = copaci.numar;
}

std::ostream & operator <<(std::ostream &out, Copaci &copaci) {
    out <<  "Specie copac: " << copaci.specie << ", numarul de bucati: " << copaci.numar << "\n";
    return out;
}

class Lac {
private:
    float suprafata;
    std::string tip; //natural, artificial
public:

    Lac() = default;

    Lac(float suprafata_, const std::string &tip_);

    Lac(const Lac &lac);

    Lac& operator=(const Lac &lac) {
        suprafata = lac.suprafata;
        tip = lac.tip;
        return *this;
    }

    float getSuprafata() const {
        return this->suprafata;
    }

    ~Lac() = default;

    friend std::ostream & operator <<(std::ostream &out, Lac &lac);
};

Lac::Lac(float suprafata_, const std::string &tip_) {
    this->suprafata = suprafata_;
    this->tip = tip_;
}

Lac::Lac(const Lac &lac) {
    this->suprafata = lac.suprafata;
    this->tip = lac.tip;
}

std::ostream & operator <<(std::ostream &out, Lac &lac) {
    out << "Tip lac: " << lac.tip << ", avand suprafata de: " << lac.suprafata << " m patrati\n";
    return out;
}

class Banci {
private:
    int numar;
    std::string culoare;
public:

    Banci() = default;

    Banci(int numar_, const std::string &culoare_);

    Banci(const Banci &banci);

    Banci& operator=(const Banci &banci) {
        numar = banci.numar;
        culoare = banci.culoare;
        return *this;
    }

//    int getNumar() const {
//        return numar;
//    }

    void afisbnc(){
        std::cout << culoare << " " << numar << "\n";
    }

    friend Banci sumaB(const std::vector<Banci> &banci) {
        int suma=0;
        for(int i = 0; i < banci.size(); i++)
            suma = suma + banci[i].numar;
        Banci total(suma, "Totalitatea bancilor");
        return total;
    }

    ~Banci() = default;

    friend std::ostream & operator <<(std::ostream &out, Banci &banci);
};

Banci::Banci(int numar_, const std::string &culoare_) {
    this->numar = numar_;
    this->culoare = culoare_;
}

Banci::Banci(const Banci &banci) {
    this->numar = banci.numar;
    this->culoare = banci.culoare;
}

std::ostream & operator <<(std::ostream &out, Banci &banci) {
    out << "Culoare banci: " << banci.culoare << ", numarul de bucati: " << banci.numar << "\n";
    return out;
}

class Parc {
private:
    std::string nume;
    float suprafata;
    std::vector<Copaci> copaci;
    std::vector<Banci> banci;
    Lac lac;
public:
    Parc(const std::string &nume_, float suprafata_, const std::vector<Copaci> &copaci_, const std::vector<Banci> &banci_, const Lac &lac_);

    Parc(const Parc &parc);

    Parc& operator=(const Parc &parc) {
        nume = parc.nume;
        suprafata = parc.suprafata;
        copaci = parc.copaci;
        banci = parc.banci;
        lac = parc.lac;
        return *this;
    }

    friend Parc dimensiune(const Parc &parc) {
        if(parc.suprafata>parc.lac.getSuprafata())
            std::cout << "Suprafata parcului este mai mare decat cea a lacului\n";
        else std::cout << "Suprafata lacului este mai mare decat cea a parului\n";
    }

    ~Parc() = default;

    friend std::ostream & operator <<(std::ostream &out, Parc &parc);
};

Parc::Parc(const std::string &nume_, float suprafata_, const std::vector<Copaci> &copaci_, const std::vector<Banci> &banci_, const Lac &lac_) {
    this->nume = nume_;
    this->suprafata = suprafata_;
    this->copaci = copaci_;
    this->banci = banci_;
    this->lac = lac_;
}

Parc::Parc(const Parc &parc) {
    this->nume = parc.nume;
    this->suprafata = parc.suprafata;
    this->copaci = parc.copaci;
    this->lac = parc.lac;
    this->banci = parc.banci;
}

std::ostream & operator <<(std::ostream &out, Parc &parc) {
    out << "Numele parcului: " << parc.nume << ", avand suprafata de: " << parc.suprafata << " m patrati\n";
    out << "Copaci:\n";
    for(int i = 0; i < parc.copaci.size(); i++)
        out << parc.copaci[i];
    out << "Lacul:\n";
    out << parc.lac;
    out << "Bancile:\n";
    for(int i = 0; i < parc.banci.size(); i++)
        out << parc.banci[i];
    return out;
}

int main(){
    std::vector<Copaci> copaci;
    copaci.reserve(100);
    copaci.emplace_back("Tei", 15);
    copaci.emplace_back("Stejar", 20);
    copaci.emplace_back("Salcam", 17);

    Lac lac(123, "Natural");

    std::vector<Banci> banci;
    banci.reserve(100);
    banci.emplace_back(12, "Rosii");
    banci.emplace_back(10, "Maro");
    banci.emplace_back(9, "Verzi");
    banci.emplace_back(15, "Albastre");

    Parc parc("IOR", 234, copaci, banci, lac);
    std::cout << parc;

    Copaci sumC = sumaC(copaci);
    sumC.afiscop();

    Banci sumB = sumaB(banci);
    sumB.afisbnc();

    //Parc dim = dimensiune(parc);
    return 0;
}
