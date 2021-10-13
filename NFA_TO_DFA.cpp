#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;


struct Tranzitie{
    int destinatie;
    string litera;
};

ifstream f ("date.in");
ofstream g ("date.out");

int main(){
    int nr_stari,
        nr_tranzitii;
    vector <int> stari;
    vector <int> tranzitii;
    vector <int> stari_dfa[101]; // vectori de vectori
    vector <string> litere;
    vector <string> t_dfa(101);
    vector <int> initial(101);
    int nr_stari_dfa;
    f>>nr_stari;
    int stare;
    for (int i = 0; i < nr_stari; i++){
        f >> stare;
        stari.push_back(stare);
        }
    f >> nr_tranzitii;
    // vector <vector<Tranzitie>> lista_adiacenta(nr_stari,vector<Tranzitie>());
        vector <vector<Tranzitie>> lista_adiacenta(100,vector<Tranzitie>());
    for (int i = 0; i < nr_tranzitii; i++){
        f >> stare;
        //cout << stare << endl;
        Tranzitie t;
        f >> t.destinatie;
        //cout << t.destinatie << endl;
        f >> t.litera;
        //cout << t.litera << endl;
        litere.push_back(t.litera);
        for (int j = 0; j < nr_stari; j++){
            if (stari[j] == stare)
                stare = j;
        }
        lista_adiacenta[stare].push_back(t);
    }

    sort(litere.begin(), litere.end());
    auto lst = unique(litere.begin(), litere.end());
    litere.erase(lst, litere.end());

    int S; // starea initiala
    f >> S;
    int nrF; // stari finale
    f >> nrF;
    vector <int> stari_fin;
    int sf;
    for (int i = 0; i < nrF; i++){
        f >> sf;
        stari_fin.push_back(sf);
    }

    queue <int> q;
    vector <int> v;
    v.push_back(0);
    q.push(0);
    stari_dfa[nr_stari_dfa++] = v;

    // cat timp coada nu e goala
    while (!q.empty()){
        int top = q.front();
        q.pop();

        // pt fiecare litera
        for (int j = 0; j < litere.size(); j++){
            vector <int> curent;
            // pentru fiecare stare din stari_dfa[top]
            for (int i = 0; i < stari_dfa[top].size(); i++){
                // pentru fiecare vecin al starii
                for (int k = 0; k < lista_adiacenta[stari_dfa[top][i]].size(); k++){
                    // daca starea se duce intr-o alta stare cu litera la care sunt acum
                    // daca da atunci o adaug in vectorul curent
                    if (litere[j] == lista_adiacenta[stari_dfa[top][i]][k].litera){
                        int ok = 1;
                        // verific daca starea se gaseste daja in vectorul curent
                        for (int h = 0; h < curent.size(); h++){
                            if (curent[h] == lista_adiacenta[stari_dfa[top][i]][k].destinatie)
                            ok = 0;
                        }
                        // daca nu se afla deja in vector adaug starea in care ma duc cu litere[k]
                        if (ok == 1)
                            curent.push_back(lista_adiacenta[stari_dfa[top][i]][k].destinatie);
                    }
                }
            }
            // sortez vectorul curent pentru a putea sa-l gasesc usor in stari_dfa
            sort (curent.begin(), curent.end());

           // for (int i = 0 ; i < curent.size(); i ++)
              //  cout << curent[i];
           // cout << endl;

            // verific daca gasesc vectorul curent in stari_dfa
            int ok = 1;
            for (int i = 0; i < nr_stari_dfa; i++)
                if (curent == stari_dfa[i])
                    ok = 0;

            // daca vectorul nu se afla in stari_dfa
            if (ok == 1){
                // daca vectorul curent este gol atunci starea asta devine dead state
                if (curent.size() == 0){

                    // adaug vectorul in stari_dfa
                    stari_dfa[nr_stari_dfa] = curent;
                    // cresc numarul de stari ale dfa-ului
                    nr_stari_dfa++;
                }
                else{
                // daca vectorul curent are size > 0
                // adaug vectorul curent ca noua stare in dfa
                stari_dfa[nr_stari_dfa] = curent;
                // ii dau push in queue ca sa ii caut vecinii in care se duce cu literele date
                q.push(nr_stari_dfa);
                nr_stari_dfa++;}
            }
        }
    }

    vector <vector<Tranzitie>> lista_adiacenta2(100,vector<Tranzitie>());
    vector <int> finale_dfa; // starile finale ale dfa-ului

   // cout << endl;
    //for (int i = 0; i < nr_stari_dfa; i++){
        // cout << "starea " << i << "[";
       // for (int j = 0; j < stari_dfa[i].size(); j++)
           // cout << stari_dfa[i][j] << " ";
       // cout << "]" << endl;}

    // initial dead_state este -1 (adica nu exista)
    // caut in stari_dfa si daca gasesc o stare a dfa-ului care are size == 0 dead_state devine acea stare
    int dead_state = -1;
    for (int i = 0; i < nr_stari_dfa; i++){
        // daca am gasit starea cu size == 0
        if (stari_dfa[i].size() == 0){
            // dead_state ia valoarea pozitiiei in dfa
            dead_state = i;
            // fac sa nu mai fie un vector gol
            stari_dfa[i].push_back(i);
            // pentru fiecare litera fac ca starea sa se duca tot in ea
            for (int j = 0; j < litere.size(); j++){
                Tranzitie tr;
                tr.destinatie = dead_state;
                tr.litera = litere[j];
                lista_adiacenta2[dead_state].push_back(tr);
            }
        }
    }


    // pentru fiecare stare a dfa-ului
    for (int i = 0; i < nr_stari_dfa; i++){
        // cout << "starea " << i << "[";
        //for (int j = 0; j < stari_dfa[i].size(); j++)
          //  cout << stari_dfa[i][j] << " ";
       // cout << "]" << endl;
        int ok = 0;
            //pentru fiecare stare a starii curenta a dfa-ului
            for (int j = 0; j < stari_dfa[i].size(); j++){
                // pentru fiecare litera
                for (int k = 0; k < litere.size(); k++){
                    vector <string> litere_intalnite;
                    // pentru fiecare vecin al starii
                    for (int l = 0; l < lista_adiacenta[stari_dfa[i][j]].size(); l++){
                        // daca din starea mea ma dun in alta stare cu litere[k]
                        if (litere[k] == lista_adiacenta[stari_dfa[i][j]][l].litera){
                            ok = 1; // ok marcheaza faptul ca am vizitat litera litere[k]
                            // marchez ca am vizitat macar o data litere[k] per stare de dfa
                            litere_intalnite.push_back(lista_adiacenta[stari_dfa[i][j]][l].litera);
                           // cout << lista_adiacenta[stari_dfa[i][j]][l].destinatie << " " << lista_adiacenta[stari_dfa[i][j]][l].litera << endl;
                           // vad daca starea la care sunt este finala in automatul citit din fisier
                            for (int b = 0; b < nrF; b++){
                                // daca starea este finala in vectorul initial atunci adaug starea din dfa la care sunt ca fiind finala in dfa
                                if (stari_dfa[i][j] == stari_fin[b])
                                    finale_dfa.push_back(i);
                            }
                        }
                    }
                    // daca nicio stare nu merge in alta stare cu litere[k] atunci o pun sa mearga cu litere[k] in dead_state
                    if (ok == 0){
                        Tranzitie tr;
                        tr.destinatie = dead_state;
                        tr.litera = litere[k];
                        lista_adiacenta2[stari_dfa[i][j]].push_back(tr);
                    }
            }
        }
    }

    // in dfa retin starile (de la 0....nr_stari_dfa) si in ce alte stari se mai duc si cu ce litera ajung acolo
    vector <vector<Tranzitie>> dfa(100,vector<Tranzitie>());
    // pentru fiecare stare din dfa
    for (int i = 0; i < nr_stari_dfa; i++){
        // daca i este diferita de dead_state
        if (i != dead_state){
            // pentru fiecare litera
             for (int k = 0; k < litere.size(); k++){
                // in vectorul p retin ce stari am vizitat
                vector <int> p;
                for (int j = 0; j < stari_dfa[i].size(); j++){
                    for (int l = 0; l < lista_adiacenta[stari_dfa[i][j]].size(); l++){
                        if (lista_adiacenta[stari_dfa[i][j]][l].litera == litere[k]){
                            p.push_back(lista_adiacenta[stari_dfa[i][j]][l].destinatie);
                        }
                    }
                }
                // daca cu litere[k] nu ma duc nicaieri din stari_dfa[i] atunci fac ca dfa[i] sa se duca in dead_state cu litere[k]
                if (p.size() == 0){
                    Tranzitie tr;
                    tr.destinatie = lista_adiacenta2[dead_state][0].destinatie;
                    tr.litera = litere[k];
                    dfa[i].push_back(tr);
                }
                else{
                // sortez vectorul si sterg duplicatele ca sa pot sa gasesc vectorul in stari_dfa
                sort(p.begin(), p.end());
                p.erase(unique(p.begin(), p.end()), p.end());
                for (int l = 0; l < nr_stari_dfa; l++){
                        if (stari_dfa[l] == p){
                            Tranzitie tr;
                            tr.destinatie = l;
                            tr.litera = litere[k];
                            dfa[i].push_back(tr);
                        }
                    }
            }
        }
    }
    // daca i este dead_state
    else{
        for (int k = 0; k < litere.size(); k++){
            Tranzitie tr;
            tr.destinatie = dead_state;
            tr.litera = litere[k];
            dfa[i].push_back(tr);
        }
    }
    }

    // minimizare

    vector <vector<int>> m;
    vector <int> n; // stari nefinale

    // determin starile nefinale
    for (int i = 0; i < nr_stari_dfa; i++){
        int ok = 1;
        for (int j = 0; j < finale_dfa.size(); j++){
            if (i == finale_dfa[j])
                ok = 0;
        }
        if (ok == 1){
            n.push_back(i);
            }
    }


    sort(finale_dfa.begin(), finale_dfa.end());
    finale_dfa.erase(unique(finale_dfa.begin(), finale_dfa.end()), finale_dfa.end());

    // in m pun starile nefinale si cele finale
    m.push_back(n);
    m.push_back(finale_dfa);

    //cout << "minimizare: " << endl;

    // parcurg m cat timp m si w sunt diferite
    while (true){
        // in w retin multimea ce se formeaza urmand algoritmul pentru minimizare
        vector <vector<int>> w;
        // pentru fiecare stare din m
        for (int i = 0; i < m.size(); i++){
            // daca am mai mult de o stare in m[i]
            if (m[i].size() > 1){
                // pentru fiecare stare din m[i]
                for (int j = 0; j < m[i].size(); j++){
                    int cont  = 1;
                    // verific pentru fiecare submultime din w daca elem meu se poate pune acolo
                    for (int k = 0; k < w.size(); k++){
                        int ok = 1;
                        // pentru fiecare litera caut daca starea mea se afla in aceeasi submultime cu w[k][0]
                        for (int h = 0; h < litere.size(); h++){
                            int p = -1, q = -2;
                            for (int g = 0; g < m.size(); g++){
                                for (int u = 0; u < m[g].size(); u++){
                                    if (dfa[m[i][j]][h].destinatie == m[g][u]){
                                        p = g;
                                    }
                                    if (dfa[w[k][0]][h].destinatie == m[g][u]){
                                        q = g;
                                    }
                                }
                            }
                            // nu se afla in aceeasi submultime din m
                            if (p != q)
                                ok = 0;
                        }
                        // daca se afla in aceeasi submultime ii adaug in w
                        if (ok == 1){
                            cont = 0;
                            w[k].push_back(m[i][j]);
                            break;
                        }
                    }
                    // daca l-am adaugat deja in w
                    if (cont == 1){
                        vector <int> inter;
                        inter.push_back(m[i][j]);
                        w.push_back(inter);
                    }
                }
            }
            // daca am o singura stare in m[i] atunci o adaug asa cum e in w
            else{
                vector <int> inter;
                inter.push_back(m[i][0]);
                w.push_back(inter);
            }
        }
        // daca m == w atunci nu mai avem ce sa minimizam (am ajuns la forma finala)
        if (m == w){
            break;
            }
        else{
            // daca nu continuam sa minimizam
            m = w;
            }
    }

    vector <vector<Tranzitie>> minimizare(100,vector<Tranzitie>());
    //cout << "afisare" ;
    for (int i = 0 ; i < m.size(); i++){
        for (int k = 0; k < litere.size(); k++){
            vector <int> inter;
            for (int j = 0 ; j < m[i].size(); j++){
                //cout << m[i][j] << " :";
                if (dfa[m[i][j]][k].litera == litere[k]){
                    inter.push_back(dfa[m[i][j]][k].destinatie);
                }
            }

            for (int j = 0; j < m.size(); j++){
                if (inter == m[j]){
                    Tranzitie tr;
                    tr.litera = litere[k];
                    //cout << tr.litera << " ";
                    tr.destinatie = j;
                    //cout << tr.destinatie << " ";
                    minimizare[i].push_back(tr);
                }
            }
            //cout << endl;
        }
    }


    for (int i = 0; i < m.size(); i++){
        for (int j = 0; j < litere.size(); j++){
            //cout << i << " " << minimizare[i][j].destinatie << " " << minimizare[i][j].litera << endl;
            g << i << " " << minimizare[i][j].destinatie << " " << minimizare[i][j].litera << endl;
        }
    }

    g << "Starea initiala: " << 0 << endl;
    g << "Starile finale: ";
    for (int i = 0 ; i < m.size(); i++){
        if (m[i] == finale_dfa)
            g << i << " ";
    }

    return 0;
}



