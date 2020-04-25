//HOSPITAL MANAGEMENT SYSTEM

//final project
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct doc
{
	int id;//every doctor has a unique id
	char name[60];//contains doctor name
	int age;
	char add[70];
	char deg[40];//contains degree of doctor
	char special[100];//conatins description of doctor's field of interest
	char cabin_no[4];//contains doctor's cabin number
	char timmimg[15];//conatins doctor's timing in hospital
	struct doc *next;
}*root=NULL;


struct patient
{
	char name[45];
	int age;
	char sex;
	char add[80];
	char disease[50];
	intref_doc_id;
	char date[12];
	char room_no[5];
    struct patient *next;
}*head=NULL;


struct medicine
{
	char med_name[15];
	char mfg_date[12];
	char exp_date[12];
	float price;
	int quantity;
	struct medicine *after;
}*first=NULL;


struct staff
{
	char name[40];
	int id;
	int age;
	char add[50];
	char desig[20];
	long ph_num;
	double salary;
	struct staff *next;
}*top=NULL;

void doctor_field();
void patient_field();
void medicine_field();
void staff_field();

void doc_insertion();
void doc_display();
void doc_deletion();
void doc_alldisplay();
void doc_disp();
void doc_modification();
void doc_doctors();
//void doc_input_doc(struct doc *temp);

void pat_insertion();
void pat_display();
void pat_disp(struct patient *temp);
void pat_amount();

void med_insertion();
void med_display();
void med_disp(struct medicine *temp);
void med_modification();
void med_deletion();
float medname1(int t);

void staff_insertion();
void staff_display();
void staff_alldisplay();
void staff_disp(struct staff *temp);
void staff_modification();
void staff_deletion();

char ch;
intnum;

void main()
{
	//char num;
	char ch;
	system("cls");
	while(1)
	{
		printf("\n\n\n\n\t\t\t\tHOSPITAL MANAGEMENT SYSYTEM\n\t\t Choose the option: \n\t\t 1) Doctor\n\t\t 2) Medicine Dept.\n\t\t 3) patient \n\t\t 4) Staff \n\t\t 5) Exit. \n\n\t\t Enter the option: ");
		scanf("%d",&num);
		fflush(stdin);
		switch(num)
		{
			case 1:
				doctor_field();
				break;
			case 2:
				medicine_field();
				break;
			case 3:
				patient_field();
				break;
			case 4:
				staff_field();
				break;
			case 5:
				system("cls");
				{
					printf("\n\n\n\n\n\n\t\t\t\t\tCreated BY: \n\t\t1) AJEETHRA Ba.\n\t\t2) KUMAR ABHISHEK\n\t\t3) SHUBHAM GUPTA");
					printf("\n\n\t\tPress any key\n\n");
					fflush(stdin);
					getch();
					exit(0);
				}
			default:
				{
					printf("\nInvalid Input");
					getch();
					system("cls");
				}
		}
	}
}


