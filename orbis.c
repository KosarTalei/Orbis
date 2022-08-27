#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
//---------------------Do Not Change This!---------------------
char c; //the input character
int input_count = 0;
void mymain(); //your main() method will be implemented later

DWORD WINAPI keypress_callback( LPVOID lpParam ){
  while(1) {
    c = getch();
    if(c == 'q')  //press q to exit
      exit(0);
    input_count ++;
  }
  return 0;
}
void starter(){
  HANDLE thread = CreateThread(NULL, 0, keypress_callback, NULL, 0, NULL);
  return;
}
int click_cheak=0,point=0,protect=3,myindex=0,i=0,count_num=0,num=1;
char now_disk[1000];
char space[10][6];
int main() {
  starter();
  mymain();
  return 0;
}
//---------------------Do Not Change This!---------------------

//Assume that the latest input character is in variable c 
//You can check the input_count to check if there was any key press.

void test(void){
    int t[200];//مقدار دیسک
    int test=0;
}

char random_disk(int i){
    char result;
    srand ( time(NULL)+i );
    int output=rand() % 10 ;
    //printf("%d",output);
    switch (output){
        case 0:result='*';return result;break;
        case 1:result='#';return result;break;
        case 2:result='$';return result;break;
        case 3:result='~';return result;break;
        case 4:result='+';return result;break;
        case 5:result='=';return result;break;
        case 6:result='|';return result;break;
        case 7:result='?';return result;break;
        case 8:result='2';return result;break;
        case 9:result='4';return result;break;
    }
} 

int printmenu(void){

  putchar('\n');
	printf("Menu\n\n");
	printf("1. New game\n");
	printf("2. Test\n");
	printf("3. Exit\n");
  printf("you have one second!\n");
  Sleep(1000);
  char choice=c;
	switch (choice){
		case '1' :click_cheak=input_count;printf("Start!");return 1;//call function
      break;
      case '2' :click_cheak=input_count;test();
        break;
    case '3' :click_cheak=input_count;printf("Goodbye! press q key\n");
      break; 
    /*default :
      printf("Wrong Choice.quitting!\n");
      break;
      */
 		    }
}

void print(void){
  for(int i=0;i<10;i++){//print disk
    for(int j=0;j<6;j++){
      printf("%c",space[i][j]);} 
      putchar('\n');      
    }
  printf("______" "\n");putchar('\n');
  printf("point: %d\n",point);
  putchar('\n');
  printf("protect: %d\n",protect);
  Sleep(3000);
}

void mymain(){//this code is for your testing:
  if(printmenu()==1){
  printf("You can press l(Left) , r(Right) or e(Exit)keys\n");
  Sleep(2000);
  int row=10,cloumn=6;
  char click[1000];
  char wall;

  for(int i=0;i<row;i++){
    for(int j=0;j<cloumn;j++)
      space[i][j]=' ';}

    while(1){//input_count=1,c=1
      //printf("%d -th input was %c\n",input_count,c);
      int fact=0;
      if(input_count==click_cheak+1){// new click
        fact++;
        click_cheak=input_count;
        click[input_count]=c;
      if(click[input_count]=='l'){wall='*';}
      else if(click[input_count]=='r'){wall='#';}
      else if(click[input_count]='e'){
        printf("Total point: %d\n",point);
        //printmenu();
        }
      }
      now_disk[i]=random_disk(i);//new disk
      if(i>0 && i<=9){/* Move elements up */
        int temp=now_disk[i];
        for (int j = i-1; j >= 0; j--){
		      now_disk[j+1] = now_disk[j];
          }
        now_disk[0]=temp;//low disk=new disk
        }
        
      myindex=0;
      for(int k=9;k>=9-i;k--){//print down to up
        space[k][0]='*';
        space[k][5]='#';
        space[k][2]=now_disk[myindex];
        space[k][3]=now_disk[myindex];
        myindex++;}

      if(myindex==10){//full
        Sleep(1000);
        if(input_count!=click_cheak+1 || input_count==0){//new click
          if(protect==0){
            printf("game over!" "\n");putchar('\n');
            printf("Total point: %d\n",point);
            Sleep(1000);
            printmenu();
            }
          else{
            protect--;
            jazab();
            }
        }
      }
      if(fact!=0){//new click
        myindex=myindex-1;
        cheak(wall);// new click , hit the last disk
        }
      print();

      i++;
      system("cls");
      Sleep(2000);
    }
  }
}

void normal_disk(int wall){
  if(count_num>0){
    count_num--;
    if(count_num==0)
      num=1;}//ضریب

  space[9-myindex][2]=' ';space[9-myindex][3]=' ';//delete disk
  if(now_disk[myindex]==wall){
    point+=num;}
  else if(protect>0){
    protect--;}
  else printf("game over" "\n");printmenu();
}

void yek(char wall){
  if(count_num>0){count_num--;}//ضریب
  point+=num;
  space[9-myindex][2]=' ';space[9-myindex][3]=' ';//delet disk
  for(int i=0;i<9;i++){//?
    int i=myindex-1;
    for(;i>=0;i--){
      point+=num;
      cheak(i,wall);}
  }
}

void life(void){
  if(protect<3)protect++;
  space[9-myindex][2]=' ';space[9-myindex][3]=' ';
}

void multiply(char wall){
    space[9-myindex][2]=' ';space[9-myindex][3]=' ';//delet disk
    count_num+=3;//3 times or more
}

void mobham(void){
  for(int i=1;;i++){
    char k;
    k=random_disk(myindex+i);
    if( k !='?'){
      space[9-myindex][2]='k';space[9-myindex][3]='k';//new disk
    }
  }
}

void quit(void){//?
  space[9-myindex][2]=' ';space[9-myindex][3]=' ';
  Sleep(3000);
}

void jazab(void){
  space[9-myindex][2]=' ';space[9-myindex][3]=' ';//حذف دیسک جذاب

  for(int i=myindex-1;i<=0;i--){//مابقی دیسک ها
    while(now_disk[i]!='='){// غیر جذاب
      if(now_disk[i]=='*' || now_disk[i]=='#'){
        point++;
        space[9-i][2]=' ';
        space[9-i][3]=' ';}

      else{//random wall
        char wall;
        srand ( time(NULL)+i );
        int output=rand() % 2 ;
        switch (output){
          case 0:wall='*';cheak(wall);break;
          case 1:wall='#';cheak(wall);break;
          }
        }
      }
    if(i<0){//empty
      for(int i=0;i<5;i++){//5 new disk
      now_disk[i]=random_disk(i);
            int myindex=0;
      for(int k=9;k>=9-i;k--){
        space[k][0]='*';
        space[k][5]='#';
        space[k][2]=now_disk[myindex];
        space[k][3]=now_disk[myindex];
        myindex++;}
        }
      }
  }
}

void cheak(char wall){

  if(count_num<0){count_num=0;num=1;}

  switch (now_disk[myindex]){//last disk
    case '*':
    case '#':normal_disk(wall);break;
    case '$':yek(wall);break;
    case '+':life();break;
    case '2':num=2;multiply(wall);break;
    case '4':num=4;multiply(wall);break;
    case '?':mobham();break;
    case '|':quit();break;
    case '~':jazab();break;
    case '=':space[9-myindex][2]=' ';space[9-myindex][3]=' ';break;//delet disk
  }
}