#include <stdio.h>
#include <stdlib.h>
typedef struct Etudiant
{
    char Name[20];
    char Prenom[20];
    char CNE [20];
    int Age ;
    float DS ;
    float DB ;
    float OS ;
    float Math ;
    float Moy  ;
} Etudiant ;

typedef struct liste
{
    Etudiant info ;
    struct liste *suiv ;
} liste ;

void affichage (liste* L){
    int count = 1;
    liste* tmp = L;
    char v[10] = {'V'};
    char nv[10] = {"NV"};
    printf("+------+------------------+------------------+------------------+-------+-------------+-------------+-------------+-------------+-------------+---------+\n");
    printf("| Num  |      Prenom      |        Nom       |        CNE       |  Age  |      DS     |      DB     |      OS     |    Math     |     MOY     |  Vald   |\n");
    printf("+------+------------------+------------------+------------------+-------+-------------+-------------+-------------+-------------+-------------+---------+\n");
    while(tmp != NULL)
    {
        if (tmp->info.Moy >= 12 )
        {
            printf("| %-3d  |  %-15s |  %-15s |  %-15s |  %-3d  |  %-10.2f |  %-10.2f |  %-10.2f |  %-10.2f |  %-10.2f |   %-5s |\n",
                   count, tmp->info.Name, tmp->info.Prenom, tmp->info.CNE, tmp->info.Age,
                   tmp->info.DS, tmp->info.DB, tmp->info.OS,tmp->info.Math,tmp->info.Moy,v);
        }
        else
        {
            printf("| %-3d  |  %-15s |  %-15s |  %-15s |  %-3d  |  %-10.2f |  %-10.2f |  %-10.2f |  %-10.2f |  %-10.2f |   %-5s |\n",
                   count, tmp->info.Name, tmp->info.Prenom, tmp->info.CNE, tmp->info.Age,
                   tmp->info.DS, tmp->info.DB, tmp->info.OS,tmp->info.Math,tmp->info.Moy,nv);
        }
        tmp = tmp->suiv;
        count ++;
    }
    printf("+------+------------------+------------------+------------------+-------+-------------+-------------+-------------+-------------+-------------+---------+\n");
}

liste * inserDebut(liste *L, Etudiant student ){
    liste *p = (liste*) malloc (sizeof (liste));
    if (p == NULL ){
        printf ("Ereure d'allocation d'espace ");
        exit (32);
    }
    if (L == NULL){
        p -> info = student ;
        p->suiv = NULL ;
        return p ;
    }
    p ->info =  student ;
    p ->info.Moy = (student.DS+student.DB+student.OS+student.Math)/4;
    p ->suiv = L ;
    L = p ;
    return L ;
}

liste* inserFin(liste *L, Etudiant student){
    liste *p, *tmp;
    p = (liste*)malloc(sizeof(liste));
    p ->info = student;
    p ->info.Moy = (student.DS+student.DB+student.OS+student.Math)/4;
    p ->suiv = NULL;
    if(L==NULL)     L=p;
    else
    {
        tmp=L;
        while(tmp->suiv!= NULL)
            tmp = tmp->suiv;
        tmp->suiv = p;
    }
    return L;
}

Etudiant search (liste *l, char *nc){
    Etudiant etudVid = {"", "", "", 0, 0.0, 0.0, 0.0, 0.0, 0.0};
    liste *tmp = l ;
    if (l == NULL ) printf ("La liste est vide !!! ");
    while (tmp != NULL)
    {
        if (strcmp(tmp->info.Name,nc) == 0  || strcmp(tmp->info.CNE,nc) == 0 || strcmp(tmp->info.Prenom,nc ) == 0)
        {
            return tmp->info;
        }
        tmp = tmp->suiv;
    }
    printf("\n\t\tEtudiant n'existe pas !!!\n");
    return etudVid ;
}

