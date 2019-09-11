#include<stdio.h>
#include<stdlib.h>

//给定一个字符串，逐个翻转字符串中的每个单词。
//示例 1：
//输入 : "the sky is blue"
//	输出 : "blue is sky the"
//	示例 2：
//	输入 : "  hello world!  "
//	输出 : "world! hello"
//	解释 : 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
//	示例 3：
//	输入 : "a good   example"
//	输出 : "example good a"
//	解释 : 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

//思路: 先把每个单词翻转,再把整个句子翻转,再删除多余的空格,最后打印;
void Resevr(char* arr, int start, int end)// 翻转
{
	char tmp;
	for (; start <= end; start++, end--) {
		tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
	}
}
void ResevrSting(char* arr, int len) 
{
	int start = 0, end = 0;
	for (int i = 0; i < len; i++) {
		if (arr[i] == ' ') {
			end = i - 1;
			Resevr(arr, start, end);
			start = i + 1;
		}
	}
	Resevr(arr, start, len);
	Resevr(arr, 0, len);
}

void Delet(char* arr,int n,int len) //删除一个元素;
{
	for (int i = n; i < len; i++) {
		arr[i] = arr[i + 1];
	}
}
void DeletSpace(char* arr,int len) {
	int Long = len;
	while(arr[0] == ' ') { //删除开头的空格
		Delet(arr, 0, len);
		Long--;
	}
	while(arr[Long - 1] == ' ') { //删除结束的空格
		Delet(arr, Long - 1, len);
		Long--;
	}
	for (int i = 0; i < Long; i++) { //删除句中多余的空格
		if (arr[i] == ' '&&arr[i + 1] == ' ') {
			Delet(arr, i, Long);
			Long--;
			i--; //保持i不变,防止多个空格连在一起的情况
		}
	}
	for (int i = 0; i < Long; i++) {
		printf("%c", arr[i]);
	}
}

int main() {
	char arr[] = "  the   sky   is   blue  ";
	int len = sizeof(arr) - 2;
	ResevrSting(arr, len);
	DeletSpace(arr, len);
	system("pause");
	return 0;
}
