#include<stdio.h>
#include<string.h>

void admin_panel();
void teachers_panel(char u_name[20]);
void student_panel(char u_name[20]);

//check ct marks
void check_marks(char u_name[20])
{
    system("cls");
    struct marks
    {
        char roll[10];
        char course_code[10];
        char mark[5];
    } m;

    struct student
    {
        char first_name[25];
        char last_name[25];
        char username[20];
        char password[10];
        char roll[10];
        char dept[10];
        char email[50];
        char mobile[12];
    } s;

    FILE *mf,*sf;
    mf=fopen("marks.txt","r");
    sf=fopen("student.txt","r");
    char r[10];
    int z=0;

    while(fread(&s,sizeof(s),1,sf))
    {
        if(strcmp(u_name,s.username)==0)
        {
            strcpy(r,s.roll);  //find the roll of the given username
            break;
        }
    }

    while(fread(&m,sizeof(m),1,mf))
    {
        if(strcmp(m.roll,r)==0)
        {
            z=1; //marks added to this roll
            printf("%s : %s\n",m.course_code,m.mark);
        }
    }

    if(z==0)
    {
        printf("\nNo marks provided!!!\n");
    }

    int a;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&a);

    while(a!=0)
    {
        printf("\nWrong input!!!\n");
        printf("\nEnter 0 to go back... ");
        scanf("%d",&a);
    }
    if(a==0)
    {
        student_panel(u_name);
    }
}

//student panel
void student_panel(char u_name[20])
{
    system("cls");
    printf("<=== Student Panel ===>\n\n");
    printf("\t1.Check CT marks\n");
    printf("\t0.Go to home\n");
    int ch;
    printf("\nEnter your choice(serial no): ");
    scanf("%d",&ch);
    if(ch==1)
    {
        check_marks(u_name);
    }
    if(ch==0)
    {
        system("cls");
        main();
    }
}

//student login
void s_login()
{
    system("cls");
    printf("<=== Log in to Your Account ===>\n\n");
    struct student
    {
        char first_name[25];
        char last_name[25];
        char username[20];
        char password[10];
        char roll[10];
        char dept[10];
        char email[50];
        char mobile[12];
    } s;

    char u_name[50],pw[10];
    int z=0,y=0;

    printf("Enter username: ");
    scanf("%s",u_name);
    printf("Enter password: ");
    scanf("%s",pw);
    printf("\n");

    FILE *sf;
    sf=fopen("student.txt","r");
    if(sf==NULL)
    {
        printf("file not found");
    }

    while(fread(&s,sizeof(s),1,sf))
    {

        if(strcmp(u_name,s.username)==0)//user found
        {
            z=1;
            if(strcmp(pw,s.password)==0)// password matched
            {

                printf("Log in successful.");
                student_panel(u_name);
                break;
            }
            else
            {
                y=1;
                printf("Incorrect password!!!");
                break;
            }
        }
    }
    fclose(sf);

    if(z==0)
    {
        printf("User not found!!!");
    }

    if(z==0 || y==1)
    {
        int a;
        printf("\nEnter 0 to go back... ");
        scanf("%d",&a);

        while(a!=0)
        {
            printf("\nWrong input!!!\n");
            printf("\nEnter 0 to go back... ");
            scanf("%d",&a);
        }

        if(a==0)
        {
            system("cls");
            main();
        }
    }
}
//total student
void s_count(char u_name[20])
{
    system("cls");
    struct student
    {
        char first_name[25];
        char last_name[25];
        char username[20];
        char password[10];
        char roll[10];
        char dept[10];
        char email[50];
        char mobile[12];
    } s;

    FILE *sf;
    sf=fopen("student.txt","r");

    int c=0;
    while(fread(&s,sizeof(s),1,sf))
    {
        c++; //counting students
    }
    printf("Total students: %d",c);

    fclose(sf);

    int a;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&a);

    if(a==0)
    {
        teachers_panel(u_name);
    }

}

