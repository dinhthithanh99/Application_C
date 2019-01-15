#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void exit();
void end();
void form();
void back();
void nhaplop();
void nhapsinhvien();
void xemlop();
void xemsinhvientheolop();
void timtuoi();
void timphong();


int i, j,dem, count=0;
char c;								//Khai bao bien toan cuc 

						
struct sinhvien						//Khai bao cau truc sinh vien
{
	char tensv[40];
	char masv[20];
	int phong;
	int  tuoi;
};

struct lop							//Khai bao cau truc lop long sinh vien
{
	int soluong;
	char tenlop[100];
	char malop[10];
	struct sinhvien sv[100];
};

struct lop lp[100];



									//Ham lua chon trong form
void choose()									
{
	char c;
	
    do
	{	
		system("cls");  
		
		form();
		c=getch();
		switch(c)
		{
			case '1':
			{
				system("color E");
				system("cls");
				printf("\t\t-------------NHAP THONG TIN LOP HOC------------\n");
				fflush(stdin);
				nhaplop();
				back();	
				break;
			}

			case '2':
			{
				system("color D");
				system("cls");
				fflush(stdin);
		        nhapsinhvien();
		        back();	
		        break;
			}
			
			case '3':
			{
				system("color 2");
				system("cls");
				printf("\n\n\n=============================THONG TIN  LOP ================================");
				fflush(stdin);
				xemlop();
				back();	
				break;
		 	}
		 
			case '4':
			{
				system("color C");
		 		system("cls");
				xemsinhvientheolop();
				back();	
		        break;
			}

		 	case '5':
			{
				system("color 7");
	 			system("cls");
				fflush(stdin);
				timtuoi();
				back();	
				break;
			}

			case '6':
			{
				system("color B");
				system("cls");
		 		timphong();
		 		back();	
		 		break;
			}
			case '7':
			{
				system("color F");
				system("cls");
				exit(0);
			}

		}
	}while (c!= '8');
	
	end();
}
									//Ham in ra lua chon
void chonlai()
	{
		printf("\n\n\n\nPRESS 1(MENU) ");
		printf("\nPRESS 0(EXIT)");
		printf("\nPRESS 2(NHAP LOP)");
		printf("\nPRESS 3(NHAP SINH VIEN)");
		printf("\nPRESS 4(XEM LOP)");
		printf("\nPRESS 5(XEM SINH VIEN THEO LOP)");
		printf("\nPRESS 6(TIM TUOI)");
		printf("\nPRESS 7(TIM PHONG)");	
	}

void back()
	{
		chonlai();
		char c=getch();
		switch(c)
		{
		case '0':
			{
			system("color F");
			system("cls");
			exit(0);
			break;
			}
		case '1':
			{
			system("cls");
			form();
			choose();
			break;
			}
		case '2':
			{
			system("cls");
			system("color E");
			fflush(stdin);
			printf("\t\t-------------NHAP THONG TIN LOP HOC------------\n");
			nhaplop();
			back();	
			break;
			}
		case '3':
			{
			system("cls");
			system("color D");
			fflush(stdin);
	        nhapsinhvien();
	        back();	
	        break;
			}
	    case '4':
			{
			system("cls");
			system("color 2");
			fflush(stdin);
			printf("\n\n\n=============================THONG TIN  LOP ================================");
			xemlop();
			back();	
			break;
			}
	    case '5':
			{
			system("cls");
			system("color C");
			xemsinhvientheolop();
			back();	
	        break;
			}
		case '6':
			{
			system("cls");
			system("color 7");
			fflush(stdin);
			timtuoi();
			back();	
			break;
			}	
		case '7':
			{
			system("cls");
			system("color B");
			timphong();
	 		back();	
	 		break;
			}		
		default:
			back();	
		}
	}


								//In bieu mau, bo cuc chuong trinh
