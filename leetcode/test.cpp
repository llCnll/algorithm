#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
bool cmp(char a,char b)
{
	return a<b;
}
int main(){

    char str[20] = "你好a";
    
    printf("str = %s, length = %d, sizeof = %d\n", str, strlen(str), sizeof(str));

	//char an[210]={0};
	//while(gets(an)!=NULL)
	//{
	//	int len;
	//	len=strlen(an);
	//	sort(an,an+len,cmp);
	//	puts(an);
	//	memset(an,0,sizeof(an));
	//}
    return 0;
}