//find student by first name
void find_by_name(char u_name[20])
{
    system("cls");
    printf("<=== Find Student by First Name ===>\n\n");
    struct student
    {
        char first_name[25];
        char last_name[25];
        char username[20];
        char password[10];
        char roll[10];
        char dept[10];
        char email[50];
        char mobile[12];
    } s;

    FILE *sf;
    sf=fopen("student.txt","r");
    char n[25];
    printf("Enter student's first name: ");
    fflush(stdin);
    gets(n);

    int z=0;
    while(fread(&s,sizeof(s),1,sf))
    {
        if(strcmp(n,s.first_name)==0)
        {
            z=1;
            printf("\nName %7c %s %s\n",':',s.first_name,s.last_name);
            printf("Roll %7c %s\n",':',s.roll);
            printf("Department %1c %s\n",':',s.dept);
            printf("Email %6c %s\n",':',s.email);
            printf("Mobile no %2c %s\n\n",':',s.mobile);
            break;
        }
    }
    fclose(sf);

    if(z==0)
    {
        printf("\nName not found!!!\n");
    }
    int a;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&a);

    while(a!=0)
    {
        printf("\nWrong input!!!\n");
        printf("\nEnter 0 to go back... ");
        scanf("%d",&a);
    }

    if(a==0)
    {
        teachers_panel(u_name);
    }
}

//find student by roll
void find_by_roll(char u_name[20])
{
    system("cls");
    printf("<=== Find Student by Roll ===>\n\n");
    struct student
    {
        char first_name[25];
        char last_name[25];
        char username[20];
        char password[10];
        char roll[10];
        char dept[10];
        char email[50];
        char mobile[12];
    } s;

    FILE *sf;
    sf=fopen("student.txt","r");
    char r[10];
    printf("Enter student's roll: ");
    scanf("%s",r);

    int z=0;
    while(fread(&s,sizeof(s),1,sf))
    {
        if(strcmp(r,s.roll)==0)
        {
            z=1;
            printf("\nName %7c %s %s\n",':',s.first_name,s.last_name);
            printf("Roll %7c %s\n",':',s.roll);
            printf("Department %1c %s\n",':',s.dept);
            printf("Email %6c %s\n",':',s.email);
            printf("Mobile no %2c %s\n\n",':',s.mobile);
            break;
        }
    }
    fclose(sf);

    if(z==0)
    {
        printf("\nRoll not found!!!\n");
    }
    int a;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&a);

    while(a!=0)
    {
        printf("\nWrong input!!!\n");
        printf("\nEnter 0 to go back... ");
        scanf("%d",&a);
    }

    if(a==0)
    {
        teachers_panel(u_name);
    }

}
//update ct marks
void u_ct_mark(char u_name[20])
{
    system("cls");
    printf("<=== Update CT Marks ===>\n\n");
    struct course
    {
        char username[20];
        char course_1[10];
        char course_2[10];
    } c;

    struct marks
    {
        char roll[10];
        char course_code[10];
        char mark[5];
    } m;

    FILE *cf,*mf;
    cf=fopen("course.txt","r");
    mf=fopen("marks.txt","r+");

    char code[10];
    int z=0,y=0,x=0;
    while(fread(&c,sizeof(c),1,cf))
    {
        if(strcmp(u_name,c.username)==0)
        {
            z=1; //teacher found
            printf("Enter course code(ex:cse-1208): ");
            scanf("%s",code);

            if((strcmp(code,c.course_1)==0) || strcmp(code,c.course_2)==0)
            {
                char r[10];
                strcpy(m.course_code,code);
                y=1;   //this course is assigned to this teacher
                printf("Enter roll: ");
                scanf("%s",r);

                while(fread(&m,sizeof(m),1,mf))
                {
                    if(strcmp(m.roll,r)==0)
                    {
                        x=1;  //roll found
                        printf("Enter new CT mark: ");
                        scanf("%s",m.mark);

                        fseek(mf,-sizeof(m),SEEK_CUR); //pointing to required data
                        fwrite(&m,sizeof(m),1,mf);

                        printf("\nmarks updated successfully...\n");

                        break;
                    }
                }

            }
        }
    }

    if(z==0)
    {
        printf("\nNo course assigned to you!!!\n");
    }
    else if(y==0)
    {
        printf("\nThis course is not for you!!!\n");
    }
    else if(x==0)
    {
        printf("\nRoll not found !!!\n");
    }

    fclose(cf);
    fclose(mf);

    int a;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&a);

    while(a!=0)
    {
        printf("\nWrong input!!!\n");
        printf("\nEnter 0 to go back... ");
        scanf("%d",&a);
    }

    if(a==0)
    {
        teachers_panel(u_name);
    }
}

