#include"pch.h"
#include<iostream>
#include<string>
#include<cctype>//toupper, isdigit
#include<cstdlib>//new y delete
#include<ctime>//rand y srand y fecha
#include<chrono>//fecha
#include<iomanip>//setw
#include<clocale>//setlocale
#include<algorithm>//sort
#define VERDE "\033[32m"
#define RESET "\033[0m"
#define AZUL "\033[34m"
#define CELESTE "\033[36m"
#define ROJO "\033[31m"
#define AMARILLO "\x1b[33m"
#define NARANJA "\x1B[38;2;255;128;0m"
#define LVERDE "\x1B[38;2;17;245;120m"
#define LAZUL "\x1B[38;2;53;149;240m"
#define FONDO_AMA "\x1B[43m"

using namespace std;
using namespace System;

struct datos_usuario
{
    string dni;
    string nombre_apellido;
    string sexo;
    string correo;
    string direccion;
};
struct datos_libro
{
    int codigo;
    string titulo;
    char tipo;
    double costo;
    double venta;
    char local_disponiblidad;
};
struct modalidad
{
    char tipo_modalidad;
    char recojo;

};
struct fecha
{
    int hora;
    int minutos;
    int dia;
    int mes;
    int a�o;
};
struct datos_venta
{
    fecha fecha;
    modalidad modalidad;
    char local;
    datos_usuario datos_usuario;
    datos_libro datos_libro;
    string metodo_pago;
};

void generacion_stock(datos_venta* stock);
void registro_nuevo_usuario(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales);
void opcion_menu(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales);
void ventas_miraflores(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales);
void ventas_san_isidro(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales);
void ventas_presencial(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales);
void mangas(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales);
void comic(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales);
void ventas_whatsapp(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales);
void recojo_en_tienda(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales);
void delivery(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales);
void impresion_boleta(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales);
void funcion_fecha(datos_venta* venta_unitaria);
void registrar_ventas_y_usuarios(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales);
void opcion_continuar(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales);
int validar(string x);
void dibujar_barra(float cantidad);
void reporte_1(datos_venta* venta_unitaria, int* cantidad_mangas_vendidos, int* cantidad_comics_vendidos);
void reporte_2(datos_venta* ventas_generales, int* cantidad_mangas_vendidos, int* cantidad_comics_vendidos);
void reporte_3(datos_venta* ventas_generales, int* cantidad_mangas_vendidos, int* cantidad_comics_vendidos);
void reporte_4(datos_venta* ventas_generales, int* cantidad_mangas_vendidos, int* cantidad_comics_vendidos);
void reporte_5(datos_venta* ventas_generales, int* cantidad_mangas_vendidos, int* cantidad_comics_vendidos);
void reporte_6(datos_venta* ventas_generales, int* cantidad_mangas_vendidos, int* cantidad_comics_vendidos);

string convertir_digito(int numero)
{
    switch (numero) {
    case 0:
        return "cero";
    case 1:
        return "uno";
    case 2:
        return "dos";
    case 3:
        return "tres";
    case 4:
        return "cuatro";
    case 5:
        return "cinco";
    case 6:
        return "seis";
    case 7:
        return "siete";
    case 8:
        return "ocho";
    case 9:
        return "nueve";
    default:
        return "";
    }
}
string convertir_menor_que_veinte(int numero)
{
    setlocale(LC_CTYPE, "Spanish");
    switch (numero) {
    case 10:
        return "diez";
    case 11:
        return "once";
    case 12:
        return "doce";
    case 13:
        return "trece";
    case 14:
        return "catorce";
    case 15:
        return "quince";
    case 16:
        return "diecis�is";
    case 17:
        return "diecisiete";
    case 18:
        return "dieciocho";
    case 19:
        return "diecinueve";
    default:
        return "";
    }
}
string convertir_decena(int numero)
{
    switch (numero) {
    case 2: return "veint";
    case 3: return "treinta";
    case 4: return "cuarenta";
    case 5: return "cincuenta";
    case 6: return "sesenta";
    case 7: return "setenta";
    case 8: return "ochenta";
    case 9: return "noventa";
    default: return "";
    }
}
string convertir_centena(int numero)
{
    setlocale(LC_CTYPE, "Spanish");
    switch (numero)
    {
    case 1:return "cien";
    case 2:return "doscientos";
    case 3:return "trescientos";
    case 4:return "cuatrocientos";
    case 5:return "quinientos";
    case 6:return "seiscientos";
    case 7:return "setecientrps";
    case 8:return "ochocientos";
    case 9:return "novecientos";
    default: return "";
    }
}
string convertir_numero_en_palabras(int numero)
{
    if (numero < 10)
    {
        return convertir_digito(numero);
    }
    else if (numero < 20)
    {
        return convertir_menor_que_veinte(numero);
    }
    else if (numero < 100)
    {
        int decena = numero / 10;
        int unidad = numero % 10;
        if (unidad == 0 && decena == 2)
        {
            return convertir_decena(decena) + "e";
        }
        else
        {
            if (decena >= 2 && decena < 3)
            {
                return convertir_decena(decena) + "i" + convertir_digito(unidad);
            }
            else
            {
                if (unidad == 0)
                {
                    return convertir_decena(decena);
                }
                else
                {
                    return convertir_decena(decena) + " y " + convertir_digito(unidad);
                }
            }
        }


    }
    else if (numero < 1000)
    {
        int centena = numero / 100;
        int decena = numero / 10 % 10;
        int unidad = numero % 10;
        if (unidad == 0 && decena == 0)
        {
            return convertir_centena(centena);
        }
        else if (centena == 1 && decena == 0)
        {
            return convertir_centena(centena) + "to " + convertir_digito(unidad);
        }

        else if (centena == 1 && decena >= 1 && decena < 2)
        {
            return convertir_centena(centena) + "to " + convertir_menor_que_veinte(decena * 10 + unidad);
        }
        else if (centena == 1 && decena >= 2 && decena < 3 && unidad == 0)
        {
            return convertir_centena(centena) + "to " + convertir_decena(decena) + "e";
        }
        else if (centena == 1 && decena == 2)
        {
            return convertir_centena(centena) + "to " + convertir_decena(decena) + "i" + convertir_digito(unidad);
        }
        else if (centena == 1 && decena >= 3 && unidad == 0)
        {
            return convertir_centena(centena) + "to " + convertir_decena(decena);
        }
        else if (centena == 1 && decena >= 3)
        {
            return convertir_centena(centena) + "to " + convertir_decena(decena) + " y " + convertir_digito(unidad);
        }
        else if (decena < 2 && decena >= 1)
        {
            return convertir_centena(centena) + " " + convertir_menor_que_veinte(decena * 10 + unidad);
        }
        else if (decena >= 2 && unidad != 0)
        {
            return convertir_centena(centena) + " " + convertir_decena(decena) + " y " + convertir_digito(unidad);
        }

        else if (unidad == 0)
        {
            return convertir_centena(centena) + " " + convertir_decena(decena);
        }
        else if (decena == 0)
        {
            return convertir_centena(centena) + " " + convertir_digito(unidad);
        }
        else
        {
            return convertir_centena(centena) + convertir_decena(decena) + " y " + convertir_digito(unidad);
        }
    }
    else {
        return "N�mero fuera de rango";
    }
}

