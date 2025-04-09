#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * binarydiv(char * data,char * divisor)
{
int i,j,k,v,n;
char *stuff1 = malloc (sizeof (char) * 20);
v=strlen(data);
n=strlen(divisor);
//initialising stuff with zeroes
for(i=0;i<n;i++)
{
stuff1[i]='0';
}
stuff1[i]='\0';

//logic to implement
k=0; i=0;
while(k!=v)
{
if(v-k<i-1)
  break;
i=0;  j=0;
  while(stuff1[i]=='0')
    i++;
while(i!=n)
{
     
      if(stuff1[i]==divisor[j])
          stuff1[j]='0';
else
stuff1[j]='1';
    j++;
    i++;
    }
    while(j<n&&k<v)
    {
      if(data[k]==divisor[j])
          stuff1[j]='0';
      else
          stuff1[j]='1';
      j++;
      k++;
     
  }
 
}
while(k!=v)
{
  stuff1[n]=data[k];
n++;
k++;
}
stuff1[n]='\0';
return stuff1;
}




void main()
{
char data[100],divisor[10],stuff[20],temp[100],t1[100];
int i,j,n,v;
printf("enter the data:");
scanf("%s",data);
strcpy(temp,data);
printf("enter the divisor");
scanf("%s",divisor);
n=strlen(divisor);
v=strlen(data);

//adding zeroes
for(i=v;i<v+n-1;i++)
{
data[i]='0';
}
data[i]='\0';

strcpy(stuff,binarydiv(data,divisor));
printf("remainder is %s\n",stuff);
printf("Data to be sent: ");
v=strlen(data);
int n1=strlen(stuff);
for(j=0;j<n-1;j++)
{
data[v]=stuff[n1];
v--;
n1--;
}
data[i]='\0';
printf("%s\n",data);
printf("\t\t\t\tReceiver\t\t\t\t\t");
printf("\nEnter data recieved by receiver: ");
scanf("%s",t1);
strcpy(stuff,binarydiv(t1,divisor));
if(strncmp("000000000000",stuff,n)==0)
printf("\ndata recieved correctly");
else
printf("\nerror detected\n");
}
