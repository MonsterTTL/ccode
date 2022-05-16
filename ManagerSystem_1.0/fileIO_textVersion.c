#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>


#define MAX 100
#define ACCOUNT_MAX 20
#define FILE_MAX 50
#define READ_MAX 256
#define SYS_ACCOUNT "system_accountlist.txt"
#define SYS_TEMPFILE "System_temp.txt"
#define SYS_PASSWORD "System_password.txt"


typedef enum statue{
    OK = 1,
    Error = 0
}Statue;

typedef enum searchstate{
    Yes = 1,
    No = 0
}SearchStatue;

typedef enum movetype{
    Forward = 1,
    Backward = 0
}Movetype;

//file Structure
//typedef struct file_list{
//    char cur_name[FILE_MAX];
//    char next_name[FILE_MAX];
//}FILE_NA;

typedef enum authority{
    System_priorty = 1,
    User_priorty = 0
}Authority_Priorty;

typedef struct user{
    
    char account[ACCOUNT_MAX]; // �˺�
    char password[ACCOUNT_MAX]; //����
    Authority_Priorty priorty; // ���ȼ�
    long money; // ���
    //��ʼ��ѧ
    int hp;
    int grade;
    int defense;
    int attack;
    int speed;
}User;

typedef struct list{
     User * cur ;
     struct list * next;
}List;


typedef enum login_statue{
    Successful = 1,
    Fail = 0
}Login_Statue;
//ս��ϵͳ(bushi)
Statue WarSystem(char Player1[],char Player2[],int* WhoWin);//˫�˵�ս��ϵͳ,Player1Ϊ�����û�
int DamageCul(int attack,int * lucky);//�˺�����ϵͳ
Statue IsDead(User * P1,User * P2);//�����ж�
int endDamege(int Damage,User Player);//�����ж�
void DamageResult(int result,User * Player);//�˺�����
Statue User_EnterWar(void);//����ս��ϵͳ
//This is my ManagerSystem function
User System;//ϵͳר�ñ���
    // ע�Ჿ��
Statue User_register(void) ;// �û�ע��
Statue Account_Init(User * temp,char name[ACCOUNT_MAX],char password[ACCOUNT_MAX]) ;//�����û�ʱ���˻���ʼ��
Statue Register_process(char usename[],char password[]); //�Ӻ��������ں����ڲ���ʵ��
    // ��¼����
Statue User_login(User * cur);//�û���¼
Login_Statue Account_Login(char usename[],char password[]);//�Ӻ��������ڵ�¼�ڲ���ʵ��
Statue Read_User_Information(char * usename,User * cur);//��ȡ�û���Ϣ
Statue User_ChangePassword(void);//�ı��û�����
Statue ChangePassWord_process(char password[]);
Statue User_UnsubscribeAccount(void);//�û�ע��
Statue User_ChangeMoney(void);//�û��޸Ľ��
Statue User_Store(void);//�û��̵�
    //ϵͳ��
void System_Menu(void);//��ʾ�˵�
void UserLoginMenu(void);//�û��ɹ���¼֮��Ľ���
void ManagerMenu(void);//����Ա�˵�
Statue System_ShowInformation(User * name);  //��ʾһ���˻���������Ϣ
Statue System_ShowAllUser(void);//��ʾ�����û�
Statue System_ShowAllDetail(void);//��ʾ�����û�����ϸ��Ϣ
Statue System_ChangeMoney_process(char * usename,int number);//�޸�һ���û������,�ڲ�����
Statue System_ChangeMoney(void);//�޸�һ���û������
Statue SystemPoint_Reset(void);//����ϵͳָ��
Statue System_RerangeProcess(void);//���ս����û���������
Statue ShowListData(List * test);//�������������ʾ
Statue System_ChangeAuthority(void);//�ı�һ���û���Ȩ��
Statue System_ChangeAuthority_process(char * usename,int n);//�ı��û�Ȩ�ޣ��������
Statue System_Delete_Process(char usename[]);//ɾ��һ���û����������
Statue System_DeleteAUser(void);//ɾ��һ���û�
Statue System_CreateAccount(void);//ϵͳ����һ���û�
Statue System_ChangePassword(void);//�ı�һ���û�������
Statue System_ChangeSpd(char usename[],int target);//�ı��ٶ�
Statue System_ChangeHP(char usename[],int target);//�ı�HP
Statue System_ChangeAck(char usename[],int target);//�ı乥����
Statue System_ChangeDef(char usename[],int target);//�ı������

//This is my FileIO function
Statue Show_A_File_version1(char * FileName);//��ʾһ���ı��ļ�����������
Statue Create_A_File_version1(char * FileName);//����һ���ı��ļ�����Ҫ����׺
SearchStatue IsFileExist(char * FileName);//����һ���ļ��Ƿ����
Statue Write_A_File_version1(char * FileName,char * target);//��ĩβд����
Statue FilePointSetEnd(FILE * fp);//����ǰ�ļ�ָ��λ��������ĩβ
Statue FilePointSetHead(FILE * fp);//����ǰ�ļ�ָ��λ�������ڿ�ͷ
Statue FilePointMoveForward(FILE * fp,long offset);//��ǰ�ļ�ָ��������
Statue FilePointMoveBackward(FILE * fp,long offset);//��ǰ�ļ�ָ����ǰ��
Statue Write_A_File_version2(char * FileName,char * target,int offset,Movetype flag);//�ھ࿪ͷoffset��д�ļ���β��д�ļ�
Statue Write_A_File_version3(char * FileName,char * target,int length); //���ļ�β��д�̶����ȵ�����
Statue Write_A_File_version4(char * FileName,char * target,int m,int max); //�ھ��ļ���ͷm��дmax���ȵ�����
Statue Read_All_Data(char * FileName,char * target); //��һ���ļ�������ȫ��ȡ������target�У���󳤶�Ϊ256
Statue Read_All_Data_version2(char * FileName,char * target,int m,int max); //��һ���ļ��ӿ�ͷm��������ȡmax������target��
Statue Delete_AendLetter(char * name,int n);//ɾ��������������
Statue DelectDataPriod(char filename[],int start,int length);//ɾ��file�е�start��ʼλ��length���ȵ�����


List * merge(List * head1,List * head2);//�鲢����
List * mergesort(List * head,List * end);//�鲢����
List * List_sort(List * exam);//�����ݽ�������
List * reverse(List * head);//��ת����
List * List_init(char * filename);//���ļ��е����ݶ���������ת����һ������


//This is my IO function
char * s_gets(char * st,int n);

int main(void)
{   
  //int test = 0;
  //WarSystem("S1","S2",&test);
  //printf("%d  ",test);
  //DelectDataPriod("us",5,5);
  //System_Delete_Process("us");
  //while(1);
  //char temp[20] = {0};
  //int tt = 102;
  //itoa(tt,temp,10);
  //printf("%s %d",temp,strlen(temp));
  //while(1);
  while(1) 
   { 
       System_Menu();
   }
   return 0;
}
Statue Create_A_File_version1(char * FileName)
{
    FILE * fp;
    fp = fopen(FileName,"r");
    if(fp != NULL)
    {
        printf("This File has been created!");
        return Error;
    }
    fclose(fp);
    fp = fopen(FileName,"a");
    fclose(fp);
    return OK;


}

Statue Show_A_File_version1(char * FileName)
{   
    int ch;
    FILE * fp;
    fp = fopen(FileName,"r");
    ch = getc(fp);
    while(ch != EOF)
    {
        putchar(ch);
        ch = getc(fp);
    }
    fclose(fp);
    return OK;
}
Statue Write_A_File_version1(char * FileName,char * target)//��ĩβд����
{   
    if(IsFileExist(FileName) == No )
    {
        printf("This File is not exist !!");
        return Error;
    }
    FILE * fp = fopen(FileName,"a");
    int ch = target[0];
    int i = 0;
    while(ch != '\0')
    {
        putc(ch,fp);
        i++;
        ch = target[i];
    }
    fclose(fp);
    return OK;

}

Statue Write_A_File_version2(char * FileName,char * target,int offset,Movetype flag)//�ھ࿪ͷoffset��д�ļ�����βoffset..
{   
    if(IsFileExist(FileName) == No )
    {
        printf("This File is not exist !!");
        return Error;
    }
    FILE * fp = fopen(FileName,"r+");
    if(flag == Forward)
    {
        FilePointSetHead(fp);
        FilePointMoveForward(fp,offset);
    }
    else if (flag == Backward)
    {
        FilePointSetEnd(fp);
        FilePointMoveBackward(fp,offset);
    }
    else
    {
        printf("This is not a avaliable move ");
    }
    int ch = target[0];
    int i = 0;
    while(ch != '\0')
    {
        putc(ch,fp);
        i++;
        ch = target[i];
    }
    fclose(fp);
    return OK;

}

Statue Write_A_File_version3(char * FileName,char * target,int length)//��ĩβд�̶����ȵ�����
{   
    if(IsFileExist(FileName) == No )
    {
        printf("This File is not exist !!");
        return Error;
    }
    FILE * fp = fopen(FileName,"a");
    int ch = target[0];
    int i = 0;
    while(ch != '\0'&& i <= length)
    {
        putc(ch,fp);
        i++;
        ch = target[i];
    }
    
    while(i < length)
    {
        putc(' ',fp);
        i++;
    }
    fclose(fp);
    return OK;

}

Statue Write_A_File_version4(char * FileName,char * target,int m,int max)
{
    if(IsFileExist(FileName) == No )
    {
        printf("This File is not exist !!");
        return Error;
    }
    FILE * fp = fopen(FileName,"r+");
    FilePointSetHead(fp);
    FilePointMoveForward(fp,m);
    int ch = target[0];
    int i = 0;
    while(ch != '\0'&& i <= max)
    {
        putc(ch,fp);
        i++;
        ch = target[i];
    }
    while(i < max)
    {
        putc(' ',fp);
        i++;
    }
    fclose(fp);
    return OK;
}

SearchStatue IsFileExist(char * FileName)
{
    FILE * fp;
    fp = fopen(FileName,"r");
    if(fp == NULL)
    {
        return No;
    }
    else{
        fclose(fp);
        return Yes;
    }
    
}


Statue FilePointSetEnd(FILE * fp)
{   
    int sta = 0;
    sta = fseek(fp,0L,SEEK_END);
    if(sta == 0)
        return OK;
    else
        return Error;
}

Statue FilePointSetHead(FILE * fp)
{
    int sta = 0;
    sta = fseek(fp,0L,SEEK_SET);
    if(sta == 0)
        return OK;
    else
        return Error;
}

Statue FilePointMoveForward(FILE * fp,long offset)
{
    int sta = 0;
    sta = fseek(fp,offset,SEEK_CUR);
    if(sta == 0)
        return OK;
    else
        return Error;
}

Statue FilePointMoveBackward(FILE * fp,long offset)
{
    int sta = 0;
    offset = -offset;
    sta = fseek(fp,offset,SEEK_CUR);
    if(sta == 0)
        return OK;
    else
        return Error;
}

char * s_gets(char * st,int n)
{
    char * ret;
    int i = 0;

    ret = fgets(st,n,stdin);
    if(ret)
    {
        while(st[i] != '\n' && st[i] != '\0')
            i++;
        if(st[i] == '\n')
        {
            st[i] = '\0';
        }
        else
        {   
           
            while(getchar() != '\n')
                continue;
        }
    }
    return ret;
}

