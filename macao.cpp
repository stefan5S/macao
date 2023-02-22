/**
NOTA:
in acest program indicele vectorilor pleaca de la valoarea 1
*/



#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<fstream>
using namespace std;
fstream f;

int pachet[54],pachet_cazut[54],ok_atac,pc,pp,optiune;
char s[25];


int carte_aleator()///aleg o carte aleator din intervalul [1;54]
{int x;
while(0==0)
    {
    x=rand();
    if(x>=1&&x<=54)
        return x;

    }
}

/**iau o carte din pachet si o sterg  elementul -1 e val reziduala, ceea ce cade pe masa
este retinut in vectorul pachet_cazut*/
int carte_aleator_pachet()
{
int x,i,ok;

ok=0;
while(ok==0)
    {
        x=carte_aleator();
        for(i=1;i<=54;i++)
            if(x==pachet[i])///iau cartea din pachet
            ok=1;
    }

ok=0;
for(i=1;i<=54;i++)
if(pachet[i]==x)
{
    for(int j=1;j<=54;j++)
    {
        if(pachet_cazut[j]==-1&&ok==0)
        {
            ok=1;
            pachet_cazut[j]=pachet[i];
        }
    }

    pachet[i]=-1;///"sterg" cartea din pachet
}
return x;

}


void afisare_vector(int v[100],int n)
{
    int i;
    for(i=1;i<=n;i++)
        cout<<v[i]<<' ';///aceasta funcie a fost scrisa pentru verificarea vectorilor
}

///in aceasta functie decodifica o carte
void decodificare_carte(int el)///el(element)=carte
{
if(el==56)
cout<<"trefla";
if(el==57)
cout<<"romb";
if(el==58)
cout<<"rosu";
if(el==59)
cout<<"negru";
if(el==1)
cout<<"A"<<"trefla";
if(el==2)
cout<<"2"<<"trefla";
if(el==3)
cout<<"3"<<"trefla";
if(el==4)
cout<<"4"<<"trefla";
if(el==5)
cout<<"5"<<"trefla";
if(el==6)
cout<<"6"<<"trefla";
if(el==7)
cout<<"7"<<"trefla";
if(el==8)
cout<<"8"<<"trefla";
if(el==9)
cout<<"9"<<"trefla";
if(el==10)
cout<<"10"<<"trefla";
if(el==11)
cout<<"J"<<"trefla";
if(el==12)
cout<<"Q"<<"trefla";
if(el==13)
cout<<"K"<<"trefla";
if(el==14)
cout<<"A"<<"romb";
if(el==15)
cout<<"2"<<"romb";
if(el==16)
cout<<"3"<<"romb";
if(el==17)
cout<<"4"<<"romb";
if(el==18)
cout<<"5"<<"romb";
if(el==19)
cout<<"6"<<"romb";
if(el==20)
cout<<"7"<<"romb";
if(el==21)
cout<<"8"<<"romb";
if(el==22)
cout<<"9"<<"romb";
if(el==23)
cout<<"10"<<"romb";
if(el==24)
cout<<"J"<<"romb";
if(el==25)
cout<<"Q"<<"romb";
if(el==26)
cout<<"K"<<"romb";
if(el==27)
cout<<"A"<<"rosu";
if(el==28)
cout<<"2"<<"rosu";
if(el==29)
cout<<"3"<<"rosu";
if(el==30)
cout<<"4"<<"rosu";
if(el==31)
cout<<"5"<<"rosu";
if(el==32)
cout<<"6"<<"rosu";
if(el==33)
cout<<"7"<<"rosu";
if(el==34)
cout<<"8"<<"rosu";
if(el==35)
cout<<"9"<<"rosu";
if(el==36)
cout<<"10"<<"rosu";
if(el==37)
cout<<"J"<<"rosu";
if(el==38)
cout<<"Q"<<"rosu";
if(el==39)
cout<<"K"<<"rosu";
if(el==40)
cout<<"A"<<"negru";
if(el==41)
cout<<"2"<<"negru";
if(el==42)
cout<<"3"<<"negru";
if(el==43)
cout<<"4"<<"negru";
if(el==44)
cout<<"5"<<"negru";
if(el==45)
cout<<"6"<<"negru";
if(el==46)
cout<<"7"<<"negru";
if(el==47)
cout<<"8"<<"negru";
if(el==48)
cout<<"9"<<"negru";
if(el==49)
cout<<"10"<<"negru";
if(el==50)
cout<<"J"<<"negru";
if(el==51)
cout<<"Q"<<"negru";
if(el==52)
cout<<"K"<<"negru";
if(el==53)
cout<<"Joker1";
if(el==54)
cout<<"Joker2";




}

