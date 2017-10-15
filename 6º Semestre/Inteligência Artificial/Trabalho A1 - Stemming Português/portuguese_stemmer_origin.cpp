#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* #include <conio.h> */
#define TRUE 1
#define FALSE 0

#define WORDSFILE "texto.txt"     /* file with the terms to be stemmed, use quotation marks */
#define STEMSFILE "saida.txt" /* output file, use quotation marks */

#define ADV 1
#define AUG 23    
#define NOUN 86
#define VERB 103
#define PLURAL 11
#define FEM 15
#define VOW 7




/* era assim
struct stem_struct { char suffix[10];
                     int min_stem_size;
                     char replacement[5];
                     char exceptions[50][15];
                    };
*/
struct stem_struct { char suffix[11];
                     int min_stem_size;
                     char replacement[5];
                     char exceptions[50][15];
                    };


/***********************  FUNCTION DECLARATIONS  *****************************/
void to_lower_case (char word[]);
void plural (char  w[]);
void adverb (char w[]);
void feminine (char w[]);
void augmentative (char w[]);
int noun (char w[]);
int verb (char w[]);
void thematic_vowel (char w[]);
int exceptions (char w[], char ex[][15]);
int exceptions2(char w[], char ex[][15]);
int ends(char w[], char s[]);
int strip_suffix (char w[], struct stem);
int strip_suffix2 (char w[], struct stem);
void append(char w[], char r[]);
void remove_accents (char s[]);

/******************************************************************************/
void main()
{
 
 char word[23];
 char buf;
 int wlength,slength;
 FILE *wordsfileptr;
 FILE *stemsfileptr;
 int i=0;

 printf("\n\n");
 if ((wordsfileptr=fopen(WORDSFILE,"r"))==NULL) printf("cannot open file");
 else
 {
    if ((stemsfileptr=fopen(STEMSFILE,"w"))==NULL)printf("cannot create file");
    else
    {
        while (!feof(wordsfileptr))
       {
           buf=getc(wordsfileptr);
           if (!strrchr("\n\"'`1234567890-=�!�$%^&*()_+ []{};'#:@~,./<>?", buf))
           {
               word[i]=buf;
               i++;
           }
           else
           {
               if (buf=='\n') fputs("\n",stemsfileptr);
               word[i]='\0';
               i=0;
               if ((word!=NULL) && (word[0]!='\0'))
               {
                   to_lower_case(word);
                   wlength=strlen(word);
				   
	                printf("Word: %s   ",word);

                   if (ends(word,"s") && (wlength>=3)) plural (word);
                       adverb (word);
                   if ( (ends(word,"a") || (ends(word,"�"))) && (wlength>=3)) feminine (word);
                       augmentative(word);
                   if (!noun(word))
                       if (!verb(word)) thematic_vowel(word);
                           remove_accents(word);
                   fputs(word,stemsfileptr);
                   fputs(" ",stemsfileptr);
		   printf("Stem: %s\n",word);
                }


	     }
       }
                fclose(wordsfileptr);
                fclose(stemsfileptr);

       }
 }
 }
/******************************************************************************/
void to_lower_case ( char word[] )

{
	int i=0;
	for ( i=0 ; i < strlen(word) ; i++ )
        {
           if ( (word[i] >= 'A') && (word[i] <= 'Z') )
	      word[i] += 'a' - 'A';
           else
              switch (word[i])
              {
                 case '�': word[i]='�';
              }
        }

}

/******************************************************************************/
int ends(char w[], char s[])
{

  int i,j;

  i=strlen(s);
  j=strlen(w);

   while (i>0)
    {
       if (w[j-1]!=s[i-1])
       {
	 i=0;
	 return FALSE;
       }
       else
       {
	 i--;
	 j--;
       }
}
return TRUE;
}


