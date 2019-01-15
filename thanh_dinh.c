#include <stdio.h>
#include <stdint.h>
#include<string.h>
void exit();
void title();
void menu();
void xemlich();
void tinhluong();
void xemluong();
int xemthongtinnhanvien();
int tinhdiemhocsinh();
void choose();
void chonlai();
void back();
									//Ham title cho CHUONG TRUONG HOC THONG MINH
void title()
{
printf("\t\t*****************************************\n\t\t*\t\t\t\t\t*\n");
printf("\t\t****** CHUONG TRUONG HOC THONG MINH *****\n");
printf("\t\t*\t\t\t\t\t*\n\t\t*****************************************\n\n\n");
}          
					
									//Ham Menu lua chon 
void menu()
{
printf("=================================MENU====================================\n\n\n");
printf("\tXIN VUI LONG CHON:\n\n\n");
printf("1. Xem lich\n\n");
printf("2. Tinh luong\n\n");
printf("3. Xem luong\n\n");
printf("4. Xem thong tin cua nhan vien\n\n");
printf("5. Tinh diem cua hoc sinh\n\n");
printf("6. Thoat chuong trinh\n");
}

									//BAI 1: Ham xem lich
void xemlich()
{
	fflush(stdin);
	int n,a;
	printf("\t\t\tXEM LICH \n\n");
	do
	{
	printf("Nhap thang can xem: ");
	scanf("%d",&n);
	}
	while(n<=0||n>12);
	do
	{
		printf("Nhap nam can xem: ");
		scanf("%d",&a);
	}
	while(a==0);
		switch(n)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		 printf("\nThang %d nam %d co 31 ngay",n,a);
		 break;
		case 2: 
		 printf("\nThang %d nam %d co 28 ngay",n,a); 
		 break;
		case 4:
		case 6:
		case 9:
		case 11:
		 printf("\nThang %d nam %d co 31 ngay",n,a);
		 break;
	}
}

									//BAI 2: Ham tinh luong cua nhan vien
void tinhluong()
{
	float a,b,s;
	printf("\t\t\tTINH TIEN LUONG \n\n");
	fflush(stdin);
	printf("Nhap so gio lam: ");
	scanf("%f",&a);
	printf("Nhap so tien luong: ");
	scanf("%f",&b);
	if(a>40)
	s=a-40*(b*1,5)+40*b;
	else
	s=a*b;
	printf("\nTien luong la: %.2f",s);
}

									//Bai 3: Ham xem luong theo thu tu tang dan
void xemluong()
{
	printf("\t\t\tXEM LUONG \n\n");
	int tam,i,j,n;
	printf("Nhap so nhan vien can sap xep: ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		printf("Nhap luong nhan vien: ");
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
		{
			tam=a[i];
			a[i]=a[j];
			a[j]=tam;
		}
		}
	}
	printf("\nDay luong la: ");
	for(i=0;i<n;i++)
		printf("\t%d",a[i]);
}

									//BAI 4: Ham xem thong tin nhan vien 
int xemthongtinnhanvien()
{
	printf("\t\t\tXEM THONG TIN CUA NHAN VIEN\n \n");
	int vt1,i;
	char s[50]="";
	printf("Nhap ho ten ban: ");
	gets(s);
		
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]>='A'&&s[i]<='Z')
			s[i]=s[i]+32;
		}
		s[0]=s[0]-32;
		for(i=1;i<strlen(s);i++)
		{
			if(s[i]==' ')
			s[i+1]=s[i+1]-32;
		
		}
		char ho[32]="",t[32]="";
		for(i=0;i<strlen(s);i++)
		{
			if(s[i]==' ')
			{
				vt1=i;
			}
		}
		
	strncpy(ho,s,vt1);
	strcpy(t,s+vt1);
    printf("\n\n\nHo va ten lot la:%s",ho);
    printf("\n\nTen la:%s",t);
	printf("\n\nHo ten day du la: %s",s);
	return 0;
}


									//BAI 5: Ham tinh diem cua hoc sinh
int tinhdiemhocsinh()
{
	printf("\t\t\tDIEM CUA HOC SINH \n\n");
	int i,n;
	printf("Nhap so mon hoc: ");
	scanf("%d",&n);
	float a[n];
	float b[n];
	for (i=0;i<n;i++)
	{
		do
		{
			printf("Nhap diem mon hoc %d: ",i+1);
			scanf("%f",&a[i]);
		}
		while(n>=10||n<0);
		
		do
		{
			printf("Nhap he so mon hoc %d: ",i+1);
			scanf("%f",&b[i]);
		}
		while(n!=1&&n!=1.5&&n!=2&&n!=2.5&&n!=3);
	}
			float ths=0;
			float dtb=0;
			for(i=0;i<n;i++)
			{
				ths=ths+b[i];
				dtb+=a[i]*b[i];
			}
	printf("\n\nTong so mon hoc can tinh DTB: %d",n);
	printf("\nTong he so: %.2f",ths);
	printf("\nDiem trung binh: %.2f",dtb/ths);
		return 0;
}



									//Ham chon lenh
void choose()
{
	char c;
	int i;
	
    do
	{	
		system("cls");  
		
		title();
		menu();
		c=getch();
		switch(c)
		{
			case '1':
			{
				system("cls");
				title();
				fflush(stdin);
				xemlich();
				back();	
				break;
			}

			case '2':
			{
				system("cls");
				title();
				fflush(stdin);
		        tinhluong();
		        back();	
		        break;
			}
			
			case '3':
			{
				system("cls");
				title();
				fflush(stdin);
				xemluong();
				back();	
				break;
		 	}
		 
			case '4':
			{
		 		system("cls");
				title();
				xemthongtinnhanvien();
				back();	
		        break;
			}

		 	case '5':
			{
		 			system("cls");
					fflush(stdin);
					title();
					tinhdiemhocsinh();
					back();	
					break;
			}

			case '6':
			{
				system("cls");
		 		exit(0);
		 		break;
			}

		}
	}while (c!= '7');
	
	end();
}


									//Ham in ra lua chon
void chonlai()
	{
	printf("\n\n\n\nPRESS 1(MENU) - PRESS 0(EXIT)");	
	}

									//Ham back menu
void back()
	{
		chonlai();
		char c=getch();
		switch(c)
		{
		case '0':
			system("cls");
			exit(0);
			break;
		case '1':
			system("cls");
			title();
			menu();
			choose();
			break;
		default:
			back();	
		}
	}

									//Ham main
void main()
{
	choose();
}
