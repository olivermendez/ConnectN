#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

	const int filas_extras = 2;
	const int columnas_extras = 3;


void bienvenida(){

    cout << "\t \t \t Bienvenid@ a ConnectN " << endl;
}

int numero_a_conectar(void){
	int tamano_del_connect;
	cout<<"Cuanto quiere conectar?  "<<endl;
	cin>>tamano_del_connect;
	return tamano_del_connect;
}

char** crear_matriz(int tamano_del_connect) {
	
	char **matriz = new char *[tamano_del_connect+filas_extras];

	for (int i = 0; i <tamano_del_connect+filas_extras; i++){

		matriz [i] = new char [tamano_del_connect+columnas_extras];
		for(int j = 0; j<tamano_del_connect+columnas_extras; j++){
			matriz[i][j]= ' ';
		}
}
	return matriz;
}

void imprimir_matriz(char **matriz, int tamano_del_connect){

	cout<<" tu eres el (O) y la pc (X) "<<endl;
	for(int i = 0; i < tamano_del_connect+columnas_extras; i++){
		cout<<i<<" ";
	}
	cout<<endl;
	for( int i = 0; i < tamano_del_connect+filas_extras; i++){
		for(int j = 0; j < tamano_del_connect+columnas_extras; j++){
			cout<<matriz[i][j]<<"|";
		}
		cout<<endl;
		for(int j = 0; j< tamano_del_connect+columnas_extras; j++){
			cout<<"--";
		}
		cout<<endl;
}
}

void intentos_jugador(char **matriz, int tamano_del_connect){
	int ColNum;

	cout<<"Elija la columna para poner la ficha: "<<endl;
	cin>>ColNum;

	//Si la matrix tiene algo
	
	while(matriz[0][ColNum] == 'x' || matriz[0][ColNum] == 'o'){
		cout<<"Esa columna esta full "<<endl;
		cin>>ColNum;
	}
	for(int i = 1; i< tamano_del_connect+filas_extras; i++){

		if (matriz[i][ColNum] == 'x' || matriz[i][ColNum] =='o'){ 
				
					matriz[i-1][ColNum] = 'o';
					return;
	}
	}
	matriz[tamano_del_connect+filas_extras-1][ColNum]= 'o';
}

void turno_computador(char **matriz, int tamano_del_connect){
	srand(static_cast<unsigned int>(time(NULL)));
	rand() ;
	int ColNum = rand()%(tamano_del_connect+columnas_extras);
	
	while (matriz[0][ColNum] == 'x' || matriz[0][ColNum] == 'o'){
		ColNum= rand()%(tamano_del_connect+columnas_extras);
	}
	for(int i = 1; i< tamano_del_connect+filas_extras; i++){

		if (matriz[i][ColNum] == 'x' || matriz[i][ColNum] =='o'){ 
				
					matriz[i-1][ColNum] = 'x';
					return;
	}
	}
	matriz[tamano_del_connect+filas_extras-1][ColNum]= 'x';
}

bool chequear_filas(char **matriz, int tamano_del_connect){
	int x = 0;
	int o =0;
	for(int i = 0; i< tamano_del_connect+filas_extras; i++){
		x= 0;
		o=0;
		for(int j = 0; j<tamano_del_connect+columnas_extras; j++){
			if (matriz[i][j]=='x'){
				x++;
				o=0;
				if(x>=tamano_del_connect){
					cout<<"la pc te gano socio!!!!"<<endl;
					return true;
				}
			}
			if (matriz[i][j]=='o'){
				o++;
				x=0;
				if(o>=tamano_del_connect){
					cout<<"Ganaste pp! "<<endl;
					return true;
				}
			}
			if (matriz[i][j]==' '){
				x= 0;
				o= 0;
			}
		}
}
	return false;
}

