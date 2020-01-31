// Structure

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define n_len 20 // name length
#define s_len 20 // surname length
#define l_len 20 // lesson name length

// ----------
// structures
struct lesson
{
    int l_id; // lesson id -> 1,2,3,...
    int cred; // lesson credit -> 3,4,5...
    char l_name[l_len]; // lesson name -> Math
};
struct student
{
    int std_id; // student id -> 1,2,3,...
    char s_name[n_len]; // student name -> Chris
    char s_surnm[s_len]; // student surname -> Abroad
    int age;
    int tot_les; // total lesson
    struct lesson *point;
};

// ----------
// global variables
 int i, j, m, t, k; // loop variable

// ----------
// main function
int main()
{
    struct student *point1; // started address of student structure
    int s_size; // total student number

    printf(" ---------------\n");
    printf(" - Total student number : ");
    scanf("%d",&s_size);
    system("CLS");

    point1=malloc(s_size*sizeof(struct student)); // dynamic memory allocation

    for(i=0; i<s_size; i++)
    {
        printf(" - Enter [%d. student] id : ",i+1);
        scanf("%d",&((point1+i)->std_id));printf("\n");
        getchar();
        printf(" - Enter [%d. student] name : ",i+1);
        gets((point1+i)->s_name);
        printf(" - Enter [%d. student] surname : ",i+1);
        gets((point1+i)->s_surnm);
        printf("\n");
        printf(" - Enter [%d. student] age : ",i+1);
        scanf("%d",&((point1+i)->age));
        system("CLS");

        printf(" - Enter [%d. student] total lesson number : ",i+1);
        scanf("%d",&(point1+i)->tot_les);
        (point1+i)->point = malloc(((point1+i)->tot_les)*sizeof(struct lesson));

        for( j=0 ; j<(point1+i)->tot_les ; j++)
        {
            system("CLS");
            printf(" - Enter [%d. student][%d. lesson] id : ",i+1,j+1);
            scanf("%d",&((point1+i)->point+j)-> l_id);
            getchar() ;
            printf(" - Enter [%d. student][%d. lesson] name : ",i+1,j+1);
            gets(((point1+i)->point+j)->l_name);
            printf(" - Enter [%d. student][%d. lesson] credit : ",i+1,j+1);
            scanf("%d",&((point1+i)->point+j)->cred);
            system("CLS");
        }
        system("CLS") ;
    }

    for(i=0; i<s_size; i++) // print all information
    {
        printf(" ---------------\n");
        if(i== 0)
        {
            printf(" - Student id - Name - Surname - Age \n");
        }
        printf("\t %d \t %s \t %s \t %d \n",(point1+i)->std_id,(point1+i)->s_name,(point1+i)->s_surnm,(point1+i)->age);

        printf(" ---------------\n");
        for(j=0; j<(point1+i)->tot_les; j++)
        {
            if(j== 0)
            {
                printf(" - Lesson id - Lesson name - Lesson credit \n");
            }
            printf("\t %d \t %s \t   %d \n",((point1+i)->point+j)->l_id,((point1+i)->point+j)->l_name,((point1+i)->point+j)->cred);
        }
         printf(" ---------------\n");
    }

    int srch;

    while(1)
    {
        printf(" ---------------\n");
        printf(" - 1.) Search of lesson id \n");
        printf(" - 2.) Search of name and surname \n");
        printf(" - 3.) Exit \n");
        printf(" ---------------\n");

        printf(" - Enter process number : ");
        while(1)
        {
            scanf("%d",&srch);
            if((srch == 1)||(srch == 2)||(srch == 3))
                break;
        }
        printf(" ---------------\n");

        if(srch == 1)
        {
            system("CLS");
            int srch_lid; // lesson id

            printf(" - Enter lesson id : ");
            scanf("%d",&srch_lid);

            for(i=0; i<s_size; i++)
            {
                for(j=0; j<(point1+i)->tot_les; j++)
                {
                    if((((point1+i)->point+j)->l_id) == srch_lid)
                    {
                        printf("\t %d \t %s \t %s \t %d \n",(point1+i)->std_id,(point1+i)->s_name,(point1+i)->s_surnm,(point1+i)->age);
                    }
                }
            }
            printf("\n");
        }
        else if (srch == 2)
        {
            system("CLS");
            int srch_num;

            printf(" ---------------\n");
            printf(" - 1.) Search of name \n");
            printf(" - 2.) Search of surname \n");
            printf(" - 3.) Search of surname and name \n\n");
            printf(" ---------------\n");

            printf(" - Enter process number : ");
            while(1)
            {
                scanf("%d",&srch_num);

                if((srch_num == 1)||(srch_num == 2)||(srch_num == 3))
                    break;
            }
            system("CLS");

            char srch_name[n_len]; // name
            char srch_surname[s_len] ; // surname

            int flag_name;
            int nm_size = 0, srnm_size=0;

            if(srch_num == 1)
            {
                getchar();
                printf(" - Enter student name: ");
                gets(srch_name);

                printf(" ---------------\n");
                for(i=0; i<s_size; i++)
                {
                    for( t=0 ; t<srch_name[t] ; t++)
                    {
                        if(srch_name[t] == (point1+i)->s_name[t])
                            nm_size++;

                        if(nm_size == strlen((point1+i)->s_name))
                        {
                            printf("\t %d \t %s \t %s \t %d \n",(point1+i)->std_id,(point1+i)->s_name,(point1+i)->s_surnm,(point1+i)->age);
                           printf(" ---------------\n");
                            for(j=0; j<(point1+i)->tot_les; j++)
                            {
                                if(j== 0)
                                {
                                    printf(" - Lesson id - Lesson name - Lesson credit \n");
                                }
                                printf("\t %d \t %s \t   %d \n",((point1+i)->point+j)->l_id,((point1+i)->point+j)->l_name,((point1+i)->point+j)->cred);
                            }
                            printf(" ---------------\n");
                        }
                    }
                    nm_size = 0;
                }

            }

            else if (srch_num == 2)
            {
                getchar();
                printf(" - Enter student surname : ");
                gets(srch_surname);

                printf(" ---------------\n");
                for(i=0; i<s_size; i++)
                {
                    for(k=0; k<srch_surname[k]; k++)
                    {
                        if(srch_surname[k] == (point1+i)->s_surnm[k])
                            srnm_size++;

                        if(srnm_size == strlen((point1+i)->s_surnm))
                        {
                            printf("\t %d \t %s \t %s \t %d \n",(point1+i)->std_id,(point1+i)->s_name,(point1+i)->s_surnm,(point1+i)->age);
                            printf(" ---------------\n");

                            for(j=0; j<(point1+i)->tot_les; j++)
                            {
                                if(j==0)
                                {
                                    printf("  Lesson id - Lesson name - Lesson credit \n");
                                }

                                printf("\t %d \t %s \t   %d \n",((point1+i)->point+j)->l_id,((point1+i)->point+j)->l_name,((point1+i)->point+j)->cred);
                            }
                            printf(" ---------------\n");
                        }
                    }
                    srnm_size = 0;
                    flag_name = 0;
                }
            }

            else if(srch_num == 3)
            {
                getchar();
                printf(" - Enter student name : ");
                gets(srch_name);
                printf(" - Enter student surname : ");
                gets(srch_surname);
                printf(" ---------------\n");

                for(i=0; i<s_size; i++)
                {
                    for(t=0; t<srch_name[t]; t++)
                    {
                        if(srch_name[t] == (point1+i)->s_name[t])
                            nm_size++;


                        if(nm_size == strlen((point1+i)->s_name))
                            flag_name=1;

                    }
                    nm_size=0;

                    if(flag_name == 1)
                    {
                        for(k=0; k<srch_surname[k]; k++)
                        {
                            if(srch_surname[k] == (point1+i)->s_surnm[k])
                                srnm_size++ ;

                            if(srnm_size == strlen((point1+i)->s_surnm))
                            {
                                printf("\t %d \t %s \t %s \t %d \n",(point1+i)->std_id,(point1+i)->s_name,(point1+i)->s_surnm,(point1+i)->age);
                                printf(" ---------------\n");

                                for(j=0; j<(point1+i)->tot_les; j++)
                                {
                                    if(j== 0)
                                    {
                                        printf("  Lesson id - Lesson name - Lesson credit \n");
                                    }
                                    printf("\t %d \t %s \t   %d \n",((point1+i)->point+j)->l_id,((point1+i)->point+j)->l_name,((point1+i)->point+j)->cred);
                                }
                                printf(" ---------------\n");
                            }
                        }
                    }
                    srnm_size = 0;
                    flag_name = 0;
                }
            }
        }

        if(srch == 3)
        {
            break;
        }
    }

    getch();
    return 0;
}
