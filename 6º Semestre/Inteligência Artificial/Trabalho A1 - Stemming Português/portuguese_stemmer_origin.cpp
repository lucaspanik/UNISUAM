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
           if (!strrchr("\n\"'`1234567890-=¬!£$%^&*()_+ []{};'#:@~,./<>?", buf))
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
                   if ( (ends(word,"a") || (ends(word,"ã"))) && (wlength>=3)) feminine (word);
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
                 case 'É': word[i]='é';
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
   {"ões",3,"ão"},
   {"ães",1,"ão",{"mãe"}},
   {"ais",1,"al",{"cais","mais"}},
   {"éis",2,"el"},
   {"eis",2,"el"},
   {"óis",2,"ol"},
   {"is",2,"il",{"lápis","cais","mais","crúcis","biquínis","pois","depois","dois"}},
   {"les",3,"l"},
   {"res",3,"r"},
   {"s",2,"",{"aliás","pires","lápis","cais","mais",
              "férias","fezes","pêsames","crúcis","gás",
              "atrás","moisés","através","convés","ês",
              "país","após","ambas","ambos","messias"}}};

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
   {"ona",3,"ão",{"abandona","lona","iona","cortisona","monótona","maratona","acetona","detona","carona"}},
   {"ora",3,"or"},
   {"na",4,"no",{"carona","abandona","lona","iona","cortisona","monótona","maratona","acetona","detona","guiana","campana","grana","caravana","banana","paisana"}},
   {"inha",3,"inho","rainha","linha","minha"},
   {"esa",3,"ês",{"mesa","obesa","princesa","turquesa","ilesa","pesa","presa"}},
   {"osa",3,"oso",{"mucosa","prosa"}},
   {"íaca",3,"íaco"},
   {"ica",3,"ico",{"dica"}},
   {"ada",2,"ado",{"pitada"}},
   {"ida",3,"ido",{"vida"}},
   {"ída",3,"ido",{"recaída","saída","dúvida"}},
   {"ima",3,"imo",{"vítima"}},
   {"iva",3,"ivo",{"saliva","oliva"}},
   {"eira",3,"eiro",{"beira","cadeira","frigideira","bandeira","feira","capoeira","barreira","fronteira","besteira","poeira"}},
   {"ã",2,"ão",{"amanhã","arapuã","fã","divã"}}};

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
  {"díssimo",5},
  {"abilíssimo",5},
  {"íssimo",3},
  {"ésimo",3},
  {"érrimo",4},
  {"zinho",2},
  {"quinho",4,"c"},
  {"uinho",4},
  {"adinho",3},
  {"inho",3,"",{"caminho","cominho"}},
  {"alhão",4},
  {"uça",4},
  {"aço",4,"",{"antebraço"}},
  {"aça",4},
  {"adão",4},
  {"idão",4},
  {"ázio",3,"",{"topázio"}},
  {"arraz",4},
  {"zarrão",3},
  {"arrão",4},
  {"arra",3},
  {"zão",2,"",{"coalizão"}},
  {"ão",3,"",{"camarão","chimarrão","canção","coração","embrião","grotão","glutão",
              "ficção","fogão","feição","furacão","gamão","lampião","leão","macacão","nação",
              "órfão","orgão","patrão","portão","quinhão","rincão","tração",
              "falcão","espião","mamão","folião","cordão","aptidão","campeão",
              "colchão","limão","leilão","melão","barão","milhão","bilhão","fusão",
              "cristão","ilusão","capitão","estação","senão"}}};
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
  {"ido",3,"",{"cândido","consolido","rápido","decido","tímido","duvido","marido"}},
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
  {"ência",3},
  {"ância",4,"",{"ambulância"}},
  {"edouro",3},
  {"queiro",3,"c"},
  {"adeiro",4,"",{"desfiladeiro"}},
  {"eiro",3,"",{"desfiladeiro","pioneiro","mosteiro"}},
  {"uoso",3},
  {"oso",3,"",{"precioso"}},
  {"alizaç",5},
  {"atizaç",5},
  {"tizaç",5},
  {"izaç",5,"",{"organizaç"}},
  {"aç",3,"",{"equaç","relaç"}},
  {"iç",3,"",{"eleição"}},
  {"ário",3,"",{"voluntário","salário","aniversário","diário","lionário","armário"}},{"atório",3},{"rio",5,"",{"voluntário","salário","aniversário","diário","compulsório","lionário","próprio","stério","armário"}},
  {"ério",6},
  {"ês",4},
  {"eza",3},
  {"ez",4},
  {"esco",4},
  {"ante",2,"",{"gigante","elefante","adiante","possante","instante","restaurante"}},
  {"ástico",4,"",{"eclesiástico"}},
  {"alístico",3},
  {"áutico",4},
  {"êutico",4},
  {"tico",3,"",{"político","eclesiástico","diagnostico","prático","doméstico","diagnóstico","idêntico","alopático","artístico","autêntico","eclético","crítico","critico"}},
  {"ico",4,"",{"tico","público","explico"}},
  {"ividade",5},
  {"idade",4,"",{"autoridade","comunidade"}},
  {"oria",4,"",{"categoria"}},
  {"encial",5},
  {"ista",4},
  {"auta",5},
  {"quice",4,"c"},
  {"ice",4,"",{"cúmplice"}},
  {"íaco",3},
  {"ente",4,"",{"freqüente","alimente","acrescente","permanente","oriente","aparente"}},
  {"ense",5},
  {"inal",3},
  {"ano",4},
  {"ável",2,"",{"afável","razoável","potável","vulnerável"}},
  {"ível",3,"",{"possível"}},
  {"vel",5,"",{"possível","vulnerável","solúvel"}},
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
 {"aríamo",2},{"ássemo",2},{"eríamo",2},
 {"êssemo",2},{"iríamo",3},{"íssemo",3},
 {"áramo",2},{"árei",2},{"aremo",2},{"ariam",2},
 {"aríei",2},{"ássei",2},{"assem",2},{"ávamo",2},
 {"êramo",3},{"eremo",3},{"eriam",3},{"eríei",3},
 {"êssei",3},{"essem,3"},{"íramo",3},{"iremo",3},
 {"iriam",3},{"iríei",3},{"íssei",3},{"issem",3},
 {"ando",2},{"endo",3},{"indo",3},{"ondo",3},
 {"aram",2},{"arão",2},{"arde",2},{"arei",2},{"arem",2},{"aria",2},
 {"armo",2},{"asse",2},{"aste",2},{"avam",2,"",{"agravam"}},
 {"ávei",2},{"eram",3},{"erão",3},{"erde",3},
 {"erei",3},{"êrei",3},{"erem",3},{"eria",3},
 {"ermo",3},{"esse",3},{"este",3,"",{"faroeste","agreste"}},{"íamo",3},
 {"iram",3},{"íram",3},{"irão",2},{"irde",2},
 {"irei",3,"",{"admirei"}},{"irem",3,"",{"adquirem"}},{"iria",3},{"irmo",3},
 {"isse",3},{"iste",4},{"iava",4,"",{"ampliava"}},{"amo",2},{"iona",3},
 {"ara",2,"",{"arara","prepara"}},{"ará",2,"",{"alvará"}},{"are",2,"",{"prepare"}},
 {"ava",2,"",{"agrava"}},{"emo",2},{"era",3,"",{"acelera","espera"}},{"erá",3},{"ere",3,"",{"espere"}},
 {"iam",3,"",{"enfiam","ampliam","elogiam","ensaiam"}},{"íei",3},
 {"imo",3,"",{"reprimo","intimo","íntimo","nimo","queimo","ximo"}},
 {"ira",3,"",{"fronteira","sátira"}},{"ído",3},{"irá"},
 {"tizar",4,"",{"alfabetizar"}},{"izar",5,"",{"organizar"}}, {"itar",5,"",{"acreditar","explicitar","estreitar"}},
 {"ire",3,"",{"adquire"}},{"omo",3},{"ai",2},{"am",2},{"ear",4,"",{"alardear","nuclear"}},
 {"ar",2,"",{"azar","bazaar","patamar"}},{"uei",3},{"uía",5,"u"},
 {"ei",3},{"guem",3,"g"},{"em",2,"",{"alem","virgem"}},{"er",2,"",{"éter","pier"}},{"eu",3,"",{"chapeu"}},
 {"ia",3,"",{"estória","fatia","acia","praia","elogia","mania","lábia","aprecia","polícia","arredia","cheia","ásia"}},
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
                                 {"á",3}, {"ê",3,"",{"bebê"}},
                                 {"a",3,"",{"ásia"}},{"e",3},{"o",3,"",{"ão"}}};
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
       if (s[i]=='á') s[i]='a';
       else if (s[i]=='ó') s[i]='o';
       else if (s[i]=='é') s[i]='e';
       else if (s[i]=='ê') s[i]='e';
       else if (s[i]=='í') s[i]='i';

       i--;
    }
}
/******************************************************************************/



