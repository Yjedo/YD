#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 10

//���һ�����������еĵ�k���ֵ
int getMaxFirst(int dataArray[], int k);

int getMaxSecond(int dataArray[], int k);

int main(void)
{
    int testData[MAXLEN] = {3, 1, 5, 2, 6, 9, 7, 4, 8, 0};

    // int kData = getMaxFirst(testData, 1);
    // int i;

    // for(i = 0; i < MAXLEN; i++)
    // {
    //     printf("%d ", testData[i]);
    // }
    // printf("\n%d", kData);

    printf("%d", getMaxSecond(testData, 1));

    return 0;
}

//��һ�֣������ݽ���k��ð������󣬸����±��ȡ
int getMaxFirst(int dataArray[], int k)
{
    int i = 0;
    int j;

    for(i; i < k; i++)
    {
        for(j = 0; j < MAXLEN - 1; j++)
        {
            if (dataArray[j] > dataArray[j+1])
            {
                int tempData = dataArray[j];
                dataArray[j] = dataArray[j+1];
                dataArray[j+1] = tempData;
            }
        }
    }

    return dataArray[MAXLEN - k];
}

//�ڶ��֣��������е�ǰk��Ԫ��ת�Ƶ������У�����֮�������򣬴˺���ʣ�������������Ԫ�رȽ�
//��֤��������ֻ��k��Ԫ�أ����������е����һ��Ԫ�ؼ���k�����
int getMaxSecond(int dataArray[], int k)
{
    int *tempArray = (int *)malloc(k);

    if (!tempArray)
    {
        printf("�����ڴ�ʧ�ܣ�");
        system("exit");
    }

    //��dataArray�е�ǰk�����ݴ���tempArray
    int i = 0;
    for(i; i < k; i++)
    {
        tempArray[i] = dataArray[i];
    }
    int j;
    //����֮��������
    for(i = 0; i < k; i++)
    {
        for(j = 0; j < k - 1; j++)
        {
            if (tempArray[j] < tempArray[j+1]){
                int temp = tempArray[j];
                tempArray[j] = tempArray[j+1];
                tempArray[j+1] = temp;
            }
        }
    }

    for(j = k; j < MAXLEN; j++){
        i = k - 1;
        while(i > -1 && tempArray[i] < dataArray[j]){
            if (i > 0 && tempArray[i-1] > dataArray[j])
            {
                tempArray[i] = dataArray[j];
                break;
            }
            else{
                if (i == 0){
                    tempArray[i] = dataArray[j];
                }
                else{
                    tempArray[i] = tempArray[i-1];
                }
            }
        }
    }

    return tempArray[k-1];
}