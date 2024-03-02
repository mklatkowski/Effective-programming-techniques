#include <iostream>
#include <string>
#include "CTable.h"
#include "Matrix.h"
#include "CTab.h"

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


    //CTab c_tab_0;
    //CTab c_tab_1;

    CTable c_table_0;
    CTable c_table_1;
  
    c_table_0.bSetNewSize(6);
    c_table_1.bSetNewSize(4);

    //c_tab_0 = std::move(c_tab_1);

    //c_table_0 = std::move(c_table_1);
    //c_tab_0.vSetValueAt(0, 1);
    //c_tab_0.vSetValueAt(1, 2);
    //c_tab_0.vSetValueAt(2, 3);
    //c_tab_0.vSetValueAt(3, 4);

    //c_tab_0.vPrint();
    //c_tab_1.vPrint();

    (c_table_1 + c_table_0).vPrint();

    //Matrix m1(3, 2);
    //Matrix m2(3, 4);
    //m1.fillMatrixWith(7);
    //m2.fillMatrixWith(2);
    //m1.print();
    //m2.print();
    //std::cout << "Wynik" << std::endl;
    //(m1 + m2).print();

    return 0;
}