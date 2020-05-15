///Radu Oana, grupa 211,proiect 3 poo :)
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>

#include <typeinfo>

#include <set>
#include <cassert>

using namespace std;

vector<float> defaultVector(){
    vector<float> temp;
    temp.push_back(0.0);
    return temp;
}

//-----------------------------------------------------------------------------
class Locuinta
{

protected:
    static int n;
    string prenume_client;
    string nume_client;
    float suprafata_utila;
    float discount;
    float pret_inchiriere_m2;

public:
/// metoda statica de afisare a numarului de obiecte
static int numarObiecte(){ return n; }


///Constructorul de initializare
Locuinta()
{
    n++;
    prenume_client="Default";
    nume_client = "Default";
    suprafata_utila=0;
    discount = 0;
    pret_inchiriere_m2 = 0;
}

///Constructorul parametrizat
Locuinta(string prenume_client , string nume_client, float suprafata_utila, float discount, float pret_inchiriere_m2)
{
    n++;
    this->prenume_client= prenume_client ;
    this->nume_client = nume_client;
    this->suprafata_utila = suprafata_utila;
    try
    {
    if (discount<0 || discount >10)
        throw this->discount;
    }
    catch (double x)
    {
        cout<<"Eroare in constructor,discountul trebuie sa fie intre 0-10%.\n";
        exit(EXIT_FAILURE);
    }
    this->discount = discount;
    this->pret_inchiriere_m2= pret_inchiriere_m2;
}

///Constructorul de copiere
 Locuinta(Locuinta& a);

///Destructorul
 ~Locuinta();

///set-uri si get-uri
    void setPrenumeClient(string pren){prenume_client=pren;}
    string getPrenumeClient(){return prenume_client;}

    void setNumeClient(string num){nume_client=num;}
    string getNumeClient(){return nume_client;}

    void setSuprafataUtila(float p){suprafata_utila=p;}
    float getSuprafataUtila(){return suprafata_utila;}

    void setDiscount(float s){discount=s;}
    float getDiscount(){return discount;}

    void setPretInchiriere(int n) {pret_inchiriere_m2= n;}
    float getPretInchiriere(){return pret_inchiriere_m2;}

///alte metode
    Locuinta& operator= ( Locuinta& z);
    friend ostream& operator<<(ostream&, Locuinta&);
    friend istream& operator>>(istream&, Locuinta&);
    virtual void citire(istream &in);
    virtual void afisare(ostream &out);
};

int Locuinta::n = 0;

void Locuinta::citire(istream &in)
{
    cout<<"Prenume Client: ";
    in>>prenume_client;

    cout<<"Nume Client: ";
    in>>nume_client;

    cout<<"Suprafata Utila: ";
    in>>suprafata_utila;

    cout<<"Discountul trebuie sa fie cuprins intre 0% si 10%\n";
    cout<<"Discount: ";
    in>>discount;

    try
    {
        if (discount<0 || discount>10)
            throw 1;
    }
    catch (int x)
    {
        cout<<"Eroare in setarea discountului, acesta trebuie sa fie cuprins intre 0 si 10%.\n";
        exit(EXIT_FAILURE);
    }

    cout<<"Pret Inchiriere pe metru patrat (Euro): ";
    in>>pret_inchiriere_m2;
}

void Locuinta::afisare(ostream &out){
    out<<"Prenume Client: "<<prenume_client<<"\n";
    //out <<"Prenumele este de tipul: " << typeid(prenume_client).name() <<endl;
    out<<"Nume Client: "<<nume_client<<"\n";
    out<<"Suprafata Utila: "<<suprafata_utila<<"\n";
    out<<"Discount: "<<discount<<"\n";
    out<<"Pret Inchiriere pe metru patrat: "<<pret_inchiriere_m2<<"\n";
}

///Constructorul de copiere
Locuinta::Locuinta(Locuinta& a)
{
    n++;
    this->prenume_client=a.prenume_client;
    this->nume_client=a.nume_client;
    this->suprafata_utila=a.suprafata_utila;
    this->discount=a.discount;
    this->pret_inchiriere_m2=a.pret_inchiriere_m2;
}

///Destructorul
Locuinta::~Locuinta(){}

/// supraincarcarea operatorului =
Locuinta& Locuinta::operator= (Locuinta& a)
{
    if ( this != &a)
    {
      this->prenume_client = a.prenume_client;
      this->nume_client = a.nume_client;
      this->suprafata_utila=a.suprafata_utila;
      this->discount =a.discount;
      this->pret_inchiriere_m2 = a.pret_inchiriere_m2;
    }
   return *this;
}