liste * DeleteStudent(liste*l,char *cne ){

    liste *tmp, *ptmp;
    tmp = l ;
    if (l == NULL)
    {
        printf (" the list is empty !!! ");
        return l ;
    }
    if (strcmp(l->info.CNE,cne) == 0)
    {
        l =  l ->suiv ;
        free (tmp);
        return l;
    }
    ptmp = tmp ->suiv ;
    while (ptmp!= NULL && strcmp(ptmp->info.CNE,cne) != 0)
    {
        tmp = ptmp ;
        ptmp = ptmp ->suiv;
    }

    if (ptmp!=NULL && strcmp(ptmp->info.CNE,cne) == 0)
    {
        tmp ->suiv = ptmp ->suiv ;
        free (ptmp);
        return l ;
    }
    else
    {
        printf (" student not existed !!!! \n");
        return l ;
    }
}

Etudiant SearchMaxDS(liste* l){
    if (l == NULL)
    {
        printf(" the list is empty !!!");
        Etudiant etudVid = {"", "", "", 0, 0.0, 0.0, 0.0, 0.0, 0.0};
        return etudVid;
    }

    liste* tmp = l;
    Etudiant etudMax = tmp->info;

    while (tmp != NULL)
    {
        if (tmp->info.DS >= etudMax.DS)
        {
            etudMax = tmp->info;
        }
        tmp = tmp->suiv;
    }

    return etudMax;
}

Etudiant SearchMaxDB(liste* l){
    if (l == NULL)
    {
        printf(" the list is empty !!!");
        Etudiant etudVid = {"", "", "", 0, 0.0, 0.0, 0.0, 0.0, 0.0};
        return etudVid;
    }

    liste* tmp = l;
    Etudiant etudMax = tmp->info;

    while (tmp != NULL)
    {
        if (tmp->info.DB >= etudMax.DB)
        {
            etudMax = tmp->info;
        }
        tmp = tmp->suiv;
    }

    return etudMax;
}

Etudiant SearchMaxOS(liste* l){
    if (l == NULL)
    {
        printf(" the list is empty !!!");
        Etudiant etudVid = {"", "", "", 0, 0.0, 0.0, 0.0, 0.0, 0.0};
        return etudVid;
    }

    liste* tmp = l;
    Etudiant etudMax = tmp->info;

    while (tmp != NULL)
    {
        if (tmp->info.OS >= etudMax.OS)
        {
            etudMax = tmp->info;
        }
        tmp = tmp->suiv;
    }

    return etudMax;
}

Etudiant SearchMaxMath(liste* l){
    if (l == NULL)
    {
        printf(" the list is empty !!!");
        Etudiant etudVid = {"", "", "", 0, 0.0, 0.0, 0.0, 0.0, 0.0};
        return etudVid;
    }

    liste* tmp = l;
    Etudiant etudMax = tmp->info;

    while (tmp != NULL)
    {
        if (tmp->info.Math >= etudMax.Math)
        {
            etudMax = tmp->info;
        }
        tmp = tmp->suiv;
    }

    return etudMax;
}

