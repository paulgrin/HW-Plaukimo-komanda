#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
+ Konstruktorių be parametrų ir konstruktorių su parametrais
+ Metodus objekto savybių keitimui (set) ir nuskaitymui (get)
+ Duomenų nuskaitymą iš failo į objektų masyvą ir peržiūrą ekrane
Suprogramuotą paieškos funkcijų perkrovimą
+ Išsamų dialogą su vartotoju
+ Papildomai galima papildyti sarasa, sumazinti sarasa (istrinti norimus asmenis) ir issaugoti vel faila (failo redagavimas)
*/

/*
- plaukimo komanda
Irasai: vardas, pavarde, lytis, ugis, svoris, plaukimo greitis

Realizuota:
+ pasirinktos lyties vidutinio greicio ir svorio skaiciavimas;
+ paieska pagal sportininko varda ir pavarde;
+ paieska pagal sportininko varda, pavarde, lyti ir plaukimo greiti;
+ pasirinktos lyties sportininku rikiavimas pagal varda ir plaukimo greiti;
*/

class Plaukikas
{
private:
    string vardas, pavarde;
    int lytis;
    float ugis, svoris, greitis;
    int viso = 0;

public:
    // ========================================================== //
    Plaukikas(){ // Tuscias konstruktorius
        vardas = "Nenurodyta";
        pavarde = "Nenurodyta";
        lytis = 0;
        ugis = 0;
        svoris = 0;
        greitis = 0;
        viso++;
    }

    Plaukikas(string v, string p, int l, float u, float s, float g){
        vardas = v; pavarde = p; lytis = l, ugis = u, svoris = s, greitis = g;
    }
    // ========================================================== //

    string getVardas() { return vardas; }
    void setVardas(string v) { vardas = v; }

    string getPavarde() { return pavarde; }
    void setPavarde(string p) { pavarde = p; }

    int getLytis() { return lytis; }
    void setLytis(int l) { lytis = l; }

    float getUgis() { return ugis; }
    void setUgis(float u) { ugis = u; }

    float getSvoris() { return svoris; }
    void setSvoris(float s) { svoris = s;}

    float getGreitis() { return greitis; }
    void setGreitis(float g) { greitis = g; }

    int getViso() { return viso; }
    void setViso(int v) { viso = v; }
};

