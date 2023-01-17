#include <iostream>
#include <fstream>
#define file "auto.csv"
using namespace std;

struct automobile{
    string categoria, marca, modello, colore, giorni;
};

int menu()
{
    automobile affitto;

    while(true)
    {
        ifstream fin(file);

        string appoge; int c=0;
        cout<<"-----------------------------------------------------"<<endl;
        while(!fin.eof())
        {
            c++;
            getline(fin,appoge);
            cout<<appoge<<endl;
        }
        cout<<"------------------------------------------------------"<<endl<<endl;

        fin.close();

        do{
        cout<<"scegli la categoria dell'auto che ti interessa: ";
        cin>>affitto.categoria;
        }while(affitto.categoria != "utilitaria" && affitto.categoria != "media" && affitto.categoria != "lusso" && affitto.categoria != "sportiva" && affitto.categoria != "furgone");

        do
        {
            do
            {
                cout<<"inserisci i giorni in cui vuoi affittare la macchina (0 per uscire): ";
                cin >> affitto.giorni;

                if(affitto.giorni >= "8" || affitto.giorni < "0")
                    cout<<"scelta non valida"<<endl;

            }while(affitto.giorni >= "8" || affitto.giorni < "0");
        }while(affitto.giorni != "0");
    }
}

int main()
{
    menu();
    return 0;
}