void addByPosition(liste* L, int position){
    Etudiant s;
    printf(" \n student n%d : \n",position);
    printf("\n\t Enter the student's last name : ");
    scanf("%s",s.Name);
    printf("\n\t tEnter the student's first name : ");
    scanf("%s",s.Prenom);
    printf("\n\t Enter the student's CNE : ");
    scanf("%s",s.CNE);
    do
    {
        printf("\n\t Enter the student's Age : ");
        scanf("%d",&s.Age);
    }
    while (s.Age < 0);
    do
    {
        printf("\n\t Enter the student's note in data structure : ");
        scanf("%f",&s.DS);
    }
    while( s.DS < 0 || s.DS > 20 );

    do
    {
        printf("\n\t Enter the student's note in database : ");
        scanf("%f",&s.DB);
    }
    while( s.DB < 0 || s.DB > 20 );

    do
    {
        printf("\n\t Enter the student's note in operating system : ");
        scanf("%f",&s.OS);
    }
    while( s.OS < 0 || s.OS > 20 );

    do
    {
        printf("\n\t Enter the student's note in math : ");
        scanf("%f",&s.Math);
    }
    while( s.Math < 0 || s.Math > 20 );

    s.Moy = (s.DS+s.DB+s.OS+s.Math)/4;

    liste* p = (liste*)malloc(sizeof(liste));
    p->info = s;
    p->suiv = NULL;

    if (position == 1)
    {
        p->suiv = L;
        L = p;
    }
    else
    {

        liste* tmp = L;
        for (int i = 1; i < position - 1 && tmp != NULL; i++)
        {
            tmp = tmp->suiv;
        }
        if (tmp == NULL)
        {
            tmp = L;
            while (tmp->suiv != NULL)
            {
                tmp = tmp->suiv;
            }
            tmp->suiv = p;
        }
        else
        {
            p->suiv = tmp->suiv;
            tmp->suiv = p;
        }
    }
}

void sortingListByName(liste *l ){
    liste *p, *q, *dernier = NULL;
    Etudiant temp;

    int flag = 1;

    while(flag)
    {
        flag = 0;
        p = l ;

        while(p->suiv != dernier)
        {
            q = p->suiv;

            if(strcmp(p->info.Name, q->info.Name) > 0)
            {
                temp = p->info;
                p->info = q->info;
                q->info = temp;

                flag = 1;
            }
            else if(strcmp(p->info.Name, q->info.Name) == 0)
            {
                if(strcmp(p->info.Prenom, q->info.Prenom) > 0)
                {
                    temp = p->info;
                    p->info = q->info;
                    q->info = temp;

                    flag = 1;
                }
            }

            p = p->suiv;
        }

        dernier = p;
    }
}

void sortingListeByMoyenne(liste* l){
    liste *p, *q, *dernier = NULL;
    Etudiant temp;

    int flag = 1;

    while(flag)
    {
        flag = 0;
        p = l;

        while(p->suiv != dernier)
        {
            q = p->suiv;

            if(p->info.Moy < q->info.Moy)
            {
                temp = p->info;
                p->info = q->info;
                q->info = temp;

                flag = 1;
            }

            p = p->suiv;
        }

        dernier = p;
    }
}

void Valid (liste *l){
   liste *tmp = l ;
   while (tmp!=NULL)
   {
    if (tmp->info.Moy>=12)
    {
        printf("\n==========================================================================================================================================================================\n\n\n");
        printf("\n\n\t\t\t\t\t\t\t\t First Name: \t\t %s \n\n\t\t\t\t\t\t\t\t Last Name: \t\t %s \n\n\t\t\t\t\t\t\t\t CNE : \t\t\t %s \n\n\t\t\t\t\t\t\t\t Age : \t\t\t %d\n\n\t\t\t\t\t\t\t\t Data Structure :  \t %.2f \n\n\t\t\t\t\t\t\t\t Data Base : \t\t %.2f \n\n\t\t\t\t\t\t\t\t OS : \t\t\t %.2f \n\n\t\t\t\t\t\t\t\t Math : \t\t %.2f \n\n\t\t\t\t\t\t\t\t Average note: \t\t %.2f \n\n\t\t\t\t\t\t\t\t situation :\t\t V \n\n"
        ,tmp->info.Name,tmp->info.Prenom,tmp->info.CNE,tmp->info.Age,tmp->info.DS,tmp->info.DB,tmp->info.OS,tmp->info.OS,tmp->info.Moy);}
   tmp = tmp ->suiv ;
   }
}

