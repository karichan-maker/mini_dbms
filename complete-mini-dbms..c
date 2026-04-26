//mini database management system for school
//MINI DBMS PROJECT
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define FULL_NAME "student.dat"
struct student {
    int roll;
    char name[20];
    float marks;

};
void addStudent(){
    FILE *fp=fopen(FULL_NAME, "ab");
    struct student s;
    printf("enter roll\n");
    scanf("%d",&s.roll);
    printf("enter the name\n");
    scanf("%s",s.name);
    printf("enter the marks\n");
    scanf("%f",&s.marks);
    fwrite(&s,sizeof(s),1,fp);
    fclose(fp);
    printf("added student successfully!\n");

}
void viewStudent(){


}
void searchStudent(){

}
void updateStudent(){

}
void delateStudent(){

}
int main(){

    int choice ;
    while(1){
        printf(" 1.Add student \n2. view stident \n 3.View student \n 4. Update student \n 5.Delate student \n 6.Exit\n ");
printf("enter your choice :");
scanf("%d",&choice);
switch(choice){
    case 1:addStudent();
    break;
    case 2:viewStudent();
    break;
    case 3:searchStudent();
    break;
    case 4: updateStudent();
    break;
    case 5:delateStudent();
    break;
    case 6:exit(0);
    default: 
    printf("enter only from above option");
}
        }
    return 0;
}