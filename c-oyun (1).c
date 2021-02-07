#include <stdio.h>
/*
  
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX000KXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMWNK0kdoooodxOKNWMMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMWXKOxooooooooolooxk0XWMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMWNX0kdoooloooooooooooooodxOKNWMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMWNKOxooolooooooooooooooooooolooxk0XWMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMWNX0kdollooloooooooooooooooooooooloooodk0KNWMMMMMMMMMMMMM
MMMMMMMMMMWNKOxoollooooooloooooooooooooooooooooooooooooxOKNWMMMMMMMMMM
MMMMMMMWX0kdoooooooooooooooooooooooooooooooooooooooooooooodk0XNMMMMMMM
MMMMMMNkdoloooooooooooooooooooooooooooooooooooooooooooooooooooxOXWMMMM
MMMMMMXxooooloooooooooooooooooooooooooooooooooooooooooooooolool:oKWMMM
MMMMMMXdooooooooooooooooooooooooooooooooooooooooooooooooooolooc;:OWMMM
MMMMMMXxooooooooooooooooooooooooooooooooooooooooooooooooooooooc;:OWMMM
MMMMMMXxooooooooooooooooooooooooooooooooooooooooooooooooooooooc;:OWMMM
MMMMMMXdooooooooooooooooooooooooooooooooooooooooooooooooooolooc;:OWMMM
MMMMMMXdooooooooooooooooooooooooooooooooooooooooooooooooooolooc;:OWMMM
MMMMMMXdooooooooooooooooooooooooooooooooooooooooooooooooooooooc;:OWMMM
MMMMMMXdooooooooooooooooooooooooooooooooooooooooooooooooooooooc;:OWMMM 
        _   _   _   _   _   _   _   _     _   _   _   _   _   _    
       / \ / \ / \ / \ / \ / \ / \ / \   / \ / \ / \ / \ / \ / \ 
      ( n | e | w | - | n | o | d | e ) ( s | o | c | i | a | l )
       \_/ \_/ \_/ \_/ \_/ \_/ \_/ \_/   \_/ \_/ \_/ \_/ \_/ \_/
MMMMMMXdooooooooooooooooooooooooooooooooooooooooooooooooooooooc;:OWMMM
MMMMMMXdooooooooooooooooooooooooooooooooooooooooooooooooooooooc;:OWMMM
MMMMMMXdooooooooooooooooooooooooooooooooooooooooooooooooooooooc;:OWMMM
MMMMMMXdooooooooooooooooooooooooooooooooooooooooooooooooooooooc;:OWMMM
MMMMMMXdooooooooooooooooooooooooooooooooooooooooooooooooooooooc;:OWMMM
MMMMMMXxooooooooooooooooooooooooooooooooooooooooooooooooooooool;:OWMMM
MMMMMMXxooolooooooooooooooooooooooooooooooooooooooooooooooooooc;:OWMMM
MMMMMMW0xoloolooooooooooooooooooooooooooooooooooooooooooooollc;,c0WMMM
MMMMMMMWXkdollloooooooooooooooooooooooooooooooooooooooollc:;,;:oONMMMM
MMMMMMMMMWNKOxollloooooooooooooooooooooooooooooooooollc;,,;cdOXNWMMMMM
MMMMMMMMMMMMMWX0kdolllooooolooooooooooooooooooooolc:;,,:ok0NWMMMMMMMMM
MMMMMMMMMMMMMMMMWNKOxollloooloooooooooooooooollc:,,;cdOKNWMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMWX0kdollloooooooooooollc:;,,:lx0NWMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMWNKOxollloooooollc:;,;cdOKNWMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMWX0kdolllc:;,,:lx0XWMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNKOdoc:cdkKNWMMMMMMMMMMMMMMMMMMMMMMMMMM
MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWNXK0KNWMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
*/

/* L bulma oyunu
Oyun 2 oyuncudan oluşur oyuncular sırayla oynamaktaadır Oyun tahtası 7 elemenalı 4 dziden oluşur Oyun başladığında dizilerin değeri 0 dır
Kullanıcılar kendi sıraları geldiğinde seçtikleri yere 1 veya 2 koayabilirler fakat daha önce giriş yapılan yere tekrar giriş yapamazlar
l şekli 3 adet aynı sayının aynı sütünda bulunduğu ve bir adet aynı sayının en alt satırda sağ tarfata bulunmasıyla oluşur örnek 1
																																 1
																																 1 1	
L yi oluşturan son elemanı ekleyen ilk oyuncu oyunu kazanır

*/
int sira = 1;
int dizi[4][7];
int i;

void ekranabas() // buarada dizinin içindeki değerler ekrana basılır 
{
	for (i = 6; i >= 0; i--)
	{
		printf("%d |%d| |%d| |%d| |%d|\n", i, dizi[0][i], dizi[1][i], dizi[2][i], dizi[3][i]);
	}
	printf("   %d   %d   %d   %d \n", 0, 1, 2, 3);
}

int isL(int x, int y, int girilendeger) // burada girilen değerlerin kurala uygun olarak bir L oluşturup oluşturmadığını kontrol edern
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

void siradegistir() // burada oyuncu sıra değişimi yapılır
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
int sayigecerlimi(int x, int y) // burda girilen değeri önceden dolu olup olmadığı kontrol edilir
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

int oyunbs() // oyun başlatılır kullanıcıdan değer alıp gerekli fonksiyonlar çağırılır
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
