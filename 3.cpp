// Опис базового класу:
// Рядки: значення рядка, конструктор з параметром, метод обчислення довжини рядка

// Опис похідного класу:
// Цифрові рядки: конструктор з параметром, метод видалення з рядка заданого символу, методи отримання даних об’єкту

// Завдання
// Описати класи, об’єкт похідного класу; вивести рядок; обчислити і вивести довжину

#include <iostream>

class Line{
    protected:
        char *line;
    public:
        Line(const char *line){
            this->line = new char[strlen(line) + 1];
            strcpy(this->line, line);
        }
        int getLength(){
            return strlen(line);
        }
        void print(){
            std::cout << line << std::endl;
        }
};

class DigitLine : public Line{
    public:
        DigitLine(const char *line) : Line(line){
        }
        void removeChar(char c){
            char *newLine = new char[strlen(line) + 1];
            int j = 0;
            for(int i = 0; i < strlen(line); i++){
                if(line[i] != c){
                    newLine[j] = line[i];
                    j++;
                }
            }
            newLine[j] = '\0';
            delete[] line;
            line = newLine;
        }
        const char *getLine(){
            return line;
        }
};

int main(){
    DigitLine d1("1234567890");
    d1.print();
    std::cout << "Length: " << d1.getLength() << std::endl;
    d1.removeChar('5');
    std::cout << "After removing 5: " << d1.getLine() << std::endl;
    std::cout << "Length: " << d1.getLength() << std::endl;
    return 0;
}