//provide ct marks to students
void p_ct_mark(char u_name[20])
{
    system("cls");
    printf("<=== Provide CT Marks ===>\n\n");
    struct course
    {
        char username[20];
        char course_1[10];
        char course_2[10];
    } c;

    struct student
    {
        char first_name[25];
        char last_name[25];
        char username[20];
        char password[10];
        char roll[10];
        char dept[10];
        char email[50];
        char mobile[12];
    } s;

    struct marks
    {
        char roll[10];
        char course_code[10];
        char mark[5];
    } m;

    FILE *cf,*sf,*mf;
    cf=fopen("course.txt","r");
    sf=fopen("student.txt","r");
    mf=fopen("marks.txt","a");

    char code[10];
    int z=0,y=0,x=0;
    while(fread(&c,sizeof(c),1,cf))
    {
        if(strcmp(u_name,c.username)==0)
        {
            z=1; //teacher found
            printf("Enter course code(ex:cse-1208): ");
            scanf("%s",code);

            if((strcmp(code,c.course_1)==0) || strcmp(code,c.course_2)==0)
            {
                strcpy(m.course_code,code);
                y=1; //this course is assigned to this teacher
                printf("Enter roll: ");
                scanf("%s",m.roll);

                while(fread(&s,sizeof(s),1,sf))
                {
                    if(strcmp(m.roll,s.roll)==0)
                    {
                        x=1; // roll found
                        printf("Enter CT mark: ");
                        scanf("%s",m.mark);

                        fwrite(&m,sizeof(m),1,mf);

                        printf("\nmarks provided successfully...\n");

                        break;
                    }
                }

            }
        }
    }

    if(z==0)
    {
        printf("\nNo course assigned to you!!!\n");
    }
    else if(y==0)
    {
        printf("\nThis course is not for you!!!\n");
    }
    else if(x==0)
    {
        printf("\nRoll not found !!!\n");
    }

    fclose(cf);
    fclose(sf);
    fclose(mf);

    int a;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&a);

    while(a!=0)
    {
        printf("\nWrong input!!!\n");
        printf("\nEnter 0 to go back... ");
        scanf("%d",&a);
    }

    if(a==0)
    {
        teachers_panel(u_name);
    }
}
//teachers panel
void teachers_panel(char u_name[20])
{
    system("cls");

    // creating teacher's option
    printf("<=== Teacher's Panel ===>\n\n");
    printf("\t1.Provide CT marks\n");
    printf("\t2.Update CT marks\n");
    printf("\t3.Find student by roll\n");
    printf("\t4.Find student by first name\n");
    printf("\t5.Total students\n");
    printf("\t0.Go to home\n");

    int ch;
    printf("\nEnter your choice(serial no): ");
    scanf("%d",&ch);

    if(ch==1)
    {
        p_ct_mark(u_name);
    }
    else if(ch==2)
    {
        u_ct_mark(u_name);
    }
    else if(ch==3)
    {
        find_by_roll(u_name);
    }
    else if(ch==4)
    {
        find_by_name(u_name);
    }
    else if(ch==5)
    {
        s_count(u_name);
    }
    else if(ch==0)
    {
        system("cls");
        main();
    }
}