void doctor_field()
{
	int num1;
	while(1)
	{
		system("cls");
		printf("\n\n\n\t\t\t\tDOCTOR's FIELD\n\t\t 1) Enter Doctor's Details\n\t\t 2) Display Doctor's Dtails\n\t\t 3) Delete the Record\n\t\t 4) Records Modification\n\t\t 5) Display doctor's name and id \n\t\t 6) exit \n\n\t\t Enter the option: ");
		scanf("%d",&num);
		fflush(stdin);
		switch(num)
		{
			case 1:
				do
				{
					doc_insertion();
					printf("\nDo You add more(Y/N): ");
					scanf("%c",&ch);
					fflush(stdin);
				}while(ch=='Y'||ch=='y');
				break;
			case 2:
				{
					if(root==NULL)
					{
						printf("No Records !!!");
						fflush(stdin);
						getch();
					}
					else
					{
						system("cls");
						printf("\n\n\t\t\tDOCTORS INFORMATION\n\t\t 1) to display selected id\n\t\t 2) for total display:\n\t\t Choose the option: ");
						scanf("%d",&num1);
						switch(num1)
						{
							case 1:
								doc_display();
								break;
							case 2:
								doc_alldisplay();
								break;
							default:
								printf("\nInvalid input");
						}
					}
				}
				break;
			case 3:
				{
					if(root==NULL)
					{
						printf("No Records!!!");
						fflush(stdin);
						getch();
					}
					else
						doc_deletion();
				}
				break;
			case 4:
				if(root==NULL)
				{
					printf("No records!!!");
					fflush(stdin);
					getch();
				}
				else
				{
					system("cls");
					ch='N';
					do
					{
						doc_modification();
						if(root!=NULL)
						{
							printf("\nDo u want to modiify more(Y/N): ");
							scanf("%c",&ch);
						}
					}while(ch=='Y'||ch=='y');
				}
				break;
			case 5:
				if(root==NULL)
				{
					printf("\nNo Records!!!");
					fflush(stdin);
					getch();
				}
				else
					doc_doctors();
				break;
			case 6:
				main();
			default:
				{
					printf("\nInvalid Input, Try Again!!!\n");
					fflush(stdin);
					getch();
				}
		}
	}
}


void doc_insertion()
{
	int m=0;
	system("cls");
	struct doc *temp;
	char abc;
	temp=(struct doc*)malloc(sizeof(struct doc));
	printf("\nEnter the details:\n");
	printf("Doctor's id(3 digits): ");
	scanf("%d",&temp->id);
	fflush(stdin);
	printf("Name: ");
	scanf("%[^\n]",temp->name);
	printf("Age: ");
	scanf("%d",&temp->age);
	fflush(stdin);
	printf("Address: ");
	scanf("%[^\n]",temp->add);
	fflush(stdin);
	printf("Degree: ");
	scanf("%[^\n]",temp->deg);
	fflush(stdin);
	printf("Speciliaziton Details: ");
	scanf("%[^\n]",temp->special);
	fflush(stdin);
	printf("Cabin no: ");
	scanf("%[^\n]",temp->cabin_no);
	fflush(stdin);
	printf("Timming: ");
	scanf("%[^\n]",temp->timmimg);
	fflush(stdin);
	temp->next=NULL;
	if(root==NULL)
	root=temp;
	else
	{
		struct doc *p,*q;
		p=root;
		while(p)
		{
			if(temp->id==p->id)
			{
				m=1;
				break;
			}
			p=p->next;
		}
		if(m==1)
		{
			printf("\n Id already exist, Try again!!!");
			doc_insertion();
		}
		else
		{
			p=root;
			if(p->next==NULL )
			{
				if(p->id>temp->id)
				{
					temp->next=p;
					root=temp;
					p->next=NULL;
				}
				else
					p->next=temp;
			}
			else
			{
				while(p->next!=NULL)
				{
					q=p;
					p=p->next;
					if(p->id>temp->id)
					{
						temp->next=p;
						q->next=temp;
						m=2;
					}
				}
				if(m!=2)
					p->next=temp;
			}
		}
	}
}

void doc_display()
{
	system("cls");
	int tar;
	struct doc *temp;
	printf("\nEnter the doctor's id'");
	scanf("%d",&tar);
	temp=root;
	if(root->next==NULL && root->id==tar)
	{
		printf("\t\t\t\tDetails of Given id\n");
		doc_disp(temp);
	}
	else if(root->next!=NULL)
	{
		while(temp->id!=tar)
		{
			temp=temp->next;
			if(temp->next==NULL)
			break;
		}
			if(temp->id==tar)
		{
			printf("\t\t\t\tDetails of Given id\n");
			doc_disp(temp);
		}
		else
		{
			printf("\nInvalid id\n");
		}
	}
	else
		printf("\nInvalid Input\n");
	fflush(stdin);
	getch();
}

