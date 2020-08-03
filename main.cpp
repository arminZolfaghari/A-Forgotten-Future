#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct moshkel
{
    char question[200];
    char tasmim_1[200];
    char tasmim_2[200];
    int grade_1[3];
    int grade_2[3];
    int Emkan;
    struct moshkel *next;

}moshkel;
//******************************************************************************************//
//******************************************************************************************//

void fspace1();
void fspace2();
void  load(moshkel *header);
void sortgrades(char name[][40],int a[],int sizee);
void saveneww_gamer(char name[]);
moshkel * searchh(moshkel *header,int j);
void deletee(moshkel * header,int j);
int shekast(int n1,int n2,int n3);
void fsave(char name[],moshkel *header);
int fload(char name[],moshkel *header);
void who_is_the_best1(moshkel *header);
void who_is_the_best2(moshkel *header);
void sortgrades2(int mardom[],int darbar[],int khazane[],char names[][40],int sizee);
void add_questin();

//******************************************************************************************//
//******************************************************************************************//
int main()
{
    char name[200];
    printf("Please enter your name:\n");
	scanf("%s",&name);
	printf("\n\n");
	printf("***** Welcome %s *****\n",name);
    fspace1();
    moshkel header;
    header.next=NULL;
    printf("Do you want to create a new choice file?\n");
    printf("[1]YES\n[2]NO\n");
    int y;
    scanf("%d",&y);
    fspace1();


    if(y==1)
    {
        system("color 74");
        add_questin();
    }

    printf("[1] sort1( sum 3 parameters )\n");
    printf("[2] sort2( first People , second Court , third Treasury ) \n");
    scanf("%d",&y);
    fspace1();

    if(y==1)
    {
        system("color 06");
        who_is_the_best1(&header);
    }
    else
    {
        system("color 17");
        who_is_the_best2(& header);
    }

    printf("\n\n");

	char c;
	int n;
	int People;
    int Court;
    int Treasury;

    printf("[1] Start a new game \n[2] Resume a game\n");
    scanf("%d",&n);
    fspace1();

    if(n==1)
    {
        system("color 47");
        load(&header);
        People=50;
        Court=50;
        Treasury=50;
    }
    else
    {
        system("color 56");
        fload(name,&header);
        People= header.next->next->grade_1[0];
        Court= header.next->next->grade_1[1];
        Treasury= header.next->next->grade_1[2];
        deletee(&header,1);
        deletee(&header,1);
    }
    printf("People=%d Court=%d Treasury=%d\n\n\n",People,Court,Treasury);
    int tedadmoshkelat=0;
    if(tedadmoshkelat==0)
    if(shekast(People,Court,Treasury))
    {
        printf("You lost your previous game...!!!!\n");
        printf("Start again\n\n");
        header.next=NULL;
        load(&header);
        People=50;
        Court=50;
        Treasury=50;
    }
    for(moshkel *i=(&header)->next;i;i=i->next,tedadmoshkelat++);
    int j;
    int answer;
    moshkel * mainn;
	int w=1;
    for(;tedadmoshkelat>0;)
    {
        srand(time(0));
        j=(rand()%tedadmoshkelat)+1;
        mainn=searchh(&header,j);
        mainn->Emkan= (mainn->Emkan)-1;
        if((mainn->Emkan)==0){
                deletee(&header,j);

                tedadmoshkelat=tedadmoshkelat-1;
        }
        printf("%s\n\n",mainn->question);
        printf("[1] %s\n",mainn->tasmim_1);
        printf("[2] %s\n",mainn->tasmim_2);

        for(;;)
        {
            scanf("%d",&answer);
            if(answer==1)
            {
                system("color 64");
                People= mainn->grade_1[0]+People;
                Court= mainn->grade_1[1]+Court;
                Treasury= mainn->grade_1[2]+Treasury;
                break;
            }
            else if(answer==2)
            {
                system("color 60");
                People= mainn->grade_2[0]+People;
                Court= mainn->grade_2[1]+Court;
                Treasury= mainn->grade_2[2]+Treasury;
                break;
            }
            else if(answer==-1)
            {
                system("color 71");
                if(n==1)saveneww_gamer(name);
                header.grade_1[0]=People;
                header.grade_1[1]=Court;
                header.grade_1[2]=Treasury;
                fsave(name,&header);
                exit(0);
            }
            else
            {
                system("color 65");
                printf("Please Enter 1 or 2\n");
            }
        }
        fspace1();
        printf("People=%d Court=%d Treasury=%d\n",People,Court,Treasury);
		if(shekast(People,Court,Treasury))
		{
		    system("color 46");
			printf("*** YOU LOSE ***\n");
			printf("Do you want to save your current game?\n");
			printf("[1] YES\n[2] NO\n");
			scanf("%d",&answer);
			if(answer==1)
            {
                system("color 72");
                if(n==1)saveneww_gamer(name);
                header.grade_1[0]=People;
                header.grade_1[1]=Court;
                header.grade_1[2]=Treasury;
                fsave(name,&header);
                exit(0);
            }
			w=0;
			break;


		}
    }
	if(w)
	{
	    system("color 27");
        printf("*** YOU WIN ***\n");
		printf("Do you want to save your current game?\n");
        printf("[1] YES\n[2] NO\n");
        scanf("%d",&answer);
        if(answer==1)
            {
                system("color 75");
                if(n==1)saveneww_gamer(name);
                header.grade_1[0]=People;
                header.grade_1[1]=Court;
                header.grade_1[2]=Treasury;
                fsave(name,&header);
                exit(0);
            }
	}
    return 0;
}