//teacher's login
void t_login()
{
    system("cls");
    printf("<=== Log in to Your Account ===>\n\n");
    struct teacher
    {
        char name[50];
        char username[20];
        char password[10];
        char dept[10];
        char email[50];
        char mobile[12];
    } t;

    char u_name[50],pw[10];
    int z=0,y=0;

    printf("Enter username: ");
    scanf("%s",u_name);
    printf("Enter password: ");
    scanf("%s",pw);
    printf("\n");

    FILE *tf;
    tf=fopen("teacher.txt","r");
    if(tf==NULL)
    {
        printf("file not found");
    }

    while(fread(&t,sizeof(t),1,tf))
    {

        if(strcmp(u_name,t.username)==0)//user found
        {
            z=1;
            if(strcmp(pw,t.password)==0)// password matched
            {

                printf("Log in successful.");
                teachers_panel(u_name);
                break;
            }
            else
            {
                y=1; //user found but incorrect password
                printf("Incorrect password!!!");
                break;
            }
        }
    }
    fclose(tf);

    if(z==0)
    {
        printf("User not found!!!");
    }
    if(z==0 || y==1) //noting matched
    {
        int a;
        printf("\nEnter 0 to go back... ");
        scanf("%d",&a);

        while(a!=0)
        {
            printf("\nWrong input!!!\n");
            printf("\nEnter 0 to go back... ");
            scanf("%d",&a);
        }

        if(a==0)
        {
            system("cls");
            main();
        }
    }


}

//update courses
void c_update()
{
    system("cls");
    printf("<=== Course Update ===>\n\n");
    struct course
    {
        char username[20];
        char course_1[10];
        char course_2[10];
    } c;
    char u[20];
    printf("Enter Teacher's username: ");
    scanf("%s",u);

    FILE *crs;
    crs=fopen("course.txt","r+");
    int z=0;

    while(fread(&c,sizeof(c),1,crs))
    {
        if(strcmp(c.username,u)==0)
        {
            z=1;
            printf("Enter new course code-1(ex:cse-1207): ");
            scanf("%s",c.course_1);
            printf("Enter new course code-2(ex:cse-1207): ");
            scanf("%s",c.course_2);

            fseek(crs,-sizeof(c),SEEK_CUR); //pointing to required data
            fwrite(&c,sizeof(c),1,crs);

            printf("\nCourse updated successfully...\n");
            break;
        }
    }

    fclose(crs);

    if(z==0)
    {
        printf("\nUser not found!!!\n");
    }

    int a;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&a);

    while(a!=0)
    {
        printf("\nWrong input!!!\n");
        printf("\nEnter 0 to go back... ");
        scanf("%d",&a);
    }

    if(a==0)
    {
        admin_panel();
    }

}

//course assignment
void courses()
{
    system("cls");
    printf("<=== Course Assignment ===>\n\n");
    struct course
    {
        char username[20];
        char course_1[10];
        char course_2[10];
    } c;

    struct teacher
    {
        char name[50];
        char username[20];
        char password[10];
        char dept[10];
        char email[50];
        char mobile[12];
    } td;

    char u[20];
    printf("Enter Teacher's username: ");
    scanf("%s",u);

    FILE *t,*crs;
    t=fopen("teacher.txt","r");
    crs=fopen("course.txt","r");
    int z=0,y=0;

    while(fread(&c,sizeof(c),1,crs)) // check whether courses has already been assigned
    {
        if(strcmp(c.username,u)==0)
        {
            y=1;  //courses already assigned
            printf("\nCourse has already been assigned to %s\n",u);
            break;
        }
    }
    fclose(crs);

    if(y==0) // no course assigned
    {
        strcpy(c.username,u);
        crs=fopen("course.txt","a");

        while(fread(&td,sizeof(td),1,t))
        {
            if(strcmp(c.username,td.username)==0)
            {
                z=1; //this teacher's account exist
                printf("Enter course code-1(ex:cse-1207): ");
                scanf("%s",c.course_1);
                printf("Enter course code-2(ex:cse-1207): ");
                scanf("%s",c.course_2);
                fwrite(&c,sizeof(c),1,crs);

                printf("\nCourse added successfully...\n");
                break;
            }
        }
        fclose(crs);
    }

    fclose(t);


    if(z==0 && y==0)
    {
        printf("\nUser not found!!!\n");
    }

    int a;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&a);

    while(a!=0)
    {
        printf("\nWrong input!!!");
        printf("\nEnter 0 to go back... ");
        scanf("%d",&a);
    }

    if(a==0)
    {
        admin_panel();
    }

}