void doc_deletion()
{
	int tar;
	struct doc *temp;
	printf("\nEnter the id which u want to delete: ");
	scanf("%d",&tar);
	if(root->id==tar)
	{
		if(root->next==NULL)
		{
			temp=root;
			root=NULL;
			free(temp);
			printf("\nRecord has deleted");
			fflush(stdin);
			getch();
		}
		else
		{
			temp=root;
			root=root->next;
			temp->next=NULL;
			free(temp);
			printf("\nRecord has deleted");
			fflush(stdin);
			getch();
		}
	}
	else
	{
		struct doc *p;
		temp=root;
		while(temp->id!=tar)
		{
			p=temp;
			if(temp->next==NULL)
			break;
			temp=temp->next;
		}
		if(temp->id==tar)
		{
			if(temp->next==NULL)
			{
				p->next=NULL;
				free(temp);
				printf("\nRecord has deleted");
				fflush(stdin);
				getch();
			}
			else
			{
				struct doc *q;
				q=temp->next;
				p->next=q;
				temp->next=NULL;
				free(temp);
				printf("\nRecord has deleted");
				fflush(stdin);
				getch();
			}
		}
		else
		{
			printf("\nInvalid Input");
			fflush(stdin);
			getch();
		}
	}
}

void doc_alldisplay()
{
	system("cls");
	struct doc *temp;
	//temp=(struct doc*)malloc(sizeof(struct doc));
	temp=root;
	printf("\t\t\t\tDetails of Given id\n");
	if(root->next==NULL)
	doc_disp(root);
	else
	{
		while(temp->next!=NULL)
		{
			doc_disp(temp);
			temp=temp->next;
		}
		doc_disp(temp);
	}
	fflush(stdin);
	getch();
}

void doc_disp(struct doc *temp)
{
	printf("\nName: %s",temp->name);
	printf("\nId: %d",temp->id);
	printf("\nAge: %d",temp->age);
	printf("\nAddress: %s",temp->add);
	printf("\nDegree: %s",temp->deg);
	printf("\nSpecialization: %s",temp->special);
	printf("\nCabin number: %s",temp->cabin_no);
	printf("\nTimming: %s",temp->timmimg);
	printf("\n\n");
}
void doc_modification()
{
	intnum;
	struct doc *temp,*p;
	printf("Enter the id: ");
	scanf("%d",&num);
	temp=root;
	while(temp->id!=num)
	{
		if(temp->next==NULL)
		break;
		temp=temp->next;
	}
	if(temp->id==num)
	{
		fflush(stdin);
		printf("Name: ");
		scanf("%[^\n]",temp->name);
		printf("Age: ");
		scanf("%d",&temp->age);
		fflush(stdin);
		printf("Address: ");
		scanf("%[^\n]",temp->add);
		fflush(stdin);
		printf("Degree: ");
		scanf("%[^\n]",temp->deg);
		fflush(stdin);
		printf("Speciliaziton Details: ");
		scanf("%[^\n]",temp->special);
		fflush(stdin);
		printf("Cabin no: ");
		scanf("%s",temp->cabin_no);
		fflush(stdin);
		printf("Timming: ");
		scanf("%[^\n]",temp->timmimg);
	}
	else
	{
		printf("\nInvalid Input");
		fflush(stdin);
		getch();
	}
}

void doc_doctors()
{
	system("cls");
	char ch;
	//to display doctor's name and their id
	struct doc *temp;
	temp=(struct doc*)malloc(sizeof(temp));
	temp=root;
	if(root->next==NULL)
		printf("\nId = %d     Name: %s",temp->id,temp->name);
	else
	{
		while(temp->next!=NULL)
		{
			printf("\nId = %d     Name: %s",temp->id,temp->name);
			temp=temp->next;
		}
		printf("\nId = %d     Name: %s",temp->id,temp->name);
	}
	fflush(stdin);
	ch=getchar();
}


