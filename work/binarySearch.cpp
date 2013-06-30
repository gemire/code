/**
 * Modified binary search.
 */
#include <iostream>
#include <cstdio>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
/*
 * Traditional binary search
 */
int GetK(int* num, int length, int k){
	if(num == NULL || length <= 0)
		return -1;
	int start = 0;
	int end = length - 1;
	int mid;
	while(start <= end){
		mid = start + ((end - start) >> 1);
		if(num[mid] > k)
			end = mid - 1;
		else if(num[mid] < k)
			start = mid + 1;
		else
			return mid;	
	}
	return -1;
}

int GetFirstK(int* num, int length, int k){
	if(num == NULL || length <= 0)
		return -1;
	int start = 0;
	int end = length - 1;
	int mid;
	while(start <= end){
		mid = start + ((end - start) >> 1);
		if(num[mid] > k)
			end = mid - 1;
		else if(num[mid] < k)
			start = mid + 1;
		else{
			if(mid > 0 && num[mid - 1] != k || mid == 0)
				return mid;
			else
				end = mid - 1;
		}
	}
	return -1;
}

int GetLastK(int* num, int length, int k){
	if(num == NULL || length <= 0)
		return -1;
	int start = 0;
	int end = length - 1;
	int mid;
	while(start <= end){
		mid = start + ((end - start) >> 1);
		if(num[mid] > k)
			end = mid - 1;
		else if(num[mid] < k)
			start = mid + 1;
		else{
			if(mid < length - 1 && num[mid + 1] != k || mid == length - 1)
				return mid;
			else
				start = mid + 1;
		}
	}
	return -1;
}

int GetNumberOfK(int* num, int length, int k){
	int result = 0;
	if(num != NULL && length > 0){
		int first = GetFirstK(num,length,k);
		int last = GetLastK(num,length,k);
		if(first > -1 && last > -1)
			result = last - first + 1;
	}
	return result;
}
void Test(char* testName, int data[], int length, int k, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    int result = GetNumberOfK(data, length, k);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// ���ҵ����ֳ�����������м�
void Test1()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// ���ҵ��������������Ŀ�ͷ
void Test2()
{
    int data[] = {3, 3, 3, 3, 4, 5};
    Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// ���ҵ��������������Ľ�β
void Test3()
{
    int data[] = {1, 2, 3, 3, 3, 3};
    Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// ���ҵ����ֲ�����
void Test4()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// ���ҵ����ֱȵ�һ�����ֻ�С��������
void Test5()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// ���ҵ����ֱ����һ�����ֻ��󣬲�����
void Test6()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// �����е����ִ�ͷ��β���ǲ��ҵ�����
void Test7()
{
    int data[] = {3, 3, 3, 3};
    Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// �����е����ִ�ͷ��βֻ��һ���ظ������֣����ǲ��ҵ�����
void Test8()
{
    int data[] = {3, 3, 3, 3};
    Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// ������ֻ��һ�����֣��ǲ��ҵ�����
void Test9()
{
    int data[] = {3};
    Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// ������ֻ��һ�����֣����ǲ��ҵ�����
void Test10()
{
    int data[] = {3};
    Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// ³���Բ��ԣ������ָ��
void Test11()
{
    Test("Test11", NULL, 0, 0, 0);
}



int main(){
	Test1();
    	Test2();
    	Test3();
   	Test4();
   	Test5();
    	Test6();
    	Test7();
    	Test8();
    	Test9();
   	Test10();
    	Test11();

	return 0;
}
