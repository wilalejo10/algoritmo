#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <string> 

using namespace std;

void crear_estudiante(string nombre,string codigo)
{
	fstream estudiantes;
	estudiantes.open("ESTUDIANTES.csv", ios::out | ios::app);
	estudiantes << nombre << "," << codigo << "\n";
	estudiantes.close();	
}

void eliminar_estudiante(string codigo)
{
	fstream eliminacion_estudiante, eliminacion1_estudiante;
	int marks, count = 0, i, index;
	char sub;
	string line,word;
	vector<string> row;

	eliminacion_estudiante.open("ESTUDIANTES.csv", ios::in);
	eliminacion1_estudiante.open("reportcardnew.csv", ios::out);
	while(!eliminacion_estudiante.eof())
	{
		row.clear();
		getline(eliminacion_estudiante,line);
		stringstream s(line);
		while (getline(s, word, ',')) 
		{
			row.push_back(word);
		}
		int row_size = row.size();
    	if (row[1] != codigo) {
            if (!eliminacion_estudiante.eof()) {
                eliminacion1_estudiante << row[0] << "," << row[1] << "\n";
            }
        }
        else {
            count = 1;
        }
        if (eliminacion_estudiante.eof())
            break;
    }
    if (count == 1)
    {
    	 cout << "Usuario eliminado\n";	
	}
    else
    {
	
        cout << "Usuario no encontrado\n";
	}
    eliminacion_estudiante.close();
    eliminacion1_estudiante.close();
    remove("ESTUDIANTES.csv");
    rename("reportcardnew.csv", "ESTUDIANTES.csv");
}

void modificacion_estudiante(string codigo, string nombre)
{
	fstream modificacion_estudiante, modificacion1_estudiante;
	
	modificacion_estudiante.open("ESTUDIANTES.csv", ios::in);
	modificacion1_estudiante.open("reportcardnew.csv", ios::out);
	
	int count = 0;
    string line, word;
    vector<string> row;
    
    while (!modificacion_estudiante.eof()) 
	{
  		row.clear();
  
        getline(modificacion_estudiante, line);
        stringstream s(line);
  
        while (getline(s, word, ',')) 
		{
            row.push_back(word);
        }
  		int row_size = row.size();
  		if (modificacion_estudiante.eof())
        {
            break;	
		}
        if (row[1] == codigo) 
		{
            count = 1;
            modificacion1_estudiante << nombre << "," << codigo << "\n";
    	} 
    	else
    	{
    		modificacion1_estudiante << row[0] << "," << row[1] << "\n";
		}
    }
    if (count == 0)
    {
	
        cout << "Usuario no encontrado\n";
	}
    modificacion_estudiante.close();
    modificacion1_estudiante.close();
  
	remove("ESTUDIANTES.csv");
    rename("reportcardnew.csv", "ESTUDIANTES.csv");
}

void crear_nota(string codigo, string materia, string nota )
{
	fstream notas;
	notas.open("NOTAS.csv", ios::out | ios::app);
	notas << codigo << ","<< materia << ","<< nota << "\n";
	notas.close();
}

void eliminar_nota(string codigo, string materia)
{
	fstream eliminacion_nota, eliminacion1_nota;
	int count = 0;
	string line,word;
	vector<string> row;
	bool condicion;

	eliminacion_nota.open("NOTAS.csv", ios::in);
	eliminacion1_nota.open("reportcardnew.csv", ios::out);
	while(!eliminacion_nota.eof())
	{
		row.clear();
		getline(eliminacion_nota,line);
		stringstream s(line);
		while (getline(s, word, ',')) 
		{
			row.push_back(word);
		}
		int row_size = row.size();
		condicion = row[1] == materia and row[0] == codigo;
    	if (!condicion) {
            if (!eliminacion_nota.eof()) 
			{
                eliminacion1_nota << row[0] << "," << row[1] << "," <<row[2] << "\n";
            }
        }
        else {
            count = 1;
        }
        if (eliminacion_nota.eof())
            break;
    }
    if (count == 1)
    {
    	 cout << "Nota eliminada\n";	
	}
    else
    {
	
        cout << "Nota no encontrada\n";
	}
    eliminacion_nota.close();
    eliminacion1_nota.close();
    remove("NOTAS.csv");
    rename("reportcardnew.csv", "NOTAS.csv");
}