// delete student's information
void s_delete()
{
    system("cls");
    printf("<=== Delete Student's information ===>\n\n");

    struct student
    {
        char first_name[25];
        char last_name[25];
        char username[20];
        char password[10];
        char roll[10];
        char dept[10];
        char email[50];
        char mobile[12];
    } sd;

    char r[20];
    printf("Enter roll which you want to delete: ");
    scanf("%s",r);

    FILE *fd,*t;
    fd=fopen("student.txt","r");
    t=fopen("temp.txt","a");  //create an temporary file to copy student's data to it except which data is needed to delete

    int z=0;
    while(fread(&sd,sizeof(sd),1,fd))
    {
        if(strcmp(r,sd.roll)==0)
        {
            z=1; //roll found which needed to be deleted
        }
        else
        {
            fwrite(&sd,sizeof(sd),1,t);
        }
    }

    fclose(fd);
    fclose(t);

    remove("student.txt"); //delete "student.txt" file
    rename("temp.txt","student.txt");  //rename temporary file as "student.txt"

    if(z==0)
    {
        printf("\nRoll not found!!!\n");
    }
    else
    {
        printf("\nInformation deleted successfully!!!\n");
    }

    int a;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&a);

    while(a!=0)
    {
        printf("\nWrong input!!!\n");
        printf("\nEnter 0 to go back... ");
        scanf("%d",&a);
    }

    if(a==0)
    {
        admin_panel();
    }
}

//delete teacher's information
void t_delete()
{
    system("cls");
    printf("<=== Delete Teacher's information ===>\n\n");
    struct teacher
    {
        char name[50];
        char username[20];
        char password[10];
        char dept[10];
        char email[50];
        char mobile[12];
    } td;

    char u[20];
    printf("Enter username which you want to delete: ");
    scanf("%s",u);

    FILE *fd,*t;
    fd=fopen("teacher.txt","r");
    t=fopen("temp.txt","a"); //create an temporary file to copy teacher's data to it except which data is needed to delete

    int z=0;
    while(fread(&td,sizeof(td),1,fd))
    {
        if(strcmp(u,td.username)==0)
        {
            z=1; //username found which needed to be deleted
        }
        else
        {
            fwrite(&td,sizeof(td),1,t); //copying data to temporary file
        }
    }

    fclose(fd);
    fclose(t);

    remove("teacher.txt"); //delete "techer.txt" file
    rename("temp.txt","teacher.txt"); //rename temporary file as "teacher.txt"

    if(z==0)
    {
        printf("\nUsername not found!!!\n");
    }
    else
    {
        printf("\nInformation deleted successfully!!!\n");
    }

    int a;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&a);

    while(a!=0)
    {
        printf("\nWrong input!!!\n");
        printf("\nEnter 0 to go back... ");
        scanf("%d",&a);
    }

    if(a==0)
    {
        admin_panel();
    }

}

//update student'information
void s_update()
{
    system("cls");
    printf("<=== Update Student's Information ===>\n\n");

    struct student
    {
        char first_name[25];
        char last_name[25];
        char username[20];
        char password[10];
        char roll[10];
        char dept[10];
        char email[50];
        char mobile[12];
    } su;

    char u[20];
    printf("Enter student's username: ");
    scanf("%s",u);

    FILE *f;
    f=fopen("student.txt","r+");

    int z=0;
    while(fread(&su,sizeof(su),1,f))
    {
        if(strcmp(u,su.username)==0)
        {
            z=1;  //user found

            printf("New first name: ");
            fflush(stdin);
            gets(su.first_name);
            printf("New last name: ");
            fflush(stdin);
            gets(su.last_name);
            printf("New roll: ");
            scanf("%s",su.roll);
            printf("New password: ");
            scanf("%s",su.password);
            printf("New department: ");
            scanf("%s",su.dept);
            printf("New e-mail: ");
            scanf("%s",su.email);
            printf("New mobile no.: ");
            scanf("%s",su.mobile);

            fseek(f,-sizeof(su),SEEK_CUR);//pointing to the required data
            fwrite(&su,sizeof(su),1,f);
            break;
        }
    }
    fclose(f);

    if(z==0)
    {
        printf("\nUsername not found!!!\n");
    }
    else
    {
        printf("\nInformation updated successfully!!!\n");
    }

    int a;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&a);

    while(a!=0)
    {
        printf("\nWrong input!!!\n");
        printf("\nEnter 0 to go back... ");
        scanf("%d",&a);
    }

    if(a==0)
    {
        admin_panel();
    }

}


