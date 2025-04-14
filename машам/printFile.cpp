#include "List.h"

void List::printToFile(ofstream& out, bool showInfo) const {
    if (!out) return;

    if (showInfo) {
        out << "---����������� �����---\n";
        out << "���������� ��������� � ������: " << size << '\n';
        out << "���������� ������:\n";
    }

    Node* current = head;
    while (current) {
        out << "->" << current->data << '\n';
        current = current->next;
    }
}