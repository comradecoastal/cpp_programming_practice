# Семинар 9

## Шаблоны для классов

Задаём абстрактный тип `T`

```c++
template <typename T>
T sqr(T x) {
    return x * x;
}

cout << sqr<int>(6) << endl;
```

Можно использовать два типа.

```c++
template <typename T_1, typename T_2>
auto max(T_1 lhs, T_2 rhs) {
    return (lhs < rhs) ? rhs : lhs;
}
```

Можно использовать для классов:

```c++
template <typename T,typename T_1,typename T_2,>
class OutMathClass {
public:
    T sqr(T x) {
        return x * x;
    }
private:
    T field;
};
```