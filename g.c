#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char arrg[9]={'1','2','3','4','5','6','7','8','9'},name1[30],name2[30],choice;
int ue;
void printfun(char[],char[]);
int main()
{  printfun(name1,name2);     //calling function
//for condition used for taking user input, as remainder of any integer divided by 2 is only 0 and 1 we used it.
     for(int i=2;i<11;i++)
      {
//taking input 
        if(i%2==0)
          { 
             printf("\n\033[1;31m %s\033[0m's turn('X') : ",name1 );
             scanf("%d",&ue);
//to eliminate any unwanted string
             while(getchar()!='\n');
//this if and else to get only right range integer input
             if(ue<=9 && ue>=1)
             {  
//used so that user can enter that place which was not filled already
                if(arrg[ue-1]!='X' && arrg[ue-1]!='O')
                   arrg[ue-1]='X'; 
                else if(arrg[ue-1]=='X' || arrg[ue-1]=='O')
//--i as loop increases i by 1 and we again want this loop to run
// continue is used as we want loop to stop going and move to next step
        
                   {printf("\n\033[1;31mERROR ! again enter the integer \n\033[0m");--i; continue;}
             }
             else{ printf("\n\033[1;31menter valid no to play \n\033[0m"); --i; continue; } 
          } 
        else if(i%2==1)
          { 
             printf("\n\033[1;32m %s\033[0m's turn('O') : ",name2);
             scanf("%d",&ue);
//to eliminate any unwanted string 
             while(getchar()!='\n');     
//this if and else to get only right range integer input
             if(ue<=9 && ue>=1)
             { 
//used so that user can enter that place which was not filled already
               if(arrg[ue-1]!='X' && arrg[ue-1]!='O')
                  arrg[ue-1]='O'; 
               else if(arrg[ue-1]=='X' || arrg[ue-1]=='O') 
//--i as loop increases i by 1 and we again want this loop to run
// continue is used as we want loop to stop going and move to next step
                  {printf("\n\033[1;31mERROR ! again enter the integer \n\033[0m");--i; continue;}
             }
             else{ printf("\n\033[1;31menter valid no to play \n\033[0m"); --i; continue; }
           }
//this is to again display the outcome at same place , as system("clear") had cleaned screen
        system("clear"); 
        printf("\nplayer who wants to play with 'X' enter your name : %s\n",name1);
        printf("\nplayer who wants to play with 'O' enter your name : %s\n",name2);
        printf("\n\033[1;33mRule \033[0m\033[0;34m: please enter any integer between 1-9 where you want to place your mark(X/O)\033[0m\n ");
//printing updated game box(abdul's idea)
        printf("\n\n");
        for(int i=0;i<=6;i=i+3)
        {   	printf("\t\t\t\t\t\t");
        		for(int j=0;j<3;j++)
        		{
        			if(arrg[i+j]=='X')
        				printf("\033[1;31m  %c  \033[0m",arrg[i+j]);
        			else if(arrg[i+j]=='O')
        				printf("\033[1;32m  %c  \033[0m",arrg[i+j]);
        			else
        				printf("  %c  ",arrg[i+j]);
        			if(j!=2)
        				printf("|");
        			else
        				printf("\n");
        		}
        		if(i!=6)
        			printf("\t\t\t\t\t\t-----------------\n");
        			
        	}           
//checking condition of winning match 
        if(arrg[0]==arrg[1] && arrg[0]==arrg[2] || arrg[0]==arrg[4] && arrg[0]==arrg[8] || arrg[2]==arrg[4] && arrg[2]==arrg[6] ||arrg[3]==arrg[4] && arrg[3]==arrg[5] || arrg[6]==arrg[7] && arrg[6]==arrg[8] || arrg[0]==arrg[3] && arrg[0]==arrg[6] || arrg[1]==arrg[4] && arrg[1]==arrg[7] || arrg[2]==arrg[5] && arrg[2]==arrg[8] )
         {
          if(i%2==0)
             printf("\n\033[1;36m %s ('X') won the match ! \033[0m",name1); 
          else if(i%2==1)
             printf("\n\033[1;36m %s ('O') won the match ! \033[0m",name2);  
//getting user choice if he again wanted to play or not(for winning condition)
          printf("\n\ndo want to play another chance(y/n) ? : ");
          scanf(" %c",&choice);
          if(choice=='y' || choice=='Y')
            { 
               i=1;   //as i++ will increase it to 2
               for(int t=0;t<9;t++)
                 { arrg[t]=t+49; }  //again creating the gaming board with ascii value(49 is ascii value of 1)
               printfun(name1,name2);
             } 
          else if(choice=='n' || choice=='N')
            {break;}
          }
//draw condition
          else if((arrg[0]=='X' || arrg[0]=='O') && (arrg[1]=='X' || arrg[1]=='O') && (arrg[2]=='X' || arrg[2]=='O') && (arrg[3]=='X' || arrg[3]=='O') && (arrg[4]=='X' || arrg[4]=='O') && (arrg[5]=='X' || arrg[5]=='O') && (arrg[6]=='X' || arrg[6]=='O') && (arrg[7]=='X' || arrg[7]=='O') && (arrg[8]=='X' || arrg[8]=='O'))
          {
           printf("\n\033[1;35m match draw !!\033[0m");
//getting user choice if he again wanted to play or not(by draw condition)
           printf("\n\ndo want to play another chance(y/n) ? : ");
           scanf(" %c",&choice);
           if(choice=='y' || choice=='Y')
              { i=1;
                
                for(int t=0;t<9;t++)
                 { arrg[t]=t+49; }  //again creating the gaming board with ascii value(49 is ascii value of 1)
                printfun(name1,name2);
              }
           else if(choice=='n' || choice=='N')
           {break;} 
          }  
     }
   return 0;
}
//function for printing and getting user name
void printfun(char n1[],char n2[]){
      system("clear");
      printf("\nplayer who wants to play with 'X' enter your name : ");
      scanf("%s",n1);
      printf("\nplayer who wants to play with 'O' enter your name : ");
      scanf("%s",n2);
      printf("\n\033[1;33mRule \033[0m\033[0;34m: please enter any integer between 1-9 where you want to place your mark(X/O)\033[0m\n ");
      printf("\n\n\t\t\t\t\t\t  1  |  2  |  3  \n\t\t\t\t\t\t-----------------\n\t\t\t\t\t\t  4  |  5  |  6  \n\t\t\t\t\t\t-----------------\n\t\t\t\t\t\t  7  |  8  |  9  ");  
      return;        
}  
