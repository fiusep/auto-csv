#include <iostream>
#include <fstream>
#define file "auto.csv"
using namespace std;

struct automobile{
    string categoria, marca, modello, colore, giorni[7];
    string marcasc, modellosc, coloresc;
};

void controllo(automobile affitto[], string cat, string gio[], int c, int magg)
{
    int x = 0, sc = 0, scl, m = 0;;

    ifstream fin(file);

    while(!fin.eof())
    {
        getline (fin, affitto[x].categoria, ',');
        getline (fin, affitto[x].marca, ',');
        getline (fin, affitto[x].modello, ',');
        getline (fin, affitto[x].colore, ',');

        for(int j = 0; j < 7; j++){
                if(j == 6)
                    getline (fin, affitto[x].giorni[j]);
                else getline (fin, affitto[x].giorni[j], ',');
        }
        x++;
        cout<<endl;
    }

    system("cls");

    cout<<"le macchine che potrebbero interessarti sono: "<<endl;

    bool check = false;
    int contatore = 0;

    for(int a = 0; a <= c; a++)
    {
        if (cat == affitto[a].categoria){
            for(int g = 0; g < 7; g++){
                if(gio[g] != "" && affitto[a].giorni[g] == " L"){
                contatore++;
                }
            }
            if(contatore == magg)
            check = true;
        }
        if(check && contatore == magg)
        {
            cout<<sc+1<<">"<<affitto[a].marca<<affitto[a].modello<<affitto[a].colore<<endl;
            affitto[sc].marcasc = affitto[a].marca;
            affitto[sc].modellosc = affitto[a].modello;
            affitto[sc].coloresc = affitto[a].colore;
            check = false;
            sc++;
        }
        contatore = 0;
    }

    cout<<"0> Nessuna di queste\n>> ";
    cin>>scl;

    if (scl != 0){
        for (int j = 0; j < c; j++)
              {
                   if (affitto[scl-1].marcasc == affitto[j].marca && affitto[scl-1].modellosc == affitto[j].modello && affitto[scl-1].coloresc == affitto[j].colore)
                   {
                       for (int g = 0; g < 7; g++)
                       {
                           if(gio[g] != "" && affitto[j].giorni[g] == " L")
                              affitto[j].giorni[g] = " A";
                       }
                   }
              }

    ofstream fout(file);
    for(int q = 0; q < c-1; q++){
        fout<<affitto[q].categoria<<","<<affitto[q].marca<<","<<affitto[q].modello<<","<<affitto[q].colore<<",";
                for(int j = 0; j < 7; j++){
                    if (j == 6)
                        fout<<affitto[q].giorni[j];
                    else fout<<affitto[q].giorni[j]<<",";
                }
        fout<<endl;
        }

    fout.close();

    cout<<endl;
    }
}

int menu()
{
    while(true)
    {
        ifstream fin(file);

        string appoge, cat, gio[7]; int c=0;
        cout<<"-----------------------------------------------------"<<endl;
        while(!fin.eof())
        {
            c++;
            getline(fin,appoge);
            cout<<appoge<<endl;
        }
        cout<<"------------------------------------------------------"<<endl<<endl;

        fin.close();

        automobile affitto[c];

        do{
        cout<<"scegli la categoria dell'auto che ti interessa (0 per uscire): ";
        cin>>cat;
            if (cat == "0"){
                cout<<endl<<"Grazie, torni a trovarci!!"<<endl;
                return 0;
                }
        }while(cat != "utilitaria" && cat != "media" && cat != "lusso" && cat != "sportiva" && cat != "furgone");

        int cont, magg = 0;

        do
        {
            do
            {
                cout<<"inserisci i giorni in cui vuoi affittare la macchina (0 per uscire): ";
                cin >> cont;

                if(cont >= 8 || cont < 0)
                    cout<<"scelta non valida"<<endl;

                if (cont > 0 && cont < 8){
                    gio[cont-1] = to_string(cont);
                    if (cont > magg)
                        magg = cont;
                }

            }while(cont >= 8 || cont < 0);
        }while(cont != 0);
        cout<<endl;

        controllo(affitto, cat, gio, c, magg);
    }
}

int main()
{
    menu();
    return 0;
}