//MEDICAL REPORT
void medicine_field()
{
	int n;
	system("cls");
	while(1)
	{
		system("cls");
		printf("\n\n\t\t\t MEDICINE INFORMATION\n\t\t 1) Medicines' Deatils\n\t\t 2) Medicine Display\n\t\t 3) Record's Modification \n\t\t 4) Deletion of record\n\t\t 5) exit:\n\t\t Enter Option:  ");
		scanf("%d",&n);
		fflush(stdin);
		switch(n)
		{
			case 1:
				med_insertion();
				break;
			case 2:
				if(first==NULL)
					printf("\nNo Records!!!");
				else
					med_display();
				break;
			case 3:
				{
					if(first==NULL)
						printf("\nNo Records!!!");
					else
						med_modification();
					break;
				}
			case 4:
				med_deletion();
				break;
			case 5:
				main();
			default:
				{
					printf("\nInvalid Input");
					fflush(stdin);
					getch();
					system("cls");
				}
		}

	}
}

void med_insertion()
{
	system("cls");
	struct medicine *temp;
	temp=(struct medicine*)malloc(sizeof(struct medicine));
	printf("\n\tEnter medicine details: ");
	fflush(stdin);
	printf("\nMedicine name: ");
	scanf("%[^\n]",temp->med_name);
	fflush(stdin);
	printf("Manufacturing date(dd/mm/yyyy): ");
	scanf("%[^\n]",temp->mfg_date);
	fflush(stdin);
	printf("Expiry date(dd/mm/yyyy): ");
	scanf("%[^\n]",temp->exp_date);
	fflush(stdin);
	printf("Price of 1 pac.: ");
	scanf("%f",&temp->price);
	printf("Quantity: ");
	scanf("%d",&temp->quantity);
	temp->after=NULL;
	if(first==NULL)
	{
		first=temp;
	}
	else
	{
		struct medicine *p;
		p=first;
		while(p->after!=NULL)
		{
			p=p->after;
		}
		p->after=temp;
	}
}


intdoc_ref()
{
	intide,m=0;
	printf("Enter consulting doctor id:");
	scanf("%d",&ide);
	struct doc *temp;
	temp=root;
	while(temp!=NULL)
	{
		if(temp->id==ide)
		{
			m=1;
			break;
		}
		temp=temp->next;
	}
	if(m==0)
	{
		printf("\nInvalid input\n");
		doc_ref();
	}
	else
		return ide;
}

void med_display()
{
	intnum;
	struct medicine *temp;
	temp=(struct medicine*)malloc(sizeof(struct medicine));
	char tar[45];
	intlp=0,res;
	fflush(stdin);
	printf("\n\t\t\t MEDICINE LIST\n\t\t 1) for details of specific medicine\n\t\t 2) for total dispaly: ");
	scanf("%d",&num);
	switch(num)
	{
		case 1:
		{

			printf("\nEnter the medicine name: ");
			fflush(stdin);
			scanf("%[^\n]",tar);
			temp=first;
			if(first->after==NULL)
			{
				res=strcmp(first->med_name,tar);
				if(res==0)
				{
					med_disp(first);
					lp=1;
				}
			}
			else
			{
				do
				{
					res=strcmp(temp->med_name,tar);
					if(res==0)
					{
						printf("\n\t\tDETAILS: ");
						med_disp(temp);
						lp=1;
						temp=temp->after;
					}
					else
					{
						lp=0;
						temp=temp->after;
					}
				}while(temp->after!=NULL);
			}
			if(lp==0)
			{
				res=strcmp(temp->med_name,tar);
				if(res==0)
					med_disp(temp);
				else
					printf("Target is not in the list");
			}
		}
		break;
		case 2:
			{
				system("cls");
				printf("\t\tMedicine Details: ");
				temp=first;
				while(temp!=NULL)
				{
					med_disp(temp);
					temp=temp->after;
				}
				fflush(stdin);
				getch();
			}
			break;
		default:
			{
				printf("\n\nInvalid Input\n\n");
				fflush(stdin);
				getch();
			}
	}
}


