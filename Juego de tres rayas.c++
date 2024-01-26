#include<iostream>
using namespace std;

void mostrarTablero();
bool eleccionCasilla();
int Marcar(int x, int y);
void ActualizarTablero();
void limPan();

char eleccion;
char tablero[3][3] = { {'-','-','-'},{'-','-','-'} ,{'-','-','-'} };
int turno = 1;
int returTrue = 0;

int main()
{
	for (char i = 0; i < 3; i++) {
		for (char j = 0; j < 3; j++) {
			tablero[i][j] = '-';
		}
	}

	cout << "::::TA-TE-TI::::" << endl;
	cout << "1) Jugar" << endl;
	cout << "2) Salir" << endl;
	cin >> eleccion;
	
	switch (eleccion)
	{
	case '1':
		mostrarTablero();
		eleccionCasilla();
		break; 
        case '2':
		limPan();
		cout << "\n Hasta pronto \n " << endl;
		exit(0);
	}
	return 0;
}

void mostrarTablero()
{
	cout << "Seleccione casilla representada en numeros" << endl;
	cout << "1 | 2 | 3" << endl;
	cout << "4 | 5 | 6" << endl;
	cout << "7 | 8 | 9" << endl;
	cout << endl;
	ActualizarTablero();
}

bool eleccionCasilla()
{
	do
	{
		std::string e;
		cout << "Seleccione casilla a marcar";
		cin >> e;
		int number = std::atoi(e.c_str()) - 1; 
		if (number < 0 || number > 8) 
			continue;
		Marcar(number / 3, number % 3);  
		ActualizarTablero();
	} while (turno); 
	return true;   
}

int Marcar(int x, int y)
{
	char letra;
	if (tablero[x][y] == '-')
	{
		if (turno == 1)
		{
			tablero[x][y] = 'X';
			turno = 2;
		}
		else
		{
			tablero[x][y] = 'O';
			turno = 1;
		}
		int countHori = 0;
		char simbolo = '-';

		for (int i = 0; i < 3; i++) 
		{
			countHori = 0;
			simbolo = '-';

			for (int j = 0; j < 3; j++)
			{
				if (tablero[i][j] == '-')
					break;

				if (countHori == 0)  
					simbolo = tablero[i][j];
				else if (tablero[i][j] != simbolo) 
					break;

				++countHori;    
			}

			if (countHori == 3)
			{
				limPan();
				cout << "\n Ganó el jugador: " << turno << " de forma horizontal \n" << endl;
				do
				{
					cout << "Precione la tecla A para salir al menu principal";
					cin >> letra;
					if (letra == 'a' || letra == 'A')
					{
						countHori = 0;         
						simbolo = '-';
						limPan();
						main();
						return 0;
					}
				} while (letra != 'a' && letra != 'A');
				return 0;
			}
		}
		int countVerti = 0;
		for (int j = 0; j < 3; j++)
		{
			countVerti = 0;
			simbolo = '-';
			for (int i = 0; i < 3; i++)
			{
				if (tablero[i][j] == '-')
					break;
				if (countVerti == 0)
					simbolo = tablero[i][j];
				else if (tablero[i][j] != simbolo)
					break;
				++countVerti;
			}
			if (countVerti == 3)
			{
				limPan();
				cout << "\n Ganó el jugador: " << turno << " de forma Vertical \n" << endl;
				do
				{
					cout << "Precione la tecla A para salir al menu principal";
					cin >> letra;
					if (letra == 'a' || letra == 'A')
					{
						countHori = 0;         
						simbolo = '-';
						limPan();
						main();
						return 0;
					}
				} while (letra != 'a' && letra != 'A');
				return 0;
			}
		}
		int countIzDe = 0;
		char simboloIzDe = '-';
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (j == i)    
				{
					if (tablero[i][j] == '-')
						break;
					if (countIzDe == 0)
						simbolo = tablero[i][j];
					else if (tablero[i][j] != simbolo)
						break;
					++countIzDe;
				}
			}
			if (countIzDe == 3)
			{
				limPan();
				cout << "\n Ganó el jugador" << turno << " de izquierda a derecha de forma vertical \n" << endl;
				do
				{
					cout << "Precione la tecla A para salir al menu principal";
					cin >> letra;
					if (letra == 'a' || letra == 'A')
					{
						countHori = 0;         
						simbolo = '-';
						limPan();
						main();
						return 0;
					}
				} while (letra != 'a' && letra != 'A');
				return 0;
			}
		}
		int countDeIz = 0;
		char simboloDeIz = '-';
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i + j == 2)    
				{
					if (tablero[i][j] == '-')
						break;
					if (countDeIz == 0)
						simbolo = tablero[i][j];
					else if (tablero[i][j] != simbolo)
						break;
					++countDeIz;
				}
			}

			if (countDeIz == 3)
			{
				limPan();
				cout << "\n Ganó el jugador" << turno << " de Derecha a Izquierda de forma vertical \n" << endl;
				do
				{
					cout << "Precione la tecla A para salir al menu principal";
					cin >> letra;
					if (letra == 'a' || letra == 'A')
					{
						countHori = 0;         
						simbolo = '-';
						limPan();
						main();
						return 0;
					}
				} while (letra != 'a' && letra != 'A');
				return 0;
			}
		}
	}
	else
	{
		cout << "La casilla ya esta marcada" << endl;
	}
}

void ActualizarTablero()
{
	limPan();
	cout << endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << '|' << tablero[i][j] << '|';
		}
		cout << endl;
	}
}

void limPan()
{
	if (system("cls") == -1)
	{
		cout << " Error " << endl;
	}
}

