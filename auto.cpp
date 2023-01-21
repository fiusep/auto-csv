#include <iostream>
#include <fstream>
#define file "auto.csv"
using namespace std;

struct automobile{
    string categoria, marca, modello, colore, giorni[7];
};

void controllo(automobile affitto[], string cat, string gio[], int c)
{
    int x = 0;

    ifstream fin(file);

    while(!fin.eof())
    {
        getline (fin, affitto[x].categoria, ',');
        cout<<affitto[x].categoria;
        getline (fin, affitto[x].marca, ',');
        cout<<affitto[x].marca;
        getline (fin, affitto[x].modello, ',');
        cout<<affitto[x].modello;
        getline (fin, affitto[x].colore, ',');
        cout<<affitto[x].colore;

        for(int j = 0; j < 7; j++){
                if(j == 6)
                    getline (fin, affitto[x].giorni[j]);
                else getline (fin, affitto[x].giorni[j], ',');
            cout<<affitto[x].giorni[j];
        }
        x++;
        cout<<endl;
    }

    cout<<"le macchine che potrebbero interessarti sono: "<<endl;

    for(int a = 0; a <= c; a++)
    {
        if (cat == affitto[a].categoria){
            for(int g = 0; g < 7; g++){
                if(gio[g] == to_string(g) && affitto[a].giorni[g] == "L"){
                    affitto[a].giorni[g] = "A";
                    }
            }
            cout<<a+1<<"> "<<affitto[a].marca<<" "<<affitto[a].modello<<" "<<affitto[a].colore<<endl;
        }
    }
    cout<<endl;
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
        cout<<"scegli la categoria dell'auto che ti interessa: ";
        cin>>cat;
        }while(cat != "utilitaria" && cat != "media" && cat != "lusso" && cat != "sportiva" && cat != "furgone");

        int cont;

        do
        {
            do
            {
                cout<<"inserisci i giorni in cui vuoi affittare la macchina (0 per uscire): ";
                cin >> cont;

                if(cont >= 8 || cont < 0)
                    cout<<"scelta non valida"<<endl;

                if (cont > 0 && cont < 8)
                    gio[cont-1] = to_string(cont);

            }while(cont >= 8 || cont < 0);
        }while(cont != 0);
        cout<<endl;

        controllo(affitto, cat, gio, c);
    }
}

int main()
{
    menu();
    return 0;
}