Statue Read_All_Data(char * FileName,char * target)
{
    if(IsFileExist(FileName) == No)
    {
        printf("This File is not exist!!");
        return Error;
    }
    FILE * fp = fopen(FileName,"r");
    int l = 0;
    int i ;
    for(i = 0 ; i < READ_MAX-1 && l != EOF ; i++)
    {   
        l = getc(fp);
        target[i] = l;
    }
    target[i] = '\0';
    fclose(fp);
    return OK;
    
}

Statue Read_All_Data_version2(char * FileName,char * target,int m,int max)
{
    if(IsFileExist(FileName) == No)
    {
        printf("This File is not exist!!");
        return Error;
    }
    FILE * fp = fopen(FileName,"r");
    FilePointMoveForward(fp,m);
    int l = getc(fp);
    int i ;
    for(i = 0 ; i < max && l != EOF && l != ' '; i++)
    {   
        target[i] = l;
        l = getc(fp);
    }
    target[i] = '\0';
    fclose(fp);
    return OK;
}

Statue Delete_AendLetter(char * name,int n) //ɾ�������ļ�����ĸ
{
    int ch1;int ch2;
    FILE * fp,* fp2,* fp1;
    if(IsFileExist(name) == No)
    {
        printf("This file is not exist!\n");
        return Error;
    }
    fp = fopen(name,"r+");
    fp1 = fopen(name,"r+");
    if(fp == NULL || fp1 == NULL)
      {printf("open error!\n");
       return Error;}  
    FilePointMoveForward(fp,n);
    ch1 = getc(fp);
    ch2 = getc(fp1);
    fp2 = fopen("System_temp.txt","w+");
    if(ch1 == EOF) // ������õ��ڳ��ȣ��ͽ������ļ�����
      {     
          fclose(fp);
          fclose(fp1);
          fclose(fp2);
          fp2 = fopen(name,"w+");
          fclose(fp2);
          return OK;
      }  
    while(ch1 != EOF)
    {
        putc(ch2,fp2);
        ch1 = getc(fp);
        ch2 = getc(fp1);
    }
    FilePointSetHead(fp2);
    fclose(fp);fclose(fp1);
    fp = fopen(name,"w+");
    ch1 = getc(fp2);
   // printf("%c",ch1);
    while(ch1 != EOF)
    {
        putc(ch1,fp);
        ch1 = getc(fp2);
    }
    fclose(fp);
    fclose(fp2);
    return OK;

}

Statue DelectDataPriod(char filename[],int start,int length)//ɾ��file�е�start��ʼλ��length���ȵ�����
{
    if(IsFileExist(filename) == No)
    {
        printf("Delete Error:This File is Not exist!\n");
        return Error;
    }
    if(IsFileExist(SYS_TEMPFILE) == No)
    {
        printf("SystemTempFile is Lost!!\n");
        return Error;
    }
    FILE * fp = fopen(filename,"r+");
    FILE * temp = fopen(SYS_TEMPFILE,"w+");
    int ch1;
    int ch2;
    for(int i = 0;i < start;i++)
    {
        ch1 = getc(fp);
        putc(ch1,temp);
    }
    FilePointMoveForward(fp,length);
    ch1 = getc(fp);
    while(ch1 != EOF)
    {
        putc(ch1,temp);
        ch1 = getc(fp);
    }
    fclose(fp);
    fp = fopen(filename,"w+");
    FilePointSetHead(temp);
    FilePointSetHead(fp);
    ch1 = getc(temp);
    while(ch1 != EOF)
    {
        putc(ch1,fp);
        ch1 = getc(temp);
    }
    
    fclose(fp); // һ���أ���Ȼ�����ڻ�������ûд���ļ���
    fclose(temp);
    return OK;
    //FilePointMoveForward(fp,start);

}

//system function
Statue User_register(void)
{   
    char usename[ACCOUNT_MAX] = {0};
    char password[ACCOUNT_MAX] = {0};
    User * temp = (User *)(malloc(sizeof(User)));   //
    printf("You are register now,please enter your account,length:1 ~ 20!\n");
    s_gets(usename,20); 
    printf("please enter your password,length:1 ~ 20!\n");
    s_gets(password,20); 
    Account_Init(temp,usename,password);
    if(Register_process(usename,password) == Error)
    {   
        printf("Register is fail!\n");
        return Error;
    }
    else
    {
        printf("Register successfully!\n");
        free(temp);
        return OK;
    }
    
    
}

Statue Register_process(char usename[],char password[]) //�����ע�����
{
    if(IsFileExist(usename) == Yes)
        {
            printf("This account has been created !!\n");
            return Error;
        }
   int inituse = 0; 
   char tempuse[20] = {0};
   srand((unsigned int)(time(NULL)));
   Create_A_File_version1(usename);
   
   Write_A_File_version3(usename,usename,20);
 
   Write_A_File_version3(usename,password,20);
 
   Write_A_File_version3(usename,"User_priorty",20);
  
   Write_A_File_version3(usename,"0",20);
   
   Write_A_File_version3(usename,"1",20);//�ȼ�

   inituse = 50 + rand()%6;
   itoa(inituse,tempuse,10);
   Write_A_File_version3(usename,tempuse,20);//Ѫ��

   inituse = 10 + rand()%6;
   itoa(inituse,tempuse,10);
   Write_A_File_version3(usename,tempuse,20);//����
   //Write_A_File_version1(usename,"#");
  // Write_A_File_version2(SYS_ACCOUNT," ",1,Backward);
   
   inituse = 10 + rand()%6;
   itoa(inituse,tempuse,10);
   Write_A_File_version3(usename,tempuse,20);//����

   inituse = 10 + rand()%6;
   itoa(inituse,tempuse,10);
   Write_A_File_version3(usename,tempuse,20);//�ٶ�

   Delete_AendLetter(SYS_ACCOUNT,1);
   Write_A_File_version3(SYS_ACCOUNT,usename,20);
   Write_A_File_version1(SYS_ACCOUNT,"#"); 
   return OK;
}

