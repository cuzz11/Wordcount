# Wordcount#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX_LINE 1024
int main (int argc, char* argv[])
{
    char file_name[100]="D:\\D盘\\D盘\\apps\\MyProjects\\Wordcount\\Debug\\input.txt";
	char buffer[MAX_LINE] ;
	int len = 0; //行字符个数
	int total = 0;
	int sum = 0;
    FILE *fp;
    int i;
    fp=fopen (file_name, "r") ; //"w+"模式：先写入后读出
    if(NULL==fp)
    {
        printf ("Failed to open the file !\n");
        exit (0);
    }
	//读取文件内容
	while(!feof(fp)){
		// fgets() 在读出 MAX_LINE 个字符之前，遇到 换行符 或 EOF 则读出结束
		if(fgets(buffer, MAX_LINE, fp) != NULL){
			len = strlen(buffer);
			total+=len;
			//遇到第一个空格之前已有一个单词
			sum ++;
			//len - 1 是为了去掉换行符所占位置
		//	for(i = 0; i < len - 1; i++){
		//		if(buffer[i] == ' '){
		//			sum ++;
		//		}
		//	}
		}
	}

	if(!strcmp(argv[1],"-w")){
		printf("单词数：%d\n",sum);
	}
	if(!strcmp(argv[1],"-c")){
		printf("字符数：%d\n",total);
	}
    fclose(fp);
}

