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
FILE *fp=fopen(FULL_NAME,"rb");
struct student s;
printf(" _____student list _____\n");
while(fread(&s,sizeof(s),1,fp));
{
    printf("roll=%d \n name =%s \n marks=%.2f\n",s.roll,s.name,s.marks);
}fclose(fp);

}
void searchStudent(){
    FILE *fp;
    fp=fopen(FULL_NAME,"rb");
    struct student s;
    int roll,found=0;
    printf("enter the roll number for search studen\n");
    scanf("%d",&roll);

    while(fread(&s,sizeof(s),1,fp))
    {

        if(s.roll==roll){
            printf("\n student found \n");
            printf("name =%s\nmarks=%.2f\n",s.name,s.marks);
            found=1;
            break;
        }
    }
    if(!found){
        printf("student not found!!\n ");

    }
}
void updateStudent()
{

    FILE *fp=fopen(FULL_NAME,"rb+");
    struct student s;
    int roll,found=0;
    printf("Enter the roll to update the student ");
    scanf("%d",&roll); 
        while(fread(&s,sizeof(s),1,fp))
{
        if(s.roll==roll){
        printf("enter new name \n");
        scanf("%s",s.name);
        printf("enter new marks\n");
        scanf("%f",&s.marks);
        fseek(fp,-sizeof(s),SEEK_CUR);
        fwrite(&s,sizeof(s),1,fp);
        printf("student data is successfully updated\n ");
        found=1;
        break;

        }
    }
        if(!found)
        {
        printf(" Student not found !!");
        }
        fclose(fp);
    
}

void delateStudent(){
    
    FILE  *fp=fopen(FULL_NAME,"rb");
    FILE  *temp=fopen("temp.dat","wb");
    struct student s;
    int roll,found=0;
    printf("enter the roll no. for delate the that student data");
    scanf("%d",&roll);
    while(fread(&s,sizeof(s),1,fp)){
        if(s.roll==roll){
            found=1;
        }
        else{ 
        fwrite(&s,sizeof(s),1,temp);
        }
        
    }

fclose(fp);
fclose(temp);
remove(FULL_NAME);
rename("temp.dat",FULL_NAME);
    if(found)
        printf("student delated !");
   else 
        printf("student not found ");


}

int main(){

    int choice ;
    while(1){
        printf(" 1.Add student \n2. view stident \n 3.search  student \n 4. Update student \n 5.Delate student \n 6.Exit\n ");
printf("enter your choice :");
scanf("%d",&choice);
switch(choice){
    case 1:addStudent();
    break;
    case 2:viewStudent();
    break;
    case 3:searchStudent();
    break;
    case 4:updateStudent();
    break;
    case 5:delateStudent();
    break;
    case 6:exit(0);
    default: 
    printf("invalid choice !");
}
}
    return 0;
}