Statue Account_Init(User * temp,char name[ACCOUNT_MAX],char password[ACCOUNT_MAX]) //�����û�ʱ���˻���ʼ��
{
    strcpy(temp -> account,name);
    strcpy(temp -> password,password);
    temp -> priorty = User_priorty;
    temp -> money = 0;
}

Statue User_login(User * cur)
{   
    char usename[ACCOUNT_MAX] = {0};
    char password[ACCOUNT_MAX] = {0};
    Login_Statue loginstatue;
    printf("You are lording now ,please enter your Account:\n");
    s_gets(usename,20);
    printf("please enter your password:\n");
    s_gets(password,20);
    loginstatue = Account_Login(usename,password);
    if(loginstatue == Successful)
    {
        Read_User_Information(usename,cur);
        return OK;
    }
    else
        return Error;
    
}

Login_Statue Account_Login(char usename[],char password[])
{
    if(IsFileExist(usename) == No)  
        {
            printf("This Account is not exist!\n");
            return Fail;
        }
    char true_password[20] = {0};
    Read_All_Data_version2(usename,true_password,20,20);
    if(strcmp(password,true_password) == 0)
        {
            printf("load successful!\n");
            return Successful;
        }
    else
        {
            printf("password error!\n");
            return Fail;
        }
    
    
}

Statue Read_User_Information(char * usename,User * cur)
{   
    char priorty[ACCOUNT_MAX] = {0};
    char money[ACCOUNT_MAX] = {0};
    char grade[ACCOUNT_MAX] = {0};
    char defense[ACCOUNT_MAX] = {0};
    char attack[ACCOUNT_MAX] = {0};
    char speed[ACCOUNT_MAX] = {0};
    char hp[ACCOUNT_MAX] = {0};
    Read_All_Data_version2(usename,cur -> account,0,20);
    Read_All_Data_version2(usename,cur -> password,20,20);
    Read_All_Data_version2(usename,priorty,40,20);
    Read_All_Data_version2(usename,money,60,20);
    Read_All_Data_version2(usename,grade,80,20);
    Read_All_Data_version2(usename,hp,100,20);
    Read_All_Data_version2(usename,defense,120,20);
    Read_All_Data_version2(usename,attack,140,20);
    Read_All_Data_version2(usename,speed,160,20);
    if(strcmp(priorty,"User_priorty") == 0)
    {
        cur -> priorty = User_priorty;
    }
    else
    {
        cur -> priorty = System_priorty;
    }
    cur -> money = (long)(atoi(money));
    cur -> grade = (int)(atoi(grade));
    cur -> defense = (int)(atoi(defense));
    cur -> attack = (int)(atoi(attack));
    cur -> speed = (int)(atoi(speed));
    cur -> hp = (int)(atoi(hp));
    return OK;
}

Statue System_ShowInformation(User * name)
{
    if(name == NULL)
        {
            printf("Showing Error!\n");
            return Error;
        }
    else
        {
            printf("Account:%s \nPassword:%s\nMoney:%d\nPriorty:(1 = system,0 = user) %d\n",name ->account,name ->password,name ->money,name ->priorty);
            printf("hp: %d\ngrade : %d \ndefense : %d\nattack:%d\nspeed:%d\n",name->hp,name->grade,name->defense,name->attack,name->speed);
        }
    return OK;
}

Statue System_ShowAllUser(void)
{
    if(IsFileExist(SYS_ACCOUNT) == No)
    {
        printf("System file is lost!!!\n");
        return  Error;
    }
    printf("Hear are all the Users:\n");
    Show_A_File_version1(SYS_ACCOUNT);
    printf("\n");
    return OK;
}

Statue System_ShowAllDetail(void)
{
    char usename[ACCOUNT_MAX] = {0};
    User * temp = (User *)(malloc(sizeof(User)));
    Read_All_Data_version2(SYS_ACCOUNT,usename,0,20);
    int i = 1;
    while(usename[0] != '#')
    {   
        Read_User_Information(usename,temp);
        System_ShowInformation(temp);
        printf("*******************\n");
        Read_All_Data_version2(SYS_ACCOUNT,usename,(i*20),20);
        i++;
    }
    free(temp);
    return OK;
}

Statue SystemPoint_Reset(void)//����ϵͳָ��
{
    for(int i = 0; i < 20;i++)
        {System.account[i] = '\0';
         System.password[i] = '\0';
        }
    System.money = 0;
    System.priorty = User_priorty;
    return OK;
}


void System_Menu(void)  //ϵͳ�˵�
{   //while(1);
    system("cls");
    printf("****************************************************\n");
    printf("********Welcome ! Please Enter you Choice!**********\n");
    printf("********    1.register for your account         ****\n");
    printf("********        2.login  your account         ******\n");
    printf("********        3.Enter Manager Menu         *******\n");
    printf("********        4.Exit the System             ******\n");
    printf("****************************************************\n");
    int select;
    select = getch();
    
    switch(select)
    {
        case '1' :User_register();
                  getch();
                  break;
        case '2' :if(User_login(&System) == OK)
                    UserLoginMenu();
                  else
                  { printf("Load fail!!Please try again!\n");
                    getch();
                  }
                    
                  break;
        case '3' : ManagerMenu();
                  break;
        case '4' : printf("Thanks for using!\n");
                    getch();
                    exit(0);
        default : printf("This select is not exist !!,Please enter again!\n");
                  getch();
                  return;
    }
    return;
}

