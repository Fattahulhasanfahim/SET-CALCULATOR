#include <stdio.h>
#include"stdlib.h"
#include<string.h>
#include<math.h>

void Display1() ;
void Display2();
void PowerSet( FILE *ptr ) ;
void CartesianProduct( FILE *ptr) ;
void IntersectionSet ( FILE *ptr );
void UnionSet( FILE *ptr );
void DifferenceSet ( FILE *ptr ) ;
void DisjointSet(FILE *ptr);
void CheckingSubSet( FILE *ptr );
int CheckRepeat( char *SetMain[50] );
int xstrlen( char *SetX[50] ) ;


int lenA,lenB,lenC ;

struct Set
{
  char *elements[50] ;
  int len ;
} ;

struct Set SetA ={{"white" ,"Green" ,"Blue","Red"},4 };
struct Set SetB = {{"Yellow","pink","Brown","black","tangle","white","Blue" }, 7};
struct Set SetC ;


void Display1()
{
    SetA.len = xstrlen( SetA.elements );
    int memberA ;

    printf("SetA = { ") ;
  for( memberA = 0 ; memberA < SetA.len ; memberA++ )
     {
    if( memberA == SetA.len -1 )
    {
        printf("%s }", SetA.elements[memberA] ) ;
    }
    else
        printf("%s ,",SetA.elements[ memberA ] );
     }
}


void Display2()
{
    int memberA,memberB ;

    SetA.len = xstrlen( SetA.elements );
  SetB.len = xstrlen( SetB.elements ) ;


    printf("SetA = { ") ;
  for( memberA = 0 ; memberA < SetA.len ; memberA++ )
     {
    if( memberA == SetA.len -1 )
    {
        printf("%s }", SetA.elements[memberA] ) ;
    }
    else
        printf("%s ,",SetA.elements[ memberA ] );
     }

 printf("\nSetB = { ") ;
  for( memberB = 0 ; memberB < SetB.len ; memberB++ )
     {
    if( memberB == SetB.len -1 )
    {
        printf("%s }", SetB.elements[memberB] ) ;
    }
    else
        printf("%s ,",SetB.elements[ memberB] );
     }

}

void PowerSet( FILE *ptr )
{
    int NonRepeatNum ;
  NonRepeatNum = CheckRepeat( SetA.elements ) ;

  Display1() ;

  int member , cnt ,SetSize,TotalSubset ;

  SetA.len =xstrlen( SetA.elements );
  TotalSubset = pow( 2,SetA.len ) ;

printf("\n\n\t\tPower Set:\n");
fprintf( ptr,"\n\n\t\tPower Set:\n");

printf("Total Subset : %d \n",TotalSubset );

  for( cnt=0 ; cnt<TotalSubset ; cnt++ )
  {
      int indicate=0;
    if( cnt== 0 )
    {
      printf("{ { ") ;
      fprintf(ptr,"{ { ") ;
    }
    else
    {
         printf("{ ");
        fprintf( ptr,"{ ");
    }

    for( member= 0 ; member<SetA.len ; member++ )
    {
         if( cnt & ( 1<<member ) )
         {
                indicate += 1;
         }

      if( cnt & ( 1<<member ) )
      {
          if(indicate > 1)
        {
            printf(",");
            fprintf(ptr,",");
            indicate = 1;
        }

        printf("%s " , SetA.elements[member] );
        fprintf( ptr,"%s " , SetA.elements[member] );

      }
    }

    if( cnt== TotalSubset-1 )
    {
     printf("}}") ;
     fprintf(ptr,"}}") ;
    }

      else
      {
         printf("},") ;
         fprintf(ptr,"},") ;
      }
  }

}


