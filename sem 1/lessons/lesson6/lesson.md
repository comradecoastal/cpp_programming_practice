# Семинар 6

## 0.

**Запрет копирующего конструктора.** `Class(Class) = delete;`

## 1.

**Ссылки:**  
_lvalue_ -- `std::string &`  
_rvalue_ -- `std::string &&`  
В `std::move` используется _rvalue_. Эта функция перемещает переменную.

## 3.

Префиксные и постфиксные операторы.  
```c++
class Number {
public:
    Number(int value) : num(value) {}
    
    // prefix operator
    Number operator++(int) {
        Number tmp = *this;
        this-> num++;
        return tmp;
    }
    // postfix operator
    Number operator++() {
        this->num++;
        return *this;
    }
private:
    int num;
};
```

## 4.

Неявное приведение типов реализуется автоматически, если есть нужные
конструкторы. Чтобы этого не проходило, пишем `explicit`.