void UserLoginMenu(void) //�û��˵�
{  
    int select;
    while(1)
   {system("cls");
    printf("********************************************************************\n");
    printf("*****Welcome     %-20s! Please Enter you Choice!*****\n",System.account);
    printf("****    1.Show your account's Information       ********************\n");
    printf("*****        2.login out your account         **********************\n");
    printf("*****           3.unsubscribe your account                 *********\n");
    printf("*********             4.Change your password          **************\n");
    printf("********          5.Change your money(need system prioty)    *******\n");
    printf("*********         6.Enter WarSystem   ******************************\n");
    printf("***********       7.Enter the Store           **********************\n");
    printf("********           any other key for exit        *******************\n");
    printf("********************************************************************\n");
    
        
        select = getch();
        switch(select)
        {
            case '1': if(System_ShowInformation(&System) == OK)
                        printf("Showing Successfully!\n");
                      else
                        printf("Something Wrong!\n");
                      getch();
                      break;  
            case '2': SystemPoint_Reset();
                      return ;
            case '3': User_UnsubscribeAccount();
                      SystemPoint_Reset();
                        getch();
                      return ;
            case '4':User_ChangePassword();
                     Read_User_Information(System.account,&System);//�������޸ĵ�����
                        getch();
                        break;
            case '5':User_ChangeMoney();
                    Read_User_Information(System.account,&System);
                     getch();
                     break;
            case '6': User_EnterWar();
                    Read_User_Information(System.account,&System);
                    getch();
                    break;
            case '7': User_Store();
                     Read_User_Information(System.account,&System);
                     getch();
                     break;
            default : SystemPoint_Reset();
                      return ;
        }
    }   
    return ;

}


void ManagerMenu(void) // ����Ա�˵�
{   
    char syspassword[20] = {0};
    char realpassword[20] = {0};
    Read_All_Data_version2(SYS_PASSWORD,realpassword,0,20);
    printf("please enter the System password:\n");
    s_gets(syspassword,20);
    if(strcmp(syspassword,realpassword) != 0)
    {
        printf("Password is Wrong!\n");
        getch();
        return;
    }
int select;
while(1)
   {system("cls");
    printf("****************************************************\n");
    printf("*Welcome to Manager Menu ! Please Enter you Choice!*\n");
    printf("*******         1.Change one's Money         *******\n");
    printf("***         2.Show all User's information        ***\n");
    printf("******      3.Change one's Authority           *****\n");
    printf("4.Rangge and show User's Information(Based on Money)\n");
    printf("******          5.Delect A Account           *******\n");
    printf("*******         6.Create a Account           *******\n");
    printf("**********      7.Change ones Password      ********\n");
    printf("******      Any other key for exit           *******\n");
    printf("****************************************************\n");

    
        
    select = getch();
    switch(select)
        {
            case '1': if(System_ChangeMoney() == OK)
                        printf("Change Successfully!\n");
                      else
                        printf("Change Can't Finish!\n");
                      getch();
                      break;  
            case '2': if(System_ShowAllDetail() == OK)
                        printf("Everything is ok!\n");
                      else
                        printf("Something Error!\n");
                      getch();
                      break;
            case '3': System_ChangeAuthority();
                      getch();
                      break;
            case '4':   System_RerangeProcess();
                       break; 
            case '5':   System_DeleteAUser();
                        getch();
                        break;
            case '6':   System_CreateAccount();
                        getch();
                        break;
            case '7':  System_ChangePassword();
                        getch();
                        break;
            default:  return ;
        }
    }
    return ;
}


Statue System_ChangeMoney_process(char * usename,int number)
{
    if(IsFileExist(usename) == No)
        {
            printf("Can't Find this User!\n");
            return Error;
        }
    Read_User_Information(usename,&System);
    System.money = number;
    char target[ACCOUNT_MAX] = {0};
    sprintf(target,"%d",number);
    Write_A_File_version4(usename,target,60,20);
    return OK;
}

Statue System_ChangeMoney(void)
{
    char usename[ACCOUNT_MAX] = {0};
    int money = 0;
    printf("Please enter your target AccountName:\n");
    s_gets(usename,20);
    printf("Please Enter your target number:\n");
    scanf("%d",&money);
    getchar();
    if(System_ChangeMoney_process(usename,money) == Error)
        {
            return Error;
        }
    else
        return OK;
}

List * List_init(char * filename) //��ͷ�ڵ��
{
   
    char usename[MAX] = {0};
    List * ret = (List *)(malloc(sizeof(List)));
    List * temp2 = ret;
    List * retu = ret;
    User * usetemp = NULL;
    ret ->cur = NULL;
    ret ->next = NULL;
    Read_All_Data_version2(filename,usename,0,20);
    int i = 1;
    while(usename[0] != '#')
    {   
       
        usetemp = (User *)(malloc(sizeof(User)));
        temp2 = (List *)(malloc(sizeof(List)));
        Read_User_Information(usename,usetemp);
        temp2 -> cur = usetemp;
        temp2 -> next = NULL;
        ret -> next = temp2;
        ret = ret ->next;
        Read_All_Data_version2(SYS_ACCOUNT,usename,(i*20),20);
        i++;
    }
    return retu;
    
}

Statue ShowListData(List * test)
{   
    if(test == NULL )
        {   printf("That is not a avaliable List!\n");
            return Error;}
    test = test -> next;
    printf("%-20s%-20s%-20s\n","Username","Money","Priorty");
    while(test != NULL )
    {   
        
        printf("%-20s",test -> cur-> account);
        printf("%-20d",test ->cur ->money);
        printf("%-20d\n",test->cur->priorty);
        test = test ->next;
    }
    return OK;
}

List * List_sort(List * exam)
{
   return mergesort(exam,NULL);

}


