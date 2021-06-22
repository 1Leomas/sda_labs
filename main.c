#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Arbore{
    char denumire[20];
    char autor[20];
    unsigned short anulEditiei, numPag,tiraj;
    struct Arbore *left, *right;
}Arbore;

void cls(){
    printf("\n\nTastati orice tasta pentru a continua...");
    fflush(stdin);
    getch();
    system("cls");
}

int menu(){

    system("cls");
     printf("In acest program am creat o structura de date de tip arbore binar\n");
     printf("Am mai adaugat unele functiile pentru prelucrare datelor arborului\n\n");
  printf("\n+----------------------------------MENU---------------------------------+\n");
    printf("|1....Crearea si introducerea informatiei...............................|\n");
    printf("|2....Afisarea informatiei despre nodurile arborelui la ecran...........|\n");
    printf("|3....Cautarea nodului in arbore........................................|\n");
    printf("|4....Modificarea informatiei unui nod din arbore.......................|\n");
    printf("|5....Determinarea numarului de noduri..................................|\n");
    printf("|6....Determinarea inaltimii arborelui..................................|\n");
    printf("|7....Eliberarea memoriei alocate pentru lista..........................|\n");
    printf("|0....Iesire din program................................................|\n");
    printf("+-----------------------------------------------------------------------+\n");
    unsigned short optiune;
    printf("\nSelect: "); scanf("%hu", &optiune);
    return optiune;
}
Arbore *insert(Arbore *Rad, char *den, char *autor, int pag, int an, int tir){
    Rad = (Arbore*)malloc(sizeof(Arbore));
    strcpy(Rad->denumire, den);
    strcpy(Rad->autor, autor);
    Rad->numPag = pag;
    Rad->anulEditiei = an;
    Rad->tiraj = tir;
    Rad->left = NULL;
    Rad->right = NULL;
}

Arbore *creare(Arbore *Rad){

    /*
    char rasp;
    Rad = (Arbore*)malloc(sizeof(Arbore));
    printf("\nDenumirea: "); fflush(stdin); gets(Rad->denumire);
    printf("Autorul: "); fflush(stdin); gets(Rad->autor);
    printf("Numarul de pagini: "); scanf("%hu",&Rad->numPag);
    printf("Anul editiei: "); scanf("%hu",&Rad->anulEditiei);
    printf("Tirajul: "); scanf("%hu",&Rad->tiraj);

    printf("Nodul %s are subarbore stang?[d/n]", Rad->denumire);
    fflush(stdin); rasp = getche();
    printf("\n");
    if (rasp == 'd')
        Rad->left = creare(Rad->left);
    else
        Rad->left = NULL;

    printf("Nodul %s are subarbore dreapt?[d/n]", Rad->denumire);
    fflush(stdin); rasp = getche();
    printf("\n");
    if (rasp == 'd')
        Rad->right = creare(Rad->right);
    else
        Rad->right = NULL;
    */
    Rad = insert(Rad, "A", "A", 1, 1, 1);
    Rad->left = insert(Rad->left, "B", "B", 2, 2, 2);
    Rad->left->left = insert(Rad->left->left, "C", "C", 3, 3, 3);
    Rad->left->right = insert(Rad->left->left, "D", "D", 4, 4, 4);
    Rad->left->right->left = insert(Rad->left->left, "E", "E", 5, 5, 5);
    Rad->right = insert(Rad->right, "F", "F", 2, 2, 2);
    Rad->right->right = insert(Rad->right, "G", "G", 3, 3, 3);

    return Rad;
}

void afisarePreordine(Arbore *Rad){
    if (Rad != NULL){
    printf("\n| %-15s | %-13s | %-6hu | %-6hu | %-7hu |", Rad->denumire, Rad->autor, Rad->numPag, Rad->anulEditiei, Rad->tiraj);
    afisarePreordine(Rad->left);
    afisarePreordine(Rad->right);
    }
}
void afisareInordine(Arbore *Rad){
    if (Rad != NULL){
    afisareInordine(Rad->left);
    printf("\n| %-15s | %-13s | %-6hu | %-6hu | %-7hu |", Rad->denumire, Rad->autor, Rad->numPag, Rad->anulEditiei, Rad->tiraj);
    afisareInordine(Rad->right);
    }
}
void afisarePostordine(Arbore *Rad){
    if (Rad != NULL){
    afisarePostordine(Rad->left);
    afisarePostordine(Rad->right);
    printf("\n| %-15s | %-13s | %-6hu | %-6hu | %-7hu |", Rad->denumire, Rad->autor, Rad->numPag, Rad->anulEditiei, Rad->tiraj);
    }
}
void afisare(Arbore *Rad){
    if (Rad != NULL){
        unsigned short select;
        bool valid = false;
        while(!valid){
            printf("\nCum doriti sa afisati arborele:");
            printf("\n1. Preordine");
            printf("\n2. Inordine");
            printf("\n3. Postordine");
            printf("\nSelect: "); fflush(stdin); scanf("%hu", &select);
            if(select < 0 || select > 3){
                printf("\nEroare la introducerea datelor, mai incercati o data\n");
                system("pause");
                system("cls");
            }
            else
                valid = true;
        }
        printf(  "                         Lista cartilor");
        printf("\n+-----------------+---------------+--------+--------+---------+");
        printf("\n| Denumirea       | Autorul       | Pagini | Editia | Tirajul |");
        printf("\n+-----------------+---------------+--------+--------+---------+");
        switch(select){
        case 1: afisarePreordine(Rad); break;
        case 2: afisareInordine(Rad); break;
        case 3: afisarePostordine(Rad); break;
        default: printf("\neroare");
        }
        printf("\n+-----------------+---------------+--------+--------+---------+");
    }
    else printf("Nu avem niciun element de afisat!!!\n");
    return;
}

