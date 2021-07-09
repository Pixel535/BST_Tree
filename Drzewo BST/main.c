#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

typedef struct drzewo
{
    int numer;
    struct drzewo *lwezel;
    struct drzewo *pwezel;
}drzewo;

void Add(drzewo **bst, int n)
{
    if((*bst) == NULL)
    {
        drzewo *nowe;
        nowe = (drzewo*)malloc(sizeof(drzewo));
        nowe -> numer = n;
        nowe -> lwezel = NULL;
        nowe -> pwezel = NULL;
       *bst = nowe;
    }
    else
    {
        if ((*bst)->numer > n)
        {
            Add(&((*bst)->lwezel), n);
        }
        else if((*bst)->numer < n)
        {
            Add(&(*bst)->pwezel, n);
        }
        else
        {
            printf("\nWartosc juz istnieje\n");
        }
    }
}

void DelALL(drzewo **bst)
{
    if ((*bst) != NULL)
    {
    if((*bst)->lwezel != NULL)
        DelALL(&((*bst)->lwezel));
    if((*bst)->pwezel != NULL)
        DelALL(&((*bst)->pwezel));
    drzewo *i;
    i = *bst;
    free(i);
    (*bst) = NULL;
    }
    else
        printf("drzewo jest puste");
}

void Del(drzewo **bst, int n)
{
    if((*bst) != NULL)
    {
        if((*bst)->numer >  n)
        {
            Del(&((*bst)->lwezel),n);
        }
        else if((*bst)->numer <  n)
        {
            Del(&((*bst)->pwezel),n);
        }
        else
        {
            DelALL(&(*bst));
        }
    }
    else
    {
        printf("Nie ma takiego elementu\n");
    }
}

void Show(drzewo *bst, int space)
{
    space += COUNT;
    if ((bst) == NULL)
    {
         return;
    }
    else
    {
        Show(bst->pwezel, space);
        printf("\n");
        for (int i = COUNT; i < space; i++)
        {
            printf(" ");
        }
        printf("%d\n", bst->numer);
        Show(bst->lwezel, space);
    }

}

void ShowWZ(drzewo **bst)
{
    if ((*bst)->lwezel != NULL)
    {
        ShowWZ(&((*bst)->lwezel));
    }
    printf("%d ",(*bst)->numer);
    if ((*bst)->pwezel != NULL)
    {
        ShowWZ(&((*bst)->pwezel));
    }
}

int main()
{
    drzewo *bst = NULL;
    int komenda;
    int n;
    printf("Program Drzewa BST\n");
	printf("----------------------------------------------\n");
	printf("[0] Wyjscie z programu\n");
	printf("[1] Dodaj wezel\n");
	printf("[2] Usun wezel\n");
	printf("[3] Wyswietl drzewo\n");
	printf("[4] wypisz wezly w kolejnosci przechodzenia\n");
	printf("----------------------------------------------\n\n");

	while(1)
    {
		printf("\nWybrana komenda: ");
		scanf("%d", &komenda);
		printf("\n");
		switch (komenda)
		{
			case 0: return 0; break;
			case 1:
			    {
                    printf("Podaj wartosc jaka chcesz dodac: ");
                    scanf("%d", &n);
			        Add(&bst, n);
			        break;
			    }

			case 2:
			    {
			        printf("Podaj wartosc jaka chcesz usunac: ");
                    scanf("%d", &n);
			        Del(&bst, n);
			        break;
			    }

			case 3:
			    {
			        Show(bst, n);
			        break;
			    }

			case 4:
			    {
			        ShowWZ(&bst);
			        printf("\n");
                    break;
			    }

        }
    }

    return 0;
}
//Mateusz Gajda Grupa WCY20IY2S1
