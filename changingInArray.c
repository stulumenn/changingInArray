#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void addFirst(int array[], int *used, int *capasity, int element);
void addLast(int array[], int *used, int *capasity, int element);
void removeIndex(int array[], int *used, int *capasity, int index);
void removeItem(int array[], int *used,int *capasity, int item);
int removeLastOccurrence(int array[], int *used, int *capasity, int item);
void removeLast(int array[], int *used, int *capasity);
void clear(int array[], int *used, int *capasity);
void lastIndexOf(int array[], int *used, int *capasity);
void copy();
int compare(int array1[], int array2[], int array1size, int array2size);

int main()
{
	int selection, element, index, value, item, newItem;
	int capasity = SIZE;
	int used = SIZE;
	int array[]={9,5,3,4,5};
	int array1[]={1,2,3,4,5};
	int array2[]={1,2,3,4,5};
	int array1size=5;
	int array2size=5;
	printf("Pick which one you would like to do.\n1-Adding an element to start\n2-Adding an element to end\n3-Remove an element\n4-Remove all 'x' elements\n5-Remove 'x' last occurence\n6-Remove last element\n7-Clear all the elements\n8-Learn 'x' index\n9-Copy the array\n10-Compare two arrays.\n");
	scanf("%d", &selection);

	switch(selection)
	{
		case 1 :
			printf("Enter the element to add the start.\n");
			scanf("%d",&element);
			addFirst(array, &used, &capasity, element);
			break;
		case 2 :
			printf("Enter the element to add the end.\n");
			scanf("%d",&element);
			addLast(array, &used, &capasity, element);
			break;
		case 3 :
			printf("Enter the index of the number to remove.\n");
			scanf("%d",&index);
			removeIndex(array, &used, &capasity, index);
			break;
		case 4 :
			for(int i=0; i<SIZE; i++)
			{
				printf("%d ", array[i]);
			}
			printf("\n");
			printf("Enter the item to remove.\n");
			scanf("%d", &item);
			removeItem(array, &used, &capasity, item);
			break;
		case 5 :
			printf("Enter the element to remove.\n");
			scanf("%d", &newItem);
			removeLastOccurrence(array,&used, &capasity,newItem);
			break;
		case 6 :
			removeLast(array, &used, &capasity);
			break;
		case 7 :
			clear(array, &used, &capasity);
			break;
		case 8 :
			lastIndexOf(array, &used, &capasity);
			break;
		case 9 :
			copy();
			break;
		case 10 :
			value = compare(array1, array2, array1size, array2size);
			printf("%d\n", value);
			break;
		default :
			printf("You didn't answer right.\n");
	}

	return 0;
}

void addFirst(int array[], int *used, int *capasity, int element)
{
	if (*used == *capasity)
	{
		*capasity += *capasity;
	}

	int newArray [*capasity];
	newArray[0] = element;
	++*used;
	printf("%d\n", *used);
	for(int i=1; i < *used; i++)
	{
		newArray[i]=array[i-1];
	}

	for(int i=0; i < *used; i++)
	{
		printf("%d ", newArray[i]);
	}
	printf("\n");
}

void addLast(int array[], int *used, int *capasity, int element)
{
	if (*used == *capasity)
	{
		*capasity += *capasity;
	}

	int newArray[*capasity];
	for(int i=0; i < *used ; i++)
	{
		newArray[i]=array[i];
	}
	++*used;
	newArray[*used-1] = element;
	for(int i=0; i < *used; i++)
	{
		printf("%d ", newArray[i]);
	}
	printf("\n");
}

void removeIndex(int array[], int *used, int *capasity, int index)
{
	int newArray[*capasity];
	for(int i=0; i<index; i++)
	{
		newArray[i]=array[i];
	}
	--*used;
	for (int i=index; i< *used; i++)
	{
		newArray[i]=array[i+1];
	}
	for(int i=0; i < *used; i++)
	{
		printf("%d ", newArray[i]);
	}
	printf("\n");
}

void removeItem(int array[], int *used, int *capasity, int item)
{
	*used =0;
	int newArray[*capasity];
	int j = 0;
	for(int i=0; i<*capasity; i++)
	{
		if (array[i] != item)
		{
			newArray[j] = array [i];
			++*used;
			++j;
		}
	}

	for(int i=0; i<*used; i++)
	{
		printf("%d ", newArray[i]);
	}
	printf("\n");
}

int removeLastOccurrence(int array[], int *used, int *capasity, int item) //sıkıntılı
{
	int newestArray[*capasity-1];
	int a=0;

	for(int i=*used-1; array[i]!=item; i--)
	{
		newestArray[i-1]=array[i];
		a++;
	}
	for(int i=0; i<*used-a-1; i++)
	{
		newestArray[i]=array[i];
	}
	
	for(int i=0; i<*used-1; i++)
	{
		printf("%d ", newestArray[i]);
	}
		printf("\n");

		return 0;
	
}

void removeLast(int array[], int *used, int *capasity)
{
	int newArray[*capasity];
	--*used;
	for(int i=0; i < *used; i++)
	{
		newArray[i]=array[i];
	}
	for(int i=0; i < *used; i++)
	{
		printf("%d ", newArray[i]);
	}
	printf("\n");
}

void clear(int array[], int *used, int *capasity)
{
	int newArray[*capasity];

	for(int i=0; i<*capasity; i++)
	{
		newArray[i]=array[i];
	}

	printf("Before cleaning:");
	for(int i=0; i<*capasity; i++)
	{
		printf("%d ", newArray[i]);
	}
	printf("\n");

	for(int i=0; i<*capasity; i++)
	{
		newArray[i]=0;
		--*used;
	}

	printf("After cleaning:");
	for(int i=0; i<*capasity; i++)
	{
		printf("%d ", newArray[i]);
	}
	printf("\n");
	printf("Used number is: %d\n", *used);
}

void lastIndexOf(int array[], int *used, int *capasity)
{
	int answer;
	printf("Enter the number in the following array to learn the index of it:");
	for(int i =0; i<*used; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	scanf("%d", &answer);
	for(int i=0; i<*used; i++)
	{
		if (answer==array[i])
		{
			printf("%d\n", i);
		}
	}
}
void copy()
{	
	int capasity, used;
	printf("Enter the capasity.\n");
	scanf("%d", &capasity);
	printf("Enter the used part.\n");
	scanf("%d", &used);
	int copiedArray[capasity];
	int array[capasity];
	printf("Enter the array.\n");
	for(int i=0; i<used; i++)
	{
		scanf("%d", &array[i]);
	}
	for (int i=0; i<used; i++)
	{
		copiedArray[i]=array[i];
	}
	printf("Coppied array is: ");
	for(int i=0; i<used; i++)
	{
		printf("%d ", copiedArray[i]);
	}
	printf("\n");
}
int compare(int array1[], int array2[], int array1size, int array2size)
{
	if (array1size != array2size)
	{
		return 0;
	}
	for (int i=0; i<array1size; i++)
	{
		if (array1[i]!=array2[i])
		{
			return 0;
		}
	}
	return 1;
}