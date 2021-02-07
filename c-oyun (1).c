#include <stdio.h>
/* L bulma oyunu
Oyun 2 oyuncudan oluþur oyuncular sýrayla oynamaktaadýr Oyun tahtasý 7 elemenalý 4 dziden oluþur Oyun baþladýðýnda dizilerin deðeri 0 dýr
Kullanýcýlar kendi sýralarý geldiðinde seçtikleri yere 1 veya 2 koayabilirler fakat daha önce giriþ yapýlan yere tekrar giriþ yapamazlar
l þekli 3 adet ayný sayýnýn ayný sütünda bulunduðu ve bir adet ayný sayýnýn en alt satýrda sað tarfata bulunmasýyla oluþur örnek 1
																																 1
																																 1 1	
L yi oluþturan son elemaný ekleyen ilk oyuncu oyunu kazanýr

*/
int sira = 1;
int dizi[4][7];
int i;

void ekranabas() // buarada dizinin içindeki deðerler ekrana basýlýr 
{
	for (i = 6; i >= 0; i--)
	{
		printf("%d |%d| |%d| |%d| |%d|\n", i, dizi[0][i], dizi[1][i], dizi[2][i], dizi[3][i]);
	}
	printf("   %d   %d   %d   %d \n", 0, 1, 2, 3);
}

int isL(int x, int y, int girilendeger) // burada girilen deðerlerin kurala uygun olarak bir L oluþturup oluþturmadýðýný kontrol edern
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

void siradegistir() // burada oyuncu sýra deðiþimi yapýlýr
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
int sayigecerlimi(int x, int y) // burda girilen deðeri önceden dolu olup olmadýðý kontrol edilir
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

int oyunbs() // oyun baþlatýlýr kullanýcýdan deðer alýp gerekli fonksiyonlar çaðýrýlýr
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