void med_disp(struct medicine *temp)
{
	printf("\nMedicine name: %s",temp->med_name);
	printf("\nManufacturing date: %s",temp->mfg_date);
	printf("\nExpiry date: %s",temp->exp_date);
	printf("\nPrice of 1 pac.: %f",temp->price);
	printf("\nQuantity: %d\n\n",temp->quantity);
	printf("\n");
}

void med_modification()
{
	struct medicine *temp;
	temp=(struct medicine*)malloc(sizeof(struct medicine));
	temp=first;
	char tar[15];
	fflush(stdin);
	printf("Enter the medicine name: ");
	scanf("%[^\n]",tar);
	int res;
	res=strcmp(temp->med_name,tar);
	while(res!=0)
	{
		if(temp->after==NULL)
		break;
		else
		{
			temp=temp->after;
			res=strcmp(temp->med_name,tar);
		}
	}
	if(res==0)
	{
		fflush(stdin);
		printf("Manufacturing date: ");
		scanf("%[^\n]",temp->mfg_date);
		fflush(stdin);
		printf("Expiry date: ");
		scanf("%[^\n]",temp->exp_date);
		fflush(stdin);
		printf("Price of 1 pac.: ");
		scanf("%f",&temp->price);
		printf("Quantity: ");
		scanf("%d",&temp->quantity);
	}
	else
	{
		printf("\nInvalid input\n");
		getch();
	}
}

void med_deletion()
{
	int res;
	char tar[15];
	struct medicine *temp;
	temp=(struct medicine*)malloc(sizeof(struct medicine));
	if(first==NULL)
		printf("\nNO records!!!\n");
	else
	{
		printf("\nEnter the name which you want to delete: ");
		fflush(stdin);
		scanf("%[^\n]",tar);
		temp=first;
		res=strcmp(temp->med_name,tar);
	    if(first->after==NULL && res==0)
		{
			temp=first;
			first=NULL;
			free(temp);
			printf("\nRecord has been deleted\n");
			getch();
		}
		else
		{
			struct medicine *p;
			while(res!=0)
			{
				p=temp;
				if(temp->after==NULL)
				break;
				else
				{
					temp=temp->after;
					res=strcmp(temp->med_name,tar);
				}
			}
			if(res==0)
			{
				if(temp->after==NULL)
				{
					p->after==NULL;
					free(temp);
					printf("\nRecord has been deleted\n");
					getch();
				}
				else
				{
					struct medicine *q;
					q=temp->after;
					p->after=q;
					temp->after=NULL;
					free(temp);
					printf("\nRecord has been deleted\n");
					getch();
				}
			}
			else
			{
				printf("\nInvalid Input\n");
				getch();
			}
		}
	}
}


void patient_field()
{
	system("cls");
	intnum;
	while(1)
	{
		printf("\n\n\t\t\tPATIENT RECORD\n\t\t 1) insertion\n\t\t 2) display\n\t\t 3) total amount to be paid\n\t\t 4) exit:\n\t\t Enter the option: ");
		scanf("%d",&num);
		fflush(stdin);
		switch(num)
		{
			case 1:
				pat_insertion();
				break;
			case 2:
				if(head==NULL)
					printf("\nNo Records!!!\n");
				else
					pat_display();
				break;
			case 3:
				if(head==NULL)
					printf("\nNo Records!!!\n");
				else
					pat_amount();
				break;
			case 4:
				main();
			default:
				printf("\nInvalid input\n");
		}
	}
}


void pat_insertion()
{
	struct patient *temp;
	struct doc *temp1;
	temp1=root;
	temp=(struct patient *)malloc(sizeof(struct patient));
	fflush(stdin);
	printf("\nEnter patient's name: ");
	scanf("%[^\n]",temp->name);
	fflush(stdin);
	printf("Enter age: ");
	scanf("%d",&temp->age);
	fflush(stdin);
	printf("Enter sex(M/F/T): ");
	scanf("%c",&temp->sex);
	fflush(stdin);
	printf("Enter address: ");
	scanf("%[^\n]",temp->add);
	fflush(stdin);
	printf("Enter disease details: ");
	scanf("%[^\n]",temp->disease);
	temp->ref_doc_id=doc_ref();
	fflush(stdin);
	printf("Enter date of admit: ");
	scanf("%[^\n]",temp->date);
	fflush(stdin);
	printf("Enter patient room number: ");
	scanf("%[^\n]",temp->room_no);
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else
	{
		struct patient *p;
		p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
	}
}

