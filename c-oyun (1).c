#include <stdio.h>
/* L bulma oyunu
Oyun 2 oyuncudan olu�ur oyuncular s�rayla oynamaktaad�r Oyun tahtas� 7 elemenal� 4 dziden olu�ur Oyun ba�lad���nda dizilerin de�eri 0 d�r
Kullan�c�lar kendi s�ralar� geldi�inde se�tikleri yere 1 veya 2 koayabilirler fakat daha �nce giri� yap�lan yere tekrar giri� yapamazlar
l �ekli 3 adet ayn� say�n�n ayn� s�t�nda bulundu�u ve bir adet ayn� say�n�n en alt sat�rda sa� tarfata bulunmas�yla olu�ur �rnek 1
																																 1
																																 1 1	
L yi olu�turan son eleman� ekleyen ilk oyuncu oyunu kazan�r

*/
int sira = 1;
int dizi[4][7];
int i;

void ekranabas() // buarada dizinin i�indeki de�erler ekrana bas�l�r 
{
	for (i = 6; i >= 0; i--)
	{
		printf("%d |%d| |%d| |%d| |%d|\n", i, dizi[0][i], dizi[1][i], dizi[2][i], dizi[3][i]);
	}
	printf("   %d   %d   %d   %d \n", 0, 1, 2, 3);
}

int isL(int x, int y, int girilendeger) // burada girilen de�erlerin kurala uygun olarak bir L olu�turup olu�turmad���n� kontrol edern
{
	if (x < 3 && y > 1)
	{
		if (dizi[x][y - 1] == girilendeger && dizi[x][y - 2] == girilendeger && dizi[x + 1][y - 2] == girilendeger)
		{
			return 1;
		}
	}
	if (x < 3 && y > 0 && y < 6)
	{
		if (dizi[x][y + 1] == girilendeger && dizi[x][y - 1] == girilendeger && dizi[x + 1][y - 1] == girilendeger)
		{
			return 1;
		}
	}
	if (x < 3 && y < 5)
	{
		if (dizi[x][y + 1] == girilendeger && dizi[x][y + 2] == girilendeger && dizi[x + 1][y] == girilendeger)
		{
			return 1;
		}
	}
	if (x > 0 && y < 5)
	{
		if (dizi[x - 1][y] == girilendeger && dizi[x - 1][y + 1] == girilendeger && dizi[x - 1][y + 2] == girilendeger)
		{
			return 1;
		}
	}
	return 0;
}

void siradegistir() // burada oyuncu s�ra de�i�imi yap�l�r
{
	if (sira == 1)
	{
		sira = 2;
	}
	else
	{
		sira = 1;
	}
}
int sayigecerlimi(int x, int y) // burda girilen de�eri �nceden dolu olup olmad��� kontrol edilir
{
	if (x >= 0 && x < 4 && y >= 0 && y < 7 && dizi[x][y] == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int oyunbs() // oyun ba�lat�l�r kullan�c�dan de�er al�p gerekli fonksiyonlar �a��r�l�r
{
	int temp = 0;
	int xkordi;
	int ykordi;
	ekranabas();
	while (1)
	{
		do
		{
			printf("%d. yarismaci kordinant girin\n", sira);
			scanf("%d%d", &xkordi, &ykordi);
		} while (!sayigecerlimi(xkordi, ykordi));

		do
		{
			printf("1 veya 2 girin\n");
			scanf("%d", &temp);
		} while (!(temp == 1 || temp == 2));

		dizi[xkordi][ykordi] = temp;
		ekranabas();
		if (isL(xkordi, ykordi, temp))
		{
			printf("oyunu %d. yarismaci kazandi\n", sira);
			system("pause");
			return 0;
		}
		siradegistir();
	}
}

int main()
{
	oyunbs();
}
