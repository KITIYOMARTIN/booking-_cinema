#include"stdio.h"
#include"stdlib.h"
#include"conio.h"
#include"process.h"
#define pf printf
#include"string.h"
#include"dos.h"
int sum=0;
struct time
{
	char hour[50];
	char minute[50];
};
struct seat
{
	char ben[10];
	int rate;
};
struct movie
{ int srlno;
	char type[50];
char name[50];
struct time str;
struct time end;
struct seat ken[50];
};
struct screen
{
	struct movie b[4];
	
};
struct day
{
	struct screen d[5];
}da[3];
void input()
{int j,k,z;
FILE *fp;
fp=fopen("movies.txt","r");
		for(j=0;j<5;j++)
		{
			for(k=0;k<4;k++)
			{
				fgets(da[0].d[j].b[k].type,100,fp);da[0].d[j].b[k].type[strlen(da[0].d[j].b[k].type)-1]='\0'; // \0 to manage the enter which was causing error
                fgets(da[0].d[j].b[k].name,100,fp);da[0].d[j].b[k].name[strlen(da[0].d[j].b[k].name)-1]='\0';
                fgets(da[0].d[j].b[k].str.hour,100,fp);da[0].d[j].b[k].str.hour[strlen(da[0].d[j].b[k].str.hour)-1]='\0';
                fgets(da[0].d[j].b[k].str.minute,100,fp);da[0].d[j].b[k].str.minute[strlen(da[0].d[j].b[k].str.minute)-1]='\0';
                fgets(da[0].d[j].b[k].end.hour,100,fp);da[0].d[j].b[k].end.hour[strlen(da[0].d[j].b[k].end.hour)-1]='\0';
				fgets(da[0].d[j].b[k].end.minute,100,fp);da[0].d[j].b[k].end.minute[strlen(da[0].d[j].b[k].end.minute)-1]='\0';
			}
		}
     fclose(fp);
	  FILE *fl;
     fl=fopen("seat.txt","r");
     for(j=0;j<5;j++)//store seats
		{
			for(k=0;k<4;k++)
			{
				for(z=0;z<50;z++)
				{
						fgets(da[0].d[j].b[k].ken[z].ben,10,fl);da[0].d[j].b[k].ken[z].ben[strlen(da[0].d[j].b[k].ken[z].ben)-2]='\0'; // values stored as string
				}
			}
		}	fclose(fl);
}
void ticket(char s[100])
{int i,j,k,n,f,p,z,sit; char m[10];//for converting rate to string line 119
	pf("\n\n\nSERIAL\tMOVIE\t\t\tSTART\t\t\tEND\n");z=1;
					 for(j=0;j<5;j++)
		              {f=0;
					  pf("---------------------\nSCREEN %d\t    }\n---------------------\n",j+1);
			            for(k=0;k<4;k++)
			               { 
			               	if((stricmp(da[0].d[j].b[k].type,s)==0)||(stricmp(s,"ALL")==0))
			               	{ da[0].d[j].b[k].srlno=z;                        // z is denote serial no. to movies
			               		pf("%d\t%s\n\t\t\t\t%s:%s\t\t\t%s:%s\n",z,da[0].d[j].b[k].name,da[0].d[j].b[k].str.hour,da[0].d[j].b[k].str.minute,da[0].d[j].b[k].end.hour,da[0].d[j].b[k].end.minute);
							 pf("________________________________________________________________\n");f=-1;
							  z++; }	
			               }
			               if(f!=-1)
			               pf("NO %s MOVIE\n",s);
			           }
			           pf("\n\n\t\t\t===============\n\t\t\tCHOOSE A MOVIE\n\t\t\t===============\n\nYour Input--->");
			           scanf("%d",&n);p=0;
			           for(j=0;j<5;j++)
		                {
		                   	for(k=0;k<4;k++)
		                    	{       
		                    		if(da[0].d[j].b[k].srlno==n)        //find the input in the data
		                    		{ do{  f=0;//continue after wrong input
									pf("\t\t\t\t========\n\t\t\t\t|SCREEN|\n\t\t\t\t========\n\n-------------------------------------------------------------------------------\nEACH SEAT FROM [1-20] IS Rs.100\n-------------------------------------------------------------------------------\n");
		                    			for(i=0;i<50;i++)       //printing the seats
		                    			{   
		                    				pf("[%s]  ",da[0].d[j].b[k].ken[i].ben);
		                    				if(i<20)
		                    				da[0].d[j].b[k].ken[i].rate=150;
		                    				if((i>=20)&&(i<40))
		                    				da[0].d[j].b[k].ken[i].rate=200;
		                    				if((i>=40)&&(i<50))
		                    				da[0].d[j].b[k].ken[i].rate=250;
											if((i+1)%5==0)
		                    			  pf("   \t ");
		                    			  if((i+1)%10==0)
		                    			  pf("\n\n");
		                    			  if(i==19)
		                    			  pf("\n-------------------------------------------------------------------------------\nEACH SEAT FROM [21-40] IS Rs.200\n-------------------------------------------------------------------------------\n");
		                    			  if(i==39)
		                    			  pf("\n-------------------------------------------------------------------------------\nEACH SEAT FROM [41-50] IS Rs.250\n-------------------------------------------------------------------------------\n");
										}pf("\n\n\t\t\tSeats with BB are already booked.\n\t\t\t-----------------------------------\nChoose your seat--->");
		                                  scanf("%d",&sit);
		                                  
		                                  if(strcmp(da[0].d[j].b[k].ken[sit-1].ben,"BB")==0)
		                                  {
		                                  	pf("\n\n\t\t\tTRY AGAIN\n");f=-1;
										  }strcpy(da[0].d[j].b[k].ken[sit-1].ben,"BB");
									}while(f==-1);FILE *o;o=fopen("final.txt","a");
									fputs(da[0].d[j].b[k].name,o);fputs("  \n",o);
									fputs(strcat(strcat(da[0].d[j].b[k].str.hour,": "),da[0].d[j].b[k].str.minute),o);fputs(" \n",o);
									fputs(strcat(strcat(da[0].d[j].b[k].end.hour,": "),da[0].d[j].b[k].end.minute),o);fputs(" \n",o);
									itoa(da[0].d[j].b[k].ken[sit-1].rate,m,10);//convert rate to string
									fputs(m,o);fputs(" \n",o);fclose(o);
		                                  pf("Your bill--->%d",sum+=da[0].d[j].b[k].ken[sit-1].rate);
		                                  
									p=-1;break;
									}
									if(p==-1)                       //f is to check and terminate itteration after task is done
		                    	break;
		                    	}
		                    }
}
void writeo()
{int j,k,i;
	 FILE *fl;
     fl=fopen("seat.txt","w");
	            for(j=0;j<5;j++)
		                {
		                   	for(k=0;k<4;k++)
		                    	{ 
								for(i=0;i<50;i++)       //writing the seats
		                    		{
									 fputs(da[0].d[j].b[k].ken[i].ben,fl);fputs(" \n",fl);
		                    		}
		                    }
						}fclose(fl);
}

