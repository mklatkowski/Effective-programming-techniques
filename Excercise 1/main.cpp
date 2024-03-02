#include <iostream>
#include <string>
#include "CTable.h"

#define value34 34

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {
    if (iSizeX < 1 || iSizeY < 1) {
        return false;
    }
    *piTable = new int* [iSizeX];
    for (int ii = 0; ii < iSizeX; ii++) {
        std::cout << &piTable[ii] << std::endl;
        (* piTable)[ii] = new int[iSizeY];
    }
    std::cout << &piTable << std::endl;
    return true;
}

bool b_dealoc_table_2_dim(int ***piTable, int iSizeX) {
    if (iSizeX < 1) {
        return false;
    }
    for (int ii = 0; ii < iSizeX; ii++) {
        std::cout << &piTable[ii] << std::endl;
        delete[] (* piTable)[ii];
    }
    std::cout << &piTable << std::endl;
    delete[] (* piTable);
    return true;
}

void v_alloc_table_fill_34(int iSize) {
    if (iSize < 1) {
        std::cout << "Zły rozmiar";
    }
    else {
        int* table;
        table = new int[iSize];
        for (int i = 0; i < iSize; i++) {
            table[i] = value34;
        }

        for (int i = 0; i < iSize; i++) {
            std::cout << table[i] << std::endl;
        }
        delete[] table;
    }
}

void v_mod_tab(CTable *pcTab, int iNewSize) {
    pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable cTab, int iNewSize) {
    cTab.bSetNewSize(iNewSize);
}

int main() {
    v_alloc_table_fill_34(5);

    int** double_dimention_table;

    std::cout << b_alloc_table_2_dim(&double_dimention_table, 3, 4) << std::endl;
    std::cout << b_dealoc_table_2_dim(&double_dimention_table, 3) << std::endl;


    CTable ctab;
    std::cout << std::endl;
    std::cout << "Stworzony obiekt:" << std::endl;
    std::cout << ctab.toString() << std::endl;
    ctab.vSetName("Nowa nazwa");
    std::cout << std::endl;
    std::cout << "Zmieniona nazwa obiekt:" << std::endl;
    std::cout << ctab.toString() << std::endl;
    std::cout << std::endl;

    std::cout << "Kopiowanie konstruktorem kopiującym:" << std::endl;

    CTable *newTable;
    newTable = ctab.pcClone();
    std::cout << newTable->toString() << std::endl;
  


    std::cout << std::endl;
    v_mod_tab(ctab, 7);
    std::cout << ctab.toString() << std::endl;
    std::cout << std::endl;
    v_mod_tab(&ctab, 8);
    std::cout << ctab.toString() << std::endl;


}