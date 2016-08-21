# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdlib.h>

//function declaration
int decimalize ( char * , int, int);
void conversion ( int, int);

int main (void)
{
	char ch; //loop
do
{
	char data[20]; //store user data
	int len; // length
	int bef;  //base (before convertion)
	int aft; //base (after convertion)
	int dataindecimal;  //data present in decimal

	printf("Please enter the number you want to convert\n");
	scanf("%s", &data);
	len = strlen(data); 

	printf("Please enter the base of this number ( from base 2 to base 36)\n");
	scanf("%d", &bef);

	printf("Please enter the base you want to convert to£¨from base 2 to base 36£©\n");
	scanf("%d", &aft);


	dataindecimal = decimalize( data , len, bef);

	conversion( dataindecimal, aft);

	printf("do you want to continue? Y/N : ");
	scanf(" %c", &ch);

}while('Y'== ch || 'y' == ch);

	return 0;
}

int decimalize ( char * data, int len, int bef)
{
	int cnt = 0, sum = 0;
	int i;

	for (i=len-1; i>=0 ; --i)
	{

		if (data[i]>=65 && data[i]<=90) 
		{
			data[i] = data[i]-55;
		}
		else if (data[i]>=97 && data[i]<=122)
		{
			data[i] = data[i]-87;
		}
		else 
			data[i] = data[i]-48;  

		sum = sum + data[i] * pow(bef,(float)cnt);
		cnt ++ ;
		
	}
	return sum;
}

void conversion( int dataindecimal, int aft)
{
	int i, j, t;
	int cnt = 0;
	char * data =(char *)malloc(sizeof(char) * 50);

	while(dataindecimal)
	{
		t = dataindecimal % aft;  //get remainder£»
		
		if (t >= 10 )    //if remainder greater than 10, it is a letter .
			t = t + 55;
		else 
			t = t + 48;
		
		data[cnt] = t;
		cnt++;
		dataindecimal /= aft;

	}  

	
	for (i=0; i<cnt-1; ++i)
	{
		for(j=0; j< cnt-1-i; ++j)
		{
			t = data[j];
			data[j]=data[j+1];
			data[j+1]=t;
		}
	}
	printf ("Number converted :");
	for (i=0; i<cnt;++i)
		printf("%c",data[i]);
	printf("\n");

	free(data);
	data=NULL;

	
}