void form()										
{
	system("color 1F");
	printf("\n\t\t***************************************************\n\n");
	printf("\t\t********* CHUONG TRINH QUAN LY SINH VIEN **********\n\n");
	printf("\t\t***************************************************\n\n");
	printf("====================================MENU========================================\n\n");
	printf("Xin vui long chon :\n");
	printf("\n1.Nhap lop\n");
	printf("\n2.Nhap sinh vien\n");
	printf("\n3.Xem thong tin lop\n");
	printf("\n4.Xem sinh vien theo lop");
	printf("\n\n5.Tim kiem sinh vien theo tuoi");
	printf("\n\n6.Tim kiem sinh vien theo phong ki tuc xa");
	printf("\n\n7.Thoat chuong trinh\n");
}


void sapxep(struct lop lp[],int n)
{
    int i,j;
   	struct lop temp;
   	for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
    {
        if(strcmp(lp[i].tenlop,lp[j].tenlop)>0)
         {
            temp=lp[i];
            lp[i]=lp[j];
            lp[j]=temp;
         }
    }
 
}
	
	
int clean_stdin() {
    while (getchar() != '\n') {
    }
    return 1;
}
	
								//Nhap lop
void nhaplop()									
{
		int sllop;
			do
			{
			printf("\nNhap so luong lop muon quan ly: ");fflush(stdin);
			}
			while(((scanf("%d%c", &sllop, &c) != 2 || c != '\n') && clean_stdin()) || sllop <= 0);
	for (i = 0; i < sllop; i++) 
	{
       printf("Nhap du lieu cho lop %d:\n", i + 1);
       printf("Ma lop: "); fflush(stdin);
       gets(lp[count].malop);
       do{
       printf("Ten lop: "); fflush(stdin);
       gets(lp[count].tenlop);
		}while(strcmp(lp[count].malop,lp[count].tenlop)==0);
       count++;
    }
    sapxep(lp,sllop);
}


									//Nhap thong tin sinh vien
void nhapsinhvien()   							
{
		system("cls");
    	printf("\t\t-------------NHAP THONG TIN SINH VIEN------------\n");
    	printf("\nChon lop ban muon nhap thong tin sinh vien:  ");
    	for(i=0;i<count;i++)
		{
			printf ("\nLop %s",lp[i].tenlop);
		}
		char sosanh[10];
		
			printf("\n\nHay nhap lop:  ");
			gets (sosanh);	
			fflush(stdin);
			
		for(i=0;i<count;i++)
		{
			if (strcmp(sosanh,lp[i].tenlop)==0)
			{
				do{
				printf("\nNhap so luong hoc sinh:  ");
				fflush(stdin);
				}while(((scanf("%d%c", &lp[i].soluong, &c) != 2 || c != '\n') && clean_stdin()) || lp[i].soluong <= 0);
				for(j=0;j<lp[i].soluong;j++)
				{

					printf("\nNhap ten sinh vien thu %d:  ",j+1);
					gets(lp[i].sv[j].tensv);
					fflush(stdin);
					do
					{
					printf("\nNhap ma sinh vien:  ");
					gets(lp[i].sv[j].masv);
					fflush(stdin);
					}while(strcmp(lp[i].sv[j].tensv,lp[i].sv[j].masv)==0);
					do
					{
					printf("\nNhap so phong:  ");
					fflush(stdin);
					}while(((scanf("%d%c", &lp[i].sv[j].phong, &c) != 2 || c != '\n') && clean_stdin()) || lp[i].sv[j].phong<=0);
					do
					{
					printf("\nNhap tuoi cua sinh vien:  ");
					}
					while(((scanf("%d%c", &lp[i].sv[j].tuoi, &c) != 2 || c != '\n') && clean_stdin())|| lp[i].sv[j].tuoi<15 || lp[i].sv[j].tuoi >29);
					printf("\n\n");
					fflush(stdin);
					                                                                                                     //
				}
		
			}
		
		}

}


								//Xem thong tin lop	