void NValid (liste *l){
   liste *tmp = l ;
   while (tmp!=NULL)
   {
    if (tmp->info.Moy<12)
    {
        printf("\n==========================================================================================================================================================================\n\n\n");
        printf("\n\n\t\t\t\t\t\t\t\t First Name: \t\t %s \n\n\t\t\t\t\t\t\t\t Last Name: \t\t %s \n\n\t\t\t\t\t\t\t\t CNE : \t\t\t %s \n\n\t\t\t\t\t\t\t\t Age : \t\t\t %d\n\n\t\t\t\t\t\t\t\t Data Structure :  \t %.2f \n\n\t\t\t\t\t\t\t\t Data Base : \t\t %.2f \n\n\t\t\t\t\t\t\t\t OS : \t\t\t %.2f \n\n\t\t\t\t\t\t\t\t Math : \t\t %.2f \n\n\t\t\t\t\t\t\t\t Average note: \t\t %.2f \n\n\t\t\t\t\t\t\t\t situation :\t\t NV \n\n"
        ,tmp->info.Name,tmp->info.Prenom,tmp->info.CNE,tmp->info.Age,tmp->info.DS,tmp->info.DB,tmp->info.OS,tmp->info.OS,tmp->info.Moy);}
   tmp = tmp ->suiv ;
   }
}