int main()
{
    int i, irasu = 0, lytis = 0;
    string vardas, pavarde;
    float ugis, svoris, greitis;
    Plaukikas p[20];

    ifstream plaukikai("plaukikai.txt");

    while(!plaukikai.eof())
    {
        plaukikai >> vardas >> pavarde >> lytis >> ugis >> svoris >> greitis;
        p[irasu].setVardas(vardas);
        p[irasu].setPavarde(pavarde);
        p[irasu].setLytis(lytis);
        p[irasu].setUgis(ugis);
        p[irasu].setSvoris(svoris);
        p[irasu].setGreitis(greitis);
        irasu++;
    }
    plaukikai.close();
    irasu--; // kad nesikartotu informacija;

    cout << "@ Duomenys perskaityti. Vykdoma programa..." << endl << endl;

    cout << "@ Registruotu plaukiku sarasas: " << endl;
    for(i = 0; i < irasu; i++)
    {
        cout << i+1 << ". " + p[i].getVardas() + " " + p[i].getPavarde();
        if(p[i].getLytis() == 1) cout << " Vyras ";
        else if(p[i].getLytis() == 2) cout << " Moteris ";
        cout << p[i].getUgis() << "CM " << p[i].getSvoris() << "KG " << p[i].getGreitis() << "KM/H" << endl;
    }

    cout << endl << "Galimos funkcijos: " << endl;
    cout << "[1] Naujo plaukiko ivestis;" << endl;
    cout << "[2] Plaukiko trinimas;" << endl;
    cout << "[3] Paieska pagal viena plaukiko aspekta;" << endl;
    cout << "[4] Rikiavimas pagal varda ir/arba plaukimo greiti;" << endl;
    cout << "[5] Rasti svorio ir/arba greicio vidurkius pagal lyti;" << endl;
    //cout << "[6] Paieska pagal varda ir pavarde;" << endl;
    //cout << "[7] Paieska pagal varda, pavarde, lyti ir greiti;" << endl;
    cout << "[0] Baigti programos darba." << endl;

    int funkcija;
    cout << endl << "[IVESTI] Iveskite funkcijos ID: ";
    cin >> funkcija;

    while(funkcija != 0)
    {
        switch(funkcija)
        {
            case 0: break; // ========== Uzdaryti programa ============== //
            case 1:{ // =========== Naujo plaukiko ivedimas ============ //
                    cout << endl << "@NAUJO SPORTININKO IVESTIS. \nIveskite '0', kad atsaukti." << endl;
                    cout << "[IVESTI] Vardas: "; cin >> vardas;
                    if(vardas == "0") break;

                    cout << "[IVESTI] Pavarde: "; cin >> pavarde;
                    if(pavarde == "0") break;

                    cout << "[IVESTI] Lytis (1 - vyras, 2 - moteris): "; cin >> lytis;
                    if(lytis == 0) break;

                    cout << "[IVESTI] Ugis: "; cin >> ugis;
                    if(ugis == 0) break;

                    cout << "[IVESTI] Svoris: "; cin >> svoris;
                    if(svoris == 0) break;

                    cout << "[IVESTI] Greitis: "; cin >> greitis;
                    if(greitis == 0) break;

                    p[irasu].setVardas(vardas);
                    p[irasu].setPavarde(pavarde);
                    p[irasu].setLytis(lytis);
                    p[irasu].setUgis(ugis);
                    p[irasu].setSvoris(svoris);
                    p[irasu].setGreitis(greitis);

                    cout << "@ Duomenys apie plaukika surinkti: " << endl;

                    cout << irasu << ". " + vardas + " " + pavarde;
                    if(lytis == 1) cout << " Vyras ";
                    else cout << " Moteris ";
                    cout << ugis << "CM " << svoris << "KG " << greitis << "KM/H"<< endl << endl;
                    irasu++;
                    break;
                }

            case 2:{ // ============== Istrinti plaukika ============= //
                    cout << endl << "@ PLAUKIKO TRINIMAS. Iveskite '0 0' norint atsaukti" << endl;
                    cout << "[IVESTI] Vardas Pavarde: "; cin >> vardas >> pavarde;
                    if(vardas == "0") break;

                    bool ArIstrinta = false;
                    for(i = 0; i < irasu; i++)
                    {
                        if(p[i].getVardas() == vardas && p[i].getPavarde() == pavarde)
                        {
                            for(int a = i, b = i+1; a < irasu; a++, b++){ p[a] = p[b];}
                            cout << "@ Plaukikas istrintas sekmingai." << endl << endl;
                            ArIstrinta = true;
                            irasu--;
                            break;
                        }
                    }
                    if(ArIstrinta == false) cout << "Plaukikas nerastas... " << endl << endl;
                    break;
                }

            case 3:{ // =========== Paieska pagal viena aspekta ========== //
                    int paieska;
                    cout << endl << "@ PLAUKIKU PAIESKA. Iveskite '0' norint atsaukti." << endl;
                    cout << "[1] Paieska pagal varda" << endl;
                    cout << "[2] Paieska pagal pavarde" << endl;
                    cout << "[3] Paieska pagal lyti" << endl;
                    cout << "[4] Paieska pagal greiti" << endl;
                    cout << "[0] Atsaukti paieska" << endl;
                    cout << "[IVESTI] Pasirinkite paieska ivesdami jos numeri: ";
                    cin >> paieska;

                    switch(paieska)
                    {
                        case 0: break;
                        case 1:{
                                cout << "[IVESTI] Vardas: "; cin >> vardas;
                                cout << "@ Ieskomi rezultatai..." << endl;
                                int rasta = 0;

                                for(i = 0; i < irasu; i++){
                                    if(p[i].getVardas() == vardas){
                                        cout << "> " + p[i].getVardas() + " " + p[i].getPavarde();
                                        if(p[i].getLytis() == 1) cout << " Vyras ";
                                        else cout << " Moteris ";
                                        cout << p[i].getUgis() << " " << p[i].getSvoris() << " " << p[i].getGreitis() << endl;
                                        rasta ++;
                                    }
                                }
                                if(rasta == 0) cout << "@ Rezultatu su vardu " + vardas + " nerasta..." << endl << endl;
                                else cout << "@ Rasta " << rasta << " rezultatai(-as)." << endl << endl;
                                break;
                            }
                        case 2:{
                                cout << "[IVESTI] Pavarde: "; cin >> pavarde;
                                cout << "@ Ieskomi rezultatai..." << endl;
                                int rasta = 0;

                                for(i = 0; i < irasu; i++){
                                    if(p[i].getPavarde() == pavarde){
                                        cout << "> " + p[i].getVardas() + " " + p[i].getPavarde();
                                        if(p[i].getLytis() == 1) cout << " Vyras ";
                                        else cout << " Moteris ";
                                        cout << p[i].getUgis() << " " << p[i].getSvoris() << " " << p[i].getGreitis() << endl;
                                        rasta ++;
                                    }
                                }
                                if(rasta == 0) cout << "@ Rezultatu su vardu " + pavarde + " nerasta..." << endl << endl;
                                else cout << "@ Rasta " << rasta << " rezultatai(-as)" << endl << endl;
                                break;
                            }
                        case 3:{
                                cout << "[IVESTI] Lytis (1 - vyras arba 2 - moteris): "; cin >> lytis;
                                cout << "@ Ieskomi rezultatai..." << endl;
                                int rasta = 0;

                                for(i = 0; i < irasu; i++){
                                    if(p[i].getLytis() == lytis){
                                        cout << "> " + p[i].getVardas() + " " + p[i].getPavarde();
                                        if(p[i].getLytis() == 1) cout << " Vyras ";
                                        else cout << " Moteris ";
                                        cout << p[i].getUgis() << " " << p[i].getSvoris() << " " << p[i].getGreitis() << endl;
                                        rasta ++;
                                    }
                                }
                                if(rasta == 0) cout << "Rezultatu nerasta" << endl << endl;
                                else cout << "@ Rasta " << rasta << " rezultatai(-as)" << endl << endl;
                                break;
                            }
                        case 4:{
                                float mingreitis = 0, maxgreitis = 0;
                                cout << "[IVESTI] Greitis([min] [max]): "; cin >> mingreitis >> maxgreitis;
                                cout << "@ Ieskomi rezultatai..." << endl;
                                int rasta = 0;

                                for(i = 0; i < irasu; i++){
                                    if(p[i].getGreitis() >= mingreitis && p[i].getGreitis() <= maxgreitis){
                                        cout << "> " +p[i].getVardas() + " " + p[i].getPavarde();
                                        if(p[i].getLytis() == 1) cout << " Vyras ";
                                        else cout << " Moteris ";
                                        cout << p[i].getUgis() << " " << p[i].getSvoris() << " " << p[i].getGreitis() << endl;
                                        rasta ++;
                                    }
                                }
                                if(rasta == 0) cout << "Rezultatu su greiciais " << mingreitis << " - " << maxgreitis << " nerasta...";
                                else cout << "@ Rasta " << rasta << " rezultatai(-as)" << endl << endl;
                                break;
                            }
                    }
                    break;
                }
            case 4:{ // =============== RIKIAVIMAS PAGAL VARDA IR GREITI ================== //
                int tipas;
                cout << "@ RIKIAVIMAS. Iveskite '0' norint atsaukti." << endl;
                cout << "[IVESTI] Rikiavimo budas (ID) (1 - vardas arba 2 - greitis): ";
                cin >> tipas;

                Plaukikas temp;
                switch(tipas)
                {
                case 0: break;
                case 1:{
                        cout << "@ Rikiuojama pagal varda..." << endl;
                        for(int i = 0; i < irasu; i++){
                            for(int j = 0; j < irasu; j++){
                                if(p[i].getVardas() > p[j].getVardas()){
                                    temp = p[i];
                                    p[i] = p[j];
                                    p[j] = temp;
                                }
                            }
                        }
                        break;
                    }
                case 2:{
                        cout << "@ Rikiuojama pagal greiti..." << endl;
                        for(int i = 0; i < irasu; i++){
                            for(int j = 0; j < irasu; j++){
                                if(p[i].getGreitis() < p[j].getGreitis()){
                                    temp = p[i];
                                    p[i] = p[j];
                                    p[j] = temp;
                                }
                            }
                        }
                    }
                    break;
                }
                for(int i = 0; i < irasu; i++)
                {
                    cout << "> " +p[i].getVardas() + " " + p[i].getPavarde();
                    if(p[i].getLytis() == 1) cout << " Vyras ";
                    else cout << " Moteris ";
                    cout << p[i].getUgis() << "CM " << p[i].getSvoris() << "KG " << p[i].getGreitis() << "KM/H"<< endl << endl;
                }
                break;
            }
            case 5:{ // ============== Greicio ir svorio vidurkiai ========== //
                cout << "@ VIDURKIAI. "<< endl;

                float vidgreitis = 0, vidsvoris = 0;
                for(int i = 0; i < irasu; i++)
                {
                    vidgreitis += p[i].getGreitis();
                    vidsvoris += p[i].getSvoris();
                }
                cout << "@ Vidutinis greitis: " << vidgreitis / irasu << "KM/H; Vidutinis svoris: " << vidsvoris / irasu << "KG." << endl << endl;
                break;
            }
            // JEIGU DESTYTOJAS TUREJO OMENY TIKSLIAS PAIESKAS //
            /*case 6: // ============= Paieska pagal varda ir pavarde ============== //
                {
                    cout << "PLAUKIKO PAIESKA. Iveskite '0 0' norint atsaukti." << endl;
                    cout << "[IVESTIS] Vardas Pavarde: "; cin >> vardas >> pavarde;

                    if(vardas == "0") break;

                    bool ArRasta = false;
                    cout << "Ieskoma " << vardas + " " + pavarde << endl;
                    for(i = 0; i < irasu; i++)
                    {
                        if(p[i].getVardas() == vardas && p[i].getPavarde() == pavarde)
                        {
                            cout << p[i].getVardas() + " " + p[i].getPavarde();
                            if(p[i].getLytis() == 1) cout << " Vyras ";
                            else cout << " Moteris ";
                            cout << p[i].getUgis() << " " << p[i].getSvoris() << " " << p[i].getGreitis() << endl;
                            ArRasta = true;
                        }
                    }
                    if(ArRasta == false) cout << "Plaukikas nerastas... " << endl << endl;
                    break;
                }
            case 7: // ============ paieska pagal varda, pavarde, lyti ir greiti ============= //
                {
                    cout << "PLAUKIKO PAIESKA. Iveskite '0' bet kuriuo metu norint atsaukti." << endl;
                    cout << "[IVESTI] Vardas: "; cin >> vardas;
                    if(vardas == "0") break;

                    cout << "[IVESTI] Pavarde: "; cin >> pavarde;
                    if(pavarde == "0") break;

                    cout << "[IVESTI] Lytis (1 - vyras, 2 - moteris): "; cin >> lytis;
                    if(lytis == 0) break;

                    cout << "[IVESTI] Greitis: "; cin >> greitis;
                    if(greitis == 0) break;

                    bool ArRasta = false;
                    cout << "Ieskoma rezultatu ..." << endl;
                    for(i = 0; i < irasu; i++)
                    {
                        if(p[i].getVardas() == vardas && p[i].getPavarde() == pavarde && p[i].getLytis() == lytis && p[i].getGreitis() == greitis)
                        {
                            cout << p[i].getVardas() + " " + p[i].getPavarde();
                            if(p[i].getLytis() == 1) cout << " Vyras ";
                            else cout << " Moteris ";
                            cout << p[i].getUgis() << " " << p[i].getSvoris() << " " << p[i].getGreitis() << endl;
                            ArRasta = true;
                        }
                    }
                    if(ArRasta == false) cout << "Plaukikas nerastas... " << endl << endl;
                    break;
                }*/
        }
        cout << "[IVESTI] Pasirinkite funkcija: ";
        cin >> funkcija;
    }
    cout << "Programa baigia darba..." << endl << endl;

    ofstream plaukikaii("plaukikai.txt");
    for(int i = 0; i < irasu; i++)
    {
        plaukikaii << p[i].getVardas() << " " << p[i].getPavarde() << " " << p[i].getLytis() << " " << p[i].getUgis() << " " << p[i].getSvoris() << " " << p[i].getGreitis() << endl;
    }
    plaukikaii.close();
    return 1;
}