bool chequear_columnas(char **matriz, int tamano_del_connect){
	int x = 0;
	int o =0;
	for(int i = 0; i< tamano_del_connect+columnas_extras; i++){
		x=0;
		o=0;
		for(int j = 0; j<tamano_del_connect+filas_extras; j++){
			if (matriz[j][i]=='x'){
				x++;
				o=0;
				if(x>=tamano_del_connect){
					cout<<"Te gano la pc"<<endl;
					return true;
				}
			}
			if (matriz[j][i]=='o'){
				o++;
				x=0;
				if(o>=tamano_del_connect){
					cout<<"Ganaste pp"<<endl;
					return true;
				}
			}
			if (matriz[j][i]!='x' && matriz[j][i]!='o'){
				x= 0;
				o= 0;
			}
		}
}
	return false;
}
bool chequear_derecha(char** matriz, int tamano_del_connect, int nfilas, int ncol){
	int k = nfilas;
	int x = 0;
	int o = 0;


	for(int j = ncol; j>=0 && k<tamano_del_connect+filas_extras; j--){
			if (matriz[k][j]=='x'){
				x++;
				o=0;
				if(x>=tamano_del_connect){
					cout<<"la pc te gano socio!!!!"<<endl;
					return true;
				}
			}
			if (matriz[k][j]=='o'){
				o++;
				x=0;
				if(o>=tamano_del_connect){
					cout<<"Ganaste!!!"<<endl;
					return true;
				}
			}
			if (matriz[k][j]!='x' && matriz[k][j]!='o'){
				x= 0;
				o= 0;
			}
			k++;
		}
	return false;
}

bool chequear_diagonal_derecha(char **matriz, int tamano_del_connect){
	int x = 0;
	int o =0;
	bool win = false;
	for(int i = 0; i< tamano_del_connect+filas_extras-1; i++){
		win=chequear_derecha(matriz, tamano_del_connect, i, tamano_del_connect+columnas_extras);
		if (win) return true;
	}
	for(int i = tamano_del_connect+columnas_extras-1; i>0; i--){
		win = chequear_derecha(matriz, tamano_del_connect, 0, i);
		if (win) return true;
	}

	return false;
}
bool chequear_diagonal(char** matriz, int tamano_del_connect, int row, int cols){
	int k = row;
	int x = 0;
	int o = 0;
	for(int j = cols; j>=0 && k>0; j--){
			
			if (matriz[k][j]=='x'){
				x++;
				o=0;
				if(x>=tamano_del_connect){
					cout<<"Gana la pc"<<endl;
					return true;
				}
			}
			if (matriz[k][j]=='o'){
				o++;
				x=0;
				if(o>=tamano_del_connect){
					cout<<"Ganaste tu"<<endl;
					return true;
				}
			}
			if (matriz[k][j]!='x' && matriz[k][j]!='o'){
				x= 0;
				o= 0;
			}
			k--;
		}
	return false;
}

bool chequear_diagonal_columna(char **matriz, int tamano_del_connect){
	int x =0;
	int o =0;
	bool win = false;
	for(int i = 1; i< tamano_del_connect+filas_extras; i++){
		
		win = chequear_diagonal(matriz, tamano_del_connect, i, tamano_del_connect+columnas_extras-1);
		if (win ) return true;
}
	for(int i = 1; i<tamano_del_connect+columnas_extras-1; i++){
		win = chequear_diagonal(matriz, tamano_del_connect, tamano_del_connect+filas_extras-1, i);
		if (win) return true;
	}
	return false;
}


void liberar_memoria(char **matriz, int tamano_del_connect){
	int filas_extras = 2;
	int columnas_extras = 3;
	for (int i = 0; i < tamano_del_connect+filas_extras; i++){
		delete [] matriz[i] ;	
		matriz[i] = 0 ;
	}

	delete [] matriz;
	matriz = 0 ;

}


int main(){


    bienvenida();
    bool estado_del_juego = true;
	int tamano;
	char** matriz;

	string nombre;


	tamano = numero_a_conectar();
	matriz = crear_matriz(tamano);
    cout << "Cual es tu nombre? "; cin>>nombre;
	cout << "Hola, "<<nombre;
	imprimir_matriz(matriz, tamano);




	while(estado_del_juego == true){
		intentos_jugador(matriz, tamano);
		imprimir_matriz(matriz, tamano);

		
			cout<<"Turno del computador "<<endl;
			//if(chequear_filas(matriz, tamano))break;
			//if(chequear_columnas(matriz, tamano))break;	
			if(chequear_diagonal_derecha(matriz, tamano))break;
			if(chequear_diagonal_columna(matriz, tamano))break;
			



		turno_computador(matriz, tamano);
		imprimir_matriz(matriz, tamano);
			cout << "Te toca " <<nombre<< " "<<endl;
			//if(chequear_filas(matriz, tamano))break;
			//if(chequear_columnas(matriz, tamano))break;
			if(chequear_diagonal_derecha(matriz, tamano))break;
			if(chequear_diagonal_columna(matriz, tamano))break;

			
			
	}

	liberar_memoria(matriz, tamano);
	cin.get();
	cin.get();

    
	return 0;
}