int main()
{
    liste *L = NULL;
    Etudiant s ;

    Etudiant s1 = {"Abdo", "Ghayt", "B130002249", 18, 15.5, 12.5, 17.25, 14, 0};
    Etudiant s2 = {"Stupid", "Hamoda", "A130004578", 18, 13.5, 1.25, 2.25, 3, 0};
    Etudiant s3 = {"Messi", "Sina", "B130007751", 19, 0, 17.5, 17.25, 16, 0};
    Etudiant s4 = {"Jhon", "Akhto", "B130002247", 20, 1, 5.5, 6.25, 11, 0};
    Etudiant s5 = {"Jotaro", "Zrzban", "B130002248", 13, 12.5, 12.5, 16.25, 14.75, 0};
    Etudiant s6 = {"Abdeslam", "Gounaich", "JH102910", 15, 10, 2, 20, 6, 0};
    Etudiant s7 = {"Abdlouahed", "Id-Boubrik", "M6789043", 18, 1,1, 1, 1, 0};
    Etudiant s8 = {"CR", "Ronaldo", "L130002248", 19, 20,20, 12.5, 15.25, 15};

    int i = 0, pos, choice ;
    char nom1[20], cne1[20], nc[20] ;
    Etudiant rechDS, rechOS, rechDB, rechMath ;
    Etudiant rech ;
    system("color 7");

    L = inserFin(L,s1);
    L = inserFin(L,s2);
    L = inserFin(L,s3);
    L = inserFin(L,s4);
    L = inserFin(L,s5);
    L = inserFin(L,s6);
    L = inserFin(L,s7);
    L = inserFin(L,s8);

    do
    {
        printf("\n============================================================================= Main Menu: =================================================================================\n\n\n");
        printf("\t\t\t\t\t\t\t 1. Add a student\n\n");
        printf("\t\t\t\t\t\t\t 2. Print the list of Students\n\n");
        printf("\t\t\t\t\t\t\t 3. Search for a Student by name or CNE \n\n");
        printf("\t\t\t\t\t\t\t 4. Delete Student by CNE \n\n");
        printf("\t\t\t\t\t\t\t 5. Superior Datastructure , DataBase , OperatingSystem and Math \n\n");
        printf("\t\t\t\t\t\t\t 6. Add a student in position \n\n");
        printf("\t\t\t\t\t\t\t 7. Sorting by ordre alphabitic  \n\n");
        printf("\t\t\t\t\t\t\t 8. Rank of Class  \n\n");
        printf("\t\t\t\t\t\t\t 9. Valider  \n\n");
        printf("\t\t\t\t\t\t\t 10. Non Valider  \n\n");
        printf("\t\t\t\t\t\t\t 11. Quit \n\n\n");
        printf("\n==========================================================================================================================================================================\n\n\n");

        printf("\n\t\t\t\t\t\t\t\t\t Enter your choice (1-11): ");
        scanf("%d", &choice);

        system("pause");
        system("cls");

        switch (choice)
        {
        case 1:

            printf(" \n student n%d : \n",i+1);
            printf("\n\t Enter the student's last name : ");
            scanf("%s",s.Name);
            printf("\n\t tEnter the student's first name : ");
            scanf("%s",s.Prenom);
            printf("\n\t Enter the student's CNE : ");
            scanf("%s",s.CNE);
            do
            {
                printf("\n\t Enter the student's Age : ");
                scanf("%d",&s.Age);
            }
            while (s.Age < 0);
            do
            {
                printf("\n\t Enter the student's note in data structure : ");
                scanf("%f",&s.DS);
            }
            while( s.DS < 0 || s.DS > 20 );

            do
            {
                printf("\n\t Enter the student's note in database : ");
                scanf("%f",&s.DB);
            }
            while( s.DB < 0 || s.DB > 20 );

            do
            {
                printf("\n\t Enter the student's note in operating system : ");
                scanf("%f",&s.OS);
            }
            while( s.OS < 0 || s.OS > 20 );

            do
            {
                printf("\n\t Enter the student's note in math : ");
                scanf("%f",&s.Math);
            }
            while( s.Math < 0 || s.Math > 20 );

            L = inserDebut(L,s);
            i++;
            system("pause");
            system("cls");
            break;
        case 2:
            affichage(L);
            system("pause");
            system("cls");
            break;
        case 3:
            affichage(L);
            printf("\n\t Enter the student's first Name , last Name or CNE : ");
            scanf("%s",nc);
            rech = search ( L, nc );

            printf("\n============================================================================= Search : ====================================================================================\n\n\n");
            if( rech.Moy < 12 )
            {
                printf("\n\n\t\t\t\t\t\t\t\t First Name: \t\t %s \n\n\t\t\t\t\t\t\t\t Last Name: \t\t %s \n\n\t\t\t\t\t\t\t\t CNE : \t\t\t %s \n\n\t\t\t\t\t\t\t\t Age : \t\t\t %d\n\n\t\t\t\t\t\t\t\t Data Structure :  \t %.2f \n\n\t\t\t\t\t\t\t\t Data Base : \t\t %.2f \n\n\t\t\t\t\t\t\t\t OS : \t\t\t %.2f \n\n\t\t\t\t\t\t\t\t Math : \t\t %.2f \n\n\t\t\t\t\t\t\t\t Average note: \t\t %.2f \n\n\t\t\t\t\t\t\t\t situation :\t\t NV \n\n",rech.Name,rech.Prenom,rech.CNE,rech.Age,rech.DS,rech.DB,rech.OS,rech.OS,rech.Moy);
                printf("\n\n==========================================================================================================================================================================\n\n");
            }
            else
            {
                printf("\n\n\t\t\t\t\t\t\t\t First Name: \t\t %s \n\n\t\t\t\t\t\t\t\t Last Name: \t\t %s \n\n\t\t\t\t\t\t\t\t CNE : \t\t\t %s \n\n\t\t\t\t\t\t\t\t Age : \t\t\t %d\n\n\t\t\t\t\t\t\t\t Data Structure :  \t %.2f \n\n\t\t\t\t\t\t\t\t Data Base : \t\t %.2f \n\n\t\t\t\t\t\t\t\t OS : \t\t\t %.2f \n\n\t\t\t\t\t\t\t\t Math : \t\t %.2f \n\n\t\t\t\t\t\t\t\t Average note: \t\t %.2f \n\n\t\t\t\t\t\t\t\t situation :\t\t V \n\n",rech.Name,rech.Prenom,rech.CNE,rech.Age,rech.DS,rech.DB,rech.OS,rech.OS,rech.Moy);
                printf("\n\n===========================================================================================================================================================================\n\n");
            }
            system("pause");
            system("cls");
            break;
        case 4:
            affichage(L);
            printf ("\n\t Donner CNE : ");
            scanf ("%s",cne1);
            L = DeleteStudent( L, cne1 );
            affichage(L);
            system("pause");
            system("cls");
            break;
        case 5:
            affichage(L);
            printf ("\n\t==> L'etudiant qui y a une note Sup de DS : \n");
            rechDS = SearchMaxDS (L) ;
            if (rechDS.Moy<12)
            {
                printf("\n\n==========================================================================================================================================================================\n\n");
                printf("\n\n\t\t\t\t\t\t\t\t First Name: \t\t %s \n\n\t\t\t\t\t\t\t\t Last Name: \t\t %s \n\n\t\t\t\t\t\t\t\t CNE : \t\t\t %s \n\n\t\t\t\t\t\t\t\t Age : \t\t\t %d\n\n\t\t\t\t\t\t\t\t Data Structure :  \t %.2f \n\n\t\t\t\t\t\t\t\t Data Base : \t\t %.2f \n\n\t\t\t\t\t\t\t\t OS : \t\t\t %.2f \n\n\t\t\t\t\t\t\t\t Math : \t\t %.2f \n\n\t\t\t\t\t\t\t\t Average note: \t\t %.2f \n\n\t\t\t\t\t\t\t\t situation :\t\t NV \n\n",rechDS.Name,rechDS.Prenom,rechDS.CNE,rechDS.Age,rechDS.DS,rechDS.DB,rechDS.OS,rechDS.OS,rechDS.Moy);
                printf("\n\n==========================================================================================================================================================================\n\n");
            }
            else
            {
                printf("\n\n==========================================================================================================================================================================\n\n");
                printf("\n\n\t\t\t\t\t\t\t\t First Name: \t\t %s \n\n\t\t\t\t\t\t\t\t Last Name: \t\t %s \n\n\t\t\t\t\t\t\t\t CNE : \t\t\t %s \n\n\t\t\t\t\t\t\t\t Age : \t\t\t %d\n\n\t\t\t\t\t\t\t\t Data Structure :  \t %.2f \n\n\t\t\t\t\t\t\t\t Data Base : \t\t %.2f \n\n\t\t\t\t\t\t\t\t OS : \t\t\t %.2f \n\n\t\t\t\t\t\t\t\t Math : \t\t %.2f \n\n\t\t\t\t\t\t\t\t Average note: \t\t %.2f \n\n\t\t\t\t\t\t\t\t situation :\t\t V \n\n",rechDS.Name,rechDS.Prenom,rechDS.CNE,rechDS.Age,rechDS.DS,rechDS.DB,rechDS.OS,rechDS.Math,rechDS.Moy);
                printf("\n\n==========================================================================================================================================================================\n\n");
            }
            system("pause");
            system("cls");

            affichage(L);
            printf ("\n\t==> L'etudiant qui y a une note Sup de DB : \n");
            rechDB = SearchMaxDB (L) ;
            if (rechDB.Moy<12)
            {
                printf("\n\n==========================================================================================================================================================================\n\n");
                printf("\n\n\t\t\t\t\t\t\t\t First Name: \t\t %s \n\n\t\t\t\t\t\t\t\t Last Name: \t\t %s \n\n\t\t\t\t\t\t\t\t CNE : \t\t\t %s \n\n\t\t\t\t\t\t\t\t Age : \t\t\t %d\n\n\t\t\t\t\t\t\t\t Data Structure :  \t %.2f \n\n\t\t\t\t\t\t\t\t Data Base : \t\t %.2f \n\n\t\t\t\t\t\t\t\t OS : \t\t\t %.2f \n\n\t\t\t\t\t\t\t\t Math : \t\t %.2f \n\n\t\t\t\t\t\t\t\t Average note: \t\t %.2f \n\n\t\t\t\t\t\t\t\t situation :\t\t NV \n\n",rechDB.Name,rechDB.Prenom,rechDB.CNE,rechDB.Age,rechDB.DB,rechDB.DB,rechDB.OS,rechDS.Math,rechDB.Moy);
                printf("\n\n==========================================================================================================================================================================\n\n");
            }
            else
            {
                printf("\n\n==========================================================================================================================================================================\n\n");
                printf("\n\n\t\t\t\t\t\t\t\t First Name: \t\t %s \n\n\t\t\t\t\t\t\t\t Last Name: \t\t %s \n\n\t\t\t\t\t\t\t\t CNE : \t\t\t %s \n\n\t\t\t\t\t\t\t\t Age : \t\t\t %d\n\n\t\t\t\t\t\t\t\t Data Structure :  \t %.2f \n\n\t\t\t\t\t\t\t\t Data Base : \t\t %.2f \n\n\t\t\t\t\t\t\t\t OS : \t\t\t %.2f \n\n\t\t\t\t\t\t\t\t Math : \t\t %.2f \n\n\t\t\t\t\t\t\t\t Average note: \t\t %.2f \n\n\t\t\t\t\t\t\t\t situation :\t\t V \n\n",rechDB.Name,rechDB.Prenom,rechDB.CNE,rechDB.Age,rechDB.DB,rechDB.DB,rechDB.OS,rechDS.Math,rechDB.Moy);
                printf("\n\n==========================================================================================================================================================================\n\n");
            }
            system("pause");
            system("cls");

            affichage(L);
            printf ("\n\t==> L'etudiant qui y a une note Sup de OS : \n");
            rechOS = SearchMaxOS (L) ;
            if (rechOS.Moy<12)
            {
                printf("\n\n==========================================================================================================================================================================\n\n");
                printf("\n\n\t\t\t\t\t\t\t\t First Name: \t\t %s \n\n\t\t\t\t\t\t\t\t Last Name: \t\t %s \n\n\t\t\t\t\t\t\t\t CNE : \t\t\t %s \n\n\t\t\t\t\t\t\t\t Age : \t\t\t %d\n\n\t\t\t\t\t\t\t\t Data Structure :  \t %.2f \n\n\t\t\t\t\t\t\t\t Data Base : \t\t %.2f \n\n\t\t\t\t\t\t\t\t OS : \t\t\t %.2f \n\n\t\t\t\t\t\t\t\t Math : \t\t %.2f \n\n\t\t\t\t\t\t\t\t Average note: \t\t %.2f \n\n\t\t\t\t\t\t\t\t situation :\t\t NV \n\n",rechOS.Name,rechOS.Prenom,rechOS.CNE,rechOS.Age,rechOS.DB,rechOS.DB,rechOS.OS,rechDS.Math,rechOS.Moy);
                printf("\n\n==========================================================================================================================================================================\n\n");
            }
            else
            {
                printf("\n\n==========================================================================================================================================================================\n\n");
                printf("\n\n\t\t\t\t\t\t\t\t First Name: \t\t %s \n\n\t\t\t\t\t\t\t\t Last Name: \t\t %s \n\n\t\t\t\t\t\t\t\t CNE : \t\t\t %s \n\n\t\t\t\t\t\t\t\t Age : \t\t\t %d\n\n\t\t\t\t\t\t\t\t Data Structure :  \t %.2f \n\n\t\t\t\t\t\t\t\t Data Base : \t\t %.2f \n\n\t\t\t\t\t\t\t\t OS : \t\t\t %.2f \n\n\t\t\t\t\t\t\t\t Math : \t\t %.2f \n\n\t\t\t\t\t\t\t\t Average note: \t\t %.2f \n\n\t\t\t\t\t\t\t\t situation :\t\t V \n\n",rechOS.Name,rechOS.Prenom,rechOS.CNE,rechOS.Age,rechOS.DB,rechOS.DB,rechOS.OS,rechDS.Math,rechOS.Moy);
                printf("\n\n==========================================================================================================================================================================\n\n");
            }
            system("pause");
            system("cls");

            affichage(L);
            printf ("\n\t==> L'etudiant qui y a une note Sup de Math : \n");
            rechMath = SearchMaxMath (L) ;
            if (rechMath.Moy<12)
            {
                printf("\n\n==========================================================================================================================================================================\n\n");
                printf("\n\n\t\t\t\t\t\t\t\t First Name: \t\t %s \n\n\t\t\t\t\t\t\t\t Last Name: \t\t %s \n\n\t\t\t\t\t\t\t\t CNE : \t\t\t %s \n\n\t\t\t\t\t\t\t\t Age : \t\t\t %d\n\n\t\t\t\t\t\t\t\t Data Structure :  \t %.2f \n\n\t\t\t\t\t\t\t\t Data Base : \t\t %.2f \n\n\t\t\t\t\t\t\t\t OS : \t\t\t %.2f \n\n\t\t\t\t\t\t\t\t Math : \t\t %.2f \n\n\t\t\t\t\t\t\t\t Average note: \t\t %.2f \n\n\t\t\t\t\t\t\t\t situation :\t\t NV \n\n",rechMath.Name,rechMath.Prenom,rechMath.CNE,rechMath.Age,rechMath.DB,rechMath.DB,rechMath.OS,rechMath.Math,rechMath.Moy);
                printf("\n\n==========================================================================================================================================================================\n\n");
            }
            else
            {
                printf("\n\n==========================================================================================================================================================================\n\n");
                printf("\n\n\t\t\t\t\t\t\t\t First Name: \t\t %s \n\n\t\t\t\t\t\t\t\t Last Name: \t\t %s \n\n\t\t\t\t\t\t\t\t CNE : \t\t\t %s \n\n\t\t\t\t\t\t\t\t Age : \t\t\t %d\n\n\t\t\t\t\t\t\t\t Data Structure :  \t %.2f \n\n\t\t\t\t\t\t\t\t Data Base : \t\t %.2f \n\n\t\t\t\t\t\t\t\t OS : \t\t\t %.2f \n\n\t\t\t\t\t\t\t\t Math : \t\t %.2f \n\n\t\t\t\t\t\t\t\t Average note: \t\t %.2f \n\n\t\t\t\t\t\t\t\t situation :\t\t V \n\n",rechMath.Name,rechMath.Prenom,rechMath.CNE,rechMath.Age,rechMath.DB,rechMath.DB,rechMath.OS,rechMath.Math,rechMath.Moy);
                printf("\n\n==========================================================================================================================================================================\n\n");
            }
            system("pause");
            system("cls");
            break;
        case 6:
            affichage(L);
            printf ("\n\tDonner la position : ");
            scanf ("%d",&pos);
            addByPosition(L,pos);
            system("cls");
            printf ("\n\t\tEtudion est ajouter \3  \3  \3  \3  \3  \n\n");
            affichage(L);

            system("pause");
            system("cls");
            break;
        case 7:
            printf ("\n\t Je suis avant tier : \n");
            affichage(L);
            sortingListByName(L);
            printf ("\n\t Je suis Apres tier : \n");
            affichage(L);

            system("pause");
            system("cls");
            break;
        case 8:
            printf ("\n\t Je suis avant tier : \n");
            affichage(L);
            sortingListeByMoyenne(L);
            printf ("\n\t Je suis Apres tier : \n");
            affichage(L);

            system("pause");
            system("cls");
            break;
        case 9:
            affichage(L);
            Valid (L);
            system("pause");
            system("cls");
            break ;
        case 10 :
            affichage(L);
            NValid(L);
            system("pause");
            system("cls");
            break ;
        case 11 :
            printf("\n=========================================================   Thank you for using this program  \3  \3  \3  ======================================================================\n\n\n");
            system("pause");
            system("cls");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 9.\n");
            system("pause");
            system("cls");
            break;
        }

    }
    while (choice != 11);

    return 0;
}
