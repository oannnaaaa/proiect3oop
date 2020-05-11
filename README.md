# proiect3oop
 Proiectul 3 la POO
– Se dorește implementarea unei aplicații care sa permita gestionarea clienților și a
proprietăților imobiliare în cadrul unei agenții imobiliare nou infiintate. Pentru fiecare
locuință se cunoaște numele clientului care o închiriază, suprafata utila și discount-ul (0-
10%). La apartamente se cunoaste etajul, iar la case se stie cati metri patrati are curtea, cate
etaje are casa și care este suprafata utila pe fiecare etaj în parte.
Evident, calculul chiriei se face diferit. Dacă la apartamente se considera doar formula data
de prețul de închiriere pe metru pătrat * suprafata utila, avand grija sa se aplice discount
unde este cazul, la casa, se adaugă, indiferent de discount, prețul pe metru pătrat de curte *
suprafața acesteia.
Structura de date: set<pair<locuinta, tip>> unde tip = apartament sau casa
Cerința suplimentară:
- Să se adauge toate campurile relevante pentru modelarea acestei probleme.
- Să se construiască clasa template Gestiune, continand structura de obiecte de tipul
locuintelor implementate, alocat dinamic, unde indexul fiecărei locuințe este incrementat
automat la adaugarea uneia noi, prin supraincarcarea operatorului +=.
- Să se construiască o specializare pentru tipul Casa care sa stocheze numărul de case,
fiecare cu chiria aferentă și afișează totalul obținut de agentia imobiliara de pe urma
acestora. 
