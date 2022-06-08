#include <stdio.h>

int arr[10],k;
void fnMax();
void fnMin();

int main(){

    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf(" %c", &arr[i]);
    }   

    fnMax();
    fnMin();

    return 0;
}

void fnMax()
{
	int i, j, n = 0;
	int top = 9;

	for (i = 0; i<k; i++)
	{
		if (arr[i] == '>')
		{
			for (j = top - n; j <= top; j++) {
                printf("%d", j);
            }
            top = top - n - 1;
			n = 0;
		}
		else
			n++;
	}

	for (i = top - n; i <= top; i++) {
        printf("%d", i);
    }
    
	printf("\n");
}

void fnMin()
{
	int i,j,n = 0;
	int min = 0;

	for (i = 0; i<k; i++)
	{
		if (arr[i] == '<')
		{
			for (j = min + n; j >= min; j--) {
                printf("%d", j);    
            }
            min = min + n + 1;
			n = 0;    
		}
		else
			n++;
	}

	for (i = min + n; i >= min; i--) {
        printf("%d", i);
    }
    
	printf("\n");
}