///supraincarcarea operatorului <<
ostream& operator<<(ostream& out, Locuinta& d)
{
 d.afisare(out);
 return out;
}

///supraincarcarea operatorului >>
istream& operator>>(istream& in, Locuinta& a)
{
 a.citire(in);
 return in;
}

//--------------------------------------------------------------------------------
class Apartament:public Locuinta
{
    private:
        int nr_etaj;
    public:
///constructor de initializare
    Apartament():Locuinta()
{
    nr_etaj=0;
}
///constructor parametrizat
    Apartament(string,string,float,float,float,int);

///Constructor de copiere
    Apartament(Apartament& a);

///Destructor
    ~Apartament();

///Alte metode
Apartament& operator= (Apartament& z);
friend ostream& operator<<(ostream&, Apartament&);
friend istream& operator>>(istream&, Apartament&);
void citire(istream &in);
void afisare(ostream &out);

float chirie( Apartament& t)
{
    float chirie=0;
    float pret_inc=t.pret_inchiriere_m2;
    float dis=t.discount;
    float suprafata=suprafata_utila;
    chirie= pret_inc*suprafata ;
    dis=chirie/10;
    chirie=chirie-dis;
    return chirie;
}

};

void Apartament::citire(istream &in){
    Locuinta::citire(in);
    cout<<"La ce etaj se afla apartamentul?: ";
    in>>nr_etaj;

}
void Apartament::afisare(ostream &out){
    Locuinta::afisare(out);
    out<<"Apartamentul se afla la etajul: ";
    out<<nr_etaj<<"\n";
    out<<"Pretul chiriei este (Euro): ";
    out<<this->chirie(*this);
}

///Constrcutor parametrizat
Apartament::Apartament(string prenume_client,string nume_client,float suprafata_utila,float discount,float pret_inchiriere_m2, int nretaj):Locuinta(prenume_client,nume_client,suprafata_utila,discount,pret_inchiriere_m2)
{
    nr_etaj=nretaj;
}

///Constructorul de copiere
Apartament::Apartament(Apartament& a):Locuinta()
{
    this->nr_etaj=a.nr_etaj;
}

///Destructor
Apartament::~Apartament(){}

/// supraincarcarea operatorului =
Apartament& Apartament::operator= (Apartament& t)
{
    if ( this != &t)
    {
      this->prenume_client=t.prenume_client;
      this->nume_client =t.nume_client;
      this->suprafata_utila=t.suprafata_utila;
      this->discount =t.discount;
      this->pret_inchiriere_m2= t.pret_inchiriere_m2;
      this->nr_etaj=t.nr_etaj;
    }
   return *this;
}

///supraincarcarea operatorului <<
ostream& operator<<(ostream& out,  Apartament& d)
{
d.afisare(out);
 return out;
}

///supraincarcarea operatorului >>
istream& operator>>(istream& in, Apartament& a)
{
 a.citire(in);
 return in;
}

//--------------------------------------------------------------------------------
class Casa:public Locuinta
{
    private:
        float suprafata_curte;
        int nr_etaje;
        vector <float> etaje;
        float pret_inchiriere_curte_m2;
    public:
///constructor de initializare
    Casa():Locuinta()
{
    suprafata_curte=0;
    nr_etaje=0;
    vector <float> a=defaultVector();
    pret_inchiriere_curte_m2=0;
}
///constructor parametrizat
    Casa(string,string,float,float,float,float,int,vector <float> ,float);

///Constructor de copiere
    Casa(Casa& a);

///Destructor
    ~Casa();

///Alte metode
Casa& operator= ( Casa& z);
Casa(vector<float>,string,int);
friend ostream& operator << (ostream&, Casa&);
friend istream& operator >> (istream&, Casa&);
void citire(istream &in);
void afisare(ostream &out);

float chirie( Casa& t)
{
    float chirie=0, chiriecurte=0, chirietot=0;
    float pret_inc=t.pret_inchiriere_m2, pret_inccurte=t.pret_inchiriere_curte_m2;
    float dis=t.discount;
    float suprafata=suprafata_utila,suprafatacurte=suprafata_curte;
    chirie= pret_inc*suprafata ;
    dis=chirie/10;
    chirie=chirie-dis;
    chiriecurte=pret_inccurte*suprafatacurte;
    chirietot=chirie+chiriecurte;
    return chirietot;
}

};