void cautareInt(Arbore *Rad, int op,int num){
    if(Rad == NULL) return;
    if( (op == 3 && Rad->numPag == num) ||
        (op == 4 && Rad->anulEditiei == num) ||
        (op == 5 && Rad->tiraj == num)
       )
    {
        printf("\n| %-15s | %-13s | %-6hu | %-6hu | %-7hu |", Rad->denumire, Rad->autor, Rad->numPag, Rad->anulEditiei, Rad->tiraj);
    }
    if(Rad->left != NULL)
        cautareInt(Rad->left, op, num);
    if(Rad->right != NULL)
        cautareInt(Rad->right, op, num);
    return;
}
void cautareChar(Arbore *Rad, int op, char *den){
    if(Rad == NULL) return NULL;
    if( (op == 1 && (strcmp(Rad->denumire, den) == 0)) ||
        (op == 2 && (strcmp(Rad->autor, den) == 0))
      )
    {
        printf("\n| %-15s | %-13s | %-6hu | %-6hu | %-7hu |", Rad->denumire, Rad->autor, Rad->numPag, Rad->anulEditiei, Rad->tiraj);
    }
    if(Rad->left != NULL)
        cautareChar(Rad->left, op, den);
    if(Rad->right != NULL)
        cautareChar(Rad->right, op, den);
}
void afisareTabelResult(){
    printf("\n                        Cartile gasite");
    printf("\n+-----------------+---------------+--------+--------+---------+");
    printf("\n| Denumirea       | Autorul       | Pagini | Editia | Tirajul |");
    printf("\n+-----------------+---------------+--------+--------+---------+");
}
void cautare(Arbore *Rad){
    if(Rad == NULL){
        printf("\nArborele este NULL");
        cls();
        return;
    }
    unsigned short op;
    do
	{
	    system("cls");
        printf("\nAlegeti criteriu de cautre\n");
        printf("\n 1 Denumire");
        printf("\n 2 Autor");
        printf("\n 3 Numarul de pagini");
        printf("\n 4 Editia");
        printf("\n 5 Tirajul");
        printf("\n 0 Meniul principal");

	    unsigned short inputInt;
	    char inputString[20];
	    printf("\n\nOptiune: "); scanf("%hu",&op);

		switch (op)
		{
		case 1:
		    fflush(stdin);
            printf("\nDenumirea: "); gets(inputString);
            afisareTabelResult();
            cautareChar(Rad, op, inputString);
            break;
		case 2:
		    fflush(stdin);
            printf("\nAutorul: "); gets(inputString);
            afisareTabelResult();
            cautareChar(Rad, op, inputString);
		    break;
		case 3:
            printf("\nNumarul de pagini: "); scanf("%hu",&inputInt);
            afisareTabelResult();
            cautareInt(Rad, op, inputInt);
		    break;
		case 4:
            printf("\nAnul editiei: "); scanf("%hu",&inputInt);
            afisareTabelResult();
            cautareInt(Rad, op, inputInt);
            break;
		case 5:
            printf("\nTirajul: "); scanf("%hu",&inputInt);
            afisareTabelResult();
            cautareInt(Rad, op, inputInt);
		    break;
        case 0:
		    return;
		default:
		    printf("\nOptiune gresita!\n");
		    break;
		}
        printf("\n+-----------------+---------------+--------+--------+---------+");
        cls();
	} while (op);
	return;
}

Arbore *cautareDenumire(Arbore *Rad, char *den){
    if(Rad == NULL) return NULL;
    Arbore* tmp;
    if( (strcmp(Rad->denumire, den) == 0) )
    {
        printf("\n| %-15s | %-13s | %-6hu | %-6hu | %-7hu |", Rad->denumire, Rad->autor, Rad->numPag, Rad->anulEditiei, Rad->tiraj);
        return Rad;
    }
    tmp = cautareDenumire(Rad->left, den);
    if ((tmp != NULL) && (strcmp(tmp->denumire, den) == 0)) return tmp;

    tmp = cautareDenumire(Rad->right, den);
    if ((tmp != NULL) && (strcmp(tmp->denumire, den) == 0)) return tmp;

    return NULL;
}