void decodificare_vector(int v[100],int n)
{
    int i,x;
    for(i=1;i<=n;i++)
    {x=v[i];
    decodificare_carte(x);
    cout<<' ';

    }
}

///sterge elementul e din vectorul v
void sterge(int e,int v[100],int n)
{
    int i,vp[100],k=0;
    ///vp vector auxiliar
    for(i=1;i<=n;i++)
        if(v[i]!=e)
        {k++;
            vp[k]=v[i];

        }

    for(i=1;i<=k;i++)
            v[i]=vp[i];


}


/**e- cartea ce trebuie verificata cu privire la validitatea ei, adica are acelasi simbol sau acelasi numar
cu carten.observam cum cartea ce trebuie data jos trebuie sa se afle in acelasi interval cu carten
(de la satanga la dreapta) si pe verticala, trebuie sa respecte conditia:daca adunam sau scadem de un anumit
numar de ori codul cartii din mana cu 13, atunci vom obtine cartea de jos (carten)(vezi poza din portofoliu).*/
int corectitudine(int e,int carten)
{
int ok1=0,ok2=0,x;///ok1 validitatea pe orizontala;ok2 validitatea pe verticala (1-valid;0-invalid)

/**daca cartea ce vreau sa o dau jos este as, atunci ea poate fi asezata peste orice alta carte*/
if(e==1||e==14||e==27||e==40)
    return 1;

/**in momentul in care a fost dat un as, carten isi schimba valoarea intr-o carte simbolica/fara numar,
adica acea carte peste care nu poate fi asezata decat o alta carte cu acelasi simbol*/
if(carten==56&&e>=1&&e<=13)
    return 1;

if(carten==57&&e>=14&&e<=26)
    return 1;

if(carten==58&&e>=27&&e<=39)
    return 1;

if(carten==59&&e>=40&&e<=52)
    return 1;



if(e!=53&&e!=54&&carten!=53&&carten!=54)
{///verific validitatea pe orizontala
if(carten>=1&&carten<=13&&e>=1&&e<=13)
    ok1=1;
    else
        if(carten>=14&&carten<=26&&e>=14&&e<=26)
        ok1=1;
    else
        if(carten>=27&&carten<=39&&e>=27&&e<=39)
        ok1=1;
    else
        if(carten>=40&&carten<=52&&e>=40&&e<=52)
        ok1=1;
    else
        if(carten>=53&&carten<=54&&e>=53&&e<=54)
        ok1=1;

///verific validitatea pe verticala
x=e;///copia lui e
    if(x>carten)
    {
        while(x!=carten&&x>0)
        {
            x=x-13;
            if(x==carten)
                ok2=1;
        }
    }
    else
        if(x<carten)
    {
        while(x!=carten&&x<55)
        {
            x=x+13;
            if(x==carten)
                ok2=1;
        }
    }

if(ok1==1||ok2==1)
    return 1;
else
    if(ok1==0&&ok2==0)
    return 0;
}

    if(e==53)///cartea ce o voi da jos trebuie sa fie peste o carte de aceeasi culoare
    {///53 reprezinta jocker-ul de rosu care nu poate fi plasat decat peste o carte rosie
        if(carten>=14&&carten<=39)
            return 1;

    }

    if(e==54)///54 este jocker-ul de negru care nu poate fi plasat decat peste o carte neagra
    {
        if(carten>=1&&carten<=13)
            return 1;

        if(carten>=40&&carten<=52)
            return 1;
    }

if(e==53&&carten==54)
    return 1;

if(e==54&&carten==53)
    return 1;

if(carten==53&&e>=14&&e<=39)
    return 1;


if(carten==54&&e>=1&&e<=13)
    return 1;

if(carten==54&&e>=40&&e<=52)
    return 1;

return 0;

}