//******************************************************************************************//
//******************************************************************************************//


void fspace1()
{
    printf("____________________________________________________________________________________________________________________\n");
    printf("____________________________________________________________________________________________________________________\n\n");
}

//******************************************************************************************//
//******************************************************************************************//

void fspace2()
{
    printf("********************************************************************************************************************\n");
}

//******************************************************************************************//
//******************************************************************************************//


void  load(moshkel *header)
{
   FILE * choice=fopen("CHOICES.txt","r");
    int sizee=0;
    char filee[10000];
    char name[10000];
    char name2[10000];
    char line[10000];
    int d=1;
    while(!feof(choice))
        fscanf(choice,"%c",&filee[sizee++]);
    filee[sizee-1]='\0';
    fclose(choice);
    int x=0;

     for(int i=0;filee[i]!='\0';++i)
    {
        x=0;
        for(;filee[i]!='\0'  && filee[i]!='\n';++i,++x)
        {
            name[x]=filee[i];

        }
        name[x]='\0';

        FILE * newfile=fopen(name,"r");

        moshkel * neww;
        neww=(moshkel *)malloc(sizeof(moshkel));
        sizee=0;
        while(!feof(newfile))
            fscanf(newfile,"%c",&line[sizee++]);
        line[sizee-1]='\0';
        d=1;
         for(int j=0;line[j]!='\0';++j)
        {
            x=0;
            for(;line[j]!='\0'  &&line[j]!='\n';++j,++x)
            {
                name2[x]=line[j];

            }
            name2[x]='\0';
            if(d==1)strcpy(neww->question,name2);
            if(d==2)strcpy(neww->tasmim_1,name2);
            if(d==3)neww->grade_1[0]=atoi(name2);
            if(d==4)neww->grade_1[1]=atoi(name2);
            if(d==5)neww->grade_1[2]=atoi(name2);
            if(d==6)strcpy(neww->tasmim_2,name2);
            if(d==7)neww->grade_2[0]=atoi(name2);
            if(d==8)neww->grade_2[1]=atoi(name2);
            if(d==9)neww->grade_2[2]=atoi(name2);
            ++d;

            }

            neww->Emkan=3;
            neww->next=header->next;
            header->next=neww;

            fclose(newfile);
    }
}



//******************************************************************************************//
//******************************************************************************************//


moshkel * searchh(moshkel *header,int j)
{
    moshkel * co=header->next;
    for(int b=1;b<j;++b,co=co->next);
    return co;
}

//******************************************************************************************//
//******************************************************************************************//

void deletee(moshkel * header,int j)
{
    moshkel *p=header;
    for(int m=1;m<j;p=p->next,++m);
    p->next=p->next->next;


}

//******************************************************************************************//
//******************************************************************************************//

int shekast(int n1,int n2,int n3)
{
	int average = (n1+n2+n3)/3;
	if((average<10)||(n1<=0)||(n2<=0)||(n3<=0))
    {
        return 1;
    }
    else
        return 0;
}

//******************************************************************************************//
//******************************************************************************************//

void fsave(char name[],moshkel *header)
{
	int sizee=0;
	for (;name[sizee]!='\0';sizee++);
	name[sizee]='.';
	name[sizee+1]='t';
	name[sizee+2]='x';
	name[sizee+3]='t';
	name[sizee+4]='\0';
	FILE *myfile =fopen (name,"wb");
	moshkel *i = header->next;

	for(;i;i=i->next)
		fwrite(i,sizeof(moshkel),1,myfile);
    fwrite(header,sizeof(moshkel),1,myfile);
}