void pat_display()
{
	struct patient *temp;
	temp=(struct patient*)malloc(sizeof(struct patient));
	char tar[45];
	intlp=0,res;
	fflush(stdin);
	printf("\nEnter the patient's name: ");
	scanf("%[^\n]",tar);
	temp=head;
	if(head->next==NULL)
	{
		res=strcmp(head->name,tar);
		if(res==0)
		{
			pat_disp(head);
			lp=1;
		}
	}
	else
	{
		do
		{
			res=strcmp(temp->name,tar);
			if(res==0)
			{
				printf("\n\t\tDETAILS: ");
				pat_disp(temp);
				lp=1;
				temp=temp->next;
			}
			else
			{
				lp=0;
				temp=temp->next;
			}
		}while(temp->next!=NULL);
	}
		if(lp==0)
		{
			res=strcmp(temp->name,tar);
			if(res==0)
				pat_disp(temp);
			else
				printf("Target is not in the list");
		}
}
void pat_disp(struct patient *temp)
{
	printf("\nName: %s",temp->name);
	printf("\nage: %d",temp->age);
	printf("\nsex: %c",temp->sex);
	printf("\nAdd: %s",temp->add);
	printf("\nDisease: %s",temp->disease);
	printf("\nDotor: %d",temp->ref_doc_id);
	printf("\nDate of admit: %s",temp->date);
	printf("\nRoomalloted: %s",temp->room_no);
}
void pat_update()
{
	struct patient *temp;
	temp=(struct patient*)malloc(sizeof(struct patient));
	temp=head;
	char tar[15];
	fflush(stdin);
	printf("Enter the patient name: ");
	scanf("%[^\n]",tar);
	int res;
	res=strcmp(temp->name,tar);
	while(res!=0)
	{
		if(temp->next==NULL)
		break;
		else
		{
			temp=temp->next;
			res=strcmp(temp->name,tar);
		}
	}
	if(res==0)
	{
		fflush(stdin);
		printf("\nEnter patient's name: ");
		scanf("%[^\n]",temp->name);
		fflush(stdin);
		printf("Enter age: ");
		scanf("%d",&temp->age);
		fflush(stdin);
		printf("Enter sex(M/F/T): ");
		scanf("%c",&temp->sex);
		fflush(stdin);
		printf("Enter address: ");
		scanf("%[^\n]",temp->add);
		fflush(stdin);
		printf("Enter disease details: ");
		scanf("%[^\n]",temp->disease);
		printf("Enter referred doctor's id: ");
		scanf("%d",&temp->ref_doc_id);
		fflush(stdin);
		printf("Enter patient room number: ");
		scanf("%[^\n]",temp->room_no);
	}
	else
	{
		printf("\nInvalid input\n");
	}
}

void pat_amount()
{
	struct patient *temp=head;
	struct med *temp1;
	intdays_icu,days_ward,n,i;
	float total_amount,total=0;
	char med_name[20],pat_name[20];
	int m=0,res=0;
	printf("\nEnter patient's name: ");
	fflush(stdin);
	scanf("%[^\n]",pat_name);
	while(temp!=NULL)
	{
		res=strcmp(temp->name,pat_name);
		if(res==0)
		{
			m=1;
			break;
		}
		temp=temp->next;
	}
	if(m==1)
	{
		printf("Total amount to be paid for %s: ",temp->name);
		printf("\nNumber of days in ICU: ");
		scanf("%d",&days_icu);
		printf("\nNumber of days  in general ward: ");
		scanf("%d",&days_ward);
		printf("\n Number of medicines: ");
		scanf("%d",&n);
		for(i=0;i<n;i++)
			total=medname1(i+1);
		total_amount= days_icu*2000 + days_ward*200 + total;
		printf("\nTotal amount to be paid: %f",total_amount);
	}
	else
		printf("\nPatient is not in the records.\n");
}