void main()
{	FILE *fp;fp=fopen("final.txt","w");fclose(fp);//to flush final everytime the program runs
    pf("\t\t\t==============================\n");
	pf("\t\t\t|  WELCOME TO INDIAN CINEMA  | \n");
	pf("\t\t\t==============================\n");
int i,j,k,n,f,z,sit;
input();sleep(2);pf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

do
{f=0;
    pf("\t\t\t{1} TO SHOW MOVIE BY TYPE\n\t\t\t{2} TO SHOW MOVIE BY NAME\n\nYour Input-->");
    scanf("%d",&n);


    

     switch(n)
     {
     	case 1: do
     	{        f=0;
		        pf("\n\t\t\t{1} FOR BOLLYWOOD\n\t\t\t{2} FOR TOLLYWOOD\n\t\t\t{3} FOR HOLLYWOOD\n\nYour Input-->");
     	        scanf("%d",&n);
     	        switch(n)
     	        {
     	        	case 1:ticket("BOLLYWOOD ");break;
     	        	case 2:ticket("TOLLYWOOD ");break;
     	        	case 3:ticket("HOLLYWOOD ");break;
     	        	default:pf("INCORRECT INPUT PLEASE TRY AGAIN");f=-1;
     	        }
     	}while(f==-1);break;
     	case 2:ticket("ALL");break;
     	default:pf("\t\t\tINCORRECT INPUT PLEASE TRY AGAIN");f=-1;
		  }pf("\n\n\n\n\n\n\n\n\n\t\t\tDO YOU WISH TO CONTINUE BUYING\n\t\t\t1)YES\n\t\t\t2)NO\n\nYour Answer--->");
					       scanf("%d",&n);
						   if(n==1)
						   f=-1;  //to continue
		  }while(f==-1);                  
		                    	writeo();
		                    char nam[20],num[20],mail[30];
		                
		                fp=fopen("details.txt","a");
		                	pf("\nPLEASE FILL THE DETAILS\nNAME-->\t\t");
		                	scanf("%s",nam);
		                	fputs(nam,fp);fputs("\n",fp);
		                	pf("\nNUMBER-->\t");
		                	scanf("%s",num);
		                	fputs(num,fp);fputs("\n",fp);
		                	pf("\nEMAIL-->\t");
		                	scanf("%s",mail);
		                	fputs(mail,fp);fputs("\n",fp);fclose(fp);
		                	pf("\nCONGRATULATION ! YOU HAVE SUCCESSFLLY BOOKED YOUR TICKET");sleep(1);
		                	pf("\n\n\n\n\n\n\n\n\n\t\t\t\t\tCONTENTS\n\t\t\t\t\t=========");
		                	pf("\nNAME\t\tSTART\t\tEND\tCOST\n");
		                	fp=fopen("final.txt","r");i=1;
		                	while(fgets(nam,50,fp)!=NULL)
		                	{nam[strlen(nam)-2]='\0';
		                	pf("%s\t",nam);
							if(i%4==0)
							pf("\n\n");i++;	
							}
							pf("\n\nTOTAL--->%d",sum);
		                	pf("\n\nYOUR TICKETS WILL BE MAILED TO %s",mail);
		                    
		                	pf("\n\n\n\n\n\t\t\t**** THANK YOU ! HAVE A NICE DAY ****");
			           sleep(3);
			           
     	        		
				}
	 