//******************************************************************************************//
//******************************************************************************************//

int fload(char name[],moshkel *header)
{
	int sizee=0;
	char name2[800];
	strcpy(name2,name);
	for (;name[sizee]!='\0';sizee++);
	name2[sizee]='.';
	name2[sizee+1]='t';
	name2[sizee+2]='x';
	name2[sizee+3]='t';
	int d=0;
	name2[sizee+4]='\0';
	FILE *my=fopen(name2,"r");
	if(my==NULL)
    {
    printf("*** YOU DON'T HAVE A GAME ***\n");
     exit(2);
    }
	moshkel * neww;
	while(1)
	{
	    if(feof(my))break;
		neww=(moshkel *)malloc(sizeof(moshkel));
		fread(neww,sizeof(moshkel),1,my);
		neww->next=header->next;
		header->next=neww;

	}
	fclose(my);
	return d;
}

//******************************************************************************************//
//******************************************************************************************//

void saveneww_gamer(char name[])
{
    FILE * hamidseffat=fopen("who.txt","a");
	int sizee=0;
	for (;name[sizee]!='\0';sizee++);
	char name2[800];
	strcpy(name2,name);
	name2[sizee]='.';
	name2[sizee+1]='t';
	name2[sizee+2]='x';
	name2[sizee+3]='t';


	fwrite(name2,sizeof(char),sizee+4,hamidseffat);
	fprintf(hamidseffat,"\n");
	fclose(hamidseffat);
}

//******************************************************************************************//
//******************************************************************************************//

void who_is_the_best1(moshkel *header)
{
    char names[40][40];
    int CountNames=1;
    int average[40];
    FILE * who=fopen("who.txt","r");
    char who2  [1000];
    int sizee=0;
    int x;
    char name[44];
    while(!feof(who))
        fscanf(who,"%c",&who2[sizee++]);
    who2[sizee-1]='\0';
    for(int i=0;who2[i]!='\0';++i)
    {
        x=0;
        for(;who2[i]!='\0'  &&who2[i]!='\n';++i,++x)
        {
            name[x]=who2[i];

        }
        name[x-4]='\0';
        fload(name,header);
        average[CountNames]= header->next->next->grade_1[0]+header->next->next->grade_1[1]+header->next->next->grade_1[2];
        strcpy(names[CountNames],name);
        ++CountNames;
        header->next=NULL;


    }
    sortgrades(names,average,CountNames);
    if(CountNames!=1)
       {
            for(int i=CountNames-1;i>=1;--i)
                printf("%s=%d\n",names[i],average[i]);

        printf("\nWINNER --> %s = %d\n",names[CountNames-1],average[CountNames-1]);
        fspace1();
       }

    fclose(who);
}

//******************************************************************************************//
//******************************************************************************************//

void who_is_the_best2(moshkel *header)
{
    char names[40][40];
    int CountNames=1;
    int mardoms[40];
    int khazane[40];
    int darbar[40];
    FILE * who=fopen("who.txt","r");
    char who2  [1000];
    int sizee=0;
    int x;
    char name[44];
    while(!feof(who))
        fscanf(who,"%c",&who2[sizee++]);
    who2[sizee-1]='\0';
    for(int i=0;who2[i]!='\0';++i)
    {
        x=0;
        for(;who2[i]!='\0'  &&who2[i]!='\n';++i,++x)
        {
            name[x]=who2[i];

        }
        name[x-4]='\0';
        fload(name,header);
         mardoms[CountNames]=header->next->next->grade_1[0];
         darbar[CountNames]=header->next->next->grade_1[1];
         khazane[CountNames]=header->next->next->grade_1[2];
        strcpy(names[CountNames],name);
        ++CountNames;
        header->next=NULL;


    }
    sortgrades2(mardoms,darbar,khazane,names,CountNames);
    if(CountNames!=1)
       {
            for(int i=CountNames-1;i>=1;--i)
            {
                printf("%s\n People=%d  cout=%d Treasury=%d\n",names[i],mardoms[i],darbar[i],khazane[i]);
                fspace2();
            }
       }
    fspace1();

    fclose(who);
}

//******************************************************************************************//
//******************************************************************************************//

void sortgrades(char name[][40],int a[],int sizee)
{
    char temp[40];
    int temp2;
    for(int i=1;i<sizee;++i)
        for(int j=1;j<sizee-1;++j)
            if(a[j]>a[j+1])
            {
                strcpy(temp,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],temp);
                temp2=a[j];
                a[j]=a[j+1];
                a[j+1]=temp2;

            }
}