/******************************************************************************/
int strip_suffix (char w[], struct stem_struct stem)
{
 int wlen,slen;


  wlen=strlen(w);
  slen=strlen(stem.suffix);

  if ((wlen-slen>=stem.min_stem_size) && (ends(w,stem.suffix)) && !(exceptions(w,stem.exceptions)))
    {
    w[wlen-slen]='\0';
    if (stem.replacement !=NULL) append(w,stem.replacement);
    return TRUE;
    }
  else
    return FALSE;
}

/******************************************************************************/

int strip_suffix2 (char w[], struct stem_struct stem)
{
 int wlen,slen;


  wlen=strlen(w);
  slen=strlen(stem.suffix);

  if ((wlen-slen>=stem.min_stem_size) && (ends(w,stem.suffix)) && !(exceptions2(w,stem.exceptions)))
    {
    w[wlen-slen]='\0';
    if (stem.replacement !=NULL) append(w,stem.replacement);
    return TRUE;
    }
  else
    return FALSE;
}
/******************************************************************************/
int exceptions(char w[], char ex[][15])
{
 int i=0;
 int done = false;
 while ((i<40) && (!done) && strlen(ex[i])>0)
 {
  if ((ends(w,ex[i])))
    {
    done = true;
    return true;
    }
  else
    i++;
    if (i>=39) return false;
  }

return false;
}
/******************************************************************************/

int exceptions2(char w[], char ex[][15])
{
 int i=0;
 int done = false;
 while ((i<50) && (!done) && strlen(ex[i])>0)
 {
  if (!(strcmp(w,ex[i])))
    {
    done = true;
    return true;
    }
  else
    i++;
    if (i>=49) return false;
  }

return false;
}

/******************************************************************************/


void append(char w[], char r[])
{
  int wlen,rlen,i;

  rlen=strlen(r);
  wlen=strlen(w);

  for (i=0; i<rlen; i++) w[wlen+i]=r[i];
  w[wlen+rlen]='\0';

}

/******************************************************************************/
void plural(char w[])
{

   struct stem_struct plural_suffix[PLURAL]= {
   {"ns",1,"m"},
   {"�es",3,"�o"},
   {"�es",1,"�o",{"m�e"}},
   {"ais",1,"al",{"cais","mais"}},
   {"�is",2,"el"},
   {"eis",2,"el"},
   {"�is",2,"ol"},
   {"is",2,"il",{"l�pis","cais","mais","cr�cis","biqu�nis","pois","depois","dois"}},
   {"les",3,"l"},
   {"res",3,"r"},
   {"s",2,"",{"ali�s","pires","l�pis","cais","mais",
              "f�rias","fezes","p�sames","cr�cis","g�s",
              "atr�s","mois�s","atrav�s","conv�s","�s",
              "pa�s","ap�s","ambas","ambos","messias"}}};

   int i=0;
   int done = false;

   while ((i<PLURAL) && (!done))
   {
       if (strip_suffix2(w, plural_suffix[i])) done = true;
       i++;
   }
}

/******************************************************************************/
void feminine(char w[])
{

   struct stem_struct feminine_suffix[FEM]={
   {"ona",3,"�o",{"abandona","lona","iona","cortisona","mon�tona","maratona","acetona","detona","carona"}},
   {"ora",3,"or"},
   {"na",4,"no",{"carona","abandona","lona","iona","cortisona","mon�tona","maratona","acetona","detona","guiana","campana","grana","caravana","banana","paisana"}},
   {"inha",3,"inho","rainha","linha","minha"},
   {"esa",3,"�s",{"mesa","obesa","princesa","turquesa","ilesa","pesa","presa"}},
   {"osa",3,"oso",{"mucosa","prosa"}},
   {"�aca",3,"�aco"},
   {"ica",3,"ico",{"dica"}},
   {"ada",2,"ado",{"pitada"}},
   {"ida",3,"ido",{"vida"}},
   {"�da",3,"ido",{"reca�da","sa�da","d�vida"}},
   {"ima",3,"imo",{"v�tima"}},
   {"iva",3,"ivo",{"saliva","oliva"}},
   {"eira",3,"eiro",{"beira","cadeira","frigideira","bandeira","feira","capoeira","barreira","fronteira","besteira","poeira"}},
   {"�",2,"�o",{"amanh�","arapu�","f�","div�"}}};

   int i=0;
   int done = false;

   while ((i<FEM) && (!done))
   {
       if (strip_suffix2(w, feminine_suffix[i])) done = true;
       i++;
   }

}

