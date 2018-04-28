#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

char oyuntahtasi[20][20];  /// max 20 belirledik

void kazanan(void); /// kullanici ve bilgisayarin skorlarini sayacak metod
void oyunTahtasi(void); /// Parametresiz olan yapici oyun tahtasini bos olarak baslatacaktir
void oyuncu_konum(void); /// Kullanicidan x y koordinatlarini alacak olan metot
void bilgisayar_konum(void); /// Boþ olan korninata bilgisayar için sembol yerleþtirecek olan metot
void oyunTahtasiYazdir(void); /// Oyun tahtasini konsol ekraninda gostermeye yarayacak bir metot
char bilgisayar_sembol; ///Bilgisayarin sembolu
char sembol; /// Kullanicinin sembolu
int N; /// Oyun tahtasinin boyutu
int score_kullanici;
int score_bilgisayar;

int main(void)
{
    string isim;
    cout<<"\n------TIC TAC TOE------\n\n";
    cout<<"Adiniz nedir? ";
    cin>>isim;

    cout<<"\n_"<<isim<<" bilgisayara karsi!!_"<<"\n"<<endl;
    cout<<"Sembolunuzu Secebilirsiniz (X veya O) : ";
    cin>>sembol;

    if(sembol=='X') bilgisayar_sembol='O' ;

    if(sembol=='O') bilgisayar_sembol='X' ;

    if(sembol!='X'&&sembol!='O')
    {
        cout<<"Yanlis sembol kullanimi!"<<endl;
        sembol='X';
        bilgisayar_sembol='O' ;
    }

    int n;
    cout<<"Oyun tahtasi boyutunu giriniz:";
    cin>>n;
    N=n;


    oyunTahtasi();
    int b;
    if(n%2==0) b=(n*n)/2;
    else b=((n*n)/2)+1;
    int i;
    for(i=0; i<b; i++)
    {
        oyunTahtasiYazdir();
        oyuncu_konum(); /// kullanicidan x y koordinatlarini aliyoruz
        bilgisayar_konum();
        kazanan();
    }


    if(score_kullanici>score_bilgisayar) cout<<"\n Siz kazandiniz ! \n";
    else if(score_kullanici<score_bilgisayar) cout<<"\n Bilgisayar kazandi !\n";
    else if(score_kullanici=score_bilgisayar) cout<<"\nOyun berabere..\n";
    oyunTahtasiYazdir();

    if(score_kullanici>score_bilgisayar) cout<<"\n TEBRIKLER!!! ! \n";
    else if(score_kullanici<score_bilgisayar)   cout<<"\n Bidahaki sefere artik..."<<endl;
    return 0;
}

/*
==============================================================================*/

void oyunTahtasi(void) //oyuntahtasi ekranda olusturulur
{
    int i, j;
    cout<<"\n";

    for(i=0; i<N; i++)
        for(j=0; j<N; j++) oyuntahtasi[i][j] =  ' ';
}


void oyuncu_konum(void) //oyuncuya koordinat girisi saglanyr.
{
    int a, b;

    cout<<"X koordinatini giriniz: ";
    cin >> a;

    cout<<"Y koordinatini giriniz: ";
    cin >> b;

    a--;
    b--;

    if(oyuntahtasi[a][b]!= ' ')
    {
        cout<<"Koordinat yanlis tekrar deneyiniz... \n";
        oyuncu_konum();

    }
    else oyuntahtasi[a][b] = sembol;
}

void bilgisayar_konum(void)
{
    int i, j;
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
            if(oyuntahtasi[i][j]==' ') break;
        if(oyuntahtasi[i][j]==' ') break;
    }
    int b=N*N;
    if(i*j==b+1)
    {
        cout<<"draw\n";
        exit(0);
    }
    else
        oyuntahtasi[i][j] = bilgisayar_sembol ;
}

void oyunTahtasiYazdir(void) //oyuntahtasi sonuc
{
    int i,j;

    for(i=0; i<N; i++)
    {
        cout<<i+1;
        cout<<"| ";
        for(j=0; j<N; j++)
        {
            cout<<" "<< oyuntahtasi[i][j]<<" | "<<" ";
        }
        cout<<"\n";
    }

    cout << "\n";
}

void kazanan(void)
{
    score_bilgisayar=0;
    score_kullanici=0;
    // satir kontrol
    int i,j;
    for(j=0; j<N; j++)
    {
        for(i=0; i<N-2; i++)
            if(oyuntahtasi[j][i]==oyuntahtasi[j][i+1] &&oyuntahtasi[j][i]==oyuntahtasi[j][i+2])
            {
                if(oyuntahtasi[j][i]==sembol) score_kullanici++;
                else if(oyuntahtasi[j][i]==bilgisayar_sembol) score_bilgisayar++;
            }
    }
    //stun kontrol
    for(j=0; j<N; j++)
    {
        for(i=0; i<N-2; i++)
            if(oyuntahtasi[i][j]==oyuntahtasi[i+1][j] &&oyuntahtasi[i][j]==oyuntahtasi[i+2][j])
            {

                if(oyuntahtasi[i][j]==sembol) score_kullanici++;
                else if(oyuntahtasi[i][j]==bilgisayar_sembol) score_bilgisayar++;
            }
    }

    // carpraz kontrol
    for(i=0; i<N-2; i++)
    {
        for(j=0; j<N-2; j++)
            if(oyuntahtasi[i][j]==oyuntahtasi[i+1][j+1] &&oyuntahtasi[i][j]==oyuntahtasi[i+2][j+2])
            {

                if(oyuntahtasi[i][j]==sembol) score_kullanici++;
                else if(oyuntahtasi[i][j]==bilgisayar_sembol) score_bilgisayar++;;
            }
    }
    //ters çarpraz kontrol
    for(i=0; i<N-2; i++)
    {
        for(j=2; j<N; j++)
            if(oyuntahtasi[i][j]==oyuntahtasi[i+1][j-1] &&oyuntahtasi[i][j]==oyuntahtasi[i+2][j-2])
            {
                if(oyuntahtasi[i][j]==sembol)  score_kullanici++;
                else if(oyuntahtasi[i][j]==bilgisayar_sembol) score_bilgisayar++;
            }
    }
    if(score_kullanici>0) cout<<"oyuncu skoru:"<<score_kullanici<<endl;
    if(score_bilgisayar>0) cout<<"bilgisayar skoru:"<<score_bilgisayar<<endl;
}
