/* Project Name: Number System Operations (Final Project)   */
/* Coded by    : Arman O. a.k.a mIndH4Ck++                  */
/* Year        : 1st Year(2000)                             */

/* "Every line of your code in your program has its purpose, */
/* if it doesnt have a purpose, it is either be commented or be deleted" */

#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <dos.h>
#include <stdio.h>
#include <conio.h>

/*     function prototypes           */
void decimal_to_binary(double sum);
void hexadecimal_operations(void);
void decimal_operations(void);
void octal_operations(void);
void binary_operations(void);

void displayNotes(void);
void splash_screen(void);
void author();
void initgraphix();
void destroygraphix();
void drawbox(int left,int top,int right,int bottom,int color);
void box(int left,int top,int right,int bottom,
    int opendirection,int shadecolor,int mydelay,int tweening);

/* Constant */
#define ARROWUP 72
#define ARROWDOWN 80

#define GOINGRIGHT 1
#define GOINGDOWN 2
#define GOINGLEFT 3
#define DELAY 30
#define TWEEN_DELAY2 7  /* box open left/right tween delay */
#define TWEEN_DELAY 3   /* smallbox open left/right tween delay*/
#define WITH_TWEEN 1    /* with smooth animation */
#define WITH_NO_TWEEN 0 /* without smooth animation */
#define MAX 20          /* limit the accepted value to 20 */


/* Global variables */
int starty=13;
int startx=30;

int xprint=20;
int yprint=32;

int choiceID;
int operatorChoice;

void displayMenu(void){
   box(28,7,52,10,GOINGDOWN,YELLOW,12,WITH_TWEEN);
   textcolor(YELLOW);gotoxy(29,8);cprintf("Operation selected:");

   switch(operatorChoice){
     case 1:
      textcolor(WHITE);gotoxy(30,9);cprintf("--> ADDITION ");
      break;
     case 2:
      textcolor(WHITE);gotoxy(30,9);cprintf("--> SUBTRACTION");
      break;
     case 3:
      textcolor(WHITE);gotoxy(30,9);cprintf("--> MULTIPLICATION");
      break;
     case 4:
      textcolor(WHITE);gotoxy(30,9);cprintf("--> DIVISION");
      break;
   }
   textcolor(WHITE);
   gotoxy(startx,starty);cprintf("® Decimal           ¯");
   gotoxy(startx,starty+1);cprintf("® Binary            ¯");
   gotoxy(startx,starty+2);cprintf("® Octal             ¯");
   gotoxy(startx,starty+3);cprintf("® Hexa              ¯");
   gotoxy(startx,starty+4);cprintf("® <-- Back to Main  ¯");
   displayNotes();
}

void dispOperations(void){
   box(28,8,52,10,GOINGRIGHT,YELLOW,12,WITH_NO_TWEEN);
   textcolor(YELLOW|BLINK);gotoxy(29,9);cprintf("<< SELECT OPERATIONS >>");
   box(28,12,52,18,GOINGDOWN,YELLOW,12,WITH_NO_TWEEN);
   textcolor(WHITE);
   textbackground(YELLOW);
   gotoxy(startx,starty);cprintf("® Addition          ¯");
   gotoxy(startx,starty+1);cprintf("® Subtraction       ¯");
   gotoxy(startx,starty+2);cprintf("® Multiplication    ¯");
   gotoxy(startx,starty+3);cprintf("® Division          ¯");
   gotoxy(startx,starty+4);cprintf("® Exit              ¯");
   displayNotes();
}

void displayNotes(void) {
   textcolor(GREEN);
   textbackground(BLACK);
   gotoxy(30,50);cprintf("Note: Use arrow keys to move the selection.");
}

void highlightOperator(int selectedChoice){
  textcolor(BLACK);
  textbackground(YELLOW);
  switch(selectedChoice){
   case 1:  gotoxy(startx,starty);cprintf("® Addition          ¯");
      break;
   case 2:  gotoxy(startx,starty+1);cprintf("® Subtraction       ¯");
      break;
   case 3:  gotoxy(startx,starty+2);cprintf("® Multiplication    ¯");
      break;
   case 4:  gotoxy(startx,starty+3);cprintf("® Division          ¯");
      break;
   case 5:  gotoxy(startx,starty+4);cprintf("® Exit              ¯");
      break;
  }
}

void highlightChoice(int selectedChoice){
  textcolor(BLACK);
  textbackground(YELLOW);
  switch(selectedChoice){
   case 1:  gotoxy(startx,starty);cprintf("® Decimal           ¯");
      break;
   case 2:  gotoxy(startx,starty+1);cprintf("® Binary            ¯");
      break;
   case 3:  gotoxy(startx,starty+2);cprintf("® Octal             ¯");
      break;
   case 4:  gotoxy(startx,starty+3);cprintf("® Hexa              ¯");
      break;
   case 5:  gotoxy(startx,starty+4);cprintf("® <--Back to Main   ¯");
      break;
  }
}