///se verifica daca vectorul pachet are carti
void existenta_carti()
{
int i,ok=1;
for(i=1;i<=54;i++)
    {
    if(pachet[i]!=-1)
        ok=0;
    }

/**daca toate elementele au valoarea -1, atunci vectorul pachet este gol, iar vectorul
pachet_cazut este plin.In acest moment le inversez.*/
if(ok==1)
    {
    for(i=1;i<=54;i++)
        pachet[i]=pachet_cazut[i];
    for(i=1;i<=54;i++)
        pachet_cazut[i]=-1;
    }
}

/**vectorul v este vectorul care primeste atacul, iar x cartea celui  ce ataca*/
void carte_atac(int x,int v[54],int &n)
{
    if(x==2||x==15||x==28||x==41)
    {ok_atac=0;
        existenta_carti();
        n++;
        v[n]=carte_aleator_pachet();
        existenta_carti();
        n++;
        v[n]=carte_aleator_pachet();
    }
    if(x==3||x==16||x==29||x==42)
    {ok_atac=0;
        existenta_carti();
        n++;
        v[n]=carte_aleator_pachet();
        existenta_carti();
        n++;
        v[n]=carte_aleator_pachet();
        existenta_carti();
        n++;
        v[n]=carte_aleator_pachet();
    }

    if(x==53)///jocker rosu, cel ce primeste atacul trebuie sa ridice 10 carti
    {ok_atac=0;
        for(int i=1;i<=10;i++)
        {
        existenta_carti();
        n++;
        v[n]=carte_aleator_pachet();
        }

    }

    if(x==54)
    {ok_atac=0;
        for(int i=1;i<=5;i++)
        {
        existenta_carti();
        n++;
        v[n]=carte_aleator_pachet();
        }
    }


}


/**functia va da un rezultat intre [56;59], aceste numere fiind carti simbolice*/
int simbolic()
{int x;
    int ok=1;
    while(ok==1)
    {
        x=rand();
        if(x>=56&&x<=59)
            ok=0;
    }
return x;
}