void modificacion_nota(string codigo, string materia, string nota)
{
	fstream modificacion_nota, modificacion1_nota;
	
	modificacion_nota.open("NOTAS.csv", ios::in);
	modificacion1_nota.open("reportcardnew.csv", ios::out);
	
	int count = 0;
    string line, word;
    vector<string> row;
    
    while (!modificacion_nota.eof()) 
	{
  		row.clear();
  
        getline(modificacion_nota, line);
        stringstream s(line);
  
        while (getline(s, word, ',')) 
		{
            row.push_back(word);
        }
  		int row_size = row.size();
  		if (modificacion_nota.eof())
        {
            break;	
		}
        if (row[0] == codigo and row[1] == materia) 
		{
            count = 1;
            modificacion1_nota << codigo << "," << materia <<","<< nota << "\n";
    	} 
    	else
    	{
    		modificacion1_nota << row[0] << "," << row[1] << "," << row[2] <<"\n";
		}
    }
    if (count == 0)
    {
	
        cout << "Nota no encontrada\n";
	}
    modificacion_nota.close();
    modificacion1_nota.close();
  
	remove("NOTAS.csv");
    rename("reportcardnew.csv", "NOTAS.csv");
}

void crear_profesor(string nombre,string codigo)
{
	fstream profesores;
	profesores.open("PROFESORES.csv", ios::out | ios::app);
	profesores << nombre << "," << codigo << "\n";
	profesores.close();	
}

void eliminar_profesor(string codigo)
{
	fstream eliminacion_profesor, eliminacion1_profesor;
	int count = 0;
	char sub;
	string line,word;
	vector<string> row;

	eliminacion_profesor.open("PROFESORES.csv", ios::in);
	eliminacion1_profesor.open("reportcardnew.csv", ios::out);
	while(!eliminacion_profesor.eof())
	{
		row.clear();
		getline(eliminacion_profesor,line);
		stringstream s(line);
		while (getline(s, word, ',')) 
		{
			row.push_back(word);
		}
		int row_size = row.size();
    	if (row[1] != codigo) {
            if (!eliminacion_profesor.eof()) {
                eliminacion1_profesor << row[0] << "," << row[1] << "\n";
            }
        }
        else {
            count = 1;
        }
        if (eliminacion_profesor.eof())
            break;
    }
    if (count == 1)
    {
    	 cout << "Profesor eliminado\n";	
	}
    else
    {
	
        cout << "Profesor no encontrado\n";
	}
    eliminacion_profesor.close();
    eliminacion1_profesor.close();
    remove("PROFESORES.csv");
    rename("reportcardnew.csv", "PROFESORES.csv");
}

void modificacion_profesor(string codigo, string nombre)
{
	fstream modificacion_profesores, modificacion1_profesores;
	
	modificacion_profesores.open("PROFESORES.csv", ios::in);
	modificacion1_profesores.open("reportcardnew.csv", ios::out);
	
	int count = 0;
    string line, word;
    vector<string> row;
    
    while (!modificacion_profesores.eof()) 
	{
  		row.clear();
  
        getline(modificacion_profesores, line);
        stringstream s(line);
  
        while (getline(s, word, ',')) 
		{
            row.push_back(word);
        }
  		int row_size = row.size();
  		if (modificacion_profesores.eof())
        {
            break;	
		}
        if (row[1] == codigo) 
		{
            count = 1;
            modificacion1_profesores << nombre << "," << codigo << "\n";
    	} 
    	else
    	{
    		modificacion1_profesores << row[0] << "," << row[1] << "\n";
		}
    }
    if (count == 0)
    {
	
        cout << "Usuario no encontrado\n";
	}
    modificacion_profesores.close();
    modificacion1_profesores.close();
  
	remove("PROFESORES.csv");
    rename("reportcardnew.csv", "PROFESORES.csv");
}

void mostrar_notas(string codigo)
{
	fstream mostar_nota;
	
	mostar_nota.open("NOTAS.csv", ios::in);
	
    string line, word;
    vector<string> row;
    
    while (!mostar_nota.eof()) 
	{
  		row.clear();
  
        getline(mostar_nota, line);
        stringstream s(line);
  
        while (getline(s, word, ',')) 
		{
            row.push_back(word);
        }
  		int row_size = row.size();
  		if (mostar_nota.eof())
        {
            break;	
		}
        if (row[0] == codigo) 
		{
            cout << "La nota de " << row[1] << " es: " << row[2] << endl;
    	} 
    }
    mostar_nota.close();
}