///supraincarcarea operatorului <<
ostream& operator<<(ostream& out, Casa& d)
{
d.afisare(out);
 return out;
}

///supraincarcarea operatorului >>
istream& operator>>(istream& in, Casa& a)
{
 a.citire(in);
 return in;
}

void Casa::citire(istream &in){
    float etaj;
    Locuinta::citire(in);
    cout<<"Ce suprafata are curtea? ";
    in>>suprafata_curte;
    cout<<"Cate etaje are casa? ";
    in>>nr_etaje;
    in.get();
    for (int i=0;i<=nr_etaje;i++)
    {
        cout<<"Dati suprafata etajului "<<i<<": ";
        in>>etaj;
        etaje.push_back(etaj);
    }
    cout<<"Care este pretul curtii pe metru patrat (Euro)? ";
    in>>pret_inchiriere_curte_m2;
}
void Casa::afisare(ostream& out){
    Locuinta::afisare(out);
    out<<"Suprafata curtii este: ";
    out<<suprafata_curte<<"\n";
    out<<"Numarul de etaje al casei este: ";
    out<<nr_etaje<<"\n";
    int n=0;

    vector<float>::iterator i;

	   for (i = etaje.begin(); i != etaje.end(); ++i)
       {
        out<<"Suprafata utila a etajului "<< n <<" este: "<< (*i)<<"\n";
        n++;
       }

    out<<"Pretul curtii/m^2 este: ";
    out<<pret_inchiriere_curte_m2<<"\n";

    out<<"Pretul chiriei este (Euro): ";
    out<<this->chirie(*this)<<"\n";
}

///Constrcutor parametrizat
Casa::Casa(string prenume_client,string nume_client,float suprafata_utila, float discount,float pret_inchiriere_m2,float suprafatacurte=0, int nretaje=0,vector<float> a=defaultVector(),float pretinchirierecurte=0):Locuinta(prenume_client,nume_client,suprafata_utila,discount,pret_inchiriere_m2)
{
    suprafata_curte=suprafatacurte;
    nr_etaje=nretaje;
    vector<float>::iterator i;
	for (i = a.begin(); i != a.end(); ++i) {
		etaje.push_back(*i);
	}
	if (*etaje.begin() == 0)
        etaje.pop_back();
    pret_inchiriere_curte_m2=pretinchirierecurte;
}

///Constructorul de copiere
Casa::Casa(Casa& a):Locuinta()
{
    this->suprafata_curte=suprafata_curte;
    this->nr_etaje=nr_etaje;
    this->etaje=etaje;
    this->pret_inchiriere_curte_m2=pret_inchiriere_curte_m2;
}

///Destructor
Casa::~Casa(){}

/// supraincarcarea operatorului =
Casa& Casa::operator= (Casa& p)
{
    if ( this != &p)
    {
      this->prenume_client=p.prenume_client;
      this->nume_client =p.nume_client;
      this->suprafata_utila=p.suprafata_utila;
      this->discount =p.discount;
      this->pret_inchiriere_m2=p.pret_inchiriere_m2;
      this->suprafata_curte=p.suprafata_curte;
      this->nr_etaje=p.nr_etaje;
      //this->suprafata_etaj=p.suprafata_etaj;
      this->pret_inchiriere_curte_m2=p.pret_inchiriere_curte_m2;
    }
   return *this;
}

template <class t> class Gestiune
{
    t *v;
    int nr;
public:
    Gestiune(t *p=NULL, int n=0)
    {
        nr=n;
        if (n!=0){
            v=new t[n];
            for(int i=0;i<n;i++)
            {
                v[i]=p[i];
            }
        }
    }
    Gestiune(Gestiune &a)
    {
        nr=a.nr;
        v=new t[nr];
        for(int i=0;i<nr;i++)
        {
            v[i]=a.v[i];
        }
    }
    ~Gestiune()
    {
        delete [] v;
    }

    int get_nr();
    t get_v(int i) {return v[i];}
    friend istream& operator >>(istream &in, Gestiune <t> &g)
    {
        cout<<"Introduceti numarul de locuinte inregistrate in baza de date a agentiei imobiliare: ";
        in>>g.nr;
        g.v=new t[g.nr];
        cout<<"Introduceti datele: \n";
        for(int i=0;i<g.nr;i++){
           in>>g.v[i];
           cout<<"\n";
        }
        return in;
    }
    friend ostream& operator <<(ostream &out, Gestiune<t> &g)
    {
        out<<"In agentia imobiliara se gasesc urmatoarele "<<g.nr<<" locuinte:"<<"\n";
        for(int i=0;i<g.nr;i++)
        {
            out<<g.v[i]<<"\n";
            out <<"Locuinta este de tipul: " << typeid(g).name() <<endl;
        }
        return out;
    }
    void operator+=(char* ob)
    {
        nr++;
        v.push_back(ob);
    }

};