float medname1(int t)
{
	struct medicine *temp;
	temp=first;
	int res=0,n,d=0;
	char medname[20];
	printf("\nEnter the medicine%d name ",t);
	fflush(stdin);
	scanf("%[^\n]",medname);
	while(temp!=NULL)
	{
		res=strcmp(temp->med_name,medname);
		if(res==0)
		{
			printf("\nEnter total number of packets: ");
			scanf("%d",&n);
			d=d+(temp->price)*n;
			break;
		}
		temp=temp->after;
	}
	if(res!=0)
		medname1(t);
	return d;
}


//STAFF MEMBERS
void staff_field()
{
	intnum;
	system("cls");
	while(1)
	{
		printf("\n\t\t\tSTAFF's INFORMATION\n Choose the option:\n 1) Data Entry\n 2) Data Display\n 3) Data modification \n 4) Data Deletion\n 5) Exit\n Enter the option: ");
		scanf("%d",&num);
		switch(num)
		{
			case 1:
				{
					system("cls");
					do
					{
						staff_insertion();
						printf("\nDo you want to add more(Y/N): ");
						fflush(stdin);
						scanf("%c",&ch);
					}while(ch=='Y'||ch=='y');
				}
				break;
			case 2:
				{
					if(top==NULL)
						printf("\nNo Records!!!\n");
					else
					{
						system("cls");
						printf("\n\t\tStaff Information Display\n 1) for selected id\n 2) for total display\n Enter the option: ");
						scanf("%d",&num);
						fflush(stdin);
						switch(num)
						{
							case 1:
								staff_display();
								break;
							case 2:
								staff_alldisplay();
								break;
							default:
								printf("\nInvalid Input\n");
						}
					}
				}
				break;
			case 3:
				{
					if(top==NULL)
						printf("\nNo Records!!!\n");
					else
					{
						system("cls");
						do
						{
							staff_modification();
							printf("\nDo u want to modify more: ");
							scanf("%c",&ch);
						}while(ch=='Y'|| ch=='y');
					}
				}
				break;
			case 4:
				if(top==NULL)
					printf("\nNo records!!!\n");
				else
					staff_deletion();
				break;
			case 5:
				main();
			default:
				printf("\nInvalidInput,Try Again!!!\n");
		}
	}
}

void staff_insertion()
{
	int m=0;
	struct staff *temp;
	temp=(struct staff*)malloc(sizeof(struct staff));
	printf("\nEnter id(4 digits): ");
	scanf("%d",&temp->id);
	fflush(stdin);
	printf("Enter name: ");
	scanf("%[^\n]",temp->name);
	//fflush(stdin);
	printf("Enter age: ");
	scanf("%d",&temp->age);
	fflush(stdin);
	printf("Enter address: ");
	scanf("%[^\n]",temp->add);
	fflush(stdin);
	printf("Enter Designation: ");
	scanf("%[^\n]",temp->desig);
	//fflush(stdin);
	printf("Enter phone number: ");
	scanf("%ld",&temp->ph_num);
	printf("Enter salary: ");
	scanf("%lf",&temp->salary);
	temp->next=NULL;

	if(top==NULL)
		top=temp;
	else
	{
		struct staff *p,*q;
		p=top;
		while(p)
		{
			if(temp->id==p->id)
			{
				m=1;
				break;
			}
			p=p->next;
		}
		if(m==1)
		{
			printf("\n Id already exist, Try again!!!");
			staff_insertion();
		}
		else
		{
			p=top;
			if(p->next==NULL )
			{
				if(p->id>temp->id)
				{
					temp->next=p;
					top=temp;
					p->next=NULL;
				}
				else
				{
					p->next=temp;
				}
			}
			else
			{
				while(p->next!=NULL)
				{
					q=p;
					p=p->next;
					if(p->id>temp->id)
					{
						temp->next=p;
						q->next=temp;
						m=2;
					}
				}
				if(m!=2)
				{
					p->next=temp;
				}
			}
		}
	}
}


