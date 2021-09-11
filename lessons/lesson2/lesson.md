## Константы

Принято писать константы в стиле CAPS_UNDERLINE

```c++
#define PI 3.1415 // плохо
const long double PI = 3.14159215; // хорошо
```
Константы сохраняются в рамках кода или функции.

## Циклы

```c++
for (/*init*/;/*cond*/;/*operation*/) {/* some code */}
while (/*cond*/) {/* some code */}
do {/* some code */} while(/*cond*/)
```
Пример
```c++
int main() {
    const unsigned NUM_STUDENTS = 18;
    for (unsigned i = 1; i < NUM_STUDENTS; i++) {
        std::cout << i << std::endl;
    }
}
```
То же самое
```c++
int main() {
    unsigned i = 1
    const unsigned NUM_STUDENTS = 18;
    for (; i < NUM_STUDENTS;) {
        std::cout << i++ << std::endl;
    }
}
```
То же, что и
```c++
int main() {
    const unsigned NUM_STUDENTS = 18;
    for (unsigned i = 1; i < NUM_STUDENTS; std::cout << i << std::endl) {}
}
```

## Модель памяти

Блок памяти
```
--------
  код   : код программы
--------
  стек  : заранее выделен под переменные
--------
  куча  : участки ОП выделенные во время работы программы
--------
```

## Указатели

Ячейки памяти `|int|---|---|---|char|...|...|`  
Ячейки имеют _адреса_, получить адрес можно оператором `&`, получить переменную по
адресу оператором `*`  
***Указатель*** - переменная, содержащая адрес другой переменной. 
Обозначение типа `int*`, `char*` итд.  
Пример
```c++
int main() {
    int x = 5;
    int* anddress_of_x = &x;
    std::cout << address_pf_x;
}
```
Арифметика указателей: смещение на _n_ размеров переменной ячеек (или байтов?).
`ptr--; ptr++; ptr += 10`

## Массивы

1. Статические
2. Динамические

```c++
int dumb_array[5] // статический
```
Строка в C == массив char.  
Массив в C и C++ == указатель на 1 элемент.  

Освобождение памяти `delete var`, `delte[] list`.

## Умные указатели

```c++
int main() {
    boll* someBool = new bool;
    std::shared_ptr<bool>smart_ptr(someBool);
    *smart_prt = true;
    std::cout << *smart_ptr;
}
```



## Динамические массивы

***Вектор*** - элемент стандартной библиотеки. Аналог ***list*** из питона.  
***Строка*** - элемент стандартной библиоткеи.
```c++
#include <vector>
#include <string>

std::string;
std::vector<int>;
std::vector<std::string>;
```

Python *list* | C++ *vector* 
:---:|:---:
**динамические типы** | **тип фиксирован**
`.append()` | `.push_back()`
`len()` | `std::size()`, `.size()`
`[]` | `[]`, `.at()`

Другие методы:  
`.resize()` - увеличение реального размера (capacity)   
`.clear()` - зануляет элементы  
`.shrink_to_fit()` - уменьшает capacity = size  