void CartesianProduct( FILE *ptr)
{
     int NonRepeatNum1 ;
NonRepeatNum1 = CheckRepeat( SetA.elements ) ;

int NonRepeatNum2 ;
NonRepeatNum2 = CheckRepeat( SetB.elements ) ;

        Display2();

  int memberA,memberB ;

     printf("\n\n\t\tCartesian Product of SetA * SetB = \n") ;
     fprintf( ptr ,"\n\n\t\tCartesian Product of SetA * SetB = \n") ;

  for( memberA = 0; memberA < SetA.len ; memberA++ )
  {
    if( memberA == 0 )
      {
          printf("{ ") ;
          fprintf( ptr,"{ " ) ;
      }

    if( memberA == SetA.len-1  )
      {
           for( memberB = 0 ; memberB < SetB.len ;memberB++ )
       {
        if( memberB == SetB.len-1 )
          {
              printf("(%s,%s) ",SetA.elements[ memberA ], SetB.elements[ memberB ] );
              fprintf( ptr,"(%s,%s) ",SetA.elements[ memberA ], SetB.elements[ memberB ] );
          }

        else
         {
             printf("(%s,%s) ,",SetA.elements[ memberA ], SetB.elements[ memberB ] );
             fprintf( ptr ,"(%s,%s) ,",SetA.elements[ memberA ], SetB.elements[ memberB ] );
         }

       }
        printf(" }");
        fprintf( ptr," }");
      }

 else
    {
      for( memberB = 0 ; memberB < SetB.len ;memberB++ )
     {
        printf("(%s,%s) , ",SetA.elements[ memberA ], SetB.elements[ memberB ] );
        fprintf( ptr,"(%s,%s) , ",SetA.elements[ memberA ], SetB.elements[ memberB ] );
     }
    }

  }
}


void IntersectionSet ( FILE *ptr )
{
    int memberA,memberB ,memberC = 0 ;

    int NonRepeatNum1 ;
    NonRepeatNum1 = CheckRepeat( SetA.elements ) ;

  int NonRepeatNum2 ;
  NonRepeatNum2 = CheckRepeat( SetB.elements ) ;


   Display2();


printf("\n\n\t\tIntersection of setA and setB = \n") ;
fprintf( ptr,"\n\n\t\tIntersection of setA and setB = \n") ;


   for( memberA =0 ; memberA <SetA.len ; memberA++ )   //memberB is the index of setB and memberA is the index of setA
    {

      for( memberB= 0; memberB< SetB.len ; memberB++)
      {

         if( strcmp( &SetA.elements[memberA] , &SetB.elements[memberB] ) == 0 )
        {

          strcpy( &SetC.elements[ memberC ] , &SetA.elements[ memberA ] );
         // printf("%s ", SetC.elements[ memberC ] );
          memberC++ ;
          break ;
        }
      }

   }

  printf("{ ");
  fprintf( ptr,"{ ");

   for( int i= 0 ; i < memberC ; i++ )
     {
       if( i== memberC-1 )
         {
        printf("%s }" ,SetC.elements[i]) ;
       fprintf( ptr,"%s }" ,SetC.elements[i]) ;
         }
         else
         {
       printf("%s ," ,SetC.elements[i]) ;
       fprintf( ptr,"%s ," ,SetC.elements[i]) ;
         }
     }

     for( int i=0; i<SetC.len ; i++ )
  {
    SetC.elements[i] =0 ;
  }

}


void UnionSet( FILE *ptr )
{
  int NonRepeatNum1 ;
  NonRepeatNum1 = CheckRepeat( SetA.elements ) ;

  int NonRepeatNum2 ;
  NonRepeatNum2 = CheckRepeat( SetB.elements ) ;

  int memberA,memberB ,memberC = 0 ;

  Display2() ;

  printf( "\n\n\n\t\tUnion Set of setA and SetB =\n") ;
   fprintf( ptr, "\n\n\t\tUnion Set of setA and SetB =\n") ;

  SetC.len = SetA.len + SetB.len ;

 int i;
 for( i=0; i<SetA.len ; i++ )
 {
     strcpy( &SetC.elements[i] , &SetA.elements[ i ]) ;

 }


  for( i=0 ; i<SetC.len ; i++)
  {
    strcpy( &SetC.elements[SetA.len+i] , &SetB.elements[ i ]) ;

  }
  int NonRepeatNum ;

  NonRepeatNum = CheckRepeat( SetC.elements ) ;


   printf("{ " ) ;
   fprintf( ptr,"{ " ) ;
    for( int i= 0 ; i< NonRepeatNum ; i++ )
     {
     if( i== NonRepeatNum-1 )
         {
        printf("%s " ,SetC.elements[i]) ;
       fprintf( ptr,"%s " ,SetC.elements[i]) ;
         }
         else
         {
       printf("%s ," ,SetC.elements[i]) ;
       fprintf( ptr,"%s ," ,SetC.elements[i]) ;
         }

     }
     printf(" }" ) ;
      fprintf( ptr," }" ) ;

     for( i=0; i<SetC.len ; i++ )
  {
    SetC.elements[i] =0 ;
  }

}