/******************************************************************************/

void adverb (char w[])
{
  struct stem_struct adv_suffix[ADV]={{"mente",4,"",{"experimente"}}};

  int i=0;
  int done=0 ;

    while ((i<ADV) && (!done))
    {
       if (strip_suffix(w,adv_suffix[i]))done = true;
       i++;
    }

}
/******************************************************************************/

void augmentative(char w[])
{
  struct stem_struct aug_suffix[AUG]= {
  {"d�ssimo",5},
  {"abil�ssimo",5},
  {"�ssimo",3},
  {"�simo",3},
  {"�rrimo",4},
  {"zinho",2},
  {"quinho",4,"c"},
  {"uinho",4},
  {"adinho",3},
  {"inho",3,"",{"caminho","cominho"}},
  {"alh�o",4},
  {"u�a",4},
  {"a�o",4,"",{"antebra�o"}},
  {"a�a",4},
  {"ad�o",4},
  {"id�o",4},
  {"�zio",3,"",{"top�zio"}},
  {"arraz",4},
  {"zarr�o",3},
  {"arr�o",4},
  {"arra",3},
  {"z�o",2,"",{"coaliz�o"}},
  {"�o",3,"",{"camar�o","chimarr�o","can��o","cora��o","embri�o","grot�o","glut�o",
              "fic��o","fog�o","fei��o","furac�o","gam�o","lampi�o","le�o","macac�o","na��o",
              "�rf�o","org�o","patr�o","port�o","quinh�o","rinc�o","tra��o",
              "falc�o","espi�o","mam�o","foli�o","cord�o","aptid�o","campe�o",
              "colch�o","lim�o","leil�o","mel�o","bar�o","milh�o","bilh�o","fus�o",
              "crist�o","ilus�o","capit�o","esta��o","sen�o"}}};
        int i=0;
        int done=0 ;

        while ((i<AUG) && (!done))
        {
           if (strip_suffix2(w,aug_suffix[i]))done = true;
           i++;
        }
 }
/******************************************************************************/