void staff_display()
{
	//system("cls");
	int tar;
	struct staff *temp;
	printf("\nEnter the staff's id'");
	scanf("%d",&tar);
	temp=top;
	if(top->next==NULL && top->id==tar)
	{
		printf("\t\t\t\tDetails of Given id\n");
		staff_disp(temp);
	}
	else if(top->next!=NULL)
	{
		while(temp->id!=tar)
		{
			temp=temp->next;
			if(temp->next==NULL)
			break;
		}
			if(temp->id==tar)
		{
			printf("\t\t\t\tDetails of Given id\n");
			staff_disp(temp);
		}
		else
		{
			printf("\nInvalid id\n");
		}
	}
	else
		printf("\nInvalid Input\n");
	fflush(stdin);
	getch();
}

void staff_alldisplay()
{
	system("cls");
	struct staff *temp;
	temp=(struct staff*)malloc(sizeof(struct staff));
	temp=top;
	printf("\t\t\t\tDetails of Given id\n");
	if(top->next==NULL)
	staff_disp(top);
	else
	{
		while(temp->next!=NULL)
		{
			staff_disp(temp);
			temp=temp->next;
		}
		staff_disp(temp);
	}
	fflush(stdin);
	getch();
}

void staff_disp(struct staff *temp)
{
	printf("\nId: %d",temp->id);
	printf("\nName: %s",temp->name);
	printf("\nAge: %d",temp->age);
	printf("\nAddress: %s",temp->add);
	printf("\nDesignation: %s",temp->desig);
	printf("\nPhone Number: %ld",temp->ph_num);
	printf("\nSalary: %lf",temp->salary);
}

void staff_modification()
{
	intnum;
	struct staff *temp;
	printf("\nEnter the id: ");
	scanf("%d",&num);
	temp=top;
	while(temp->id!=num)
	{
		if(temp->next==NULL)
		break;
		temp=temp->next;
	}
	if(temp->id==num)
	{
		fflush(stdin);
		printf("Name: ");
		scanf("%[^\n]",temp->name);
		printf("Age: ");
		scanf("%d",&temp->age);
		fflush(stdin);
		printf("Address: ");
		scanf("%[^\n]",temp->add);
		fflush(stdin);
		printf("Designaton: ");
		scanf("%[^\n]",temp->desig);
		fflush(stdin);
		printf("Phone Number: ");
		scanf("%ld",&temp->ph_num);
		fflush(stdin);
		printf("Salary: ");
		scanf("%lf",&temp->salary);
	}
	else
	{
		printf("\nInvalid Input");
		fflush(stdin);
		getch();
	}
}

void staff_deletion()
{
	int tar;
	struct staff *temp;
	printf("\nEnter the id which u want to delete: ");
	scanf("%d",&tar);
	if(top->id==tar)
	{
		if(top->next==NULL)
		{
			temp=top;
			top=NULL;
			free(temp);
			printf("\nRecord has deleted");
			fflush(stdin);
			getch();
		}
		else
		{
			temp=top;
			top=top->next;
			temp->next=NULL;
			free(temp);
			printf("\nRecord has deleted");
			fflush(stdin);
			getch();
		}
	}
	else
	{
		struct staff *p;
		temp=top;
		while(temp->id!=tar)
		{
			p=temp;
			if(temp->next==NULL)
			break;
			temp=temp->next;
		}
		if(temp->id==tar)
		{
			if(temp->next==NULL)
			{
				p->next=NULL;
				free(temp);
				printf("\nRecord has deleted");
			}
			else
			{
				struct staff *q;
				q=temp->next;
				p->next=q;
				temp->next=NULL;
				free(temp);
				printf("\nRecord has deleted");
			}
		}
		else
		{
			printf("\nInvalid Input");
			fflush(stdin);
			getch();
		}
	}
}