int main() 
{
    int opcion;
    string codigo;

    do {
		cout << "                                   UNIVERSIDAD DISTRITAL FRANCISCO JOSE DE CALDAS" << endl;
        cout << "Ingrese una opcion: " << endl;
		cout << "1. Estudiante" << endl;
        cout << "2. Profesor" << endl;
        cout << "3. Administrador" << endl;
        cout << "4. Salir" << endl;
        cin >> opcion;

        switch(opcion) {
            case 1:
              	cout << "Digite su codigo" << endl;
              	cin >> codigo;
              	mostrar_notas(codigo);
                break;
            case 2:	
				cout << "Digite la opcion que desea realizar" << endl;
              	cout << "1. Agregar una nota" << endl;
               	cout << "2. Eliminar una nota" << endl;
               	cout << "3. Modificar una nota" << endl;
               	cin >> opcion;
               	if (1 == opcion)
               	{
               		string materia, nota;
					cout << "Ingrese el codigo del estudiante que desea agregar la nota"<<endl;
					cin >> codigo;
					cout << "Ingrese la materia del estudiante que desea agregar la nota (calculo, algebra, textos, algoritmos, catedra)"<< endl;
					cin >> materia;
					cout << "Ingrese la nota a cear" << endl;
					cin >> nota;
					crear_nota(codigo, materia, nota );
				}
				else if (2 == opcion)
				{
					string materia;
					cout << "Ingrese el codigo del estudiante que desea eliminar la nota"<<endl;
					cin >> codigo;
					cout << "Ingrese la materia del estudiante que desea eliminar la nota (calculo, algebra, textos, algoritmos, catedra)"<< endl;
					cin >> materia;	
					eliminar_nota(codigo, materia);	
				}
				else if (3 == opcion)
				{
					string  materia, nota;
					cout << "Ingrese el codigo del estudiante que desea actualizar la nota"<<endl;
					cin >> codigo;
					cout << "Ingrese la materia del estudiante que desea actualizar la nota (calculo, algebra, textos, algoritmos, catedra)"<< endl;
					cin >> materia;
					cout << "Ingrese la nota a actualizar" << endl;
					cin >> nota;
					modificacion_nota(codigo, materia, nota);
				}
                break;
            case 3:
                cout << "Digite la opcion que desea realizar" << endl;
                cout << "1. Agregar un estudiante" << endl;
               	cout << "2. Eliminar un estudiante" << endl;
                cout << "3. Modificar datos de un estudiante" << endl;
				cout << "4. Agregar una nota" << endl;
                cout << "5. Eliminar una nota" << endl;
                cout << "6. Modificar una nota" << endl;
                cout << "7. Agregar un profesor" << endl;
                cout << "8. Eliminar un profesor" << endl;
                cout << "9. Modificar datos de un profesor" << endl;
                cin >> opcion;
				if(1 == opcion)
				{
					string nombre;
					cout << "Ingrese el nombre del estudiante a crear"<< endl;
					cin >> nombre;
					cout << "Ingrese el codigo del estudiante a crear"<< endl;
					cin >> codigo;
					crear_estudiante(nombre,codigo);
				}
				else if (2 == opcion)
				{
				
					cout << "Ingrese el codigo del estudiante a eliminar"<< endl;
					cin >> codigo;
					eliminar_estudiante(codigo);
				}
				else if (3 == opcion)
				{
					string nombre;
					cout << "Ingrese el codigo del estudiante"<< endl;
					cin >> codigo;
					cout << "Ingrese el nombre del estudiante a actualizar"<< endl;
					cin >> nombre;
					modificacion_estudiante(codigo,nombre);
				}	
				else if (4 == opcion)
				{
					string  materia, nota;
					cout << "Ingrese el codigo del estudiante que desea agregar la nota"<<endl;
					cin >> codigo;
					cout << "Ingrese la materia del estudiante que desea agregar la nota (calculo, algebra, textos, algoritmos, catedra)"<< endl;
					cin >> materia;
					cout << "Ingrese la nota a cear" << endl;
					cin >> nota;
					crear_nota(codigo, materia, nota );
				}
				else if (5 == opcion)
				{
					string  materia;
					cout << "Ingrese el codigo del estudiante que desea eliminar la nota"<<endl;
					cin >> codigo;
					cout << "Ingrese la materia del estudiante que desea eliminar la nota (calculo, algebra, textos, algoritmos, catedra)"<< endl;
					cin >> materia;	
					eliminar_nota(codigo, materia);	
				}
				else if (6 == opcion)
				{
					string  materia, nota;
					cout << "Ingrese el codigo del estudiante que desea actualizar la nota"<<endl;
					cin >> codigo;
					cout << "Ingrese la materia del estudiante que desea actualizar la nota (calculo, algebra, textos, algoritmos, catedra)"<< endl;
					cin >> materia;
					cout << "Ingrese la nota a actualizar" << endl;
					cin >> nota;
					modificacion_nota(codigo, materia, nota);
				}
				else if (7 == opcion)
				{
					string nombre;
					cout << "Ingrese el nombre del profesor a crear"<< endl;
					cin >> nombre;
					cout << "Ingrese el codigo del profesor a crear"<< endl;
					cin >> codigo;
					crear_profesor(nombre,codigo);
				}
				else if (8 == opcion)
				{
					cout << "Ingrese el codigo del profesor a eliminar"<< endl;
					cin >> codigo;
					eliminar_profesor(codigo);
				}
				else if (9 == opcion)
				{
					string nombre;
					cout << "Ingrese el codigo del profesor"<< endl;
					cin >> codigo;
					cout << "Ingrese el nombre del profesor a actualizar"<< endl;
					cin >> nombre;
					modificacion_profesor(codigo,nombre);
				}
                break;
            case 4:
                cout << "Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        } 
	}
	while(opcion != 4);
	return 0;
}