template <class t> int Gestiune<t>::get_nr()
{
    return nr;
}

template <> class Gestiune <Casa>
{
    Casa* v;
    int nr;
    int nr_Case;
public:
    Gestiune(Casa *p=NULL, int n=0)
    {
        nr_Case=0;
        nr=n;
        v=new Casa[n];
        for(int i=0;i<n;i++)
        {
            v[i]=p[i];
            for (int j=0;j<v[i].numarObiecte();j++)
                   {
                     nr_Case+=1;
                     break;
                   }
        }
    }
    Gestiune(Gestiune &a)
    {
        nr=a.nr;
        nr_Case=0;
        v=new Casa[nr];
        for(int i=0;i<nr;i++)
        {
            v[i]=a.v[i];
            for (int j=0;j<v[i].numarObiecte();j++)
                    nr_Case+=1;
        }
    }
    ~Gestiune()
    {
        delete [] v;
    }

    int get_nr() {return nr;}
    Casa get_v(int i) {return v[i];}
    friend istream& operator >>(istream &in, Gestiune <Casa> &g)
    {
        cout<<"Introduceti numarul de Case: ";
        in>>g.nr;
        g.v=new Casa[g.nr];
        cout<<"Introduceti obiectele\n";
        for(int i=0;i<g.nr;i++)
        {
            in>>g.v[i];
            for (int j=0;j<g.v[i].numarObiecte();j++)
                    {
                        g.nr_Case+=1;
                        break;
                    }
           cout<<"\n";
        }
        return in;
    }
    friend ostream& operator <<(ostream &out, Gestiune<Casa> &g)
    {
        out<<"In agentia imobiliara sunt "<<g.nr<<" case inregistrate.\n";
        for(int i=0;i<g.nr;i++)
            out<<g.v[i]<<"\n";

        return out;
    }

};



///Functie cu care incepe programul(nu este metoda a vreunei clase)
void tip(Locuinta *&p, int &i) {

    string s;
    cout<<"Introduceti tipul locuintei "<<i+1<<" (Apartament, Casa): "<<endl;
    cin>>s;

    try{
        if(s=="Apartament" || s=="apartament"){
                p=new Apartament;
                cin>>*p;
                i++;
        }
        else
            if(s=="Casa" || s=="casa"){
                p=new Casa;
                cin>>*p;
                i++;
            }
            else


                    throw 10;
    }
    catch (bad_alloc var){
        cout << "Allocation Failure\n";
        exit(EXIT_FAILURE);
    }
    catch(int j){
        cout<<"Nu ati introdus un tip de casa valid. Incercati Apartament sau Casa.\n ";
    }
}


