// #include <iostream>
// #include <string>
// #include <fstream>
// #include <vector>
// #include <queue>
// #include <unordered_set>
// #include <algorithm>
// using namespace std;


// struct Tranzitie{
//     int destinatie;
//     string litera;
// };

// // struct Element{
// //     int start;
// //     int indice;
// // };

// ifstream f ("date.in");
// ofstream g ("date.out");

// int main(){
//     int nr_stari,
//         nr_tranzitii;
//     vector <int> stari;
//     vector <int> tranzitii;
//     vector <int> stari_dfa[101]; // vectori de vectori
//     vector <string> litere;
//     vector <string> t_dfa(101);
//     vector <int> initial(101);
//     int nr_stari_dfa;
//     f>>nr_stari;
//     int stare;
//     for (int i = 0; i < nr_stari; i++){
//         f >> stare;
//         stari.push_back(stare);
//         }
//     f >> nr_tranzitii;
//     // vector <vector<Tranzitie>> lista_adiacenta(nr_stari,vector<Tranzitie>());
//         vector <vector<Tranzitie>> lista_adiacenta(100,vector<Tranzitie>());
//     for (int i = 0; i < nr_tranzitii; i++){
//         f >> stare;
//         //cout << stare << endl;
//         Tranzitie t;
//         f >> t.destinatie;
//         //cout << t.destinatie << endl;
//         f >> t.litera;
//         //cout << t.litera << endl;
//         litere.push_back(t.litera);
//         for (int j = 0; j < nr_stari; j++){
//             if (stari[j] == stare)
//                 stare = j;
//         }
//         lista_adiacenta[stare].push_back(t);
//     }

//     sort(litere.begin(), litere.end());
//     auto lst = unique(litere.begin(), litere.end());
//     litere.erase(lst, litere.end());

//     int S; // starea initiala
//     f >> S;
//     int nrF; // stari finale
//     f >> nrF;
//     vector <int> stari_fin;
//     int sf;
//     for (int i = 0; i < nrF; i++){
//         f >> sf;
//         stari_fin.push_back(sf);
//     }

//     queue <int> q;
//     vector <int> v;
//     v.push_back(0);
//     q.push(0);
//     stari_dfa[nr_stari_dfa++] = v;

//     // cat timp coada nu e goala
//     while (!q.empty()){
//         int top = q.front();
//         q.pop();

//         // pt fiecare litera
//         for (int j = 0; j < litere.size(); j++){
//             vector <int> cur;
//             // pentru fiecare stare din 
//             for (int i = 0; i < stari_dfa[top].size(); i++){
//                 for (int k = 0; k < lista_adiacenta[stari_dfa[top][i]].size(); k++){
//                     if (litere[j] == lista_adiacenta[stari_dfa[top][i]][k].litera){
//                         int ok = 1;
//                         for (int h = 0; h < cur.size(); h++){
//                             if (cur[h] == lista_adiacenta[stari_dfa[top][i]][k].destinatie)
//                             ok = 0;
//                         }
//                         if (ok == 1)
//                             cur.push_back(lista_adiacenta[stari_dfa[top][i]][k].destinatie);
//                     }
//                 }
//             }
//             sort (cur.begin(), cur.end());

//             for (int i = 0 ; i < cur.size(); i ++)
//                 cout << cur[i];
//             cout << endl;

            
//             int ok = 1;
//             for (int i = 0; i < nr_stari_dfa; i++)
//                 if (cur == stari_dfa[i])
//                     ok = 0;

//             if (ok == 1){
//                 if (cur.size() == 0){
//                     cout << "dead_state" << "nr stari dfa " << nr_stari_dfa << endl;
                    
//                     // cur.push_back(nr_stari_dfa - litere.size() + j);
//                     stari_dfa[nr_stari_dfa] = cur;
//                     initial[nr_stari_dfa] = top;
//                     t_dfa[nr_stari_dfa] = litere[j];
//                     nr_stari_dfa++;
//                 }
//                 else{
//                 stari_dfa[nr_stari_dfa] = cur;
//                 q.push(nr_stari_dfa);
//                 initial[nr_stari_dfa] = top;
//                 t_dfa[nr_stari_dfa] = litere[j];
//                 nr_stari_dfa++;}
//             }
//             // else{
//             //     initial. push_back(-1);
//             //     t_dfa.push_back("-1");
//             // }
//         }
//     }
//     vector <vector<Tranzitie>> lista_adiacenta2(100,vector<Tranzitie>());
//     vector <int> finale_dfa;