void modificare(Arbore* Rad) {
    if (Rad == NULL) {
        printf("\nArborele este NULL");
        cls();
        return;
    }
    char den[30];
    unsigned short num, camp;
    bool join = true;
    while (join) {
        system("cls");
        printf(  "                         Lista cartilor");
        printf("\n+-----------------+---------------+--------+--------+---------+");
        printf("\n| Denumirea       | Autorul       | Pagini | Editia | Tirajul |");
        printf("\n+-----------------+---------------+--------+--------+---------+");
        afisarePreordine(Rad);
        printf("\n+-----------------+---------------+--------+--------+---------+");

        printf("\n\nTastati:");
        printf("\n\t-num pag a cartii spre modificare");
        printf("\n\t-cifra 0 pentru intoarcere in meniul principal");
        printf("\nSelect: ");

        fflush(stdin); gets(den);
        if(strcmp(den, "0") == 0){
            system("cls");
            return;
        }
        Arbore* element = cautareDenumire(Rad, den);
        if (element == NULL) {
            printf("\nEroare!!! Nu exista carte cu asa denumire.\n");
            cls();
            continue;
        }
        printf("\nElementul gasit: %d", element->numPag);

        do {
            system("cls");
            printf("\n+-----------------+---------------+--------+--------+---------+");
            printf("\n| Denumirea       | Autorul       | Pagini | Editia | Tirajul |");
            printf("\n+-----------------+---------------+--------+--------+---------+");
            printf("\n| %-15s | %-13s | %-6hu | %-6hu | %-7hu |", element->denumire , element->autor, element->numPag, element->anulEditiei, element->tiraj);
            printf("\n+-----------------+---------------+--------+--------+---------+");
            printf("\n-Optiunile-posibile-");
            printf("\n 1 Denumirea");
            printf("\n 2 Autorul cartii");
            printf("\n 3 Numarul de pagini");
            printf("\n 4 Editia");
            printf("\n 5 Tirajul");
            printf("\n 6 Toate campurile");
            printf("\n 7 Alege alta carte");
            printf("\n 0 Meniul principal");
            printf("\n\nAlegeti optiunea: "); scanf_s("%hu", &camp);

            switch (camp)
            {
            case 1:
                printf("\nDenumirea: "); fflush(stdin); gets(element->denumire);
                break;
            case 2:
                printf("\nAutorul: "); fflush(stdin); gets(element->autor);
                break;
            case 3:
                printf("\nNumarul de pagini: "); scanf_s("%hu", &element->numPag);
                break;
            case 4:
                printf("\nAnul editiei: "); scanf_s("%hu", &element->anulEditiei);
                break;
            case 5:
                printf("\nTirajul: "); scanf_s("%hu", &element->tiraj);
                break;
            case 6:
                printf("\nNumarul de pagini: "); scanf_s("%hu", &element->numPag);
                printf("\nAnul editiei: "); scanf_s("%hu", &element->anulEditiei);
                printf("\nTirajul: "); scanf_s("%hu", &element->tiraj);
                break;
            case 7: break;
            case 0: return;
            default: printf("\nOptiune gresita!\n"); cls(); break;
            }
        } while (camp != 7);
    }
    return;
}

int noduri(Arbore *Rad){
    int count = 1;
    if(Rad == NULL) return 0;
    count += noduri(Rad->left);
    count += noduri(Rad->right);
    return count;
}
void countNoduri(Arbore *Rad){
    int count;
    count = noduri(Rad);
    printf("Avem %d noduri", count);
    cls();
}

int nivele(Arbore *Rad){
    int left = 0, right = 0;
    if(Rad == NULL) return 0;
    left += noduri(Rad->left);
    right += noduri(Rad->right);
    if(left >= right) return left;
    else return right;
}
void inaltimeArbore(Arbore *Rad){
    int inaltime;
    inaltime = nivele(Rad);
    printf("Inaltimea este : %d", inaltime);
    cls();
}

void eliberareMemorie(Arbore *Rad){
    if(Rad == NULL) return;
    if(Rad->left != NULL) eliberareMemorie(Rad->left);
    if(Rad->right != NULL) eliberareMemorie(Rad->right);
    free(Rad);
}

int main()
{
    Arbore *Rad = NULL;
    while(1)
    {
        fflush(stdin);
        unsigned short optiune = menu();
        switch(optiune){
        case 1: system("cls");
                printf("Crearea arborului: \n");
                Rad = creare(Rad); break;
        case 2: system("cls"); afisare(Rad); cls(); break;
        case 3: cautare(Rad); break;
        case 4: modificare(Rad); break;
        case 5: countNoduri(Rad); break;
        case 6: inaltimeArbore(Rad); break;
        case 7: eliberareMemorie(Rad);
                Rad = NULL;
                printf("\nMemoria pentru arbore a fost eliberata cu succes!\n");
                cls();
                break;
        case 0: return 0;
        default: printf("\nOptiune gresita!\n"); cls(); break;
        }
    }
    return 0;
}
