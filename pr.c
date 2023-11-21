#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
struct bloodgroup
{
	int blood[8];
}d;
void fun(int a)
{
	switch(a){
		case 1:
			printf("\t\t\t\t\t->blood group:A+              \n");
			break;
		case 2:
			printf("\t\t\t\t\t->blood group:O+              \n");
			break;
		case 3:
			printf("\t\t\t\t\t->blood group:B+              \n");
			break;
		case 4:
			printf("\t\t\t\t\t->blood group:AB+             \n");
			break;
		case 5:
			printf("\t\t\t\t\t->blood group:A-              \n");
			break;
		case 6:
			printf("\t\t\t\t\t->blood group:O-              \n");
			break;
		case 7:
			printf("\t\t\t\t\t->blood group:B-              \n");
			break;
		case 8:
			printf("\t\t\t\t\t->blood group:AB-             \n");
			break;								
	}
}
void display()
{
	printf("\t\t\t=================================================================\n");
    printf("\t\t\t*****  *      *****  ****   ****    *****     *****  *****  *****\n");
	printf("\t\t\t*   *  *      *      *   *  *       *         *   *  *      *   *\n");
	printf("\t\t\t*   *  *      *      *   *  *       *         *   *  *      *   *\n");
	printf("\t\t\t*****  *      *****  *   *  *  ***  *****     *****  *****  *   *\n");
	printf("\t\t\t*      *      *      *   *  *  * *  *         **     *      *   *\n");
	printf("\t\t\t*      *      *      *   *  *  * *  *         * *    *      *   *\n");
	printf("\t\t\t*      *****  *****  ****   **** *  *****     *  *   *****  ****\n");
	printf("\t\t\t=================================================================\n");
}
struct details
{
    char name[100];
    int weight;
    int age;
    char gender;
    int blood;
    char username[100];
    char password[100];
    char pincode[100];
    char rt[100];
    char phone[100];
}b;
struct login
{
    char username[100];
    char password[100];
    char phone[100];
}a;
int main()
{
	COORD c;
	int i;
    FILE *f1,*f2,*f3;
    for(i=0;i<8;i++){
    	d.blood[i]=0;
	}
    f3=fopen("blood","r");
    if(f3!=NULL && ftell(f3)==0){
    	fread(&d,sizeof(struct bloodgroup),1,f3);
	}
	fclose(f3);
    char ch,user[100],pass[100],pin[100];
    int choice;
    do
    {
    	display();
    	printf("\t\t\t\t\t+---+---------------------+\n");
        printf("\t\t\t\t\t| 1 |  Admin              |\n");
        printf("\t\t\t\t\t+---+---------------------+\n");
        printf("\t\t\t\t\t| 2 |  Donor              |\n");
        printf("\t\t\t\t\t+---+---------------------+\n");
        printf("\t\t\t\t\t| 3 |  blood requests     |\n");
        printf("\t\t\t\t\t+---+---------------------+\n");
        printf("\t\t\t\t\tEnter   your   choice    :");
        scanf("%d",&choice);
        system("CLS");
        switch(choice){
            case 1:
				display();
            	printf("\t\t\t\t\t+---+---------------------+\n");
		        printf("\t\t\t\t\t| 1 |  new registration   |\n");
		        printf("\t\t\t\t\t+---+---------------------+\n");
		        printf("\t\t\t\t\t| 2 |  login              |\n");
		        printf("\t\t\t\t\t+---+---------------------+\n");
		        printf("\t\t\t\t\tEnter   your   choice    :");
		        scanf("%d",&choice);
	        	system("CLS");
                if(choice==1){
                	display();
                	printf("\t\t\t\t\t****************************\n");
                    printf("\t\t\t\t\tEnter username:");
                    scanf("%s",a.username);
                    printf("\t\t\t\t\t****************************\n");
                    printf("\t\t\t\t\tEnter password:");
                    scanf("%s",a.password);
                    printf("\t\t\t\t\t****************************\n");
                    printf("\t\t\t\t\tEnter phone number:");
                    scanf("%s",a.phone);
                    f1=fopen("admin.data","a");
                    if(f1==NULL){
                    	printf("\t\t\t\t\tXXXXXXXXXXXXXXXXXXX\n");
                        fprintf(stderr, "\t\t\t\t\tXError opened fileX\n");
                        printf("\t\t\t\t\tXXXXXXXXXXXXXXXXXXX\n");
                        exit (1);
                    }
                    fwrite(&a,sizeof(struct login),1,f1);
                    if(fwrite!=0){
                    	printf("\t\t\t\t\t---------------------------------------\n");
                        printf("\t\t\t\t\tcontents to file written successfully !\n");
                        printf("\t\t\t\t\t---------------------------------------\n");
                        sleep(2);
                    }
                    else{
                    	printf("\t\t\t\t\t--------------------\n");
                        printf("\t\t\t\t\terror writing file !\n");
                        printf("\t\t\t\t\t--------------------\n");
                    }
                    fclose(f1);   
                }
                else{
                	display();
                	printf("\t\t\t\t\t****************************\n");
                    printf("\t\t\t\t\tEnter username:");
                    scanf("%s",user);
                    printf("\t\t\t\t\t****************************\n");
                    printf("\t\t\t\t\tEnter password:");
                    scanf("%s",pass);
                    system("CLS");
                    f1=fopen("admin.data","r");
                    int temp=1;
                    while(fread(&a,sizeof(struct login),1,f1)){
                        if(strcmp(user,a.username)==0 && strcmp(pass,a.password)==0){
                            temp=0;
                            break;
                        }
                    }
                    if(!temp){
                    	do
                    	{
                    		system("CLS");
                    		display();
	                    	printf("\t\t\t\t\t+---+---------------------+\n");
					        printf("\t\t\t\t\t| 1 |  all user details   |\n");
					        printf("\t\t\t\t\t+---+---------------------+\n");
					        printf("\t\t\t\t\t| 2 |  pincode search     |\n");
					        printf("\t\t\t\t\t+---+---------------------+\n");
							printf("\t\t\t\t\t| 3 | Blood group search  |\n");
							printf("\t\t\t\t\t+---+---------------------+\n");
							printf("\t\t\t\t\t| 4 | male donors list    |\n");
							printf("\t\t\t\t\t+---+---------------------+\n");
							printf("\t\t\t\t\t| 5 | female donors list  |\n");
							printf("\t\t\t\t\t+---+---------------------+\n");
							printf("\t\t\t\t\t| 6 | Blood packet details|\n");
							printf("\t\t\t\t\t+---+---------------------+\n");
							printf("\t\t\t\t\t| 7 | Donate Blood        |\n");
							printf("\t\t\t\t\t+---+---------------------+\n");
					        printf("\t\t\t\t\tEnter   your   choice    :");
					        scanf("%d",&choice);
				        	system("CLS");
	                        if(choice==1){
	                        	int i=0;
	                        	f2=fopen("user.data","r");
	                        	display();
		                        while(fread(&b,sizeof(struct details),1,f2)){
		                        	printf("\t\t\t\t\t******************           *\n");
		                            printf("\t\t\t\t\t#User %d details:            \n",++i);
		                            printf("\t\t\t\t\t******************           *\n");
		                            printf("\t\t\t\t\t->Name:%s                     \n",b.name);
		                            printf("\t\t\t\t\t->weight:%d                   \n",b.weight);
		                            printf("\t\t\t\t\t->Age:%d                      \n",b.age);
		                            printf("\t\t\t\t\t->gender:%c                   \n",b.gender);
		                            printf("\t\t\t\t\t->Phone:%s                    \n",b.phone);
		                            fun(b.blood);
		                            printf("\t\t\t\t\t->Pincode:%s                  \n",b.pincode);
		                        }
		                        sleep(2);
		                        fclose(f2);  	
							}
							else if(choice==2){
								int i=0;
								display();
								printf("\t\t\t\t\t******************************\n");
								printf("\t\t\t\t\tEnter pincode:");
								scanf("%s",pin);
								system("CLS");
								f2=fopen("user.data","r");
								display();
								temp=1;
		                        while(fread(&b,sizeof(struct details),1,f2)){
		                        	if(strcmp(pin,b.pincode)==0){
			                        	printf("\t\t\t\t\t******************           *\n");
			                            printf("\t\t\t\t\t#User %d details:            \n",++i);
			                            printf("\t\t\t\t\t******************           *\n");
			                            printf("\t\t\t\t\t->Name:%s                     \n",b.name);
			                            printf("\t\t\t\t\t->weight:%d                   \n",b.weight);
			                            printf("\t\t\t\t\t->Age:%d                      \n",b.age);
			                            printf("\t\t\t\t\t->gender:%c                   \n",b.gender);
			                            printf("\t\t\t\t\t->Phone:%s                    \n",b.phone);
			                            fun(b.blood);
										temp=0;	
									}
		                        }
		                        if(temp){
		                        	printf("\t\t\t\t\t No Donor at the %s pincode.\n",pin);
								}
		                        sleep(2);
		                        fclose(f2);  
							}
							else if(choice==3){
								int i=0,tem;
								display();
								printf("\t\t\t\t\t******************************\n");
								printf("\t\t\t\t\t+ --- + --- + --- + --- + --- + --- + --- + --- +\n");
				                printf("\t\t\t\t\t|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |\n");
				                printf("\t\t\t\t\t+ --- + --- + --- + --- + --- + --- + --- + --- +\n");
				                printf("\t\t\t\t\t|  A+ |  O+ |  B+ |  AB+|  A- |  O- |  B- |  AB-|\n");
				                printf("\t\t\t\t\t+ --- + --- + --- + --- + --- + --- + --- + --- +\n");
                				printf("\t\t\t\t\tEnter required blood group from above:");
								scanf("%d",&tem);
								system("CLS");
								f2=fopen("user.data","r");
								display();
								temp=1;
		                        while(fread(&b,sizeof(struct details),1,f2)){
		                        	if(tem==b.blood){
			                        	printf("\t\t\t\t\t******************           *\n");
			                            printf("\t\t\t\t\t#User %d details:            \n",++i);
			                            printf("\t\t\t\t\t******************           *\n");
			                            printf("\t\t\t\t\t->Name:%s                     \n",b.name);
			                            printf("\t\t\t\t\t->weight:%d                   \n",b.weight);
			                            printf("\t\t\t\t\t->Age:%d                      \n",b.age);
			                            printf("\t\t\t\t\t->gender:%c                   \n",b.gender);
			                            printf("\t\t\t\t\t->Phone:%s                    \n",b.phone);
			                            printf("\t\t\t\t\t->pincode:%s                  \n",b.pincode);
										temp=0;	
									}
		                        }
		                        if(temp){
		                        	printf("\t\t\t\t\t No Donor with ");
		                        	fun(tem);
								}
		                        sleep(2);
		                        fclose(f2);  
							}
							else if(choice==4){
								int i=0;
								display();
								f2=fopen("user.data","r");
								temp=1;
		                        while(fread(&b,sizeof(struct details),1,f2)){
		                        	if(b.gender=='M' || b.gender=='m'){
			                        	printf("\t\t\t\t\t******************           *\n");
			                            printf("\t\t\t\t\t#User %d details:            \n",++i);
			                            printf("\t\t\t\t\t******************           *\n");
			                            printf("\t\t\t\t\t->Name:%s                     \n",b.name);
			                            printf("\t\t\t\t\t->weight:%d                   \n",b.weight);
			                            printf("\t\t\t\t\t->Age:%d                      \n",b.age);
			                            printf("\t\t\t\t\t->Phone:%s                    \n",b.phone);
			                            fun(b.blood);
			                            printf("\t\t\t\t\t->pincode:%s                  \n",b.pincode);
										temp=0;	
									}
		                        }
		                        if(temp){
		                        	printf("\t\t\t\t\t No male donors\n");
								}
		                        sleep(2);
		                        fclose(f2);  
							}
							else if(choice==5){
								int i=0;
								display();
								f2=fopen("user.data","r");
								temp=1;
		                        while(fread(&b,sizeof(struct details),1,f2)){
		                        	if(b.gender=='f' || b.gender=='F'){
			                        	printf("\t\t\t\t\t******************           *\n");
			                            printf("\t\t\t\t\t#User %d details:            \n",++i);
			                            printf("\t\t\t\t\t******************           *\n");
			                            printf("\t\t\t\t\t->Name:%s                     \n",b.name);
			                            printf("\t\t\t\t\t->weight:%d                   \n",b.weight);
			                            printf("\t\t\t\t\t->Age:%d                      \n",b.age);
			                            printf("\t\t\t\t\t->Phone:%s                    \n",b.phone);
			                            fun(b.blood);
			                            printf("\t\t\t\t\t->pincode:%s                  \n",b.pincode);
										temp=0;	
									}
		                        }
		                        if(temp){
		                        	printf("\t\t\t\t\t No female donors\n");
								}
		                        sleep(2);
		                        fclose(f2);  
							}
							else if(choice==7){
								display();
								printf("\t\t\t\t\t+ --- + --- + --- + --- + --- + --- + --- + --- +\n");
								printf("\t\t\t\t\t|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |\n");
								printf("\t\t\t\t\t+ --- + --- + --- + --- + --- + --- + --- + --- +\n");
								printf("\t\t\t\t\t|  A+ |  O+ |  B+ |  AB+|  A- |  O- |  B- |  AB-|\n");
								printf("\t\t\t\t\t+ --- + --- + --- + --- + --- + --- + --- + --- +\n");
								printf("\t\t\t\t\tEnter blood group for donation:");
								int tem;
								scanf("%d",&tem);
								d.blood[tem-1]--;
								if(d.blood<0){
									printf("No blood packets");
									fun(tem);
									d.blood[tem-1]=0;
								}
								else{
									printf("Donation succesful");
								}
								sleep(2);
								system("CLS");
							}
							else{
								display();
								printf("\t\t\t+ -------------- + --- + --- + --- + --- + --- + --- + --- + --- +\n");
			                	printf("\t\t\t|  Blood group   |  A+ |  O+ |  B+ |  AB+|  A- |  O- |  B- |  AB-|\n");
			                	printf("\t\t\t+ -------------- + --- + --- + --- + --- + --- + --- + --- + --- +\n");
			                	printf("\t\t\t|  no.of packets |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |  %d  |\n",d.blood[0],d.blood[1],d.blood[2],d.blood[3],d.blood[4],d.blood[5],d.blood[6],d.blood[7]);
			                	printf("\t\t\t+ -------------- + --- + --- + --- + --- + --- + --- + --- + --- +\n");
			                	sleep(2);
							} 
							printf("\t\t\t\t\t*****************************\n");
							printf("\t\t\t\t\tDo you want to logout as admin:");
							scanf("\n%c",&ch);
						}while(ch!='Y' && ch!='y');
                }
                    else{
                    	printf("\t\t\t\t\txxxxxxxxxxxxxx\n");
                    	printf("\t\t\t\t\t OOPS NO DATA \n");
                    	printf("\t\t\t\t\txxxxxxxxxxxxxx\n");
                    	sleep(2);
                    	system("CLS");
					}
					fclose(f1);
                }
            break;
            case 2:	
            display();
            printf("\t\t\t\t\t+---+---------------------+\n");
			printf("\t\t\t\t\t| 1 |  new registration   |\n");
			printf("\t\t\t\t\t+---+---------------------+\n");
			printf("\t\t\t\t\t| 2 |  login              |\n");	
			printf("\t\t\t\t\t+---+---------------------+\n");
			printf("\t\t\t\t\tEnter   your   choice    :");
			scanf("%d",&choice);	
        	system("CLS");
            if(choice==1){
            	display();
            	printf("\t\t\t\t\t***********\n");	
                printf("\t\t\t\t\tEnter name:");
                getchar();
                gets(b.name);
                printf("\t\t\t\t\t***********\n");
                printf("\t\t\t\t\tEnter weight:");
                scanf("%d",&b.weight);
                printf("\t\t\t\t\t***********\n");
                printf("\t\t\t\t\tEnter age:");
                scanf("%d",&b.age);
                printf("\t\t\t\t\t***********\n");
                printf("\t\t\t\t\tEnter gender:");
                scanf("\n%c",&b.gender);
                printf("\t\t\t\t\t+ --- + --- + --- + --- + --- + --- + --- + --- +\n");
                printf("\t\t\t\t\t|  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |\n");
                printf("\t\t\t\t\t+ --- + --- + --- + --- + --- + --- + --- + --- +\n");
                printf("\t\t\t\t\t|  A+ |  O+ |  B+ |  AB+|  A- |  O- |  B- |  AB-|\n");
                printf("\t\t\t\t\t+ --- + --- + --- + --- + --- + --- + --- + --- +\n");
                printf("\t\t\t\t\tEnter your blood group from above:");
                scanf("%d",&b.blood);
				d.blood[b.blood-1]++;
				printf("\t\t\t\t\tEnter phone number:");
				scanf("%s",b.phone);
				printf("\t\t\t\t\t***********\n");
                printf("\t\t\t\t\tEnter username:");
                scanf("%s",b.username);
                printf("\t\t\t\t\t***********\n");
                printf("\t\t\t\t\tEnter password:");
                scanf("%s",b.password);
                printf("\t\t\t\t\t***********\n");
                printf("\t\t\t\t\tEnter your pincode:");
                scanf("%s",b.pincode);
                printf("\t\t\t\t\t***********\n");
                printf("\t\t\t\t\tAre you sufferning from any chronic disease:");
                scanf("\n%c",&ch);
                f2=fopen("user.data","a");
                if(f2==NULL){
                    fprintf(stderr, "\t\t\t\t\t\nError opened file\n");
                    sleep(2);
                    system("CLS");
                    exit (1);
                }
                if(b.weight>=50 && b.age>=18 && ch!='y' && ch!='Y'){
	                fwrite(&b,sizeof(struct details),1,f2);
	                if(fwrite!=0){
	                	printf("\t\t\t\t\t-----------------------------------------\n");
	                    printf("\t\t\t\t\t contents to file written successfully ! \n");
	                    printf("\t\t\t\t\t-----------------------------------------\n");
	                    sleep(2);
	                    system("CLS");
	                }
	                else{
	                	printf("\t\t\t\t\t----------------------\n");
	                    printf("\t\t\t\t\t error writing file ! \n");
	                    printf("\t\t\t\t\t----------------------\n");
	                    sleep(2);
	                    system("CLS");
	                }
				}
				else{
					printf("\t\t\t\t\t-----------------------------------\n");
					printf("\t\t\t\t\t You are unfit for blood donation. \n");
					printf("\t\t\t\t\t-----------------------------------\n");
					sleep(2);
					system("CLS");
				}
                
                fclose(f2);
            }
            else{
            	display();
            	printf("\t\t\t\t\t********************\n");
                printf("\t\t\t\t\tEnter username:");
                scanf("%s",user);
                printf("\t\t\t\t\t********************\n");
                printf("\t\t\t\t\tEnter password:");
                scanf("%s",pass);
                system("CLS");
                f2=fopen("user.data","r");
                int temp=1;
                display();
                printf("\t\t\t\t\t******************************\n");
	            while(fread(&b,sizeof(struct details),1,f2)){
	                if(strcmp(user,b.username)==0 && strcmp(pass,b.password)==0){
	                    printf("\t\t\t\t\t******************           *\n");
	                    printf("\t\t\t\t\t#User details:               *\n");
	                    printf("\t\t\t\t\t******************           *\n");
	                    printf("\t\t\t\t\t->Name:%s                     \n",b.name);
	                    printf("\t\t\t\t\t->weight:%d                   \n",b.weight);
	                    printf("\t\t\t\t\t->Age:%d                      \n",b.age);
	                    printf("\t\t\t\t\t->gender:%c                   \n",b.gender);
	                    printf("\t\t\t\t\t->Phone:%s                    \n",b.phone);
	                    fun(b.blood);
	                    printf("\t\t\t\t\t->Pincode:%s                  \n",b.pincode);
	                    sleep(2);
	                    temp=0;
                        break;
               		}
	            }
                if(temp){
                	system("CLS");
                	display();
                	printf("\t\t\t\t\t------------------------------------\n");
                    printf("\t\t\t\t\t username or password is incorrect. \n");
                    printf("\t\t\t\t\t------------------------------------\n");
                    sleep(2);
                }
                fclose(f2);
            }
            break;
            case 3:
            	display();
            	printf("\t\t\t\t\t-----------------\n");
            	printf("\t\t\t\t\t Contact admins: \n");
            	printf("\t\t\t\t\t-----------------\n");
            	f1=fopen("admin.data","r");
            	printf("\t\t\t\t\t******************************\n");
                while(fread(&a,sizeof(struct login),1,f1)){
                    printf("\t\t\t\t\t %s     :%s            \n",a.username,a.phone);
                }
                sleep(2);
                fclose(f1);    
        }
        printf("\t\t\t\t\t******************************\n");
        printf("\t\t\t\t\tDo you want to return to main menu(Y/N):");
        getchar();
        scanf("%c",&ch);
        system("CLS");
    }while(ch=='Y' || ch=='y');
    f3=fopen("blood","w");
    fwrite(&d,sizeof(struct bloodgroup),1,f3);
    fclose(f3);
    printf("                                   ----------------------------------------------\n");
    printf("                                         * * * * * * * *  * * * * * * * *\n");
    printf("                                         * * * * * * * *  * * * * * * * *\n");
    printf("                                               * *        * *         * * \n");
    printf("                                               * *        * *         * * \n");
    printf("                                               * *        * *         * *\n");
    printf("                                               * *        * *  * *    * *\n");
    printf("                                               * *        * *   * *   * *\n");
    printf("                                               * *        * * * * * * * * \n");
    printf("                                               * *        * * * * * * * * \n");
    printf("                                               * *                 * *\n");
    printf("                                   -----------------------------------------------\n");
    return 0;
}
