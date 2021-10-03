# Семинар 5

## Классы

Объявление класса:
```c++
class Vector {
    std::vector<double> components;
    unsigned dimension;
    // Все поля по умолчанию приватные
};
```

Для инициализации класса используется конструктор:

```c++
class Vector {
public:
    Vector(const std::vector<double>& new_components, unsigned new_dimension) {
        components = new_components;
        dimension = new_dimension;
    }    
};
```

**_Метод_** -- функция внутри класса, имеет доступ ко всем элементам класса.  
**_Геттеры_** -- методы, возвращающие поля.  
_**Сеттера**_ -- методы, изменяющие поля.  
Например:
```c++
unsigned int get_dimension() const {
        return dimension;
    }

    void set_dimension(unsigned int new_dimension) {
        Vector::dimension = new_dimension;
        components.resize(new_dimension);
    }
```

В конструкторе есть способ задать поля во время их инициализации через `:`.  

В публичных полях _класса_ можно объявить дружественную функцию или класс 
через слово `firendly`;

## Использование нескольких файлов

