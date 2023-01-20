#include <iostream>
#include <fstream>
#define file "auto.csv"
using namespace std;

struct automobile{
    string categoria, marca, modello, colore, giorni[7];
};

void controllo(automobile affitto[], string cat, string gio[])
{
    int c = 0;

    ifstream fin(file);

    while(!fin.eof())
    {
        fin >> affitto[c].categoria;
        fin >> affitto[c].marca;
        fin >> affitto[c].modello;
        fin >> affitto[c].colore;

        for(int j = 0; j < 7; j++)
            fin >> affitto[c].giorni[j];
    }

    fin.close();

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
                else gio[cont] = to_string(cont);

            }while(cont >= 8 || cont < 0);
            cont++;
        }while(cont != 0);
        cout<<endl;

        controllo(affitto, cat, gio);
    }
}

int main()
{
    menu();
    return 0;
}