// update teacher's information
void t_update()
{
    system("cls");
    printf("<=== Update Teacher's Information ===>\n\n");

    struct teacher
    {
        char name[50];
        char username[20];
        char password[10];
        char dept[10];
        char email[50];
        char mobile[12];
    } tu;

    char u[20];
    printf("Enter teacher's username: ");
    scanf("%s",u);

    FILE *f;
    f=fopen("teacher.txt","r+");

    int z=0;
    while(fread(&tu,sizeof(tu),1,f))
    {
        if(strcmp(u,tu.username)==0)
        {
            z=1; //user found

            printf("New full name: ");
            fflush(stdin);
            gets(tu.name);
            printf("New password: ");
            scanf("%s",tu.password);
            printf("New department: ");
            scanf("%s",tu.dept);
            printf("New e-mail: ");
            scanf("%s",tu.email);
            printf("New mobile no.: ");
            scanf("%s",tu.mobile);

            fseek(f,-sizeof(tu),SEEK_CUR); //pointing to the required data
            fwrite(&tu,sizeof(tu),1,f);
            break;
        }
    }
    fclose(f);

    if(z==0)
    {
        printf("Username not found!!!\n\n");
    }
    else
    {
        printf("Information updated successfully!!!\n");
    }

    int a;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&a);

    while(a!=0)
    {
        printf("\nWrong input!!!\n");
        printf("\nEnter 0 to go back... ");
        scanf("%d",&a);
    }

    if(a==0)
    {
        admin_panel();
    }

}

// show student's information
void s_info()
{
    system("cls");
    struct student
    {
        char first_name[25];
        char last_name[25];
        char username[20];
        char password[10];
        char roll[10];
        char dept[10];
        char email[50];
        char mobile[12];
    } s_inf;

    printf("%-10s %-30s %-20s %-15s %-15s %-15s %-40s %s","Sl_No","Name","Username","Password","Roll","Department","E-mail","Mobile No.\n");


    FILE *sf=fopen("student.txt","r");

    int c=0;
    while(fread(&s_inf,sizeof(s_inf),1,sf))
    {
        char name[50];
        strcpy(name,s_inf.first_name);
        strcat(name," ");
        strcat(name,s_inf.last_name);
        c++;
        printf("%-10d %-30s %-20s %-15s %-15s %-15s %-40s %s\n",c,name,s_inf.username,s_inf.password,s_inf.roll,s_inf.dept,s_inf.email,s_inf.mobile);
//        printf("Username %3c %s\n",':',s_inf.username);
//        printf("Name %7c %s %s\n",':',s_inf.first_name,s_inf.last_name);
//        printf("Password %3c %s\n",':',s_inf.password);
//        printf("Roll %7c %s\n",':',s_inf.roll);
//        printf("Department %1c %s\n",':',s_inf.dept);
//        printf("Email %6c %s\n",':',s_inf.email);
//        printf("Mobile no %2c %s\n\n",':',s_inf.mobile);
    }
    fclose(sf);

    int a;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&a);

    while(a!=0)
    {
        printf("\nWrong input!!!\n");
        printf("\nEnter 0 to go back... ");
        scanf("%d",&a);
    }

    if(a==0)
    {
        admin_panel();
    }


}

//check duplicate of student
int s_duplicate(char r[10])
{
    struct student
    {
        char first_name[25];
        char last_name[25];
        char username[20];
        char password[10];
        char roll[10];
        char dept[10];
        char email[50];
        char mobile[12];
    } s;

    int d=0;
    FILE *sf;
    sf=fopen("student.txt","r");

    while(fread(&s,sizeof(s),1,sf))
    {
        if(strcmp(r,s.roll)==0)
        {
            d=1; //duplicate data
            break;
        }
    }
    fclose(sf);
    return d;
}