int getOperatorChoice(void){
  int ch,i;
  int choiceID;
   dispOperations();
   highlightOperator(choiceID);
   while(ch!=13){
     ch=getch();
     /*    printf("%d",ch); */
      switch(ch){
        case ARROWUP :/* arrow up */
          choiceID--;
          if (choiceID<1) {
            choiceID=5;
          }
        break;
        case ARROWDOWN : /* arrow down */
          choiceID++;
          if (choiceID>5) {
            choiceID=1;
          }
        break;
      }
      dispOperations();
      highlightOperator(choiceID);
    }
  return choiceID;
}

int getChoice(void){
  int ch,i;
  int choiceID;

   displayMenu();
   highlightChoice(choiceID);
   while(ch!=13){
     ch=getch();
     /*    printf("%d",ch); */
      switch(ch){
        case ARROWUP :/* arrow up */
          choiceID--;
          if (choiceID<1) {
            choiceID=5;
          }
        break;
        case ARROWDOWN : /* arrow down */
          choiceID++;
          if (choiceID>5) {
            choiceID=1;
          }
          break;
     }
     displayMenu();
     highlightChoice(choiceID);
  }
  return choiceID;
}

void main(void){
  int choice;
  clrscr();
  splash_screen();
  textmode(64);
  highvideo(); /* sets video to high */
  textbackground(BLACK);
  choiceID = 2;
  highlightOperator(choiceID);
   for(;;){
      dispOperations();       /* display the operations ==> addition,subtraction,etc.. */
      operatorChoice = getOperatorChoice();  /* get the user operator choice */
      if (operatorChoice==5) {
        box(0,0,90,50,GOINGDOWN,BLACK,10,WITH_NO_TWEEN);
        author();getch();
        box(0,0,90,50,GOINGRIGHT,BLACK,10,WITH_TWEEN);
        exit(0);
      }

       displayMenu();
       do {
         //clrscr();
         displayMenu();        /* display the number system  */
         choice = getChoice(); /* get the user number system selected */
         switch(choice){
           case 1:          /* decimal */
              decimal_operations();
              break;
            case 2:         /* binary */
              binary_operations();
              break;
            case 3:         /* octal  */
              octal_operations();
              break;
            case 4:         /*  hexa  */
              hexadecimal_operations();
              break;
            case 5:         /* cancel */
              break;
           default:
              highlightOperator(choiceID);
         }// end switch(choice)
         
         textbackground(BLACK);
         clrscr();
       } while(choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5);
    }
}

