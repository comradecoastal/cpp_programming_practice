# IV. Структуры в C++

## Структура


Пример _**структуры**_-точки:
```c++
struct Point {
    double x, y, z;
};
```
_**Обращение**_ к полю структуры `.`:
```c++
int main() {
    Point p;
    p.x = 3;
    p.y = 0.5;
    p.z = 6;
}
```
_**Инициализация**_ структуры `{...}`:
```c++
int main() {
    Point p = {3, 0.5, 6};
}
```
Можно создавать указатели к структуре. 
Здесь обращение к полю `->`
```c++
int main() {
    Point p = {3, 0.5, 6};
    Point* pointer_to_p = &p;
    std::cout << (*pointer_to_t.z) << '\n';
    std::cout << pointer_to_t->z << '\n';
}
```
В структуре можно создавать **_приватные_** поля `private:` и
**_публичные_** поля `public:`
```c++
struct Human {
private:
    std::string name = "Niki";
public:
    unsigned age = 12;
};
```
Для получения доступа пишем **_функцию-член_**
```c++
struct Human {
    std::string get_name() {
        return name;
    }
private:
    std::string name = "Niki";
public:
    unsigned age = 12;
};
```
Функция - **_конструктор_** для структуры:
```c++
struct Human {
    Human(std::string name, int age) {
        this-> name;
        this-> age;
    }
    
    std::string get_name() {
        return name;
    }
private:
    std::string name = "Niki";
public:
    unsigned age = 12;
};
```
### Никита всё выпиливает

## Перегрузка операторов

Создаём структуру вектора в трёхмерном евклидовом пространстве.

```c++
struct Vect {
    double x, y, z;
};
```

Мы хотим умножить вектор на число. Для этого делаем перегрузку оператора.

```c++
Vect operator * (Vect a, double lambda) {
    return {a.x * lambda, a.y * lambda, a.z * lambda};
}
```

Оператор вычитания векторов:
```c++
Vect operator - (Vect a, Vect b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}
```

Оператор вывода:
```c++
std::ostream& operator<<(std::ostream& ostr, const std::vector<int>& nums) {
    ostr << '[';
    for(const auto& number: nums) {
        ostr << number << ' ';
    }
    ostr << ']';
    return ostr;
}
```
Оператор ввода:
```c++
std::istream& operator>>(std::istream& in, std::vector<int> v) {
    for (auto& elem: v) {
        std::cin >> elem;
    }
    return in;
}
```

## Битовые поля

Двоичный ввод переменной.
```c++
int main() {
    int x = 0b1010;
    std::cout << x << std::endl;
}
```
Битовое поле `std::bitset` из `<bitset>`:

```c++
#include <bitset>
#include <iostream>

int main() {
    int x = 0b1010;
    std::cout << x << std::endl; // выведет 10
    std::bitset<4> bools(0b1010);
    std::cout << bools << std::endl; // выведет 1010
}
```

Можно использовать `std::vector<bool>`, так как он хранит булы побитно.

## Объединения

Когда-то давно, когда трава была зеленее, а небо голубее, существовало ключевое
слово `union`:
```c++
union {
    int number;
    std::string line;
};
```
Сейчас `union` использовать не надо. Сейчас существует `std::variant`:

```c++
#include <variant>

int main() {
    std::variant<int, double> var_var;
    var_var = 5;
    std::cout << std::get<int>(var_var) << std::endl;
    var_var = 54.2356;
    std::cout << std::get<double>(var_var) << std::endl;
}
```

### Это всё не применяется, Никита даже не может придумать применение для этого. Когда-то это применялось

## Перечисления

Оператор **_Свитч-кейс_**:
```c++
int main() {
    int a = 5, b = 6, c;
    char op;
    
    switch(op) {
        case '+':
            c = a + b;
            break;
        case '-':
            c = a - b;
            break;
        default:
            c = 0;
    }
    
}
```
Но со строчками такое не работает.   
Теперь используем **_перечисления_** для этого используем `enum`:
```c++
enum class Seasons {
    AUTUMN;
    WINTER;
    SPRING;
    SUMMER;
};

int main() {
    Seasons season = Seasons::SPRING;
    
    switch (season) {
        case Seasons::WINTER:
            break;
        case Seasons::SPRING:
            break;
        case Seasons::SUMMER:
            break;
        case Seasons::AUTUMN:
            break;
    }
    switch()
}
```

А как какать (~~срать~~ (вводить их))?  
Используем приведение типов. Для этого можем ввести номер. Дефолтная нумерация начинается с нуля.
```c++
int main(){
    int season_number = 0;
    Seasons season;
    season = static_cast<Seasons>(season_number); // кастуем число в сезон
}
```
Нумерацию можно менять.
```c++
enum class Seasons {
    AUTUMN = 3; // 3
    WINTER; // 4
    SPRING = 0; // 0
    SUMMER = 42; // 42
};
```