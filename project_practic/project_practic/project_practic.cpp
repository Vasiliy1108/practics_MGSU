#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <clocale>
#include <windows.h>
#include <fstream>


using namespace std;
using namespace System;
using namespace System::IO;
#define ENTER 13
#define ESC 27
#define UP 72
#define DOWN 80
#define HOME 71
#define END 79
void russian()
{
	setlocale(LC_ALL, ".1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

char dan[13][155]={
 "Cамая лучшая видеокарта(по мощности и по объему памяти)",
 "Самая старая и самая новая видеокарта                  ",
 "Количество видеокарт производителя Red                 ",
 "Количество видеокарт производителя Yellow              ",
 "Количество видеокарт производителя Green               ",
 "Cписок видеокарт от А до Я                             ",
 "Cписок видеокарт от Я до А                             ",
 "Видеокарты для Fart Kray                               ",
 "Диаграмма относительно среднего значения               ",
 "Количество видеокарт (вводим производителя сами)       ",
 "Список видеокарт с совпадающим количеством видеопамяти ",
 "Вернуться на предыдущую страницу                       ",
 "Выход                                                  ",
};

int count_strok (const char *file)
{
char *str = new char [1024];
int iii=0;
ifstream bas (file);
while (!bas.eof())
{bas.getline(str,1024,'\n');
iii++;}
return iii;
}

void text_data(char *s,char *sd)
{ 
char s0[3],month[12][9]={"января","февраля","марта","апреля","мая","июня","июля","августа","сентября","октября","ноября","декабря"};
strcpy(s,sd+8);
strcat(s," ");
strncpy(s0,sd+5,2); s0[2]=0;
strcat(s,month[ atoi(s0)-1]);
strcat(s," ");
strncat(s,sd,4);
return;
}


//Производитель Модель  Кол-во_ядер Частота(МГЦ) Объем_памяти(МБ) Дата_выхода G
struct v {
char proiz[20];
char name[20];
int coris;
int freq;
int mimore;
char data[11];
int papuga;
}; //элемент массива
struct sp {
char proiz[20];
char name[20];
long summa;
struct sp* pred;
struct sp* sled;
 } *spisok;

int menu(int,int,int,int,int,int);
void maxim(struct v*,int);
void first(struct v*,int);
void kolvo(struct v *, char*,int);
void alfalist(struct v*,int,int);
void listing(struct v*,int);
void diagram(struct v*,int);
void kol1(struct v *,int);
void sovpadeniya(struct v *viduha,int);
void text_data(char *,char *,int);
void vstavka(struct v*,char*,int);

int main(array<System::String ^> ^args)
{

int num_c;
int at,bt;
int y1,y2;
y1=0;y2=1;
at=19;bt=3;
//SetConsoleCP(1251);
//SetConsoleOutputCP(1251);
setlocale(LC_CTYPE,"Russian");
int i,n,a;
FILE *in,*out;
struct v *viduha;
Console::CursorVisible::set(false);
Console::BufferHeight=720;
Console::BufferWidth=1280;

if((in=fopen("for_kurs.txt","r"))==NULL)
{
printf("\nФайл for_kurs.txt не открыт !");
 getch(); exit(1);
}
out=fopen("for_zapis.txt","w");
Console::BackgroundColor=ConsoleColor::Black;
Console::ForegroundColor=ConsoleColor::Magenta;
// Ввод из файла и контрольная печать
//fscanf(in,"%d",&NC);

num_c=count_strok ("for_kurs.txt");
viduha=(struct v*)malloc(num_c*sizeof(struct v));
for(i=0;i<num_c;i++) {fscanf(in,"%s%s%d%d%d%s%d",viduha[i].proiz,viduha[i].name,&viduha[i].coris,&viduha[i].freq,&viduha[i].mimore,viduha[i].data,&viduha[i].papuga);}
for(i=0;i<num_c;i++) {fprintf(out,"%s %s %d %d %d %s %d \n",viduha[i].proiz,viduha[i].name,viduha[i].coris,viduha[i].freq,viduha[i].mimore,viduha[i].data,viduha[i].papuga);}
//сохранение текущих данных
point1:;
printf("Количество видеокарт в базе данных: %d ",num_c);
Console::BackgroundColor=ConsoleColor::Magenta;
Console::ForegroundColor=ConsoleColor::White;
printf("\nПроизводитель        Модель      Кол-во_ядер    Частота(МГЦ)     Объем_памяти(МБ)    Дата_выхода      G             ");
Console::BackgroundColor=ConsoleColor::Black;
Console::ForegroundColor=ConsoleColor::Magenta;


for(i=0;i<num_c;i++) {printf("\n%-20s %-15s %-15d %-15d %-15d %-15s %-15d",viduha[i].proiz,viduha[i].name,viduha[i].coris,viduha[i].freq,viduha[i].mimore,viduha[i].data,viduha[i].papuga);}

Console::ForegroundColor=ConsoleColor::White;
Console::BackgroundColor=ConsoleColor::Magenta;
printf("\nДля перехода на следующую страницу нажмите Enter                                                                    ");
char c=312;
int y11=0;
int y22=1;
while (c!=ENTER)
{
switch(c) {
 case DOWN: y22=y11; y11+=1; break;
 case UP: y22=y11; y11-=1; break;
 case ENTER: return y11+2;
 }
if(y11>num_c-1){y11=0;}
if(y11<0) {y11=num_c-1;}
char prov[20];
Console::ForegroundColor=ConsoleColor::White;
Console::BackgroundColor=ConsoleColor::DarkMagenta;
if (strcmp(viduha[y11].proiz,"Red")==0){Console::BackgroundColor=ConsoleColor::DarkRed;}
if (strcmp(viduha[y11].proiz,"Yellow")==0){Console::BackgroundColor=ConsoleColor::DarkYellow;}
if (strcmp(viduha[y11].proiz,"Green")==0){Console::BackgroundColor=ConsoleColor::DarkGreen;}
if (strcmp(viduha[y11].proiz,"Аврора")==0){Console::BackgroundColor=ConsoleColor::DarkBlue;}


Console::CursorLeft=0;
Console::CursorTop=y11+2;
printf("%-20s %-15s %-15d %-15d %-15d %-15s %-15d",viduha[y11].proiz,viduha[y11].name,viduha[y11].coris,viduha[y11].freq,viduha[y11].mimore,viduha[y11].data,viduha[y11].papuga);
Console::ForegroundColor=ConsoleColor::Magenta;
Console::BackgroundColor=ConsoleColor::Black;
Console::CursorLeft=0;//имитирует движ у щтанах, обводя актуальный и перекрашивая в обратку предыдущую
Console::CursorTop=y22+2;
printf("%-20s %-15s %-15d %-15d %-15d %-15s %-15d",viduha[y22].proiz,viduha[y22].name,viduha[y22].coris,viduha[y22].freq,viduha[y22].mimore,viduha[y22].data,viduha[y22].papuga);
c=getch();
}

int ext;
ext=0;
while(ext!=1)
{
//Console::ForegroundColor=ConsoleColor::Magenta;
Console::BackgroundColor=ConsoleColor::Black;
Console::Clear();
Console::ForegroundColor=ConsoleColor::Magenta;
Console::BackgroundColor=ConsoleColor::DarkGreen;//!!!!!!!!!!!!!!!!
Console::CursorLeft=at-1;
Console::CursorTop=2;
printf("                                                         \n");
for(i=0;i<13;i++)
{
Console::CursorLeft=at-1;
Console::CursorTop=i+3;//
printf(" %s ",dan[i]);
}
Console::CursorLeft=at-1;
Console::CursorTop=16;
printf("                                                         \n");
n=menu(13,num_c,y1,y2,at,bt);
switch(n) {
case 1: maxim(viduha,num_c); break;
case 2: first(viduha,num_c); break;
case 3: kolvo(viduha,"Red",num_c); break;
case 4: kolvo(viduha,"Yellow",num_c); break;
case 5: kolvo(viduha,"Green",num_c); break;
case 6: alfalist(viduha,1,num_c); break;
case 7: alfalist(viduha,2,num_c); break;
case 8: listing(viduha,num_c); break;
case 9: diagram(viduha,num_c); break;
case 10: kol1(viduha,num_c); break;
case 11: sovpadeniya(viduha,num_c); break;
case 12: {Console::CursorLeft=0;
Console::BackgroundColor=ConsoleColor::Black;
Console::ForegroundColor=ConsoleColor::Magenta;
Console::CursorTop=0;
Console::Clear();
goto point1;}
case 13: ext=1;
 }
} // конец while(1)...
getch();
return 0;
} // конец main()
// программирование выбора из меню
int menu(int n,int num_c,int y1,int y2,int at,int bt)

{
char c=312;
while (c!=ESC)
{
switch(c) {
 case DOWN: y2=y1; y1+=1; break;
 case UP: y2=y1; y1-=1; break;
 case HOME: y2=y1; y1=0; break;
 case END: y2=y1;y1=n-1; break;
 case ENTER: return y1+1;
 }
if(y1>n-1){y1=0;}
if(y1<0) {y1=n-1;}
Console::ForegroundColor=ConsoleColor::Magenta;
Console::BackgroundColor=ConsoleColor::DarkYellow;//:)
Console::CursorLeft=at;
Console::CursorTop=y1+bt;
printf("%s",dan[y1]);
Console::ForegroundColor=ConsoleColor::Magenta;
Console::BackgroundColor=ConsoleColor::DarkGreen;
Console::CursorLeft=at;//имитирует движ у щтанах, обводя актуальный и перекрашивая в обратку предыдущую
Console::CursorTop=y2+bt;
printf("%s",dan[y2]);
c=getch();
} // конец while(c!=ESC)...

exit(0);
}

void maxim(struct v* viduha, int num_c)
{

int i=0; struct v best1,best2;
best1=viduha[0];
best2=viduha[0];
for(i=1;i<num_c;i++)
{
	if (viduha[i].papuga>best1.papuga)
		{
			best1=viduha[i];
			
		}
	if (viduha[i].mimore>best2.mimore)
		{
			best2=viduha[i];
		}
}
Console::ForegroundColor=ConsoleColor::DarkCyan;
Console::BackgroundColor=ConsoleColor::White;
Console::CursorLeft=18;
Console::CursorTop=19;
printf("Самая производительная видеокарта имеет %ld количество очков",best1.papuga);
Console::CursorLeft=18;
Console::CursorTop=20;
printf("Это видеокарта:%s %s (%d cores/%d Мгц/%d Мб/%s/%d points)",best1.proiz,best1.name,best1.coris,best1.freq,best1.mimore,best1.data,best1.papuga);

Console::CursorLeft=18;
Console::CursorTop=22;
printf("Самое большое количество памяти %ld Мб",best2.mimore);
Console::CursorLeft=18;
Console::CursorTop=23;
printf("Это видеокарта:%s %s (%d cores/%d Мгц/%d Мб/%s/%d points)",best2.proiz,best2.name,best2.coris,best2.freq,best2.mimore,best2.data,best2.papuga);
getch();
}

void first(struct v* viduha, int num_c)
{

int i;
char s[17],s2[17];
struct v best1,best2;
best1=viduha[0];
best2=viduha[0];
for(i=1;i<num_c;i++){
	if (strcmp(viduha[i].data,best1.data)<0)
		{best1=viduha[i];}
	else if (strcmp(viduha[i].data,best1.data)==0)
		{if (viduha[i].papuga>best1.papuga)
			{best1=viduha[i];}}
}
for(i=1;i<num_c;i++){
	if (strcmp(viduha[i].data,best2.data)>0)
		{best2=viduha[i];}
	else if (strcmp(viduha[i].data,best2.data)==0)
		{if (viduha[i].papuga<best2.papuga)
			{best2=viduha[i];}}
}
text_data(s,best1.data);
text_data(s2,best2.data);
Console::ForegroundColor=ConsoleColor::DarkCyan;
Console::BackgroundColor=ConsoleColor::White;
Console::CursorLeft=18;
Console::CursorTop=19;
printf("Самая старая(и мощная) видеокарта %s %s",best1.proiz,best1.name);
Console::CursorLeft=18;
Console::CursorTop=20;
printf("Была произведена в %s ",s);

Console::CursorLeft=18;
Console::CursorTop=22;
printf("Самая молодая(и слабая) видеокарта %s %s",best2.proiz,best2.name);
Console::CursorLeft=18;
Console::CursorTop=23;
printf("Была произведена в %s ",s2);
getch();
}

void kolvo(struct v *viduha,char *a, int num_c)
{

int i,k=0;
for(i=0;i<num_c;i++)
	{if (strcmp(viduha[i].proiz,a)==0)k++;}
if (strcmp(a,"Red")==0){Console::ForegroundColor=ConsoleColor::DarkRed;}
if (strcmp(a,"Yellow")==0){Console::ForegroundColor=ConsoleColor::DarkYellow;}
if (strcmp(a,"Green")==0){Console::ForegroundColor=ConsoleColor::DarkGreen;}
Console::BackgroundColor=ConsoleColor::White;
Console::CursorLeft=18;
Console::CursorTop=19;
printf("Количество видеокарт производителя %s: %d",a,k);
getch();
}

void vstavka(struct v* cl,char* name, int num_c)
{

int i;
struct sp *nov,*nt,*z=0;
for(nt=spisok; nt!=0 && strcmp(nt->name,name)<0; z=nt, nt=nt->sled);
if(nt && strcmp(nt->name,name)==0) return;
nov=(struct sp *) malloc(sizeof(struct sp));
strcpy(nov->name,name);
nov->pred = z;
nov->sled=nt;
nov->summa=0;
for(i=0;i<num_c;i++)
if(strcmp(cl[i].name,name)==0)
{nov->summa+=cl[i].papuga;strcpy(nov->proiz,cl[i].proiz);}
if(!z) spisok=nov;
if(z) z->sled=nov;
if(nt) nt->pred=nov;
return;
}

void alfalist(struct v* viduh,int a, int num_c)
{

int i;
struct sp* nt,*z;
Console::ForegroundColor=ConsoleColor::White;
Console::BackgroundColor=ConsoleColor::DarkMagenta;
Console::Clear();
if(!spisok)
 for(i=0;i<num_c;i++)
	vstavka(viduh,viduh[i].name,num_c);

Console::Clear();
printf("\n Алфавитный список видеокарт");
printf("\n ===============================\n");
if (a==1){
for(nt=spisok; nt!=0; nt=nt->sled)
printf("\n %-10s %-20s %ld",nt->proiz,nt->name,nt->summa);
}
if (a==2){
for(nt=spisok,z=0; nt!=0; z=nt,nt=nt->sled);
for(nt=z; nt!=0; nt=nt->pred)
printf("\n %-10s %-20s %ld",nt->proiz,nt->name,nt->summa);
}
getch();
}

void listing(struct v* viduh, int num_c)
{

int i;
struct v* net;
Console::ForegroundColor=ConsoleColor::White;
Console::BackgroundColor=ConsoleColor::DarkMagenta;
Console::Clear();
printf("\n\r Видеокарты, удовлетворяющие требованиям для Fart Kray (G>=400, Объем памяти>=550)");
printf("\n\r Произв.    Модель           G        (Объем памяти/количество ядер/частота) ");
printf("\n\r=====================================================");
for(i=0,net=viduh;i<num_c;net++,i++)
{if ((((net->papuga)>400) && ((net->mimore)>550))){
	printf("\n %-10s %-15s %-10ld(%ld/%ld/%ld)",net->proiz,net->name,net->papuga,net->mimore,net->coris,net->freq);};};
getch();
}

void diagram(struct v *viduha, int num_c)
{

struct sp *nt;
int len,i,NColor;
long sum1 = 0 ;
long sum;
char str1[200];
char str2[200];
System::ConsoleColor Color;
Console::ForegroundColor=ConsoleColor::White;
Console::BackgroundColor=ConsoleColor::DarkMagenta;
Console::Clear();
for(i=0;i<num_c;i++) sum1 = sum1+viduha[i].papuga;
sum=sum1/num_c;
if(!spisok)
for(i=0;i<num_c;i++)
vstavka(viduha,viduha[i].name,num_c);
Color=ConsoleColor::Black; NColor=0;
Console::BackgroundColor=ConsoleColor::Black;
Console::ForegroundColor=ConsoleColor::Magenta;
printf("     Произ.     Модель        Уровень производительности относительно среднего значения в процентах и диаграмма                                                       \n");
printf("=========================================================================================================================================================================\n");
Console::ForegroundColor=ConsoleColor::White;
 Console::BackgroundColor= ConsoleColor::DarkMagenta;
printf("     Cр.знач производ.(%d)   100%%       ",sum);

Console::BackgroundColor=ConsoleColor::White;
Console::CursorLeft=40;
for(len=0; len<50; len++) printf(" ");
 Console::ForegroundColor=ConsoleColor::White;
 Console::BackgroundColor= ConsoleColor::DarkMagenta;
printf("\n=========================================================================================================================================================================");
for(nt=spisok,i=0; nt!=0; nt=nt->sled,i++)
{
 sprintf(str1,"%-10s %-10s",viduha[i].proiz,viduha[i].name);
 sprintf(str2,"%3.1f%%",(viduha[i].papuga*100./sum));
 Console::ForegroundColor=ConsoleColor::White;
 Console::BackgroundColor= ConsoleColor::DarkMagenta;
 Console::CursorLeft=5; Console::CursorTop=i+4;
 printf(str1);
 Console::CursorLeft=30;
 printf("%s",str2);
 Console::BackgroundColor=ConsoleColor::Magenta;
if (strcmp(viduha[i].proiz,"Red")==0){Console::BackgroundColor=ConsoleColor::Red;}
if (strcmp(viduha[i].proiz,"Yellow")==0){Console::BackgroundColor=ConsoleColor::DarkYellow;}
if (strcmp(viduha[i].proiz,"Green")==0){Console::BackgroundColor=ConsoleColor::DarkGreen;}

 Console::CursorLeft=40;
 for(len=0; len<(viduha[i].papuga)*50/sum; len++) printf(" ");
 if(NColor==14)
{ Color=ConsoleColor::Black; NColor=0; }
 }
getch();
return ;
}

void kol1(struct v *viduha, int num_c)
{

char a[80];
Console::CursorLeft=18;
Console::CursorTop=18;
Console::BackgroundColor=ConsoleColor::Black;
Console::ForegroundColor=ConsoleColor::White;
printf("Введите название производителя: ");
SetConsoleCP(1251);
gets(a);
SetConsoleCP(866);
int i,k=0;
for(i=0;i<num_c;i++)
	{if (strcmp(viduha[i].proiz,a)==0)k++;}
Console::ForegroundColor=ConsoleColor::DarkCyan;
Console::BackgroundColor=ConsoleColor::White;
Console::CursorLeft=18;
Console::CursorTop=19;
printf("Количество видеокарт производителя %s: %d",a,k);
setlocale(LC_CTYPE,"Russian");
getch();
}

void sovpadeniya(struct v *viduha, int num_c)
{

int i,l,t,t1,prov,coun;
int *a;
int *a1;
a=(int*)malloc(num_c*sizeof(int));
System::ConsoleColor Color;
Console::ForegroundColor=ConsoleColor::White;
Console::BackgroundColor=ConsoleColor::DarkMagenta;
Console::Clear();
Console::CursorLeft=1;
Console::CursorTop=2;
t=0;
for(i=0;i<num_c;i++)
{
	prov=0;
	for(l=0;l<i;l++)
	{
		if (viduha[i].mimore==viduha[l].mimore) {prov=1;break;}
	}
	if (prov==1) continue;
	a[t]=viduha[i].mimore;
	t+=1;
}
a1=(int*)malloc(t*sizeof(int));
t1=0;
printf("Видеокарты, с повторяющимся количеством памяти\n");
printf("============================================================================================================\n");

for(i=0;i<t;i++)
{
	coun=0;
	for(l=0;l<num_c;l++)
	{
		if (a[i]==viduha[l].mimore){coun+=1;}
}
	if (coun<=1)continue;
	a1[t1]=a[i];
	printf(" Объем памяти в %dМБ у %d видеокарт: ",a1[t1],coun);
	for(l=0;l<num_c;l++)
	{
		if (a1[t1]==viduha[l].mimore){printf("%s %s; ",viduha[l].proiz,viduha[l].name);}
	}
	printf("\n");
	t1+=1;
}
printf("\n\n Объем памяти, который повторяется не в одной видеокарте: ");

for(i=0;i<t1;i++)
{
	printf("%d ",a1[i]);
}

getch();
}