List * merge(List * head1,List * head2)
{
    List * newhead = (List *)(malloc(sizeof(List)));
    List * ret = newhead;
    newhead -> cur = NULL;
    newhead -> next = NULL;
    
    if(head1 == NULL || head2 == NULL)
        {
            printf("That is not a avaliable List!\n");
            return NULL;
        }
    head1 = head1 -> next;
    head2 = head2 -> next;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1 -> cur -> money > head2 -> cur ->money)
        {
            newhead -> next = head1;
            head1 = head1 -> next;
        }
        else
        {
            newhead -> next = head2;
            head2 = head2 -> next;
        }
        newhead = newhead->next;
    }
    while(head1 != NULL)
    {
        newhead -> next = head1;
        head1 = head1 ->next;
        newhead = newhead -> next;
    }
    while(head2 != NULL)
    {
        newhead -> next = head2;
        head2 = head2 ->next;
        newhead = newhead -> next;
    }
    
    return ret;

}

List * mergesort(List * head,List * end)
{   
    List * touhead = head;
    if(head == NULL)
        return NULL;
    head = head -> next;
    if(head == NULL)
        return touhead;
    
    if(head -> next == end)
    {
        head -> next = NULL;
        return touhead;
    }
    List * fast = head -> next;
    List * slow = head -> next;
    List slowhead ;
    while(fast != end && fast -> next != end)
    {
        fast = fast -> next -> next;
        slow = slow -> next;
        
    }
    slowhead.cur = NULL;
    slowhead.next = slow;
    return merge(mergesort(touhead,slow),mergesort(&slowhead,end));
}

List * reverse(List * head)
{
    if(head == NULL )
    {
        printf("That is not a avaliable!\n");
        return NULL;
    }
    List * node ;
    List * newhead = NULL;
    List * ret = (List *)(malloc(sizeof(List)));
    ret -> cur = NULL;
    head = head -> next;
    while(head != NULL )
    {
        node = head;
        head = head -> next;
        node -> next = newhead;
        newhead = node;
    }
    ret -> next = newhead;
    free(head);
    return ret;


}


Statue System_RerangeProcess(void)
{   
   int select; 
   List * test = List_init(SYS_ACCOUNT);
   test = List_sort(test);
   int flag = 0;
   while(1)
   {
       system("cls");
       printf("*****************************************\n");
       printf("******What range do you want ?***********\n");
       printf("press 1 for rise and press 2 for decrease\n");
       printf("******press any other key for exit*******\n");
       printf("*****************************************\n");
       select = getch();
       switch(select)
       {
           case '1':if(flag == 0)
                    {test = reverse(test);
                     flag = 1;} 
                    ShowListData(test);
                    getch();
                    break;
           case '2':if(flag == 1)
                    {
                    test = reverse(test);
                    flag = 0;
                    }
                    ShowListData(test);
                    getch();
                    break;
            default : return OK;

       }
   }
   return OK;
}

Statue System_ChangeAuthority(void)
{
    int select;
    char usename[ACCOUNT_MAX] = {0};
    
    system("cls");
    printf("please enter User's Account:\n");
    s_gets(usename,20);
    printf("What Authority you want give ? 0 for User and 1 for System:\n");
    select = getch();
    if(System_ChangeAuthority_process(usename,select) == Error)
    {
        
        return Error;
    }
    else
    {
        
        return OK;
    }

}

Statue System_ChangeAuthority_process(char * usename,int n)
{
    if(IsFileExist(usename) == No)
        {
            printf("Can't Find this User!\n");
            printf("User's Authority hasn't been changed!\n");
            return Error;
        }
    if(n == 1)
      Write_A_File_version4(usename,"User_priorty",40,20);
    else
      Write_A_File_version4(usename,"System_priorty",40,20);
    printf("User's Authority has been changed!\n");
    return OK;
}

Statue System_DeleteAUser(void)
{
    printf("Which Account you want to delete?\n");
    char usename[ACCOUNT_MAX] = {0};
    s_gets(usename,20);
    if(System_Delete_Process(usename) == OK)
    {
        printf("Delete Successfully!\n");
        return OK;
    }
    else
    {
        printf("Delete Error!!\n");
        return Error;
    }

}

Statue System_Delete_Process(char usename[])
{
    if(IsFileExist(usename) == No)
    {
        printf("Can't Find this User!Please Try again!\n");
        return Error;
    }
    //Read_User_Information(usename,&System);
    char tempuse[20] = {0};
    int cnt = 0;
    
    Read_All_Data_version2(SYS_ACCOUNT,tempuse,cnt*20,20);
    while(strcmp(usename,tempuse) != 0)
    {   
        cnt++;
        Read_All_Data_version2(SYS_ACCOUNT,tempuse,cnt*20,20);
    }
    DelectDataPriod(SYS_ACCOUNT,cnt*20,20);
    remove(usename);
    return OK;
}


Statue User_UnsubscribeAccount(void)//�û�ע������
{   
    int select;
    printf("Do you really want to unsubscribe your account? Y/N\n");
    select = getch();
    if(select == 'Y'|| select == 'y')
    {
        if(System_Delete_Process(System.account) == OK)
           {
               printf("Your Account has been subscribe,See you again!\n");
               return OK;
            } 
        else
           {
               printf("Something wrong!\n");
               return Error;
            } 
    }
    else
    {
        printf("exit\n");
        return Error;
    }
}

Statue System_CreateAccount(void)
{
    char usename[20] = {0};
    char password[20] = {0};
    printf("You are Creating a Account now,Please enter usename:\n");
    s_gets(usename,20);
    if(IsFileExist(usename) == Yes)
    {
        printf("Error , this user is exist.\n");
        return Error;
    }
    printf("Now please enter the password:\n");
    s_gets(password,20);
    if(Register_process(usename,password) == OK)
    {
        printf("Register OK\n");
        return OK;
    }
    else
    {
        printf("Cant create!");
        return Error;
    }

}