void xemlop ()														
{
	
	printf("\n\nHien tai co %d lop",count);
	printf("\n\nTen lop\t\tMa lop\t\tSo luong sinh vien");
	for(i=0;i<count;i++)
	{
		printf("\n\n%s\t\t%s\t\t%d",lp[i].tenlop,lp[i].malop,lp[i].soluong );
	}
	int n;
    printf("\n\n BAN MUON NHAP THEM LOP KHONG ?");
    printf("\n\n\n\nNHAN 2 DE TIEP TUC NHAP HOAC 3 DE TRO VE!\n");
    do
    {
    printf("Lua chon: ");
	}while(((scanf("%d%c", &n, &c) != 2 || c != '\n') && clean_stdin()) || n!=2 && n!=3);
    switch(n)
    {
		case 2:
			{
				nhaplop();
				system("cls");
				printf("\n\n\n=============================THONG TIN  LOP ================================");
				xemlop();
				break;
			}
		case 3:
			{
				system("cls");
				form();
				choose();
				break;
			}
	}
}


								//Xem sinh vien theo lop
void xemsinhvientheolop()											
{
			char ss[10];
			system("cls");
			printf("\t\t-------------XEM THONG TIN SINH VIEN------------\n");
			printf ("\nBan muon hien thi thong tin lop nao ? ");
			for(i=0;i<count;i++)
			{
				printf ("\nLop %s",lp[i].tenlop);
			}
	
				printf ("\n\nHay nhap ten lop:  ");	fflush(stdin);
				gets (ss);
				
			for(i=0;i<count;i++)
			{
				if (strcmp(ss,lp[i].tenlop)==0)
				{
					printf ("\nLop %s\n",lp[i].tenlop);
					printf ("%-40s %-20s %-5s %-3s\n","Name","StudentID","Room","Age");fflush(stdin);
				
					for(j=0;j<lp[i].soluong;j++)
					{
						fflush(stdin);
						printf ("%-40s %-20s %-5d %-3d\n",lp[i].sv[j].tensv,lp[i].sv[j].masv,lp[i].sv[j].phong,lp[i].sv[j].tuoi);
					}
				}
			}

}


								//Tim kiem thong tin theo tuoi
void timtuoi()
{				
		int tuoi;
		system("cls");
		printf("\t\t---------------TIM KIEM THONG TIN THEO TUOI--------------\n");
	
		do
			{
				printf ("\n\nHay nhap tuoi de tim kiem:  ");   
			}while(((scanf("%d%c", &tuoi, &c) != 2 || c != '\n') && clean_stdin()) || tuoi <= 10 || tuoi >= 40); 	    	 
	
		printf ("\n\n");
		printf ("\nTuoi %d\n",tuoi);
		printf ("%-20s  %-20s %-20s %-3s\n","Name","Class","StudentID","Room");
		for(i=0;i<count;i++)
		{
			for(j=0;j<lp[i].soluong;j++)
			{
				if (tuoi==lp[i].sv[j].tuoi)
				{
					printf ("%-20s  %-20s %-20s %-3d\n",lp[i].sv[j].tensv,lp[i].tenlop,lp[i].sv[j].masv,lp[i].sv[j].phong);
				}
			}	
		}
	
}


								//Tim kiem thong tin sinh vien theo phong
void timphong()												
{													
		int sophong;
		printf("\t\t---------------TIM KIEM THONG TIN THEO PHONG--------------\n");
		
		do
			{
				printf ("\n\nHay nhap so phong de tim kiem:  ");
				fflush(stdin);   
			}while(((scanf("%d%c", &sophong, &c) != 2 || c != '\n') && clean_stdin())); 
				
		printf ("\n\n");
		printf ("\nPhong %d\n",sophong);
		printf ("%-20s  %-20s %-20s %-3s\n","Name","Class","StudentID","Age");
		for(i=0;i<count;i++)
		{
			for(j=0;j<lp[i].soluong;j++)
			{
				if (sophong==lp[i].sv[j].phong)
				{
					printf ("%-20s  %-20s %-20s %-3d\n",lp[i].sv[j].tensv,lp[i].tenlop,lp[i].sv[j].masv,lp[i].sv[j].tuoi);
				}
			}	
	}
}


								
void main()
{
	choose();
}