//create student account
void s_account()
{
    struct student
    {
        char first_name[25];
        char last_name[25];
        char username[20];
        char password[10];
        char roll[10];
        char dept[10];
        char email[50];
        char mobile[12];
    } s;

    int a;
    system("cls");
    printf("<=== Create Student's Account ===>\n\n");

    // getting student's information
    printf("First name: ");
    fflush(stdin);
    gets(s.first_name);
    printf("Last name: ");
    fflush(stdin);
    gets(s.last_name);
    printf("Username: ");
    scanf("%s",s.username);
    printf("Password: ");
    scanf("%s",s.password);
    printf("Roll: ");
    scanf("%s",s.roll);
    printf("Department: ");
    scanf("%s",s.dept);
    printf("E-mail: ");
    scanf("%s",s.email);
    printf("Mobile no.: ");
    scanf("%s",s.mobile);

    int d;
    d=s_duplicate(s.roll);  //check duplicate

    if(d==0) //no duplicate
    {
        FILE *sd;
        sd=fopen("student.txt","a");
        fwrite(&s,sizeof(s),1,sd);

        fclose(sd);

        printf("Account created successfully!!!\n\n");
    }
    else //duplicate roll
    {
        printf("\n%s is already added!!!\n\n",s.roll);
    }

    printf("1. Create another account?\n");
    printf("0. Go back\n\n");
    printf("Enter your choice(serial no.): ");
    scanf("%d",&a);

    if(a==1)
    {
        s_account(); //add another data
    }
    else
    {
        while(a!=0)
        {
            printf("\nWrong input!!!\n");
            printf("\nEnter 0 to go back... ");
            scanf("%d",&a);
        }
    }

    if(a==0)
    {
        admin_panel();
    }


}

//show teacher's information
void t_info()
{
    system("cls");
    printf("<=== Teacher's Information ===>\n\n");
    struct teacher
    {
        char name[50];
        char username[20];
        char password[10];
        char dept[10];
        char email[50];
        char mobile[12];
    } t_inf;

    printf("%-10s %-30s %-20s %-20s %-20s %-30s %s","Sl_No","Name","Username","Password","Department","E-mail","Mobile No.\n");

    FILE *tf=fopen("teacher.txt","r");

    int c=0;
    while(fread(&t_inf,sizeof(t_inf),1,tf))
    {
        c++;
        printf("%-10d %-30s %-20s %-20s %-20s %-30s %s\n",c,t_inf.name,t_inf.username,t_inf.password,t_inf.dept,t_inf.email,t_inf.mobile);
    }
    fclose(tf);

    int a;
    printf("\nEnter 0 to go back... ");
    scanf("%d",&a);

    while(a!=0)
    {
        printf("\nWrong input!!!\n");
        printf("\nEnter 0 to go back... ");
        scanf("%d",&a);
    }

    if(a==0)
    {
        admin_panel(); //go to admin menu
    }


}

//check duplicate of teacher
int t_duplicate(char u_name[20])
{
    struct teacher
    {
        char name[50];
        char username[20];
        char password[10];
        char dept[10];
        char email[50];
        char mobile[12];
    } t;

    int d=0;
    FILE *tf;
    tf=fopen("teacher.txt","r");

    while(fread(&t,sizeof(t),1,tf))
    {
        if(strcmp(u_name,t.username)==0)
        {
            d=1;  //duplicate data found
            break;
        }
    }
    fclose(tf);
    return d;
}

//create teacher account
void t_account()
{
    struct teacher
    {
        char name[50];
        char username[20];
        char password[10];
        char dept[10];
        char email[50];
        char mobile[12];
    } t;

    int a;
    system("cls");
    printf("<=== Create Teacher's Account ===>\n\n");

    //getting teacher's information
    printf("Full name: ");
    fflush(stdin); //remove extra new line from string
    gets(t.name);
    printf("Username: ");
    scanf("%s",t.username);
    printf("Password: ");
    scanf("%s",t.password);
    printf("Department: ");
    scanf("%s",t.dept);
    printf("E-mail: ");
    scanf("%s",t.email);
    printf("Mobile no.: ");
    scanf("%s",t.mobile);

    int d;
    d=t_duplicate(t.username); //check for duplicate data

    if(d==0) //no duplicate found
    {
        FILE *td;
        td=fopen("teacher.txt","a");
        fwrite(&t,sizeof(t),1,td);

        fclose(td);
        printf("\nAccount created successfully!!!\n\n");
    }
    else
    {
        printf("\n%s is already added!!!\n\n",t.username);
    }

    printf("1. Create another account?\n");
    printf("0. Go back\n\n");
    printf("Enter your choice(serial no.) ");
    scanf("%d",&a);

    if(a==1)
    {
        t_account(); //add another account
    }
    else
    {
        while(a!=0)
        {
            printf("\nWrong input!!!\n");
            printf("\nEnter 0 to go back... ");
            scanf("%d",&a);
        }
    }


    if(a==0)
    {
        admin_panel();
    }



}