void meniu()
{


while(optiune!=1&&optiune!=4)
{char rezidual;

    system("color 4B");///fundal-rosu | scris aqua-deschis
    cout<<' '<<' '<<' '<<' '<<' '<<' '<<' '<<' '<<' '<<"Macao!"<<'\n';
    cout<<"Start joc"<<'\n';
    cout<<"Statistica"<<'\n';
    cout<<"Instructiuni"<<'\n';
    cout<<"Iesire"<<'\n';

    cin>>optiune;

    system("cls");
    if(optiune==2)
    {system("color 67");///fundal-galben|scris-alb
    f.open("scor",ios::in);
    f.getline(s,25);
    f>>pc>>pp;///pc-puncte calculator pp-puncte player
    cout<<s<<'\n';
    cout<<pc<<' '<<pp;
    f.close();
    cout<<'\n'<<"intoarcete la meniu";
    cin>>rezidual;///este o variabila care nu face dacat sa tina totul pe loc, dar care nu are alta
                  ///importanta in program
    }
system("cls");

    if(optiune==3)
    {system("color 25");///fundal verde|scris-mov
        cout<<"Hellow my friend!"<<'\n'<<"Aici este un pachet cu instructiunile de care s-ar putea sa ai nevoie in confruntarea ta cu adversarul tau virtual.Deci sa incepem!"<<'\n'<<"Daca vei invoca o carte de atac(2 sau 3 sau jocker) atunci vei avea dreptul la inca o miscare.Atacul este imparabil."<<'\n'<<"Cartea 4 va face adversarul sa isi piarda tura."<<'\n'<<"Asul schimba cartea.Atunci cand il vei dezvalui, se va afisa optiunea:";
        cout<<"schimba in: ,atunci va trebui sa scrii un cod de la 56 la 59 inclusiv.Cu semnificatiile urmatoare:"<<'\n'<<"56-schima in trefla"<<'\n'<<"57-schimba in romb"<<'\n'<<"58-schimba in inima rosie"<<'\n'<<"59-schimba in inima neagra."<<'\n';
        cout<<"A, era sa uit de ce era mai important!Prima carte afisata pe ecran este cartea peste care trebuie sa pui o alta.Pentru a pune o carte pe masa, va trebui sa scrii a cata carte din sirul de pe randul urmator vrei sa o activezi.In caz in care nu ai o astfel de carte, poti trage una folosind comanda 55(scrii numarul efectiv)."<<'\n';
        cout<<"Cum se joaca?"<<'\n'<<"Cine va ajunge primul in a nu mai avea carti va castiga.Suna simplu!"<<"O carte este compatibila cu cea de jos, de pe masa daca are acelasi numar sau acelasi simbol, asul poate fi activat peste orice carte!"<<'\n';
        cout<<"Daca vrei sa iti faci o statistica in legatura cu victoriile tale, poti folosi butonul Statistica, aici vei avea numarul de victorii al ambilor oponenti."<<'\n';
        cout<<"Bafta!"<<'\n'<<"Intoarcete la meniu.";
        cin>>rezidual;
    }
system("cls");
}



}


/**este o functie care modifica datele din fisier
unde c-cartile calculatorului p-cartile jucatorului*/
void runda(int c,int p)
{
char rezidual;
    if(c==0)
    {
        system("cls");
        cout<<"Ai pierdut!"<<'\n';
        f.open("scor",ios::in);
        f.getline(s,25);
        f>>pc>>pp;
        pc++;
        f.close();

        f.open("scor",ios::out);
        f<<s;
        f<<'\n'<<pc<<' '<<pp;
        f.close();
        cin>>rezidual;

    }

    if(p==0)
    {
        cout<<"Ai castigat!"<<'\n';
        f.open("scor",ios::in);
        f.getline(s,25);
        f>>pc>>pp;
        pp++;
        f.close();

        f.open("scor",ios::out);
        f<<s;
        f<<'\n'<<pc<<' '<<pp;
        cin>>rezidual;
    }
    system("cls");
}