//     cout << endl;
//     for (int i = 0; i < nr_stari_dfa; i++){
//          cout << "starea " << i << "[";
//         for (int j = 0; j < stari_dfa[i].size(); j++)
//             cout << stari_dfa[i][j] << " ";
//         cout << "]" << endl;}

//     int dead_state = -1;
//     for (int i = 0; i < nr_stari_dfa; i++){
//         if (stari_dfa[i].size() == 0){
//             dead_state = i;
//             stari_dfa[i].push_back(i);
//             //lista_adiacenta[i].clear();
//             for (int j = 0; j < litere.size(); j++){
//                 Tranzitie tr;
//                 tr.destinatie = dead_state;
//                 tr.litera = litere[j];
//                 //lista_adiacenta[dead_state].push_back(tr);
//                 lista_adiacenta2[dead_state].push_back(tr);
//             }
//         }
//     }

//     cout << "nr_stari_dfa: " << nr_stari_dfa << endl;
//     for (int i = 0; i < nr_stari_dfa; i++){
//          cout << "starea " << i << "[";
//         for (int j = 0; j < stari_dfa[i].size(); j++)
//             cout << stari_dfa[i][j] << " ";
//         cout << "]" << endl;
//         int ok = 0;    
//             for (int j = 0; j < stari_dfa[i].size(); j++){
//                 for (int k = 0; k < litere.size(); k++){
//                     vector <string> litere_intalnite;
//                     for (int l = 0; l < lista_adiacenta[stari_dfa[i][j]].size(); l++){
//                         if (litere[k] == lista_adiacenta[stari_dfa[i][j]][l].litera){
//                             ok = 1;
//                             litere_intalnite.push_back(lista_adiacenta[stari_dfa[i][j]][l].litera);
//                             cout << lista_adiacenta[stari_dfa[i][j]][l].destinatie << " " << lista_adiacenta[stari_dfa[i][j]][l].litera << endl;
//                             for (int b = 0; b < nrF; b++){
//                                 if (stari_dfa[i][j] == stari_fin[b])
//                                     finale_dfa.push_back(i);
//                             }
//                         }
//                     }
//                     if (ok == 0){
//                         Tranzitie tr;
//                         tr.destinatie = dead_state;
//                         tr.litera = litere[k];
//                         lista_adiacenta2[stari_dfa[i][j]].push_back(tr);
//                         //lista_adiacenta[stari_dfa[i][j]].push_back(tr);
//                         cout << "moarta";
//                         cout << tr.destinatie << " " << tr.litera << endl;
//                     }
//             }
//         }
//     }

//     cout << "fmm";
//     vector <vector<Tranzitie>> dfa(100,vector<Tranzitie>());
//     for (int i = 0; i < nr_stari_dfa; i++){
//         //cout << "I " << i << endl;
//         if (i != dead_state){
//              for (int k = 0; k < litere.size(); k++){
//                  cout << litere[k] << " ";
//                 vector <int> p;
//                 for (int j = 0; j < stari_dfa[i].size(); j++){
//                      //cout << i << " ";
//                 for (int l = 0; l < lista_adiacenta[stari_dfa[i][j]].size(); l++){
//                     if (lista_adiacenta[stari_dfa[i][j]][l].litera == litere[k]){
//                         cout << "destinatie " << lista_adiacenta[stari_dfa[i][j]][l].destinatie << endl;
//                         p.push_back(lista_adiacenta[stari_dfa[i][j]][l].destinatie);
//                     }   
//                 }
//                 }
//                 if (p.size() == 0){
//                     Tranzitie tr;
//                     tr.destinatie = lista_adiacenta2[dead_state][0].destinatie;
//                     tr.litera = litere[k];
//                     dfa[i].push_back(tr);
//                     cout << lista_adiacenta2[dead_state][0].destinatie << " " << litere[k] << endl;
//                 }
//                 else{
//                     cout << "????????????";
//                 sort(p.begin(), p.end());
//                 p.erase(unique(p.begin(), p.end()), p.end());
//                 cout << "a juns?";
//                 for (int l = 0; l < nr_stari_dfa; l++){
//                         if (stari_dfa[l] == p){
//                             Tranzitie tr;
//                             tr.destinatie = l;
//                             tr.litera = litere[k];
//                             dfa[i].push_back(tr);
//                             cout << "starea : "<< l << " " << litere[k] << endl;
//                         }
//                     }
//             }
//         }
//     }
//     else{
//         for (int k = 0; k < litere.size(); k++){
//             Tranzitie tr;
//             tr.destinatie = dead_state;
//             tr.litera = litere[k];
//             dfa[i].push_back(tr);
//         }
//     }
//     }
//     cout << "aici::::::::::" <<endl ;
//     for (int i = 0; i < nr_stari_dfa; i++){
//         cout << "starea: " << i << endl;
//         for (int j = 0; j < litere.size(); j++)
//             cout << dfa[i][j].destinatie << " " << dfa[i][j].litera << endl;
//     }