void admin_panel()
{
    int ch;
    system("cls");
    printf("<=== Admin Panel ===>\n\n");

    // creating admin options
    printf("What you want to do?\n");
    printf("\t1.Create teacher's account\n");
    printf("\t2.Create student's account\n");
    printf("\t3.Show teacher's information\n");
    printf("\t4.Show student's information\n");
    printf("\t5.Update teacher's information\n");
    printf("\t6.Update student's information\n");
    printf("\t7.Delete teacher's information\n");
    printf("\t8.Delete student's information\n");
    printf("\t9.Assign courses to teacher\n");
    printf("\t10.Update courses of teacher\n");
    printf("\t0.Go to home\n");

    printf("Enter your choice(serial no): ");
    scanf("%d",&ch);

    if(ch==1)
    {
        t_account();
    }
    else if(ch==2)
    {
        s_account();
    }
    else if(ch==3)
    {
        t_info();
    }
    else if(ch==4)
    {
        s_info();
    }
    else if(ch==5)
    {
        t_update();
    }
    else if(ch==6)
    {
        s_update();
    }
    else if(ch==7)
    {
        t_delete();
    }
    else if(ch==8)
    {
        s_delete();
    }
    else if(ch==9)
    {
        courses();
    }
    else if(ch==10)
    {
        c_update();
    }
    else if(ch==0)
    {
        system("cls");
        main();
    }

}

void a_login()
{
    struct admin_login
    {
        char username[50];
        char password[10];
    } a_l;

    system("cls");
    printf("<===Log in to Your Account===>\n\n");
    char u_name[50],pw[10];
    int z=0,y=0;

    printf("Enter username: ");
    scanf("%s",u_name);     // get username of admin
    printf("Enter password: ");
    scanf("%s",pw);    // get admin password
    printf("\n");

    FILE *al;
    al=fopen("admin.txt","r");

    if(al==NULL)
    {
        printf("file not found");
    }

    while(fread(&a_l,sizeof(a_l),1,al))
    {

        if(strcmp(u_name,a_l.username)==0)
        {
            z=1;  //user found
            if(strcmp(pw,a_l.password)==0)// password matching
            {

                printf("Log in successful.");
                admin_panel();
                break;
            }
            else
            {
                y=1; // user found but password incorrect
                printf("Incorrect password!");
                break;
            }
        }
    }

    fclose(al);

    if(z==0)
    {
        printf("User not found!!!");
    }

    if(z==0 || y==1) // nothing is matched
    {
        int a;
        printf("\nEnter 0 to go back... ");
        scanf("%d",&a);

        while(a!=0)
        {
            printf("\nWrong input!!!\n");
            printf("\nEnter 0 to go back... ");
            scanf("%d",&a);
        }

        if(a==0)
        {
            system("cls");
            main();
        }
    }



}


int main()
{
    int ch;

    printf("<=== Welcome to University Management system ===>\n\n");
    printf("Choose an option how you want to enroll:\n");
    printf("\t1.Admin\n");
    printf("\t2.Teacher\n");
    printf("\t3.Student\n");
    printf("\t0.Exit\n");

    printf("\nEnter your choice(serial no): ");
    scanf("%d",&ch);

    if(ch==0)
    {
        return 0;
    }
    else if(ch==1)
    {
        a_login();
    }
    else if(ch==2)
    {
        t_login();
    }
    else if(ch==3)
    {
        s_login();
    }
    else
    {
        printf("\nWrong input!!!");
    }

    return 0;

}