int noun(char w[])
{

  struct stem_struct noun_suffix[NOUN]= {
  {"encialista",4},
  {"alista",5},
  {"agem",3,"",{"coragem","chantagem","vantagem","carruagem"}},
  {"iamento",4},
  {"amento",3,"",{"firmamento","fundamento","departamento"}},
  {"imento",3},
  {"mento",6,"",{"firmamento","elemento","complemento","instrumento","departamento"}},
  {"alizado",4},
  {"atizado",4},
  {"tizado",4,"",{"alfabetizado"}},
  {"izado",5,"",{"organizado","pulverizado"}},
  {"ativo",4,"",{"pejorativo","relativo"}},
  {"tivo",4,"",{"relativo"}},
  {"ivo",4,"",{"passivo","possessivo","pejorativo","positivo"}},
  {"ado",2,"",{"grado"}},
  {"ido",3,"",{"c�ndido","consolido","r�pido","decido","t�mido","duvido","marido"}},
  {"ador",3},
  {"edor",3},
  {"idor",4,"",{"ouvidor"}},
  {"dor",4,"",{"ouvidor"}},
  {"sor",4,"",{"assessor"}},
  {"atoria",5},
  {"tor",3,"",{"benfeitor","leitor","editor","pastor","produtor","promotor","consultor"}},
  {"or",2,"",{"motor","melhor","redor","rigor","sensor","tambor","tumor","assessor","benfeitor","pastor","terior","favor","autor"}},
  {"abilidade",5},
  {"icionista",4},
  {"cionista",5},
  {"ionista",5},
  {"ionar",5},
  {"ional",4},
  {"�ncia",3},
  {"�ncia",4,"",{"ambul�ncia"}},
  {"edouro",3},
  {"queiro",3,"c"},
  {"adeiro",4,"",{"desfiladeiro"}},
  {"eiro",3,"",{"desfiladeiro","pioneiro","mosteiro"}},
  {"uoso",3},
  {"oso",3,"",{"precioso"}},
  {"aliza�",5},
  {"atiza�",5},
  {"tiza�",5},
  {"iza�",5,"",{"organiza�"}},
  {"a�",3,"",{"equa�","rela�"}},
  {"i�",3,"",{"elei��o"}},
  {"�rio",3,"",{"volunt�rio","sal�rio","anivers�rio","di�rio","lion�rio","arm�rio"}},{"at�rio",3},{"rio",5,"",{"volunt�rio","sal�rio","anivers�rio","di�rio","compuls�rio","lion�rio","pr�prio","st�rio","arm�rio"}},
  {"�rio",6},
  {"�s",4},
  {"eza",3},
  {"ez",4},
  {"esco",4},
  {"ante",2,"",{"gigante","elefante","adiante","possante","instante","restaurante"}},
  {"�stico",4,"",{"eclesi�stico"}},
  {"al�stico",3},
  {"�utico",4},
  {"�utico",4},
  {"tico",3,"",{"pol�tico","eclesi�stico","diagnostico","pr�tico","dom�stico","diagn�stico","id�ntico","alop�tico","art�stico","aut�ntico","ecl�tico","cr�tico","critico"}},
  {"ico",4,"",{"tico","p�blico","explico"}},
  {"ividade",5},
  {"idade",4,"",{"autoridade","comunidade"}},
  {"oria",4,"",{"categoria"}},
  {"encial",5},
  {"ista",4},
  {"auta",5},
  {"quice",4,"c"},
  {"ice",4,"",{"c�mplice"}},
  {"�aco",3},
  {"ente",4,"",{"freq�ente","alimente","acrescente","permanente","oriente","aparente"}},
  {"ense",5},
  {"inal",3},
  {"ano",4},
  {"�vel",2,"",{"af�vel","razo�vel","pot�vel","vulner�vel"}},
  {"�vel",3,"",{"poss�vel"}},
  {"vel",5,"",{"poss�vel","vulner�vel","sol�vel"}},
  {"bil",3,"vel"},
  {"ura",4,"",{"imatura","acupuntura","costura"}},
  {"ural",4},
  {"ual",3,"",{"bissexual","virtual","visual","pontual"}},
  {"ial",3},
  {"al",4,"",{"afinal","animal","estatal","bissexual","desleal","fiscal","formal","pessoal","liberal","postal","virtual","visual","pontual","sideral","sucursal"}},
  {"alismo",4},
  {"ivismo",4},
  {"ismo",3,"",{"cinismo"}}};

  int i=0;
  int done = false ;

  while ((i<NOUN) && (!done))
    {
       if (strip_suffix(w,noun_suffix[i]))
       {
       done= true;
       return true;
       }
       i++;
       if (i==NOUN-2)
        return false;
    }
return false;
}

/******************************************************************************/