Statue User_ChangePassword(void)
{
    char newpassword[20] = {0};
    char flag = 0;
    printf("Please enter your new password:\n");
    s_gets(newpassword,20);
    printf("Do you really want to change it? Y = yes\n");
    flag = getch();
    if(flag == 'Y'||flag == 'y')
    {
        if(ChangePassWord_process(newpassword) == OK)
        {
            printf("Change Successfully!\n");
            return OK;
        }
        else
        {
            printf("Change fail!\n");
            return Error;
        }
    }
    else
    {
        printf("Exit\n");
        return OK;
    }
}

Statue ChangePassWord_process(char password[])
{
   if(Write_A_File_version4(System.account,password,20,20) == OK) 
   {
       return OK;
   }
   else
   {
       return Error;
   }
}


Statue System_ChangePassword(void)
{
    char newpassword[20] = {0};
    char usename[20] = {0};
    printf("Please enter the usename:\n");
    s_gets(usename,20);
    if(IsFileExist(usename) == No)
    {
        printf("This use is not exist!\n");
        return Error;
    }
    Read_User_Information(usename,&System);
    printf("please enter the new password\n");
    s_gets(newpassword,20);
    if(ChangePassWord_process(newpassword) == OK)
    {
        printf("Change successfully.\n");
        return OK;
    }
    else
    {
        printf("Cant Change!\n");
        return Error;
    }
}

Statue User_ChangeMoney(void)
{
    if(System.priorty == User_priorty)
    {
        printf("Sorry , you dont have the priorty!\n");
        return Error;
    }
    int target = 0;
    printf("Please enter your target number:\n");
    scanf("%d",&target);
    getchar();
    if(System_ChangeMoney_process(System.account,target) == OK)
    {
        printf("You have change your money!\n");
        return OK;
    }
    else{
        return Error;
    }

}


Statue WarSystem(char Player1[],char Player2[],int* WhoWin)//˫�˵�ս��ϵͳ,Player1Ϊ�����û�
{
    int select = 0;
    if(strcmp(Player1,Player2) == 0)
    {
        printf("You cant fight with yourself!\n");
        return Error;
    }
    if(IsFileExist(Player1) == No || IsFileExist(Player2) == No)
    {
        printf("Player is not exist!\n");
        return Error;
    }
    User P1;User P2;
    int speedflag = 0; 
    int endresult = 0;
    int luckyFlag = 0;
    Read_User_Information(Player1,&P1);
    Read_User_Information(Player2,&P2);
    if(P1.speed >= P2.speed)
    {
        speedflag = 1;
    }
    else
    {
        speedflag = 2;
    }
    while(IsDead(&P1,&P2) == No)
    {   luckyFlag = 0;
        if(speedflag == 1)
        {
            printf("You attack first\n");
            while((select = getch()) != '\r');
            endresult = DamageCul(P1.attack,&luckyFlag);//һ���˺��ж�
            endresult = endDamege(endresult,P2);//�����ж�
            if(luckyFlag == 1)
            {
                printf("You are so lucky!  \n");
                while((select = getch()) != '\r');
            }
            
            printf("You cause %-d damages in the end!\n",endresult);
            DamageResult(endresult,&P2);
            printf("%-s has %-d Hp left\n",P2.account,P2.hp);
            while((select = getch()) != '\r');

            if(P2.hp <= 0)
            {
                printf("You win!Congratulationgs!\n");
                *WhoWin = 1;
                while((select = getch()) != '\r');
                return  OK;
            }

            printf("Then anther Player attack \n");
            while((select = getch()) != '\r');

            endresult = DamageCul(P2.attack,&luckyFlag);//һ���˺��ж�
            endresult = endDamege(endresult,P1);//�����ж�
            if(luckyFlag == 1)
            {
                printf("%-s  is so lucky!  ",P2.account);
                while((select = getch()) != '\r');
            }
            
            printf("%-s cause %-d damages in the end!\n",P2.account,endresult);
            DamageResult(endresult,&P1);
            printf("You have %-d HP left\n",P1.hp);
            while((select = getch()) != '\r');

            if(P1.hp <= 0)
            {
                printf("You Lost!!\n");
                *WhoWin = 2;
                while((select = getch()) != '\r');
                return  OK;
            }

        }
        else
        {
            printf("Anther Player attack first\n");
            while((select = getch()) != '\r');

            endresult = DamageCul(P2.attack,&luckyFlag);//һ���˺��ж�
            endresult = endDamege(endresult,P1);//�����ж�
            if(luckyFlag == 1)
            {
                printf("%-s  is so lucky!  \n",P2.account);
                while((select = getch()) != '\r');
            }
            
            printf("%-s cause %-d damages in the end!\n",P2.account,endresult);
            DamageResult(endresult,&P1);
            printf("You have %-d HP left\n",P1.hp);
            while((select = getch()) != '\r');

            if(P1.hp <= 0)
            {
                printf("You Lost!!\n");
                *WhoWin = 2;
                while((select = getch()) != '\r');
                return  OK;
            }

            printf("Then You attack \n");
            while((select = getch()) != '\r');
            endresult = DamageCul(P1.attack,&luckyFlag);//һ���˺��ж�
            endresult = endDamege(endresult,P2);//�����ж�
            if(luckyFlag == 1)
            {
                printf("You are so lucky!  \n");
            }
            while((select = getch()) != '\r');
            printf("You cause %-d damages in the end!\n",endresult);
            DamageResult(endresult,&P2);
            printf("%-s has %-d Hp left\n",P2.account,P2.hp);
            while((select = getch()) != '\r');

            if(P2.hp <= 0)
            {
                printf("You win!Congratulationgs!\n");
                *WhoWin = 1;
                while((select = getch()) != '\r');
                return  OK;
            }

        }
    }



}