void decimal_operations(void){
  int dec[100],n,sum,diff,prod;
  char result[5];
  float quotient;
  int i;
  int size;

    switch(operatorChoice){
      case 1:
        box(13,20,70,22,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);
        gotoxy(startx/2,starty+8);cprintf("How many decimal nos. to be added(maximum of 20)?");
        result[0] = 3;
        strcpy(result,cgets(result));
        size = atoi(result);
        if (size<2 || size>20){
          box(5,28,80,32,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
          gotoxy(6,30);textcolor(BLACK);cprintf("Can only accept a minimum of 2 decimal nos.and a maximum of 20 decimals.");
          getch();
          return;
        }
        n = size;
        //scanf("%d",&n);

        box(13,24,70,27+n,GOINGDOWN,YELLOW,12,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);textcolor(WHITE);
        for(i=0;i<n;i++){
            gotoxy(startx/2+5,starty+12+i);cprintf("Input decimal value #%d: ",i+1);
            scanf("%d",&dec[i]);
        }

        sum=0;
        for(i=0;i<n;i++){
          sum+=dec[i];
        }
        gotoxy(startx/2+27,starty+12+i);textcolor(WHITE);cprintf("----------------");
        gotoxy(startx/2+23,starty+13+i);textcolor(YELLOW);cprintf("Sum : %d",sum);
        getch();
        box(13,23,70,28+n,GOINGLEFT,BLACK,5,WITH_TWEEN);
        box(13,19,70,23,GOINGLEFT,BLACK,3,WITH_TWEEN);
        break;
      case 2:
        box(11,20,70,22,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);

        gotoxy(startx/2-2,starty+8); cprintf("How many decimal nos. to be subtracted(maximum of 20)?");
        result[0] = 3;
        strcpy(result,cgets(result));
        size = atoi(result);
        if (size<2 || size>20){
          box(5,28,80,32,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
          gotoxy(6,30);textcolor(BLACK);cprintf("Can only accept a minimum of 2 decimal nos.and a maximum of 20 decimals.");
          getch();
          return;
        }
        n = size;
        //scanf("%d",&n);

        box(11,24,70,27+n,GOINGDOWN,YELLOW,12,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);textcolor(WHITE);
        for(i=0;i<n;i++){
          gotoxy(startx/2+1,starty+12+i);cprintf("Input decimal value #%d: ",i+1);
          scanf("%d",&dec[i]);
        }

        diff=dec[0];    /* save first subtrahend */
        for(i=1;i<n;i++){
              diff=diff-dec[i];
        }

        gotoxy(startx/2+24,starty+12+i);textcolor(WHITE);cprintf("----------------");
        gotoxy(startx/2+12,starty+13+i);textcolor(YELLOW);cprintf("Difference : %d",diff);
        getch();
        box(10,23,70,27+n,GOINGLEFT,BLACK,8,WITH_TWEEN);
        box(10,19,70,23,GOINGRIGHT,BLACK,5,WITH_TWEEN);
        break;
      case 3:
        box(13,20,70,22,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);
        gotoxy(startx/2,starty+8); cprintf("How many decimal nos. to be multiply(maximum of 20)?");
        result[0] = 3;
        strcpy(result,cgets(result));
        size = atoi(result);
        if (size<2 || size>20){
          box(5,28,80,32,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
          gotoxy(6,30);textcolor(BLACK);cprintf("Can only accept a minimum of 2 decimal nos.and a maximum of 20 decimals.");
          getch();
          box(5,28,80,32,GOINGRIGHT,BLACK,5,WITH_TWEEN);
          return;
        }
        n = size;
        box(13,24,70,27+n,GOINGDOWN,YELLOW,12,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);textcolor(WHITE);
        for(i=0;i<n;i++){
          gotoxy(startx/2+5,starty+12+i);cprintf("Input decimal value #%d: ",i+1);
          scanf("%d",&dec[i]);
        }
        prod=dec[0];
        for(i=1;i<n;i++){
          prod*=dec[i];
        }
        gotoxy(startx/2+28,starty+12+i);textcolor(WHITE);cprintf("----------------");
        gotoxy(startx/2+19,starty+13+i);textcolor(YELLOW);cprintf("Product : %d",prod);
        getch();
        box(12,23,71,27+n,GOINGDOWN,BLACK,15,WITH_TWEEN);
        box(13,19,70,23,GOINGLEFT,BLACK,5,WITH_TWEEN);
        break;
      case 4:
        n=2;
        box(19,24,67,27+n,GOINGDOWN,YELLOW,12,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);textcolor(WHITE);
        for(i=0;i<n;i++){
          gotoxy(startx/2+5,starty+12+i);cprintf("Input decimal value #%d: ",i+1);
          scanf("%d",&dec[i]);
        }
        if(dec[1] == 0) {
          gotoxy(startx/2+20,starty+13+i);
          _setcursortype(_NOCURSOR);
          textcolor(RED|BLINK);cprintf("ERROR: Division by zero.");
          getch();
          box(19,24,67,27+n,GOINGLEFT,BLACK,5,WITH_TWEEN);
          break;
        }
        quotient=dec[0];
        for(i=1;i<n;i++){
          quotient/=dec[i];
        }
        gotoxy(startx/2+27,starty+12+i);textcolor(WHITE);cprintf("----------------");
        gotoxy(startx/2+24,starty+13+i);textcolor(YELLOW);cprintf("Quotient : %.2f",quotient);
        getch();
        box(19,23,67,28+n,GOINGLEFT,BLACK,5,WITH_TWEEN);
        box(19,19,67,23,GOINGLEFT,BLACK,12,WITH_TWEEN);
        break;
    }
}

void binary_operations(void){
  struct{
    char val[100];
    double dec;
  } bin[100];

  int n,diff;
  double prod;

  char result[5];
  float quotient;
  int i,j;
  int size;
  double dec[100];
  double x,y,total,sum;

    switch(operatorChoice){
      case 1:
        box(13,20,70,22,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);
        gotoxy(startx/2,starty+8);cprintf("How many binary nos. to be added(maximum of 20)?");
        result[0] = 3;
        strcpy(result,cgets(result));
        size = atoi(result);
        if (size<2 || size>20){
          box(5,28,80,32,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
          gotoxy(6,30);textcolor(BLACK);cprintf("Can only accept a minimum of 2 binary nos.and a maximum of 20 binaries.");
          getch();
          return;
        }
        n = size;
        box(13,24,70,27+n,GOINGDOWN,YELLOW,12,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);textcolor(WHITE);
        for(i=0;i<n;i++){
            gotoxy(startx/2+5,starty+12+i);cprintf("Input binary value #%d: ",i+1);
            scanf("%s",&bin[i].val);
        }
        x=2.0;
        for(i=0;i<n;i++){
           y     = 0.0;
           total = 0.0;
           sum   = 0.0;
           for(j = strlen(bin[i].val)-1; j>-1;j--){
                sum = ((bin[i].val[j] - 49)+1) * pow(x,y);
                /*printf("\n%d times ",bin[i].val[j] - 48 );
                printf(" %.0lf raised to the %.0lf is %.0lf:",x,y,pow(x,y));*/
                total+=sum;
                y++;
           }
           bin[i].dec = total;
        }
        sum = 0.0;
        for(i=0;i<n;i++){
            sum +=bin[i].dec;
        }
        gotoxy(startx/2+27,starty+12+i);textcolor(WHITE);cprintf("----------------");
        gotoxy(startx/2+23,starty+13+i);textcolor(YELLOW);cprintf("Sum : ");
        decimal_to_binary(sum);  /* convert the decimal(sum) to binary */
        getch();
        box(13,23,70,28+n,GOINGLEFT,BLACK,5,WITH_TWEEN);
        box(13,19,70,23,GOINGLEFT,BLACK,3,WITH_TWEEN);
        getch();
        break;
      case 2:
        box(13,20,70,22,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);
        gotoxy(startx/2,starty+8);cprintf("How many binary nos. to be subtracted(maximum of 20)?");
        result[0] = 3;
        strcpy(result,cgets(result));
        size = atoi(result);
        if (size<2 || size>20){
          box(5,28,80,32,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
          gotoxy(6,30);textcolor(BLACK);cprintf("Can only accept a minimum of 2 binary nos.and a maximum of 20 binaries.");
          getch();
          return;
        }
        n = size;
        box(13,24,70,27+n,GOINGDOWN,YELLOW,12,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);textcolor(WHITE);

        for(i=0;i<n;i++){
          gotoxy(startx/2+5,starty+12+i);cprintf("Input binary value #%d: ",i+1);
          scanf("%s",&bin[i].val);
        }
        x=2.0;
        for(i=0;i<n;i++){
          y     = 0.0;
          total = 0.0;
          sum   = 0.0;
          for(j = strlen(bin[i].val)-1; j>-1;j--){
            sum = ((bin[i].val[j] - 49)+1) * pow(x,y);
            /*printf("\n%d times ",bin[i].val[j] - 48 );
            printf(" %.0lf raised to the %.0lf is %.0lf:",x,y,pow(x,y));*/
            total+=sum;
            y++;
          }
          bin[i].dec = total;
        }
        diff=bin[0].dec;    /* save first subtrahend */
        for(i=1;i<n;i++){
              diff=diff-bin[i].dec;
        }
        gotoxy(startx/2+24,starty+12+i);textcolor(WHITE);cprintf("----------------");
        gotoxy(startx/2+12,starty+13+i);textcolor(YELLOW);cprintf("Difference : ");
        decimal_to_binary(diff);
        getch();
        box(10,23,70,27+n,GOINGLEFT,BLACK,8,WITH_TWEEN);
        box(10,19,70,23,GOINGRIGHT,BLACK,5,WITH_TWEEN);
        break;
      case 3:
        box(13,20,70,22,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);
        gotoxy(startx/2,starty+8);cprintf("How many binary nos. to be added(maximum of 20)?");
        result[0] = 3;
        strcpy(result,cgets(result));
        size = atoi(result);
        if (size<2 || size>20){
          box(5,28,80,32,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
          gotoxy(6,30);textcolor(BLACK);cprintf("Can only accept a minimum of 2 binary nos.and a maximum of 20 binaries.");
          getch();
          return;
        }
        n = size;
        box(13,24,70,27+n,GOINGDOWN,YELLOW,12,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);textcolor(WHITE);
        for(i=0;i<n;i++){
          gotoxy(startx/2+5,starty+12+i);cprintf("Input binary value #%d: ",i+1);
          scanf("%s",&bin[i].val);
        }
        x=2.0;
        for(i=0;i<n;i++){
         y     = 0.0;
         total = 0.0;
         sum   = 0.0;
         for(j = strlen(bin[i].val)-1; j>-1;j--){
            sum = ((bin[i].val[j] - 49)+1) * pow(x,y);
            /*printf("\n%d times ",bin[i].val[j] - 48 );
            printf(" %.0lf raised to the %.0lf is %.0lf:",x,y,pow(x,y));*/
            total+=sum;
            y++;
         }
         bin[i].dec = total;
        }
        prod = bin[0].dec;
        for(i=1;i<n;i++){
            prod *=bin[i].dec;
        }
        gotoxy(startx/2+27,starty+12+i);textcolor(WHITE);cprintf("----------------");
        gotoxy(startx/2+23,starty+13+i);textcolor(YELLOW);cprintf("Product : ");
        decimal_to_binary(prod);  /* convert the decimal(sum) to binary */
        getch();
        box(13,23,70,28+n,GOINGLEFT,BLACK,5,WITH_TWEEN);
        box(13,19,70,23,GOINGLEFT,BLACK,3,WITH_TWEEN);
        getch();
        break;
      case 4:
        n=2;
        box(19,24,67,27+n,GOINGDOWN,YELLOW,12,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);textcolor(WHITE);
        for(i=0;i<n;i++){
          gotoxy(startx/2+5,starty+12+i);cprintf("Input binary value #%d: ",i+1);
          scanf("%s",&bin[i].val);
        }
        if(bin[1].val == 0) {
          gotoxy(startx/2+20,starty+13+i);
          _setcursortype(_NOCURSOR);
          textcolor(RED|BLINK);cprintf("ERROR: Division by zero.");
          getch();
          box(19,24,67,27+n,GOINGLEFT,BLACK,5,WITH_TWEEN);
          break;
        }
        x=2.0;
        for(i=0;i<n;i++){
           y     = 0.0;
           total = 0.0;
           sum   = 0.0;
           for(j = strlen(bin[i].val)-1; j>-1;j--){
              sum = ((bin[i].val[j] - 49)+1) * pow(x,y);
              /*printf("\n%d times ",bin[i].val[j] - 48 );
              printf(" %.0lf raised to the %.0lf is %.0lf:",x,y,pow(x,y));*/
              total+=sum;
              y++;
           }
           bin[i].dec = total;
        }
        quotient=bin[0].dec;
        for(i=1;i<n;i++){
          quotient/=bin[i].dec;
        }
        gotoxy(startx/2+27,starty+12+i);textcolor(WHITE);cprintf("----------------");
        gotoxy(startx/2+16,starty+13+i);textcolor(YELLOW);cprintf("Quotient : ");
        decimal_to_binary(quotient);
        getch();
        box(19,23,67,28+n,GOINGLEFT,BLACK,5,WITH_TWEEN);
        box(19,19,67,23,GOINGLEFT,BLACK,12,WITH_TWEEN);
        break;
    }

}

/* ---------------------------DECIMAL TO BINARY-------------------------------*/
void decimal_to_binary(double sum){
  int dec,a[100];
  int bin,n,i=0;
  int j;
  char s[20];
  dec = (int) sum;
  do{
    a[i]=dec%2;
    dec=dec/2;
    i++;
  }while(dec!=0);
  for(n=i-1;n>=0;n--)
  cprintf("%d",a[n]);
}

/* ---------------------------OCTAL OPERATIONS -------------------------------*/
void octal_operations(void){
  int oct[100],n,sum,diff,prod;
  char result[5];
  long quotient;
  int i;
  int size;

    switch(operatorChoice){
      case 1:
        box(13,20,70,22,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);
        gotoxy(startx/2,starty+8);cprintf("How many octal nos. to be added(maximum of 20)?");
        result[0] = 3;
        strcpy(result,cgets(result));
        size = atoi(result);
        if (size<2 || size>20){
            box(5,28,80,32,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
            gotoxy(6,30);textcolor(BLACK);cprintf("Can only accept a minimum of 2 octal nos.and a maximum of 20 octals.");
            getch();
            return;
        }
        n = size;
        box(13,24,70,27+n,GOINGDOWN,YELLOW,12,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);textcolor(WHITE);
        for(i=0;i<n;i++){
            gotoxy(startx/2+5,starty+12+i);cprintf("Input octal value #%d: ",i+1);
            scanf("%o",&oct[i]);
        }
        sum=0;
        for(i=0;i<n;i++){
              sum+=oct[i];
        }
        gotoxy(startx/2+27,starty+12+i);textcolor(WHITE);cprintf("----------------");
        gotoxy(startx/2+21,starty+13+i);textcolor(YELLOW);cprintf("Sum : %o",sum);
        getch();
        box(13,23,70,28+n,GOINGLEFT,BLACK,5,WITH_TWEEN);
        box(13,19,70,23,GOINGLEFT,BLACK,3,WITH_TWEEN);
        break;
      case 2:
        box(11,20,70,22,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);
        gotoxy(startx/2-2,starty+8); cprintf("How many octal nos. to be subtracted(maximum of 20)?");
        result[0] = 3;
        strcpy(result,cgets(result));
        size = atoi(result);
        if (size<2 || size>20){
          box(5,28,80,32,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
          gotoxy(6,30);textcolor(BLACK);cprintf("Can only accept a minimum of 2 octal nos.and a maximum of 20 octals.");
          getch();
          return;
        }
        n = size;
        box(11,24,70,27+n,GOINGDOWN,YELLOW,12,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);textcolor(WHITE);
        for(i=0;i<n;i++){
          gotoxy(startx/2+1,starty+12+i);cprintf("Input octal value #%d: ",i+1);
          scanf("%o",&oct[i]);
        }
        diff=oct[0];    /* save first subtrahend */
        for(i=1;i<n;i++){
          diff=diff-oct[i];
        }
        gotoxy(startx/2+24,starty+12+i);textcolor(WHITE);cprintf("----------------");
        gotoxy(startx/2+12,starty+13+i);textcolor(YELLOW);cprintf("Difference : %o",diff);
        getch();
        box(10,23,70,27+n,GOINGLEFT,BLACK,8,WITH_TWEEN);
        box(10,19,70,23,GOINGRIGHT,BLACK,5,WITH_TWEEN);
        break;
      case 3:
        box(13,20,70,22,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);
        gotoxy(startx/2,starty+8); cprintf("How many octal nos. to be multiply(maximum of 20)?");
        result[0] = 3;
        strcpy(result,cgets(result));
        size = atoi(result);
        if (size<2 || size>20){
          box(5,28,80,32,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
          gotoxy(6,30);textcolor(BLACK);cprintf("Can only accept a minimum of 2 octal nos.and a maximum of 20 octals.");
          getch();
          box(5,28,80,32,GOINGRIGHT,BLACK,5,WITH_TWEEN);
          return;
        }
        n = size;
        box(13,24,70,27+n,GOINGDOWN,YELLOW,12,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);textcolor(WHITE);
        for(i=0;i<n;i++){
          gotoxy(startx/2+5,starty+12+i);cprintf("Input octal value #%d: ",i+1);
          scanf("%o",&oct[i]);
        }

        prod=oct[0];
        for(i=1;i<n;i++){
          prod*=oct[i];
        }

        gotoxy(startx/2+27,starty+12+i);textcolor(WHITE);cprintf("----------------");
        gotoxy(startx/2+17,starty+13+i);textcolor(YELLOW);cprintf("Product : %o",prod);
        getch();
        box(12,23,71,27+n,GOINGDOWN,BLACK,15,WITH_TWEEN);
        box(13,19,70,23,GOINGLEFT,BLACK,5,WITH_TWEEN);
        break;
      case 4:
        n=2;
        box(19,24,67,27+n,GOINGDOWN,YELLOW,12,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);textcolor(WHITE);
        for(i=0;i<n;i++){
          gotoxy(startx/2+5,starty+12+i);cprintf("Input octal value #%d: ",i+1);
          scanf("%o",&oct[i]);
        }

        if(oct[1] == 0) {
          gotoxy(startx/2+20,starty+13+i);
          _setcursortype(_NOCURSOR);
          textcolor(RED|BLINK);cprintf("ERROR: Division by zero.");
          getch();
          box(19,24,67,27+n,GOINGLEFT,BLACK,5,WITH_TWEEN);
          break;
        }
        quotient=oct[0];
        for(i=1;i<n;i++){
          quotient/=oct[i];
        }
        gotoxy(startx/2+27,starty+12+i);textcolor(WHITE);cprintf("----------------");
        gotoxy(startx/2+16,starty+13+i);textcolor(YELLOW);cprintf("Quotient : %o",quotient);
        getch();
        box(19,23,67,28+n,GOINGLEFT,BLACK,5,WITH_TWEEN);
        box(19,19,67,23,GOINGLEFT,BLACK,12,WITH_TWEEN);
        break;
    }
}
/* ----------------------HEXADECIMAL OPERATIONS----------------------------*/
void hexadecimal_operations(void){
  int hex[100],n,sum,diff,prod;
  char result[5];
  long quotient;
  int i;
  int size;

    switch(operatorChoice){
      case 1:
        box(13,20,70,22,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);
        gotoxy(startx/2,starty+8);cprintf("How many hexa nos. to be added(maximum of 20)?");
        result[0] = 3;
        strcpy(result,cgets(result));
        size = atoi(result);
        if (size<2 || size>20){
            box(5,28,80,32,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
            gotoxy(6,30);textcolor(BLACK);cprintf("Can only accept a minimum of 2 hexa nos.and a maximum of 20 hexa nos.");
            getch();
            return;
        }
        n = size;
        box(13,24,70,27+n,GOINGDOWN,YELLOW,12,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);textcolor(WHITE);
        for(i=0;i<n;i++){
            gotoxy(startx/2+5,starty+12+i);cprintf("Input hexa value #%d: ",i+1);
            scanf("%x",&hex[i]);
        }

        sum=0;
        for(i=0;i<n;i++){
              sum+=hex[i];
        }
        gotoxy(startx/2+25,starty+12+i);textcolor(WHITE);cprintf("----------------");
        gotoxy(startx/2+20,starty+13+i);textcolor(YELLOW);cprintf("Sum : %x",sum);
        getch();
        box(13,23,70,28+n,GOINGLEFT,BLACK,5,WITH_TWEEN);
        box(13,19,70,23,GOINGLEFT,BLACK,3,WITH_TWEEN);
        break;
      case 2:
        box(11,20,70,22,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);

        gotoxy(startx/2-2,starty+8); cprintf("How many hexa nos. to be subtracted(maximum of 20)?");
        result[0] = 3;
        strcpy(result,cgets(result));
        size = atoi(result);
        if (size<2 || size>20){
            box(5,28,80,32,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
            gotoxy(6,30);textcolor(BLACK);cprintf("Can only accept a minimum of 2 hexa nos.and a maximum of 20 hexa nos.");
            getch();
            return;
        }
        n = size;
        //scanf("%d",&n);

        box(11,24,70,27+n,GOINGDOWN,YELLOW,12,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);textcolor(WHITE);
        for(i=0;i<n;i++){
          gotoxy(startx/2+1,starty+12+i);cprintf("Input hexa value #%d: ",i+1);
          scanf("%x",&hex[i]);
        }

        diff=hex[0];    /* save first subtrahend */
        for(i=1;i<n;i++){
              diff=diff-hex[i];
        }

        gotoxy(startx/2+22,starty+12+i);textcolor(WHITE);cprintf("----------------");
        gotoxy(startx/2+9,starty+13+i);textcolor(YELLOW);cprintf("Difference : %x",diff);
        getch();
        box(10,23,70,27+n,GOINGLEFT,BLACK,8,WITH_TWEEN);
        box(10,19,70,23,GOINGRIGHT,BLACK,5,WITH_TWEEN);
        break;
      case 3:
        box(13,20,70,22,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);
        gotoxy(startx/2,starty+8); cprintf("How many hexa nos. to be multiply(maximum of 20)?");
        result[0] = 3;
        strcpy(result,cgets(result));
        size = atoi(result);
        if (size<2 || size>20){
          box(5,28,80,32,GOINGRIGHT,YELLOW,5,WITH_TWEEN);
          gotoxy(6,30);textcolor(BLACK);cprintf("Can only accept a minimum of 2 hexa nos.and a maximum of 20 hexa nos.");
          getch();
          box(5,28,80,32,GOINGRIGHT,BLACK,5,WITH_TWEEN);
          return;
        }
        n = size;

        box(13,24,70,27+n,GOINGDOWN,YELLOW,12,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);textcolor(WHITE);
        for(i=0;i<n;i++){
          gotoxy(startx/2+5,starty+12+i);cprintf("Input hexa value #%d: ",i+1);
          scanf("%x",&hex[i]);
        }

        prod=hex[0];
        for(i=1;i<n;i++){
              prod*=hex[i];
        }

        gotoxy(startx/2+26,starty+12+i);textcolor(WHITE);cprintf("----------------");
        gotoxy(startx/2+16,starty+13+i);textcolor(YELLOW);cprintf("Product : %x",prod);
        getch();
        box(12,23,71,27+n,GOINGDOWN,BLACK,15,WITH_TWEEN);
        box(13,19,70,23,GOINGLEFT,BLACK,5,WITH_TWEEN);
        break;
      case 4:
        n=2;
        box(19,24,67,27+n,GOINGDOWN,YELLOW,12,WITH_TWEEN);
        _setcursortype(_NORMALCURSOR);textcolor(WHITE);
        for(i=0;i<n;i++){
          gotoxy(startx/2+5,starty+12+i);cprintf("Input hexa value #%d: ",i+1);
          scanf("%x",&hex[i]);
        }

        if(hex[1] == 0) {
          gotoxy(startx/2+20,starty+13+i);
          _setcursortype(_NOCURSOR);
          textcolor(RED|BLINK);cprintf("ERROR: Division by zero.");
          getch();
          box(19,24,67,27+n,GOINGLEFT,BLACK,5,WITH_TWEEN);
          break;
        }
        quotient=hex[0];
        for(i=1;i<n;i++){
          quotient/=hex[i];
        }
        gotoxy(startx/2+26,starty+12+i);textcolor(WHITE);cprintf("----------------");
        gotoxy(startx/2+15,starty+13+i);textcolor(YELLOW);cprintf("Quotient : %x",quotient);
        getch();
        box(19,23,67,28+n,GOINGLEFT,BLACK,5,WITH_TWEEN);
        box(19,19,67,23,GOINGLEFT,BLACK,12,WITH_TWEEN);
        break;
    }
}

/* ---------------------------DRAW BOX---------------------------------*/
void drawbox(int left,int top,int right,int bottom,int color){
  int ctr,ctr2;
  char topLeftChar    = 'Ú';
  char topRightChar   = '¿';
  char bottomLeftChar = 'À';
  char bottomRightChar= 'Ù';
  char horizontalChar = 'Ä';
  char verticalChar   = '³';
 textcolor(color);
 gotoxy(left,top);putch(topLeftChar);
 gotoxy(right,top);putch(topRightChar);
 gotoxy(left,bottom);putch(bottomLeftChar);
 gotoxy(right,bottom);putch(bottomRightChar);
 for(ctr=left+1;ctr < right;ctr++){
    gotoxy(ctr,top);putch(horizontalChar);
    gotoxy(ctr,bottom);putch(horizontalChar);
 }
 for(ctr=top+1;ctr<bottom;ctr++){
    gotoxy(left,ctr);putch(verticalChar);
    gotoxy(right,ctr);putch(verticalChar);
 }
}

/* -----------------DRAW BOX/SHADING/MOTION TWEENING ----------------------------*/
void box(int left,int top,int right,int bottom,
          int opendirection,int shadecolor,int mydelay,int tweening){
  int i;
  int ctr,ctr2;

  _setcursortype(_NOCURSOR);
  switch(opendirection){
  case GOINGDOWN: /* open downward */
   textcolor(shadecolor);
   textbackground(shadecolor);
   for(ctr=top+1;ctr < bottom;ctr++) {
      for(ctr2=left+1;ctr2<right;ctr2++){
        gotoxy(ctr2,ctr);putch(' ');
      }
    if (tweening) delay(mydelay);
   }
   drawbox(left,top,right,bottom,shadecolor);
   break;
  case GOINGRIGHT: /* open to left*/
    textbackground(shadecolor);
    textcolor(shadecolor);
    for(ctr=left+1;ctr < right;ctr++){
      for(ctr2=top+1;ctr2<bottom;ctr2++){
       gotoxy(ctr,ctr2);putch(' ');
      }
      if (tweening) delay(mydelay);
    }
    drawbox(left,top,right,bottom,shadecolor);
    break;
  case GOINGLEFT : /* erase shading */
   textbackground(shadecolor);
   textcolor(shadecolor);
   for(ctr=right;ctr >= left;ctr--){
      for(ctr2=top;ctr2<=bottom;ctr2++){
          gotoxy(ctr,ctr2);putch(' ');
      }
    if (tweening) delay(mydelay);
   }
   break;
  }
}

void initgraphix(){
  int gd=DETECT,gm;
  int errcode;

  initgraph(&gd,&gm,"..\\bgi");
  errcode=graphresult();
  if (errcode!=grOk){
      printf("Graphics error : %s.\n",grapherrormsg(errcode));
      getch();
      exit(1);
  }
}
void destroygraphix(){
 closegraph();
}

void author() {
  clrscr();
  delay(1000);
  //textbackground(BLACK);
  box(0,0,90,50,GOINGDOWN,BLACK,1,WITH_NO_TWEEN);
  box(10,17,75,23,GOINGRIGHT,YELLOW,4,WITH_TWEEN);delay(DELAY);
  textcolor(YELLOW);
  gotoxy(startx-15,starty+5);cprintf("Project Name:");delay(DELAY);
  gotoxy(startx-15,starty+6);cprintf("Subject Code:");delay(DELAY);
  gotoxy(startx-15,starty+7);cprintf("Year:");delay(DELAY);
  gotoxy(startx-15,starty+8);cprintf("Coded by:");delay(DELAY);
  gotoxy(startx-15,starty+9);cprintf("Instructor:");delay(DELAY);
  textcolor(WHITE);
  gotoxy(startx+2,starty+5);cprintf("Number Systems Operations");delay(DELAY);
  gotoxy(startx+2,starty+6);cprintf("Computer Architecture w/ Assembly Language");delay(DELAY);
  gotoxy(startx+2,starty+7);cprintf("1st Year");delay(DELAY);
  gotoxy(startx+2,starty+8);cprintf("Arman Ortega a.k.a mIndH4Ck++");delay(DELAY);
  gotoxy(startx+2,starty+9);cprintf("Mr. Francis Baylon");delay(DELAY);
  getch();
}
void splash_screen(void){
  int maxX,maxY;
    initgraphix();
    maxX=getmaxx();
    maxY=getmaxy();

  /* shadow */
  setcolor(DARKGRAY);
  settextstyle(0,HORIZ_DIR,1);

  outtextxy(maxX/4+51,maxY/2+2,"Number Systems Operations v1.0");
  /* outline text */
  setcolor(WHITE);
  outtextxy(maxX/4+50,maxY/2,"Number Systems Operations v1.0");

  setcolor(DARKGRAY);
  line(maxX/4,maxY/2+12,maxX/4+700,maxY/2+12);
  line(maxX/4+40,maxY/2-50,maxX/4+40,maxY/2+40);
  /*getch();*/
  /*exit(1);*/
  delay(2000);
  destroygraphix();
}