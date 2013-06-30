// DicesProbability.cpp : Defines the entry point for the console application.
//

// ����ָOffer�����������Թپ������ͱ���⡷����
// ����Ȩ�����ߣ��κ���
#include <cstdio>
#include <cmath>
int g_maxValue = 6;
 
// ====================����һ====================
void Probability(int number, int* pProbabilities);
void Probability(int original, int current, int sum, int* pProbabilities);

void PrintProbability_Solution1(int number)
{
    if(number < 1)
        return;
 
    int maxSum = number * g_maxValue;
    int* pProbabilities = new int[maxSum - number + 1];
    for(int i = number; i <= maxSum; ++i)
        pProbabilities[i - number] = 0;
 
    Probability(number, pProbabilities);
 
    int total = pow((double)g_maxValue, number);
    for(int i = number; i <= maxSum; ++i)
    {
        double ratio = (double)pProbabilities[i - number] / total;
        printf("%d: %e\n", i, ratio);
    }
 
    delete[] pProbabilities;
}
 
void Probability(int number, int* pProbabilities)
{
    for(int i = 1; i <= g_maxValue; ++i)
        Probability(number, number, i, pProbabilities);
}
 
void Probability(int original, int current, int sum, 
                 int* pProbabilities)
{
    if(current == 1)
    {
        pProbabilities[sum - original]++;
    }
    else
    {
        for(int i = 1; i <= g_maxValue; ++i)
        {
            Probability(original, current - 1, i + sum, pProbabilities);
        }
    }
} 

// ====================������====================
void PrintProbability_Solution2(int number)
{
    if(number < 1)
        return;

    int* pProbabilities[2];
    pProbabilities[0] = new int[g_maxValue * number + 1];
    pProbabilities[1] = new int[g_maxValue * number + 1];
    for(int i = 0; i < g_maxValue * number + 1; ++i)
    {
        pProbabilities[0][i] = 0;
        pProbabilities[1][i] = 0;
    }
 
    int flag = 0;
    for (int i = 1; i <= g_maxValue; ++i) 
        pProbabilities[flag][i] = 1; 
    
    for (int k = 2; k <= number; ++k) 
    {
        for(int i = 0; i < k; ++i)
            pProbabilities[1 - flag][i] = 0;

        for (int i = k; i <= g_maxValue * k; ++i) 
        {
            pProbabilities[1 - flag][i] = 0;
            for(int j = 1; j <= i && j <= g_maxValue; ++j) 
                pProbabilities[1 - flag][i] += pProbabilities[flag][i - j];
        }
 
        flag = 1 - flag;
    }
 
    double total = pow((double)g_maxValue, number);
    for(int i = number; i <= g_maxValue * number; ++i)
    {
        double ratio = (double)pProbabilities[flag][i] / total;
        printf("%d: %e\n", i, ratio);
    }
 
    delete[] pProbabilities[0];
    delete[] pProbabilities[1];
}

void solution3(int n){
	if(n < 1)
		return;
	int* prev = new int[g_maxValue * n + 1];
	int* cur = new int[g_maxValue * n + 1];
	for(int i = 0;i < g_maxValue * n + 1;i++){
		prev[i] = 0;
		cur[i] = 0;
	}
	
	for(int i = 1;i <= g_maxValue;i++)
		prev[i] = 1;

	for(int i = 2;i <= n;i++){
		for(int j = 0;j < g_maxValue * n + 1;j++)
			cur[j] = 0;
		for(int j = i;j <= g_maxValue * i;j++){
			for(int k = 1;k <= j && k <= g_maxValue;k++)
				cur[j] += prev[j - k];
		}
		int* tmp = prev;
		prev = cur;
		cur = tmp;
	}
	double total = pow((double)g_maxValue,n);
	for(int i = n;i <= g_maxValue * n;i++)
		printf("%d: %e\n",i,(double)prev[i] / total);
	delete[] prev;
	delete[] cur;
}

// ====================���Դ���====================
void Test(int n)
{
    printf("Test for %d begins:\n", n);
    
    //printf("Test for solution1\n");
    //PrintProbability_Solution1(n);

    printf("Test for solution2\n");
    PrintProbability_Solution2(n);
    
    printf("Test for solution3\n");
    solution3(n);

    printf("\n");
}

int main()
{
    Test(1);
    Test(2);
    Test(3);
    Test(4);
    
    Test(11);

    Test(0);

    return 0;
}