void generacion_stock(datos_venta* stock)
{
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        /*
            |Miraflores |    | San Isidro|
            |Comic|Manga|    |Comic|Manga|
            |11XX |12XX |    |21XX |22XX |
         |Thanos  |DragonB   SecWar|ChainsawMan01
         |Thor    |MHeroA    Spider|JoJo's Bizarre Adventure: Part 1
         |TonyS.  |                |DeathNote01
        */
        if (i >= 90 && i < 100)
        {
            stock[i].datos_libro.titulo = "Chainsaw Man 01";
            stock[i].datos_libro.venta = 27.30;
            stock[i].datos_libro.tipo = 'M';
            stock[i].datos_libro.costo = 31.00;
            stock[i].datos_libro.local_disponiblidad = 'S';
        }
        else if (i >= 80 && i < 90)
        {
            stock[i].datos_libro.titulo = "Death Note 01";
            stock[i].datos_libro.venta = 27.30;
            stock[i].datos_libro.tipo = 'M';
            stock[i].datos_libro.costo = 31.00;
            stock[i].datos_libro.local_disponiblidad = 'S';
        }
        else if (i >= 70 && i < 80)
        {
            stock[i].datos_libro.titulo = "JoJo's Bizarre Adventure: Part 1";
            stock[i].datos_libro.venta = 27.30;
            stock[i].datos_libro.tipo = 'M';
            stock[i].datos_libro.costo = 31.00;
            stock[i].datos_libro.local_disponiblidad = 'S';
        }
        else if (i >= 60 && i < 70)
        {
            stock[i].datos_libro.titulo = "Dragon Ball Super 03";
            stock[i].datos_libro.venta = 27.30;
            stock[i].datos_libro.tipo = 'M';
            stock[i].datos_libro.costo = 31.00;
            stock[i].datos_libro.local_disponiblidad = 'M';
        }
        else if (i >= 50 && i < 60)
        {
            stock[i].datos_libro.titulo = "My Hero Academy 01";
            stock[i].datos_libro.venta = 25.20;
            stock[i].datos_libro.tipo = 'M';
            stock[i].datos_libro.costo = 32.60;
            stock[i].datos_libro.local_disponiblidad = 'M';
        }
        else if (i >= 40 && i < 50)
        {
            stock[i].datos_libro.titulo = "Marvel Secret War";
            stock[i].datos_libro.venta = 109.00;
            stock[i].datos_libro.tipo = 'C';
            stock[i].datos_libro.costo = 120.10;
            stock[i].datos_libro.local_disponiblidad = 'S';
        }
        else if (i >= 30 && i < 40)
        {
            stock[i].datos_libro.titulo = "Marvel Ultimate Spiderman 2";
            stock[i].datos_libro.venta = 108.50;
            stock[i].datos_libro.tipo = 'C';
            stock[i].datos_libro.costo = 115.90;
            stock[i].datos_libro.local_disponiblidad = 'S';
        }
        else if (i >= 20 && i < 30)
        {
            stock[i].datos_libro.titulo = "Marvel Thanos. Poderes Cosmicos";
            stock[i].datos_libro.venta = 89.40;
            stock[i].datos_libro.tipo = 'C';
            stock[i].datos_libro.costo = 93.10;
            stock[i].datos_libro.local_disponiblidad = 'M';
        }
        else if (i >= 10 && i < 20)
        {
            stock[i].datos_libro.titulo = "Marvel Thor. Vikingos";
            stock[i].datos_libro.venta = 47.40;
            stock[i].datos_libro.tipo = 'C';
            stock[i].datos_libro.costo = 54.80;
            stock[i].datos_libro.local_disponiblidad = 'M';
        }
        else if (i >= 0 && i < 10)
        {
            stock[i].datos_libro.titulo = "Marvel Tony Stark. Iron Man 01";
            stock[i].datos_libro.venta = 46.00;
            stock[i].datos_libro.tipo = 'C';
            stock[i].datos_libro.costo = 49.70;
            stock[i].datos_libro.local_disponiblidad = 'M';
        }
        int numero_magico = 1 + rand() % (99 + 1 - 1);
        switch (stock[i].datos_libro.local_disponiblidad)
        {
        case 'M':
            switch (stock[i].datos_libro.tipo)
            {
            case'M':
                stock[i].datos_libro.codigo = 1100 + numero_magico;
                break;
            case'C':
                stock[i].datos_libro.codigo = 1200 + numero_magico;
            default:
                break;
            }
            break;
        case'S':
            switch (stock[i].datos_libro.tipo)
            {
            case'M':
                stock[i].datos_libro.codigo = 2100 + numero_magico;
                break;
            case'C':
                stock[i].datos_libro.codigo = 2200 + numero_magico;
            default:
                break;
            }
            break;
        default:
            break;
        }

    }
}
void registro_nuevo_usuario(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales)
{
    bool numero = true;
    bool gmail_repetido = false;
    bool dni_repetido = false;
    bool esgmail;
    int iterador = 0;
    int cantidad_libros_vendidos = 0;
    for (int i = 0; i < 5; i++)
    {
        cantidad_libros_vendidos += cantidad_mangas_ya_vendidos[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cantidad_libros_vendidos += cantidad_comics_ya_vendidos[i];
    }
    usuario_datos = new datos_venta[1];
    cout << "===================BIENVENIDO/A A LIBRER�A MULTILIBROS===================";
    for (int i = 0; i < 1; i++)
    {
        cout << CELESTE << "\n\t\tIngrese su Nombre y Apellido: " << RESET;
        getline(cin, usuario_datos[i].datos_usuario.nombre_apellido);
        validar(usuario_datos[i].datos_usuario.nombre_apellido);
        while (validar(usuario_datos[i].datos_usuario.nombre_apellido) == 0)
        {

            cout << ROJO << "\t\t\tINGRESE SOLO LETRAS" << RESET << endl;
            cout << CELESTE << "\t\tIngrese su Nombre y Apellido:" << RESET;
            getline(cin, usuario_datos[i].datos_usuario.nombre_apellido);

        }
        do
        {
            iterador = 0;
            numero = true;
            dni_repetido = true;
            cout << CELESTE << "\t\tIngrese su DNI: " << RESET; getline(cin, usuario_datos[i].datos_usuario.dni);
            for (int i = 1; i < cantidad_libros_vendidos + 1; i++)
            {
                if (ventas_generales[i].datos_usuario.dni == venta_unitaria[0].datos_usuario.dni)
                {
                    cout << ROJO << "\t\tDNI YA REGISTRADO" << RESET << endl;
                    dni_repetido = false;
                }
            }
            while (usuario_datos[i].datos_usuario.dni[iterador] != '\0' && numero)
            {

                if (isdigit(usuario_datos[i].datos_usuario.dni[iterador]) != 0)
                {
                    iterador++;

                }
                else
                {
                    cout << ROJO << "\t\t\tINGRESE SOLO NUMEROS" << RESET << endl;
                    numero = false;
                }
            }
            if (usuario_datos[0].datos_usuario.dni.length() != 8)
            {
                cout << ROJO "\t\t\tINGRESE 8 D�GITOS" << endl << RESET;
            }

        } while (!numero || !dni_repetido || usuario_datos[0].datos_usuario.dni.length() != 8);
        do
        {
            cout << CELESTE << "\t\tIngrese su sexo (M o F): " << RESET;
            cin >> usuario_datos[i].datos_usuario.sexo;
            if (usuario_datos[i].datos_usuario.sexo == "m")
            {
                usuario_datos[i].datos_usuario.sexo = "M";
            }
            else if (usuario_datos[i].datos_usuario.sexo == "f")
            {
                usuario_datos[i].datos_usuario.sexo = "F";
            }
        } while ((usuario_datos[i].datos_usuario.sexo != "F" && usuario_datos[i].datos_usuario.sexo != "M") || usuario_datos[i].datos_usuario.sexo.length() != 1);
        do
        {
            char caracter;
            esgmail = true;
            gmail_repetido = true;
            cout << CELESTE << "\t\tIngrese su correo electronico: " << RESET; cin >> usuario_datos[i].datos_usuario.correo;
            for (int i = 0; i < usuario_datos[0].datos_usuario.correo.length(); i++)
            {
                caracter = usuario_datos[0].datos_usuario.correo[i];
                if (caracter == '@')
                {
                    esgmail = true;
                    break;
                }
                else
                {
                    esgmail = false;
                }
            }
            for (int i = 1; i < cantidad_libros_vendidos + 1; i++)
            {
                if (ventas_generales[i].datos_usuario.correo == venta_unitaria[0].datos_usuario.correo)
                {
                    cout << ROJO << "\t\t\tCORREO YA REGISTRADO" << RESET << endl;
                    gmail_repetido = false;
                }
            }
        } while (!gmail_repetido || !esgmail);

    }
    system("cls");
    opcion_menu(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
}
void opcion_menu(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales)
{
    venta_unitaria = new datos_venta[1];
    int opcion;
    for (int i = 0; i < 1; i++)
    {
        if (cantidad_mangas_ya_vendidos[i] == 0 && cantidad_comics_ya_vendidos[i] == 0 && cantidad_mangas_ya_vendidos[i + 1] == 0 && cantidad_comics_ya_vendidos[i + 1] == 0 && cantidad_mangas_ya_vendidos[i + 2] == 0 && cantidad_comics_ya_vendidos[i + 2] == 0 && cantidad_mangas_ya_vendidos[i + 3] == 0 && cantidad_comics_ya_vendidos[i + 3] == 0 && cantidad_mangas_ya_vendidos[i + 4] == 0 && cantidad_comics_ya_vendidos[i + 4] == 0)
        {
            generacion_stock(el_stock);
            cout << "\n";
            cout << "===================BIENVENIDO A LIBRERIA MULTILIBROS, " << usuario_datos[0].datos_usuario.nombre_apellido << "===================" << endl;
        }
    }
    cout << "\n\t\t\t Escoga opcion para registrar" << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << CELESTE "\t\t\t Opcion 1: SEDE MIRAFLORES " << endl;
    cout << "\t\t\t Opcion 2: SEDE SAN ISIDRO " << endl;
    cout << "\t\t\t Opcion 3: Salir del Sistema " << RESET << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << "\n";
    do
    {
        cout << "\tIngrese Opcion a registrar -> : "; cin >> opcion;
    } while (opcion < 1 || opcion>3);
    switch (opcion)
    {
    case 1:
        venta_unitaria[0].local = 'M';
        ventas_miraflores(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;
    case 2:
        venta_unitaria[0].local = 'S';
        ventas_san_isidro(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;
    case 3:
        exit(0);
    default:
        cout << "\n\tOpcion ingresada inavalido " << endl;
        cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
        opcion_menu(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;
    }
}
void ventas_miraflores(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales)
{
    system("cls");
    int opcion;
    cout << "\n\t\t\t Escoja opcion para registrar" << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << VERDE << "\t\t\t\t SEDE: MIRAFLORES" << RESET << endl;
    cout << CELESTE << "\t\t\t Opcion 1: MODALIDAD PRESENCIAL" << endl;
    cout << "\t\t\t Opcion 2: MODALIDAD WhatsApp (RECOJO)" << endl;
    cout << "\t\t\t Opcion 3: VOLVER AL MENU" << RESET << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << "\n";
    do
    {
        cout << "\tIngrese Opcion a registrar -> : "; cin >> opcion;
    } while (opcion < 1 || opcion>3);
    switch (opcion)
    {
    case 1:
        venta_unitaria[0].modalidad.tipo_modalidad = 'P';
        ventas_presencial(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;
    case 2:
        venta_unitaria[0].modalidad.tipo_modalidad = 'W';
        ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;
    case 3:
        opcion_menu(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;
    default:
        cout << "\n\tOpcion ingresada inavalida " << endl;
        cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
        ventas_miraflores(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;
    }
}
void ventas_san_isidro(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales)
{
    system("cls");
    int opcion;
    cout << "\n\t\t\t Escoja opcion para registrar" << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << VERDE << "\t\t\t\t SEDE: SAN ISIDRO" << RESET << endl;
    cout << CELESTE << "\t\t\t Opcion 1: MODALIDAD PRESENCIAL:" << endl;
    cout << "\t\t\t Opcion 2: MODALIDAD WhatsApp (RECOJO)" << endl;
    cout << "\t\t\t Opcion 3: VOLVER AL MENU" << RESET << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << "\n";
    do
    {
        cout << "\tIngrese Opcion a registrar -> : "; cin >> opcion;
    } while (opcion < 1 || opcion>3);
    switch (opcion)
    {
    case 1:
        venta_unitaria[0].modalidad.tipo_modalidad = 'P';
        ventas_presencial(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;
    case 2:
        venta_unitaria[0].modalidad.tipo_modalidad = 'W';
        ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;
    case 3:
        opcion_menu(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;
    default:
        cout << "\n\tOpcion ingresada inavalido " << endl;
        cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
        ventas_san_isidro(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;
    }
}
void ventas_presencial(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales)
{
    system("cls");
    int opcion;
    generacion_stock(el_stock);
    cout << "\n\t\t\t Escoja opcion para registrar" << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << VERDE << "\t\t\t\t SEDE: ";
    if (venta_unitaria[0].local == 'S')
    {
        cout << "SAN INSIDRO";
    }
    if (venta_unitaria[0].local == 'M')
    {
        cout << "MIRAFLORES";
    }
    cout << RESET << endl;
    cout << VERDE << "\t\t\t\t MODALIDAD: PRESENCIAL" << RESET << endl;
    cout << CELESTE << "\t\t\t Opcion 1: MANGAS" << endl;
    cout << "\t\t\t Opcion 2: COMICS" << endl;
    cout << "\t\t\t Opcion 3: VOLVER A SELECCION DE MODALIDADES" << RESET << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << "\n";
    do
    {
        cout << "\tIngrese Opcion a registrar -> : "; cin >> opcion;
    } while (opcion < 1 || opcion>3);
    switch (opcion)
    {
    case 1:
        venta_unitaria[0].datos_libro.tipo = 'M';
        mangas(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;
    case 2:
        venta_unitaria[0].datos_libro.tipo = 'C';
        comic(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;
    case 3:
        if (venta_unitaria[0].local == 'M')
        {
            ventas_miraflores(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        }
        else if (venta_unitaria[0].local == 'S')
        {
            ventas_san_isidro(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        }
        break;
    default:
        cout << "\n\tOpcion ingresada inavalido " << endl;
        cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
        ventas_presencial(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;
    }
}
void mangas(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales)
{
    system("cls");
    int opcion;
    cout << "\n\t\t\t Escoja opcion para registrar" << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << VERDE << "\t\t\t\t SEDE: ";
    if (venta_unitaria[0].local == 'S')
    {
        cout << "SAN INSIDRO";
    }
    if (venta_unitaria[0].local == 'M')
    {
        cout << "MIRAFLORES";
    }
    cout << RESET << endl;
    cout << VERDE << "\t\t\t\t MODALIDAD: PRESENCIAL" << RESET << endl;
    cout << VERDE << "\t\t\t\t TIPO DE LIBRO: MANGA" << RESET << endl;

    int iteracion = 0;
    if (cantidad_mangas_ya_vendidos[0] == 10)
    {
        el_stock[50].datos_libro.titulo = "AGOTADO";
    }
    if (cantidad_mangas_ya_vendidos[1] == 10)
    {
        el_stock[60].datos_libro.titulo = "AGOTADO";
    }
    if (cantidad_mangas_ya_vendidos[2] == 10)
    {
        el_stock[70].datos_libro.titulo = "AGOTADO";
    }
    if (cantidad_mangas_ya_vendidos[3] == 10)
    {
        el_stock[80].datos_libro.titulo = "AGOTADO";
    }
    if (cantidad_mangas_ya_vendidos[4] == 10)
    {
        el_stock[90].datos_libro.titulo = "AGOTADO";
    }
    for (int i = 0; i < 100; i = i + 10)
    {
        if (el_stock[i].datos_libro.tipo == 'M' && el_stock[i].datos_libro.local_disponiblidad == venta_unitaria[0].local)
        {
            cout << CELESTE << "\t\t\t\t Opcion " << iteracion + 1 << ": ";
            if (el_stock[i].datos_libro.titulo == "AGOTADO")
            {
                cout << ROJO << el_stock[i + 1].datos_libro.titulo << " (AGOTADO)" << RESET << endl;
                iteracion++;
            }
            else if (el_stock[i].datos_libro.titulo != "AGOTADO")
            {
                cout << CELESTE << el_stock[i].datos_libro.titulo << "\t" << setw(5) << VERDE << " (S/. " << el_stock[i].datos_libro.venta << ")" << RESET << endl;
                iteracion++;
            }

        }
    }
    cout << CELESTE << "\t\t\t OPCION " << iteracion + 1 << ": VOLVER LA SELECCION DE TIPO DE LIBRO" << RESET << endl;
    cout << "\n";
    cout << "\t\t\t-----------------------------------" << endl;
    cout << "\n";
    do
    {
        cout << "\tIngrese Opcion a registrar -> : "; cin >> opcion;
    } while (opcion < 1 || opcion>iteracion + 1);
    int OpcionConfirmar;

    if (iteracion == 2)
    {
        switch (opcion)
        {
        case 1:
            if (cantidad_mangas_ya_vendidos[0] == 10)
            {
                cout << endl;
                cout << ROJO << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                mangas(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            }
            cout << endl << "\t\t\tDesea comprar el libro seleccionado? " << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << CELESTE << "\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << "\t\t\tIngrese Opcion a registrar ->"; cin >> OpcionConfirmar;
            if (OpcionConfirmar == 1)
            {
                do
                {
                    cout << "\t\t\tINGRESE A�O ACTUAL: " << endl;
                    cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    if (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024)
                    {
                        cout << "\n\t\t\tINGRESE A�O ACTUAL (2022-2024): " << endl;
                        cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    }
                } while (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024);
                if (el_stock[50].datos_libro.titulo != "VACIO")
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[50].datos_libro.titulo;
                    el_stock[50].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[50].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[50].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[50].datos_libro.codigo;
                    cantidad_mangas_ya_vendidos[0]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                    break;
                }
                else
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[50 + cantidad_mangas_ya_vendidos[0]].datos_libro.titulo;
                    el_stock[50 + cantidad_mangas_ya_vendidos[0]].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[50].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[50].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[50].datos_libro.codigo;
                    cantidad_mangas_ya_vendidos[0]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                }
            }
            else if (OpcionConfirmar == 2)
            {
                mangas(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            }
            break;
        case 2:
            if (cantidad_mangas_ya_vendidos[1] == 10)
            {
                cout << endl;
                cout << ROJO << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                mangas(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            }
            cout << endl << "\t\t\tDesea comprar el libro seleccionado? " << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << CELESTE << "\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << "\t\t\tIngrese Opcion a registrar ->"; cin >> OpcionConfirmar;
            if (OpcionConfirmar == 1)
            {
                do
                {
                    cout << "\n\t\t\tINGRESE A�O ACTUAL: " << endl;
                    cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    if (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024)
                    {
                        cout << "\n\t\t\tINGRESE A�O ACTUAL (2022-2024): " << endl;
                        cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    }
                } while (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024);
                if (el_stock[60].datos_libro.titulo != "VACIO")
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[60].datos_libro.titulo;
                    el_stock[60].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[60].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[60].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[60].datos_libro.codigo;
                    cantidad_mangas_ya_vendidos[1]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                    break;
                }
                else
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[60 + cantidad_mangas_ya_vendidos[1]].datos_libro.titulo;
                    el_stock[60 + cantidad_mangas_ya_vendidos[1]].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[60].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[60].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[60].datos_libro.codigo;
                    cantidad_mangas_ya_vendidos[1]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                }
            }
            else if (OpcionConfirmar == 2)
            {
                mangas(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            }
            break;
        case 3:
            ventas_presencial(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            break;
        default:
            cout << "\n\tOpcion ingresada inavalido " << endl;
            cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
            comic(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            break;
        }
    }
    else if (iteracion == 3)
    {
        switch (opcion)
        {
        case 1:
            if (cantidad_mangas_ya_vendidos[2] == 10)
            {
                cout << endl;
                cout << ROJO << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                mangas(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            }
            cout << endl << "\t\t\tDesea comprar el libro seleccionado? " << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << CELESTE << "\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << "\t\t\tIngrese Opcion a registrar ->"; cin >> OpcionConfirmar;
            if (OpcionConfirmar == 1)
            {
                do
                {
                    cout << "\n\t\t\tINGRESE A�O ACTUAL: " << endl;
                    cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    if (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024)
                    {
                        cout << "\n\t\t\tINGRESE A�O ACTUAL (2022-2024): " << endl;
                        cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    }
                } while (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024);
                if (el_stock[70].datos_libro.titulo != "VACIO")
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[70].datos_libro.titulo;
                    el_stock[70].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[70].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[70].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[70].datos_libro.codigo;
                    cantidad_mangas_ya_vendidos[2]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                    break;
                }
                else
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[70 + cantidad_mangas_ya_vendidos[2]].datos_libro.titulo;
                    el_stock[70 + cantidad_mangas_ya_vendidos[2]].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[70].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[70].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[70].datos_libro.codigo;
                    cantidad_mangas_ya_vendidos[2]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                }
            }
            else if (OpcionConfirmar == 2)
            {
                mangas(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            }
            break;
        case 2:
            if (cantidad_mangas_ya_vendidos[3] == 10)
            {
                cout << endl;
                cout << ROJO << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                mangas(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            }
            cout << endl << "\t\t\tDesea comprar el libro seleccionado? " << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << CELESTE << "\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << "\t\t\tIngrese Opcion a registrar ->"; cin >> OpcionConfirmar;
            if (OpcionConfirmar == 1)
            {
                do
                {
                    cout << "\n\t\t\tINGRESE A�O ACTUAL: " << endl;
                    cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    if (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024)
                    {
                        cout << "\n\t\t\tINGRESE A�O ACTUAL (2022-2024): " << endl;
                        cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    }
                } while (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024);
                if (el_stock[80].datos_libro.titulo != "VACIO")
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[80].datos_libro.titulo;
                    el_stock[80].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[80].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[80].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[80].datos_libro.codigo;
                    cantidad_mangas_ya_vendidos[3]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                    break;
                }
                else
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[80 + cantidad_mangas_ya_vendidos[3]].datos_libro.titulo;
                    el_stock[80 + cantidad_mangas_ya_vendidos[3]].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[80].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[80].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[80].datos_libro.codigo;
                    cantidad_mangas_ya_vendidos[3]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                }
            }
            else if (OpcionConfirmar == 2)
            {
                mangas(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            }
            break;
        case 3:
            if (cantidad_mangas_ya_vendidos[4] == 10)
            {
                cout << endl;
                cout << ROJO << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                mangas(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            }
            cout << endl << "\t\t\tDesea comprar el libro seleccionado? " << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << CELESTE << "\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << "\t\t\tIngrese Opcion a registrar ->"; cin >> OpcionConfirmar;
            if (OpcionConfirmar == 1)
            {
                do
                {
                    cout << "\n\t\t\tINGRESE A�O ACTUAL: " << endl;
                    cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    if (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024)
                    {
                        cout << "\n\t\t\tINGRESE A�O ACTUAL (2022-2024): " << endl;
                        cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    }
                } while (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024);
                if (el_stock[90].datos_libro.titulo != "VACIO")
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[90].datos_libro.titulo;
                    el_stock[90].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[90].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[90].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[90].datos_libro.codigo;
                    cantidad_mangas_ya_vendidos[4]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                    break;
                }
                else
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[90 + cantidad_mangas_ya_vendidos[4]].datos_libro.titulo;
                    el_stock[90 + cantidad_mangas_ya_vendidos[4]].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[90].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[90].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[90].datos_libro.codigo;
                    cantidad_mangas_ya_vendidos[4]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                }
            }
            else if (OpcionConfirmar == 2)
            {
                mangas(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            }

            break;
        case 4:
            ventas_presencial(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            break;
        default:
            cout << "\n\tOpcion ingresada inavalido " << endl;
            cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
            comic(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            break;
        }
    }
}
void comic(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales)
{
    system("cls");
    int opcion;
    cout << "\n\t\t\t Escoja opcion para registrar" << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << VERDE << "\t\t\t\t SEDE: ";
    if (venta_unitaria[0].local == 'S')
    {
        cout << "SAN INSIDRO";
    }
    if (venta_unitaria[0].local == 'M')
    {
        cout << "MIRAFLORES";
    }
    cout << RESET << endl;
    cout << VERDE << "\t\t\t\t MODALIDAD: PRESENCIAL" << RESET << endl;
    cout << VERDE << "\t\t\t\t TIPO DE LIBRO: COMIC" << RESET << endl;
    //Mostramos los libros segun sede y tipo;  
    int iteracion = 0;
    if (cantidad_comics_ya_vendidos[3] == 10)
    {
        el_stock[30].datos_libro.titulo = "AGOTADO";
    }
    if (cantidad_comics_ya_vendidos[4] == 10)
    {
        el_stock[40].datos_libro.titulo = "AGOTADO";
    }
    if (cantidad_comics_ya_vendidos[0] == 10)
    {
        el_stock[0].datos_libro.titulo = "AGOTADO";
    }
    if (cantidad_comics_ya_vendidos[1] == 10)
    {
        el_stock[10].datos_libro.titulo = "AGOTADO";
    }
    if (cantidad_comics_ya_vendidos[2] == 10)
    {
        el_stock[20].datos_libro.titulo = "AGOTADO";
    }
    for (int i = 0; i < 100; i += 10)
    {
        if (el_stock[i].datos_libro.tipo == 'C' && el_stock[i].datos_libro.local_disponiblidad == venta_unitaria[0].local)
        {
            cout << CELESTE << "\t\t\t\t Opcion " << iteracion + 1 << ": ";
            if (el_stock[i].datos_libro.titulo == "AGOTADO")
            {
                cout << ROJO << el_stock[i + 1].datos_libro.titulo << "(AGOTADO)" << RESET << endl;
                iteracion++;
            }
            else
            {
                cout << CELESTE << el_stock[i].datos_libro.titulo << VERDE << setw(3) << "\t (S/. " << el_stock[i].datos_libro.venta << ")" << RESET << endl;
                iteracion++;
            }

        }
    }
    cout << CELESTE << "\t\t\t\t OPCION " << iteracion + 1 << ": VOLVER LA SELECCION DE TIPO DE LIBRO" << RESET << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << "\n";
    do
    {
        cout << "\tIngrese Opcion a registrar -> : "; cin >> opcion;
    } while (opcion < 1 || opcion>iteracion + 1);

    int opcion_confirmar;

    if (iteracion == 2)//Solo 2 comics significa sede san isidro //3 y 4
    {
        switch (opcion)
        {
        case 1:
            if (cantidad_comics_ya_vendidos[3] == 10)
            {
                cout << endl;
                cout << ROJO << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                comic(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            }
            cout << endl << "\t\t\tDesea comprar el libro seleccionado? " << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << CELESTE << "\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << "\t\t\t->";cin >> opcion_confirmar;
            if (opcion_confirmar == 1)
            {
                do
                {
                    cout << "\n\t\t\tINGRESE A�O ACTUAL: " << endl;
                    cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    if (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024)
                    {
                        cout << "\n\t\t\tINGRESE A�O ACTUAL (2022-2024): " << endl;
                        cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    }
                } while (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024);
                if (el_stock[30].datos_libro.titulo != "VACIO")
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[30].datos_libro.titulo;
                    el_stock[0].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[30].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[30].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[30].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[3]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                    break;
                }
                else
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[30 + cantidad_comics_ya_vendidos[3]].datos_libro.titulo;
                    el_stock[30 + cantidad_comics_ya_vendidos[3]].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[30].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[30].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[30].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[3]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                }
            }
            else if (opcion_confirmar == 2)
            {
                comic(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            }
            break;
        case 2:
            if (cantidad_comics_ya_vendidos[4] == 10)
            {
                cout << endl;
                cout << ROJO << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                comic(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            }
            cout << endl << "\t\t\tDesea comprar el libro seleccionado? " << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << CELESTE << "\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << "\t\t\t->";cin >> opcion_confirmar;
            if (opcion_confirmar == 1)
            {
                do
                {
                    cout << "\n\t\t\tINGRESE A�O ACTUAL: " << endl;
                    cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    if (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024)
                    {
                        cout << "\n\t\t\tINGRESE A�O ACTUAL (2022-2024): " << endl;
                        cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    }
                } while (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024);
                if (el_stock[40].datos_libro.titulo != "VACIO")
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[40].datos_libro.titulo;
                    el_stock[40].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[40].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[40].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[40].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[4]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                    break;
                }
                else
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[40 + cantidad_comics_ya_vendidos[4]].datos_libro.titulo;
                    el_stock[40 + cantidad_comics_ya_vendidos[4]].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[40].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[40].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[40].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[4]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                }
            }
            else if (opcion_confirmar == 2)
            {
                comic(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            }
            break;
        case 3:
            ventas_presencial(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            break;
        default:
            cout << "\n\tOpcion ingresada inavalido " << endl;
            cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
            comic(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            break;
        }
    }
    else if (iteracion == 3)  //3 Comics significa sede Miraflores
    {
        switch (opcion)
        {
        case 1:
            if (cantidad_comics_ya_vendidos[0] == 10)
            {
                cout << endl;
                cout << ROJO << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                comic(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            }
            cout << endl << "\t\t\tDesea comprar el libro seleccionado? " << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << CELESTE << "\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << "\t\t\t->";cin >> opcion_confirmar;
            if (opcion_confirmar == 1)
            {
                do
                {
                    cout << "\n\t\t\tINGRESE A�O ACTUAL: " << endl;
                    cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    if (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024)
                    {
                        cout << "\n\t\t\tINGRESE A�O ACTUAL (2022-2024): " << endl;
                        cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    }
                } while (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024);
                if (el_stock[0].datos_libro.titulo != "VACIO")
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[0].datos_libro.titulo;
                    el_stock[0].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[0].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[0].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[0].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[0]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                    break;
                }
                else
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[0 + cantidad_comics_ya_vendidos[0]].datos_libro.titulo;
                    el_stock[0 + cantidad_comics_ya_vendidos[0]].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[0].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[0].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[0].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[0]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                }
            }
            else if (opcion_confirmar == 2)
            {
                comic(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            }
            break;
        case 2:
            if (cantidad_comics_ya_vendidos[1] == 10)
            {
                cout << endl;
                cout << ROJO << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                comic(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            }
            cout << endl << "\t\t\tDesea comprar el libro seleccionado? " << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << CELESTE << "\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << "\t\t\t->";cin >> opcion_confirmar;
            if (opcion_confirmar == 1)
            {
                do
                {
                    cout << "\n\t\t\tINGRESE A�O ACTUAL: " << endl;
                    cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    if (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024)
                    {
                        cout << "\n\t\t\tINGRESE A�O ACTUAL (2022-2024): " << endl;
                        cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    }
                } while (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024);
                if (el_stock[10].datos_libro.titulo != "VACIO")
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[10].datos_libro.titulo;
                    el_stock[10].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[10].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[10].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[10].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[1]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                    break;
                }
                else
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[10 + cantidad_comics_ya_vendidos[1]].datos_libro.titulo;
                    el_stock[10 + cantidad_comics_ya_vendidos[1]].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[10].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[10].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[10].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[1]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                }
            }
            else if (opcion_confirmar == 2)
            {
                comic(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            }
            break;
        case 3:
            if (cantidad_comics_ya_vendidos[2] == 10)
            {
                cout << endl;
                cout << ROJO << "\t\t\tLIBRO AGOTADO POR FAVOR ELIJA OTRO LIBRO" << RESET << endl;
                comic(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            }
            cout << endl << "\t\t\tDesea comprar el libro seleccionado? " << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << CELESTE << "\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t\t-----------------------------------" << endl;
            cout << "\t\t\t->";cin >> opcion_confirmar;
            if (opcion_confirmar == 1)
            {
                do
                {
                    cout << "\n\t\t\tINGRESE A�O ACTUAL: " << endl;
                    cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    if (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024)
                    {
                        cout << "\n\t\t\tINGRESE A�O ACTUAL (2022-2024): " << endl;
                        cout << "\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
                    }
                } while (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024);
                if (el_stock[20].datos_libro.titulo != "VACIO")
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[20].datos_libro.titulo;
                    el_stock[20].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[20].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[20].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[20].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[2]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                    break;
                }
                else
                {
                    venta_unitaria[0].datos_libro.titulo = el_stock[20 + cantidad_comics_ya_vendidos[2]].datos_libro.titulo;
                    el_stock[20 + cantidad_comics_ya_vendidos[2]].datos_libro.titulo = "VACIO";
                    venta_unitaria[0].datos_libro.venta = el_stock[20].datos_libro.venta;
                    venta_unitaria[0].datos_libro.costo = el_stock[20].datos_libro.costo;
                    venta_unitaria[0].datos_libro.codigo = el_stock[20].datos_libro.codigo;
                    cantidad_comics_ya_vendidos[2]++;
                    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                }
            }
            else if (opcion_confirmar == 2)
            {
                comic(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            }
            break;
        case 4:
            ventas_presencial(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            break;
        default:
            cout << "\n\tOpcion ingresada inavalido " << endl;
            cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
            comic(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            break;
        }
    }

}
void ventas_whatsapp(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales)
{
    system("cls");
    int opcion;
    cout << "\n\t\t\t Escoja opcion para registrar" << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << VERDE << "\t\t\t\t SEDE: ";
    if (venta_unitaria[0].local == 'S')
    {
        cout << "SAN INSIDRO";
    }
    if (venta_unitaria[0].local == 'M')
    {
        cout << "MIRAFLORES";
    }
    cout << RESET << endl;
    cout << VERDE << "\t\t\t\t MODALIDAD: WHATSAPP" << RESET << endl;
    cout << CELESTE "\t\t\t Opcion 1: RECOJO EN TIENDA" << endl;
    cout << "\t\t\t Opcion 2: ENTREGA A DOMICILIO" << endl;
    cout << "\t\t\t Opcion 3: VOLVER A SELECCI�N DE MODALIDADES" << RESET << endl;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << "\n";
    do
    {
        cout << "\tIngrese Opcion a registrar -> : "; cin >> opcion;
    } while (opcion < 1 || opcion>3);
    switch (opcion)
    {
    case 1:
        venta_unitaria[0].modalidad.recojo = 'T';
        recojo_en_tienda(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;
    case 2:
        venta_unitaria[0].modalidad.recojo = 'D';
        delivery(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;
    case 3:
        if (venta_unitaria[0].local == 'M')
        {
            ventas_miraflores(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        }
        else if (venta_unitaria[0].local == 'S')
        {
            ventas_san_isidro(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        }
        break;
    default:
        cout << "\n\tOpcion ingresada inavalido " << endl;
        cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
        ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;
    }
}
void recojo_en_tienda(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales)
{
    system("cls");
    int opcion;
    srand(time(NULL));
    cout << "\t\t\t-----------------------------------" << endl;
    cout << VERDE << "\t\t\t\t SEDE EN DONDE SE RECOJERA EL LIBRO: ";
    if (venta_unitaria[0].local == 'S')
    {
        cout << "SAN INSIDRO";
    }
    if (venta_unitaria[0].local == 'M')
    {
        cout << "MIRAFLORES";
    }
    cout << endl;
    cout << VERDE << "\t\t\t\t MODALIDAD: WHATSAPP" << RESET << endl;

    do
    {
        cout << "\t\t\tINGRESE CODIGO DEL LIBRO \n\t\t\t\t4 DIGITOS\n\t\t\tFORMATO DE CODIGO POR LIBRERIA Y TIPO: " << RESET << endl;
        cout << AZUL << " \t\t\t| Miraflores   |    |  San Isidro  | " << endl;
        cout << " \t\t\t| Comic | Manga|    |Comic | Manga |" << endl;
        cout << " \t\t\t| 11XX  | 12XX |    | 21XX | 22XX  |" << RESET << endl;
        cout << "\t\t\t->"; cin >> venta_unitaria[0].datos_libro.codigo;
    } while ((venta_unitaria[0].datos_libro.codigo < 1100 || venta_unitaria[0].datos_libro.codigo>1299) && (venta_unitaria[0].datos_libro.codigo < 2100 || venta_unitaria[0].datos_libro.codigo>2299));
    if ((venta_unitaria[0].datos_libro.codigo > 1100 && venta_unitaria[0].datos_libro.codigo < 1300) && venta_unitaria[0].local == 'S')
    {
        cout << ROJO << "LOS RECOJOS EN TIENDA DE LOS LIBROS DE MIRAFLORES DEBEN DE HACERSE EN EL APARTADO DE 'MIRAFLORES'" << RESET << endl;
        opcion_menu(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
    }
    if ((venta_unitaria[0].datos_libro.codigo >= 2100 && venta_unitaria[0].datos_libro.codigo < 2300) && venta_unitaria[0].local == 'M')
    {
        cout << ROJO << "LOS RECOJOS EN TIENDA DE LOS LIBROS DE SAN ISIDRO DEBEN DE HACERSE EN EL APARTADO DE 'SAN ISIDRO'" << RESET << endl;
        opcion_menu(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
    }
    if (venta_unitaria[0].datos_libro.codigo >= 1100 && venta_unitaria[0].datos_libro.codigo < 1200)
    {
        int n = 0 + rand() % (2);
        cantidad_mangas_ya_vendidos[n]++;
        switch (n)
        {
        case 0:
            cout << CELESTE << "\t\t\tLIBRO A RECOJER: " << RESET << AZUL << "My Hero Academy 01" << endl;
            cout << "\t\t\tPRECIO DEL LIBRO: " << VERDE << "S/." << el_stock[50].datos_libro.venta << RESET << endl;
            cout << "\t\t\tDESEA RECOJER EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t============================================" << endl;
            do
            {
                cout << "\tIngrese Opcion a registrar -> : "; cin >> opcion;
            } while (opcion < 1 || opcion>2);
            switch (opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "My Hero Academy 01";
                venta_unitaria[0].datos_libro.venta = el_stock[50].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[50].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'M';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        case 1:
            cout << CELESTE << "\t\t\tLIBRO A RECOJER: " << RESET << AZUL << "Dragon Ball Super 03" << RESET << endl;
            cout << CELESTE << "\t\t\tPRECIO DEL LIBRO: " << RESET << VERDE << "S/." << el_stock[60].datos_libro.venta << RESET << endl;
            cout << "\t\t\tDESEA RECOJER EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << RESET << endl;
            cout << CELESTE << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t============================================" << endl;
            do
            {
                cout << "\tIngrese Opcion a registrar -> : "; cin >> opcion;
            } while (opcion < 1 || opcion>2);
            switch (opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "Dragon Ball Super 03";
                venta_unitaria[0].datos_libro.venta = el_stock[60].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[60].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'M';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    else if (venta_unitaria[0].datos_libro.codigo >= 1200 && venta_unitaria[0].datos_libro.codigo < 1300)
    {
        int n = 0 + rand() % (3);
        cantidad_comics_ya_vendidos[n]++;
        switch (n)
        {
        case 0:
            cout << CELESTE << "\t\t\tLIBRO A RECOJER: " << RESET << AZUL << "Marvel Tony Stark. Iron Man 01" << endl;
            cout << "\t\t\tPRECIO DEL LIBRO: " << VERDE << "S/." << el_stock[0].datos_libro.venta << RESET << endl;
            cout << "\t\t\tDESEA RECOJER EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t============================================" << endl;
            do
            {
                cout << "\tIngrese Opcion a registrar -> : "; cin >> opcion;
            } while (opcion < 1 || opcion>2);
            switch (opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "Marvel Tony Stark. Iron Man 01";
                venta_unitaria[0].datos_libro.venta = el_stock[0].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[0].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'C';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        case 1:
            cout << CELESTE << "\t\t\tLIBRO A RECOJER: " << RESET << AZUL << "Marvel Thor. Vikingos" << endl;
            cout << "\t\t\tPRECIO DEL LIBRO: " << VERDE << "S/." << el_stock[10].datos_libro.venta << RESET << endl;
            cout << "\t\t\tDESEA RECOJER EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t============================================" << endl;
            do
            {
                cout << "\tIngrese Opcion a registrar -> : "; cin >> opcion;
            } while (opcion < 1 || opcion>2);
            switch (opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "Marvel Thor. Vikingos";
                venta_unitaria[0].datos_libro.venta = el_stock[10].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[10].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'C';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        case 2:
            cout << CELESTE << "\t\t\tLIBRO A RECOJER: " << RESET << AZUL << "Marvel Thanos. Poderes Cosmicos" << endl;
            cout << "\t\t\tPRECIO DEL LIBRO: " << VERDE << "S/." << el_stock[20].datos_libro.venta << RESET << endl;
            cout << "\t\t\tDESEA RECOJER EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t============================================" << endl;
            do
            {
                cout << "\tIngrese Opcion a registrar -> : "; cin >> opcion;
            } while (opcion < 1 || opcion>2);
            switch (opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "Marvel Thanos. Poderes Cosmicos";
                venta_unitaria[0].datos_libro.venta = el_stock[20].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[20].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'C';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    else if (venta_unitaria[0].datos_libro.codigo >= 2100 && venta_unitaria[0].datos_libro.codigo < 2200)
    {
        int n = 2 + rand() % (3);
        cantidad_mangas_ya_vendidos[n]++;
        switch (n)
        {
        case 2:
            cout << CELESTE << "\t\t\tLIBRO A RECOJER: " << RESET << AZUL << "Jojo's Bizarre Adventure: Part 1" << endl;
            cout << "\t\t\tPRECIO DEL LIBRO: " << VERDE << "S/." << el_stock[70].datos_libro.venta << RESET << endl;
            cout << "\t\t\tDESEA RECOJER EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t============================================" << endl;
            do
            {
                cout << "\tIngrese Opcion a registrar -> : "; cin >> opcion;
            } while (opcion < 1 || opcion>2);
            switch (opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "Jojo's Bizarre Adventure: Part 1";
                venta_unitaria[0].datos_libro.venta = el_stock[70].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[70].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'M';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        case 3:
            cout << CELESTE << "\t\t\tLIBRO A RECOJER: " << RESET << AZUL << "Death Note 01" << endl;
            cout << "\t\t\tPRECIO DEL LIBRO: " << VERDE << "S/." << el_stock[80].datos_libro.venta << RESET << endl;
            cout << "\t\t\tDESEA RECOJER EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t============================================" << endl;
            do
            {
                cout << "\tIngrese Opcion a registrar -> : "; cin >> opcion;
            } while (opcion < 1 || opcion>2);
            switch (opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "Death Note 01";
                venta_unitaria[0].datos_libro.venta = el_stock[80].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[80].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'M';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        case 4:
            cout << CELESTE << "\t\t\tLIBRO A RECOJER: " << RESET << AZUL << "Chainsaw Man 01" << endl;
            cout << "\t\t\tPRECIO DEL LIBRO: " << VERDE << "S/." << el_stock[90].datos_libro.venta << RESET;
            cout << "\t\t\tDESEA RECOJER EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t============================================" << endl;
            do
            {
                cout << "\tIngrese Opcion a registrar -> : "; cin >> opcion;
            } while (opcion < 1 || opcion>2);
            switch (opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "Chainsaw Man 01";
                venta_unitaria[0].datos_libro.venta = el_stock[90].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[90].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'M';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    else if (venta_unitaria[0].datos_libro.codigo >= 2200 && venta_unitaria[0].datos_libro.codigo < 2300)
    {
        int n = 3 + rand() % (2);
        cantidad_comics_ya_vendidos[n]++;
        switch (n)
        {
        case 3:
            cout << CELESTE << "\t\t\tLIBRO A RECOJER: " << RESET << AZUL << "Marvel Ultimate Spiderman 2" << endl;
            cout << "\t\t\tPRECIO DEL LIBRO: " << VERDE << "S/." << el_stock[30].datos_libro.venta << RESET << endl;

            cout << "\t\t\tDESEA RECOJER EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t============================================" << endl;
            do
            {
                cout << "\tIngrese Opcion a registrar -> : "; cin >> opcion;
            } while (opcion < 1 || opcion>2);
            switch (opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "Marvel Ultimate Spiderman 2";
                venta_unitaria[0].datos_libro.venta = el_stock[30].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[30].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'C';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        case 4:
            cout << CELESTE << "\t\t\tLIBRO A RECOJER: " << RESET << AZUL << "Marvel Secret War" << endl;
            cout << "\t\t\tPRECIO DEL LIBRO: " << VERDE << "S/." << el_stock[40].datos_libro.venta << RESET << endl;
            cout << "\t\t\tDESEA RECOJER EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << endl;
            cout << "\t\t============================================" << endl;
            do
            {
                cout << "\tIngrese Opcion a registrar -> : "; cin >> opcion;
            } while (opcion < 1 || opcion>2);
            switch (opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "Marvel Secret War";
                venta_unitaria[0].datos_libro.venta = el_stock[40].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[40].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'C';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    do
    {
        cout << "\t\t\tINGRESE EL A�O: \n\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
        if (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024)
        {
            cout << "\t\t\tINGRESE EL A�O (2022-2024): "; cin >> venta_unitaria[0].fecha.a�o;
        }
    } while (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024);
    do
    {
        cout << "\t\t\tINGRESE EL MES: \n\t\t\t->"; cin >> venta_unitaria[0].fecha.mes;
        if (venta_unitaria[0].fecha.mes < 1 || venta_unitaria[0].fecha.mes>12)
        {
            cout << "\t\t\tINGRESE EL MES (1-12): "; cin >> venta_unitaria[0].fecha.mes;
        }
    } while (venta_unitaria[0].fecha.mes < 1 || venta_unitaria[0].fecha.mes>12);
    if (venta_unitaria[0].fecha.mes == 1 || venta_unitaria[0].fecha.mes == 3 || venta_unitaria[0].fecha.mes == 5 || venta_unitaria[0].fecha.mes == 7 || venta_unitaria[0].fecha.mes == 8 || venta_unitaria[0].fecha.mes == 10 || venta_unitaria[0].fecha.mes == 12)
    {
        do
        {
            cout << "\t\t\tINGRESE EL DIA: \n\t\t\t->"; cin >> venta_unitaria[0].fecha.dia;
            if (venta_unitaria[0].fecha.dia < 1 || venta_unitaria[0].fecha.dia>31)
            {
                cout << "\t\t\tINGRESE EL DIA (1-31): "; cin >> venta_unitaria[0].fecha.dia;
            }
        } while (venta_unitaria[0].fecha.dia < 1 || venta_unitaria[0].fecha.dia>31);
    }
    else if (venta_unitaria[0].fecha.mes == 4 || venta_unitaria[0].fecha.mes == 6 || venta_unitaria[0].fecha.mes == 9 || venta_unitaria[0].fecha.mes == 11)
    {
        do
        {
            cout << "\t\t\tINGRESE EL DIA: \n\t\t\t->"; cin >> venta_unitaria[0].fecha.dia;
            if (venta_unitaria[0].fecha.dia < 1 || venta_unitaria[0].fecha.dia>30)
            {
                cout << "\t\t\tINGRESE EL DIA (1-30): "; cin >> venta_unitaria[0].fecha.dia;
            }
        } while (venta_unitaria[0].fecha.dia < 1 || venta_unitaria[0].fecha.dia>30);
    }
    else if (venta_unitaria[0].fecha.mes == 2 && venta_unitaria[0].fecha.a�o == 2024)
    {
        do
        {
            cout << "\t\t\tINGRESE EL DIA: \n\t\t\t->"; cin >> venta_unitaria[0].fecha.dia;
            if (venta_unitaria[0].fecha.dia < 1 || venta_unitaria[0].fecha.dia>29)
            {
                cout << "\t\t\tINGRESE EL DIA (1-29): "; cin >> venta_unitaria[0].fecha.dia;
            }
        } while (venta_unitaria[0].fecha.dia < 1 || venta_unitaria[0].fecha.dia>29);
    }
    else if (venta_unitaria[0].fecha.mes == 2 && venta_unitaria[0].fecha.a�o != 2024)
    {
        do
        {
            cout << "\t\t\tINGRESE EL DIA: \n\t\t\t->"; cin >> venta_unitaria[0].fecha.dia;
            if (venta_unitaria[0].fecha.dia < 1 || venta_unitaria[0].fecha.dia>28)
            {
                cout << "\t\t\tINGRESE EL DIA (1-28): "; cin >> venta_unitaria[0].fecha.dia;
            }
        } while (venta_unitaria[0].fecha.dia < 1 || venta_unitaria[0].fecha.dia>28);
    }
    cout << "\t\t\tINGRESE METODO DE PAGO: " << endl;
    cout << "\t\t============================================" << endl;
    cout << "\t\t\t OPCION 1: YAPE" << endl;
    cout << "\t\t\t OPCION 2: EFECTIVO" << endl;
    cout << "\t\t\t OPCION 3: DEBITO" << endl;
    cout << "\t\t\t OPCION 4: CREDITO" << endl;
    cout << "\t\t============================================" << endl;
    do
    {
        cout << "\tIngrese Opcion a registrar -> : "; cin >> opcion;
    } while (opcion < 1 || opcion>4);
    string nombre_y_apellido;
    int mes_vencimiento;
    int a�o_vencimiento;
    string numero_tarjeta;
    string e;
    switch (opcion)
    {
    case 1:
        venta_unitaria[0].metodo_pago = "YAPE";
        cout << AZUL << "\t\t\tNUMERO PARA YAPEAR: 921 030 367" << endl;
        cout << "\n\t\t\tPRESIONE [1] SI YA YAPEO AL NUMERO INDICADO." << RESET << endl;
        do
        {
            while (e != "1")
            {
                cout << "\t\t\t->"; cin >> e;
            }
            validar(e);
        } while (validar(e) == 0);
        break;
    case 2:
        int monto_para_pagar;
        venta_unitaria[0].metodo_pago = "EFECTIVO";
        cout << "\t\t\tINGRESE MONTO PARA PAGAR:" << VERDE << "(S / ." << venta_unitaria[0].datos_libro.venta << ")" << RESET << endl;
        cout << "\t\t\t->";
        while (monto_para_pagar < venta_unitaria[0].datos_libro.venta);
        {
            cin >> monto_para_pagar;
            if (monto_para_pagar < venta_unitaria[0].datos_libro.venta)
            {
                cout << "\t\t\tMONTO INSUFICIENTE" << endl;
                cout << "\t\t\t->"; cin >> monto_para_pagar;
            }
        }
        break;
    case 3:
        cout << endl;
        venta_unitaria[0].metodo_pago = "DEBITO";
        cout << "\t\t\tINGRESE NOMBRE Y APELLIDO DEL TITULAR DE LA TARJETA" << endl;
        cin.ignore();
        do
        {
            cout << "\t\t\t->"; getline(cin, nombre_y_apellido);
            validar(nombre_y_apellido);
            if (validar(nombre_y_apellido) == 0)
            {
                cout << ROJO << "\t\tINGRESE SOLO LETRAS" << RESET << endl;
            }
        } while (validar(nombre_y_apellido) == 0);

        do
        {
            cout << "\t\t\tINGRESE MES DE VENCIMIENTO:" << endl;
            cout << "\t\t\t->"; cin >> mes_vencimiento;
            if (mes_vencimiento < 0 || mes_vencimiento>12)
            {
                cout << AZUL << "\t\t\tINGRESE MES DE VENCIMIENTO VALIDO:" << endl;
                cout << "\t\t\t->" << RESET; cin >> mes_vencimiento;
            }
        } while (mes_vencimiento < 0 || mes_vencimiento>12);
        do
        {
            cout << "\t\t\tINGRESE A�O DE VENCIMIENTO:" << endl;
            cout << "\t\t\t->"; cin >> a�o_vencimiento;
        } while (a�o_vencimiento < 2024);
        do
        {
            cout << "\t\t\tINGRESE NUMERO DE LA TARJETA" << endl;
            cout << "\t\t\t->"; cin >> numero_tarjeta;
        } while (numero_tarjeta.length() != 16);
        break;
    case 4:
        venta_unitaria[0].metodo_pago = "CREDITO";
        cout << "\n\t\t\tINGRESE NOMBRE Y APELLIDO DEL TITULAR DE LA TARJETA" << endl;
        cin.ignore();
        do
        {
            cout << "\t\t\t->"; getline(cin, nombre_y_apellido);
            validar(nombre_y_apellido);
            if (validar(nombre_y_apellido) == 0)
            {
                cout << ROJO << "\t\tINGRESE SOLO LETRAS" << RESET << endl;
            }
        } while (validar(nombre_y_apellido) == 0);

        do
        {
            cout << "\t\t\tINGRESE MES DE VENCIMIENTO:" << endl;
            cout << "\t\t\t->"; cin >> mes_vencimiento;
            if (mes_vencimiento < 0 || mes_vencimiento>12)
            {
                cout << AZUL << "\t\t\tINGRESE MES DE VENCIMIENTO VALIDO:" << endl;
                cout << "\t\t\t->" << RESET; cin >> mes_vencimiento;
            }
        } while (mes_vencimiento < 0 || mes_vencimiento>12);
        do
        {
            cout << "\t\t\tINGRESE A�O DE VENCIMIENTO:" << endl;
            cout << "\t\t\t->"; cin >> a�o_vencimiento;
        } while (a�o_vencimiento < 2024);
        do
        {
            cout << "\t\t\tINGRESE NUMERO DE LA TARJETA" << endl;
            cout << "\t\t\t->"; cin >> numero_tarjeta;
        } while (numero_tarjeta.length() != 16);
        break;
    default:
        break;
    }
    cout << "\t\t\tPAGO RECIBIDO";
    registrar_ventas_y_usuarios(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
}
void delivery(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales)
{
    system("cls");
    int Opcion;
    cout << "\t\t\t-----------------------------------" << endl;
    cout << VERDE << "\t\t\t\t SEDE ORIGEN DEL LIBRO: ";
    if (venta_unitaria[0].local == 'S')
    {
        cout << "SAN INSIDRO";
    }
    if (venta_unitaria[0].local == 'M')
    {
        cout << "MIRAFLORES";
    }
    cout << endl;
    cout << VERDE << "\t\t\t\t MODALIDAD: WHATSAPP" << RESET << endl;
    cout << "\t\t\tINGRESE SU DIRECCION: " << endl;
    cin.ignore();
    cout << "\t\t\t->"; getline(cin, venta_unitaria[0].datos_usuario.direccion);
    do
    {
        cout << "\t\t\tINGRESE CODIGO DEL LIBRO \n\t\t\tCOMPUESTO POR 4 DIGITOS\n\t\t\tFORMATO DE CODIGO POR LIBRERIA Y TIPO: " << RESET << endl;
        cout << AZUL << " \t\t\t| Miraflores   |    |  San Isidro  | " << endl;
        cout << " \t\t\t| Comic | Manga|    |Comic | Manga |" << endl;
        cout << " \t\t\t| 11XX  | 12XX |    | 21XX | 22XX  |" << RESET << endl;
        cout << "\t\t\t->"; cin >> venta_unitaria[0].datos_libro.codigo;
    } while ((venta_unitaria[0].datos_libro.codigo < 1100 || venta_unitaria[0].datos_libro.codigo>1299) && (venta_unitaria[0].datos_libro.codigo < 2100 || venta_unitaria[0].datos_libro.codigo>2299));
    if ((venta_unitaria[0].datos_libro.codigo > 1100 && venta_unitaria[0].datos_libro.codigo < 1300) && venta_unitaria[0].local == 'S')
    {
        cout << ROJO << "LOS RDELIVERYS DE LOS LIBROS DE MIRAFLORES DEBEN DE HACERSE EN EL APARTADO DE 'MIRAFLORES'" << RESET << endl;
        opcion_menu(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
    }
    if ((venta_unitaria[0].datos_libro.codigo >= 2100 && venta_unitaria[0].datos_libro.codigo < 2300) && venta_unitaria[0].local == 'M')
    {
        cout << ROJO << "LOS DELIVERYS DE LOS LIBROS DE SAN ISIDRO DEBEN DE HACERSE EN EL APARTADO DE 'SAN ISIDRO'" << RESET << endl;
        opcion_menu(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
    }
    if (venta_unitaria[0].datos_libro.codigo >= 1100 && venta_unitaria[0].datos_libro.codigo < 1200)
    {
        int n = 0 + rand() % (2);
        cantidad_mangas_ya_vendidos[n]++;
        switch (n)
        {
        case 0:
            cout << CELESTE << "\t\t\tLIBRO A ENTREGAR: " << RESET << AZUL << "My Hero Academy 01" << endl;
            cout << "\t\t\tPRECIO DEL LIBRO: " << VERDE << "S/." << el_stock[50].datos_libro.venta << RESET << endl;
            cout << "\t\t\tDESEA QUE LE LLEVEMOS EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t============================================" << endl;
            cout << "\t\t\t->"; cin >> Opcion;
            switch (Opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "My Hero Academy 01";
                venta_unitaria[0].datos_libro.venta = el_stock[50].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[50].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'M';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        case 1:
            cout << CELESTE << "\t\t\tLIBRO A ENTREGAR: " << RESET << AZUL << "Dragon Ball Super 03" << RESET << endl;
            cout << CELESTE << "\t\t\tPRECIO DEL LIBRO: " << RESET << VERDE << "S/." << el_stock[60].datos_libro.venta << RESET << endl;
            cout << "\t\t\tDESEA QUE LE LLEVEMOS EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << RESET << endl;
            cout << CELESTE << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t============================================" << endl;
            cout << "\t\t\t->"; cin >> Opcion;
            switch (Opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "Dragon Ball Super 03";
                venta_unitaria[0].datos_libro.venta = el_stock[60].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[60].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'M';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    else if (venta_unitaria[0].datos_libro.codigo >= 1200 && venta_unitaria[0].datos_libro.codigo < 1300)
    {
        int n = 0 + rand() % (3);
        cantidad_comics_ya_vendidos[n]++;
        switch (n)
        {
        case 0:
            cout << CELESTE << "\t\t\tLIBRO A ENTREGAR: " << RESET << AZUL << "Marvel Tony Stark. Iron Man 01" << endl;
            cout << "\t\t\tPRECIO DEL LIBRO: " << VERDE << "S/." << el_stock[0].datos_libro.venta << RESET << endl;
            cout << "\t\t\tDESEA QUE LE LLEVEMOS EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t============================================" << endl;
            cout << "\t\t\t->"; cin >> Opcion;
            switch (Opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "Marvel Tony Stark. Iron Man 01";
                venta_unitaria[0].datos_libro.venta = el_stock[0].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[0].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'C';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        case 1:
            cout << CELESTE << "\t\t\tLIBRO A ENTREGAR: " << RESET << AZUL << "Marvel Thor. Vikingos" << endl;
            cout << "\t\t\tPRECIO DEL LIBRO: " << VERDE << "S/." << el_stock[10].datos_libro.venta << RESET << endl;
            cout << "\t\t\tDESEA QUE LE LLEVEMOS EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t============================================" << endl;
            cout << "\t\t\t->"; cin >> Opcion;
            switch (Opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "Marvel Thor. Vikingos";
                venta_unitaria[0].datos_libro.venta = el_stock[10].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[10].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'C';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        case 2:
            cout << CELESTE << "\t\t\tLIBRO A ENTREGAR: " << RESET << AZUL << "Marvel Thanos. Poderes Cosmicos" << endl;
            cout << "\t\t\tPRECIO DEL LIBRO: " << VERDE << "S/." << el_stock[20].datos_libro.venta << RESET << endl;
            cout << "\t\t\tDESEA QUE LE LLEVEMOS EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t============================================" << endl;
            cout << "\t\t\t->"; cin >> Opcion;
            switch (Opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "Marvel Thanos. Poderes Cosmicos";
                venta_unitaria[0].datos_libro.venta = el_stock[20].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[20].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'C';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    else if (venta_unitaria[0].datos_libro.codigo >= 2100 && venta_unitaria[0].datos_libro.codigo < 2200)
    {
        int n = 2 + rand() % (3);
        cantidad_mangas_ya_vendidos[n]++;
        switch (n)
        {
        case 2:
            cout << CELESTE << "\t\t\tLIBRO A ENTREGAR: " << RESET << AZUL << "Jojo's Bizarre Adventure: Part 1" << endl;
            cout << "\t\t\tPRECIO DEL LIBRO: " << VERDE << "S/." << el_stock[70].datos_libro.venta << RESET << endl;
            cout << "\t\t\tDESEA RECOJER EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t============================================" << endl;
            cout << "\t\t\t->"; cin >> Opcion;
            switch (Opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "Jojo's Bizarre Adventure: Part 1";
                venta_unitaria[0].datos_libro.venta = el_stock[70].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[70].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'M';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        case 3:
            cout << CELESTE << "\t\t\tLIBRO A ENTREGAR: " << RESET << AZUL << "Death Note 01" << endl;
            cout << "\t\t\tPRECIO DEL LIBRO: " << VERDE << "S/." << el_stock[80].datos_libro.venta << RESET << endl;
            cout << "\t\t\tDESEA RECOJER EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t============================================" << endl;
            cout << "\t\t\t->"; cin >> Opcion;
            switch (Opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "Death Note 01";
                venta_unitaria[0].datos_libro.venta = el_stock[80].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[80].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'M';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        case 4:
            cout << CELESTE << "\t\t\tLIBRO A ENTREGAR: " << RESET << AZUL << "Chainsaw Man 01" << endl;
            cout << "\t\t\tPRECIO DEL LIBRO: " << VERDE << "S/." << el_stock[90].datos_libro.venta << RESET;
            cout << "\t\t\tDESEA RECOJER EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t============================================" << endl;
            cout << "\t\t\t->"; cin >> Opcion;
            switch (Opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "Chainsaw Man 01";
                venta_unitaria[0].datos_libro.venta = el_stock[90].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[90].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'M';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    else if (venta_unitaria[0].datos_libro.codigo >= 2200 && venta_unitaria[0].datos_libro.codigo < 2300)
    {
        int n = 3 + rand() % (2);
        cantidad_comics_ya_vendidos[n]++;
        switch (n)
        {
        case 3:
            cout << CELESTE << "\t\t\tLIBRO A ENTREGAR: " << RESET << AZUL << "Marvel Ultimate Spiderman 2" << endl;
            cout << "\t\t\tPRECIO DEL LIBRO: " << VERDE << "S/." << el_stock[30].datos_libro.venta << RESET << endl;

            cout << "\t\t\tDESEA RECOJER EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << RESET << endl;
            cout << "\t\t============================================" << endl;
            cout << "\t\t\t->"; cin >> Opcion;
            switch (Opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "Marvel Ultimate Spiderman 2";
                venta_unitaria[0].datos_libro.venta = el_stock[30].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[30].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'C';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        case 4:
            cout << CELESTE << "\t\t\tLIBRO A ENTREGAR: " << RESET << AZUL << "Marvel Secret War" << endl;
            cout << "\t\t\tPRECIO DEL LIBRO: " << VERDE << "S/." << el_stock[40].datos_libro.venta << RESET << endl;
            cout << "\t\t\tDESEA QUE LE LLEVEMOS EL LIBRO SELECCIONADO?" << endl;
            cout << "\t\t============================================" << endl;
            cout << CELESTE"\t\t\tOPCION 1: SI" << endl;
            cout << "\t\t\tOPCION 2: NO" << endl;
            cout << "\t\t============================================" << endl;
            cout << "\t\t\t->"; cin >> Opcion;
            switch (Opcion)
            {
            case 1:
                venta_unitaria[0].datos_libro.titulo = "Marvel Secret War";
                venta_unitaria[0].datos_libro.venta = el_stock[40].datos_libro.venta;
                venta_unitaria[0].datos_libro.costo = el_stock[40].datos_libro.costo;
                venta_unitaria[0].datos_libro.tipo = 'C';
                break;
            case 2:
                ventas_whatsapp(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    do
    {
        cout << "\t\t\tINGRESE EL A�O: \n\t\t\t->"; cin >> venta_unitaria[0].fecha.a�o;
        if (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024)
        {
            cout << "\t\t\tINGRESE EL A�O (2022-2024): "; cin >> venta_unitaria[0].fecha.a�o;
        }
    } while (venta_unitaria[0].fecha.a�o < 2022 || venta_unitaria[0].fecha.a�o>2024);
    do
    {
        cout << "\t\t\tINGRESE EL MES: \n\t\t\t->"; cin >> venta_unitaria[0].fecha.mes;
        if (venta_unitaria[0].fecha.mes < 1 || venta_unitaria[0].fecha.mes>12)
        {
            cout << "\t\t\tINGRESE EL MES (1-12): "; cin >> venta_unitaria[0].fecha.mes;
        }
    } while (venta_unitaria[0].fecha.mes < 1 || venta_unitaria[0].fecha.mes>12);
    if (venta_unitaria[0].fecha.mes == 1 || venta_unitaria[0].fecha.mes == 3 || venta_unitaria[0].fecha.mes == 5 || venta_unitaria[0].fecha.mes == 7 || venta_unitaria[0].fecha.mes == 8 || venta_unitaria[0].fecha.mes == 10 || venta_unitaria[0].fecha.mes == 12)
    {
        do
        {
            cout << "\t\t\tINGRESE EL DIA: \n\t\t\t->"; cin >> venta_unitaria[0].fecha.dia;
            if (venta_unitaria[0].fecha.dia < 1 || venta_unitaria[0].fecha.dia>31)
            {
                cout << "\t\t\tINGRESE EL MES (1-31): "; cin >> venta_unitaria[0].fecha.dia;
            }
        } while (venta_unitaria[0].fecha.dia < 1 || venta_unitaria[0].fecha.dia>31);
    }
    else if (venta_unitaria[0].fecha.mes == 4 || venta_unitaria[0].fecha.mes == 6 || venta_unitaria[0].fecha.mes == 9 || venta_unitaria[0].fecha.mes == 11)
    {
        do
        {
            cout << "\t\t\tINGRESE EL DIA: \n\t\t\t->"; cin >> venta_unitaria[0].fecha.dia;
            if (venta_unitaria[0].fecha.dia < 1 || venta_unitaria[0].fecha.dia>30)
            {
                cout << "\t\t\tINGRESE EL DIA(1-30): "; cin >> venta_unitaria[0].fecha.dia;
            }
        } while (venta_unitaria[0].fecha.dia < 1 || venta_unitaria[0].fecha.dia>30);
    }
    else if (venta_unitaria[0].fecha.mes == 2 && venta_unitaria[0].fecha.a�o == 2024)
    {
        do
        {
            cout << "\t\t\tINGRESE EL DIA: \n\t\t\t->"; cin >> venta_unitaria[0].fecha.dia;
            if (venta_unitaria[0].fecha.dia < 1 || venta_unitaria[0].fecha.dia>29)
            {
                cout << "\t\t\tINGRESE EL DIA (1-29): "; cin >> venta_unitaria[0].fecha.dia;
            }
        } while (venta_unitaria[0].fecha.dia < 1 || venta_unitaria[0].fecha.dia>29);
    }
    else if (venta_unitaria[0].fecha.mes == 2 && venta_unitaria[0].fecha.a�o != 2024)
    {
        do
        {
            cout << "\t\t\tINGRESE EL DIA: \n\t\t\t->"; cin >> venta_unitaria[0].fecha.dia;
            if (venta_unitaria[0].fecha.dia < 1 || venta_unitaria[0].fecha.dia>28)
            {
                cout << "\t\t\tINGRESE EL DIA (1-28): "; cin >> venta_unitaria[0].fecha.dia;
            }
        } while (venta_unitaria[0].fecha.dia < 1 || venta_unitaria[0].fecha.dia>28);
    }
    cout << "\t\t\tINGRESE METODO DE PAGO: " << endl;
    cout << "\t\t============================================" << endl;
    cout << "\t\t\t OPCION 1: YAPE" << endl;
    cout << "\t\t\t OPCION 2: EFECTIVO" << endl;
    cout << "\t\t\t OPCION 3: DEBITO" << endl;
    cout << "\t\t\t OPCION 4: CREDITO" << endl;
    cout << "\t\t============================================" << endl;
    cout << "\t\t\t->INGRESE OPCION A REGISTRAR: "; cin >> Opcion;
    string nombre_y_apellido;
    int mes_vencimiento;
    int a�o_vencimiento;
    string numero_tarjeta;
    string e;
    switch (Opcion)
    {
    case 1:
        venta_unitaria[0].metodo_pago = "YAPE";
        cout << AZUL << "\t\t\tNUMERO PARA YAPEAR: 921 030 367" << endl;
        cout << "\n\t\t\tPRESIONE [1] SI YA YAPEO AL NUMERO INDICADO." << RESET << endl;
        do
        {
            cout << "\t\t\t->"; cin >> e;
            validar(e);

        } while (validar(e) == 0);
        break;
    case 2:
        int monto_para_pagar;
        venta_unitaria[0].metodo_pago = "EFECTIVO";
        cout << "\t\t\tINGRESE MONTO PARA PAGAR:" << VERDE << "(S / ." << venta_unitaria[0].datos_libro.venta << ")" << RESET << endl;
        cout << "\t\t\t->";
        while (monto_para_pagar < venta_unitaria[0].datos_libro.venta);
        {
            cin >> monto_para_pagar;
            if (monto_para_pagar < venta_unitaria[0].datos_libro.venta)
            {
                cout << "\t\t\tMONTO INSUFICIENTE" << endl;
                cout << "\t\t\t->"; cin >> monto_para_pagar;
            }
        }
        break;
    case 3:
        cout << endl;
        venta_unitaria[0].metodo_pago = "DEBITO";
        cout << "\t\t\tINGRESE NOMBRE Y APELLIDO DEL TITULAR DE LA TARJETA" << endl;
        cin.ignore();
        cout << "\t\t\t->"; getline(cin, nombre_y_apellido);
        do
        {
            cout << "\t\t\tINGRESE MES DE VENCIMIENTO:" << endl;
            cout << "\t\t\t->"; cin >> mes_vencimiento;
            if (mes_vencimiento < 0 || mes_vencimiento>12)
            {
                cout << AZUL << "\t\t\tINGRESE MES DE VENCIMIENTO VALIDO:" << endl;
                cout << "\t\t\t->" << RESET; cin >> mes_vencimiento;
            }
        } while (mes_vencimiento < 0 || mes_vencimiento>12);
        do
        {
            cout << "\t\t\tINGRESE A�O DE VENCIMIENTO:" << endl;
            cout << "\t\t\t->"; cin >> a�o_vencimiento;
        } while (a�o_vencimiento < 2024);
        cout << "\t\t\tINGRESE NUMERO DE LA TARJETA" << endl;
        cout << "\t\t\t->"; cin >> numero_tarjeta;
        break;
    case 4:
        venta_unitaria[0].metodo_pago = "CREDITO";
        cout << "\t\t\tINGRESE NOMBRE Y APELLIDO DEL TITULAR DE LA TARJETA" << endl;
        cin.ignore();
        getline(cin, nombre_y_apellido);
        do
        {
            cout << "\t\t\tINGRESE MES DE VENCIMIENTO:" << endl;
            cout << "\t\t\t->"; cin >> mes_vencimiento;
            if (mes_vencimiento < 0 || mes_vencimiento>12)
            {
                cout << AZUL << "\t\t\tINGRESE MES DE VENCIMIENTO VALIDO:" << endl;
                cout << "\t\t\t->" << RESET; cin >> mes_vencimiento;
            }
        } while (mes_vencimiento < 0 || mes_vencimiento>12);
        cout << "\t\t\tINGRESE NUMERO DE LA TARJETA" << endl;
        cout << "\t\t\t->"; cin >> numero_tarjeta;
        do
        {
            cout << "\t\t\tINGRESE A�O DE VENCIMIENTO:" << endl;
            cout << "\t\t\t->"; cin >> a�o_vencimiento;
        } while (a�o_vencimiento < 2024);
        break;
    default:
        break;
    }
    cout << "\t\t\tPAGO RECIBIDO";
    registrar_ventas_y_usuarios(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
    impresion_boleta(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
}
void impresion_boleta(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales)
{
    system("cls");
    float valor_igv = 0.18;
    float igv = venta_unitaria[0].datos_libro.venta * valor_igv;
    float subtotal = venta_unitaria[0].datos_libro.venta - igv;
    int parte_entera_de_venta = venta_unitaria[0].datos_libro.venta;
    float parte_decimal_de_venta = venta_unitaria[0].datos_libro.venta - parte_entera_de_venta;
    cout << endl;
    cout << "\t\t\tDATOS DEL CLIENTE: " << endl;
    cout << "\t\t\tNOMBRE Y APELLIDO: " << usuario_datos[0].datos_usuario.nombre_apellido << endl;
    cout << "\t\t\tDNI: " << usuario_datos[0].datos_usuario.dni << endl;
    cout << "\t\t\tCORREO: " << usuario_datos[0].datos_usuario.correo << endl;
    cout << "\t\t\t\t\tBOLETA DE COMPRA: " << endl;
    cout << "\t\t\t=========================================================" << endl;
    funcion_fecha(venta_unitaria);
    cout << "\t\t\t---------------------------------------------------------" << endl;
    cout << "\t\t\tCTD \t U.M. \t DESCRIPCION \t PRECIO UNIT. \t  IMPORTE" << endl;
    cout << "\t\t\t---------------------------------------------------------" << endl;
    cout << "\t\t\t1 \tUND \t " << venta_unitaria[0].datos_libro.titulo << " \t " << venta_unitaria[0].datos_libro.venta << " \t " << venta_unitaria[0].datos_libro.venta << endl;
    cout << "\t\t\t---------------------------------------------------------" << endl;
    cout << "\t\t\tOP. GRAVADA\tS/.\t:\t\t" << setprecision(3) << subtotal << endl;
    cout << "\t\t\tIGV : 18%\tS/.\t:\t\t" << igv << endl;
    cout << "\t\t\tVALOR VTA.\tS/.\t:\t\t" << subtotal << endl;
    cout << "\t\t\tIMPORTE TOTAL\tS/.\t:\t\t" << venta_unitaria[0].datos_libro.venta << endl << "\n";
    cout << "\t\t\tSON: " << convertir_numero_en_palabras(int(venta_unitaria[0].datos_libro.venta)) << " CON " << parte_decimal_de_venta * 100 << " / 100 SOLES" << endl;
    cout << "\t\t\t---------------------------------------------------------" << endl;
    cout << "\t\t\t\t  *** GRACIAS POR SU PREFERENCIA ***" << endl;
    opcion_continuar(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
}
void funcion_fecha(datos_venta* venta_unitaria)
{
    auto Actual = chrono::system_clock::now();
    auto ActualEpoch = chrono::system_clock::to_time_t(Actual);
    tm* TiempoLocal = localtime(&ActualEpoch);
    cout << "\t\t\tFecha: " << TiempoLocal->tm_mday << "/" << (TiempoLocal->tm_mon + 1) << "/" << venta_unitaria[0].fecha.a�o;
    cout << "\t\t\t" << (TiempoLocal->tm_hour) << ":" << (TiempoLocal->tm_min) << ":" << (TiempoLocal->tm_sec) << endl;
    venta_unitaria[0].fecha.mes = TiempoLocal->tm_mon + 1;
    venta_unitaria[0].fecha.dia = TiempoLocal->tm_mday;
}
void registrar_ventas_y_usuarios(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales)
{

    int  cantidad_de_libros_vendidos = 0;
    for (int i = 0; i < 5; i++)
    {
        cantidad_de_libros_vendidos += cantidad_mangas_ya_vendidos[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cantidad_de_libros_vendidos += cantidad_comics_ya_vendidos[i];
    }
    for (int i = cantidad_de_libros_vendidos; i < cantidad_de_libros_vendidos + 1; i++)
    {
        ventas_generales[i].datos_libro.titulo = venta_unitaria[0].datos_libro.titulo;
        ventas_generales[i].datos_libro.codigo = venta_unitaria[0].datos_libro.codigo;
        ventas_generales[i].datos_libro.costo = venta_unitaria[0].datos_libro.costo;
        ventas_generales[i].datos_libro.venta = venta_unitaria[0].datos_libro.venta;
        ventas_generales[i].modalidad.tipo_modalidad = venta_unitaria[0].modalidad.tipo_modalidad;
        ventas_generales[i].datos_libro.tipo = venta_unitaria[0].datos_libro.tipo;
        if (venta_unitaria[0].modalidad.tipo_modalidad == 'W')
        {
            ventas_generales[i].modalidad.recojo = ventas_generales[0].modalidad.recojo;
        }
        ventas_generales[i].local = venta_unitaria[0].local;
        ventas_generales[i].datos_usuario.nombre_apellido = usuario_datos[0].datos_usuario.nombre_apellido;
        ventas_generales[i].datos_usuario.correo = usuario_datos[0].datos_usuario.correo;
        ventas_generales[i].datos_usuario.sexo = usuario_datos[0].datos_usuario.sexo;
        ventas_generales[i].datos_usuario.dni = usuario_datos[0].datos_usuario.dni;
        ventas_generales[i].fecha.a�o = venta_unitaria[0].fecha.a�o;
        ventas_generales[i].metodo_pago = venta_unitaria[0].metodo_pago;
    }

}
void opcion_continuar(datos_venta* venta_unitaria, datos_venta* usuario_datos, datos_venta* el_stock, int* cantidad_mangas_ya_vendidos, int* cantidad_comics_ya_vendidos, datos_venta* ventas_generales)
{
    int opcion;
    int opcion_cont;
    do
    {
        cout << "\n\t\t\t Desea continuar o Salir?" << endl;
        cout << "\t\t\t--------------------------------------" << endl;
        cout << CELESTE << "\t\t\t Opcion 1: Continuar en el sistema con mi usuario:" << endl;
        cout << CELESTE << "\t\t\t Opcion 2: Continuar en el sistema con nuevo usuario:" << endl;
        cout << "\t\t\t Opcion 3: Salir del sistema e imprimir reportes " << RESET << endl;
        cout << "\t\t\t--------------------------------------" << endl;
        cout << "\n";
        cout << "\t\t\tIngrese Opcion -> : "; cin >> opcion_cont;
        if (opcion_cont < 1 || opcion_cont>3)
        {
            cout << "\n\tOpcion (" << opcion_cont << ") es incorrecto" << endl;
            cout << "\tIntente nuevamente ingresando opcion correcta " << endl << endl;
        }
    } while (opcion_cont < 1 || opcion_cont>3);
    switch (opcion_cont)
    {
    case 1:
        registrar_ventas_y_usuarios(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        cout << endl;
        cout << "===================BIENVENIDO DE VUELTA, " << usuario_datos[0].datos_usuario.nombre_apellido << "===================" << endl;
        delete[]venta_unitaria;
        cout << endl;
        opcion_menu(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;

    case 2:
        registrar_ventas_y_usuarios(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        delete[]venta_unitaria;
        delete[]usuario_datos;
        cout << endl;
        cin.ignore();
        registro_nuevo_usuario(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        break;
    case 3:
        system("cls");
        registrar_ventas_y_usuarios(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        cout << "\n\t\t\tQUE REPORTE DESEA IMPRIMIR?" << endl;
        cout << CELESTE << "====================================================================" << RESET << endl;
        cout << "\t\t\tOpcion 1: Reporte de recaudaci�n anual" << endl;
        cout << "\t\t\tOpcion 2: Reporte de porcentaje de ventas por modalidad" << endl;
        cout << "\t\t\tOpcion 3: Reporte de listado de compradoras femeninas en un local espec�fico" << endl;
        cout << "\t\t\tOpcion 4: Reporte de n�mero de ventas por tipo para un a�o espec�fico" << endl;
        cout << "\t\t\tOpcion 5: Reporte de tendencias de busqueda y demanda" << endl;
        cout << "\t\t\tOpcion 6: Reporte sobre la compra de mangas de hombres" << endl;
        cout << ROJO "\t\t\tOpcion 7: SALIR DEL SISTEMA" << RESET << endl;
        cout << CELESTE << "====================================================================" << RESET << endl;
        do
        {
            cout << "\t\t\t->";cin >> opcion;
        } while (opcion < 1 || opcion>7);
        switch (opcion)
        {
        case 1:
            reporte_1(ventas_generales, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            cout << endl;
            opcion_continuar(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            break;
        case 2:
            reporte_2(ventas_generales, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            opcion_continuar(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            cout << endl;
            break;
        case 3:
            reporte_3(ventas_generales, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            opcion_continuar(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            cout << endl;
            break;
        case 4:
            reporte_4(ventas_generales, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            opcion_continuar(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            cout << endl;
            break;
        case 5:
            reporte_5(ventas_generales, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            opcion_continuar(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
            cout << endl;
            break;
        case 6:
            reporte_6(ventas_generales, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos);
            cout << endl;
            opcion_continuar(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
        case 7:
            cout << LAZUL << "\t\t------MUCHAS GRACIAS POR SU PREFERENCIA------" <<endl<< RESET;
            cout << "\t\tGRUPO 2" << endl;
            cout << NARANJA"----------------------------" << RESET << endl;
            cout << "\t\tINTEGRANTES: \n";
            cout << NARANJA"----------------------------" << RESET << endl;
            cout << " \tGARCIA MAURICIO \n";
            cout << "\tCOLLAZOS FERNANDA\n";
            cout << "\tGARCIA LEAO\n";
            cout << NARANJA"----------------------------" << RESET << endl;
            delete[]venta_unitaria;
            exit(0);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
int validar(string arreglo)
{
    char caracter = 0;
    for (int i = 0; i < arreglo.length(); i++)
    {
        caracter = arreglo[i];
        if (isalpha(caracter) == 0)
        {
            if (isspace(caracter) == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}
void reporte_1(datos_venta* ventas_generales, int* cantidad_mangas_vendidos, int* cantidad_comics_vendidos)
{
    system("cls");
    float cantidad_libros_vendidos = 0;
    for (int i = 0; i < 5; i++)
    {
        cantidad_libros_vendidos += cantidad_mangas_vendidos[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cantidad_libros_vendidos += cantidad_comics_vendidos[i];
    }
    double** recaudacion;
    recaudacion = new double* [3]();
    for (int i = 0; i < 3; i++)
    {
        recaudacion[i] = new double[2]();
    }
    for (int i = 1; i < cantidad_libros_vendidos + 1; i++)
    {
        switch (ventas_generales[i].fecha.a�o)
        {
        case 2022:
            switch (ventas_generales[i].local)
            {
            case'S':
                recaudacion[0][0] += (ventas_generales[i].datos_libro.costo - ventas_generales[i].datos_libro.venta);
                break;
            case'M':
                recaudacion[0][1] += (ventas_generales[i].datos_libro.costo - ventas_generales[i].datos_libro.venta);
                break;
            default:
                break;
            }
            break;
        case 2023:
            switch (ventas_generales[i].local)
            {
            case'S':
                recaudacion[1][0] += (ventas_generales[i].datos_libro.costo - ventas_generales[i].datos_libro.venta);
                break;
            case'M':
                recaudacion[1][1] += (ventas_generales[0].datos_libro.costo - ventas_generales[0].datos_libro.venta);
                break;
            default:
                break;
            }
            break;
        case 2024:
            switch (ventas_generales[i].local)
            {
            case'S':
                recaudacion[2][0] += (ventas_generales[i].datos_libro.costo - ventas_generales[i].datos_libro.venta);
                break;
            case'M':
                recaudacion[2][1] += (ventas_generales[i].datos_libro.costo - ventas_generales[i].datos_libro.venta);
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
    cout << AZUL "\t\t\tREPORTE #1" << RESET << endl;
    cout << "\tReporte de recaudaci�n anual" << endl;
    cout << CELESTE << "====================================================================" << RESET << endl;
    cout << NARANJA"\t\t\t\tSAN ISIDRO | MIRAFLORES" << RESET << endl;
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            cout << "\t\t\t2022 ";
        }
        if (i == 1)
        {
            cout << "\t\t\t2023 ";
        }
        if (i == 2)
        {
            cout << "\t\t\t2024 ";
        }
        for (int j = 0; j < 2; j++)
        {
            cout << "  \t   " << recaudacion[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "------------------------------------------------------------" << endl;
    cout << endl;
    cout << LVERDE << "\t\t\tGRAFICO DE BARRAS:" << RESET;
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            cout << "\t\t\t\t2022| ";
        }
        if (i == 1)
        {
            cout << NARANJA << "SAN ISIDRO" << RESET << "\t\t\t2023| ";
        }
        if (i == 2)
        {
            cout << "\t\t\t\t2024| ";
        }
        for (int j = 0; j < 1; j++)
        {
            dibujar_barra(recaudacion[i][j]);
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        if (i == 0)
        {
            cout << "\t\t\t\t2022| ";
        }
        if (i == 1)
        {
            cout << NARANJA << "MIRAFLORES" << RESET << "\t\t\t2023| ";
        }
        if (i == 2)
        {
            cout << "\t\t\t\t2024| ";
        }
        for (int j = 1; j < 2; j++)
        {
            dibujar_barra(recaudacion[i][j]);
        }
        cout << endl;
    }
    cout << LAZUL << "\t\t\t LEYENDA: (" << FONDO_AMA << AMARILLO << "M" << RESET << " = " << VERDE << "S / .3.70" << RESET << LAZUL << ")" << RESET << endl;
    cout << CELESTE << "====================================================================" << RESET << endl;
    cout << "\n";
}
void reporte_2(datos_venta* ventas_generales, int* cantidad_mangas_vendidos, int* cantidad_comics_vendidos)
{
    system("cls");
    float cantidad_libros_vendidos = 0;
    float contador_whatsapp = 0;
    float contador_presencial = 0;
    for (int i = 0; i < 5; i++)
    {
        cantidad_libros_vendidos += cantidad_mangas_vendidos[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cantidad_libros_vendidos += cantidad_comics_vendidos[i];
    }
    for (int i = 1; i < cantidad_libros_vendidos + 1; i++)
    {
        if (ventas_generales[i].modalidad.tipo_modalidad == 'W')
        {
            contador_whatsapp++;
        }
        if (ventas_generales[i].modalidad.tipo_modalidad == 'P')
        {
            contador_presencial++;
        }
    }
    cout << "\n";
    cout << AZUL "\t\t\tREPORTE #2" << RESET << endl;
    cout << "\tReporte de porcentaje de ventas por modalidad" << endl;
    cout << CELESTE << "====================================================================" << RESET << endl;
    cout << NARANJA << "PORCENTAJE DE VENTAS WHATSAPP: " << RESET << setprecision(3) << (contador_whatsapp / cantidad_libros_vendidos) * 100 << "%" << endl;
    cout << NARANJA << "PORCENTAJE DE VENTAS PRESENCIAL: " << RESET << (contador_presencial / cantidad_libros_vendidos) * 100 << "%" << endl;
    cout << CELESTE << "====================================================================" << RESET << endl;
    cout << "\n";
}
void reporte_3(datos_venta* ventas_generales, int* cantidad_mangas_vendidos, int* cantidad_comics_vendidos)
{
    system("cls");
    int cantidad_libros_vendidos = 0;
    int Opcion;
    for (int i = 0; i < 5; i++)
    {
        cantidad_libros_vendidos += cantidad_mangas_vendidos[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cantidad_libros_vendidos += cantidad_comics_vendidos[i];
    }
    cout << AZUL "\t\t\tREPORTE #3" << RESET << endl;
    cout << "\tREPORTE DE LISTADO DE COMPRADORAS FEMENINAS\n\t\tEN UN LOCAL ESPEC�FICO" << endl;
    cout << CELESTE << "====================================================================" << RESET << endl;
    cout << NARANJA"\t\tIngrese local a evaluar para el reporte 3" << RESET << endl;
    cout << "===================================================" << endl;
    cout << CELESTE "\t\t\tOpcion 1: MIRAFLORES" << endl;
    cout << "\t\t\tOpcion 2: SAN ISIDRO" << RESET << endl;
    cout << "===================================================" << endl;
    do
    {
        cout << "\t\t\t->";cin >> Opcion;
    } while (Opcion < 1 || Opcion>2);
    string* arreglo_de_nombres;
    arreglo_de_nombres = new string[cantidad_libros_vendidos];
    for (int i = 1; i < cantidad_libros_vendidos + 1; i++)
    {
        arreglo_de_nombres[i - 1] = ventas_generales[i].datos_usuario.nombre_apellido;
    }
    sort(arreglo_de_nombres, arreglo_de_nombres + cantidad_libros_vendidos);
    switch (Opcion)
    {
    case 1:
        for (int i = 1; i < cantidad_libros_vendidos + 1; i++)
        {
            if (ventas_generales[i].datos_usuario.sexo == "F" && ventas_generales[i].local == 'M')
            {
                cout << arreglo_de_nombres[i - 1] << endl;
            }
        }
        break;
    case 2:

        for (int i = 1; i < cantidad_libros_vendidos + 1; i++)
        {
            if (ventas_generales[i].datos_usuario.sexo == "F" && ventas_generales[i].local == 'S')
            {
                cout << arreglo_de_nombres[i - 1] << endl;
            }
        }
        break;
    default:
        break;
    }
    cout << CELESTE << "====================================================================" << RESET << endl;
    cout << "\n";
}
void reporte_4(datos_venta* ventas_generales, int* cantidad_mangas_vendidos, int* cantidad_comics_vendidos)
{
    system("cls");
    int Opcion;
    int cantidad_libros_vendidos = 0;
    for (int i = 0; i < 5; i++)
    {
        cantidad_libros_vendidos += cantidad_mangas_vendidos[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cantidad_libros_vendidos += cantidad_comics_vendidos[i];
    }
    int** arreglo;
    arreglo = new int* [3]();
    for (int i = 0; i < 3; i++)
    {
        arreglo[i] = new int[2]();
    }
    for (int i = 1; i < cantidad_libros_vendidos + 1; i++)
    {
        if (ventas_generales[i].fecha.a�o == 2022)
        {
            if (ventas_generales[i].datos_libro.tipo == 'M')
            {
                arreglo[0][0]++;
            }
            if (ventas_generales[i].datos_libro.tipo == 'C')
            {
                arreglo[0][1]++;
            }
        }
        if (ventas_generales[i].fecha.a�o == 2023)
        {
            if (ventas_generales[i].datos_libro.tipo == 'M')
            {
                arreglo[1][0]++;
            }
            if (ventas_generales[i].datos_libro.tipo == 'C')
            {
                arreglo[1][1]++;
            }
        }
        if (ventas_generales[i].fecha.a�o == 2024)
        {
            if (ventas_generales[i].datos_libro.tipo == 'M')
            {
                arreglo[2][0]++;
            }
            if (ventas_generales[i].datos_libro.tipo == 'C')
            {
                arreglo[2][1]++;
            }
        }
    }
    cout << AZUL << "\t\t\tREPORTE 4" << RESET << endl;
    cout << "\tREPORTE DE NUMERO DE VENTAS POR TIPO PARA UN A�O ESPEC�FICO" << endl;
    cout << CELESTE << "====================================================================" << RESET << endl;
    cout << NARANJA << "\t\tINGRESE A�O PARA EVALUAR EN EL REPORTE 4" << RESET << endl;
    cout << "===================================================" << endl;
    cout << CELESTE << "Opcion 1: 2022" << endl;
    cout << CELESTE << "Opcion 2: 2023" << endl;
    cout << CELESTE << "Opcion 3: 2024" << RESET << endl;
    cout << "===================================================" << endl;
    do
    {
        cout << "\t\t\t->";cin >> Opcion;
    } while (Opcion < 1 || Opcion>3);
    switch (Opcion)
    {
    case 1:
        cout << NARANJA << "\t\tNUMERO DE VENTAS POR TIPO EN EL A�O 2022" << RESET << endl;
        cout << "\t\t\tMANGAS: " << arreglo[0][0] << endl;
        cout << "\t\t\tCOMICS: " << arreglo[0][1] << endl;
        break;
    case 2:
        cout << NARANJA << "\t\tNUMERO DE VENTAS POR TIPO EN EL A�O 2023" << RESET << endl;
        cout << "\t\t\tMANGAS: " << arreglo[1][0] << endl;
        cout << "\t\t\tCOMICS: " << arreglo[1][1] << endl;
        break;
    case 3:
        cout << NARANJA << "\t\tNUMERO DE VENTAS POR TIPO EN EL A�O 2024" << RESET << endl;
        cout << "\t\t\tMANGAS: " << arreglo[2][0] << endl;
        cout << "\t\t\tCOMICS: " << arreglo[2][1] << endl;
        break;
    default:
        break;
    }
    cout << CELESTE << "====================================================================" << RESET << endl;
}
void reporte_5(datos_venta* ventas_generales, int* cantidad_mangas_vendidos, int* cantidad_comics_vendidos)
{
    system("cls");
    struct libros_y_cantidades
    {
        string titulos;
        int cantidad;
    };
    string nombres[10] = { "Marvel Tony Stark. Iron Man 01","Marvel Thor. Vikingos","Marvel Thanos. Poderes Cosmicos","Marvel Ultimate Spiderman 2","Marvel Secret War","My Hero Academy 01","Dragon Ball Super 03","JoJo's Bizarre Adventure: Part 1","Death Note 01","Chainsaw Man 01" };
    libros_y_cantidades* arreglo;
    arreglo = new libros_y_cantidades[10]();
    for (int i = 0; i < 10; i++)
    {
        arreglo[i].titulos = nombres[i];
    }

    if (cantidad_comics_vendidos[0] > 0)
    {
        arreglo[0].cantidad += cantidad_comics_vendidos[0];
    }
    if (cantidad_comics_vendidos[1] > 0)
    {
        arreglo[1].cantidad += cantidad_comics_vendidos[1];
    }
    if (cantidad_comics_vendidos[2] > 0)
    {
        arreglo[2].cantidad += cantidad_comics_vendidos[2];
    }
    if (cantidad_comics_vendidos[3] > 0)
    {
        arreglo[3].cantidad += cantidad_comics_vendidos[3];
    }
    if (cantidad_comics_vendidos[4] > 0)
    {
        arreglo[4].cantidad += cantidad_comics_vendidos[4];
    }
    if (cantidad_mangas_vendidos[0] > 0)
    {
        arreglo[5].cantidad += cantidad_mangas_vendidos[0];
    }
    if (cantidad_mangas_vendidos[1] > 0)
    {
        arreglo[6].cantidad += cantidad_mangas_vendidos[0];
    }
    if (cantidad_mangas_vendidos[2] > 0)
    {
        arreglo[7].cantidad += cantidad_mangas_vendidos[0];
    }
    if (cantidad_mangas_vendidos[3] > 0)
    {
        arreglo[8].cantidad += cantidad_mangas_vendidos[0];
    }
    if (cantidad_mangas_vendidos[4] > 0)
    {
        arreglo[9].cantidad += cantidad_mangas_vendidos[0];
    }
    libros_y_cantidades aux;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (arreglo[i].cantidad > arreglo[j].cantidad)
            {
                aux = arreglo[i];
                arreglo[i] = arreglo[j];
                arreglo[j] = aux;
            }
        }
    }


    cout << AZUL << "\t\t\tREPORTE #5" << endl;
    cout << NARANJA << "\tREPORTE DE TENDENCIAS DE B�SQUEDA Y DEMANDA" << RESET << endl;
    cout << CELESTE << "====================================================================" << RESET << endl;
    cout << "\t\tLIBROS M�S VENDIDOS: " << endl;
    if (arreglo[0].cantidad == 0 && arreglo[1].cantidad == 0 && arreglo[2].cantidad == 0 && arreglo[3].cantidad == 0 && arreglo[4].cantidad == 0)
    {
        cout << "";
    }
    else
    {
        cout << VERDE << "\t\t\tCOMICS: " << RESET << endl;
        for (int i = 0; i < 5; i++)
        {
            if (arreglo[i].cantidad == 0)
            {
                cout << "";
            }
            else
            {
                cout << arreglo[i].titulos << " (" << arreglo[i].cantidad << ")" << endl;
            }
        }
    }
    if (arreglo[5].cantidad == 0 && arreglo[6].cantidad == 0 && arreglo[7].cantidad == 0 && arreglo[8].cantidad == 0 && arreglo[9].cantidad == 0)
    {
        cout << "";
    }
    else
    {
        cout << VERDE << "\t\t\tMANGAS:" << RESET << endl;
        for (int i = 5; i < 10; i++)
        {
            if (arreglo[i].cantidad == 0)
            {
                cout << "";
            }
            else
            {
                cout << arreglo[i].titulos << " (" << arreglo[i].cantidad << ")" << endl;
            }
        }
    }
    cout << CELESTE << "====================================================================" << RESET << endl;
    cout << "\n";
}
void reporte_6(datos_venta* ventas_generales, int* cantidad_mangas_vendidos, int* cantidad_comics_vendidos)
{
    system("cls");
    int cantidad_usuarios = 0;
    int cantidad_hombres = 0;
    int cantidad_hombres_mangas = 0;
    int cantidad_libros_vendidos = 0;
    for (int i = 0; i < 5; i++)
    {
        cantidad_libros_vendidos += cantidad_mangas_vendidos[i];
    }
    for (int i = 0; i < 5; i++)
    {
        cantidad_libros_vendidos += cantidad_comics_vendidos[i];
    }
    string* arreglo_usuarios;
    arreglo_usuarios = new string[cantidad_libros_vendidos];
    for (int i = 1; i < cantidad_libros_vendidos + 1; i++)
    {
        cantidad_usuarios++;
        if (ventas_generales[i + 1].datos_usuario.nombre_apellido == ventas_generales[i].datos_usuario.nombre_apellido)
        {
            cantidad_usuarios--;
        }
    }
    for (int i = 1; i < cantidad_libros_vendidos + 1; i++)
    {
        if (ventas_generales[i].datos_usuario.sexo == "M")
        {
            cantidad_hombres++;
        }
        if (ventas_generales[i].datos_usuario.sexo == "M" && ventas_generales[i].datos_libro.tipo == 'M')
        {
            cantidad_hombres_mangas++;
        }
    }

    cout << AZUL"\t\t\tREPORTE #6" << RESET << endl;
    cout << NARANJA "\t\tREPORTE SOBRE LA COMPRA DE MANGAS DE HOMBRES" << RESET << endl;
    cout << CELESTE << "====================================================================" << RESET << endl;
    cout << "\t\t\tCANTIDAD TOTAL DE USUARIOS: " << cantidad_usuarios << endl;
    cout << "\t\t\tCANTIDAD DE HOMBRES: " << cantidad_usuarios << endl;
    cout << "\tPORCENTAJE DE HOMBRES QUE COMPRAN MANGA RESPECTO AL TOTAL DE HOMBRES: " << (cantidad_hombres_mangas / cantidad_hombres) * 100 << "%" << endl;
    cout << CELESTE << "====================================================================" << RESET << endl;
    cout << "\n";


}
void dibujar_barra(float cantidad)
{
    float n = cantidad / 3.70;
    for (int i = 0; i < n; i++)
    {
        cout << FONDO_AMA << AMARILLO << "M" << RESET << " ";
    }
}
int main()
{
    setlocale(LC_CTYPE, "Spanish");
    int* cantidad_comics_ya_vendidos;
    int* cantidad_mangas_ya_vendidos;
    cantidad_comics_ya_vendidos = new int[5]();
    cantidad_mangas_ya_vendidos = new int[5]();
    datos_venta* el_stock;
    el_stock = new datos_venta[100];
    datos_venta* usuario_datos;
    usuario_datos = new datos_venta[1];
    datos_venta* venta_unitaria;
    venta_unitaria = new datos_venta[1];
    datos_venta* ventas_generales;
    ventas_generales = new datos_venta[100]();
    cout << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMWKXWO:;:cldxkO0KXXXNNNNWWMMMMMMMMMMMMMMMMMMMWWNNNNXXXK0Okxdlc:,;OWXKWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMW" << RESET << "XN0, :Kk.'lolc:;;,,,,;;;;;;" << AMARILLO << ":cokKWMMMMMMMMMWKkoc::" << RESET << ";;;;;,,,,;;:clol'.kK;, 0NX" << AMARILLO << "WMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "k, ox''0k., KMMMWNNXKK00OOOOkxo:," << AMARILLO << " ':dKWMMMWKd:'" << RESET << ", : oxkOOOO00KKXNNWMMMK, .k0''xo, k" << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "d. : x''0k., KMMMMMMMMMMMMMMMMMMWXkl''" << AMARILLO << "l0NKo" << RESET << "''lkXWMMMMMMMMMMMMMMMMMMK, .k0''x : .d" << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "d. : x''0k., KMMMMMMMMMMMMMMMMMMMMMWKo'';''oKWMMMMMMMMMMMMMMMMMMMMMK, .k0''x : .d" << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "d. : x''0k., KMMMMMMMMMMMMMMMMMMMMMMMWd..dWMMMMMMMMMMMMMMMMMMMMMMMK, .k0''x : .d" << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "d. : x''0k., KMMMMMMMMMMMMMMMMMMMMMMMMk..kMMMMMMMMMMMMMMMMMMMMMMMMK, .k0''x : .d" << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "d. : x''0k., KMMMMMMMMMMMMMMMMMMMMMMMMk..kMMMMMMMMMMMMMMMMMMMMMMMMK, .k0''x : .d" << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "d. : x''0k., KMMMMMMMMMMMMMMMMMMMMMMMMk..kMMMMMMMMMMMMMMMMMMMMMMMMK, .k0''x : .d" << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "d. : x''0k., KMMMMMMMMMMMMMMMMMMMMMMMMk..kMMMMMMMMMMMMMMMMMMMMMMMMK, .k0''x : .d" << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "d. : d''0k., KMMMMMMMMMMMMMMMMMMMMMMMMk..kMMMMMMMMMMMMMMMMMMMMMMMMK, .k0,'d : .d" << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "d. : d',0k.,KMMMMMMMMMMMMMMMMMMMMMMMMk. .kMMMMMMMMMMMMMMMMMMMMMMMMK,.k0,'d : .d" << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "d. : d',0k.,KMMMMMMMMMMMMMMMMMMMMMMMMx. .kMMMMMMMMMMMMMMMMMMMMMMMMK,.k0,'d : .d" << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "d. : d',0k.,KMMMMMMMMMMMMMMMMMMMMMMMMx. .kMMMMMMMMMMMMMMMMMMMMMMMMK,.k0,'d : .d" << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "d. : d',0k.,KMMMMMMMMMMMMMMMMMMMMMMMMx. .kMMMMMMMMMMMMMMMMMMMMMMMM0,.k0,.d : .d" << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "d. : d',0k.,KMMMMMMMMMMMMMMMMMMMMMMMMx. .kMMMMMMMMMMMMMMMMMMMMMMMM0,.k0'.d : .d" << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "d. : d',0k.'x000OOkxdddooooodxOKXWMMMk..kMMMWXKOxdooooooddxxkOO00x'.k0''d : . d" << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "d. : x., 0k'.,;;:cccccccclllcc:;,,:lkKx. .xKxl:,,,:cclllcccc:::;;,.'k0, 'd : .d" << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "d. : x''kOddxxxxxddddooooddxOOOOkdc, ''...'', cdkOOOOkddooooddddxxxxdddOk''dc.x" << AMARILLO << "WMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "d. : d, ., ;;::::::::ccccccc::;, , ;:lxxd:. . : dxdl : ;, , ;::cccccccc:::;;;;;" << AMARILLO << "WMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "d., lccllooooddxxxxxxxxxxxddoc;'...;ccccl;...';coddxxxxxxxxxxxddooolllcll, .d" << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMM" << RESET << "Oc:::ccc::::::::::::::::::::::::, ....'....,::::::::::::::::::::::::clcc::cO" << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW" << RESET << "Kd : '...' : dK" << AMARILLO << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n"
        << AMARILLO << "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMWX00KXWMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n" << RESET;
    string a;
    cin >> a;
    system("cls");
    cin.ignore();
    registro_nuevo_usuario(venta_unitaria, usuario_datos, el_stock, cantidad_mangas_ya_vendidos, cantidad_comics_ya_vendidos, ventas_generales);
}