//     vector <vector<int>> m;
//     vector <int> n;

//     for (int i = 0; i < nr_stari_dfa; i++){
//         int ok = 1; 
//         for (int j = 0; j < finale_dfa.size(); j++){
//             if (i == finale_dfa[j])
//                 ok = 0;
//         }
//         if (ok == 1){
//             n.push_back(i);
//             cout << i;
//             }
//     }


//     sort(finale_dfa.begin(), finale_dfa.end());
//     finale_dfa.erase(unique(finale_dfa.begin(), finale_dfa.end()), finale_dfa.end());

//     cout << "finale " << endl;
//     for (int i = 0; i < finale_dfa.size(); i++)
//         cout << finale_dfa[i] << " ";


//     m.push_back(n);
//     m.push_back(finale_dfa);

//     cout << "minimizare: " << endl;

//     while (true){
//         vector <vector<int>> w;
//         vector <int> v;
//         v.push_back(m[0][0]);
//         w.push_back(v);
        
//         for (int i = 0; i < m.size(); i++){
//             if (m[i].size() > 1){
//                 for (int j = 1; j < m[i].size(); j++){
//                     int cont  = 1;
//                     for (int k = 0; k < w.size(); k++){
//                         int ok = 1;
//                         for (int h = 0; h < litere.size(); h++){
//                             int p = -1, q = -2;
//                             for (int g = 0; g < m.size(); g++){
//                                 for (int u = 0; u < m[g].size(); u++){
//                                     if (dfa[m[i][j]][h].destinatie == m[g][u]){
//                                         p = g;
//                                         cout << "p " <<p<<endl;
//                                     }
//                                     if (dfa[w[k][0]][h].destinatie == m[g][u]){
//                                         q = g;
//                                         cout << "q " <<q<<endl;
//                                     }
//                                 }
//                             }
//                             if (p != q)
//                                 ok = 0;
//                         }
//                         if (ok == 1){
//                             cont = 0;
//                             w[k].push_back(m[i][j]);
//                             break;
//                         }
//                     }
//                     if (cont == 1){
//                         vector <int> inter;
//                         cout << "m[i][j] " << m[i][j];
//                         inter.push_back(m[i][j]);
//                         w.push_back(inter);
//                     }
//                 }
//             }
//             else{
//                 vector <int> inter;
//                 inter.push_back(m[i][0]);
//                 w.push_back(inter);
//             }
//         }
//         if (m == w){
//             // for (int i = 0; i < w.size(); i++){
//             //     cout << endl;
//             //     for (int j = 0; j < w[i].size(); j++){
//             //         cout << w[i][j] << " ";
//             //     }
//             // }
//             cout << "egale" << endl;
//             break;
//             }
//         else{
//             cout << "aici" << endl;
//             m = w;
//             }
//     }

//     cout << "afisare" ;
//     for (int i = 0 ; i < m.size() ; i++){
//         for (int j = 0 ; j < m[i].size(); j++){
//             cout << m[i][j] << " ";
//         }
//         cout << endl;
//     }


//     // cout << "Starea moarta: " << dead_state << endl;

//     // cout << "nou : " << endl;
//     // for (int i = 0; i < nr_stari_dfa; i++){
//     //     for (int k = 0; k < litere.size(); k++){
//     //         vector <int> stari_intermediare;
//     //         cout << i << endl;
//     //     for (int j = 0; j < stari_dfa[i].size(); j++){
//     //             for (int l = 0; l < lista_adiacenta[stari_dfa[i][j]].size(); l++){
//     //                     if (lista_adiacenta[stari_dfa[i][j]][l].litera == litere[k]){
//     //                         stari_intermediare.push_back(lista_adiacenta[stari_dfa[i][j]][l].destinatie);
//     //                     }
//     //             }
//     //         }
//     //         sort(stari_intermediare.begin(), stari_intermediare.end());
//     //         auto lst = unique(stari_intermediare.begin(), stari_intermediare.end());
//     //         stari_intermediare.erase(lst, stari_intermediare.end());

