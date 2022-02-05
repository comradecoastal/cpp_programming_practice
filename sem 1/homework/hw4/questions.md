## Контрольные вопросы

### Вопрос 1

**Как обратиться к полям структуры?**  
К полям структуры можно обратиться через точку `structure.field`  
**Как обратиться к полям структуры, имея указатель?**  
Имея можно обратиться к полу через стрелочку `pointer_to_structure->field`  
**Как инициализировать структуру?**  
Пишем название структуры и название переменной `Sturcture structure;`  
**Как задать значения по умолчанию для полей структуры?**  
Во время объявления структуры присвоить полям значение.

```c++
struct Structure{
    int field = 0; // значение field = 0 по умолчанию
};
```

### Вопрос 2

**Что такое битовое поле?**  
Битовое полу - тип данных, в котором к каждому биту можно обращаться по отдельности. По сути массив битов.  
**В каких случаях оно используется?**  
Битовое поле можно использовать как массив булевых переменных. Получится, что вместо того, чтобы занимать 8 байтов для 8
переменных, можно использовать всего 1 байт. Также в `std::vector<bool>` изначально используется битовое поле для
хранения переменных.

### Вопрос 3

**Что такое объединение?**  
Объединение - переменная, которая может хранить данные разных типов. При этом при изменении типа переменной, не меняется
её место в памяти.  
**Каким образом переменные хранятся внутри объединения?**  
Объединение хранит все данные в выделенной под него память. Если присвоить объединению значение переменной первого типа,
то из него можно получить значение переменной первого типа; если после этого присвоить ему значение переменной второго
типа, то из него можно будет получить его, но значение переменной первого типа будет удалено.  
**С какой целью объединения использовались раньше и почему они практически не используются сейчас?**  
Раньше объединение использовались для уменьшения памяти. Объединения использовались, если нужно было несколько
переменных разного типа, которые используются в разное время, и при этом не было нужды их сохранять. Вместо объявления
нескольких переменных можно было объявить одно объединение, которое принимало разные значения. Сейчас для большинства
случаев нет необходимости экономить память, к тому же в объединениях лего запутаться.

### Вопрос 4

**Что такое перегрузка операторов?**  
Перегрузка операторов - определение функционала операторов для новых типов данных (типов данных для которых функционал
операторов не был задан ранее).  
**Как она осуществляется?**  
У перегрузки операторов следующий синтаксис:

```c++
ReturnType operator + (LeftSideType left, RightSideType right) {
    ReturnType output;
    // code
    retun output;
}
```

Сначала определяется тип возвращаемого значения, затем пишется ключевое слово `operator`, затем пишется оператор который
нужно перегрузить, затем в круглых скобках задаются аргументы оператора: 2 аргумента, если оператор бинарный, 1
аргумент, если оператор унарный. После этого в фигурных скобочках пишется код, и возвращается значение операции.

### Вопрос 5

**Почему передача объектов типа std::ostream и std::istream в операторы вывода и ввода соответственно осуществляется по
ссылке? Почему из них затем возвращаются эти ссылки?**  
Для вывода текста в консоль предусмотрен только один поток вывода, объект
`std::cout` обращается именно к нему, передавая этот объект по ссылке мы всё время работаем с одним и тем же буфером
вывода. Возвращается объект по ссылке соответственно по той же причине, для того чтобы последующие операции работали с
тем же потоком. Аналогично для потока ввода.

### Вопрос 6

**Для чего применяется перечисление с областью видимости enum class?**  
`enum class` применяется для того, чтобы существовало хорошо читаемое соответствие между числом и концепцией. Например,
если у нас есть 20 действий, намного легче работать с ними в виде `enum class`, где для каждого действия прописано
название, чем работать с числами.  
**В каких случаях используется конструкция switch-case-default и как она устроена?**  
_switch-case-default_ используется если необходимо выполнить несколько различных действий при различных значениях
переменной. Значение заданное после `switch` сравнивается со значениями `case`, когда находится такое значение _case_,
которе совпадает с ним, выполняется весь последующий код до операции `break`. Если не было найдено совпадающего
значения, то выполняется код после слова `default`.