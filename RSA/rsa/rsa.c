#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int x = 71, y = 293, n, t, i, flag;
long int e[500000], d[500000], temp[500000], j;
char en[100000], m[100000];
char msg[100000];
int isprime(long int);
void encryption_key();
long int cd(long int);
void encrypt();
void decrypt();

int main()
{

   printf("enter the message\n");
   gets(msg);
   for (i = 0; msg[i] != NULL; i++)
      m[i] = msg[i];
   n = x * y;
   t = (x - 1) * (y - 1);

   encryption_key();

   encrypt();

   decrypt();

   return 0;
}

int isprime(long int pr)
{
   int i;
   j = sqrt(pr);
   for (i = 2; i <= j; i++)
   {
      if (pr % i == 0)
         return 0;
   }
   return 1;
}

void encryption_key()
{
   int k;
   k = 0;
   for (i = 2; i < t; i++)
   {
      if (t % i == 0)
         continue;
      flag = isprime(i);
      if (flag == 1 && i != x && i != y)
      {
         e[k] = i;
         flag = cd(e[k]);
         if (flag > 0)
         {
            d[k] = flag;
            k++;
         }
         if (k == 100000)
            break;
      }
   }
}

long int cd(long int a)
{
   long int k = 1;
   while (1)
   {
      k = k + t;
      if (k % a == 0)
         return (k / a);
   }
}

void encrypt()
{
   long int pt, ct, key = e[0], k, len;
   i = 0;
   len = strlen(msg);

   while (i != len)
   {
      pt = m[i];
      pt = pt - 96;
      k = 1;
      for (j = 0; j < key; j++)
      {
         k = k * pt;
         k = k % n;
      }
      temp[i] = k;
      ct = k + 96;
      en[i] = ct;
      i++;
   }
   en[i] = '\0';
   printf("\n\nTHE ENCRYPTED MESSAGE IS\n");
   for (i = 0; en[i] != '\0'; i++)
      printf("%c", en[i]);
}

void decrypt()
{
   long int pt, ct, key = d[0], k;
   i = 0;
   while (en[i] != '\0')
   {
      ct = temp[i];
      k = 1;
      for (j = 0; j < key; j++)
      {
         k = k * ct;
         k = k % n;
      }
      pt = k + 96;
      m[i] = pt;
      i++;
   }
   m[i] = '\0';
   printf("\n\nTHE DECRYPTED MESSAGE IS\n");
   for (i = 0; m[i] != '\0'; i++)
      printf("%c", m[i]);

   printf("\n");
}