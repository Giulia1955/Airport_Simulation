    #include <iostream>
    #include <ctime>
    using namespace std;
    #include "FilaPrioridadesLE.h"

    void imprime(no *L)
    {
        no *P = L;
        cout << " ";
        while (P != NULL) {
            cout << "Voo: " << P->info << " Prior: " << P->prior << endl;
            P = P->link;
        }
    }

    int main()
    {
        no *solicita, *Fpousa, *Fdecola;
        int ut, voo, tipo, prior, i;
        int continua = 1, qntVoos = 50;
        srand(time(nullptr));

        solicita = inicializaFP(solicita);    	
        Fpousa = inicializaFP(Fpousa);
        Fdecola = inicializaFP(Fdecola);

        for (i = 0; i < qntVoos; i++){
            prior = ((rand() % 4) + 1);
            solicita = insereFilaChegada(solicita, i, prior);
        }

        imprime(solicita);


        for(ut=1; continua ; ut++){
            cout << endl << "**************************" << endl;
            cout << endl << "***** UNIDADE DE TEMPO: "<< ut << " *****" << endl;

            for (voo = 1; voo <=5; voo++){
                if (!verificaSeVazia(solicita)){
                    solicita = removeFP(solicita, &tipo, &prior);

                    if(prior == 1 || prior == 2){
                        Fpousa = insereFP(Fpousa, tipo, prior);
                        cout << "Solicitacao de pouso do aviao "<< tipo << " com prioridade " << prior << endl;
                    } else {
                        Fdecola = insereFP(Fdecola, tipo, prior);
                        cout << "Solicitacao de decolagem do aviao "<< tipo << " com prioridade " << prior << endl;
                    }
                    cout << "-----------------------------------------------------" << endl;
                }
            }

            if (((ut + 1)%2)&&(continua)){
                if (Fpousa != NULL){
                    Fpousa = removeFP(Fpousa, &tipo, &prior);
                    cout << "Pista 1: Aviao " << tipo << " esta POUSANDO (prioridade " << prior << ")" << endl;
                } else {
                    cout << "Pista 1: LIVRE, mas nenhum aviao aguardando pouso." << endl;
                }
            }

            if (((ut + 1)%3)&&(continua)){
                if (Fdecola != NULL){
                    Fdecola = removeFP(Fdecola, &tipo, &prior);
                    cout << "Pista 2: Aviao " << tipo << " esta DECOLANDO (prioridade " << prior << ")" << endl;
                } else {
                    cout << "Pista 2: LIVRE, mas nenhum aviao aguardando decolagem." << endl;
                }
                
            }

            if ((Fdecola == NULL) && (Fpousa == NULL)){
                continua = 0;
            }
        }
    }