//     //         if (stari_intermediare.size() == 0){
//     //             // cout << lista_adiacenta[dead_state][0].destinatie << " " << lista_adiacenta[dead_state][0].litera << endl;
//     //             cout << "aici" << lista_adiacenta2[dead_state][0].destinatie << " " << litere[k]<< endl;
//     //         }
//     //         else{

//     //         for (int l = 0; l < nr_stari_dfa; l++){
//     //                 if (stari_dfa[l] == stari_intermediare){
//     //                     Tranzitie tr;
//     //                     tr.destinatie = l;
//     //                     tr.litera = litere[k];
//     //                     cout << tr.destinatie << " " << tr.litera << endl;
//     //                     lista_adiacenta2[i].push_back(tr);
//     //                 }
//     //             }}
//     //     }
//     // }

//     // sort(finale_dfa.begin(), finale_dfa.end());
//     // auto ls = unique(finale_dfa.begin(), finale_dfa.end());
//     // finale_dfa.erase(ls, finale_dfa.end());

//     // cout << "stari finale: " << endl;
//     // for (int i = 0; i < finale_dfa.size(); i++)
//     //     cout << finale_dfa[i] << " ";
    
//     return 0;
// }

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

// struct Element{
//     int start;
//     int indice;
// };

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
            vector <int> cur;
            // pentru fiecare stare din
            for (int i = 0; i < stari_dfa[top].size(); i++){
                for (int k = 0; k < lista_adiacenta[stari_dfa[top][i]].size(); k++){
                    if (litere[j] == lista_adiacenta[stari_dfa[top][i]][k].litera){
                        int ok = 1;
                        for (int h = 0; h < cur.size(); h++){
                            if (cur[h] == lista_adiacenta[stari_dfa[top][i]][k].destinatie)
                            ok = 0;
                        }
                        if (ok == 1)
                            cur.push_back(lista_adiacenta[stari_dfa[top][i]][k].destinatie);
                    }
                }
            }
            sort (cur.begin(), cur.end());

            for (int i = 0 ; i < cur.size(); i ++)
                cout << cur[i];
            cout << endl;


            int ok = 1;
            for (int i = 0; i < nr_stari_dfa; i++)
                if (cur == stari_dfa[i])
                    ok = 0;

            if (ok == 1){
                if (cur.size() == 0){
                    cout << "dead_state" << "nr stari dfa " << nr_stari_dfa << endl;

                    // cur.push_back(nr_stari_dfa - litere.size() + j);
                    stari_dfa[nr_stari_dfa] = cur;
                    initial[nr_stari_dfa] = top;
                    t_dfa[nr_stari_dfa] = litere[j];
                    nr_stari_dfa++;
                }
                else{
                stari_dfa[nr_stari_dfa] = cur;
                q.push(nr_stari_dfa);
                initial[nr_stari_dfa] = top;
                t_dfa[nr_stari_dfa] = litere[j];
                nr_stari_dfa++;}
            }
            // else{
            //     initial. push_back(-1);
            //     t_dfa.push_back("-1");
            // }
        }
    }
    vector <vector<Tranzitie>> lista_adiacenta2(100,vector<Tranzitie>());
    vector <int> finale_dfa;

    cout << endl;
    for (int i = 0; i < nr_stari_dfa; i++){
         cout << "starea " << i << "[";
        for (int j = 0; j < stari_dfa[i].size(); j++)
            cout << stari_dfa[i][j] << " ";
        cout << "]" << endl;}

    int dead_state = -1;
    for (int i = 0; i < nr_stari_dfa; i++){
        if (stari_dfa[i].size() == 0){
            dead_state = i;
            stari_dfa[i].push_back(i);
            //lista_adiacenta[i].clear();
            for (int j = 0; j < litere.size(); j++){
                Tranzitie tr;
                tr.destinatie = dead_state;
                tr.litera = litere[j];
                //lista_adiacenta[dead_state].push_back(tr);
                lista_adiacenta2[dead_state].push_back(tr);
            }
        }
    }

    cout << "nr_stari_dfa: " << nr_stari_dfa << endl;
    for (int i = 0; i < nr_stari_dfa; i++){
         cout << "starea " << i << "[";
        for (int j = 0; j < stari_dfa[i].size(); j++)
            cout << stari_dfa[i][j] << " ";
        cout << "]" << endl;
        int ok = 0;
            for (int j = 0; j < stari_dfa[i].size(); j++){
                for (int k = 0; k < litere.size(); k++){
                    vector <string> litere_intalnite;
                    for (int l = 0; l < lista_adiacenta[stari_dfa[i][j]].size(); l++){
                        if (litere[k] == lista_adiacenta[stari_dfa[i][j]][l].litera){
                            ok = 1;
                            litere_intalnite.push_back(lista_adiacenta[stari_dfa[i][j]][l].litera);
                            cout << lista_adiacenta[stari_dfa[i][j]][l].destinatie << " " << lista_adiacenta[stari_dfa[i][j]][l].litera << endl;
                            for (int b = 0; b < nrF; b++){
                                if (stari_dfa[i][j] == stari_fin[b])
                                    finale_dfa.push_back(i);
                            }
                        }
                    }
                    if (ok == 0){
                        Tranzitie tr;
                        tr.destinatie = dead_state;
                        tr.litera = litere[k];
                        lista_adiacenta2[stari_dfa[i][j]].push_back(tr);
                        //lista_adiacenta[stari_dfa[i][j]].push_back(tr);
                        cout << "moarta";
                        cout << tr.destinatie << " " << tr.litera << endl;
                    }
            }
        }
    }

    cout << "fmm";
    vector <vector<Tranzitie>> dfa(100,vector<Tranzitie>());
    for (int i = 0; i < nr_stari_dfa; i++){
        //cout << "I " << i << endl;
        if (i != dead_state){
             for (int k = 0; k < litere.size(); k++){
                 cout << litere[k] << " ";
                vector <int> p;
                for (int j = 0; j < stari_dfa[i].size(); j++){
                     //cout << i << " ";
                for (int l = 0; l < lista_adiacenta[stari_dfa[i][j]].size(); l++){
                    if (lista_adiacenta[stari_dfa[i][j]][l].litera == litere[k]){
                        cout << "destinatie " << lista_adiacenta[stari_dfa[i][j]][l].destinatie << endl;
                        p.push_back(lista_adiacenta[stari_dfa[i][j]][l].destinatie);
                    }
                }
                }
                if (p.size() == 0){
                    Tranzitie tr;
                    tr.destinatie = lista_adiacenta2[dead_state][0].destinatie;
                    tr.litera = litere[k];
                    dfa[i].push_back(tr);
                    cout << lista_adiacenta2[dead_state][0].destinatie << " " << litere[k] << endl;
                }
                else{
                    cout << "????????????";
                sort(p.begin(), p.end());
                p.erase(unique(p.begin(), p.end()), p.end());
                cout << "a juns?";
                for (int l = 0; l < nr_stari_dfa; l++){
                        if (stari_dfa[l] == p){
                            Tranzitie tr;
                            tr.destinatie = l;
                            tr.litera = litere[k];
                            dfa[i].push_back(tr);
                            cout << "starea : "<< l << " " << litere[k] << endl;
                        }
                    }
            }
        }
    }
    else{
        for (int k = 0; k < litere.size(); k++){
            Tranzitie tr;
            tr.destinatie = dead_state;
            tr.litera = litere[k];
            dfa[i].push_back(tr);
        }
    }
    }
    cout << "aici::::::::::" <<endl ;
    for (int i = 0; i < nr_stari_dfa; i++){
        cout << "starea: " << i << endl;
        for (int j = 0; j < litere.size(); j++)
            cout << dfa[i][j].destinatie << " " << dfa[i][j].litera << endl;
    }

    vector <vector<int>> m;
    vector <int> n;

    for (int i = 0; i < nr_stari_dfa; i++){
        int ok = 1;
        for (int j = 0; j < finale_dfa.size(); j++){
            if (i == finale_dfa[j])
                ok = 0;
        }
        if (ok == 1){
            n.push_back(i);
            cout << i;
            }
    }


    sort(finale_dfa.begin(), finale_dfa.end());
    finale_dfa.erase(unique(finale_dfa.begin(), finale_dfa.end()), finale_dfa.end());

    cout << "finale " << endl;
    for (int i = 0; i < finale_dfa.size(); i++)
        cout << finale_dfa[i] << " ";


    m.push_back(n);
    m.push_back(finale_dfa);

    cout << "minimizare: " << endl;

    while (true){
        vector <vector<int>> w;
        //vector <int> v;
        //v.push_back(m[0][0]);
        //w.push_back(v);

        for (int i = 0; i < m.size(); i++){
            if (m[i].size() > 1){
                for (int j = 0; j < m[i].size(); j++){
                    int cont  = 1;
                    for (int k = 0; k < w.size(); k++){
                        int ok = 1;
                        for (int h = 0; h < litere.size(); h++){
                            int p = -1, q = -2;
                            for (int g = 0; g < m.size(); g++){
                                for (int u = 0; u < m[g].size(); u++){
                                    if (dfa[m[i][j]][h].destinatie == m[g][u]){
                                        p = g;
                                        cout << "p " <<p<<endl;
                                    }
                                    if (dfa[w[k][0]][h].destinatie == m[g][u]){
                                        q = g;
                                        cout << "q " <<q<<endl;
                                    }
                                }
                            }
                            if (p != q)
                                ok = 0;
                        }
                        if (ok == 1){
                            cont = 0;
                            w[k].push_back(m[i][j]);
                            break;
                        }
                    }
                    if (cont == 1){
                        vector <int> inter;
                        inter.push_back(m[i][j]);
                        w.push_back(inter);
                    }
                }
            }
            else{
                vector <int> inter;
                inter.push_back(m[i][0]);
                w.push_back(inter);
            }
        }
        if (m == w){
            // for (int i = 0; i < w.size(); i++){
            //     cout << endl;
            //     for (int j = 0; j < w[i].size(); j++){
            //         cout << w[i][j] << " ";
            //     }
            // }
            break;
            }
        else{
            m = w;
            }
    }

    vector <vector<Tranzitie>> minimizare(100,vector<Tranzitie>());
    cout << "afisare" ;
    for (int i = 0 ; i < m.size() ; i++){
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
                    tr.destinatie = j;
                    minimizare[i].push_back(tr);
                }
            }
            cout << endl;
        }
    }

    for (int i = 0; i < minimizare.size(); i++){
        for (int j = 0; j < litere.size(); j++){
            cout << i << " " << minimizare[i][j].destinatie << " " << minimizare[i][j].litera << endl;
        }
    }


    // cout << "Starea moarta: " << dead_state << endl;

    // cout << "nou : " << endl;
    // for (int i = 0; i < nr_stari_dfa; i++){
    //     for (int k = 0; k < litere.size(); k++){
    //         vector <int> stari_intermediare;
    //         cout << i << endl;
    //     for (int j = 0; j < stari_dfa[i].size(); j++){
    //             for (int l = 0; l < lista_adiacenta[stari_dfa[i][j]].size(); l++){
    //                     if (lista_adiacenta[stari_dfa[i][j]][l].litera == litere[k]){
    //                         stari_intermediare.push_back(lista_adiacenta[stari_dfa[i][j]][l].destinatie);
    //                     }
    //             }
    //         }
    //         sort(stari_intermediare.begin(), stari_intermediare.end());
    //         auto lst = unique(stari_intermediare.begin(), stari_intermediare.end());
    //         stari_intermediare.erase(lst, stari_intermediare.end());

    //         if (stari_intermediare.size() == 0){
    //             // cout << lista_adiacenta[dead_state][0].destinatie << " " << lista_adiacenta[dead_state][0].litera << endl;
    //             cout << "aici" << lista_adiacenta2[dead_state][0].destinatie << " " << litere[k]<< endl;
    //         }
    //         else{

    //         for (int l = 0; l < nr_stari_dfa; l++){
    //                 if (stari_dfa[l] == stari_intermediare){
    //                     Tranzitie tr;
    //                     tr.destinatie = l;
    //                     tr.litera = litere[k];
    //                     cout << tr.destinatie << " " << tr.litera << endl;
    //                     lista_adiacenta2[i].push_back(tr);
    //                 }
    //             }}
    //     }
    // }

    // sort(finale_dfa.begin(), finale_dfa.end());
    // auto ls = unique(finale_dfa.begin(), finale_dfa.end());
    // finale_dfa.erase(ls, finale_dfa.end());

    // cout << "stari finale: " << endl;
    // for (int i = 0; i < finale_dfa.size(); i++)
    //     cout << finale_dfa[i] << " ";

    return 0;
}



