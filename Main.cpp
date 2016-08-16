#include "TableEntry.hpp"
#include "SymbolTable.hpp"
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(int argc, char **argv){

    TableEntry *t1 = new TableEntry;
    t1->setLexeme("batata");
    t1->setToken("ID");

    TableEntry *t2 = new TableEntry;
    t2->setLexeme("batata");
    t2->setToken("NUMBER");

    TableEntry *t3 = new TableEntry;
    t3->setLexeme("batata");
    t3->setToken("TETA");

    TableEntry *t4 = new TableEntry;
    t4->setLexeme("batata");
    t4->setToken("TETA");

    TableEntry *t5 = new TableEntry;
    t5->setLexeme("batata");
    t5->setToken("TETA");

    TableEntry *t6 = new TableEntry;
    t6->setLexeme("batata");
    t6->setToken("NUMBER");

    TableEntry *t7 = new TableEntry;
    t7->setLexeme("batata");
    t7->setToken("ID");


    SymbolTable st;
    st.insertEntry(t1);
    st.insertEntry(t2);
    st.insertEntry(t3);
    st.insertEntry(t4);
    st.insertEntry(t5);
    st.insertEntry(t6);
    st.insertEntry(t7);


    TableEntry *tmp;
    tmp = st.getHashMap()["batata"];

    while(tmp != NULL){
        cout << tmp->getToken() << endl;
        tmp = tmp->getNextEntry();
    }

    return 0;
}
