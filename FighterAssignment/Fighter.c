

#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
int t,i;
float d;
float xf[12],yf[12],xb[12],yb[12],vf;

printf("\nSIMULATION OF PURE PURSUIT PROBLEM IN C\n\n");
printf("Enter Target path, xb[t] & yb[t]:");
  for(i=0;i<12;i++){
  scanf("%f%f",&xb[i],&yb[i]);
  }
printf("Enter Fighter's Initial path, xf[0] & yf[0]:");
scanf("%f%f",&xf[0],&yf[0]);
printf("Enter Fighter velocity, vf:");
scanf("%f",&vf);
for(t=0;t<12;t++) {
  d=sqrt(pow((yb[t]-yf[t]),2)+pow((xb[t]-xf[t]),2));
  if(d<10)
    {
    printf("\nCaught at %d mts and %f kms\n",t,d);
    break;
     }
    else
    {
    xf[t+1]=xf[t]+(vf*(xb[t]-xf[t])/d);
    yf[t+1]=yf[t]+(vf*(yb[t]-yf[t])/d);
     }
}
if(t>11)
printf("Target Escaped\n");
getch();
return(0);
}