int main()
{
int i,p,player[54],c,calculator[54],carten,a,x,continu,ok,tura;


srand(time(0));

for(i=1;i<=54;i++)
    pachet[i]=i;///vectorul pachet carti
///fiecare carte are un cod de la 1 la 54




p=5;///numar carti player initial
for(i=1;i<=p;i++)
    {
        player[i]=carte_aleator_pachet();///vectorul carti de joc player, cartile tale din mana

    }

c=5;///numar carti calculator initial
for(i=1;i<=c;i++)
    {
        calculator[i]=carte_aleator_pachet();
    }

for(i=1;i<=54;i++)
{
    pachet_cazut[i]=-1;///este acel pachet, care se formeaza din cartile date pe masa de jucatori
}



///creez un meniu al jocului
optiune=-1;

meniu();


///daca aleg sa joc incep
while(optiune==1)
{
system("cls");
system("color 34");

///avansarea in joc
carten=carte_aleator_pachet();///carte neutra sau cartea de jos
decodificare_carte(carten);
cout<<'\n';
decodificare_vector(player,p);///am afisat vectorul player in forma necodificata, a jocului propriuzis
cout<<'\n';
for(i=1;i<=c;i++)
    cout<<(char)219<<' ';
cout<<'\n'<<'\n';

///confruntarea
while(c>0&&p>0)
{



continu=0;///o val ce imi permite sa aleg dinou o carte din vector
while(continu==0)
{

cin>>a;///al catelea element din vector vreau sa cada pe masa
if(a==55)
{
existenta_carti();///se verifica daca sunt carti in pachet
p++;
player[p]=carte_aleator_pachet();



/*
cout<<'\n'<<'\n';
decodificare_carte(carten);
cout<<'\n';
decodificare_vector(player,p);
cout<<'\n'<<'\n';*/
continu=1;
}
else
{
for(i=1;i<=p;i++)
    if(i==a)
    {
        x=player[i];///o copie a lui player[i]

        if(corectitudine(x,carten)==1)///se verifica daca cartea data de player respecta regulile jocului
            {
                carte_atac(x,calculator,c);
                carten=player[i];

                sterge(carten,player,p);
                p--;///trebuie scazut numarul de carti al jucatorului nu pot scadea in functie parametrul ei

                if(carten==1||carten==14||carten==27||carten==40)
                {
                    do{
                        cout<<"schimba in:";cin>>a;///a-numar intre [56;59]
                        carten=a;
                      }while(a<56||a>59);///verific daca am introdus date corecte
                }



///am verificat daca am atacat, daca da atunci sa dau o viitoare carte jos
///am dreptul de a mai juca o carte daca am dat un 4
                if(carten==2||carten==15||carten==28||carten==41||carten==54||carten==53||carten==3||carten==16||carten==29||carten==42||carten==4||carten==17||carten==30||carten==43)
                    continu=0;
                else
                    continu=1;

            system("cls");
            //cout<<'\n'<<'\n';
            decodificare_carte(carten);
            cout<<'\n';
            decodificare_vector(player,p);
            cout<<'\n';
            //decodificare_vector(calculator,c);
            //cout<<'\n';
            for(i=1;i<=c;i++)
                cout<<(char)219<<' ';
            cout<<'\n'<<'\n';



            }
    }

}


}



/*
cout<<'\n'<<'\n';
decodificare_carte(carten);
cout<<'\n';//pentru verificari in legatura cu player
decodificare_vector(player,p);
*/


///evolutia partii calculatorului

tura=1;///daca calculatorul da o carte de atac jos atunci va mai da o data
while(tura==1)
{ok=1;
tura=0;
     for(i=1;i<=c;i++)
        if(corectitudine(calculator[i],carten)==1)///caut o carte din vectorul calculator, daca este potrivita
             {carten=calculator[i];///o dau si ies din for
                ok=0;///calculatorul a dat o carte jos
                break;
             }

             if(ok==0)///daca a fost data o carte jos o sterg
                {sterge(carten,calculator,c);
                c--;


                /**daca calculatorul a dat un as jos va alege(aleator) una dintre cartile simbolice*/
                if(carten==1||carten==14||carten==27||carten==40)
                {
                    carten=simbolic();

                }



                     if(carten==2||carten==15||carten==28||carten==41||carten==54||carten==53||carten==3||carten==16||carten==29||carten==42||carten==4||carten==17||carten==30||carten==43)
                        {tura=1;///calculatorul mai da o data o carte
                        carte_atac(carten,player,p);///player-ul este lovit
                        }
                }

    if(ok==1)///nu exista o carte potrivita pentru a fi data jos, atunci va trebui sa fie trasa una
    {
        existenta_carti();
    c++;
    calculator[c]=carte_aleator_pachet();
    }



            system("cls");
            decodificare_carte(carten);
            cout<<'\n';
            decodificare_vector(player,p);
            /*cout<<'\n';
            decodificare_vector(calculator,c);*/
            cout<<'\n';
            for(i=1;i<=c;i++)
                cout<<(char)219<<' ';
            cout<<'\n'<<'\n';



}
}


/**rundele castigate de oponenti le retin intr-un fisier pe care il deschid ca sa modific punctajele*/
runda(c,p);


///reafisej meniul
optiune=-1;
meniu();


}



if(optiune==4)
{system("color 67");///scris-galben|fundal-alb
cout<<"Ne mai vedem!";
cin>>optiune;
}


    return 0;
}
