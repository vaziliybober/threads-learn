# learn-threads
HSE second grade course about threads

## homework 1

Бобров Василий БПИ-191 вариант 6.

Папка hw1. Скрины в папке screens. Исходный код в HW1/HW1.cpp

Вычислить прямое произведение множеств А1, А2, А3, А4. Входныеданные: множества чисел А1, А2, А3, А4, мощности множеств могут быть неравны между собой и мощность каждого множества больше или равна 1.Количество потоков является входным параметром

Использован итеративный параллелизм. Пусть l1 - мощность множества A1, а N - кол-во потоков, введенное пользователем. Тогда K = min(l1, N) - число потоков, которое используется для разбиения задачи. Каждый поток берет свою часть множества A1 и находит декартовые произведения для этого подмножества. В конце результаты объединяются.

Для быстроты объединения результатов выбрана структура std::list. Преимущество над массивом в том, что объединить результаты в конце можно мгновенно.

Используются инструменты стандартной библиотеки C++.

Источик информации: плейлист на youtube https://www.youtube.com/playlist?list=PLQOaTSbfxUtAc_RpyDiWCHq0YTzLtVSD0.

## homework 2

Все то же самое, что и homework 1, только использована OpenMp + выведены номера потоков. Находится в папке hw2. Тесты специально взяты те же самые. Скрины в папке screens.
