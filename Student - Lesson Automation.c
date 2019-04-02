// Structure

// Yunus Emre Alpu 17010011005

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define N_Size 20 // Name Size
#define S_Size 20 // Surname Size
#define Le_Size 20 // Lesson Name Size

/*
   1  - Chris Abroad   19

   15 - Math          3
   16 - Algorithm     6
   17 - Electronic    3

*/

struct Lesson
{

    int Lesson_id ; // Lesson id -> 1,2,3,...
    int Credit ;    // Lesson credit -> 3,4,5...

    char Lesson_Name[Le_Size] ; // Lesson Name -> Math

};

struct Student
{

    int Student_id ; // Student id -> 1,2,3,...
    int Age ;

    char Name[N_Size] ; // Student Name -> Chris
    char Surname[S_Size] ; // Student Surname -> Abroad

    struct Lesson *P_2 ; // Started address of Lesson structure

};

int main()
{
    struct Student *P_1 ; // Started address of Student structure

    int Student_Size ; // Total student number

    // -------------------- Add information Part

    printf(" Please enter Total student number : ") ;
    scanf("%d",&Student_Size) ;

    system("CLS") ; // clear page

    P_1 = malloc(Student_Size*sizeof(struct Student)) ; // Dynamic memory allocation

    // --------------------

    int Lesson_Size ; // Total lesson number

    int i, j, m ;    // Loop variable

    int Counter = 0 ;

    int L_Size[Student_Size] ;

    // --------------------

    for( i=0 ; i<Student_Size ; i++ )
    {
        printf(" Please enter %d. Student id : ",i+1)  ;
        scanf("%d",&((P_1+i)->Student_id)) ;

        printf("\n") ;

        printf(" Please enter %d. Student Name : ",i+1) ;
        scanf("%s",&(P_1+i)->Name) ;

        printf(" Please enter %d. Student Surname : ",i+1) ;
        scanf("%s",&(P_1+i)->Surname) ;

        printf("\n") ;

        printf(" Please enter %d. Student Age : ",i+1) ;
        scanf("%d",&((P_1+i)->Age)) ;

        system("CLS") ; // Clear

        printf(" Please enter %d. Student Total Lesson number : ",i+1) ;
        scanf("%d",&Lesson_Size) ;

        (P_1+i)->P_2 = malloc(Lesson_Size*sizeof(struct Lesson)) ;

        L_Size[i] = Lesson_Size ;

        for( j=0 ; j<Lesson_Size ; j++)
        {
            system("CLS") ;

            printf(" Please enter %d. Student %d. Lesson id : ",i+1,j+1) ;
            scanf("%d",&((P_1+i)->P_2+j)-> Lesson_id) ;

            printf(" Please enter %d. Student %d. Lesson name : ",i+1,j+1) ;
            scanf("%s",&((P_1+i)->P_2+j)->Lesson_Name) ;

            printf(" Please enter %d. Student %d. Lesson credit : ",i+1,j+1) ;
            scanf("%d",&((P_1+i)->P_2+j)->Credit) ;

            system("CLS") ;
        }

        system("CLS") ;
    }

    // --------------------

    for(i=0 ; i<Student_Size ; i++) // Print all information
    {
        printf("\n ---------- \n\n") ;

        if( i== 0 )
        {
            printf("  Student id - Name - Surname - Age \n") ;
        }

        printf("\t %d \t %s \t %s \t %d \n",(P_1+i)->Student_id,(P_1+i)->Name,(P_1+i)->Surname,(P_1+i)->Age) ;

        printf("\n ---------- \n\n") ;

        for(j=0 ; j<L_Size[i] ; j++)
        {
            if( j== 0 )
            {
                printf("  Lesson id - Lesson Name - Lesson Credit \n") ;
            }

            printf("\t %d \t %s \t   %d \n",((P_1+i)->P_2+j)->Lesson_id,((P_1+i)->P_2+j)->Lesson_Name,((P_1+i)->P_2+j)->Credit) ;
        }

        printf("\n ---------- \n\n") ;
    }

    // --------------------

    int Search ;

    while(1)
    {

        printf(" Search of Lesson id Please press 1 \n") ;
        printf(" Search of Name and Surname Please press 2 \n") ;
        printf(" Exit -> Please press 3 \n\n") ;

        printf(" Please enter process number : ") ;

        while(1) // Control
        {
            scanf("%d",&Search) ;

            if((Search == 1)||(Search == 2)||(Search == 3))
            {
                break ;
            }
        }

        // --------------------

        printf("\n ---------- \n\n") ;


        if( Search == 1 )
        {
            system("CLS") ;
            int Se_Lesson_id ; // Lesson id

            printf(" Please enter Lesson id for Search : ") ;
            scanf("%d",&Se_Lesson_id) ;

            for( i=0 ; i<Student_Size ; i++ )
            {
                for( j=0 ; j<L_Size[i] ; j++)
                {
                    if((((P_1+i)->P_2+j)->Lesson_id) == Se_Lesson_id)
                    {
                        printf("\t %d \t %s \t %s \t %d \n",(P_1+i)->Student_id,(P_1+i)->Name,(P_1+i)->Surname,(P_1+i)->Age) ;
                    }

                }
            }

            printf("\n") ;
        }


        else if ( Search == 2 )
        {
            system("CLS") ;

            int Se_Choose ;

            printf(" Search of Name Please press 1 \n") ;
            printf(" Search of Surname Please press 2 \n") ;
            printf(" Search of Surname and Name Please press 3 \n\n") ;

            printf(" Please enter process number : ") ;

            while(1) // Control
            {
                scanf("%d",&Se_Choose) ;

                if((Se_Choose == 1)||(Se_Choose == 2)||(Se_Choose == 3))
                {
                    break ;
                }
            }

            system("CLS") ;
            // --------------------

            char Se_Name[N_Size] ;    // Name
            char Se_Surname[S_Size] ; // Surname

            int t,k ; // Loop variable

            int flag_Name ;  // Control

            int Name_Size = 0, Surname_Size = 0  ;  // Size



            if(Se_Choose == 1)
            {
                printf(" Please enter Student Name for Search : ") ;
                scanf("%s",&Se_Name) ;

                printf("\n ---------- \n\n") ;

                for( i=0 ; i<Student_Size ; i++)
                {
                    for( t=0 ; t<Se_Name[t] ; t++)
                    {
                        if(Se_Name[t] == (P_1+i)->Name[t])
                        {
                            Name_Size++ ;
                        }

                        if(Name_Size == strlen((P_1+i)->Name))
                        {
                            printf("\t %d \t %s \t %s \t %d \n",(P_1+i)->Student_id,(P_1+i)->Name,(P_1+i)->Surname,(P_1+i)->Age) ;

                            printf("\n ---------- \n\n") ;

                            for(j=0 ; j<L_Size[i] ; j++)
                            {
                                if( j== 0 )
                                {
                                    printf("  Lesson id - Lesson Name - Lesson Credit \n") ;
                                }

                                printf("\t %d \t %s \t   %d \n",((P_1+i)->P_2+j)->Lesson_id,((P_1+i)->P_2+j)->Lesson_Name,((P_1+i)->P_2+j)->Credit) ;
                            }

                            printf("\n ---------- \n\n") ;

                        }
                    }

                    Name_Size = 0 ;

                }

            }

            else if (Se_Choose == 2)
            {
                printf(" Please enter Student Surname for Search : ") ;
                scanf("%s",&Se_Surname) ;

                printf("\n ---------- \n\n") ;


                for( i=0 ; i<Student_Size ; i++)
                {

                    for( k=0 ; k<Se_Surname[k]; k++)
                    {
                        if(Se_Surname[k] == (P_1+i)->Surname[k])
                        {
                            Surname_Size++ ;
                        }

                        if(Surname_Size == strlen((P_1+i)->Surname))
                        {
                            printf("\t %d \t %s \t %s \t %d \n",(P_1+i)->Student_id,(P_1+i)->Name,(P_1+i)->Surname,(P_1+i)->Age) ;

                            printf("\n ---------- \n\n") ;

                            for(j=0 ; j<L_Size[i] ; j++)
                            {
                                if( j== 0 )
                                {
                                    printf("  Lesson id - Lesson Name - Lesson Credit \n") ;
                                }

                                printf("\t %d \t %s \t   %d \n",((P_1+i)->P_2+j)->Lesson_id,((P_1+i)->P_2+j)->Lesson_Name,((P_1+i)->P_2+j)->Credit) ;
                            }

                            printf("\n ---------- \n\n") ;

                        }
                    }



                    Surname_Size = 0 ;
                    flag_Name = 0 ;

                }

            }


            else if(Se_Choose == 3)
            {
                printf(" Please enter Student Name for Search : ") ;
                scanf("%s",&Se_Name) ;

                printf(" Please enter Student Surname for Search : ") ;
                scanf("%s",&Se_Surname) ;

                printf("\n ---------- \n\n") ;

                for( i=0 ; i<Student_Size ; i++)
                {
                    for( t=0 ; t<Se_Name[t] ; t++)
                    {
                        if(Se_Name[t] == (P_1+i)->Name[t])
                        {
                            Name_Size++ ;
                        }

                        if(Name_Size == strlen((P_1+i)->Name))
                        {
                            flag_Name = 1 ;

                        }
                    }

                    Name_Size = 0 ;

                    if(flag_Name == 1)
                    {
                        for( k=0 ; k<Se_Surname[k]; k++)
                        {
                            if(Se_Surname[k] == (P_1+i)->Surname[k])
                            {
                                Surname_Size++ ;
                            }

                            if(Surname_Size == strlen((P_1+i)->Surname))
                            {
                                printf("\t %d \t %s \t %s \t %d \n",(P_1+i)->Student_id,(P_1+i)->Name,(P_1+i)->Surname,(P_1+i)->Age) ;

                                printf("\n ---------- \n\n") ;

                                for(j=0 ; j<L_Size[i] ; j++)
                                {
                                    if( j== 0 )
                                    {
                                        printf("  Lesson id - Lesson Name - Lesson Credit \n") ;
                                    }

                                    printf("\t %d \t %s \t   %d \n",((P_1+i)->P_2+j)->Lesson_id,((P_1+i)->P_2+j)->Lesson_Name,((P_1+i)->P_2+j)->Credit) ;
                                }

                                printf("\n ---------- \n\n") ;

                            }
                        }

                    }

                    Surname_Size = 0 ;
                    flag_Name = 0 ;

                }

            }

        }

        if(Search == 3)
        {
            break ;
        }
    }


    getch() ;
    return 0 ;
}