int DamageCul(int attack,int * lucky)//�˺�����ϵͳ
{
    srand((unsigned int)(time(NULL)));
    *lucky = 0;
    int flag = rand()%6;
    int resultDamage = rand()%10 + attack;
    if(flag == 5) //�Ƿ񱩻�
    {
        resultDamage *= 2;
        *lucky = 1;
    }
    return resultDamage;
}

int endDamege(int Damage,User Player)//�����ж�
{
    srand((unsigned int)(time(NULL)));
    int rand1 = rand()%6;
    if(Damage - Player.defense + rand1 > 0)
      return (Damage - Player.defense + rand1 );
    else
      return 1;  
}

void DamageResult(int result,User * Player)//�˺�����
{
    Player->hp = Player->hp-result;
    return ;
}


Statue IsDead(User * P1,User * P2)//�����ж�
{
    if(P1->hp <= 0 || P2 ->hp <=0)
    {
        return Yes;
    }
    else
        return No;
}

Statue User_EnterWar(void)
{
    srand((unsigned int)(time(NULL)));
    int WhoWin = 0;
    int select = 0;
    char P2[20] = {0};
    int addmoney = rand()%20+1;
    printf("Here is all the User,select YOUR PLAYER:\n");
    while((select = getch())!= '\r');
    System_ShowAllUser();
    s_gets(P2,20);
    if(WarSystem(System.account,P2,&WhoWin) == OK)
    {
        printf("Finish.\n");
        if(WhoWin == 1)
        {
            printf("You win %-d  coins",addmoney);
            System_ChangeMoney_process(System.account,addmoney);
        }
        return OK;
    }
    else{
        printf("Error.\n");
        return Error;
    }
}

Statue User_Store(void)
{
    int select = 0;
    int num = 0;
    while(1)
    {system("cls");
     printf("*********************************************\n");
     printf("**********     Here is the Store:      ******\n");
     printf("**********1.ADD ACK (10coin per ack)   ******\n");
     printf("**********2.ADD HP  (10coin per  hp)   ******\n");
     printf("**********3.ADD DEF (10coin per def)   ******\n");
     printf("**********4.ADD SPD (10coin per spd)   ******\n");
     printf("*********************************************\n");
     select = getch();
     switch(select)
     {
         case '1':
                    printf("How many do you want?\n");
                    scanf("%d",&num);getchar();
                    if(System.money >= num *10)
                    {
                        System_ChangeAck(System.account,System.hp + num);
                        System_ChangeMoney_process(System.account,System.money - num*10);
                    }
                    else
                    {
                        printf("You dont have enough money.\n");
                    }
                    Read_User_Information(System.account,&System);
                    getch();
                    break;
         case '2':  
                    printf("How many do you want?\n");
                    scanf("%d",&num);getchar();
                    if(System.money >= num *10)
                    {
                        System_ChangeHP(System.account,System.hp + num);
                        System_ChangeMoney_process(System.account,System.money - num*10);
                        
                    }
                    else
                    {
                        printf("You dont have enough money.\n");
                        
                    }
                    Read_User_Information(System.account,&System);
                    getch();
                    break;
         case '3':
                    printf("How many do you want?\n");
                    scanf("%d",&num);getchar();
                    if(System.money >= num *10)
                    {
                        System_ChangeDef(System.account,System.hp + num);
                        System_ChangeMoney_process(System.account,System.money - num*10);
                    }
                    else
                    {
                        printf("You dont have enough money.\n");
                    }
                    Read_User_Information(System.account,&System);
                    getch();
                    break;
         case '4':
                printf("How many do you want?\n");
                    scanf("%d",&num);getchar();
                    if(System.money >= num *10)
                    {
                        System_ChangeSpd(System.account,System.hp + num);
                        System_ChangeMoney_process(System.account,System.money - num*10);
                    }
                    else
                    {
                        printf("You dont have enough money.\n");
                    }
                    Read_User_Information(System.account,&System);
                    getch();
                    break;
         default:
                return OK;
     }
    }

}

Statue System_ChangeHP(char usename[],int target)
{
    if(IsFileExist(usename) == No)
    {
        printf("this user is not exist.\n");
        return Error;
    }
    char temp[20] = {0};
    itoa(target,temp,10);
    if(Write_A_File_version4(usename,temp,100,20) == OK)
    {
        printf("Change Successfully.\n");
        return OK;
    }
    else
    {
        printf("Error.\n");
        return Error;
    }
}

Statue System_ChangeDef(char usename[],int target)
{
    if(IsFileExist(usename) == No)
    {
        printf("this user is not exist.\n");
        return Error;
    }
    char temp[20] = {0};
    itoa(target,temp,10);
    if(Write_A_File_version4(usename,temp,120,20) == OK)
    {
        printf("Change Successfully.\n");
        return OK;
    }
    else
    {
        printf("Error.\n");
        return Error;
    }
}


Statue System_ChangeAck(char usename[],int target)
{
    if(IsFileExist(usename) == No)
    {
        printf("this user is not exist.\n");
        return Error;
    }
    char temp[20] = {0};
    itoa(target,temp,10);
    if(Write_A_File_version4(usename,temp,140,20) == OK)
    {
        printf("Change Successfully.\n");
        return OK;
    }
    else
    {
        printf("Error.\n");
        return Error;
    }
}

Statue System_ChangeSpd(char usename[],int target)
{
    if(IsFileExist(usename) == No)
    {
        printf("this user is not exist.\n");
        return Error;
    }
    char temp[20] = {0};
    itoa(target,temp,10);
    if(Write_A_File_version4(usename,temp,160,20) == OK)
    {
        printf("Change Successfully.\n");
        return OK;
    }
    else
    {
        printf("Error.\n");
        return Error;
    }
}




