#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<string.h>
#define ESC 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4


//create matrix 4x4

void createMatrix(int arr[4][4])
{
    int num[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int lastIndex=14,index;
    int i,j;

    srand(time(NULL));    // for ramdom number generation

    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            
            if(lastIndex>=0)
            {
                index=rand()%(lastIndex+1);  // random number generate from 1 to 15
                arr[i][j]=num[index];        
                num[index]=num[lastIndex];   // to avoid repetation
                lastIndex--;
            }
            else
            {
                arr[i][j]=0;
            }
        }
    }
}

// showing matrix
void showMatrix(int arr[][4])
{
    int i,j;
    printf("----------------------\n");
    for(i=0;i<=3;i++)
   { printf("| ");
       for(j=0;j<=3;j++)
    {   if(arr[i][j]!=0)
        printf(" %-2d |",arr[i][j]);
        else
        printf("    |");
    }
    printf("\n");
   }

    printf("----------------------\n");
}


// read the user input......

int readKey()
{
    int ch;
    ch=getch(); 
    switch (ch)
    {
    case 101:
        return('e');
    case 69:
        return('E');
    case 72:
        return(UP);
    case 80:
        return(DOWN);
    case 75:
        return(LEFT);
    case 77:
        return(RIGHT);
    default:
        return(5);
    }
}


//winning checking by this function
int winner(int arr[][4])
{
    int i,j,k=0;

    for(i=0;i<=3;i++)
    {
        for(j=0;j<=3;j++)
        {
            k<15?k++:(k=0);
            if(arr[i][j]!=k)
            return 0;
        }
    }
    return 1;
}


// keys.....

int shiftRight(int A[][4]){
    int i,j,temp,zeroFound=0;

    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(j==0)
        return(0);//shifting not possible
    else{
        temp=A[i][j];
        A[i][j]=A[i][j-1];
        A[i][j-1]=temp;
        return(1);
    }

}
int shiftLeft(int A[][4]){
  int i,j,temp,zeroFound=0;

    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(j==3)
        return(0);//shifting not possible
    else{
        temp=A[i][j];
        A[i][j]=A[i][j+1];
        A[i][j+1]=temp;
        return(1);
    }

}
int shiftUp(int A[][4]){
      int i,j,temp,zeroFound=0;

    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(i==3)
        return(0);//shifting not possible
    else{
        temp=A[i][j];
        A[i][j]=A[i+1][j];
        A[i+1][j]=temp;
        return(1);
    }

}
int shiftDown(int A[][4]){
          int i,j,temp,zeroFound=0;

    for(i=0;i<=3;i++){
        for(j=0;j<=3;j++){
            if(A[i][j]==0){
                zeroFound=1;
                break;
            }
        }
        if(zeroFound)
            break;
    }
    if(i==0)
        return(0);//shifting not possible
    else{
        temp=A[i][j];
        A[i][j]=A[i-1][j];
        A[i-1][j]=temp;
        return(1);
    }

}

//start Gamee
int startGame()
{
    int ch;
    ch=getch();
    if(ch>=1&&ch<=210)
    {
        return 0;
    }    
}



// Game rules 
int gameRule(int arr[4][4])
{
    system("cls");
    
    int i,j,k=1;
    int x;
    printf("\n                   MATRIX GAME                                     \n");
    printf("\n                 RULE OF THIS GAME                 \n");
    printf("\n1.You can move only 1 step at a time by arrow key \n");

    printf("\nMove Up   : by Up arrow key ");
    printf("\nMove Down : by Down arrow key");
    printf("\nMove Left : by Left arrow key");
    printf("\nMove Right: by Right arrow key");

    printf("\n2.You can move number at empty position only ");
    printf("\n");
    printf("\n3.For each valid move : your total number of move will decreased by 1 \n");
    printf("4.Wining situation : ");
    printf("number in a 4*4 matrix should be in order from 1 to 15 ");
    printf("\n\n            winning situation:         \n");
   
    printf("------------------\n");
    for(i=0;i<4;i++)
   { printf("| ");
       for(j=0;j<4;j++)
    {   if(arr[i][j]!=0)
        printf("%-2d |",4*i+j+1);
        else
        printf("   |");
    }
    printf("\n");
   }

    printf("------------------\n");
    printf("\n5.You can exit the game at any time by pressing 'E' or 'e ");
   
   
    printf("\nSo Try to win in minimum no of move \n");
    printf("\n         Happy gaming , Good Luck\n");
   
    printf("\nEnter any key to start -----> : ");
    x=startGame();
    return x;
}

// Levels
int levels()
{
    system("cls");
    int level;
    printf("1. Easy\n");

    printf("2. Medium\n");

    printf("3. Hard\n");

    printf("4. Custom move\n");
    
    printf("Choose levels: ");
    scanf("%d",&level);
    

    return level;
}

// Number Shifting Game

void numberShiftingGame()
{
    int startGame=0;
while (!startGame)
{
    system("cls");
    int arr[4][4],move;
    createMatrix(arr);
    char name[20];
    int level=1;
    

    printf("Player Name:- ");
    scanf("%s",&name);

    gameRule(arr);

    while (level)
    {
    switch (levels())
    {
    case 1:
        move=100;
        level=0;
        break;
    case 2:
        move=50;
        level=0;
        break;
    case 3:
        move=20;
        level=0;
        break;
    case 4:
        printf("\nSelect custom move: ");
        scanf("%d",&move);
        level=0;
        break;
    default:
        printf("Invalid number Try again.........");
        getch();
        break;
    }
    }

    while(move){
        system("cls");
        printf("\n");
        printf("Player Name: ");
        puts(name);
        printf("\nMove Remaining: %d\n",move);
        showMatrix(arr);
        if(winner(arr)){
            printf("\nCongratulation you win in %d moves",500-move);
            printf("\nPress any key to exit...");
            getch();
            exit(0);
        }
        switch(readKey())
        {
       
        case UP:
            if(shiftUp(arr)==0)
                move++;
            break;
        case DOWN:
            if(shiftDown(arr)==0)
                move++;
            break;
        case LEFT:
            if(shiftLeft(arr)==0)
                move++;
            break;
        case RIGHT:
            if(shiftRight(arr)==0)
                move++;
            break;
         case 'e':
            exit(0);
        case 'E':
            exit(0);
        default:
            move++;
        }
        system("cls");
        move--;
    }
    if(move==0)
    {
    printf("Moves Over butter luck next time...\n");
    printf("----------------------------------------\n");
    startGame=0; // Game Over
    }
    
    playAgain();


}
}


//play Again

void playAgain()
{
    char startAgain;
    printf("Do you want to play again Y/N: ");
    scanf("%s",&startAgain);

    if(startAgain=='Y'||startAgain=='y')
    numberShiftingGame();
    if(startAgain=='N'||startAgain=='n')
    {
    printf("Thanks For playing.....");
    getch();
    exit(1);
    }
}


int main()
{

    numberShiftingGame();
 
}