//******************************************************************************************//
//******************************************************************************************//

void sortgrades2(int mardom[],int darbar[],int khazane[],char names[][40],int sizee)
{
    char temp[40];
    int temp2;
    for(int i=1;i<sizee;++i)
        for(int j=1;j<sizee-1;++j)
        {
            if(mardom[j]>mardom[j+1])
            {
                strcpy(temp,names[j]);
                strcpy(names[j],names[j+1]);
                strcpy(names[j+1],temp);
                temp2=mardom[j];
                mardom[j]=mardom[j+1];
                mardom[j+1]=temp2;
                temp2=darbar[j];
                darbar[j]=darbar[j+1];
                darbar[j+1]=temp2;
                temp2=khazane[j];
                khazane[j]=khazane[j+1];
                khazane[j+1]=temp2;

            }
            else if(mardom[j]==mardom[j+1])
                    if(darbar[j]>darbar[j+1])
                    {
                        strcpy(temp,names[j]);
                        strcpy(names[j],names[j+1]);
                        strcpy(names[j+1],temp);
                        temp2=mardom[j];
                        mardom[j]=mardom[j+1];
                        mardom[j+1]=temp2;
                        temp2=darbar[j];
                        darbar[j]=darbar[j+1];
                        darbar[j+1]=temp2;
                        temp2=khazane[j];
                        khazane[j]=khazane[j+1];
                        khazane[j+1]=temp2;
                    }
                    else if(darbar[j]==darbar[j+1])
                            if(khazane[j]>khazane[j+1])
                        {
                            strcpy(temp,names[j]);
                            strcpy(names[j],names[j+1]);
                            strcpy(names[j+1],temp);
                            temp2=mardom[j];
                            mardom[j]=mardom[j+1];
                            mardom[j+1]=temp2;
                            temp2=darbar[j];
                            darbar[j]=darbar[j+1];
                            darbar[j+1]=temp2;
                            temp2=khazane[j];
                            khazane[j]=khazane[j+1];
                            khazane[j+1]=temp2;
                        }
        }
}

//******************************************************************************************//
//******************************************************************************************//

void add_questin()
{
    printf("Enter file name:\n");
    char name [400];
    int i;
    scanf("%s",name);
    int sizee=0;
    for(;name[sizee]!='\0';++sizee);
    name[sizee]='.';
    name[sizee+1]='t';
    name[sizee+2]='x';
    name[sizee+3]='t';
    name[sizee+4]='\0';
    FILE * All=fopen("CHOICES.txt","a");
    fwrite(name,sizeof(char),sizee+4,All);
    fprintf(All,"\n");
    fclose(All);
    FILE * newwfile=fopen(name,"w");
    printf("\nQuestion:\n");
    scanf("%s",name);
    sizee=0;
    for(;name[sizee]!='\0';++sizee);
    fwrite(name,sizeof(char),sizee,All);
    fprintf(All,"\n");
    printf("\nChoice 1:\n");
    scanf("%s",name);
    sizee=0;
    for(;name[sizee]!='\0';++sizee);
    fwrite(name,sizeof(char),sizee,All);
    fprintf(All,"\n");
    printf("\nPeople:\n");
    scanf("%s",name);
    sizee=0;
    for(;name[sizee]!='\0';++sizee);
    fwrite(name,sizeof(char),sizee,All);
    fprintf(All,"\n");
    printf("\nCourt:\n");
    scanf("%s",name);
    sizee=0;
    for(;name[sizee]!='\0';++sizee);
    fwrite(name,sizeof(char),sizee,All);
    fprintf(All,"\n");
    printf("\nTreasury:\n");
    scanf("%s",name);
    sizee=0;
    for(;name[sizee]!='\0';++sizee);
    fwrite(name,sizeof(char),sizee,All);
    fprintf(All,"\n");
    printf("\nChoice 2:\n");
    scanf("%s",name);
    sizee=0;
    for(;name[sizee]!='\0';++sizee);
    fwrite(name,sizeof(char),sizee,All);
    fprintf(All,"\n");
    printf("\nPeople:\n");
    scanf("%s",name);
    sizee=0;
    for(;name[sizee]!='\0';++sizee);
    fwrite(name,sizeof(char),sizee,All);
    fprintf(All,"\n");
    printf("\nCourt:\n");
    scanf("%s",name);
    sizee=0;
    for(;name[sizee]!='\0';++sizee);
    fwrite(name,sizeof(char),sizee,All);
    fprintf(All,"\n");
    printf("\nTreasury:\n");
    scanf("%s",name);
    sizee=0;
    exit(0);
}
