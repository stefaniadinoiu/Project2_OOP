# Queue_OOP_Project

Cozi de caractere (implementate dinamic)


Se dau urmatoarele clase:
- Nod (char info, nod*next)
- Coada (nod * prim, nod * ultim, int dim_max);
- DEQUE:Coada - cu operatiile de adaugare și stergere modificate corespunzator.
- PriorityQueue:Coada - cu operatiile de adaugare și stergere modificate
corespunzator.

Clasele derivate trebuie sa contina cel puțin constructori parametrizati prin
care sa se evidentieze transmiterea parametrilor catre constructorul din clasa
de baza si destructor.

Cerinte suplimentare: 

1. toate clase vor conține obligatoriu constructori de inițializare, parametrizati și de
copiere, destructor, iar operatorii >>, <<, = să fie supraincarcati.

2. ilustrarea conceptelor de moștenire și functii virtuale (pure – unde se considera
mai natural)

3. citirea informațiilor complete a n obiecte, memorarea și afisarea acestora

4. Fiecare din temele de mai jos au o tema din Tema1 corespunzatoare. Veti gasi
care anume in dreptul temei respective. Asta inseamna ca trebuie implementate
si cerintele din Tema1 respective.

5. Operatorii trebuie implementati ca functii membre ale claselor, nu ca functii
friend.(mai putin in cazul operatorilor >> si <<)

6. Accentul se pune pe mosteniri, functii virtuale. (Un design ce presupune functii
virtuale pure/clase abastracte/interfete este apreciat)

7. Daca considerati ca aveti un design mai bun pentru implementarea mostenirilor si
in general a temei puteti sa il folositi si la prezentare sa spuneti de ce ati
implementat asa insa trebuie sa aveti in continuare implementate atat mosteniri
cat si functii virtuale.

8. Cerintele obligatorii de la Tema1 se pastreaza si aici (cele cu verde). De exemplu,
toate clasele vor trebui sa fie implementate folosind alocare dinamica.

9. Aveti grija sa dealocati memoria si sa implementati constructorii de copiere,
operatorii = si >> bine.

10. Nu aveti voie sa folositi STL.

11. Pentru bucatile de cod ce cauzeaza memory leakuri se scad 0.5p.

12. Pentru 1p in plus folositi template-uri. Pentru alt punct in plus folositi, cu sens, un
design pattern singleton, iterator, observer, factory, etc.
