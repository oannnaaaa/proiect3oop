///Radu Oana, grupa 211,proiect 3 poo :)
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>

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
static void numarObiecte(){ cout<<"Numarul total de locuinte este: "<<n<<endl;}

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

    cout<<"Discount: ";
    in>>discount;

    cout<<"Pret Inchiriere pe metru patrat: ";
    in>>pret_inchiriere_m2;
}

void Locuinta::afisare(ostream &out){
    out<<"Prenume Client: "<<prenume_client<<"\n";
    out<<"Nume Client: "<<nume_client<<"\n";
    out<<"Suprafata Utila: "<<suprafata_utila<<"\n";
    out<<"Discount: "<<discount<<"\n";
    out<<"Pret Inchiriere pe metru patrat: "<<pret_inchiriere_m2;
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
     chirie= t.pret_inchiriere_m2 * t.suprafata_utila ;
     //mai trebuie sa rezolvi treaba cu discountul

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
    out<<"Pretul chiriei este: ";
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
    int chirie=0;
     //trebuie sa rezolvi pretul chiriei
    return chirie;
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
    for (int i=0;i<=nr_etaje;i++){
        cout<<"Dati suprafata etajului "<<i<<": ";
        in>>etaj;
        etaje.push_back(etaj);
    }
    cout<<"Care este pretul curtii pe metru patrat? ";
    in>>pret_inchiriere_curte_m2;
}
void Casa::afisare(ostream& out){
    Locuinta::afisare(out);
    out<<"Suprafata curtii este: ";
    out<<suprafata_curte<<"\n";
    out<<"Numarul de etaje al casei este: ";
    out<<nr_etaje<<"\n";
    int n=nr_etaje;

    vector<float>::iterator i;

	   for (i = etaje.begin(); i != etaje.end(); ++i)
        out<<"Suprafata utila a etajului "<<n<<"este: "<<(*i)<<'\n';



    out<<"Pretul chiriei este: ";
    out<<this->chirie(*this);
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

        _sleep(3000);  //asteapta 4 secunde
        system("cls"); // curata ecranul din consola

        int opt = 0;


        cout<<"\n-----------------MENIU-----------------\n\n";
        cout<<"\t 1. Afisati datele locuintelor;\n";
        cout<<"\t 2. Curatati ecranul. \n";
        cout<<"\t 3. Iesiti din program. \n";

        while (opt != -1)
        {
        if (opt == 1)
        cout<<"\n  Introduceti optiunea dorita: \n  1 - afisati toate locuintele; \n  2 - curatati ecranul;\n  3 - inchideti programul; \n";
        cin >> opt;

            switch (opt)
            {
                case 1:
                    {
                            cout<<"\nAfisam datele locuintele citite anterior:\n";

                        for(int i=0;i<n;i++)
                            {
                            cout<<"\n Locuinta id: "<<i+1<<" \n"<<*loc[i]; ///afisez locuinta de pe pozitia i
                            cout<<"--------------------------\n";
                            }
                    }
                    break;

                case 2:
                    {
                        system("cls");
                        cout<<"\n-----------------MENIU-----------------\n\n";
                        cout<<"\t 1. Afisati datele locuintelor;\n";
                        cout<<"\t 2. Curatati ecranul. \n";
                        cout<<"\t 3. Iesiti din program. \n";
                    }
                    break;
                case 3:
                    return 0;
                default:
                    cout<<"Ati ales o optiune invalida. \n";

            }
        }
    }
    catch (bad_alloc var){
        cout<<"Numarul introdus trebuie sa fie pozitiv. Bad Alloc!\n";
        exit(EXIT_FAILURE);
    }
    return 0;

 return 0;
}