int main()
{

    Locuinta **loc;

    int n;
    cout<<"Introduceti numarul de locuinte. "; cin>>n; cout<<endl;

    try{
        loc=new Locuinta*[n];
        for(int i=0;i<n;)
            tip(loc[i],i);

        cout<<"\n\nDatele locuintelor au fost citite cu succes!\n\n";

       // _sleep(2000);  //asteapta 2 secunde
        system("cls"); // curata ecranul din consola

        int opt = 0;


        cout<<"\n-----------------MENIU-----------------\n\n";
        cout<<"\t 1. Afisati datele locuintelor;\n";
        cout<<"\t 2. Curatati ecranul. \n";
        cout<<"\t 3. Adauga case in baza de date a agentiei. \n";
        cout<<"\t 4. Adauga apartamente in baza de date a agentiei. \n";
        cout<<"\t 5. Contorizare locuinte. \n";
        cout<<"\t 6. Iesiti din program. \n";

        while (opt != -1)
        {
        cin >> opt;

            switch (opt)
            {
                case 1:
                    {
                            cout<<"\nAfisam datele locuintele citite anterior:\n";

                        for(int i=0;i<n;i++)
                            {
                            cout<<"\n Locuinta id: "<<i+1<<" \n"<<*loc[i]; ///afisez locuinta de pe pozitia i
                            cout<<"\n--------------------------\n";
                            }
                            cout<<"\n-----------------MENIU-----------------\n\n";
                            cout<<"\t 1. Afisati datele locuintelor;\n";
                            cout<<"\t 2. Curatati ecranul. \n";
                            cout<<"\t 3. Adauga case in baza de date a agentiei. \n";
                            cout<<"\t 4. Adauga apartamente in baza de date a agentiei. \n";
                            cout<<"\t 5. Contorizare locuinte. \n";
                            cout<<"\t 6. Iesiti din program. \n";
                    }
                    break;

                case 2:
                    {
                        system("cls");
                        cout<<"\n-----------------MENIU-----------------\n\n";
                        cout<<"\t 1. Afisati datele locuintelor;\n";
                        cout<<"\t 2. Curatati ecranul. \n";
                        cout<<"\t 3. Adauga case in baza de date a agentiei. \n";
                        cout<<"\t 4. Adauga apartamente in baza de date a agentiei. \n";
                        cout<<"\t 5. Contorizare locuinte. \n";
                        cout<<"\t 6. Iesiti din program. \n";

                    }
                    break;
                case 3:
                    {
                    Gestiune <Casa> x;
                    cin>>x;
                    cout<<x<<"\n";
                    cout<<"\n";
                    cout<<"\n-----------------MENIU-----------------\n\n";
                    cout<<"\t 1. Afisati datele locuintelor;\n";
                    cout<<"\t 2. Curatati ecranul. \n";
                    cout<<"\t 3. Adauga case in baza de date a agentiei. \n";
                    cout<<"\t 4. Adauga apartamente in baza de date a agentiei. \n";
                    cout<<"\t 5. Contorizare locuinte. \n";
                    cout<<"\t 6. Iesiti din program. \n";
                    }
                    break;
                case 4:
                    {
                    Gestiune <Apartament> y;
                    cin>>y;
                    cout<<y;
                    cout<<"\n";
                    cout<<"\n-----------------MENIU-----------------\n\n";
                    cout<<"\t 1. Afisati datele locuintelor;\n";
                    cout<<"\t 2. Curatati ecranul. \n";
                    cout<<"\t 3. Adauga case in baza de date a agentiei. \n";
                    cout<<"\t 4. Adauga apartamente in baza de date a agentiei. \n";
                    cout<<"\t 5. Contorizare locuinte. \n";
                    cout<<"\t 6. Iesiti din program. \n";
                    }
                    break;
                case 5:
                    {
                            int N_case,N_apartamente;
                            N_case=N_apartamente=0;
                            if (n>0)
                            {
                                for(int i=0;i<n;i++)
                                {
                                ///incerc cast catre casa
                                Casa *p1=dynamic_cast<Casa*>(loc[i]);
                                ///incerc cast catre apartament
                                Apartament *p2=dynamic_cast<Apartament*>(loc[i]);
                                ///daca sunt nenuli atunci incrementez corespunzator
                                if (p1)
                                    N_case++;
                                if (p2)
                                    N_apartamente++;
                                }
                                cout<<"Numarul de case: "<<N_case<<"\n";
                                cout<<"Numarul de apartamente: "<<N_apartamente<<"\n";
                            }
                            else
                                {
                                cout<<"Nu s-au citit date. Redeschideti programul si cititi datele.\n";
                                }
                            cout<<"\n-----------------MENIU-----------------\n\n";
                            cout<<"\t 1. Afisati datele locuintelor;\n";
                            cout<<"\t 2. Curatati ecranul. \n";
                            cout<<"\t 3. Adauga case in baza de date a agentiei. \n";
                            cout<<"\t 4. Adauga apartamente in baza de date a agentiei. \n";
                            cout<<"\t 5. Contorizare locuinte. \n";
                            cout<<"\t 6. Iesiti din program. \n";
                    }
                    break;
                    case 6:
                    {
                    cout<<":)";
                    return 0;
                    }

                default:
                    cout<<"Ati ales o optiune invalida. \n";
        }
    }
    }
    catch (bad_alloc var)
    {
        cout<<"Numarul introdus trebuie sa fie pozitiv. Bad Alloc!\n";
        exit(EXIT_FAILURE);
    }

 return 0;
}