void DifferenceSet ( FILE *ptr )
{
     int NonRepeatNum1 ;
NonRepeatNum1 = CheckRepeat( SetA.elements ) ;

int NonRepeatNum2 ;
NonRepeatNum2 = CheckRepeat( SetB.elements ) ;


    Display2();

    printf("\n\n\t\tDiffernce Set -> SetA - SetB :\n");
  fprintf( ptr,"\n\n\t\tDiffernce Set -> SetA - SetB :\n");

  SetA.len = xstrlen( SetA.elements );
  SetB.len = xstrlen( SetB.elements ) ;

  int memberA,memberB ,memberC = 0 ;

   for( memberA =0 ; memberA <SetA.len ; memberA++ )   //memberB is the index of setB and memberA is the index of setA
    {
      int matching = 0 ;

      for( memberB= 0; memberB< SetB.len ; memberB++)
      {

         if( strcmp( &SetA.elements[memberA] , &SetB.elements[memberB] ) == 0 )
        {

           matching++ ;
          break ;
        }

      }

      if( matching == 0 )
      {

      strcpy( &SetC.elements[ memberC ] , &SetA.elements[ memberA ] ) ;

        memberC++ ;
      }


    }


    printf("{ ");
    fprintf( ptr,"{ " );
    for( int i= 0 ; i < memberC ; i++ )
     {
       if( i== memberC-1 )
         {
        printf("%s }" ,SetC.elements[i]) ;
       fprintf( ptr,"%s }" ,SetC.elements[i]) ;
         }
         else
         {
       printf("%s ," ,SetC.elements[i]) ;
       fprintf( ptr,"%s ," ,SetC.elements[i]) ;
         }
     }

     printf("\n\n");
     fprintf( ptr,"\n\n");
}


void DisjointSet(FILE *ptr)
{
     int NonRepeatNum1 ;
NonRepeatNum1 = CheckRepeat( SetA.elements ) ;

int NonRepeatNum2 ;
NonRepeatNum2 = CheckRepeat( SetB.elements ) ;

    Display2() ;

   printf("\n\n\t\tDisjoint Set of SetA and SetB :\n");
fprintf( ptr,"\n\n\t\tDisjoint Set of SetA and SetB :\n");


  SetA.len = xstrlen( SetA.elements );
  SetB.len = xstrlen( SetB.elements ) ;

  int memberA ,memberB,matching =0 ;



  for( memberB =0 ; memberB <SetB.len ; memberB++ )   //memberB is the index of setB and memberA is the index of setA
    {
      for( memberA= 0; memberA< SetA.len ; memberA++)
      {
        if( strcmp( &SetB.elements[memberB ] , &SetA.elements[ memberA]) == 0)
        {
          matching++ ;
        }
      }

      if( matching > 0  )
      {
        printf("set B and set A are not disjoint\n") ;
        fprintf(ptr,"set B and set A are not disjoint\n");
        break ;
      }
    }

    if ( matching == 0 )
    {
      printf("set B and set A are disjoint set\n ") ;
       fprintf(ptr,"set B and set A are disjoint set\n ");
    }

     printf("\n\n");
     fprintf( ptr,"\n\n");
}


void CheckingSubSet( FILE *ptr )
{
    int NonRepeatNum1 ;
NonRepeatNum1 = CheckRepeat( SetA.elements ) ;

int NonRepeatNum2 ;
NonRepeatNum2 = CheckRepeat( SetB.elements ) ;

    Display2() ;

    printf("\n\n\t\tChecking Subset of SetA and SetB :\n");
fprintf( ptr,"\n\n\t\tChecking Subset of SetA and SetB :\n") ;


  int memberA ,memberB,matching =0 ;


  for( memberB =0 ; memberB <SetB.len ; memberB++ )   //memberB is the index of setB and memberA is the index of setA
    {
      for( memberA= 0; memberA< SetA.len ; memberA++)
      {
        if( strcmp( &SetB.elements[memberB ] , &SetA.elements[ memberA]) == 0)
        {
          matching++ ;
        }
      }

      if( matching == 0 )
      {
        printf("set B is not subset of setA \n") ;
        fprintf( ptr,"set B is not subset of setA \n") ;
        break ;
      }
    }

  if( matching >0 )

  {
  if ( matching == lenB )
    {
      printf("set B is subset of set A ") ;
      fprintf( ptr,"set B is subset of set A ") ;
    }
   else
   {
     printf("set B is not subset of set A") ;
     fprintf( ptr,"set B is not subset of set A") ;
   }
  }
     printf("\n\n");
     fprintf( ptr,"\n\n");
}