int verb(char w[])
{

 struct stem_struct verb_suffix[VERB] = {
 {"ar�amo",2},{"�ssemo",2},{"er�amo",2},
 {"�ssemo",2},{"ir�amo",3},{"�ssemo",3},
 {"�ramo",2},{"�rei",2},{"aremo",2},{"ariam",2},
 {"ar�ei",2},{"�ssei",2},{"assem",2},{"�vamo",2},
 {"�ramo",3},{"eremo",3},{"eriam",3},{"er�ei",3},
 {"�ssei",3},{"essem,3"},{"�ramo",3},{"iremo",3},
 {"iriam",3},{"ir�ei",3},{"�ssei",3},{"issem",3},
 {"ando",2},{"endo",3},{"indo",3},{"ondo",3},
 {"aram",2},{"ar�o",2},{"arde",2},{"arei",2},{"arem",2},{"aria",2},
 {"armo",2},{"asse",2},{"aste",2},{"avam",2,"",{"agravam"}},
 {"�vei",2},{"eram",3},{"er�o",3},{"erde",3},
 {"erei",3},{"�rei",3},{"erem",3},{"eria",3},
 {"ermo",3},{"esse",3},{"este",3,"",{"faroeste","agreste"}},{"�amo",3},
 {"iram",3},{"�ram",3},{"ir�o",2},{"irde",2},
 {"irei",3,"",{"admirei"}},{"irem",3,"",{"adquirem"}},{"iria",3},{"irmo",3},
 {"isse",3},{"iste",4},{"iava",4,"",{"ampliava"}},{"amo",2},{"iona",3},
 {"ara",2,"",{"arara","prepara"}},{"ar�",2,"",{"alvar�"}},{"are",2,"",{"prepare"}},
 {"ava",2,"",{"agrava"}},{"emo",2},{"era",3,"",{"acelera","espera"}},{"er�",3},{"ere",3,"",{"espere"}},
 {"iam",3,"",{"enfiam","ampliam","elogiam","ensaiam"}},{"�ei",3},
 {"imo",3,"",{"reprimo","intimo","�ntimo","nimo","queimo","ximo"}},
 {"ira",3,"",{"fronteira","s�tira"}},{"�do",3},{"ir�"},
 {"tizar",4,"",{"alfabetizar"}},{"izar",5,"",{"organizar"}}, {"itar",5,"",{"acreditar","explicitar","estreitar"}},
 {"ire",3,"",{"adquire"}},{"omo",3},{"ai",2},{"am",2},{"ear",4,"",{"alardear","nuclear"}},
 {"ar",2,"",{"azar","bazaar","patamar"}},{"uei",3},{"u�a",5,"u"},
 {"ei",3},{"guem",3,"g"},{"em",2,"",{"alem","virgem"}},{"er",2,"",{"�ter","pier"}},{"eu",3,"",{"chapeu"}},
 {"ia",3,"",{"est�ria","fatia","acia","praia","elogia","mania","l�bia","aprecia","pol�cia","arredia","cheia","�sia"}},
 {"ir",3,"",{"freir"}},{"iu",3},{"eou",5},{"ou",3},{"i",3}};


  int i=0;
  int done= false ;

  while ((i<VERB) && (!done))
    {
       if (strip_suffix(w,verb_suffix[i]))
       {
       done= true;
       return true;
     }
     i++;
     if (i>=VERB-2) return false;
    }
return false;
}

/******************************************************************************/

void thematic_vowel(char w[])
{

struct stem_struct vowel[VOW] = {{"bil",2,"vel"},
                                 {"gue",2,"g",{"gangue","jegue"}},
                                 {"�",3}, {"�",3,"",{"beb�"}},
                                 {"a",3,"",{"�sia"}},{"e",3},{"o",3,"",{"�o"}}};
  int i=0;
  int done=false ;

  while ((i<VOW) && (!done))
    {
     if (strip_suffix(w,vowel[i])) done = TRUE;
     i++;
    }
}


/******************************************************************************/
void remove_accents (char s[])
{
 int i;
 i=strlen(s)-1;

  while (i>=0)
    {
       if (s[i]=='�') s[i]='a';
       else if (s[i]=='�') s[i]='o';
       else if (s[i]=='�') s[i]='e';
       else if (s[i]=='�') s[i]='e';
       else if (s[i]=='�') s[i]='i';

       i--;
    }
}
/******************************************************************************/



