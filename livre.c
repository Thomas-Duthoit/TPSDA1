#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
    T_Emp emp = {"", -1, -1, -1, -1};
    lireChaine("CODE :", (ptrL->code ), K_MaxCode);
    lireChaine("TITRE :", (ptrL->titre), K_MaxTit );
    lireChaine("AUTEUR :", (ptrL->auteur ), K_MaxAut);
    lireChaine("EDITEUR :", (ptrL->editeur ), K_MaxEdit);
    printf("ANNEE :");
    scanf("%d", &(ptrL->annee));
    ptrL->emprunteur = emp;
}

/*void afficherLivre(const T_livre *ptrL)
{
afficherChaine("CODE :", (ptrL->code));
printf(" - ");
afficherChaine("TITRE :", (ptrL->titre));
printf(" - ");
afficherChaine("AUTEUR :", (ptrL->auteur));
printf(" - ");
afficherChaine("EDITEUR :", (ptrL->editeur));
printf(" - ANNEE : %d - ", ptrL->annee);
afficherChaine("EMPRUNTEUR :", (ptrL->emprunteur));
printf("\n");
}*/

void afficherLivre(const T_livre *L)
{

char jour[13],mois[13];
afficherChaine("CODE :", (L->code));
printf(" - ");
afficherChaine("AUTEUR :", (L->auteur));
printf(" - ");
afficherChaine("EDITEUR :", (L->editeur));
printf(" - ANNEE : %d", L->annee);
printf("\n titre du livre : %s",L->titre);

printf("\n emprunteur du livre : %s",L->emprunteur.nomemprunteur);

printf("\n  emprunt realise le : ");
switch(L->emprunteur.lejour)
{
case 0 :  strcpy(jour,"lundi");break;
case 1 :  strcpy(jour,"mardi");break;
case 2 :  strcpy(jour,"mercredi");break;
case 3 :  strcpy(jour,"jeudi");break;
case 4 :  strcpy(jour,"vendredi");break;
case 5 :  strcpy(jour,"samedi");break;
case 6 :  strcpy(jour,"dimanche");break;

default : strcpy(jour,"jour inconnu");break;
}
printf("%s ",jour);

printf("%d ",L->emprunteur.ladate);


switch(L->emprunteur.lemois)
{
case 0 :  strcpy(mois,"janvier");break;
case 1 :  strcpy(mois,"fevrier");break;
case 2 :  strcpy(mois,"mars");break;
case 3 :  strcpy(mois,"avril");break;
case 4 :  strcpy(mois,"mai");break;
case 5 :  strcpy(mois,"juin");break;
case 6 :  strcpy(mois,"juillet");break;
case 7 :  strcpy(mois,"aout");break;
case 8 :  strcpy(mois,"septembre");break;
case 9 :  strcpy(mois,"octobre");break;
case 10 :  strcpy(mois,"novembre");break;
case 11 :  strcpy(mois,"decembre");break;

default : strcpy(jour,"mois inconnu");break;
}
printf("%s ",mois);

printf("%d ",L->emprunteur.lannee);


}

void lireDateSysteme(T_Emp *E)
{
char j[9],m[10],h[9],mer[11],vir[2];
int d,a;


system("date > ladate"	);
FILE * fic=NULL;  // pointeur de fichier
fic=fopen("ladate","r"); //fileOpen en mode 'r'EAD

//ici , si fic vaut NULL, alors le fopen a indiquÃ©
//que le fichier ladate n'est pas accessible
if (fic!=NULL)
	{
	while(!feof(fic))	
		{
		fscanf(fic,"%s %d %s %d %s %s %s",j,&d,m,&a,vir,h,mer);		
		if (!feof(fic)) 
			printf("\n-->LU : %s- %d- %s- %d- %s- %s",j,d,m,a,h,mer);		

		}
	fclose(fic);
	
if (strcmp(j,"Mon")==0) E->lejour=lundi;
if (strcmp(j,"Tue")==0) E->lejour=mardi;
if (strcmp(j,"Wed")==0) E->lejour=mercredi;
if (strcmp(j,"Thu")==0) E->lejour=jeudi;
if (strcmp(j,"Fri")==0) E->lejour=vendredi;
if (strcmp(j,"Sat")==0) E->lejour=samedi;
if (strcmp(j,"Sun")==0) E->lejour=dimanche;

E->ladate=d;

if (strcmp(m,"Jan")==0) E->lemois=janvier;
if (strcmp(m,"Feb")==0) E->lemois=fevrier;
if (strcmp(m,"Mar")==0) E->lemois=mars;
if (strcmp(m,"Apr")==0) E->lemois=avril;
if (strcmp(m,"May")==0) E->lemois=mai;
if (strcmp(m,"Jun")==0) E->lemois=juin;
if (strcmp(m,"Jul")==0) E->lemois=juillet;
if (strcmp(m,"Aug")==0) E->lemois=aout;
if (strcmp(m,"Sep")==0) E->lemois=septembre;
if (strcmp(m,"Oct")==0) E->lemois=octobre;
if (strcmp(m,"Nov")==0) E->lemois=novembre;
if (strcmp(m,"Dec")==0) E->lemois=decembre;


E->lannee=a;
	}
	else
	{
		printf("n souci avec la date systeme !!");
		
		//on range une date irrÃ©elle 
		E->lejour=dimanche;
		E->ladate=99;
		E->lemois=decembre;
		E->lannee=-999;


	}

}

