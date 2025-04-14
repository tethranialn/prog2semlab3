#include "List.h"

void List::printToFile(ofstream& out, bool showInfo) const {
    if (!out) return;

    if (showInfo) {
        out << "---КОНТРОЛЬНЫЙ ВЫВОД---\n";
        out << "Количество элементов в списке: " << size << '\n';
        out << "Содержимое списка:\n";
    }

    Node* current = head;
    while (current) {
        out << "->" << current->data << '\n';
        current = current->next;
    }
}