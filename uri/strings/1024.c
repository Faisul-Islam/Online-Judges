#include<stdio.h>
#include<string.h>
int main(){
int n = 0,i =0,z=0;
char m[1000];
scanf("%d",&n);
getchar();
while(n--){

gets(m);
for(i;i<strlen(m);i++){
        if((m[i]>='A'&& m[i]<='Z')||(m[i]>='a'&& m[i]<='z')){
             m[i]+=3;
        }
}
i=0;
strrev(m);

if(strlen(m)%2!=0){
        int tmp =  (strlen(m)-1)/2;
    for(z =tmp;z<strlen(m);z++){
              m[z] -=1;

    }
    z=0;
}else{
for(z =strlen(m)/2;z<strlen(m);z++){
              m[z] -=1;

        }
        z=0;

}
printf("%s\n",m);

}
return 0;
}