int CheckRepeat( char *SetMain[50] )
{
  int length = xstrlen( SetMain ) ;
  char *Set2[ length+1 ] ;
  int MainInd ,Set2Ind ,Set2Size =0 ;

  for( MainInd = 0; MainInd < length ; MainInd++ )
  {
    for( Set2Ind =0 ; Set2Ind<Set2Size ; Set2Ind++ )
    {
      if( strcmp( &SetMain[MainInd][0], &Set2[Set2Ind][0] ) == 0)
         {
           break ;
         }
    }


    if( Set2Ind == Set2Size )
    {
      strcpy( &Set2[Set2Size] ,&SetMain[MainInd] ) ;
      Set2Size++ ;
      SetMain[ MainInd ] = "0" ;
    }

  }

  for( Set2Ind = 0 ; Set2Ind<Set2Size ;Set2Ind++ )
  {
   strcpy( &SetMain[Set2Ind] , &Set2[Set2Ind] ) ;
  }

  return Set2Ind ;
}

int xstrlen( char *SetX[50] )
{
  int index=0 ;
   while( SetX[ index ] != '\0' )
   {
     index++ ;
   }
  return index ;
}

int  main( )
{
    FILE *fp;
    char filename[] ="Set Calculator.txt" ;
    fp = fopen( filename,"w+" );

  int choice ;


  char *ChoiceHistory[50];
  int NumOfChoice =0 ;

  printf("\t\t THIS IS SET CALCULATOR \n") ;

  while( 1 )
  {
    printf("\n\nplease choose your option .\npress your choice key.(0 for exit)\n") ;
    printf("1 : Union set\n2 : Intersection set\n3 : Difference Set\
           \n4 : Cartesian product \n5 : Disjoint Set\n6 : Power Set \n7 : Cheking Subset \
           \n0 : exit\n\n\t\tChoice : ") ;
    scanf("%d", &choice ) ;
 printf("\n") ;

    if( choice == 1 )
    {
        printf("Your choice is Union Set\n");
        ChoiceHistory[NumOfChoice] ="choice : Union Set ";
        NumOfChoice++ ;
        UnionSet( fp ) ;
    }

    else if( choice == 2 )
    {
         printf("Your choice is Intersection Set\n");
         ChoiceHistory[NumOfChoice] ="choice : Intersection Set ";
        NumOfChoice++ ;
         IntersectionSet(fp );
    }

    else if( choice == 3 )
    {
        printf("Your choice is Difference Set\n");
        ChoiceHistory[NumOfChoice] ="choice : Difference Set ";
        NumOfChoice++ ;
       DifferenceSet( fp ) ;
    }

    else if( choice == 4 )
     {
         printf("Your choice is Cartesian Product\n");
         ChoiceHistory[NumOfChoice] ="choice : Cartesian Product ";
        NumOfChoice++ ;
       CartesianProduct( fp ) ;

     }

    else if( choice == 5 )
    {
         printf("Your choice is DisjointSet\n");
         ChoiceHistory[NumOfChoice] ="choice : Difference Set ";
        NumOfChoice++ ;
         DisjointSet(fp ) ;
    }

    else if ( choice == 6 )
    {
        printf("Your choice is Power Set\n");
        ChoiceHistory[NumOfChoice] ="choice : Power Set ";
        NumOfChoice++ ;
         PowerSet(fp) ;
    }

   else if( choice == 7 )
   {
       printf("Your choice is Checking SubSet\n");
       ChoiceHistory[NumOfChoice] ="choice : Subset ";
        NumOfChoice++ ;
       CheckingSubSet( fp );

   }

    else if( choice == 0 )
    {
        ChoiceHistory[NumOfChoice] ="choice : Exit ";
        NumOfChoice++ ;

        printf("\n\t\t\tYour Choice history \n");
        for( int i=0 ; i<NumOfChoice ; i++)
        {
            printf("\t%d ->%s \n",i+1,ChoiceHistory[i] );
            fprintf( fp , "\t%d ->%s \n",i+1,ChoiceHistory[i] );
        }
      break ;
    }

     else
     {
         ChoiceHistory[NumOfChoice] ="wrong choice !! ";
        NumOfChoice++ ;
         printf("wrong choice !!") ;
     }
  }

  fclose(fp);

  return 0 ;

}
